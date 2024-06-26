

#include "delay.h"
#include "main.h"
////////////////////////////////////////////////////////////////////////////////// 	 


//////////////////////////////////////////////////////////////////////////////////  


//STM32H7开发板
//使用SysTick的普通计数模式对延迟进行管理(支持ucosii)
//包括delay_us,delay_ms

//STM32H7工程模板-HAL库函数版本
//DevEBox  大越创新
//淘宝店铺：mcudev.taobao.com
//淘宝店铺：devebox.taobao.com	
////////////////////////////////////////////////////////////////////////////////// 

////static u32 fac_us=0;							//us延时倍乘数














/////*******************************************************************************/

//////初始化延迟函数

//////SYSTICK的时钟固定为AHB时钟的1/8
//////SYSCLK:系统时钟频率

//////STM32H7工程模板-HAL库函数版本
//////DevEBox  大越创新
//////淘宝店铺：mcudev.taobao.com
//////淘宝店铺：devebox.taobao.com	

/////*******************************************************************************/


////void delay_init(u16 SYSCLK)
////{

////  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);//SysTick频率为HCLK
////	fac_us=SYSCLK;						                           

////}								    


///////*******************************************************************************/

////////延时nus
////////nus为要延时的us数.	
////////注意:nus的值不要大于1000us

////////STM32H7工程模板-HAL库函数版本
////////DevEBox  大越创新
////////淘宝店铺：mcudev.taobao.com
////////淘宝店铺：devebox.taobao.com	

///////*******************************************************************************/


//////void delay_us(u32 nus)
//////{		
//////	u32 ticks;
//////	u32 told,tnow,tcnt=0;
//////	u32 reload=SysTick->LOAD;				  //LOAD的值	 
//////	
//////	ticks=nus*fac_us; 						    //需要的节拍数 
//////	told=SysTick->VAL;        				//刚进入时的计数器值
//////	while(1)
//////	{
//////		tnow=SysTick->VAL;	
//////		if(tnow!=told)
//////		{	    
//////			if(tnow<told)tcnt+=told-tnow;	//这里注意一下SYSTICK是一个递减的计数器就可以了.
//////			else tcnt+=reload-tnow+told;	    
//////			told=tnow;
//////			if(tcnt>=ticks)break;			//时间超过/等于要延迟的时间,则退出.
//////		}  
//////	};
//////}
 
/*******************************************************************************/

//延时nms
//nms:要延时的ms数

//STM32H7工程模板-HAL库函数版本
//DevEBox  大越创新
//淘宝店铺：mcudev.taobao.com
//淘宝店铺：devebox.taobao.com	

/*******************************************************************************/


void delay_ms(uint32_t nms)
{
////	u32 i;
////	for(i=0;i<nms;i++) delay_us(1000);
	
	delay_ms(nms);
	
}







//STM32H7工程模板-HAL库函数版本
//DevEBox  大越创新
//淘宝店铺：mcudev.taobao.com
//淘宝店铺：devebox.taobao.com	

























