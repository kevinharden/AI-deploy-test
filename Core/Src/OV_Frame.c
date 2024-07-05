
#include "OV_Frame.h"
#include "key.h"

#include "lcd.h"
#include "Dis_Picture.h" 
#include "Text.h"	
#include "GBK_LibDrive.h"	

#include "STM32H7xx_HAL_DCMI.h"

#include "ov5640.h"
#include "dcmi.h"

#include "dma.h"

#include "usart.h"


__attribute__((section (".RAM_D2"))) uint8_t Print_buf[48];	//��Ϣ������

__attribute__((section (".RAM_D2"))) uint8_t Key_Flag; //��ֵ

//////////////////////////////////////////////////////////////////////////////////	 

/************************************************************************************************/
//OV5640--֡������ʾ���� ��������

//STM32H7����ģ��-HAL�⺯���汾
//DevEBox  ��Խ����
//�Ա����̣�mcudev.taobao.com
//�Ա����̣�shop389957290.taobao.com	


/************************************************************************************************/							  
////////////////////////////////////////////////////////////////////////////////// 



/************************************************************************************************/

//OV5640 ����ͷ ������ʾ����  ʹ��2.8��240x320������ʾ��


//STM32H7����ģ��-HAL�⺯���汾
//DevEBox  ��Խ����
//�Ա����̣�mcudev.taobao.com
//�Ա����̣�shop389957290.taobao.com	


/************************************************************************************************/


u8 OV_mode=0;							//bit0:0,RGB565ģʽ;1,JPEGģʽ

u16 yoffset=0;							//y�����ƫ����




#if  USE_HORIZONTAL  

#define RGB_Width    320 //������Ļ�������û����С�͸�ʽ
#define RGB_Height	 240 //������Ļ


#else

#define RGB_Width    240 //������Ļ�������û����С�͸�ʽ
#define RGB_Height	 320//������Ļ

#endif 


#define jpeg_buf_size   320*240+128		//����JPEG���ݻ���jpeg_buf�Ĵ�С(320x240x4+128 �ֽ�)




#define JPEG_buf_size   1024*20   		//����JPEG���ݻ���jpeg_buf�Ĵ�С(RGB_Width*RGB_Height+1024*20 �ֽ�)

#define RGB_buf_size   RGB_Width*RGB_Height   		//����JPEG���ݻ���jpeg_buf�Ĵ�С(RGB_Width*RGB_Height+1024*20 �ֽ�)



__align(4)   uint32_t RGB_Line_DATA[RGB_Width/2]__attribute((at(0X24010000)));            //����һ��    


__align(2)   uint16_t RGB_DATA[RGB_Height][RGB_Width]__attribute((at(0X24010000)));       //����һ��Ļ����    //����һ��Ļ����   


__align(4)   uint32_t JPEG_DATA[1]__attribute((at(0X20010000)));              //JPEG���ݻ���buf,������LCD֡����֮��JPEG_buf_size
 	

uint16_t  curline=0;							   //����ͷ�������,��ǰ�б��





/************************************************************************************************/

//0,����û�вɼ���;
//1,���ݲɼ�����,���ǻ�û����;
//2,�����Ѿ����������,���Կ�ʼ��һ֡����

//JPEG�ߴ�֧���б�

//STM32H7����ģ��-HAL�⺯���汾
//DevEBox  ��Խ����
//�Ա����̣�mcudev.taobao.com
//�Ա����̣�shop389957290.taobao.com	


/************************************************************************************************/


const u16 jpeg_img_size_tbl[][2]=
{
    160,120,	//QQVGA
    320,240,	//QVGA
    640,480,	//VGA
    800,600,	//SVGA
    1024,768,	//XGA
    1280,800,	//WXGA
    1440,900,	//WXGA+
    1280,1024,	//SXGA
    1600,1200,	//UXGA
    1920,1080,	//1080P
    2048,1536,	//QXGA
    2592,1944,	//500W
};





const u8*EFFECTS_TBL[7]= {"Normal","Cool","Warm","B&W","Yellowish ","Inverse","Greenish"};	//7����Ч
const u8*JPEG_SIZE_TBL[12]= {"QQVGA","QVGA","VGA","SVGA","XGA","WXGA","WXGA+","SXGA","UXGA","1080P","QXGA","500W"}; //JPEGͼƬ 12�ֳߴ�


