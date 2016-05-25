#include <Include.h>
#include <DeBug.h>
#include <Board_Driver.h>
#ifdef COMPILE_MODE_DEBUG
void WWDG_IRQHandler(){DeBug("WWDG_IRQHandler",Infor_Infor);}
void PVD_IRQHandler(){DeBug("PVD_IRQHandler",Infor_Infor);}
void TAMPER_IRQHandler(){DeBug("TAMPER_IRQHandler",Infor_Infor);}
//void RTC_IRQHandler(){DeBug("RTC_IRQHandler",Infor_Infor);}
void FLASH_IRQHandler(){DeBug("FLASH_IRQHandler",Infor_Infor);}
void RCC_IRQHandler(){DeBug("RCC_IRQHandler",Infor_Infor);}
//void EXTI0_IRQHandler(){DeBug("EXTI0_IRQHandler",Infor_Infor);}
//void EXTI1_IRQHandler(){DeBug("EXTI1_IRQHandler",Infor_Infor);}
void EXTI2_IRQHandler(){DeBug("EXTI2_IRQHandler",Infor_Infor);}
void EXTI3_IRQHandler(){DeBug("EXTI3_IRQHandler",Infor_Infor);}
void EXTI4_IRQHandler(){DeBug("EXTI4_IRQHandler",Infor_Infor);}
//void DMA1_Channel1_IRQHandler(){DeBug("WWDG_IRQHandler",Infor_Infor);}
void DMA1_Channel2_IRQHandler(){DeBug("DMA1_Channel2_IRQHandler",Infor_Infor);}
void DMA1_Channel3_IRQHandler(){DeBug("DMA1_Channel3_IRQHandler",Infor_Infor);}
//void DMA1_Channel4_IRQHandler(){DeBug("WWDG_IRQHandler",Infor_Infor);}
//void DMA1_Channel5_IRQHandler(){DeBug("WWDG_IRQHandler",Infor_Infor);}
//void DMA1_Channel6_IRQHandler(){DeBug("DMA1_Channel6_IRQHandler",Infor_Infor);}
void DMA1_Channel7_IRQHandler(){DeBug("DMA1_Channel7_IRQHandler",Infor_Infor);}
//void ADC1_2_IRQHandler(){DeBug("WWDG_IRQHandler",Infor_Infor);}
//void USB_HP_CAN1_TX_IRQHandler(){DeBug("WWDG_IRQHandler",Infor_Infor);}
//void USB_LP_CAN1_RX0_IRQHandler(){DeBug("WWDG_IRQHandler",Infor_Infor);}
void CAN1_RX1_IRQHandler(){DeBug("CAN1_RX1_IRQHandler",Infor_Infor);}
void CAN1_SCE_IRQHandler(){DeBug("CAN1_SCE_IRQHandler",Infor_Infor);}
void EXTI9_5_IRQHandler(){DeBug("EXTI9_5_IRQHandler",Infor_Infor);}
void TIM1_BRK_IRQHandler(){DeBug("TIM1_BRK_IRQHandler",Infor_Infor);}
void TIM1_UP_IRQHandler(){DeBug("TIM1_UP_IRQHandler",Infor_Infor);}
void  TIM1_TRG_COM_IRQHandler(){DeBug("TIM1_TRG_COM_IRQHandler",Infor_Infor);}
void TIM1_CC_IRQHandler(){DeBug("TIM1_CC_IRQHandler",Infor_Infor);}
//void TIM2_IRQHandler(){DeBug("WWDG_IRQHandler",Infor_Infor);}
//void TIM3_IRQHandler(){DeBug("WWDG_IRQHandler",Infor_Infor);}
void TIM4_IRQHandler(){DeBug("TIM4_IRQHandler",Infor_Infor);}
void I2C1_EV_IRQHandler(){DeBug("I2C1_EV_IRQHandler",Infor_Infor);}
void I2C1_ER_IRQHandler(){DeBug("I2C1_ER_IRQHandler",Infor_Infor);}
void I2C2_EV_IRQHandler(){DeBug("I2C2_EV_IRQHandler",Infor_Infor);}
void I2C2_ER_IRQHandler(){DeBug("I2C2_ER_IRQHandler",Infor_Infor);}
void SPI1_IRQHandler(){DeBug("SPI1_IRQHandler",Infor_Infor);}
void SPI2_IRQHandler(){DeBug("SPI2_IRQHandler",Infor_Infor);}
//void USART1_IRQHandler(){DeBug("WWDG_IRQHandler",Infor_Infor);}
//void USART2_IRQHandler(){DeBug("WWDG_IRQHandler",Infor_Infor);}
//void USART3_IRQHandler(){DeBug("USART3_IRQHandler",Infor_Infor);}
void EXTI15_10_IRQHandler(){DeBug("EXTI15_10_IRQHandler",Infor_Infor);}
void RTCAlarm_IRQHandler(){DeBug("RTCAlarm_IRQHandler",Infor_Infor);}
//void USBWakeUp_IRQHandler(){DeBug("USBWakeUp_IRQHandler",Infor_Infor);}
void TIM8_BRK_IRQHandler(){DeBug("TIM8_BRK_IRQHandler",Infor_Infor);}
void TIM8_UP_IRQHandler(){DeBug("TIM8_UP_IRQHandler",Infor_Infor);}
void TIM8_TRG_COM_IRQHandler(){DeBug("TIM8_TRG_COM_IRQHandler",Infor_Infor);}
void TIM8_CC_IRQHandler(){DeBug("TIM8_CC_IRQHandler",Infor_Infor);}
void ADC3_IRQHandler(){DeBug("ADC3_IRQHandler",Infor_Infor);}
void FSMC_IRQHandler(){DeBug("FSMC_IRQHandler",Infor_Infor);}
//void SDIO_IRQHandler(){DeBug("SDIO_IRQHandler",Infor_Infor);}
void TIM5_IRQHandler(){DeBug("TIM5_IRQHandler",Infor_Infor);}
void SPI3_IRQHandler(){DeBug("SPI3_IRQHandler",Infor_Infor);}
//void UART4_IRQHandler(){DeBug("UART4_IRQHandler",Infor_Infor);}
//void UART5_IRQHandler(){DeBug("UART5_IRQHandler",Infor_Infor);}
void TIM6_IRQHandlerv(){DeBug("TIM6_IRQHandlerv",Infor_Infor);}
void TIM7_IRQHandler(){DeBug("TIM7_IRQHandler",Infor_Infor);}
void DMA2_Channel1_IRQHandler(){DeBug("DMA2_Channel1_IRQHandler",Infor_Infor);}
void DMA2_Channel2_IRQHandler(){DeBug("DMA2_Channel2_IRQHandler",Infor_Infor);}
void DMA2_Channel3_IRQHandler(){DeBug("DMA2_Channel3_IRQHandler",Infor_Infor);}
//void DMA2_Channel4_5_IRQHandler(){DeBug("WWDG_IRQHandler",Infor_Infor);}
#endif


