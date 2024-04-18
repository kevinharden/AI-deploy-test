


#ifndef __SCCB_H
#define __SCCB_H

#include "ov5640.h"

//////////////////////////////////////////////////////////////////////////////////	 
 
/************************************************************************************************/

//OVϵ������ͷ SCCB ��������	  

//STM32H7����ģ��-HAL�⺯���汾
//DevEBox  ��Խ����
//�Ա����̣�mcudev.taobao.com
//�Ա����̣�shop389957290.taobao.com	


/************************************************************************************************/
#define u8 uint8_t
#define u16 uint16_t
////////////////////////////////////////////////////////////////////////////////// 	
//IO��������


//IO����
#define SCCB_SCL(n)  (n?HAL_GPIO_WritePin(GPIOB,GPIO_PIN_10,GPIO_PIN_SET):HAL_GPIO_WritePin(GPIOB,GPIO_PIN_10,GPIO_PIN_RESET)) //SCL--PB10
#define SCCB_SDA(n)  (n?HAL_GPIO_WritePin(GPIOB,GPIO_PIN_11,GPIO_PIN_SET):HAL_GPIO_WritePin(GPIOB,GPIO_PIN_11,GPIO_PIN_RESET)) //SDA--PB11

#define SCCB_READ_SDA    HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_11)     //����SDA--PB11
#define SCCB_ID          0X60                                    //OVxxxx ��ID

///////////////////////////////////////////
void SCCB_Init(void);
	
void SCCB_SDA_IN(void);//IO��������
void SCCB_SDA_OUT(void);//IO��������
	
void SCCB_Start(void);
void SCCB_Stop(void);
void SCCB_No_Ack(void);
u8 SCCB_WR_Byte(u8 dat);
u8 SCCB_RD_Byte(void);
//u8 SCCB_WR_Reg(u8 reg,u8 data);
//u8 SCCB_RD_Reg(u8 reg);
#endif





































/************************************************************************************************/


//STM32H7����ģ��-HAL�⺯���汾
//DevEBox  ��Խ����
//�Ա����̣�mcudev.taobao.com
//�Ա����̣�shop389957290.taobao.com	


/************************************************************************************************/

