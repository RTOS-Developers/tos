
#ifndef _TOS_TIMER_H_
#define _TOS_TIMER_H_

#include <Include.h>

#define TOS_TIMER_FLAG_START				0x40
#define TOS_TIMER_FLAG_RUN				0x80
#define TOS_TIMER_LIFE_FOREVER			0xFFFF


typedef struct 
{
	uint8 Year;
	uint8 Mon;
	uint8 Day;
	uint8 Week;
	uint8 Hour;
	uint8 Min;
	uint8 Sec;
}Date_Time;
typedef struct 
{
	uint8 Year;
	uint8 Mon;
	uint8 Day;
}Date;
/*---------------------定时器结构----------------------------*/
//任务定时器固定于100ms定时周期运行
//最长定时时间为25.5S
typedef struct _Tos_Timer
{
	uint8 ID;								//定时器ID号
	struct _Tos_Timer *NextTimer;			//指向下一个定时器
	uint16 Interval;							//定时器时间间隔
	uint16 Lifecycle;						//定时器生命周期 0xFFFF 无限生命
	uint16 Counter;							//计数器,用于周期计数
	uint8 Flags;							//定时器标志 B7/Run B6/sta B[5:0]/task_ID
	Func  Function;							//调用任务
}Tos_Timer;	

extern Tos_Timer _Tos_SystemTimer;
Tos_Timer *Tos_TimerFind(uint8 TimerID);
uint8 Tos_TimerCreate(Tos_Timer *NewTimer,uint16 Interval,uint16 Lifecycle,Func Function);
uint8 Tos_TimerAlter(uint8 TimerID,uint16 Interval,uint16 Lifecycle,Func Function);
uint8 Tos_TimerStart(uint8 TimerID);
uint8 Tos_TimerPause(uint8 TimerID);
uint8 Tos_TimerDelete(uint8 TimerID);
void  Tos_TimerScan(void);
void  Tos_TimerExecute(void);
uint8 Tos_TimerCount(void);



#endif																								
