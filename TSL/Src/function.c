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

void Reset_default_position(void)
{
	uint8_t speed_1 =0, speed_2 = 0;
	nValue.LastStatus[0] = Move_down;
	nValue.LastStatus[1] = Move_down;
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

void set_stop_motor(void)
{
	if(nValue.motor_id == 0){
		sOutput.bit.Out_A1 = 0;
		sOutput.bit.Out_B1 = 0;
	}
	else{
		sOutput.bit.Out_A2 = 0;
		sOutput.bit.Out_B2 = 0;
	}
	nValue.pwmValue[nValue.motor_id] = DUTY_MIN;
	nValue.Status[nValue.motor_id] = 0;
	nValue.LastStatus[nValue.motor_id] = 0;
}

void set_motor_direction(void)
{
	if (trig_up.Active == HOLDTRIG && trig_dw.Active == HOLDTRIG) {
		set_stop_motor();
	}
	else if (trig_up.Active == HOLDTRIG) {
		nValue.Status[nValue.motor_id] = Move_up;
		if(nValue.motor_id == 0){
			sOutput.bit.Out_A1 = 1;
		}
		else{
			sOutput.bit.Out_A2 = 1;
		}
	}
	else if (trig_dw.Active == HOLDTRIG) {
		if(nValue.motor_id == 0){
			sOutput.bit.Out_B1 = 1;
		}
		else{
			sOutput.bit.Out_B2 = 1;
		}
		nValue.Status[nValue.motor_id] = Move_down;
	} else{
	}
}

void run_motor(uint8_t id)
{
	nValue.motor_id = id;
	set_motor_direction();
	//run
	int16_t dif = 0;
	dif = (halsensor[nValue.motor_id][0].Counter - halsensor[!nValue.motor_id][0].Counter) * (nValue.Status[nValue.motor_id] == Move_down? -1 : 1);


	if(nValue.Status[nValue.motor_id] && !nValue.LastStatus[nValue.motor_id])
		nValue.LastStatus[nValue.motor_id] = nValue.Status[nValue.motor_id];

	if(halsensor[nValue.motor_id][0].Counter < LINEAR_RESET_ZONE && trig_dw.Active == HOLDTRIG){
		nValue.rundowntoreset[nValue.motor_id] = 1;
		nValue.rundowntoreset[!nValue.motor_id] = 1;
	}

	if(halsensor[nValue.motor_id][0].Counter != 0 && nValue.rundowntoreset[nValue.motor_id] == 1){
		if (nValue.pwmValue[nValue.motor_id] < DUTY_MAX/2) {
			nValue.pwmValue[nValue.motor_id] += ((halsensor[0][0].Counter - halsensor[1][0].Counter) > 0 ? 2 : 1);
		}else{
			nValue.pwmValue[nValue.motor_id] -= ((halsensor[0][0].Counter - halsensor[1][0].Counter) > 0 ? 1 : 2);
		}
	}
	else{
			nValue.rundowntoreset[nValue.motor_id] = 0;
			if ((trig_dw.Active == HOLDTRIG || (trig_up.Active == HOLDTRIG && halsensor[nValue.motor_id][0].Counter < sInput.highest_position))
					&& (nValue.Status[nValue.motor_id] == nValue.LastStatus[nValue.motor_id])
					) {
				if (nValue.pwmValue[nValue.motor_id] < DUTY_MAX - 1) {
					nValue.pwmValue[nValue.motor_id] += (dif > 0 ? 1:2);
				}
				else{
					if( dif > 0){
						nValue.pwmValue[nValue.motor_id] -= 1;
					}
					else{
						nValue.pwmValue[!nValue.motor_id] -= 1;
					}
				}


			}else {

				if (nValue.pwmValue[nValue.motor_id] > DUTY_MIN) {
					nValue.pwmValue[nValue.motor_id] -= (dif > 0 ? 5:4);
				} else {
					set_stop_motor();
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

		user_pwm_setvalue(nValue.pwmValue[nValue.motor_id], nValue.motor_id);

}

