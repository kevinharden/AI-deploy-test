#include "key.h"
//#include "delay.h"
//////////////////////////////////////////////////////////////////////////////////	 

//KEY驱动代码	   


//STM32H7工程模板-HAL库函数版本
//DevEBox  大越创新
//淘宝店铺：mcudev.taobao.com
//淘宝店铺：devebox.taobao.com								  
//////////////////////////////////////////////////////////////////////////////////


/************************************************************************************/

//按键初始化函数


//STM32H7工程模板-HAL库函数版本
//DevEBox  大越创新
//淘宝店铺：mcudev.taobao.com
//淘宝店铺：devebox.taobao.com	


/************************************************************************************/

void KEY_Init(void)
{
    GPIO_InitTypeDef GPIO_Initure;

	  
    __HAL_RCC_GPIOC_CLK_ENABLE();           //开启GPIOC时钟
    __HAL_RCC_GPIOE_CLK_ENABLE();           //开启GPIOE时钟

    
	  GPIO_Initure.Pin=GPIO_PIN_3;            //PE3  :对应 K1
    GPIO_Initure.Mode=GPIO_MODE_INPUT;      //输入
    GPIO_Initure.Pull=GPIO_PULLUP;          //上拉
    GPIO_Initure.Speed=GPIO_SPEED_FREQ_VERY_HIGH;     //高速
    HAL_GPIO_Init(GPIOE,&GPIO_Initure);
	
		GPIO_Initure.Pin=GPIO_PIN_5;            //PC5  :对应 K2
    GPIO_Initure.Mode=GPIO_MODE_INPUT;      //输入
    GPIO_Initure.Pull=GPIO_PULLUP;          //上拉
    GPIO_Initure.Speed=GPIO_SPEED_FREQ_VERY_HIGH;     //高速
    HAL_GPIO_Init(GPIOC,&GPIO_Initure);
		
    

}


/************************************************************************************/

//按键处理函数
//返回按键值
//mode:0,不支持连续按;1,支持连续按;
//0，没有任何按键按下
//1，WKUP按下 WK_UP
//注意此函数有响应优先级,KEY1>KEY2


//STM32H7工程模板-HAL库函数版本
//DevEBox  大越创新
//淘宝店铺：mcudev.taobao.com
//淘宝店铺：devebox.taobao.com	


/************************************************************************************/

static uint8_t key_up=1;     //按键松开标志

uint8_t KEY_Scan(uint8_t mode)
{
    
    if(mode==1)key_up=1;    //支持连按
    if(key_up&&(KEY1==0||KEY2==0))
    {
        HAL_Delay(10);
        key_up=0;
        if(KEY1==0)  return KEY1_PRES;
        else if(KEY2==0)  return KEY2_PRES;
        
    }else if(KEY1==1&&KEY2==1)key_up=1;
    return 0;   //无按键按下
}


/************************************************************************************/

//按键测试程序，放主循环查询按键键值


//STM32H7工程模板-HAL库函数版本
//DevEBox  大越创新
//淘宝店铺：mcudev.taobao.com
//淘宝店铺：devebox.taobao.com	


/************************************************************************************/

uint8_t key;
uint8_t LED2_sta = 0;


void KEY_Test(void)
{

		key=KEY_Scan(0); 		//得到键值
		
	  if(key)
		{						   
			switch(key)
			{	
				case KEY1_PRES:	//控制LED2点亮
					
				  LED2_sta=0;
				  printf("\r\n KEY1 按键按下一次 \r\n");
					break;

				case KEY2_PRES:	//控制LED2翻转	 
					
	 				LED2_sta=!LED2_sta;
				
				  printf("\r\n KEY2 按键按下一次 \r\n");
				
					break;

			}
			
			LED2(LED2_sta);		//控制LED1状态
		}
		else 
			HAL_Delay(10); 

	}

	
	
	
	
	
	
	
	
	
	
	
	
	
	

//STM32H7工程模板-HAL库函数版本
//DevEBox  大越创新
//淘宝店铺：mcudev.taobao.com
//淘宝店铺：devebox.taobao.com	












