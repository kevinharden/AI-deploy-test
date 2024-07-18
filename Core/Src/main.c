/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "crc.h"
#include "dcmi.h"
#include "dma.h"
#include "quadspi.h"
#include "sdmmc.h"
#include "spi.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "sdmmc_sdcard.h"
#include "lcd.h"
#include "ov5640.h"
#include <w25qxx.h>
#include "text.h"
#include "GBK_LibDrive.h"
#include "OV_Frame.h"
#include "network.h"
#include "network_data_params.h"
#include "network_data.h"


#include "task.h"
#include <string.h>
#include "stdint.h"
#include "stdio.h"
#include "lcd.h"
#include "led.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define RGB_Width    128 //根据屏幕方向，设置缓存大小和格式
#define RGB_Height	 128//根据屏幕
#define CHANNELS 3
extern uint8_t USB_STATUS_REG; //USB状态
extern uint8_t  bDeviceState;		//默认没有连接 

uint8_t USB_STA;
uint8_t Divece_STA;

uint8_t tct=0;
uint8_t offline_cnt=0;


extern uint8_t  OV_mode;				//bit0:  1,RGB565模式;2,JPEG模式		
extern uint16_t Camera_ID;      //摄像头型号ID号
extern uint8_t Print_buf[32];	//消息缓存区

extern uint16_t RGB_DATA[RGB_Height][RGB_Width];

uint8_t  key_F;//键值
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
int test=0;
__attribute__((section (".RAM_D2"))) uint8_t se[60]={0x1B,0x40,0x1A,0x5B,0x01,0x00,0x00,0x00,0x00,0xB0,0x01,0x40,0x01,0x00,0x1D,0x48,0x02,0x1A,0x30,0x00,0x50,0x00,0x70,0x00,0x0c,0x45,0x02,0x00,0x31,0x37,0x33,0x36,0x32,0x30,0x33,0x34,0x39,0x33,0x32,0x00,0x1A,0x54,0x01,0x00,0x31,0x35,0x30,0x45,0x72,0x65,0x6E,0x00,0x1A,0x5D,0x00,0x1A,0x4F,0x00,0x1b,0x6d};

__attribute__((section (".RAM_D2"))) uint8_t rx_data[5];     //UART_RX  data
__attribute__((section (".RAM_D2"))) int Mode_Flag=0;        //cash or weight Mode
__attribute__((section (".RAM_D2"))) int Print_Flag=0;       //Mode1
__attribute__((section (".RAM_D2"))) int Pay_Flag=0;         //Mode2
__attribute__((section (".RAM_D2"))) int Scan_Flag=0;        //Scan state
__attribute__((section (".RAM_D2"))) int Judge_Flag=0;        //Scan state
__attribute__((section (".RAM_D2"))) uint16_t Weight=0;      //Weight data
__attribute__((section (".RAM_D2"))) uint16_t Type=0;        //Type data
__attribute__((section (".RAM_D2"))) uint16_t Sig_Money=0;   //sigMoney data
uint16_t Money=0;       //Money data
//char tjcstr[100];
uint16_t ai_result;


/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
static ai_handle network = AI_HANDLE_NULL;

AI_ALIGNED(32)
static ai_u8 activations[AI_NETWORK_DATA_ACTIVATIONS_SIZE];

AI_ALIGNED(32)
static ai_float in_data[AI_NETWORK_IN_1_SIZE];

AI_ALIGNED(32)
__attribute__((section (".RAM_D2"))) static ai_float out_data[AI_NETWORK_OUT_1_SIZE];

static ai_buffer *ai_input;
static ai_buffer *ai_output;

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

uint8_t Textbuf[32];


/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */
/* Enable the CPU Cache */

  /* Enable I-Cache---------------------------------------------------------*/
  SCB_EnableICache();

  /* Enable D-Cache---------------------------------------------------------*/
  SCB_EnableDCache();

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_QUADSPI_Init();
  MX_DCMI_Init();
  MX_SDMMC1_SD_Init();
  MX_USART1_UART_Init();
  MX_CRC_Init();
  MX_SPI2_Init();
  MX_UART4_Init();
  MX_UART7_Init();
  MX_USART2_UART_Init();
  MX_USART3_UART_Init();
  /* USER CODE BEGIN 2 */
HAL_UART_Receive_IT(&huart1,(uint8_t *)&rx_data, 4); //UART1_RX_IT_START
HAL_UART_Receive_IT(&huart4,(uint8_t *)&rx_data, 4); //UART1_RX_IT_START
	
	
	
