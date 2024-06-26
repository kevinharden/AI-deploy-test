#ifndef _DELAY_H
#define _DELAY_H
#include "main.h"	  
//////////////////////////////////////////////////////////////////////////////////  

//STM32H7开发板
//使用SysTick的普通计数模式对延迟进行管理(支持ucosii)
//包括delay_us,delay_ms

//STM32H7工程模板-HAL库函数版本
//DevEBox  大越创新
//淘宝店铺：mcudev.taobao.com
//淘宝店铺：devebox.taobao.com	
//********************************************************************************
////////////////////////////////////////////////////////////////////////////////// 

void HAL_IncTick(void);
void delay_ms(uint32_t Delay);

//void delay_init(u16 SYSCLK);
void delay_ms(uint32_t nms);
//void delay_us(u32 nus);
#endif









//STM32H7工程模板-HAL库函数版本
//DevEBox  大越创新
//淘宝店铺：mcudev.taobao.com
//淘宝店铺：devebox.taobao.com	

