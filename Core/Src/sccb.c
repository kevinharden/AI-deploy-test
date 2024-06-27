#include "sccb.h"
#include "delay.h"
//////////////////////////////////////////////////////////////////////////////////	 
   
/************************************************************************************************/
//OVϵ������ͷ SCCB ��������	

//STM32H7����ģ��-HAL�⺯���汾
//DevEBox  ��Խ����
//�Ա����̣�mcudev.taobao.com
//�Ա����̣�shop389957290.taobao.com	


/************************************************************************************************/							  
////////////////////////////////////////////////////////////////////////////////// 	

void SCCB_Delay(void)
{
	u16 i;
	
	for(i=0;i<0xFF;i++);
	
}

void SCCB_Delay_us(u16 D_Time)
{
	u16 i;
	
	for(i=0;i<D_Time;i++);
	
}

/************************************************************************************************/

//��ʼ��SCCB�ӿ�

//STM32H7����ģ��-HAL�⺯���汾
//DevEBox  ��Խ����
//�Ա����̣�mcudev.taobao.com
//�Ա����̣�shop389957290.taobao.com	


/************************************************************************************************/


void SCCB_Init(void)
{
////    GPIO_InitTypeDef GPIO_Initure;
////    __HAL_RCC_GPIOB_CLK_ENABLE();           //ʹ��GPIOBʱ��
////    
////    //PB10--SCL PB11--SDA  ��ʼ������
////    GPIO_Initure.Pin=GPIO_PIN_10|GPIO_PIN_11;
////	
////    GPIO_Initure.Mode=GPIO_MODE_OUTPUT_PP;  //�������
////    GPIO_Initure.Pull=GPIO_PULLUP;          //����
////    GPIO_Initure.Speed=GPIO_SPEED_FREQ_VERY_HIGH;     //����
////    HAL_GPIO_Init(GPIOB,&GPIO_Initure); 
	
}



/************************************************************************************************/

//����SDA--PB11 ����

//STM32H7����ģ��-HAL�⺯���汾
//DevEBox  ��Խ����
//�Ա����̣�mcudev.taobao.com
//�Ա����̣�shop389957290.taobao.com	


/************************************************************************************************/

void SCCB_SDA_IN(void)  //SDA--PB11 ���
{
		GPIO_InitTypeDef GPIO_Initure;
      
    //PB10--SCL PB11--SDA  ��ʼ������
    GPIO_Initure.Pin=GPIO_PIN_11;
	
    GPIO_Initure.Mode=GPIO_MODE_INPUT;      //����ģʽ
    GPIO_Initure.Pull=GPIO_PULLUP;          //����
    GPIO_Initure.Speed=GPIO_SPEED_FREQ_VERY_HIGH;     //����
    HAL_GPIO_Init(GPIOB,&GPIO_Initure); 
	
}

/************************************************************************************************/

//����SDA--PB11 ���

//STM32H7����ģ��-HAL�⺯���汾
//DevEBox  ��Խ����
//�Ա����̣�mcudev.taobao.com
//�Ա����̣�shop389957290.taobao.com	


/************************************************************************************************/
void SCCB_SDA_OUT(void)  //SDA--PB11 ���
{
	
	  GPIO_InitTypeDef GPIO_Initure;
      
    //PB10--SCL PB11--SDA  ��ʼ������
    GPIO_Initure.Pin=GPIO_PIN_11;
	
    GPIO_Initure.Mode=GPIO_MODE_OUTPUT_PP;  //�������
    GPIO_Initure.Pull=GPIO_PULLUP;          //����
    GPIO_Initure.Speed=GPIO_SPEED_FREQ_VERY_HIGH;     //����
    HAL_GPIO_Init(GPIOB,&GPIO_Initure); 
	
}

/************************************************************************************************/
//SCCB��ʼ�ź�
//��ʱ��Ϊ�ߵ�ʱ��,�����ߵĸߵ���,ΪSCCB��ʼ�ź�
//�ڼ���״̬��,SDA��SCL��Ϊ�͵�ƽ

//STM32H7����ģ��-HAL�⺯���汾
//DevEBox  ��Խ����
//�Ա����̣�mcudev.taobao.com
//�Ա����̣�shop389957290.taobao.com	


/************************************************************************************************/


void SCCB_Start(void)
{
    SCCB_SDA(1);     //�����߸ߵ�ƽ	   
    SCCB_SCL(1);	    //��ʱ���߸ߵ�ʱ���������ɸ�����
    SCCB_Delay();  
    SCCB_SDA(0);
    SCCB_Delay();	 
    SCCB_SCL(0);	    //�����߻ָ��͵�ƽ��������������Ҫ	  
}


/************************************************************************************************/
//SCCBֹͣ�ź�
//��ʱ��Ϊ�ߵ�ʱ��,�����ߵĵ͵���,ΪSCCBֹͣ�ź�
//����״����,SDA,SCL��Ϊ�ߵ�ƽ

//STM32H7����ģ��-HAL�⺯���汾
//DevEBox  ��Խ����
//�Ա����̣�mcudev.taobao.com
//�Ա����̣�shop389957290.taobao.com	