//����һ���ṹ��

union TData
{
	
   uint32_t B32_temp;
   uint8_t  B8_Temp[4];
	
} TData; 


uint8_t Get_Picture=0;//������Ƭ��״̬

uint32_t JPEG_CharSize; //JPEG ���ֽ� ����
 uint32_t JPEG_File_Length; //= JPEG_buf_size;





/************************************************************************************************/
//����  JPEG����  ����
//���ɼ���һ֡JPEG���ݺ�,���ô˺���,�л�JPEG BUF.��ʼ��һ֡�ɼ�.

//STM32H7����ģ��-HAL�⺯���汾
//DevEBox  ��Խ����
//�Ա����̣�mcudev.taobao.com
//�Ա����̣�shop389957290.taobao.com	


/************************************************************************************************/


void Start_OV5640_JPEG(DCMI_HandleTypeDef *hdcmi)
{
	
////		memset((uint8_t *)JPEG_DATA, 0, JPEG_buf_size*4);                                //��ս��ջ�����

    SCB_InvalidateDCache_by_Addr((uint32_t*)JPEG_DATA, JPEG_CharSize);
	
		__HAL_DCMI_ENABLE_IT(hdcmi, DCMI_IER_FRAME_IE);                                      //ʹ��֡�ж�
	  
    HAL_DCMI_Start_DMA(hdcmi, DCMI_MODE_SNAPSHOT, (uint32_t)JPEG_DATA, JPEG_buf_size); 	//���� JPEG��������
		     
	
////    HAL_DCMI_Stop(hdcmi);
	
}


/************************************************************************************************/

//����һ֡ͼ������
//hdcmi:DCMI���  

//STM32H7����ģ��-HAL�⺯���汾
//DevEBox  ��Խ����
//�Ա����̣�mcudev.taobao.com
//�Ա����̣�devebox.taobao.com	


/************************************************************************************************/		



void HAL_DCMI_FrameEventCallback(DCMI_HandleTypeDef *hdcmi)
{
			
	  HAL_DCMI_Suspend(hdcmi); // �������,���� DCMI
	
	  HAL_DCMI_Stop(hdcmi);    // �������,ֹͣDMA����
	
		Get_Picture = 1;
		
}



void HAL_UART_TxHalfCpltCallback(UART_HandleTypeDef *huart)
{
	
	huart->gState=HAL_UART_STATE_READY; 
		
////	HAL_UART_Transmit_IT(huart11,datass,2 );
	
////	DMA_ClearFlag(DMAy_Streamx, DMA_FLAG_TCIFx)
//	__HAL_DCMI_ENABLE_IT(hdcmi, DCMI_IER_FRAME_IE);                                      //ʹ��֡�ж�

}



/************************************************************************************************/
//JPEG����
//JPEG����,ͨ������2���͸�����.

//STM32H7����ģ��-HAL�⺯���汾
//DevEBox  ��Խ����
//�Ա����̣�mcudev.taobao.com
//�Ա����̣�shop389957290.taobao.com	


/************************************************************************************************/


uint8_t  *P_data;

uint32_t i,jpgstart,jpglen;


