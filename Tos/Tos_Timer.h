
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
/*---------------------��ʱ���ṹ----------------------------*/
//����ʱ���̶���100ms��ʱ��������
//���ʱʱ��Ϊ25.5S
typedef struct _Tos_Timer
{
	uint8 ID;								//��ʱ��ID��
	struct _Tos_Timer *NextTimer;			//ָ����һ����ʱ��
	uint16 Interval;							//��ʱ��ʱ����
	uint16 Lifecycle;						//��ʱ���������� 0xFFFF ��������
	uint16 Counter;							//������,�������ڼ���
	uint8 Flags;							//��ʱ����־ B7/Run B6/sta B[5:0]/task_ID
	Func  Function;							//��������
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
