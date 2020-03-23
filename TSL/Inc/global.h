/*
 * global.h
 *
 *  Created on: Feb 26, 2020
 *      Author: Suphot-pc
 */

#ifndef GLOBAL_H_
#define GLOBAL_H_

#include "main.h"
#include "driver_Input.h"
#include "driver_Output.h"
//#include "Process.h"

typedef struct
{
	uint16_t Input;
	uint16_t Display;
	uint16_t Output;
	uint16_t Alarm;
	uint16_t Key;
	uint16_t Modbus;
} Tick_sType;

typedef struct
{
	uint32_t Counter;	//
	uint16_t HighTime;	//
} Value_sType;

extern sOutput_sType sOutput;
extern Tick_sType Tick;
extern Value_sType Value;
extern Input_sType sInput;

extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim6;
extern TIM_HandleTypeDef htim14;

extern uint8_t FlagSetting;
void EncoderTimer(void);

#endif /* GLOBAL_H_ */
