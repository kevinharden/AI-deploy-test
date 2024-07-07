
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


__attribute__((section (".RAM_D2"))) uint8_t Print_buf[48];	//消息缓存区

__attribute__((section (".RAM_D2"))) uint8_t Key_Flag; //键值

//////////////////////////////////////////////////////////////////////////////////	 

/************************************************************************************************/
//OV5640--帧数据显示处理 驱动代码

//STM32H7工程模板-HAL库函数版本
//DevEBox  大越创新
//淘宝店铺：mcudev.taobao.com
//淘宝店铺：shop389957290.taobao.com	


/************************************************************************************************/							  
////////////////////////////////////////////////////////////////////////////////// 



/************************************************************************************************/

//OV5640 摄像头 驱动显示例程  使用2.8寸240x320高清显示屏


//STM32H7工程模板-HAL库函数版本
//DevEBox  大越创新
//淘宝店铺：mcudev.taobao.com
//淘宝店铺：shop389957290.taobao.com	


/************************************************************************************************/


u8 OV_mode=0;							//bit0:0,RGB565模式;1,JPEG模式

u16 yoffset=0;							//y方向的偏移量




#if  USE_HORIZONTAL  

#define RGB_Width    320 //根据屏幕方向，设置缓存大小和格式
#define RGB_Height	 240 //根据屏幕


#else

#define RGB_Width    240 //根据屏幕方向，设置缓存大小和格式
#define RGB_Height	 320//根据屏幕

#endif 


#define jpeg_buf_size   320*240+128		//定义JPEG数据缓存jpeg_buf的大小(320x240x4+128 字节)




#define JPEG_buf_size   1024*20   		//定义JPEG数据缓存jpeg_buf的大小(RGB_Width*RGB_Height+1024*20 字节)

#define RGB_buf_size   RGB_Width*RGB_Height   		//定义JPEG数据缓存jpeg_buf的大小(RGB_Width*RGB_Height+1024*20 字节)



__align(4)   uint32_t RGB_Line_DATA[RGB_Width/2]__attribute((at(0X24010000)));            //缓存一行    


__align(2)   uint16_t RGB_DATA[RGB_Height][RGB_Width]__attribute((at(0X24010000)));       //缓存一屏幕数据    //缓存一屏幕数据   


__align(4)   uint32_t JPEG_DATA[1]__attribute((at(0X20010000)));              //JPEG数据缓存buf,定义在LCD帧缓存之后JPEG_buf_size
 	

uint16_t  curline=0;							   //摄像头输出数据,当前行编号





/************************************************************************************************/

//0,数据没有采集完;
//1,数据采集完了,但是还没处理;
//2,数据已经处理完成了,可以开始下一帧接收

//JPEG尺寸支持列表

//STM32H7工程模板-HAL库函数版本
//DevEBox  大越创新
//淘宝店铺：mcudev.taobao.com
//淘宝店铺：shop389957290.taobao.com	


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





const u8*EFFECTS_TBL[7]= {"Normal","Cool","Warm","B&W","Yellowish ","Inverse","Greenish"};	//7种特效
const u8*JPEG_SIZE_TBL[12]= {"QQVGA","QVGA","VGA","SVGA","XGA","WXGA","WXGA+","SXGA","UXGA","1080P","QXGA","500W"}; //JPEG图片 12种尺寸


//建立一个结构体

union TData
{
	
   uint32_t B32_temp;
   uint8_t  B8_Temp[4];
	
} TData; 


uint8_t Get_Picture=0;//捕获照片的状态

uint32_t JPEG_CharSize; //JPEG 的字节 长度
 uint32_t JPEG_File_Length; //= JPEG_buf_size;





/************************************************************************************************/
//启动  JPEG数据  传输
//当采集完一帧JPEG数据后,调用此函数,切换JPEG BUF.开始下一帧采集.

//STM32H7工程模板-HAL库函数版本
//DevEBox  大越创新
//淘宝店铺：mcudev.taobao.com
//淘宝店铺：shop389957290.taobao.com	


/************************************************************************************************/


