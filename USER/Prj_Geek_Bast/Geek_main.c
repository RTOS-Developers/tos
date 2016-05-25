#include <Include.h>
#include <Driver_Include.h>
#include <Tools_Include.h>
#include <Tos_Mema.h>
#include <FuncTask_Include.h>
#include <..\USER\Prj_Geek_Bast\IO_Driver.c>
#include <..\USB\STM32_USB-FS-Device_Driver\USB_FS_Device_Driver.c>
#include <..\USER\Prj_Geek_Bast\usb_desc.c>
#include <..\USER\Prj_Geek_Bast\hw_config.c>
#include <..\USER\Prj_Geek_Bast\usb_endp.c>
#include <..\USER\Prj_Geek_Bast\usb_istr.c>
#include <..\USER\Prj_Geek_Bast\usb_prop.c>
#include <..\USER\Prj_Geek_Bast\usb_pwr.c>
#include <..\USER\Prj_Geek_Bast\Explainer.c>

typedef struct Text
{
	struct Text *NextAddr;
	char  Line;
}Text;
void Task0(void *Tags)
{
	Remap_SWJ_JTAGDisable();
	LED1_ON;
	LED2_ON;
	LED3_ON;
	LED4_ON;
	Tos_TaskDelay(100);
	LED1_OFF;
	LED2_OFF;
	LED3_OFF;
	LED4_OFF;
	while(1)
	{	
	Tos_TaskDelay(1000);
	LED5_ON;
	Tos_TaskDelay(1);
	LED5_OFF;
	}
}
void VisualCOM_Writes(char *Buf,uint16 Length)
{
	UserToPMABufferCopy((uint8 *)Buf, ENDP1_TXADDR, Length);
	SetEPTxCount(ENDP1, Length);
	SetEPTxValid(ENDP1);
	Tos_TaskDelay(10);
}
Text *TT;

void Task1(void *Tags)
{
	Text *T;
	Set_System();
  Set_USBClock();
  USB_Interrupts_Config();
  USB_Init();
	while(1)
	{
		Tos_TaskDelay(1000);
		T=TT;
		while(T!=0)
		{
		VisualCOM_Writes(&T->Line,GetTextLength(&T->Line));
		Bast_Export(&T->Line);
		T=T->NextAddr;
		}
	}
}
void Text_Join(Text *T,uint8 *Str)
{
	Text *t=T;
	uint8 Length;
	Length=GetTextLength(Str);
	if(TT==0)
	{
		TT=Mema_Malloc(Length+5);
		TT->NextAddr=0;
		StringCoppy(Str,&TT->Line);
		return;
	}
	while(t->NextAddr!=0)
	{
		t=t->NextAddr;
	}
	t->NextAddr=Mema_Malloc(Length+5);
	StringCoppy(Str,&t->NextAddr->Line);
	t->NextAddr->NextAddr=0;
}
void Task2(void *Tags)
{
	Set_System();
  Set_USBClock();
  USB_Interrupts_Config();
  USB_Init();
	Text_Join(TT,"task1\n");
	Text_Join(TT,"port.cfg(pa0,out)\n");
	Text_Join(TT,"port.cfg(pa1,out)\n");
	Text_Join(TT,"loop\n");
	Text_Join(TT,"{\n");
	Text_Join(TT," delay.ms.1000\n");
	Text_Join(TT," port.set(pc0,0)\n");
	Text_Join(TT," delay.ms.1000\n");
	Text_Join(TT," port.set(pc0,1)\n");
	Text_Join(TT,"}\n");
	while(1)
	{
		if ((count_out != 0) && (bDeviceState == CONFIGURED))
    {
			
			UserToPMABufferCopy(buffer_out, ENDP1_TXADDR, count_out);
			SetEPTxCount(ENDP1, count_out);
			SetEPTxValid(ENDP1);
      count_out = 0;
    }
		Tos_TaskDelay(100);
	}
}
const TaskInitList TaskList[]={
{Task0,Null,"Task0",2000},
{Task1,Null,"Task0",2000},
{Task2,Null,"Task0",2000},
{Task_Arrary,Null,"Task_Arrary",2000},
{Null},
};
const GPIO_InitStruct IO_List[]=
{
	{GPIO_Speed_2MHz,GPIO_Mode_Out_PP,GPIOC,GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3},
	{GPIO_Speed_2MHz,GPIO_Mode_Out_PP,GPIOA,GPIO_Pin_15},
	{0},
};
int main(void)
{
	NVIC_SetVectorTable(NVIC_VectTab_FLASH, 0x5000); 
	Mema_Init(&MemBuf[0]);
	DeviceList_Init();
	DeviceMount_Usart(USART1);
	DeviceMount_IO(IO_List);
	Tos_ListCreate(TaskList);
	while(1);
}



