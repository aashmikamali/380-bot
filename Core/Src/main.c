/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
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
#include "adc.h"
#include "dma.h"
#include "i2c.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "motors.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
/*typedef enum
{
	NONE = 0,
	UP,
	DOWN,
	LEFT,
	RIGHT,
	CENTRE
}keypadState;
keypadState keypadStatus;*/
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define SYSTEM_TICK 100
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
uint32_t current_time, last_time;
HAL_StatusTypeDef uart2Status;
uint16_t VbatSense;
uint16_t PotSense, LeftCurrentCount, RightCurrentCount;
uint8_t printNone[] = {' ', 'N', 'O', 'N', 'E', 0x0A, 0x0D};
uint8_t printUp[] = {' ', 'U', 'P', 0x0A, 0x0D};
uint8_t printDown[] = {' ', 'D', 'O', 'W', 'N', 0x0A, 0x0D};
uint8_t printLeft[] = {' ', 'L', 'E', 'F', 'T', 0x0A, 0x0D};
uint8_t printRight[] = {' ', 'R', 'I', 'G', 'H', 'T', 0x0A, 0x0D};
uint8_t printCentre[] = {' ', 'C', 'E', 'N', 'T','R', 'E', 0x0A, 0x0D};
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
void print_Values();
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

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
  MX_ADC_Init();
  MX_I2C1_Init();
  MX_TIM1_Init();
  MX_TIM2_Init();
  MX_TIM3_Init();
  MX_TIM14_Init();
  MX_TIM15_Init();
  MX_TIM16_Init();
  MX_USART2_UART_Init();
  /* USER CODE BEGIN 2 */
  ADC_ConfigDMA();
  TIM_initTimers();
  RightInit();
  LeftInit();
  last_time = HAL_GetTick();
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	current_time = HAL_GetTick();
	if((current_time - last_time) >= SYSTEM_TICK)
	{
		last_time = current_time;
		// get adc data
		VbatSense = g_adcBuffer[0];
		RightCurrentCount = g_adcBuffer[1];
		PotSense = g_adcBuffer[2];
		LeftCurrentCount = g_adcBuffer[3];
		LeftCW(3000);
		RightCW(3000);
		print_Values();
	}
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
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI|RCC_OSCILLATORTYPE_HSI14;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSI14State = RCC_HSI14_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.HSI14CalibrationValue = 16;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL12;
  RCC_OscInitStruct.PLL.PREDIV = RCC_PREDIV_DIV1;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_I2C1;
  PeriphClkInit.I2c1ClockSelection = RCC_I2C1CLKSOURCE_HSI;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
void print_Values()
{
	uint16_t temp;
	// convert to ASCII for display
	uint8_t arrayVal[] = {0x30, 0x30, 0x30, 0x30, ' ', 0x30, 0x30, 0x30, 0x30, ' ',
	0x30, 0x30, 0x30, 0x30, ' ',0x30, 0x30, 0x30, 0x30};
	temp = VbatSense;
	arrayVal[0] += (temp / 1000);
	temp = temp % 1000;
	arrayVal[1] += (temp / 100);
	temp = temp % 100;
	arrayVal[2] += (temp / 10);
	temp = temp % 10;
	arrayVal[3] += temp;
	temp = VbatSense;
	arrayVal[5] += (temp / 1000);
	temp = temp % 1000;
	arrayVal[6] += (temp / 100);
	temp = temp % 100;
	arrayVal[7] += (temp / 10);
	temp = temp % 10;
	arrayVal[8] += temp;
	temp = PotSense;
	arrayVal[10] += (temp / 1000);
	temp = temp % 1000;
	arrayVal[11] += (temp / 100);
	temp = temp % 100;
	arrayVal[12] += (temp / 10);
	temp = temp % 10;
	arrayVal[13] += temp;
	temp = LeftCurrentCount;
	arrayVal[15] += (temp / 1000);
	temp = temp % 1000;
	arrayVal[16] += (temp / 100);
	temp = temp % 100;
	arrayVal[17] += (temp / 10);
	temp = temp % 10;
	arrayVal[18] += temp;
	// send it across
	HAL_UART_Transmit(&huart2, arrayVal, sizeof(arrayVal), 100);
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

