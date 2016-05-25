#ifndef _BOARD_DRIVER_H_
#define _BOARD_DRIVER_H_

#include <Include.h>


typedef struct 
{
	uint8 GPIO_Speed;
	GPIOMode_TypeDef GPIO_Mode;
	GPIO_TypeDef *GPIOx;
	uint16 GPIO_Pin;
}GPIO_InitStruct;


/////定义蜂鸣器端口
//#if defined(BOARD_LCD4_3)
//#define SPK_ON  GPIO_SetBits(GPIOB,GPIO_Pin_5)   
//#define SPK_OFF GPIO_ResetBits(GPIOB,GPIO_Pin_5)
//#elif defined(BOARD_TANK_Hand)
//#define SPK_OFF  GPIO_SetBits(GPIOD,GPIO_Pin_6)   
//#define SPK_ON GPIO_ResetBits(GPIOD,GPIO_Pin_6)
//#endif//结束定义蜂鸣器端口

/////定义LED端口
//#if defined(BOARD_LCD4_3)
//#define LED_ON  GPIO_ResetBits(GPIOC,GPIO_Pin_7)
//#define LED_OFF GPIO_SetBits(GPIOC,GPIO_Pin_7) 

//#elif defined(BOARD_CORE1_0)
//#define LED_ON  GPIO_ResetBits(GPIOB,GPIO_Pin_11)
//#define LED_OFF GPIO_SetBits(GPIOB,GPIO_Pin_11) 

//#elif defined(BOARD_REALLY)
//#define LED_ON  GPIO_ResetBits(GPIOB,GPIO_Pin_14)
//#define LED_OFF GPIO_SetBits(GPIOB,GPIO_Pin_14) 
//#define WIRE_ON  GPIO_ResetBits(GPIOB,GPIO_Pin_12)
//#define WIRE_OFF GPIO_SetBits(GPIOB,GPIO_Pin_12) 
//#define LCD_ON  GPIO_ResetBits(GPIOB,GPIO_Pin_13)
//#define LCD_OFF GPIO_SetBits(GPIOB,GPIO_Pin_13) 

//#elif defined(BOARD_PRAFIRE)
//#define LED1_ON  GPIO_ResetBits(GPIOC,GPIO_Pin_3)
//#define LED1_OFF GPIO_SetBits(GPIOC,GPIO_Pin_3) 
//#define LED2_ON  GPIO_ResetBits(GPIOC,GPIO_Pin_4)
//#define LED2_OFF GPIO_SetBits(GPIOC,GPIO_Pin_4) 
//#define LED3_ON  GPIO_ResetBits(GPIOC,GPIO_Pin_5)
//#define LED3_OFF GPIO_SetBits(GPIOC,GPIO_Pin_5) 

//#elif defined(BOARD_PDATRAN)
//#define LED_ON  GPIO_ResetBits(GPIOB,GPIO_Pin_11)
//#define LED_OFF GPIO_SetBits(GPIOB,GPIO_Pin_11) 

//#elif defined(BOARD_TWOCAN)
//#define LED1_ON  GPIO_ResetBits(GPIOC,GPIO_Pin_0)
//#define LED1_OFF GPIO_SetBits(GPIOC,GPIO_Pin_0) 
//#define LED2_ON  GPIO_ResetBits(GPIOC,GPIO_Pin_1)
//#define LED2_OFF GPIO_SetBits(GPIOC,GPIO_Pin_1) 
//#define LED3_ON  GPIO_ResetBits(GPIOC,GPIO_Pin_14)
//#define LED3_OFF GPIO_SetBits(GPIOC,GPIO_Pin_14) 
//#define LED4_ON  GPIO_ResetBits(GPIOC,GPIO_Pin_15)
//#define LED4_OFF GPIO_SetBits(GPIOC,GPIO_Pin_15) 