void JPEG_mode(void)
{
    u32 i,jpgstart,jpglen;
    u8  *p;
    
	  u8  headok=0;
	  u8  effect=0;
	  u8  contrast=2;
    u8 size=1;			               //Ĭ����QVGA 320*240�ߴ�  2.8��Һ����

    USART1_BaudRate_Init(921600);	 //����1 ��ʼ��--������ (460800); (921600); (1382400);

    LCD_Clear(WHITE);  //����
    	
    Draw_Font16B(30,50,BLUE,"DevEBox STM32H750 ");
    Draw_Font16B(30,70,BLUE,"OV5640 JPEG Mode");
	
//    Draw_Font16B(30,100,BLUE,"KEY1:Contrast");			//�Աȶ�
//    Draw_Font16B(30,120,BLUE,"KEY2:Auto Focus"); 		//ִ���Զ��Խ�
//    Draw_Font16B(30,140,BLUE,"KEY2:Effects"); 			//��Ч
//    Draw_Font16B(30,160,BLUE,"KEY_UP:Size");				//�ֱ�������
	
    sprintf((char*)Print_buf,"JPEG Size:%s",JPEG_SIZE_TBL[size]);
	
    Draw_Font16B(30,90,BLUE,Print_buf);					       //��ʾ��ǰJPEG�ֱ���
	 
    //�Զ��Խ���ʼ��
	
    OV5640_Focus_Init();

    delay_ms(50);//��ʱ��ʾ

    OV5640_JPEG_Mode();		//JPEGģʽ

    delay_ms(50);//��ʱ��ʾ

    OV5640_Light_Mode(0);	//�Զ�ģʽ
    OV5640_Color_Saturation(3); //ɫ�ʱ��Ͷ�0
    OV5640_Brightness(4);     	//����0
    OV5640_Contrast(3);		      //�Աȶ�0
    OV5640_Sharpness(33);     	//�Զ����
    OV5640_Focus_Constant();    //���������Խ�
   
	  delay_ms(50);//��ʱ��ʾ
		
    OV5640_OutSize_Set(4,0,jpeg_img_size_tbl[size][0],jpeg_img_size_tbl[size][1]);//��������ߴ�
		
		delay_ms(50);        //��ʱ
		
		Start_OV5640_JPEG(&hdcmi);
		
		delay_ms(1000);        //��ʱ  ��һ֡�����յ��Ļ�Ƚ���
		

		
    while(1)
    {
			
        if(Get_Picture==1)	//�Ѿ��ɼ���һ֡ͼ����
        {
					
					  LED2_Toggle;//LED���� ��ʾϵͳ������
					
            P_data=(uint8_t*)JPEG_DATA;
					
					  JPEG_File_Length = JPEG_buf_size;//�ӻ�����ĩβ��ʼ�ж��Ƿ�Ϊ��
					
					  while (JPEG_File_Length > 0)     //�����  JPEG�Ĵ�С
						{
								if (JPEG_DATA[JPEG_File_Length - 1] != 0x00000000)
								{
										break;
								}
								JPEG_File_Length--;
						}
						
												
						JPEG_CharSize=JPEG_File_Length*4;
					
//            printf("Jpeg_data:%d\r\n",jpeg_data_len*4);//��ӡ֡��
					
           Draw_Font16B(30,150,BLUE,"Sending JPEG ..."); //��ʾ���ڴ�������
						
////////typedef enum
////////{
////////  HAL_DMA_STATE_RESET             = 0x00U,  /*!< DMA not yet initialized or disabled */
////////  HAL_DMA_STATE_READY             = 0x01U,  /*!< DMA initialized and ready for use   */
////////  HAL_DMA_STATE_BUSY              = 0x02U,  /*!< DMA process is ongoing              */
////////  HAL_DMA_STATE_ERROR             = 0x03U,  /*!< DMA error state                     */
////////  HAL_DMA_STATE_ABORT             = 0x04U,  /*!< DMA Abort state                     */
////////}HAL_DMA_StateTypeDef;
					
////					while(HAL_DMA_GetState(&hdma_usart1_tx) == HAL_DMA_STATE_BUSY);

          SCB_CleanDCache_by_Addr((uint32_t*)JPEG_DATA, JPEG_CharSize);
          HAL_UART_Transmit_DMA(&huart1, (uint8_t*)JPEG_DATA, JPEG_CharSize);

          while(HAL_DMA_GetState(&hdma_usart1_tx) == HAL_DMA_STATE_BUSY);
					
           JPEG_CharSize=0;						
						
						
						
						
						Key_Flag=KEY_Scan(0);   //��ȡ��ֵ
						
            if(Key_Flag)	//�а�������,��Ҫ����
            {

                Draw_Font16B(30,210,BLUE,"Quit Sending  ");//��ʾ�˳����ݴ���
							
                switch(Key_Flag)
                {
                case KEY1_PRES:	//�Աȶ�����
                    contrast++;
                    if(contrast>6)contrast=0;
                    OV5640_Contrast(contrast);
                    sprintf((char*)Print_buf,"Contrast:%d",(signed char)contrast-3);
                    break;
                case KEY2_PRES:	//ִ��һ���Զ��Խ�
                    OV5640_Focus_Single();
                    break;
//                case KEY2_PRES:	//��Ч����
//                    effect++;
//                    if(effect>6)effect=0;
//                    OV5640_Special_Effects(effect);//������Ч
//                    sprintf((char*)Print_buf,"%s",EFFECTS_TBL[effect]);
//                    break;
//                case WKUP_PRES:	//JPEG����ߴ�����
//                    size++;
//                    if(size>11)size=0;
//                    OV5640_OutSize_Set(16,4,jpeg_img_size_tbl[size][0],jpeg_img_size_tbl[size][1]);//��������ߴ�
//                    sprintf((char*)Print_buf,"JPEG Size:%s",JPEG_SIZE_TBL[size]);
//                    break;
                }
								
                Draw_Font16B(30,180,BLUE,"               ");//��ʾ��ʾ����
								
                Draw_Font16B(30,180,BLUE,Print_buf);//��ʾ��ʾ����
								
                delay_ms(800);
								
            } 
						
						Draw_Font16B(30,150,BLUE,"Send complete!!");//��ʾ�����������
						
						Get_Picture=2;	//���jpeg���ݴ�������,������DMAȥ�ɼ���һ֡��.
												
						Start_OV5640_JPEG(&hdcmi);//���¿�ʼ����ͼ��
        }
    }
}



