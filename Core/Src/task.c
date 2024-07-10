#include "task.h"
#include "stdint.h"
#include "stdio.h"
#include "main.h"
#include "usart.h"
#include "gpio.h"
#include <string.h>
#include "math.h"

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
	
//字符串发送函数
void HMISends(uint8_t *buf1)		  
{
	uint8_t i=0;
	while(1)
	{
		if(buf1[i] != 0)
	 	{

		  HAL_UART_Transmit(&huart1, buf1+i, 1, 1);//发送一个字节
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

//字节发送函数
void HMISendb(uint8_t k)		         
{		 
	uint8_t i;
	 for(i=0; i<3; i++)
	 {
			if(k != 0)
			{
		  HAL_UART_Transmit(&huart1, &k, 1, 1);//发送一个字节
	while(HAL_UART_GetState(&huart1) == HAL_UART_STATE_BUSY_TX);
			}
			else
			{
				return ;
			}
	 } 
} 