void Remap_SWJ_JTAGDisable()
{
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE);
}

void RCC_Configuration(void)
{
#ifdef HSI_USER
	 RCC_DeInit(); /*将外设RCC寄存器重设为缺省值 */ 
   RCC_HSICmd(ENABLE); ;
   RCC_SYSCLKConfig(RCC_SYSCLKSource_HSI);//选择内部高速时钟作为系统时钟SYSCLOCK=8MHZ 
   while(RCC_GetFlagStatus(RCC_FLAG_HSIRDY)== RESET);//等待HSI就绪 
   RCC_HCLKConfig(RCC_SYSCLK_Div1);   /*设置AHB时钟（HCLK） RCC_SYSCLK_Div1——AHB时钟 = 系统时*/  
   RCC_PCLK2Config(RCC_HCLK_Div1);   /* 设置高速AHB时钟（PCLK2)RCC_HCLK_Div1——APB2时钟 = HCLK*/     
   RCC_PCLK1Config(RCC_HCLK_Div2); /*设置低速AHB时钟（PCLK1）RCC_HCLK_Div2——APB1时钟 = HCLK / 2*/      
   FLASH_SetLatency(FLASH_Latency_2);   /*设置FLASH存储器延时时钟周期数FLASH_Latency_2  2延时周期*/   
   FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable);  /*选择FLASH预取指缓存的模,预取指缓存使能*/ 
   RCC_PLLConfig(RCC_PLLSource_HSI_Div2, RCC_PLLMul_9);/*设置PLL时钟源及倍频系数，频率为8/2*9=36Mhz*/    
   RCC_PLLCmd(ENABLE);   /*使能PLL */ 
   while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET) ; /*检查指定的RCC标志位(PLL准备好标志)设置与否*/    
   RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);  /*设置系统时钟（SYSCLK） */  
   while(RCC_GetSYSCLKSource() != 0x08);     /*0x08：PLL作为系统时钟 */ 
#else 
	uint8_t HSEStartUpStatus;
	RCC_DeInit();
	RCC_HSEConfig(RCC_HSE_ON);
	HSEStartUpStatus=RCC_WaitForHSEStartUp();
	if(HSEStartUpStatus==SUCCESS)
	{
		FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable);
		FLASH_SetLatency(FLASH_Latency_2);
		RCC_HCLKConfig(RCC_SYSCLK_Div1);//72M
		RCC_PCLK2Config(RCC_HCLK_Div1);//72M
		RCC_PCLK1Config(RCC_HCLK_Div2);//36M
		RCC_PLLConfig(RCC_PLLSource_HSE_Div1,RCC_PLLMul_9);
		RCC_PLLCmd(ENABLE);
		while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY)==RESET)
		{
		}
		RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
		while(RCC_GetSYSCLKSource()!=0x08)
		{
		}
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB |\
                            RCC_APB2Periph_GPIOC | RCC_APB2Periph_GPIOD,\
                            ENABLE);
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
	  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);
	}
