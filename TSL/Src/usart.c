/**
  ******************************************************************************
  * File Name          : USART.c
  * Description        : This file provides code for the configuration
  *                      of the USART instances.
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

/* Includes ------------------------------------------------------------------*/
#include "usart.h"

/* USER CODE BEGIN 0 */
#define b8n1 0
#define b8n2 1
#define b8o1 2
#define b8o2 3
#define b8e1 4
#define b8e2 5

#define b7n1 6
#define b7n2 7
#define b7o1 8
#define b7o2 9
#define b7e1 10
#define b7e2 11

#define BAUDRATE_1200   0
#define BAUDRATE_2400	1
#define BAUDRATE_4800	2
#define BAUDRATE_9600	3
#define BAUDRATE_19200	4
#define BAUDRATE_38400	5
#define BAUDRATE_57600	6

/* USER CODE END 0 */

UART_HandleTypeDef huart1;

/* USART1 init function */

void MX_USART1_UART_Init(void)
{

  huart1.Instance = USART1;
  huart1.Init.BaudRate = 38400;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  huart1.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart1.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_RS485Ex_Init(&huart1, UART_DE_POLARITY_HIGH, 0, 0) != HAL_OK)
  {
    Error_Handler();
  }

}

void HAL_UART_MspInit(UART_HandleTypeDef* uartHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(uartHandle->Instance==USART1)
  {
  /* USER CODE BEGIN USART1_MspInit 0 */

  /* USER CODE END USART1_MspInit 0 */
    /* USART1 clock enable */
    __HAL_RCC_USART1_CLK_ENABLE();
  
    __HAL_RCC_GPIOA_CLK_ENABLE();
    /**USART1 GPIO Configuration    
    PA9     ------> USART1_TX
    PA10     ------> USART1_RX
    PA12     ------> USART1_DE 
    */
    GPIO_InitStruct.Pin = GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_12;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF1_USART1;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /* USER CODE BEGIN USART1_MspInit 1 */

  /* USER CODE END USART1_MspInit 1 */
  }
}

void HAL_UART_MspDeInit(UART_HandleTypeDef* uartHandle)
{

  if(uartHandle->Instance==USART1)
  {
  /* USER CODE BEGIN USART1_MspDeInit 0 */

  /* USER CODE END USART1_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_USART1_CLK_DISABLE();
  
    /**USART1 GPIO Configuration    
    PA9     ------> USART1_TX
    PA10     ------> USART1_RX
    PA12     ------> USART1_DE 
    */
    HAL_GPIO_DeInit(GPIOA, GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_12);

  /* USER CODE BEGIN USART1_MspDeInit 1 */

  /* USER CODE END USART1_MspDeInit 1 */
  }
} 

/* USER CODE BEGIN 1 */
void Uart1_Init(int baundrate,int communication)
{
	switch (baundrate)
	{
	case BAUDRATE_1200:
		huart1.Init.BaudRate = 1200;
		break;
	case BAUDRATE_2400:
		huart1.Init.BaudRate = 2400;
		break;
	case BAUDRATE_4800:
		huart1.Init.BaudRate = 4800;
		break;
	case BAUDRATE_9600:
		huart1.Init.BaudRate = 9600;
		break;
	case BAUDRATE_19200:
		huart1.Init.BaudRate = 19200;
		break;
	case BAUDRATE_38400:
		huart1.Init.BaudRate = 38400;
		break;
	case BAUDRATE_57600:
		huart1.Init.BaudRate = 57600;
		break;
	default:
		huart1.Init.BaudRate = 9600;
		break;
	}
	switch (communication)
	{
	case b8n1:
		huart1.Init.WordLength = UART_WORDLENGTH_8B;
		huart1.Init.Parity = UART_PARITY_NONE;
		huart1.Init.StopBits = UART_STOPBITS_1;
		break;
	case b8n2:
		huart1.Init.WordLength = UART_WORDLENGTH_8B;
		huart1.Init.Parity = UART_PARITY_NONE;
		huart1.Init.StopBits = UART_STOPBITS_2;
		break;
	case b8o1:
		huart1.Init.WordLength = UART_WORDLENGTH_9B;
		huart1.Init.Parity = UART_PARITY_ODD;
		huart1.Init.StopBits = UART_STOPBITS_1;
		break;
	case b8o2:
		huart1.Init.WordLength = UART_WORDLENGTH_9B;
		huart1.Init.Parity = UART_PARITY_ODD;
		huart1.Init.StopBits = UART_STOPBITS_2;
		break;
	case b8e1:
		huart1.Init.WordLength = UART_WORDLENGTH_9B;
		huart1.Init.Parity = UART_PARITY_EVEN;
		huart1.Init.StopBits = UART_STOPBITS_1;
		break;
	case b8e2:
		huart1.Init.WordLength = UART_WORDLENGTH_9B;
		huart1.Init.Parity = UART_PARITY_EVEN;
		huart1.Init.StopBits = UART_STOPBITS_2;
		break;
	default:
		huart1.Init.WordLength = UART_WORDLENGTH_8B;
		huart1.Init.Parity = UART_PARITY_NONE;
		huart1.Init.StopBits = UART_STOPBITS_1;
		break;
	}

	huart1.Instance = USART1;
	huart1.Init.Mode = UART_MODE_TX_RX;
	huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	huart1.Init.OverSampling = UART_OVERSAMPLING_16;
	huart1.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
	huart1.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
	if (HAL_RS485Ex_Init(&huart1, UART_DE_POLARITY_HIGH, 0, 0) != HAL_OK)
	{
		Error_Handler();
	}

}

/* USER CODE END 1 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
