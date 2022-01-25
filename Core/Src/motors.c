/*
 * motors.c
 *
 *  Created on: Jul 26, 2021
 *      Author: amali
 */

/* Includes */
#include "motors.h"
#include "tim.h"

uint16_t rightPWM, leftPWM;

void RightInit(void)
{
	HAL_GPIO_WritePin(MOTOR_RIGHT_A_H_GPIO_Port, MOTOR_RIGHT_A_H_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(MOTOR_RIGHT_B_H_GPIO_Port, MOTOR_RIGHT_B_H_Pin, GPIO_PIN_RESET);
	TIM14->CCR1 = 0; // Right ILIM
}

void LeftInit(void)
{
	HAL_GPIO_WritePin(MOTOR_LEFT_A_H_GPIO_Port, MOTOR_LEFT_A_H_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(MOTOR_LEFT_B_H_GPIO_Port, MOTOR_LEFT_B_H_Pin, GPIO_PIN_RESET);
	TIM16->CCR1 = 0; // Right ILIM
}


void RightCW(uint32_t duty)
{
	if(duty > 30000)
	{
		duty = 30000;
	}
	TIM1->CCR3 = 0; // Right B L
	HAL_GPIO_WritePin(MOTOR_RIGHT_A_H_GPIO_Port, MOTOR_RIGHT_A_H_Pin, GPIO_PIN_RESET);
	TIM1->CCR1 = duty;
	HAL_GPIO_WritePin(MOTOR_RIGHT_B_H_GPIO_Port, MOTOR_RIGHT_B_H_Pin, GPIO_PIN_SET);
	TIM14->CCR1 = 2000; // 3000  =  0.15A
}

void RightCCW(uint32_t duty)
{
	if(duty > 30000)
	{
		duty = 30000;
	}
	TIM1->CCR1 = 0; // Right B L
	HAL_GPIO_WritePin(MOTOR_RIGHT_B_H_GPIO_Port, MOTOR_RIGHT_B_H_Pin, GPIO_PIN_RESET);
	TIM1->CCR3 = duty;
	HAL_GPIO_WritePin(MOTOR_RIGHT_A_H_GPIO_Port, MOTOR_RIGHT_A_H_Pin, GPIO_PIN_SET);
	TIM14->CCR1 = 2000; // 3000  =  0.15A
}

void RightOFF(void)
{
	TIM1->CCR1 = 0;
	TIM1->CCR3 = 0;
	TIM14->CCR1 = 0;
	HAL_GPIO_WritePin(MOTOR_RIGHT_A_H_GPIO_Port, MOTOR_RIGHT_A_H_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(MOTOR_RIGHT_B_H_GPIO_Port, MOTOR_RIGHT_B_H_Pin, GPIO_PIN_RESET);
}

void LeftCW(uint32_t duty)
{
	if(duty > 30000)
	{
		duty = 30000;
	}
	TIM15->CCR2 = 0; // Left B L
	HAL_GPIO_WritePin(MOTOR_LEFT_A_H_GPIO_Port, MOTOR_LEFT_A_H_Pin, GPIO_PIN_RESET);
	TIM15->CCR1 = duty;
	HAL_GPIO_WritePin(MOTOR_LEFT_B_H_GPIO_Port, MOTOR_LEFT_B_H_Pin, GPIO_PIN_SET);
	TIM16->CCR1 = 2000; // 3000  =  0.15A
}

void LeftCCW(uint32_t duty)
{
	if(duty > 30000)
	{
		duty = 30000;
	}
	TIM15->CCR1 = 0; // Left B L
	HAL_GPIO_WritePin(MOTOR_LEFT_B_H_GPIO_Port, MOTOR_LEFT_B_H_Pin, GPIO_PIN_RESET);
	TIM15->CCR2 = duty;
	HAL_GPIO_WritePin(MOTOR_LEFT_A_H_GPIO_Port, MOTOR_LEFT_A_H_Pin, GPIO_PIN_SET);
	TIM16->CCR1 = 2000; // 3000  =  0.15A
}

void LeftOFF(void)
{
	TIM15->CCR1 = 0;
	TIM15->CCR2 = 0;
	TIM16->CCR1 = 0;
	HAL_GPIO_WritePin(MOTOR_LEFT_A_H_GPIO_Port, MOTOR_LEFT_A_H_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(MOTOR_LEFT_B_H_GPIO_Port, MOTOR_LEFT_B_H_Pin, GPIO_PIN_RESET);
}