#endif	
}
#ifdef USE_FULL_ASSERT
void assert_failed(uint8_t* file, uint32_t line)
{
	while(1)
	{	DeBug_Get();
		DeBug("ErrorFile%s->Line%d",file,line,Infor_Infor);
		Tos_TaskDelay(1000);
	}
}
#endif
/**************************************************************************************
 Func: 端口清单初始化
 Time: 2015-9-02
 Ver.: V1.0
 Note;
**************************************************************************************/
void GPIO_InitList(const GPIO_InitStruct *List)
{
	GPIO_InitTypeDef GPIO_InitStructure; 
	uint32_t RCC_APB2Periph_GPIOx; 
	while(List->GPIO_Speed)
	{
		switch((uintbus)List->GPIOx)
	{
		case (uintbus)GPIOA:RCC_APB2Periph_GPIOx=RCC_APB2Periph_GPIOA;break;
		case (uintbus)GPIOB:RCC_APB2Periph_GPIOx=RCC_APB2Periph_GPIOB;break;
		case (uintbus)GPIOC:RCC_APB2Periph_GPIOx=RCC_APB2Periph_GPIOC;break;
		case (uintbus)GPIOD:RCC_APB2Periph_GPIOx=RCC_APB2Periph_GPIOD;break;
		case (uintbus)GPIOE:RCC_APB2Periph_GPIOx=RCC_APB2Periph_GPIOE;break;
		case (uintbus)GPIOF:RCC_APB2Periph_GPIOx=RCC_APB2Periph_GPIOF;break;
	}
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOx|RCC_APB2Periph_AFIO,ENABLE);
	GPIO_InitStructure.GPIO_Speed=(GPIOSpeed_TypeDef)List->GPIO_Speed;
	GPIO_InitStructure.GPIO_Pin=List->GPIO_Pin; 
	GPIO_InitStructure.GPIO_Mode=List->GPIO_Mode;
	GPIO_Init(List->GPIOx, &GPIO_InitStructure);
	List++;
	}
}

void Sys_Speak(uint8 i)
{
#ifdef SPK_ON
	SPK_ON;
	Tos_TaskDelay(2);
	SPK_OFF;
#endif
}
void BareDelay(uint32 i)
{
	uint32 m;
	while(i--)
	{
		m=72000000000/Tos_Cpu_Freq;
		while(m--);
	}
}
void Standby_Init()
{
	GPIO_InitTypeDef   GPIO_InitStructure;      
	NVIC_InitTypeDef NVIC_InitStructure;
	EXTI_InitTypeDef EXTI_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_AFIO, ENABLE);//使能 GPIOA 和复用功能时钟
	GPIO_InitStructure.GPIO_Pin =GPIO_Pin_0;    //PA.0
	GPIO_InitStructure.GPIO_Mode =GPIO_Mode_IPD;//上拉输入
	GPIO_Init(GPIOA, &GPIO_InitStructure);  //初始化 IO
	//使用外部中断方式
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource0); 
	//中断线 0 连接 GPIOA.0
	EXTI_InitStructure.EXTI_Line = EXTI_Line0;  //设置按键所有的外部线路
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;    //设外外部中断模
	//式:EXTI 线路为中断请求
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;   //上升沿触发
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);  //  初始化外部中断
	NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn; //使能按键所在的外部中断通道
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2; //先占优先级 2 级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2; //从优先级 2 级
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //使能外部中断通道
	NVIC_Init(&NVIC_InitStructure); //根据指定的参数初始化 NVIC
	Sys_Enter_Standby();
	
}
void EXTI0_IRQHandler(void)
{                          
	
	EXTI_ClearITPendingBit(EXTI_Line0); //  清除 LINE10 上的中断标志位   
	MCU_Reset();	
} 
void Sys_Standby(void)
{  
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR, ENABLE);  //使能 PWR 外设时钟
	PWR_WakeUpPinCmd(ENABLE);   //使能唤醒管脚功能
	PWR_BackupAccessCmd(ENABLE);
	//PWR_EnterSTANDBYMode();    //进入待命（STANDBY）模式       
	PWR_EnterSTOPMode(PWR_Regulator_LowPower, PWR_STOPEntry_WFE);
}
//系统进入待机模式
void Sys_Enter_Standby(void)
{     
	RCC_APB2PeriphResetCmd(0X01FC,DISABLE);  //复位所有 IO 口
	Sys_Standby();
}
void MCU_Reset(void)
{
	__disable_fault_irq();      // STM32 软复位  
	NVIC_SystemReset();
}

void IWDG_Configuration(void)
{
 IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable); /* 写入0x5555,用于允许狗狗寄存器写入功能 */
 IWDG_SetPrescaler(IWDG_Prescaler_256); /* 狗狗时钟分频,40K/256=156HZ(6.4ms)*/
 IWDG_SetReload(0xff0);/* 喂狗时间 5s/6.4MS=781 .注意不能大于0xfff*/
 IWDG_ReloadCounter();/* 喂狗*/
 IWDG_Enable(); /* 使能狗狗*/
}
