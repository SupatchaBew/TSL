/*
 * function.h
 *
 *  Created on: Feb 26, 2020
 *      Author: Suphot-pc
 */

#ifndef FUNCTION_H_
#define FUNCTION_H_

#define DUTY_MIN	0
#define DUTY_MAX	100

#define LINEAR_RESET_ZONE		100
#define LINEAR_HIGHT_LEVEL_0	200
#define LINEAR_HIGHT_LEVEL_1	400
#define LINEAR_HIGHT_LEVEL_2	600
#define LINEAR_HIGHT_LEVEL_3	800
#define LINEAR_HIGHT_LEVEL_4	1000

#define BUTTOM_LIMIT_1 				HAL_GPIO_ReadPin(LB01_GPIO_Port, LB01_Pin)
#define BUTTOM_LIMIT_2 				HAL_GPIO_ReadPin(LB02_GPIO_Port, LB02_Pin)
enum PWM_CHANNEL{
	PWM_CH_1,
	PWM_CH_2,
};

extern void user_pwm_setvalue(uint16_t value, uint16_t channel);
extern void Reset_default_position(void);
extern void run_motor(uint8_t id);

#endif /* FUNCTION_H_ */
