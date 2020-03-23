/**
 ******************************************************************************
 * File Name          	: fm25lxx.h
 * Description        	: This file FRAM for deriver FM25LXX.
 * Date				: 4/11/2019
 * Author				: R&D
 ******************************************************************************
 */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef FM25LXX_H_
#define FM25LXX_H_

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "spi.h"

/* Private defines -----------------------------------------------------------*/
#define FM25LXX_SPI			hspi1

#define	FM25LXX_CS_Hi 		HAL_GPIO_WritePin(FM25L16B_NSS_GPIO_Port, FM25L16B_NSS_Pin, 1 );
#define FM25LXX_CS_Lo 		HAL_GPIO_WritePin(FM25L16B_NSS_GPIO_Port, FM25L16B_NSS_Pin, 0 );

//#define FM25L04	// 512 bytes
#define FM25L16		// 2048 bytes
//#define FM25L64	// 8192 bytes

/*OPCODE*/
#define FM25LXX_OPCODE_WR_ENABLE	                	0x06 // Write enable latch
#define FM25LXX_OPCODE_WR_DISABLE	                	0x04 // Write disable
#define FM25LXX_OPCODE_RD_STATUS_REG	                0x05 // Read status register
#define FM25LXX_OPCODE_WR_STATUS_REG	                0x01 // Write status register
#define FM25LXX_OPCODE_RD_MEMORY_DATA	                0x03 // Read memory data
#define FM25LXX_OPCODE_WR_MEMORY_DATA	                0x02 // Write memory data

/* Exported functions prototypes ---------------------------------------------*/
extern void FM25LXX_Init(void);
extern void FM25LXX_EnableWrite(void);
extern void FM25LXX_DisableWrite(void);
extern unsigned char FM25LXX_ReadStatusReg(void);

void FM25LXX_SaveData(uint16_t address, uint8_t *data, uint8_t length);
void FM25LXX_LoadData(uint16_t address, uint8_t *data, size_t length);

void FM25LXX_WriteMemory(uint16_t address, uint8_t data);
unsigned char FM25LXX_ReadMemory(uint16_t address);

#endif /* FM25LXX_H_ */
/************************ (C) COPYRIGHT PRIMUS *****END OF FILE****/