W25QXX_Init(); 
LCD_Init();            //初始化2.0寸 240x320 高清屏  LCD显示
//	GBK_Lib_Init();        //硬件GBK字库初始化--(如果使用不带字库的液晶屏版本，此处可以屏蔽，不做字库初始化）
	LCD_Clear(WHITE);      //清屏  	
	ai_Init();
	
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_1,GPIO_PIN_RESET);
	HAL_GPIO_TogglePin(LED_G_GPIO_Port,LED_G_Pin);
	Camera_Init();
	
	OV_Camera_Demo(1);//选择摄像头工作模式演示	
	while(1)
			{  LED2_Toggle;//LED灯闪 提示系统在运行					
				
					 RGB_Refresh_LCD();//根据帧数据，进行刷屏
					 
						 //copy_rgb_to_in_data();
				
						 aiRun(RGB_DATA, out_data);
				aiRun(in_data, out_data);
				Start_OV5640_RGB(&hdcmi);  //启动传输
}				
	//copy_rgb_to_in_data();
			
	//aiRun(in_data, out_data);
			
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

  
		if(Mode_Flag==1)
		{
		             	//weight start
			            //if weight>50
			My_delay_ms(1000);
			            //send weight data
			
			            //Type?
			            //Sig_Money?
			            //Money?
			            //send Data
			//TEST_BEGIN1
		  while(test==0)//TEST
			  ;
			My_delay_ms(100);
			
			HMISendstart();  
//	   sprintf(tjcstr, "n0.val=266");
//	   HMISends(tjcstr); 
//	   HMISendb(0xff);		
//	
//						HMISendstart();  
//	   sprintf(tjcstr, "t5.txt=\"苹果\"");
//	   HMISends(tjcstr); 
//	   HMISendb(0xff);	
//			
//									HMISendstart();  
//	   sprintf(tjcstr, "n2.val=12");
//	   HMISends(tjcstr); 
//	   HMISendb(0xff);	

//												HMISendstart();  
//	   sprintf(tjcstr, "x0.val=3192");
//	   HMISends(tjcstr); 
//	   HMISendb(0xff);	
		 

			 
				//TEST_END1
			while (Print_Flag==0)
				;
			if(Print_Flag==1)
 HAL_UART_Transmit(&huart2, se, 60, HAL_MAX_DELAY); // 使用最大延时




			//printf weight&money data
		  while ((__HAL_UART_GET_FLAG(&huart1, UART_FLAG_TC))==0) 
			  ;
		         test=0;     //Clear flag

			
		
		
		}
		
		if(Mode_Flag==2)
{
//      while(Scan_Flag==0)
//        ;				 //wait for scan
			           //weight start
			           //if weight>50
			
			while( (__HAL_UART_GET_FLAG(&huart1, UART_FLAG_RXNE))==0)
				;
						//TEST_BEGIN2

			My_delay_ms(100);
			
			HMISendstart();  
//	   sprintf(tjcstr, "t2.txt=\"成功识别\"");
//	   HMISends(tjcstr); 
//	   HMISendb(0xff);		
//	
//						HMISendstart();  
//	   sprintf(tjcstr, "n0.val=266");
//	   HMISends(tjcstr); 
//	   HMISendb(0xff);	
//			
//									HMISendstart();  
//	   sprintf(tjcstr, "t6.txt=\"苹果\"");
//	   HMISends(tjcstr); 
//	   HMISendb(0xff);	

//												HMISendstart();  
//	   sprintf(tjcstr, "n1.val=12");
//	   HMISends(tjcstr); 
//	   HMISendb(0xff);	
//		 
//		 												HMISendstart();  
//	   sprintf(tjcstr, "x0.val=3192");
//	   HMISends(tjcstr); 
//	   HMISendb(0xff);	
//		 
//		 		 
//		 												HMISendstart();  
//	   sprintf(tjcstr, "t11.txt=\"匹配成功\"");
//	   HMISends(tjcstr); 
//	   HMISendb(0xff);	
		 
			 
				//TEST_END2
			
			
			
			My_delay_ms(1000);
			           //weight judge
			
			while(Pay_Flag==1)
				;
				         //send 4Gmodule data
			
			

		
		
		
		
		
		
		
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
		key_F=KEY_Scan(0); 		//得到键值   //按键扫描测试函数
		
	
		
	  }

  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Supply configuration update enable
  */
  HAL_PWREx_ConfigSupply(PWR_LDO_SUPPLY);

  /** Configure the main internal regulator output voltage
  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  while(!__HAL_PWR_GET_FLAG(PWR_FLAG_VOSRDY)) {}

  __HAL_RCC_SYSCFG_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE0);

  while(!__HAL_PWR_GET_FLAG(PWR_FLAG_VOSRDY)) {}

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 5;
  RCC_OscInitStruct.PLL.PLLN = 192;
  RCC_OscInitStruct.PLL.PLLP = 2;
  RCC_OscInitStruct.PLL.PLLQ = 5;
  RCC_OscInitStruct.PLL.PLLR = 2;
  RCC_OscInitStruct.PLL.PLLRGE = RCC_PLL1VCIRANGE_2;
  RCC_OscInitStruct.PLL.PLLVCOSEL = RCC_PLL1VCOWIDE;
  RCC_OscInitStruct.PLL.PLLFRACN = 0;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2
                              |RCC_CLOCKTYPE_D3PCLK1|RCC_CLOCKTYPE_D1PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.SYSCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB3CLKDivider = RCC_APB3_DIV2;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_APB1_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_APB2_DIV2;
  RCC_ClkInitStruct.APB4CLKDivider = RCC_APB4_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{ 	
	
	if (huart->Instance == USART1)
{
	HAL_UART_Receive_IT(&huart1,(uint8_t *)&rx_data, 4);
	if((rx_data[0]==1)&&(rx_data[1]==1)&&(rx_data[2]==0)&&(rx_data[3]==1))
  Mode_Flag=1;
	else if((rx_data[0]==1)&&(rx_data[1]==1)&&(rx_data[2]==0)&&(rx_data[3]==2))
	Mode_Flag=2;
	
	if((rx_data[0]==1)&&(rx_data[1]==1)&&(rx_data[2]==0)&&(rx_data[3]==0)&&((Mode_Flag==1)||(Mode_Flag==2)))
	Mode_Flag=0;
	
	if((rx_data[0]==1)&&(rx_data[1]==1)&&(rx_data[2]==0)&&(rx_data[3]==3)&&(Mode_Flag==1))
	Print_Flag=1;
	if((rx_data[0]==1)&&(rx_data[1]==1)&&(rx_data[2]==0)&&(rx_data[3]==4)&&(Mode_Flag==2)&&(Judge_Flag==1))
	Pay_Flag=1;
		if((rx_data[0]==1)&&(rx_data[1]==1)&&(rx_data[2]==0)&&(rx_data[3]==9))
 test=1;
}

	if (huart->Instance == UART4)
{
	HAL_UART_Receive_IT(&huart4,(uint8_t *)&rx_data, 4);
if((rx_data[0]==1)&&(rx_data[1]==1)&&(rx_data[2]==0)&&(rx_data[3]==5)&&(Mode_Flag==2))
	Scan_Flag=1;
	
}

}

/*神经网络初始化*/
int ai_Init(void)
{
	ai_error err;
	
	const ai_handle acts[] = { activations };
  err = ai_network_create_and_init(&network, acts, NULL);
	if(err.type != AI_ERROR_NONE)
	{
	while(1)
	HAL_GPIO_WritePin(LED_G_GPIO_Port,LED_G_Pin,GPIO_PIN_RESET);
	}
	
	ai_input = ai_network_inputs_get(network, NULL);
	ai_output = ai_network_outputs_get(network, NULL);
	
	return 0;
}

