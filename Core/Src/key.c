#include "key.h"
#include "delay.h"
//////////////////////////////////////////////////////////////////////////////////	 

//KEY��������	   


//STM32H7����ģ��-HAL�⺯���汾
//DevEBox  ��Խ����
//�Ա����̣�mcudev.taobao.com
//�Ա����̣�devebox.taobao.com								  
//////////////////////////////////////////////////////////////////////////////////


/************************************************************************************/

//������ʼ������


//STM32H7����ģ��-HAL�⺯���汾
//DevEBox  ��Խ����
//�Ա����̣�mcudev.taobao.com
//�Ա����̣�devebox.taobao.com	


/************************************************************************************/

void KEY_Init(void)
{
    GPIO_InitTypeDef GPIO_Initure;

	  
    __HAL_RCC_GPIOC_CLK_ENABLE();           //����GPIOCʱ��
    __HAL_RCC_GPIOE_CLK_ENABLE();           //����GPIOEʱ��

    
	  GPIO_Initure.Pin=GPIO_PIN_3;            //PE3  :��Ӧ K1
    GPIO_Initure.Mode=GPIO_MODE_INPUT;      //����
    GPIO_Initure.Pull=GPIO_PULLUP;          //����
    GPIO_Initure.Speed=GPIO_SPEED_FREQ_VERY_HIGH;     //����
    HAL_GPIO_Init(GPIOE,&GPIO_Initure);
	
		GPIO_Initure.Pin=GPIO_PIN_5;            //PC5  :��Ӧ K2
    GPIO_Initure.Mode=GPIO_MODE_INPUT;      //����
    GPIO_Initure.Pull=GPIO_PULLUP;          //����
    GPIO_Initure.Speed=GPIO_SPEED_FREQ_VERY_HIGH;     //����
    HAL_GPIO_Init(GPIOC,&GPIO_Initure);
		
    

}


/************************************************************************************/

//����������
//���ذ���ֵ
//mode:0,��֧��������;1,֧��������;
//0��û���κΰ�������
//1��WKUP���� WK_UP
//ע��˺�������Ӧ���ȼ�,KEY1>KEY2


//STM32H7����ģ��-HAL�⺯���汾
//DevEBox  ��Խ����
//�Ա����̣�mcudev.taobao.com
//�Ա����̣�devebox.taobao.com	


/************************************************************************************/

static uint8_t key_up=1;     //�����ɿ���־

uint8_t KEY_Scan(uint8_t mode)
{
    
    if(mode==1)key_up=1;    //֧������
    if(key_up&&(KEY1==0||KEY2==0))
    {
        HAL_Delay(10);
        key_up=0;
        if(KEY1==0)  return KEY1_PRES;
        else if(KEY2==0)  return KEY2_PRES;
        
    }else if(KEY1==1&&KEY2==1)key_up=1;
    return 0;   //�ް�������
}


/************************************************************************************/

//�������Գ��򣬷���ѭ����ѯ������ֵ


//STM32H7����ģ��-HAL�⺯���汾
//DevEBox  ��Խ����
//�Ա����̣�mcudev.taobao.com
//�Ա����̣�devebox.taobao.com	


/************************************************************************************/

uint8_t key;
uint8_t LED2_sta = 0;


void KEY_Test(void)
{

		key=KEY_Scan(0); 		//�õ���ֵ
		
	  if(key)
		{						   
			switch(key)
			{	
				case KEY1_PRES:	//����LED2����
					
				  LED2_sta=0;
				  printf("\r\n KEY1 ��������һ�� \r\n");
					break;

				case KEY2_PRES:	//����LED2��ת	 
					
	 				LED2_sta=!LED2_sta;
				
				  printf("\r\n KEY2 ��������һ�� \r\n");
				
					break;

			}
			
			LED2(LED2_sta);		//����LED1״̬
		}
		else 
			HAL_Delay(10); 

	}

	
	
	
	
	
	
	
	
	
	
	
	
	
	

//STM32H7����ģ��-HAL�⺯���汾
//DevEBox  ��Խ����
//�Ա����̣�mcudev.taobao.com
//�Ա����̣�devebox.taobao.com	