//#elif defined(BOARD_TANK_Hand)
//#define LED1_ON  GPIO_ResetBits(GPIOD,GPIO_Pin_9)
//#define LED1_OFF GPIO_SetBits(GPIOD,GPIO_Pin_9) 
//#define LED2_ON  GPIO_ResetBits(GPIOD,GPIO_Pin_8)
//#define LED2_OFF GPIO_SetBits(GPIOD,GPIO_Pin_8) 
//#define LED3_ON  GPIO_ResetBits(GPIOB,GPIO_Pin_15)
//#define LED3_OFF GPIO_SetBits(GPIOB,GPIO_Pin_15) 
//#define LED4_ON  GPIO_ResetBits(GPIOC,GPIO_Pin_15)
//#define LED4_OFF GPIO_SetBits(GPIOC,GPIO_Pin_15) 

//#define POWER_DIS GPIO_ResetBits(GPIOB,GPIO_Pin_2)
//#define POWER_EN GPIO_SetBits(GPIOB,GPIO_Pin_2)

//#elif defined(BOARD_TANK_Ctr)
//#define LED1_ON  GPIO_ResetBits(GPIOE,GPIO_Pin_2)
//#define LED1_OFF GPIO_SetBits(GPIOE,GPIO_Pin_2) 
//#define LED2_ON  GPIO_ResetBits(GPIOE,GPIO_Pin_3)
//#define LED2_OFF GPIO_SetBits(GPIOE,GPIO_Pin_3) 
//#define LED3_ON  GPIO_ResetBits(GPIOE,GPIO_Pin_4)
//#define LED3_OFF GPIO_SetBits(GPIOE,GPIO_Pin_4) 
//#elif defined(BOARD_TANK_Ctr1)
//#define LED1_ON  GPIO_ResetBits(GPIOE,GPIO_Pin_2)
//#define LED1_OFF GPIO_SetBits(GPIOE,GPIO_Pin_2) 
//#define LED2_ON  GPIO_ResetBits(GPIOE,GPIO_Pin_3)
//#define LED2_OFF GPIO_SetBits(GPIOE,GPIO_Pin_3) 
//#define LED3_ON  GPIO_ResetBits(GPIOE,GPIO_Pin_4)
//#define LED3_OFF GPIO_SetBits(GPIOE,GPIO_Pin_4) 
//#elif defined(BOARD_TS_Collect)
//#define LED1_ON  GPIO_ResetBits(GPIOE,GPIO_Pin_2)
//#define LED1_OFF GPIO_SetBits(GPIOE,GPIO_Pin_2) 
//#define LED2_ON  GPIO_ResetBits(GPIOE,GPIO_Pin_3)
//#define LED2_OFF GPIO_SetBits(GPIOE,GPIO_Pin_3) 
//#define LED3_ON  GPIO_ResetBits(GPIOE,GPIO_Pin_4)
//#define LED3_OFF GPIO_SetBits(GPIOE,GPIO_Pin_4) 
//#elif defined(BOARD_NJSIGDOT)
//#define LED1_ON  GPIO_ResetBits(GPIOE,GPIO_Pin_2)
//#define LED1_OFF GPIO_SetBits(GPIOE,GPIO_Pin_2) 
//#define LED2_ON  GPIO_ResetBits(GPIOE,GPIO_Pin_3)
//#define LED2_OFF GPIO_SetBits(GPIOE,GPIO_Pin_3) 
//#define LED3_ON  GPIO_ResetBits(GPIOE,GPIO_Pin_4)
//#define LED3_OFF GPIO_SetBits(GPIOE,GPIO_Pin_4) 
//#else 
////	#warning "TOS提示：您确定您的硬件上一个指示灯都不要吗？"  
//#endif
extern uint8 DeviceId_LED;
extern uint8 DeviceId_BUZZER;
void RCC_Configuration(void);
void DeviceMount_Led(void);
void DeviceMount_Spk(void);
void DeviceMount_Ctr(void);
void Sys_Standby(void);
void BareDelay(uint32 i);
void MCU_Reset(void);
void Sys_Enter_Standby(void);
void IWDG_Configuration(void);
void assert_failed(uint8_t* file, uint32_t line);
void Sys_Speak(uint8 i);
void Remap_SWJ_JTAGDisable(void);
void GPIO_InitList(const GPIO_InitStruct *List);
void Standby_Init(void);
#endif
