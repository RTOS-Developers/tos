#include <..\USER\Prj_TP502T\QuectelM26.h>
#include <AT_Command.h>
#include <..\USER\Prj_TP502T\Auto_Register.h>
u8 QuectelM26_Init(void)
{
		uint8 sta;
    M26_POWER_OFF;
    Tos_TaskDelay(1100); 
		DeBug("GPRS上电",Infor_Warning);
    M26_POWER_ON;
    Tos_TaskDelay(1100); 
    M26_RESET_ON;
    Tos_TaskDelay(1100); 
		DeBug("GPRS开机",Infor_Warning);
    M26_RESET_OFF;
    Tos_TaskDelay(1000);
		if(GPRS_VDDEXT==1)DeBug("开机成功",Infor_Warning);
		else return 1;
	  Tos_TaskDelay(14000);
		if(!GPRS_CommandAck("AT\r\n","OK",1000))return 2;
		DeBug("AT指令执行成功",Infor_Warning);
    Tos_TaskDelay(1000);
		if(!GPRS_CommandAck("ATE0\r\n","OK",2000))return 3;
		DeBug("设置不回显",Infor_Warning);
	  if(!GPRS_CommandAck("AT+CPIN?\r\n","OK",1000))return 4;
		DeBug("查看是否有PIN",Infor_Warning);
    sta=QuectelM26_ConnectNet();                                      //连接网络
		if(sta)DeBug("连接网失败[%d]",sta,Infor_Warning);
		else DeBug("连接网络成功",Infor_Warning);
    return M26_OK;
}

u8 QuectelM26_Connect()
{
	char Buf[100];
	FmtToBuf(&Buf[0],"AT+QIOPEN=\"TCP\",\"%s\",%d\r\n",&UIShowValue.SaveValue.DomainName[0][0],UIShowValue.SaveValue.ServerPort[0]);
	DeBug("连接到:%s",&Buf[0],Infor_Warning);
	return GPRS_Connect(&Buf[0]);
}
/***************************************************************************************************
 * 函 数 名: QuectelM26_ConnectNet
 * 功能描述: 模块连接网络
 * 函数说明: 无
 * 调用函数: 无
 * 全局变量: 无
 * 输　　入: 无
 * 返　　回: 处理结果
***************************************************************************************************/
u8 QuectelM26_ConnectNet(void)
{
    if(!GPRS_CommandAck("AT+CSQ\r\n","!99",1000))return 1;
		UIShowValue.RSSI=QuectelM26_GetCSQ();
		DeBug("检查信号",Infor_Warning);
		DeBug("正在注册",Infor_Warning);
		if(!GPRS_CommandAck("AT+CREG?\r\n","0",1000));
		if(!GPRS_CommandAckCount("AT+CREG?\r\n","5",1000,2))DeBug("本地卡",Infor_Warning);else DeBug("外地卡",Infor_Warning);
		if(GPRS_CommandAckCount("AT+COPS?\r\n","MOBILE",1000,2)){DeBug("中国移动SIM卡",Infor_Warning);UIShowValue.SIMType=ST_CHINA_MOBILE;}
		else if(GPRS_CommandAckCount("AT+COPS?\r\n","UNICOM",1000,2)){DeBug("中国联通SIM卡",Infor_Warning);UIShowValue.SIMType=ST_CHINA_UNINET;}
		DeBug("注册成功",Infor_Warning);
		return 0;
}



u8 QuectelM26_CreateCFG(u8 *Buf)
{
	uint16 i=0;
	Buf[i++]=0x10;//消息类型：发布消息 非UDP通信QOS至少一次
	Buf[i++]=0xff;//数据长度，当大于127个字节一下只需要一个字节表示
	Buf[i++]=0x00;//版本
	Buf[i++]=0x04;//连接标志
	i+=BufferCoppy("MQTT",&Buf[i],4);
	Buf[i++]=0x04;//协议版本
	Buf[i++]=0x02;//连接标志
	Buf[i++]=0x00;//
	Buf[i++]=0x3c;//保持活动周期
	Buf[i++]=0x00;//
	Buf[i++]=0x10;//长度
	i+=BufferCoppy(&UIShowValue.SaveValue.LoginHead[0],&Buf[i],sizeof(UIShowValue.SaveValue.LoginHead));
	Buf[1]=i-2;
	return i;
}

