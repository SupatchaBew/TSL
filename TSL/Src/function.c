/*
 * function.c
 *
 *  Created on: Feb 26, 2020
 *      Author: Suphot-pc
 */

#include "main.h"
#include "spi.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

#include "main.h"
#include "global.h"
#include "driver_Input.h"
#include "driver_Output.h"
#include "initial_parameter.h"
#include "function.h"

uint8_t IsClosedToLimit(void)
{
	return (trig_H1[2].Counter > 200 && trig_H1[2].Counter < 800) ? 1:0;
}



void run_Function(void)
{
//	if (trig_up.Active == HOLDTRIG) {
//		nValue.Status = 1;
//	} else if (trig_dw.Active == HOLDTRIG) {
//		nValue.Status = 2;
//	} else{
//	}
//
//
//	if(nValue.Status && !nValue.LastStatus){
//		if (nValue.Status == 1) {
//			sOutput.bit.Out_B1 = 1;
//			sOutput.bit.Out_B2 = 1;
//			nValue.LastStatus = 1;
//		} else if (nValue.Status == 2) {
//			sOutput.bit.Out_A1 = 1;
//			sOutput.bit.Out_A2 = 1;
//			nValue.LastStatus = 2;
//		}
//	}

//	if(trig_up.Active != nValue.buttonUpLastStatus) {
//		nValue.buttonUpLastStatus = HOLDTRIG;
//	}
//	if(trig_dw.Active != nValue.buttonDownLastStatus) {
//		nValue.buttonDownLastStatus = HOLDTRIG;
//	}

//
//	if ((trig_up.Active == HOLDTRIG || trig_dw.Active == HOLDTRIG) && (nValue.Status == nValue.LastStatus)) {
//		if (nValue.pwmValue[0] < DUTY_MAX) {
//			nValue.pwmValue[0] += 2;
//		}
//		if (nValue.pwmValue[1] < DUTY_MAX) {
//			nValue.pwmValue[1] += 2;
//		}

//		if(nValue.Status == 2){
//			if((trig_H1.Counter - trig_H2.Counter) > 5){
//				nValue.pwmValue[0] -= 1;
//			}
//			else if((trig_H2.Counter - trig_H1.Counter) > 5){
//				nValue.pwmValue[1] -= 1;
//			}
//		}else{
//			if((trig_H1.Counter - trig_H2.Counter) > 5){
//				nValue.pwmValue[1] -= 1;
//			}
//			else if((trig_H2.Counter - trig_H1.Counter) > 5){
//				nValue.pwmValue[0] -= 1;
//			}
//		}



//	}else {
//		if (nValue.pwmValue[0] > DUTY_MIN) {
//			nValue.pwmValue[0] -= 4;
//		} else {
//			sOutput.bit.Out_A1 = 0;
//			sOutput.bit.Out_B1 = 0;
//			nValue.pwmValue[0] = DUTY_MIN;
//			nValue.Status = 0;
//			nValue.LastStatus = 0;
//		}
//		if (nValue.pwmValue[1] > DUTY_MIN) {
//			nValue.pwmValue[1] -= 4;
//		} else {
//			sOutput.bit.Out_A2 = 0;
//			sOutput.bit.Out_B2 = 0;
//			nValue.pwmValue[1] = DUTY_MIN;
//			nValue.Status = 0;
//			nValue.LastStatus = 0;
//		}
//	}

//	if(nValue.pwmValue[0] < DUTY_MIN)
//		nValue.pwmValue[0] = DUTY_MIN;
//	if(nValue.pwmValue[1] < DUTY_MIN)
//		nValue.pwmValue[1] = DUTY_MIN;
//
//	user_pwm_setvalue(nValue.pwmValue[0], PWM_CH_1);
//	user_pwm_setvalue(nValue.pwmValue[1], PWM_CH_2);

}