/************************************************************************************************/
//����ת�溬˰

//STM32H7����ģ��-HAL�⺯���汾
//DevEBox  ��Խ����
//�Ա����̣�mcudev.taobao.com
//�Ա����̣�shop389957290.taobao.com	


/************************************************************************************************/

static void  Copy_RAM_Data(u16 *P1, u16 *P2, u16 Num)
{
	u16 i;
	
	for(i=0;i<Num;i++)
	{
		*P1++=*P2++;

	}
	
}



/************************************************************************************************/
//RGB�����ݽ��ջص�����

//STM32H7����ģ��-HAL�⺯���汾
//DevEBox  ��Խ����
//�Ա����̣�mcudev.taobao.com
//�Ա����̣�shop389957290.taobao.com	


/************************************************************************************************/



void RGBLine_Shift(DCMI_HandleTypeDef *hdcmi)
{
		
	    	if(curline<lcddev.height)
				{
					
										
////					HAL_DCMI_Suspend(hdcmi); // 
////					HAL_DCMI_Stop(hdcmi);
					
					__HAL_DCMI_ENABLE_IT(hdcmi, DCMI_IER_FRAME_IE);                                          //ʹ��֡�ж�
				
					SCB_InvalidateDCache_by_Addr((uint32_t*)RGB_Line_DATA, RGB_Width/2);  //���ݵ�ַ��Ϣ����Ч���Ӧ�� cache-line
					
					HAL_DCMI_Start_DMA(hdcmi, DCMI_MODE_SNAPSHOT,(uint32_t)&RGB_Line_DATA, RGB_Width/2); 	    //���� JPEG��������
					
					HAL_DMA_Abort(&hdma_memtomem_dma1_stream0);   //��Ҫ��ֹͣDMA������������DMA ����Դ��ַ��Ŀ���ַ
					
					HAL_DMA_Start(&hdma_memtomem_dma1_stream0, (uint32_t)&RGB_Line_DATA, (uint32_t)&RGB_DATA[curline][0], RGB_Width*2); //ʹ��DMAת��һ������
					
  				++curline;
				
				}

		
}






/************************************************************************************************/
//����ʾ���������ݽ���ˢ������

//STM32H7����ģ��-HAL�⺯���汾
//DevEBox  ��Խ����
//�Ա����̣�mcudev.taobao.com
//�Ա����̣�shop389957290.taobao.com	


/************************************************************************************************/



  u16 Num_Dot;
  u16 Num_H;//����
	u16 *R_Buf; //ˢ������ָ��
	
static void  RGB_Refresh_LCD(void)
{
	  
		LCD_Set_Window(0,0,lcddev.width,lcddev.height);//����ȫ������
		
    LCD_SetCursor(0,0);              //������Ļ��ʾ���	
	
    LCD_WR_REG(lcddev.wramcmd);	  
	
		for(Num_H=0;Num_H<lcddev.height;Num_H++)
		{
			
			R_Buf=&RGB_DATA[Num_H][0];
			
			for(Num_Dot=0;Num_Dot<lcddev.width;Num_Dot++)
			{
				
				LCD_WR_DATA16(*R_Buf);	
				R_Buf++;
				
			}
			
	  }
	
	
}