void Start_OV5640_JPEG(DCMI_HandleTypeDef *hdcmi)
{
	
////		memset((uint8_t *)JPEG_DATA, 0, JPEG_buf_size*4);                                //清空接收缓冲区

    SCB_InvalidateDCache_by_Addr((uint32_t*)JPEG_DATA, JPEG_CharSize);
	
		__HAL_DCMI_ENABLE_IT(hdcmi, DCMI_IER_FRAME_IE);                                      //使用帧中断
	  
    HAL_DCMI_Start_DMA(hdcmi, DCMI_MODE_SNAPSHOT, (uint32_t)JPEG_DATA, JPEG_buf_size); 	//启动 JPEG传输拍照
		     
	
////    HAL_DCMI_Stop(hdcmi);
	
}


/************************************************************************************************/

//捕获到一帧图像处理函数
//hdcmi:DCMI句柄  

//STM32H7工程模板-HAL库函数版本
//DevEBox  大越创新
//淘宝店铺：mcudev.taobao.com
//淘宝店铺：devebox.taobao.com	


/************************************************************************************************/		



void HAL_DCMI_FrameEventCallback(DCMI_HandleTypeDef *hdcmi)
{
			
	  HAL_DCMI_Suspend(hdcmi); // 拍照完成,挂起 DCMI
	
	  HAL_DCMI_Stop(hdcmi);    // 拍照完成,停止DMA传输
	
		Get_Picture = 1;
		
}



void HAL_UART_TxHalfCpltCallback(UART_HandleTypeDef *huart)
{
	
	huart->gState=HAL_UART_STATE_READY; 
		
////	HAL_UART_Transmit_IT(huart11,datass,2 );
	
////	DMA_ClearFlag(DMAy_Streamx, DMA_FLAG_TCIFx)
//	__HAL_DCMI_ENABLE_IT(hdcmi, DCMI_IER_FRAME_IE);                                      //使用帧中断

}



/************************************************************************************************/
//JPEG测试
//JPEG数据,通过串口2发送给电脑.

//STM32H7工程模板-HAL库函数版本
//DevEBox  大越创新
//淘宝店铺：mcudev.taobao.com
//淘宝店铺：shop389957290.taobao.com	


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
    u8 size=1;			               //默认是QVGA 320*240尺寸  2.8寸液晶屏

    USART1_BaudRate_Init(921600);	 //串口1 初始化--波特率 (460800); (921600); (1382400);

    LCD_Clear(WHITE);  //清屏
    	
    Draw_Font16B(30,50,BLUE,"DevEBox STM32H750 ");
    Draw_Font16B(30,70,BLUE,"OV5640 JPEG Mode");
	