void run(void)
{
//	if (trig_up.Active == HOLDTRIG) {
//		nValue.Status = 1;
//	} else if (trig_dw.Active == HOLDTRIG) {
//		nValue.Status = 2;
//	} else{
//	}
//
//
//	if(nValue.Status && !nValue.LastStatus){
//		if (nValue.Status == 1) {
//			sOutput.bit.Out_B1 = 1;
//			sOutput.bit.Out_B2 = 1;
//			nValue.LastStatus = 1;
//		} else if (nValue.Status == 2) {
//			sOutput.bit.Out_A1 = 1;
//			sOutput.bit.Out_A2 = 1;
//			nValue.LastStatus = 2;
//		}
//	}
//
//	if(trig_H1[2].Counter < 100 && trig_up.Active == HOLDTRIG){
//		nValue.rundowntoreset[0] = 1;
//	}
//
//	if(trig_H1[2].Counter < 100 && trig_H1[2].Counter > 20 && nValue.rundowntoreset[0] == 1){
//		if (nValue.pwmValue[0] < DUTY_MAX/2) {
//			nValue.pwmValue[0] += 2;
//		}else{
//			nValue.pwmValue[0] -= 2;
//		}
//		if (nValue.pwmValue[1] < DUTY_MAX/2) {
//			nValue.pwmValue[1] += 2;
//		}
//		else{
//			nValue.pwmValue[1] -= 2;
//		}
//	}
//	else{
//		nValue.rundowntoreset[0] = 0;
//		run_Function();
//	}
//
//
//
//	if(nValue.pwmValue[0] < DUTY_MIN)
//		nValue.pwmValue[0] = DUTY_MIN;
//	if(nValue.pwmValue[1] < DUTY_MIN)
//		nValue.pwmValue[1] = DUTY_MIN;
//
//	user_pwm_setvalue(nValue.pwmValue[0], PWM_CH_1);
//	user_pwm_setvalue(nValue.pwmValue[1], PWM_CH_2);
}

void check_holding_key(void)
{
//	if (trig_up.Active == HOLDTRIG) {
//		nValue.Status = Move_up;
//	} else if (trig_dw.Active == HOLDTRIG) {
//		nValue.Status = Move_down;
//	} else{
//	}
//
//	if(nValue.Status && !nValue.LastStatus){
//		if (nValue.Status == Move_up) {
//			sOutput.bit.Out_B1 = 1;
//			sOutput.bit.Out_B2 = 1;
//			nValue.LastStatus = 1;
//		} else if (nValue.Status == Move_down) {
//			sOutput.bit.Out_A1 = 1;
//			sOutput.bit.Out_A2 = 1;
//			nValue.LastStatus = 2;
//		}
//	}
}


void Reset_default_position(void)
{
	uint8_t speed_1 =0, speed_2 = 0;
	nValue.LastStatus[0] = 1;
	nValue.LastStatus[1] = 1;
	while (BUTTOM_LIMIT_1 == GPIO_PIN_RESET || BUTTOM_LIMIT_2 == GPIO_PIN_RESET)
	{
		sOutput.bit.Out_B1 = 1;
		sOutput.bit.Out_B2 = 1;

		if (speed_1 < DUTY_MAX/2) {
			speed_1 += ((halsensor[0][0].Counter - halsensor[1][0].Counter) > 0 ? 2 : 1);
		}else{
			speed_1 -= ((halsensor[0][0].Counter - halsensor[1][0].Counter) > 0 ? 1 : 2);
		}
		if (speed_2 < DUTY_MAX/2) {
			speed_2 += 1;
		}else{
			speed_2 -= 1;
		}
		user_pwm_setvalue(speed_1, PWM_CH_1);
		user_pwm_setvalue(speed_2, PWM_CH_2);
		run_Output(&sOutput);
		HAL_Delay(50);
	}
	nValue.LastStatus[0] = 0;
	nValue.LastStatus[1] = 0;
	user_pwm_setvalue(0, PWM_CH_1);
	user_pwm_setvalue(0, PWM_CH_2);
}


