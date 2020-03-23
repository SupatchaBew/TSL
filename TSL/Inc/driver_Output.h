/*
 * drover_Output.h
 *
 *  Created on: Oct 24, 2019
 *      Author: Suphot-pc
 */

#ifndef DRIVER_OUTPUT_H_
#define DRIVER_OUTPUT_H_

#define OUTPUT_A1(x) 		HAL_GPIO_WritePin(	INA_1_GPIO_Port, 		INA_1_Pin, x)
#define OUTPUT_ON_A1 		HAL_GPIO_WritePin(	INA_1_GPIO_Port, 		INA_1_Pin, 1)
#define OUTPUT_OFF_A1 		HAL_GPIO_WritePin(	INA_1_GPIO_Port, 		INA_1_Pin, 0)

#define OUTPUT_A2(x) 		HAL_GPIO_WritePin(	INA_2_GPIO_Port, 		INA_2_Pin, x)
#define OUTPUT_ON_A2 		HAL_GPIO_WritePin(	INA_2_GPIO_Port, 		INA_2_Pin, 1)
#define OUTPUT_OFF_A2 		HAL_GPIO_WritePin(	INA_2_GPIO_Port, 		INA_2_Pin, 0)

#define OUTPUT_B1(x) 		HAL_GPIO_WritePin(	INB_1_GPIO_Port, 		INB_1_Pin, x)
#define OUTPUT_ON_B1 		HAL_GPIO_WritePin(	INB_1_GPIO_Port, 		INB_1_Pin, 1)
#define OUTPUT_OFF_B1 		HAL_GPIO_WritePin(	INB_1_GPIO_Port, 		INB_1_Pin, 0)

#define OUTPUT_B2(x) 		HAL_GPIO_WritePin(	INB_2_GPIO_Port, 		INB_2_Pin, x)
#define OUTPUT_ON_B2 		HAL_GPIO_WritePin(	INB_2_GPIO_Port, 		INB_2_Pin, 1)
#define OUTPUT_OFF_B2 		HAL_GPIO_WritePin(	INB_2_GPIO_Port, 		INB_2_Pin, 0)

#define OUTPUT_SEL1(x) 		HAL_GPIO_WritePin(	SEL_1_GPIO_Port, 		SEL_1_Pin, x)
#define OUTPUT_ON_SEL1 		HAL_GPIO_WritePin(	SEL_1_GPIO_Port, 		SEL_1_Pin, 1)
#define OUTPUT_OFF_SEL1		HAL_GPIO_WritePin(	SEL_1_GPIO_Port, 		SEL_1_Pin, 0)

#define OUTPUT_SEL2(x) 		HAL_GPIO_WritePin(	SEL_2_GPIO_Port, 		SEL_2_Pin, x)
#define OUTPUT_ON_SEL2 		HAL_GPIO_WritePin(	SEL_2_GPIO_Port, 		SEL_2_Pin, 1)
#define OUTPUT_OFF_SEL2		HAL_GPIO_WritePin(	SEL_2_GPIO_Port, 		SEL_2_Pin, 0)

enum RL_ST{
	RL_RESET,
	RL_SET
};
typedef union
{
	uint8_t Byte;
	struct
	{
		uint8_t Out_A1	 	:1;		//
		uint8_t Out_B1 		:1;		//
		uint8_t Out_A2 		:1;		//
		uint8_t Out_B2		:1;		//
		uint8_t Out_SEL1 	:1;		//
		uint8_t Out_SEL2 	:1;		//
		uint8_t Free 		:2;		//
	}bit;
} sOutput_sType;

extern void run_Output(sOutput_sType *Out);

#endif /* DRIVER_RELAY_H_ */
