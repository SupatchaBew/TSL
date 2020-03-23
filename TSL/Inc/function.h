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

#define BUTTOM_LIMIT_1 				HAL_GPIO_ReadPin(HAL11_GPIO_Port, HAL11_Pin)
#define BUTTOM_LIMIT_2 				HAL_GPIO_ReadPin(LB02_GPIO_Port, LB02_Pin)
enum PWM_CHANNEL{
	PWM_CH_1,
	PWM_CH_2,
};

extern void user_pwm_setvalue(uint16_t value, uint16_t channel);
extern void run_Function(void);
extern void run(void);
extern void check_holding_key(void);
extern void Reset_default_position(void);
extern void run_motor(uint8_t motor_id);

#endif /* FUNCTION_H_ */