//    Draw_Font16B(30,100,BLUE,"KEY1:Contrast");			//对比度
//    Draw_Font16B(30,120,BLUE,"KEY2:Auto Focus"); 		//执行自动对焦
//    Draw_Font16B(30,140,BLUE,"KEY2:Effects"); 			//特效
//    Draw_Font16B(30,160,BLUE,"KEY_UP:Size");				//分辨率设置
	
    sprintf((char*)Print_buf,"JPEG Size:%s",JPEG_SIZE_TBL[size]);
	
    Draw_Font16B(30,90,BLUE,Print_buf);					       //显示当前JPEG分辨率
	 
    //自动对焦初始化
	
    OV5640_Focus_Init();

    delay_ms(50);//延时显示

    OV5640_JPEG_Mode();		//JPEG模式

    delay_ms(50);//延时显示

    OV5640_Light_Mode(0);	//自动模式
    OV5640_Color_Saturation(3); //色彩饱和度0
    OV5640_Brightness(4);     	//亮度0
    OV5640_Contrast(3);		      //对比度0
    OV5640_Sharpness(33);     	//自动锐度
    OV5640_Focus_Constant();    //启动持续对焦
   
	  delay_ms(50);//延时显示
		
    OV5640_OutSize_Set(4,0,jpeg_img_size_tbl[size][0],jpeg_img_size_tbl[size][1]);//设置输出尺寸
		
		delay_ms(50);        //延时
		
		Start_OV5640_JPEG(&hdcmi);
		
		delay_ms(1000);        //延时  第一帧数据收到的会比较慢
		

		
    while(1)
    {
			
        if(Get_Picture==1)	//已经采集完一帧图像了
        {
					
					  LED2_Toggle;//LED灯闪 提示系统在运行
					
            P_data=(uint8_t*)JPEG_DATA;
					
					  JPEG_File_Length = JPEG_buf_size;//从缓冲区末尾开始判断是否为空
					
					  while (JPEG_File_Length > 0)     //计算出  JPEG的大小
						{
								if (JPEG_DATA[JPEG_File_Length - 1] != 0x00000000)
								{
										break;
								}
								JPEG_File_Length--;
						}
						
												
						JPEG_CharSize=JPEG_File_Length*4;
					
//            printf("Jpeg_data:%d\r\n",jpeg_data_len*4);//打印帧率
					
           Draw_Font16B(30,150,BLUE,"Sending JPEG ..."); //提示正在传输数据
						
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
						
						
						
						
						Key_Flag=KEY_Scan(0);   //获取键值
						
            if(Key_Flag)	//有按键按下,需要处理
            {

                Draw_Font16B(30,210,BLUE,"Quit Sending  ");//提示退出数据传输
							
                switch(Key_Flag)
                {
                case KEY1_PRES:	//对比度设置
                    contrast++;
                    if(contrast>6)contrast=0;
                    OV5640_Contrast(contrast);
                    sprintf((char*)Print_buf,"Contrast:%d",(signed char)contrast-3);
                    break;
                case KEY2_PRES:	//执行一次自动对焦
                    OV5640_Focus_Single();
                    break;
//                case KEY2_PRES:	//特效设置
//                    effect++;
//                    if(effect>6)effect=0;
//                    OV5640_Special_Effects(effect);//设置特效
//                    sprintf((char*)Print_buf,"%s",EFFECTS_TBL[effect]);
//                    break;
//                case WKUP_PRES:	//JPEG输出尺寸设置
//                    size++;
//                    if(size>11)size=0;
//                    OV5640_OutSize_Set(16,4,jpeg_img_size_tbl[size][0],jpeg_img_size_tbl[size][1]);//设置输出尺寸
//                    sprintf((char*)Print_buf,"JPEG Size:%s",JPEG_SIZE_TBL[size]);
//                    break;
                }
								
                Draw_Font16B(30,180,BLUE,"               ");//显示提示内容
								
                Draw_Font16B(30,180,BLUE,Print_buf);//显示提示内容
								
                delay_ms(800);
								
            } 
						
						Draw_Font16B(30,150,BLUE,"Send complete!!");//提示传输结束设置
						
						Get_Picture=2;	//标记jpeg数据处理完了,可以让DMA去采集下一帧了.
												
						Start_OV5640_JPEG(&hdcmi);//从新开始捕获图像
        }
    }
}



/************************************************************************************************/
//数据转存含税

//STM32H7工程模板-HAL库函数版本
//DevEBox  大越创新
//淘宝店铺：mcudev.taobao.com
//淘宝店铺：shop389957290.taobao.com	


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
//RGB屏数据接收回调函数

//STM32H7工程模板-HAL库函数版本
//DevEBox  大越创新
//淘宝店铺：mcudev.taobao.com
//淘宝店铺：shop389957290.taobao.com	


/************************************************************************************************/



void RGBLine_Shift(DCMI_HandleTypeDef *hdcmi)
{
		
	    	if(curline<lcddev.height)
				{
					
										
////					HAL_DCMI_Suspend(hdcmi); // 
////					HAL_DCMI_Stop(hdcmi);
					
					__HAL_DCMI_ENABLE_IT(hdcmi, DCMI_IER_FRAME_IE);                                          //使用帧中断
				
					SCB_InvalidateDCache_by_Addr((uint32_t*)RGB_Line_DATA, RGB_Width/2);  //根据地址信息，无效其对应的 cache-line
					
					HAL_DCMI_Start_DMA(hdcmi, DCMI_MODE_SNAPSHOT,(uint32_t)&RGB_Line_DATA, RGB_Width/2); 	    //启动 JPEG传输拍照
					
					HAL_DMA_Abort(&hdma_memtomem_dma1_stream0);   //需要先停止DMA工作，再设置DMA 数据源地址和目标地址
					
					HAL_DMA_Start(&hdma_memtomem_dma1_stream0, (uint32_t)&RGB_Line_DATA, (uint32_t)&RGB_DATA[curline][0], RGB_Width*2); //使用DMA转存一行数据
					
  				++curline;
				
				}

		
}






/************************************************************************************************/
//用显示缓冲区数据进行刷屏操作

//STM32H7工程模板-HAL库函数版本
//DevEBox  大越创新
//淘宝店铺：mcudev.taobao.com
//淘宝店铺：shop389957290.taobao.com	


