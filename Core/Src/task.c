#include "task.h"
#include "stdint.h"
#include "stdio.h"
#include "main.h"
#include "usart.h"
#include "gpio.h"
#include <string.h>
#include "math.h"
#include "lcd.h"
#include "ov5640.h"
#include <w25qxx.h>
#include "OV_Frame.h"
#include "sdmmc_sdcard.h"

extern uint8_t Textbuf[32];
extern uint8_t  OV_mode;				//bit0:  1,RGB565ģʽ;2,JPEGģʽ		
extern uint16_t Camera_ID;      //����ͷ�ͺ�ID��
extern uint8_t Print_buf[32];	//��Ϣ������
//delay
void My_delay_us(uint32_t n)
{
    uint32_t ticks;
    uint32_t told;
    uint32_t tnow;
    uint32_t tcnt = 0;
    uint32_t reload;
       
	reload = SysTick->LOAD;                
    ticks = n * (SystemCoreClock / 1000000);	
    
    tcnt = 0;
    told = SysTick->VAL;             
 
    while (1)
    {
        tnow = SysTick->VAL;    
        if (tnow != told)
        {    
            if (tnow < told)
            {
                tcnt += told - tnow;    
            }
            else
            {
                tcnt += reload - tnow + told;    
            }        
            told = tnow;
 
            if (tcnt >= ticks)
            {
            	break;
            }
        }  
    }
} 

void My_delay_ms(uint32_t t)
{
	
My_delay_us(1000*t);
}

void HMISendstart(void)
{
	 	My_delay_ms(200);
		HMISendb(0xff);
		My_delay_ms(200);
	}
	
//�ַ������ͺ���
void HMISends(uint8_t *buf1)		  
{
	uint8_t i=0;
	while(1)
	{
		if(buf1[i] != 0)
	 	{

		  HAL_UART_Transmit(&huart1, buf1+i, 1, 1);//����һ���ֽ�
	while(HAL_UART_GetState(&huart1) == HAL_UART_STATE_BUSY_TX)
		;
		 	i++;
		}
		else
		{
			return ;
		}
	}
}

//�ֽڷ��ͺ���
void HMISendb(uint8_t k)		         
{		 
	uint8_t i;
	 for(i=0; i<3; i++)
	 {
			if(k != 0)
			{
		  HAL_UART_Transmit(&huart1, &k, 1, 1);//����һ���ֽ�
	while(HAL_UART_GetState(&huart1) == HAL_UART_STATE_BUSY_TX);
			}
			else
			{
				return ;
			}
	 } 
} 

void Camera_Init()
{
	Draw_Font16B(16,10,RED,"  STM32H7 DCMI OV5640 ");
	 Draw_Font16B(16,30,BLUE,"     Ƕ��ʽ������   ");	 
	 Draw_Font16B(16,50,BLUE," mcudev.taobao.com  "); 
	 

	if(W25QXX_ReadID()!=W25Q64)
		Draw_Font16B(16,80,RED,"W25Q64 Error!");	//���W25Q128����
	else //SPI FLASH ����
	{   														 
		Draw_Font16B(16,80,BLUE,"W25Q64 OK OK OK ");	 
		Draw_Font16B(16,100,BLUE,"SPI FLASH Size:8MB");	 
	} 

	
	  while(SD_Init())//��ⲻ��SD��
    {
        Draw_Font16B(16,140,RED,"SD Card Error!");
			  Draw_Font16B(16,160,RED,"Please Check! ");
        HAL_Delay(500);
        Draw_Font16B(16,160,RED,"               ");
        HAL_Delay(500);

    }
		
		
                                       
    Draw_Font16B(16,140,BLUE,"SD Card OK    "); //���SD���ɹ�
		
		sprintf((char*)Textbuf,"SD Card Size: %u MB",SDCardInfo.CardCapacity>>20); //��ʾ�޷���ʮ��������		
   
		Draw_Font16B(16,160,BLUE,Textbuf);  				//��ʾ�洢������


    while(OV5640_Init())//��ʼ��OV5640
    {
        Draw_Font16B(24,200,RED,"OV5640 ERROR");
        HAL_Delay(200);
        Draw_Font16B(24,200,RED,"             ");
        HAL_Delay(200);
				HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_1);
    }
		
		if(Camera_ID!=OV5640_ID)
			   sprintf((char*)Print_buf,"Camera_ID: ERR");
			else 
				 sprintf((char*)Print_buf,"Camera_ID: 0x%4X",Camera_ID);
				
		 Draw_Font16B(24,200,BLUE,Print_buf);//��ʾ��ʾ����

     Draw_Font16B(24,220,BLUE,"OV5640 OK");	
		
		HAL_Delay(1000);
}