void run_motor(uint8_t motor_id)
{
	//run
	int16_t dif = 0;
	dif = (halsensor[motor_id][0].Counter - halsensor[!motor_id][0].Counter) * (nValue.Status[motor_id] == 2? 1 : -1);

	if (trig_up.Active == HOLDTRIG) {
		nValue.Status[motor_id] = Move_up;
		if(motor_id == 0){
			sOutput.bit.Out_B1 = 1;
		}
		else{
			sOutput.bit.Out_B2 = 1;
		}
	} else if (trig_dw.Active == HOLDTRIG) {
		if(motor_id == 0){
			sOutput.bit.Out_A1 = 1;
		}
		else{
			sOutput.bit.Out_A2 = 1;
		}
		nValue.Status[motor_id] = Move_down;
	} else{
	}

	if(nValue.Status[motor_id] && !nValue.LastStatus[motor_id])
		nValue.LastStatus[motor_id] = nValue.Status[motor_id];

	if(halsensor[motor_id][0].Counter < 100 && trig_up.Active == HOLDTRIG){
		nValue.rundowntoreset[motor_id] = 1;
		nValue.rundowntoreset[!motor_id] = 1;
	}

	if(halsensor[motor_id][0].Counter < 100 && halsensor[motor_id][0].Counter != 0 && nValue.rundowntoreset[motor_id] == 1){
		if (nValue.pwmValue[motor_id] < DUTY_MAX/2) {
			nValue.pwmValue[motor_id] += ((halsensor[0][0].Counter - halsensor[1][0].Counter) > 0 ? 2 : 1);
		}else{
			nValue.pwmValue[motor_id] -= ((halsensor[0][0].Counter - halsensor[1][0].Counter) > 0 ? 1 : 2);
		}
	}
	else{
			nValue.rundowntoreset[motor_id] = 0;
			if ((trig_up.Active == HOLDTRIG || (trig_dw.Active == HOLDTRIG && halsensor[motor_id][0].Counter < 700)) && (nValue.Status[motor_id] == nValue.LastStatus[motor_id])
					) {
				if (nValue.pwmValue[motor_id] < DUTY_MAX - 1) {
					nValue.pwmValue[motor_id] += (dif > 0 ? 1:2);
				}
				else{
					if( dif > 0){
						nValue.pwmValue[motor_id] -= 1;
					}
					else{
						nValue.pwmValue[!motor_id] -= 1;
					}
				}


			}else {
				if (nValue.pwmValue[motor_id] > DUTY_MIN) {
					nValue.pwmValue[motor_id] -= (dif > 0 ? 4:3);
				} else {
					if(motor_id == 0){
						sOutput.bit.Out_A1 = 0;
						sOutput.bit.Out_B1 = 0;
					}
					else{
						sOutput.bit.Out_A2 = 0;
						sOutput.bit.Out_B2 = 0;
					}
					nValue.pwmValue[motor_id] = DUTY_MIN;
					nValue.Status[motor_id] = 0;
					nValue.LastStatus[motor_id] = 0;
				}
			}
	}

	if(HAL_GPIO_ReadPin(LB02_GPIO_Port, LB02_Pin) == GPIO_PIN_SET){
		halsensor[1][0].Counter = 0;
	}

	if(HAL_GPIO_ReadPin(HAL11_GPIO_Port, HAL11_Pin) == GPIO_PIN_SET){
		halsensor[0][0].Counter = 0;
	}


		if(nValue.pwmValue[0] < DUTY_MIN)
			nValue.pwmValue[0] = DUTY_MIN;

		if(nValue.pwmValue[1] < DUTY_MIN)
			nValue.pwmValue[1] = DUTY_MIN;






		user_pwm_setvalue(nValue.pwmValue[motor_id], motor_id);

}