void Start_OV5640_RGB(DCMI_HandleTypeDef *hdcmi)
{
	
	 
	
////		memset((uint8_t *)RGB_DATA, 0, RGB_buf_size*2);                                       //��ս��ջ�����
	
		__HAL_DCMI_ENABLE_IT(hdcmi, DCMI_IER_FRAME_IE);                                       //ʹ��֡�ж�
	    
    HAL_DCMI_Start_DMA(hdcmi, DCMI_MODE_SNAPSHOT, (uint32_t)&RGB_Line_DATA, RGB_Width/2); 	  //���� JPEG��������  ��������
	
	  curline=0;
	
	
}


/************************************************************************************************/
//RGB565����
//RGB����ֱ����ʾ��LCD����

//STM32H7����ģ��-HAL�⺯���汾
//DevEBox  ��Խ����
//�Ա����̣�mcudev.taobao.com
//�Ա����̣�shop389957290.taobao.com	


/************************************************************************************************/

  u8 Key_N;


void RGB565_mode(void)
{
    
    float fac=0;
    u8 effect=0,contrast=2;
    u8 scale=1;		//Ĭ����ȫ�ߴ�����
    
    u16 outputheight=0;

    LCD_Clear(WHITE);
	    	
    Draw_Font16B(30,50,BLUE,"DevEBox STM32H750");
    Draw_Font16B(30,70,BLUE,"OV5640 RGB565 Mode");
	
//    Draw_Font16B(30,100,BLUE,"KEY1:Contrast");			//�Աȶ�
//    Draw_Font16B(30,120,BLUE,"KEY2:Auto Focus"); 		//ִ���Զ��Խ�
//    LCD_ShowString(30,140,200,16,16,"KEY2:Effects"); 			//��Ч
//    LCD_ShowString(30,160,200,16,16,"KEY_UP:FullSize/Scale");	//1:1�ߴ�(��ʾ��ʵ�ߴ�)/ȫ�ߴ�����
	
	
    //�Զ��Խ���ʼ��
    OV5640_RGB565_Mode();	//RGB565ģʽ
    OV5640_Focus_Init();
    OV5640_Light_Mode(0);	//�Զ�ģʽ
    OV5640_Color_Saturation(3);//ɫ�ʱ��Ͷ�0
    OV5640_Brightness(4);	//����0
    OV5640_Contrast(3);		//�Աȶ�0
    OV5640_Sharpness(33);	//�Զ����
    OV5640_Focus_Constant();//���������Խ�
		
		
//    if(lcddev.height==1024)
//    {
//        yoffset=(lcddev.height-800)/2;
//        outputheight=800;
//        OV5640_WR_Reg(0x3035,0X51);//�������֡�ʣ�������ܶ���
//			
//    } 
//		else if(lcddev.height==1280)
//    {
//        yoffset=(lcddev.height-600)/2;
//        outputheight=600;
//        OV5640_WR_Reg(0x3035,0X51);//�������֡�ʣ�������ܶ���
//    }
//		else
//    {
//        yoffset=0;
//        outputheight=lcddev.height;
        OV5640_WR_Reg(0x3035,0X51);//�������֡�ʣ�������ܶ���
//    }
		
		    
		
    OV5640_OutSize_Set(4,0,lcddev.width,lcddev.height);		//����������ʾ
						
    Start_OV5640_RGB(&hdcmi);  //��������
			
    LCD_Clear(BLACK);
		
    while(1)
    {
			
        Key_Flag=KEY_Scan(0);   //��ȡ��ֵ
			
			
			  if(Key_Flag==KEY1_PRES)//����1�л�����
				{
						Key_N++;
						if(Key_N>=3)Key_N=0;
		
					if(Key_N==1)
						{
							Draw_Font16B(30,50,BLUE,"OV5640: DCMI_Stop");//��ʾ��ʾ����
					    delay_ms(800);
							
////							DCMI_Stop(); //��KEY1����,ֹͣ��ʾ
						}
					else if(Key_N==2) 
						{	
							Draw_Font16B(30,50,BLUE,"OV5640: DCMI_Start");//��ʾ��ʾ����
					    delay_ms(800);
							
////							DCMI_Start();	//���¿�ʼ����
						}					
				}
			 else if(Key_Flag==KEY2_PRES)//����1�л�����
				{
					Draw_Font16B(30,50,BLUE,"OV5640: Focus");//��ʾ��ʾ����
					
          delay_ms(800);
					
					OV5640_Focus_Single(); //ִ��һ���Զ��Խ�
				}
				
				
////////////////////        if(Key_Flag)
////////////////////        {
////////////////////					
////////////////////					
////////////////////            if(Key_Flag!=KEY1_PRES)  //û�кܶఴ��
////////////////////							{
////////////////////								
////////////////////							  DCMI_Stop(); //��KEY1����,ֹͣ��ʾ
////////////////////								
////////////////////						   }
////////////////////							
////////////////////            switch(Key_Flag)
////////////////////            {
////////////////////							
////////////////////							
//////////////////////							case KEY1_PRES:	//�Աȶ�����
//////////////////////									contrast++;
//////////////////////									if(contrast>6)contrast=0;
//////////////////////									OV5640_Contrast(contrast);
//////////////////////									sprintf((char*)Print_buf,"Contrast:%d",(signed char)contrast-3);
//////////////////////									break;
////////////////////							case KEY2_PRES:	//ִ��һ���Զ��Խ�
////////////////////									OV5640_Focus_Single();
////////////////////									break;
////////////////////							
////////////////////							
//////////////////////            case KEY2_PRES:	//��Ч����
//////////////////////                effect++;
//////////////////////                if(effect>6)effect=0;
//////////////////////                OV5640_Special_Effects(effect);//������Ч
//////////////////////                sprintf((char*)Print_buf,"%s",EFFECTS_TBL[effect]);
//////////////////////                break;
//////////////////////            case WKUP_PRES:	//1:1�ߴ�(��ʾ��ʵ�ߴ�)/����
//////////////////////                scale=!scale;
//////////////////////                if(scale==0)
//////////////////////                {
//////////////////////                    fac=(float)800/outputheight;	//�õ���������
//////////////////////                    OV5640_OutSize_Set((1280-fac*lcddev.width)/2,(800-fac*outputheight)/2,lcddev.width,outputheight);
//////////////////////                    sprintf((char*)Print_buf,"Full Size 1:1");
//////////////////////                } else
//////////////////////                {
//////////////////////                    OV5640_OutSize_Set(4,0,lcddev.width,outputheight);
//////////////////////                    sprintf((char*)Print_buf,"Scale");
//////////////////////                }
//////////////////////                break;
////////////////////            }
////////////////////            if(Key_Flag!=KEY1_PRES)	//��KEY1����
////////////////////            {
////////////////////                Draw_Font16B(30,50,BLUE,Print_buf);//��ʾ��ʾ����
////////////////////                delay_ms(800);
////////////////////                DCMI_Start();	//���¿�ʼ����
////////////////////            }
////////////////////        }
        	
           LED2_Toggle;//LED���� ��ʾϵͳ������					
				
					 RGB_Refresh_LCD();//����֡���ݣ�����ˢ��
					 
					 Start_OV5640_RGB(&hdcmi);  //��������
				

				 
	    }
}




















