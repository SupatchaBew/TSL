/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file    stm32f0xx_it.c
 * @brief   Interrupt Service Routines.
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f0xx_it.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "global.h"
#include "MODBUS.h"
#include "initial_parameter.h"
#include "function.h"
#include "driver_Input.h"
#include "driver_Output.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/
extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim6;
extern TIM_HandleTypeDef htim14;
extern TIM_HandleTypeDef htim15;
extern TIM_HandleTypeDef htim16;
extern TIM_HandleTypeDef htim17;
/* USER CODE BEGIN EV */

/* USER CODE END EV */

/******************************************************************************/
/*           Cortex-M0 Processor Interruption and Exception Handlers          */ 
/******************************************************************************/
/**
  * @brief This function handles Non maskable interrupt.
  */
void NMI_Handler(void)
{
  /* USER CODE BEGIN NonMaskableInt_IRQn 0 */

  /* USER CODE END NonMaskableInt_IRQn 0 */
  /* USER CODE BEGIN NonMaskableInt_IRQn 1 */

  /* USER CODE END NonMaskableInt_IRQn 1 */
}

/**
  * @brief This function handles Hard fault interrupt.
  */
void HardFault_Handler(void)
{
  /* USER CODE BEGIN HardFault_IRQn 0 */

  /* USER CODE END HardFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_HardFault_IRQn 0 */
    /* USER CODE END W1_HardFault_IRQn 0 */
  }
}

/**
  * @brief This function handles System service call via SWI instruction.
  */
void SVC_Handler(void)
{
  /* USER CODE BEGIN SVC_IRQn 0 */

  /* USER CODE END SVC_IRQn 0 */
  /* USER CODE BEGIN SVC_IRQn 1 */

  /* USER CODE END SVC_IRQn 1 */
}

/**
  * @brief This function handles Pendable request for system service.
  */
void PendSV_Handler(void)
{
  /* USER CODE BEGIN PendSV_IRQn 0 */

  /* USER CODE END PendSV_IRQn 0 */
  /* USER CODE BEGIN PendSV_IRQn 1 */

  /* USER CODE END PendSV_IRQn 1 */
}

/**
  * @brief This function handles System tick timer.
  */
void SysTick_Handler(void)
{
  /* USER CODE BEGIN SysTick_IRQn 0 */

  /* USER CODE END SysTick_IRQn 0 */
  HAL_IncTick();
  /* USER CODE BEGIN SysTick_IRQn 1 */

  /* USER CODE END SysTick_IRQn 1 */
}

/******************************************************************************/
/* STM32F0xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32f0xx.s).                    */
/******************************************************************************/

/**
  * @brief This function handles RCC global interrupt.
  */
void RCC_IRQHandler(void)
{
  /* USER CODE BEGIN RCC_IRQn 0 */

  /* USER CODE END RCC_IRQn 0 */
  /* USER CODE BEGIN RCC_IRQn 1 */

  /* USER CODE END RCC_IRQn 1 */
}

/**
  * @brief This function handles TIM1 capture compare interrupt.
  */
void TIM1_CC_IRQHandler(void)
{
  /* USER CODE BEGIN TIM1_CC_IRQn 0 */

  /* USER CODE END TIM1_CC_IRQn 0 */
  HAL_TIM_IRQHandler(&htim1);
  /* USER CODE BEGIN TIM1_CC_IRQn 1 */

  /* USER CODE END TIM1_CC_IRQn 1 */
}

/**
  * @brief This function handles TIM3 global interrupt.
  */
void TIM3_IRQHandler(void)
{
  /* USER CODE BEGIN TIM3_IRQn 0 */

  /* USER CODE END TIM3_IRQn 0 */
  HAL_TIM_IRQHandler(&htim3);
  /* USER CODE BEGIN TIM3_IRQn 1 */
  run_modbus();
  /* USER CODE END TIM3_IRQn 1 */
}

/**
  * @brief This function handles TIM6 global interrupt.
  */
void TIM6_IRQHandler(void)
{
  /* USER CODE BEGIN TIM6_IRQn 0 */

  /* USER CODE END TIM6_IRQn 0 */
  HAL_TIM_IRQHandler(&htim6);
  /* USER CODE BEGIN TIM6_IRQn 1 */

  /* USER CODE END TIM6_IRQn 1 */
}

/**
  * @brief This function handles TIM14 global interrupt.
  */
