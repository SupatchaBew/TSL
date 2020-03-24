/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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
#define HAL12_Pin GPIO_PIN_0
#define HAL12_GPIO_Port GPIOC
#define HAL22_Pin GPIO_PIN_1
#define HAL22_GPIO_Port GPIOC
#define LT02_Pin GPIO_PIN_2
#define LT02_GPIO_Port GPIOC
#define LB02_Pin GPIO_PIN_3
#define LB02_GPIO_Port GPIOC
#define FM25L16B_NSS_Pin GPIO_PIN_4
#define FM25L16B_NSS_GPIO_Port GPIOA
#define FM25L16B_SCK_Pin GPIO_PIN_5
#define FM25L16B_SCK_GPIO_Port GPIOA
#define FM25L16B_MISO_Pin GPIO_PIN_6
#define FM25L16B_MISO_GPIO_Port GPIOA
#define M25L16B_MOSI_Pin GPIO_PIN_7
#define M25L16B_MOSI_GPIO_Port GPIOA
#define KEY_F0_Pin GPIO_PIN_5
#define KEY_F0_GPIO_Port GPIOC
#define INA_1_Pin GPIO_PIN_10
#define INA_1_GPIO_Port GPIOB
#define INB_1_Pin GPIO_PIN_11
#define INB_1_GPIO_Port GPIOB
#define SEL_1_Pin GPIO_PIN_12
#define SEL_1_GPIO_Port GPIOB
#define INA_2_Pin GPIO_PIN_13
#define INA_2_GPIO_Port GPIOB
#define INB_2_Pin GPIO_PIN_14
#define INB_2_GPIO_Port GPIOB
#define SEL_2_Pin GPIO_PIN_15
#define SEL_2_GPIO_Port GPIOB
#define KEY_F1_Pin GPIO_PIN_6
#define KEY_F1_GPIO_Port GPIOC
#define KEY_UP_Pin GPIO_PIN_10
#define KEY_UP_GPIO_Port GPIOC
#define KEY_DW_Pin GPIO_PIN_11
#define KEY_DW_GPIO_Port GPIOC
#define PWM_1_Pin GPIO_PIN_4
#define PWM_1_GPIO_Port GPIOB
#define PWM_2_Pin GPIO_PIN_5
#define PWM_2_GPIO_Port GPIOB
#define LB01_Pin GPIO_PIN_6
#define LB01_GPIO_Port GPIOB
#define HAL21_Pin GPIO_PIN_7
#define HAL21_GPIO_Port GPIOB
#define LT01_Pin GPIO_PIN_8
#define LT01_GPIO_Port GPIOB
#define HAL11_Pin GPIO_PIN_9
#define HAL11_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