/************************************************************************************************/


void SCCB_Stop(void)
{
    SCCB_SDA(0);
    SCCB_Delay();	 
    SCCB_SCL(1);	
    SCCB_Delay(); 
    SCCB_SDA(1);	
    SCCB_Delay();
}  

/************************************************************************************************/
//����NA�ź�

//STM32H7����ģ��-HAL�⺯���汾
//DevEBox  ��Խ����
//�Ա����̣�mcudev.taobao.com
//�Ա����̣�shop389957290.taobao.com	


/************************************************************************************************/


void SCCB_No_Ack(void)
{
	SCCB_Delay();
	SCCB_SDA(1);	
	SCCB_SCL(1);	
	SCCB_Delay();
	SCCB_SCL(0);	
	SCCB_Delay();
	SCCB_SDA(0);	
	SCCB_Delay();
}

/************************************************************************************************/
//SCCB,д��һ���ֽ�
//����ֵ:0,�ɹ�;1,ʧ��. 

//STM32H7����ģ��-HAL�⺯���汾
//DevEBox  ��Խ����
//�Ա����̣�mcudev.taobao.com
//�Ա����̣�shop389957290.taobao.com	


/************************************************************************************************/

u8 SCCB_WR_Byte(u8 dat)
{
	u8 j,res;	 
	for(j=0;j<8;j++) //ѭ��8�η�������
	{
		if(dat&0x80)SCCB_SDA(1);	
		else SCCB_SDA(0);
		dat<<=1;
		SCCB_Delay();
		SCCB_SCL(1);	
		SCCB_Delay();
		SCCB_SCL(0);		   
	}			 
	SCCB_SDA_IN();		//����SDAΪ���� 
	SCCB_Delay();
	SCCB_SCL(1);			//���յھ�λ,���ж��Ƿ��ͳɹ�
	SCCB_Delay();
	if(SCCB_READ_SDA)res=1;  //SDA=1����ʧ�ܣ�����1
	else res=0;         //SDA=0���ͳɹ�������0
	SCCB_SCL(0);		 
	SCCB_SDA_OUT();		//����SDAΪ���    
	return res;  
}

/************************************************************************************************/
//SCCB ��ȡһ���ֽ�
//��SCL��������,��������
//����ֵ:����������

//STM32H7����ģ��-HAL�⺯���汾
//DevEBox  ��Խ����
//�Ա����̣�mcudev.taobao.com
//�Ա����̣�shop389957290.taobao.com	


/************************************************************************************************/

u8 SCCB_RD_Byte(void)
{
	u8 temp=0,j;    
	SCCB_SDA_IN();		//����SDAΪ����  
	for(j=8;j>0;j--) 	//ѭ��8�ν�������
	{		     	  
		SCCB_Delay();
		SCCB_SCL(1);
		temp=temp<<1;
		if(SCCB_READ_SDA)temp++;   
		SCCB_Delay();
		SCCB_SCL(0);
	}	
	SCCB_SDA_OUT();		//����SDAΪ���    
	return temp;
} 

/************************************************************************************************/


//STM32H7����ģ��-HAL�⺯���汾
//DevEBox  ��Խ����
//�Ա����̣�mcudev.taobao.com
//�Ա����̣�shop389957290.taobao.com	


/************************************************************************************************/

////д�Ĵ���
////����ֵ:0,�ɹ�;1,ʧ��.
//u8 SCCB_WR_Reg(u8 reg,u8 data)
//{
//	u8 res=0;
//	SCCB_Start(); 					//����SCCB����
//	if(SCCB_WR_Byte(SCCB_ID))res=1;	//д����ID	 
//	delay_us(100);
//  	if(SCCB_WR_Byte(reg))res=1;		//д�Ĵ�����ַ	  
//	delay_us(100);
//  	if(SCCB_WR_Byte(data))res=1; 	//д����	 
//  	SCCB_Stop();	  
//  	return	res;
//}		  					    
////���Ĵ���
////����ֵ:�����ļĴ���ֵ
//u8 SCCB_RD_Reg(u8 reg)
//{
//	u8 val=0;
//	SCCB_Start(); 				//����SCCB����
//	SCCB_WR_Byte(SCCB_ID);		//д����ID	  
//	delay_us(100);	 
//  	SCCB_WR_Byte(reg);			//д�Ĵ�����ַ	  
//	delay_us(100);	  
//	SCCB_Stop();   
//	delay_us(100);	   
//	//���üĴ�����ַ�󣬲��Ƕ�
//	SCCB_Start();
//	SCCB_WR_Byte(SCCB_ID|0X01);	//���Ͷ�����	  
//	delay_us(100);
//  	val=SCCB_RD_Byte();		 	//��ȡ����
//  	SCCB_No_Ack();
//  	SCCB_Stop();
//  	return val;
//}






























/************************************************************************************************/


//STM32H7����ģ��-HAL�⺯���汾
//DevEBox  ��Խ����
//�Ա����̣�mcudev.taobao.com
//�Ա����̣�shop389957290.taobao.com	


/************************************************************************************************/





