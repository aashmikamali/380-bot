/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f0xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define MOTOR_RIGHT_B_H_Pin GPIO_PIN_13
#define MOTOR_RIGHT_B_H_GPIO_Port GPIOC
#define ADC_VBAT_Pin GPIO_PIN_0
#define ADC_VBAT_GPIO_Port GPIOA
#define ADC_RIGHT_ISENSE_Pin GPIO_PIN_1
#define ADC_RIGHT_ISENSE_GPIO_Port GPIOA
#define DEBUG_TX_Pin GPIO_PIN_2
#define DEBUG_TX_GPIO_Port GPIOA
#define DEBUG_RX_Pin GPIO_PIN_3
#define DEBUG_RX_GPIO_Port GPIOA
#define ADC_POT_Pin GPIO_PIN_4
#define ADC_POT_GPIO_Port GPIOA
#define ADC_ILIFT_SENSE_Pin GPIO_PIN_5
#define ADC_ILIFT_SENSE_GPIO_Port GPIOA
#define TOF_LEFT_SHDN_Pin GPIO_PIN_6
#define TOF_LEFT_SHDN_GPIO_Port GPIOA
#define TOF_LEFT_INT_Pin GPIO_PIN_7
#define TOF_LEFT_INT_GPIO_Port GPIOA
#define TOF_RIGHT_SHDN_Pin GPIO_PIN_0
#define TOF_RIGHT_SHDN_GPIO_Port GPIOB
#define MOTOR_RIGHT_ILIM_Pin GPIO_PIN_1
#define MOTOR_RIGHT_ILIM_GPIO_Port GPIOB
#define TOF_RIGHT_INT_Pin GPIO_PIN_2
#define TOF_RIGHT_INT_GPIO_Port GPIOB
#define TOF_CENTER_SHDN_Pin GPIO_PIN_10
#define TOF_CENTER_SHDN_GPIO_Port GPIOB
#define TOF_CENTER_INT_Pin GPIO_PIN_11
#define TOF_CENTER_INT_GPIO_Port GPIOB
#define MOTOR_RIGHT_IFLT_Pin GPIO_PIN_12
#define MOTOR_RIGHT_IFLT_GPIO_Port GPIOB
#define MOTOR_LEFT_A_L_Pin GPIO_PIN_14
#define MOTOR_LEFT_A_L_GPIO_Port GPIOB
#define MOTOR_LEFT_B_L_Pin GPIO_PIN_15
#define MOTOR_LEFT_B_L_GPIO_Port GPIOB
#define MOTOR_RIGHT_A_L_Pin GPIO_PIN_8
#define MOTOR_RIGHT_A_L_GPIO_Port GPIOA
#define MOTOR_LEFT_IFLT_Pin GPIO_PIN_9
#define MOTOR_LEFT_IFLT_GPIO_Port GPIOA
#define MOTOR_RIGHT_B_L_Pin GPIO_PIN_10
#define MOTOR_RIGHT_B_L_GPIO_Port GPIOA
#define MOTOR_LEFT_A_H_Pin GPIO_PIN_11
#define MOTOR_LEFT_A_H_GPIO_Port GPIOA
#define MOTOR_LEFT_B_H_Pin GPIO_PIN_12
#define MOTOR_LEFT_B_H_GPIO_Port GPIOA
#define ENC_RIGHT_A_Pin GPIO_PIN_15
#define ENC_RIGHT_A_GPIO_Port GPIOA
#define ENC_RIGHT_B_Pin GPIO_PIN_3
#define ENC_RIGHT_B_GPIO_Port GPIOB
#define ENC_LEFT_A_Pin GPIO_PIN_4
#define ENC_LEFT_A_GPIO_Port GPIOB
#define ENC_LEFT_B_Pin GPIO_PIN_5
#define ENC_LEFT_B_GPIO_Port GPIOB
#define SENSOR_I2C_SCL_Pin GPIO_PIN_6
#define SENSOR_I2C_SCL_GPIO_Port GPIOB
#define SENSOR_I2C_SDA_Pin GPIO_PIN_7
#define SENSOR_I2C_SDA_GPIO_Port GPIOB
#define MOTOR_LEFT_ILIM_Pin GPIO_PIN_8
#define MOTOR_LEFT_ILIM_GPIO_Port GPIOB
#define MOTOR_RIGHT_A_H_Pin GPIO_PIN_9
#define MOTOR_RIGHT_A_H_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
