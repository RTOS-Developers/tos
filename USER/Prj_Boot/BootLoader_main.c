#include <Include.h>
#include <Driver_Include.h>
#include <Tools_Include.h>
#include <FuncTask_Include.h>
#include <..\USER\Prj_Boot\BootLoader.h>
#include <..\Driver\SZZigBee_Driver.h>
#include <..\USER\Prj_Boot\BootLoader.c>
#include <..\Driver\SZZigBee_Driver.c>
#include <StandardModBus.h>


void Temp(void *Tags)
{
	Load_EnvConfig();
	while(1)
	{
		Tos_TaskDelay(200);
		WaitDownLoadCount--;	
	 if(enValue.UpdateApp==True)if(enValue.UpdateApp!=0xff)WaitDownLoadCount=10;
	 if(WaitDownLoadCount==0)Application_Run(ApplicationAddress);
	} 
}
const TaskInitList TaskList[]={
{DownLoad_Command,(void *)USART1,"Task0",10000},
{DownLoad_Command,(void *)USART2,"Task1",10000},
{Temp,Null,"Task0",2000},
{Null},
};
int main(void)
{	
	Mema_Init(&MemBuf[0]);
	DeviceList_Init();
	DeviceMount_Usart(USART1);
	DeviceMount_Usart(USART2);
	Tos_ListCreate(TaskList);
	while(1);
}
