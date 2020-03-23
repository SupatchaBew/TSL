/**
 ******************************************************************************
 * File Name          : driver_Input.h
 * Description        : This file Driver for All input.
 ******************************************************************************
 */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef DRIVER_INPUT_H_
#define DRIVER_INPUT_H_

/* Includes ------------------------------------------------------------------*/
#include "main.h"
//#include "Hardware_Config.h"

/* Private defines -----------------------------------------------------------*/
#define	SWDOWN						HAL_GPIO_ReadPin(KEY_DW_GPIO_Port, KEY_DW_Pin)
#define	SWUP						HAL_GPIO_ReadPin(KEY_UP_GPIO_Port, KEY_UP_Pin)
#define	SWF0						HAL_GPIO_ReadPin(KEY_F0_GPIO_Port, KEY_F0_Pin)
#define	SWF1						HAL_GPIO_ReadPin(KEY_F1_GPIO_Port, KEY_F1_Pin)

#define	LT_1						HAL_GPIO_ReadPin(LT01_GPIO_Port, LT01_Pin)
#define	LB_1						HAL_GPIO_ReadPin(LB01_GPIO_Port, LB01_Pin)
#define	LT_2						HAL_GPIO_ReadPin(LT02_GPIO_Port, LT02_Pin)
#define	LB_2						HAL_GPIO_ReadPin(LB02_GPIO_Port, LB02_Pin)

#define	PIN_ENA						0//HAL_GPIO_ReadPin(EN_A_GPIO_Port, EN_A_Pin)
#define	PIN_ENB						0//HAL_GPIO_ReadPin(EN_B_GPIO_Port, EN_B_Pin)

#define	HAL1_1						HAL_GPIO_ReadPin(HAL11_GPIO_Port, HAL11_Pin)
#define	HAL2_1						HAL_GPIO_ReadPin(HAL21_GPIO_Port, HAL21_Pin)
#define	HAL1_2						HAL_GPIO_ReadPin(HAL12_GPIO_Port, HAL12_Pin)
#define	HAL2_2						HAL_GPIO_ReadPin(HAL22_GPIO_Port, HAL22_Pin)

enum TRIG_INPUT {
	TRIG, DEBOUNCE, RELEASE
};
enum TRIG_ACTIVE {
	NONETRIG, BEFORETRIG, ONETRIG, NOTRIG, HOLDTRIG, AFTERTRIG
};

//>>>>--------------- Version Switch button Hardware  -----<<< //

//>>>>-----------------------------------------------------<<< //

typedef struct {
	int8_t Status;
	int8_t Buff;
	int32_t Count;
	union {
		uint16_t Byte;
		struct {
			uint8_t INA :1;
			uint8_t INB :1;
			uint8_t INF :6;
		};
	} Pin;
} Encoder_Type;
typedef struct {
	union {
		uint16_t Byte;
		struct {
			uint8_t SW_DN :1;			//	bit 0
			uint8_t SW_UP :1;			//	bit 1
			uint8_t SW_F0 :1;			//  bit 2
			uint8_t SW_F1 :1;   		//  bit 3
			uint8_t LIMIT_TP_1 :1;  	//  bit 4
			uint8_t LIMIT_BM_1 :1;   	//  bit 5
			uint8_t LIMIT_TP_2 :1;  	//  bit 6
			uint8_t LIMIT_BM_2 :1;   	//  bit 7
			uint8_t DIPSW_LEVEL_1 :1;  	//  bit 0
			uint8_t DIPSW_LEVEL_2 :1;  	//  bit 1
			uint8_t DIPSW_LEVEL_3 :1;  	//  bit 2
			uint8_t DIPSW_LEVEL_4 :1;  	//  bit 3
		} Bit;
	} status;
} Pin_Type;


typedef struct {
	Pin_Type Even;
	Encoder_Type Encoder2;
	Encoder_Type Encoder1;
} Input_sType;

typedef struct {
	unsigned char HoldTime;
	unsigned char Active;
	unsigned char Stand;
	unsigned char Status;
} Trig_sType;

typedef struct {
	unsigned char Status;
	signed long Counter;
	unsigned char Active;
} Count_sType;

extern Trig_sType trig_up;
extern Trig_sType trig_dw;
extern Trig_sType trig_f0;
extern Trig_sType trig_f1;

extern Count_sType trig_H1[4];
extern Count_sType trig_H2[2];
extern Count_sType halsensor[2][2];

extern Encoder_Type Encoder[2];

extern void run_Input(void);
extern void run_Count(void);
extern void INPUT_GetEncoder(uint32_t *count);
extern void trig_Count(Count_sType *trig, int in, int mode);

#endif /* DRIVER_BUTTON_H_ */