BOOL GPRS_Printf(uint16 Wating)//打印接收到的数据
{
	uint8 i=1;
	uint8 Length;
	while(i--)
	{
		BufferFill(USART_RX_Buffer[1],0x00,USART_RX_BUFFER_SIZE);
		Length=USART_ReadDatas(USART2,Null,50,Wating);
		if(Length)
		{
			if(strstr((const char *)USART_RX_Buffer[1],"CLOSED")){DeBug("连接被关闭",Infor_Warning);return False;}
			else {QuectelM26Printf_Bytes("接收:",USART_RX_Buffer[1],Length);return True;}
		}
	}
	return False;
}

u8 QuectelM26_SendData()
{
	uint8 Buf[500];
	uint8 LengthSize=2;
	uint8 c,c1;
	uint16 i=0;
	if(UIShowValue.SaveValue.WorkBit&WCB_MQTTEN)
	{
		Buf[i++]=0x32;//消息类型：发布消息 非UDP通信QOS至少一次
		i+=LengthSize;
		Buf[i++]=0x00;//版本
		Buf[i++]=0x10;//连接标志
		i+=BufferCoppy(&UIShowValue.SaveValue.LoginHead[0],&Buf[i],sizeof(UIShowValue.SaveValue.LoginHead));
		Buf[i++]=0x00;//
		Buf[i++]=0x01;//dd
		i+=GetStringByFmt((char *)&Buf[i],"{\"sensorDatas\":[");
		i+=GetStringByFmt((char *)&Buf[i],"{\"value\":%.2f},",UIShowValue.CH_Value[0]);
		i+=GetStringByFmt((char *)&Buf[i],"{\"value\":%.2f},",UIShowValue.CH_Value[1]);
		i+=GetStringByFmt((char *)&Buf[i],"{\"value\":%.2f},",UIShowValue.CH_Value[2]);
		i+=GetStringByFmt((char *)&Buf[i],"{\"value\":%.2f},",(float)UIShowValue.RSSI);
		i+=GetStringByFmt((char *)&Buf[i],"{\"lat\":%.7f,\"lng\":%.7f}",UIShowValue.GPS_Latitude,UIShowValue.GPS_Longitude);
		i+=GetStringByFmt((char *)&Buf[i],"]}");
		MQTT_LegnthToByte(i-LengthSize-1,&Buf[1]);
		USART_WriteLine(USART2,"AT+QISEND=%d\r\n",i);
		if(!GPRS_AckDelay(">",2000))return 1;
		USART_WriteDatas(USART2,&Buf[0],i);
		if(!GPRS_AckDelay("SEND OK",1000))return 2;//检查发送成功
		GPRS_Printf(2000);
	}else
	{
		if(UIShowValue.CH_Value[0]>=0)c='+';else c='-';
		if(UIShowValue.CH_Value[1]>=0)c1='+';else c1='-';
		i=GetStringByFmt((char *)&Buf[0],"#TP300,%c0%.1f,0.00\r\n",c,UIShowValue.CH_Value[0]);
		if(UIShowValue.CH_Value[1]<UIShowValue.CH_Value[0])i=GetStringByFmt((char *)&Buf[0],"#TP300,%c0%.1f,0.00\r\n",c1,UIShowValue.CH_Value[1]);
		if(UIShowValue.RunFlag&WRF_SensorCH1Connected)i=GetStringByFmt((char *)&Buf[0],"#TP300,%c0%.1f,0.00\r\n",c,UIShowValue.CH_Value[0]);
		else if(UIShowValue.RunFlag&WRF_SensorCH2Connected)i=GetStringByFmt((char *)&Buf[0],"#TP300,%c0%.1f,0.00\r\n",c1,UIShowValue.CH_Value[1]);
		USART_WriteLine(USART2,"AT+QISEND=%d\r\n",i);
		Tos_TaskDelay(1000);
		DeBug("发送数据:%s",&Buf[0],Infor_Warning);
		USART_WriteDatas(USART2,&Buf[0],i);
		if(!GPRS_AckDelay("SEND OK",1000))return 2;//检查发送成功
	}
	return 0;
}
u8 QuectelM26_SendHeartbeat()
{
	uint8 Buf[200];
	uint16 i=0;
	if(UIShowValue.SaveValue.WorkBit&WCB_MQTTEN)
	{
		Buf[i++]=0xc0;
		Buf[i++]=0x00;
		USART_WriteLine(USART2,"AT+QISEND=%d\r\n",i);
		if(!GPRS_AckDelay(">",2000))return 1;
		QuectelM26Printf_Bytes("发送:",&Buf[0],i);
		USART_WriteDatas(USART2,&Buf[0],i);
		if(!GPRS_AckDelay("SEND OK",1000))return 2;//检查发送成功
		if(!GPRS_Printf(2000))return 0;
	}else
	{
		i=StringCoppy("0000",&Buf[0]);
		USART_WriteLine(USART2,"AT+QISEND=%d\r\n",i);
		Tos_TaskDelay(1000);
		USART_WriteDatas(USART2,&Buf[0],i);
		if(!GPRS_AckDelay("SEND OK",1000))return 2;//检查发送成功
	}
	return 0;
}
u8 QuectelM26_SendCFG()
{
	uint8 Buf[200];
	uint16 i=0;
	if(UIShowValue.SaveValue.WorkBit&WCB_MQTTEN)
	{
		DeBug("配置为MQTT协议",Infor_Warning);
		Tos_TaskDelay(3000);
		i=QuectelM26_CreateCFG(&Buf[0]);
		DeBug("发送配置[%d]",i,Infor_Warning);
		USART_WriteLine(USART2,"AT+QISEND=%d\r\n",i);
		if(GPRS_AckDelay(">",2000))goto OK;
		if(GPRS_AckDelay(">",2000))goto OK;
		if(GPRS_AckDelay(">",2000))goto OK;
	OK:
		USART_WriteDatas(USART2,&Buf[0],i);
		if(!GPRS_AckDelay("SEND OK",1000))return 2;//检查发送成功
		GPRS_Printf(2000);
		return 0;
	}else 
	{
		DeBug("配置为TCP协议",Infor_Warning);
		i+=BufferCoppy(&UIShowValue.SaveValue.LoginHead[0],&Buf[i],sizeof(UIShowValue.SaveValue.LoginHead));
	  USART_WriteLine(USART2,"AT+QISEND=%d\r\n",i);
		Tos_TaskDelay(1000);
		DeBug("发送配置:%s",&Buf[0],Infor_Warning);
		USART_WriteDatas(USART2,&Buf[0],i);
		if(!GPRS_AckDelay("SEND OK",1000))return 2;//检查发送成功
		return 0;
	}
}

