#ifndef _DELAY_H
#define _DELAY_H
#include "main.h"	  
//////////////////////////////////////////////////////////////////////////////////  

//STM32H7������
//ʹ��SysTick����ͨ����ģʽ���ӳٽ��й���(֧��ucosii)
//����delay_us,delay_ms

//STM32H7����ģ��-HAL�⺯���汾
//DevEBox  ��Խ����
//�Ա����̣�mcudev.taobao.com
//�Ա����̣�devebox.taobao.com	
//********************************************************************************
////////////////////////////////////////////////////////////////////////////////// 

void HAL_IncTick(void);
void delay_ms(uint32_t Delay);

//void delay_init(u16 SYSCLK);
void delay_ms(uint32_t nms);
//void delay_us(u32 nus);
#endif









//STM32H7����ģ��-HAL�⺯���汾
//DevEBox  ��Խ����
//�Ա����̣�mcudev.taobao.com
//�Ա����̣�devebox.taobao.com	