void TIM14_IRQHandler(void)
{
  /* USER CODE BEGIN TIM14_IRQn 0 */
  /* USER CODE END TIM14_IRQn 0 */
  HAL_TIM_IRQHandler(&htim14);
  /* USER CODE BEGIN TIM14_IRQn 1 */

  run_Count();

  /* USER CODE END TIM14_IRQn 1 */
}

/**
  * @brief This function handles TIM15 global interrupt.
  */
void TIM15_IRQHandler(void)
{
  /* USER CODE BEGIN TIM15_IRQn 0 */

  /* USER CODE END TIM15_IRQn 0 */
  HAL_TIM_IRQHandler(&htim15);
  /* USER CODE BEGIN TIM15_IRQn 1 */

  /* USER CODE END TIM15_IRQn 1 */
}

/**
  * @brief This function handles TIM16 global interrupt.
  */
void TIM16_IRQHandler(void)
{
  /* USER CODE BEGIN TIM16_IRQn 0 */

  /* USER CODE END TIM16_IRQn 0 */
  HAL_TIM_IRQHandler(&htim16);
  /* USER CODE BEGIN TIM16_IRQn 1 */
	if(nValue.LastStatus[1] == Move_up)
//		trig_H2[2].Counter += 1;
		halsensor[1][0].Counter += 1;
	else if(nValue.LastStatus[1] == Move_down)
		halsensor[1][0].Counter -= 1;
  /* USER CODE END TIM16_IRQn 1 */
}

/**
  * @brief This function handles TIM17 global interrupt.
  */
void TIM17_IRQHandler(void)
{
  /* USER CODE BEGIN TIM17_IRQn 0 */

  /* USER CODE END TIM17_IRQn 0 */
  HAL_TIM_IRQHandler(&htim17);
  /* USER CODE BEGIN TIM17_IRQn 1 */
	if(nValue.LastStatus[0] == Move_up)
//		trig_H2[2].Counter += 1;
		halsensor[0][0].Counter += 1;
	else if(nValue.LastStatus[0] == Move_down)
		halsensor[0][0].Counter -= 1;
  /* USER CODE END TIM17_IRQn 1 */
}

/* USER CODE BEGIN 1 */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
//	__HAL_UART_FLUSH_DRREGISTER(huart); // Clear the buffer to prevent overrun
	if (huart->Instance == USART1){
		MODBUS1_IT();
		if (HAL_UART_Receive_IT(&huart1, (uint8_t *)&rxBuffer_modbus1, 1)!= HAL_OK)
		{
//			Error_UART_Handler();
		}
	}
}
void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart){
	if(!modbus1.ByteRsp){
		rx1_en();
	}
}
uint32_t IC_Value1 = 0;
uint32_t IC_Value2 = 0;
uint32_t Difference = 0;
uint32_t Frequency = 0;
float fFrequency = 0.0;
uint32_t input_capture;
uint8_t Is_First_Captured = 0;  // 0- not captured, 1- captured

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim) {
//	if(htim->Instance == TIM16){
//		if(nValue.LastStatus == 2)
//			trig_H1[2].Counter += 1;
//		else if(nValue.LastStatus == 1)
//			trig_H1[2].Counter -= 1;
//	}else{
//	}
//
//	if(htim->Instance == TIM17){
//		if(nValue.LastStatus == 2)
//			trig_H2[2].Counter += 1;
//		else if(nValue.LastStatus == 1)
//			trig_H2[2].Counter -= 1;
//	}else{
//	}
//
//	}
//	if(htim->Instance == TIM17){
//		if(SWUP)
//			trig_H1[3].Counter += 1;
//		else
//			trig_H1[3].Counter -= 1;
//	}else{
//
//	}

//	if (htim->Instance == TIM16 && htim->Channel == HAL_TIM_ACTIVE_CHANNEL_1)
//	{
//		if (Is_First_Captured==0)
//		{
//			IC_Value1 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1);
//			Is_First_Captured =1;
//		}
//		else if (Is_First_Captured)  // if the first is captured
//		{
//			IC_Value2 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1);  // capture second value
//
//			if (IC_Value2 > IC_Value1)
//			{
//				Difference = IC_Value2-IC_Value1;   // calculate the difference
//			}
//
//			else if (IC_Value2 < IC_Value1)
//			{
//				Difference = ((0xffff-IC_Value1)+IC_Value2) +1;
//			}
//
//			else
//			{
//				Error_Handler();
//			}
//
//			Frequency = HAL_RCC_GetPCLK1Freq()/Difference;  // calculate frequency
//			fFrequency = Frequency/10.0;
//			Is_First_Captured = 0;  // reset the first captured
//		}
//	}
}
/* USER CODE END 1 */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