/*AI 运行处理函数*/
int aiRun(const void *in_data, void *out_data)
{
	ai_i32 n_batch;
	ai_error err;
	
	ai_input[0].data = AI_HANDLE_PTR(in_data);
	ai_output[0].data = AI_HANDLE_PTR(out_data);
	
	n_batch = ai_network_run(network, &ai_input[0], &ai_output[0]);
	if(n_batch != 1)
	{
	err=ai_network_get_error(network);
	};
	
	return 0;
	
}
/*RGB数据转移*/
void copy_rgb_to_in_data() 
	{
     int index = 0;
    for (int i = 0; i < RGB_Height; i++) {
        for (int j = 0; j < RGB_Width; j++) {
            // 提取RGB值
            uint16_t pixel = RGB_DATA[i][j];
            uint8_t r = (pixel >> 11) & 0x1F;  // 假设RGB565格式，提取红色分量
            uint8_t g = (pixel >> 5) & 0x3F;   // 提取绿色分量
            uint8_t b = pixel & 0x1F;          // 提取蓝色分量

            // 将RGB值按顺序存入in_data
            if (index < AI_NETWORK_IN_1_SIZE - CHANNELS + 1) {
                in_data[index++] = (ai_float)r / 31.0f;   // 归一化到[0, 1]
                in_data[index++] = (ai_float)g / 63.0f;   // 归一化到[0, 1]
                in_data[index++] = (ai_float)b / 31.0f;   // 归一化到[0, 1]
            } else {
                // 如果in_data的大小小于RGB_DATA的总元素数，跳出循环
                break;
            }
        }
        if (index >= AI_NETWORK_IN_1_SIZE - CHANNELS + 1) {
            break;
        }
    }
	}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
		
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