u8 QuectelM26_SendTextMsg(u8 *string)
{
	uint8 Num[20],Buf[400],i=0,c=0;
R:
	if(i>2)
	{
		return c;
	}
	BufferCoppy(&UIShowValue.SaveValue.CallNumber[i++][0],&Num[0],sizeof(UIShowValue.SaveValue.CallNumber[0]));
	Num[sizeof(UIShowValue.SaveValue.CallNumber[0])]=0;
	if(!CheckCallNumber(&Num[0]))goto R;
	QuectelM26_InitSMS(1);
	GBKToUniCode(&Num[0],&Buf[0]);
	Buf[44]=0x00;
	USART_WriteLine(USART2,"AT+CMGS=\"%s\"\r\n",&Buf[0]);
	DeBug("发送到[%s]",&Num[0],Infor_Warning);
	Tos_TaskDelay(1000);
	GBKToUniCode(&string[0],&Buf[0]);
	Buf[GetTextLength(string)*4]=0x00;
	USART_WriteLine(USART2,(char *)Buf);
	USART_WriteData(USART2,0x1a);                                        //发送数据
	GPRS_AckDelay("CMGS", 1000);                            //数据发送状态
	c++;
	goto R;
}



void QuectelM26_Config()
{
	uint8 sta;
	sta=QuectelM26_SendCFG();
	if(sta)DeBug("发送配置帧失败[%d]",sta,Infor_Warning);
	else DeBug("发送配置帧OK",Infor_Warning);
}
uint8 Task_SendMsg()
{
	uint8 i=0,c=0;
	char Buf[200];
	static uint8 OLDFlag=0xff,z=0;
	uint8 ThisBit;
	ThisBit=UIShowValue.RunFlag&(WRF_CH1Max|WRF_CH1Min|WRF_CH2Max|WRF_CH2Min);
	DeBug("Count=%d,CH1=%.2f,CH2:%.2f",z,UIShowValue.CH_Value[0],UIShowValue.CH_Value[1],Infor_Warning);
	if(OLDFlag==0xff)OLDFlag=ThisBit;
	if(ThisBit!=OLDFlag)
	{
		z++;
		if(z>UIShowValue.SaveValue.SendSMSDelay)
		{
		c=StringCoppy(&UIShowValue.SaveValue.PrintfTitle[0],&Buf[0]);
		i=GetStringByFmt(&Buf[c],"恢复CH1=%.2f,CH2:%.2f",UIShowValue.CH_Value[0],UIShowValue.CH_Value[1]);
		if(UIShowValue.RunFlag&WRF_CH1Max)i=GetStringByFmt(&Buf[c],"触发CH1=%.2f,MAX:%.2f",UIShowValue.CH_Value[0],UIShowValue.SaveValue.CH_Limit[0].Max);
		if(UIShowValue.RunFlag&WRF_CH1Min)i=GetStringByFmt(&Buf[c],"触发CH1=%.2f,Min:%.2f",UIShowValue.CH_Value[0],UIShowValue.SaveValue.CH_Limit[0].Min);
		if(UIShowValue.RunFlag&WRF_CH2Max)i=GetStringByFmt(&Buf[c],"触发CH2=%.2f,MAX:%.2f",UIShowValue.CH_Value[1],UIShowValue.SaveValue.CH_Limit[1].Max);
		if(UIShowValue.RunFlag&WRF_CH2Min)i=GetStringByFmt(&Buf[c],"触发CH2=%.2f,Min:%.2f",UIShowValue.CH_Value[1],UIShowValue.SaveValue.CH_Limit[1].Min);
		i+=c;
		if(i%2==1)i+=GetStringByFmt(&Buf[i]," ");
		DeBug("短信内容[%d]:%s",i,&Buf[0],Infor_Warning);
		i=QuectelM26_SendTextMsg((uint8*)&Buf[0]);
		Tos_TaskDelay(5000);
		OLDFlag=ThisBit;
		}
	}
	if(ThisBit==OLDFlag)z=0;
	return i;
}
void Task_M26(void *Tags)
{
	uint8 sta,i,FailCount=0,RFailCount;
R:
	RFailCount=0;
	UIShowValue.RSSI=99;
	sta=QuectelM26_Init();
	if(sta)DeBug("注册网络失败[%d]",sta,Infor_Error);
	Task_AutoReg(0);
	sta=QuectelM26_InitSMS(1);
	if(sta)DeBug("初始化短信[%d]",sta,Infor_Warning);
	sta=QuectelM26_Connect();
	if(sta)DeBug("连接服务器[%d]",sta,Infor_Warning);
	PDU_GetCenterNumber();
	Tos_TaskDelay(1000);
	QuectelM26_Config();
	while(1)
	{
		sta=QuectelM26_SendData();
		if(sta){DeBug("发送数据失败[%d]",sta,Infor_Warning);FailCount++;}
		else {DeBug("发送数据OK",Infor_Warning);FailCount=0;RFailCount=0;Tos_TaskDelay(9000);}
		for(i=0;i<(UIShowValue.SaveValue.SendCycle/20);i++)
		{
			sta=Task_SendMsg();
			if(sta)DeBug("短信发给[%d]/[%d]人",sta%10,3,Infor_Warning);
			Tos_TaskDelay(1000);
			UIShowValue.RSSI=QuectelM26_GetCSQ();
			QuectelM26_ShowSMS();//获取短信
			Tos_TaskDelay(18000);
			sta=QuectelM26_SendHeartbeat();
			if(sta){DeBug("发送心跳失败[%d]",sta,Infor_Warning);FailCount++;}
			else {DeBug("发送心跳OK",Infor_Warning);RFailCount=0;FailCount=0;}
			if(FailCount>0){QuectelM26_Connect();FailCount=0;QuectelM26_Config();RFailCount++;}
		}
		if(RFailCount>3)goto R;
	}
}