/************************************************************************************************/



  u16 Num_Dot;
  u16 Num_H;//行数
	u16 *R_Buf; //刷屏数据指针
	
static void  RGB_Refresh_LCD(void)
{
	  
		LCD_Set_Window(0,0,lcddev.width,lcddev.height);//设置全屏窗口
		
    LCD_SetCursor(0,0);              //设置屏幕显示起点	
	
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
	
	 
	
////		memset((uint8_t *)RGB_DATA, 0, RGB_buf_size*2);                                       //清空接收缓冲区
	
		__HAL_DCMI_ENABLE_IT(hdcmi, DCMI_IER_FRAME_IE);                                       //使用帧中断
	    
    HAL_DCMI_Start_DMA(hdcmi, DCMI_MODE_SNAPSHOT, (uint32_t)&RGB_Line_DATA, RGB_Width/2); 	  //启动 JPEG传输拍照  连续传输
	
	  curline=0;
	
	
}


/************************************************************************************************/
//RGB565测试
//RGB数据直接显示在LCD上面

//STM32H7工程模板-HAL库函数版本
//DevEBox  大越创新
//淘宝店铺：mcudev.taobao.com
//淘宝店铺：shop389957290.taobao.com	


/************************************************************************************************/

  u8 Key_N;


void RGB565_mode(void)
{
    
    float fac=0;
    u8 effect=0,contrast=2;
    u8 scale=1;		//默认是全尺寸缩放
    
    u16 outputheight=0;

    LCD_Clear(WHITE);
	    	
    Draw_Font16B(30,50,BLUE,"DevEBox STM32H750");
    Draw_Font16B(30,70,BLUE,"OV5640 RGB565 Mode");
	
//    Draw_Font16B(30,100,BLUE,"KEY1:Contrast");			//对比度
//    Draw_Font16B(30,120,BLUE,"KEY2:Auto Focus"); 		//执行自动对焦
//    LCD_ShowString(30,140,200,16,16,"KEY2:Effects"); 			//特效
//    LCD_ShowString(30,160,200,16,16,"KEY_UP:FullSize/Scale");	//1:1尺寸(显示真实尺寸)/全尺寸缩放
	
	
    //自动对焦初始化
    OV5640_RGB565_Mode();	//RGB565模式
    OV5640_Focus_Init();
    OV5640_Light_Mode(0);	//自动模式
    OV5640_Color_Saturation(3);//色彩饱和度0
    OV5640_Brightness(4);	//亮度0
    OV5640_Contrast(3);		//对比度0
    OV5640_Sharpness(33);	//自动锐度
    OV5640_Focus_Constant();//启动持续对焦
		
		
//    if(lcddev.height==1024)
//    {
//        yoffset=(lcddev.height-800)/2;
//        outputheight=800;
//        OV5640_WR_Reg(0x3035,0X51);//降低输出帧率，否则可能抖动
//			
//    } 
//		else if(lcddev.height==1280)
//    {
//        yoffset=(lcddev.height-600)/2;
//        outputheight=600;
//        OV5640_WR_Reg(0x3035,0X51);//降低输出帧率，否则可能抖动
//    }
//		else
//    {
//        yoffset=0;
//        outputheight=lcddev.height;
        OV5640_WR_Reg(0x3035,0X51);//降低输出帧率，否则可能抖动
//    }
		
		    
		
    OV5640_OutSize_Set(4,0,lcddev.width,lcddev.height);		//满屏缩放显示
						
    Start_OV5640_RGB(&hdcmi);  //启动传输
			
    LCD_Clear(BLACK);
		
    while(1)
    {
			
        Key_Flag=KEY_Scan(0);   //获取键值
			
			
			  if(Key_Flag==KEY1_PRES)//按键1切换功能
				{
						Key_N++;
						if(Key_N>=3)Key_N=0;
		
					if(Key_N==1)
						{
							Draw_Font16B(30,50,BLUE,"OV5640: DCMI_Stop");//显示提示内容
					    delay_ms(800);
							
////							DCMI_Stop(); //非KEY1按下,停止显示
						}
					else if(Key_N==2) 
						{	
							Draw_Font16B(30,50,BLUE,"OV5640: DCMI_Start");//显示提示内容
					    delay_ms(800);
							
////							DCMI_Start();	//重新开始传输
						}					
				}
			 else if(Key_Flag==KEY2_PRES)//按键1切换功能
				{
					Draw_Font16B(30,50,BLUE,"OV5640: Focus");//显示提示内容
					
          delay_ms(800);
					
					OV5640_Focus_Single(); //执行一次自动对焦
				}
				
				
////////////////////        if(Key_Flag)
////////////////////        {
////////////////////					
////////////////////					
////////////////////            if(Key_Flag!=KEY1_PRES)  //没有很多按键
////////////////////							{
////////////////////								
////////////////////							  DCMI_Stop(); //非KEY1按下,停止显示
////////////////////								
////////////////////						   }
////////////////////							
////////////////////            switch(Key_Flag)
////////////////////            {
////////////////////							
////////////////////							
//////////////////////							case KEY1_PRES:	//对比度设置
//////////////////////									contrast++;
//////////////////////									if(contrast>6)contrast=0;
//////////////////////									OV5640_Contrast(contrast);
//////////////////////									sprintf((char*)Print_buf,"Contrast:%d",(signed char)contrast-3);
//////////////////////									break;
////////////////////							case KEY2_PRES:	//执行一次自动对焦
////////////////////									OV5640_Focus_Single();
////////////////////									break;
////////////////////							
////////////////////							
//////////////////////            case KEY2_PRES:	//特效设置
//////////////////////                effect++;
//////////////////////                if(effect>6)effect=0;
//////////////////////                OV5640_Special_Effects(effect);//设置特效
//////////////////////                sprintf((char*)Print_buf,"%s",EFFECTS_TBL[effect]);
//////////////////////                break;
//////////////////////            case WKUP_PRES:	//1:1尺寸(显示真实尺寸)/缩放
//////////////////////                scale=!scale;
//////////////////////                if(scale==0)
//////////////////////                {
//////////////////////                    fac=(float)800/outputheight;	//得到比例因子
//////////////////////                    OV5640_OutSize_Set((1280-fac*lcddev.width)/2,(800-fac*outputheight)/2,lcddev.width,outputheight);
//////////////////////                    sprintf((char*)Print_buf,"Full Size 1:1");
//////////////////////                } else
//////////////////////                {
//////////////////////                    OV5640_OutSize_Set(4,0,lcddev.width,outputheight);
//////////////////////                    sprintf((char*)Print_buf,"Scale");
//////////////////////                }
//////////////////////                break;
////////////////////            }
////////////////////            if(Key_Flag!=KEY1_PRES)	//非KEY1按下
////////////////////            {
////////////////////                Draw_Font16B(30,50,BLUE,Print_buf);//显示提示内容
////////////////////                delay_ms(800);
////////////////////                DCMI_Start();	//重新开始传输
////////////////////            }
////////////////////        }
        	
           LED2_Toggle;//LED灯闪 提示系统在运行					
				
					 RGB_Refresh_LCD();//根据帧数据，进行刷屏
					 
					 Start_OV5640_RGB(&hdcmi);  //启动传输
				
aiRun();
				 
	    }
}




















uint8_t T_Num;              //循环变量			


void OV_Camera_Demo(uint8_t Key_Value)
{
	

	  if(Key_Value==KEY1_PRES) 
			{
				Key_Value=0;  //清除键值
        OV_mode=1;    //RGB565模式
						
           
      }
    else if(Key_Value==KEY2_PRES) 
			{
				Key_Value=0;//清除键值
        OV_mode=2;    //JPEG模式
      }
        
				T_Num++;
				
        if(T_Num==100)Draw_Font16B(24,240,RED,"KEY1:RGB565  KEY2:JPEG"); //闪烁显示提示信息
        if(T_Num==200)
        {
            Draw_Font16B(24,240,RED,"                      "); //闪烁显示提示信息
            T_Num=0;
            LED2_Toggle;
					  
        }
     
		 delay_ms(5);
				
				
		if(OV_mode==1) RGB565_mode();       //选择RGB液晶屏显示模式	  
			
    else if(OV_mode==2) JPEG_mode();//选择JPEG串口输出模式
			

}















/************************************************************************************************/

//STM32H7工程模板-HAL库函数版本
//DevEBox  大越创新
//淘宝店铺：mcudev.taobao.com
//淘宝店铺：shop389957290.taobao.com	


/************************************************************************************************/