uint8_t T_Num;              //ѭ������			


void OV_Camera_Demo(uint8_t Key_Value)
{
	

	  if(Key_Value==KEY1_PRES) 
			{
				Key_Value=0;  //�����ֵ
        OV_mode=1;    //RGB565ģʽ
						
           
      }
    else if(Key_Value==KEY2_PRES) 
			{
				Key_Value=0;//�����ֵ
        OV_mode=2;    //JPEGģʽ
      }
        
				T_Num++;
				
        if(T_Num==100)Draw_Font16B(24,240,RED,"KEY1:RGB565  KEY2:JPEG"); //��˸��ʾ��ʾ��Ϣ
        if(T_Num==200)
        {
            Draw_Font16B(24,240,RED,"                      "); //��˸��ʾ��ʾ��Ϣ
            T_Num=0;
            LED2_Toggle;
					  
        }
     
		 delay_ms(5);
				
				
		if(OV_mode==1) RGB565_mode();       //ѡ��RGBҺ������ʾģʽ	  
			
    else if(OV_mode==2) JPEG_mode();//ѡ��JPEG�������ģʽ
			

}















/************************************************************************************************/

//STM32H7����ģ��-HAL�⺯���汾
//DevEBox  ��Խ����
//�Ա����̣�mcudev.taobao.com
//�Ա����̣�shop389957290.taobao.com	


/************************************************************************************************/





