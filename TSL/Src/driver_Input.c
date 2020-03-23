/**
 ******************************************************************************
 * File Name          : eeprom.c
 * Description        : This file EEPROM for build for deriver  24LC16.
 ******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "global.h"
#include "driver_Input.h"
#include "initial_parameter.h"

/* Private typedef -----------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

Trig_sType trig_up;
Trig_sType trig_dw;
Trig_sType trig_f0;
Trig_sType trig_f1;
Count_sType trig_H1[4];
Count_sType trig_H2[2];
Count_sType halsensor[2][2];
Encoder_Type Encoder[2];

/* Private user code ---------------------------------------------------------*/
void get_Switch_Status(void) {
	sInput.Even.status.Bit.SW_DN = SWDOWN;
	sInput.Even.status.Bit.SW_UP = SWUP;
	sInput.Even.status.Bit.SW_F0 = SWF0;
	sInput.Even.status.Bit.SW_F1 = SWF1;
}
void get_Limit_Status(void) {
	sInput.Even.status.Bit.LIMIT_TP_1 = LT_1;
	sInput.Even.status.Bit.LIMIT_BM_1 = LB_1;
	sInput.Even.status.Bit.LIMIT_TP_2 = LT_2;
	sInput.Even.status.Bit.LIMIT_BM_2 = LB_2;
}
void get_dipSwitch_Status(void) {
	sInput.Even.status.Bit.DIPSW_LEVEL_1 = 1;
	sInput.Even.status.Bit.DIPSW_LEVEL_2 = 0;
	sInput.Even.status.Bit.DIPSW_LEVEL_3 = 0;
	sInput.Even.status.Bit.DIPSW_LEVEL_4 = 0;
}
void get_Encoder_Status(char stA, char stB, Encoder_Type *En) {
	En->Pin.INA = stA;
	En->Pin.INB = stB;

	switch (En->Status) {
	case 0:
		if (En->Pin.Byte == 1 || En->Pin.Byte == 2) {
			En->Status = En->Pin.Byte;
		} else {
			En->Status = 0;
		}
		break;
	case 1:
		if (En->Pin.Byte == 3) {
			En->Buff = 1;
			En->Count -= En->Buff;
			En->Status = En->Pin.Byte;
		} else if (En->Pin.Byte == 0) {
			En->Status = En->Pin.Byte;
		}
		break;
	case 2:
		if (En->Pin.Byte == 3) {
			En->Buff = -1;
			En->Count += En->Buff;
			En->Status = En->Pin.Byte;
		} else if (En->Pin.Byte == 0) {
			En->Status = En->Pin.Byte;
		}
		break;
	case 3:
		if (En->Pin.Byte == 0 || En->Pin.Byte == 3) {
			En->Status = En->Pin.Byte;
		}
		break;
	default:
		En->Status = 0;
		break;
	}
}
void trig_input(Trig_sType *trig, int in, int delay) {
	switch (trig->Status) {
	case TRIG:
		if (in) {
			/*trig before deboune*/
			trig->Active = BEFORETRIG;
			trig->Status = DEBOUNCE;
		}else{
			trig->Active = NONETRIG;
			trig->HoldTime = 0;
			trig->Status = TRIG;
		}
		break;
	case DEBOUNCE:
		if (in) {
			if (++trig->HoldTime >= delay) {
				/*trig*/
				trig->Active = ONETRIG;
				trig->HoldTime = 0;
				trig->Status = RELEASE;
			}
		} else {
			/*no trig*/
			trig->Active = NOTRIG;
			trig->Status = RELEASE;
		}
		break;
	case RELEASE:
		if (!in) {
			trig->Status = TRIG;
		} else {
			trig->Active = HOLDTRIG;
			/*trig hold*/
		}
		break;
	}
}
void trig_Count(Count_sType *trig, int in, int mode) {
	switch (trig->Status) {
	case TRIG:
		if (in) {
			/*trig before deboune*/
			trig->Active = ONETRIG;
			trig->Counter += mode;
			trig->Status = RELEASE;
		}else{
			trig->Active = NONETRIG;
			trig->Status = TRIG;
		}
		break;
	case RELEASE:
		if (!in) {
			trig->Active = AFTERTRIG;
			trig->Status = TRIG;
		} else {
			trig->Active = HOLDTRIG;
			/*trig hold*/
		}
		break;
	}
}
void run_Input(void) {
	/* Get Input SW */
	get_Switch_Status();
	get_Limit_Status();
	get_dipSwitch_Status();
	trig_input(&trig_up, sInput.Even.status.Bit.SW_UP, 2);
	trig_input(&trig_dw, sInput.Even.status.Bit.SW_DN, 2);
	trig_input(&trig_f0, sInput.Even.status.Bit.SW_F0, 2);
	trig_input(&trig_f1, sInput.Even.status.Bit.SW_F1, 2);
}
void run_Count(void){
//	get_Encoder_Status(HAL1_1, HAL2_1, &Encoder[0]);
//	get_Encoder_Status(HAL1_2, HAL2_2, &Encoder[1]);

	if(trig_up.Active == HOLDTRIG){
		trig_Count(&trig_H1[0], HAL1_1, 1);
		trig_Count(&trig_H1[1], HAL2_1, 1);

		trig_Count(&trig_H2[0], HAL1_2, 1);
		trig_Count(&trig_H2[1], HAL2_2, 1);
	}
	else if(trig_dw.Active == HOLDTRIG){
		trig_Count(&trig_H1[0], HAL1_1, -1);
		trig_Count(&trig_H2[0], HAL1_2, -1);

		trig_Count(&trig_H1[1], HAL2_1, -1);
		trig_Count(&trig_H2[1], HAL2_2, -1);
	}
}

/************************ (C) COPYRIGHT PRIMUS *****END OF FILE****/
