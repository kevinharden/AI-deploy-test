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
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
extern uint8_t USB_STATUS_REG; //USB状态
extern uint8_t  bDeviceState;		//默认没有连接 

uint8_t USB_STA;
uint8_t Divece_STA;

uint8_t tct=0;
uint8_t offline_cnt=0;


extern uint8_t  OV_mode;				//bit0:  1,RGB565模式;2,JPEG模式		
extern uint16_t Camera_ID;      //摄像头型号ID号
extern uint8_t Print_buf[32];	//消息缓存区


uint8_t  key_F;//键值
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

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
static ai_float out_data[AI_NETWORK_OUT_1_SIZE];

static ai_buffer *ai_input;
static ai_buffer *ai_output;

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

uint8_t Textbuf[32];

/*神经网络初始化*/
int ai_Init(void)
{
	ai_error err;
	
	const ai_handle acts[] = { activations };
  err = ai_network_create_and_init(&network, acts, NULL);
	if(err.type != AI_ERROR_NONE)
	{
	
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
	ai_input[0].data = AI_HANDLE_PTR(out_data);
	
	n_batch = ai_network_run(network, &ai_input[0], &ai_output[0]);
	if(n_batch != 1)
	{
	err=ai_network_get_error(network);
	};
	
	return 0;
	
}

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
W25QXX_Init(); 
LCD_Init();            //初始化2.0寸 240x320 高清屏  LCD显示
	GBK_Lib_Init();        //硬件GBK字库初始化--(如果使用不带字库的液晶屏版本，此处可以屏蔽，不做字库初始化）
	LCD_Clear(WHITE);      //清屏  	
	ai_Init();
	
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_1,GPIO_PIN_RESET);
	
//	ai_network_create_and_init(
//  ai_handle* network, const ai_handle activations[], const ai_handle weights[]);
//	
	
	
	
	 Draw_Font16B(16,10,RED,"  STM32H7 DCMI OV5640 ");
	 Draw_Font16B(16,30,BLUE,"     嵌入式开发网   ");	 
	 Draw_Font16B(16,50,BLUE," mcudev.taobao.com  "); 
	 

	if(W25QXX_ReadID()!=W25Q64)
		Draw_Font16B(16,80,RED,"W25Q64 Error!");	//检测W25Q128错误
	else //SPI FLASH 正常
	{   														 
		Draw_Font16B(16,80,BLUE,"W25Q64 OK OK OK ");	 
		Draw_Font16B(16,100,BLUE,"SPI FLASH Size:8MB");	 
	} 

	
	  while(SD_Init())//检测不到SD卡
    {
        Draw_Font16B(16,140,RED,"SD Card Error!");
			  Draw_Font16B(16,160,RED,"Please Check! ");
        HAL_Delay(500);
        Draw_Font16B(16,160,RED,"               ");
        HAL_Delay(500);

    }
		
		
                                       
    Draw_Font16B(16,140,BLUE,"SD Card OK    "); //检测SD卡成功
		
		sprintf((char*)Textbuf,"SD Card Size: %u MB",SDCardInfo.CardCapacity>>20); //显示无符号十进制整数		
   
		Draw_Font16B(16,160,BLUE,Textbuf);  				//显示存储卡容量


    while(OV5640_Init())//初始化OV5640
    {
        Draw_Font16B(24,200,RED,"OV5640 ERROR");
        HAL_Delay(200);
        Draw_Font16B(24,200,RED,"             ");
        HAL_Delay(200);
        //LED2_Toggle;
    }
		
		if(Camera_ID!=OV5640_ID)
			   sprintf((char*)Print_buf,"Camera_ID: ERR");
			else 
				 sprintf((char*)Print_buf,"Camera_ID: 0x%4X",Camera_ID);
				
		 Draw_Font16B(24,200,BLUE,Print_buf);//显示提示内容

     Draw_Font16B(24,220,BLUE,"OV5640 OK");	




	 // MX_USB_DEVICE_Init();//  先屏蔽前面初始化部分，等其他模块都初始化后，再启动USB工作
		
		HAL_Delay(1000);		
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
		key_F=KEY_Scan(0); 		//得到键值   //按键扫描测试函数
		
		OV_Camera_Demo(1);//选择摄像头工作模式演示	
		
////		   Demo_Menu();//测试LCD 2寸高清屏
	
////		   delay_ms(500);
////		   printf("\r\n串口1 发送的消息:\r\n");
		

		
		
		
		
		
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
