/*
 * timer_interface.h
 *
 *  Created on: Mar 4, 2022
 *      Author: Farouk
 */

#ifndef INC_PWM_INTERFACE_H_
#define INC_PWM_INTERFACE_H_





void Pwm_Init(void);

void Pwm_ChangeDutyCycle(unsigned char duty_cycle);

unsigned char Pwm_Status(void);

void Pwm_ClrIntFlag(void);

void Pwm_EnableEventTrig(void);

void Pwm_DisableEventTrig(void);


#endif /* INC_PWM_INTERFACE_H_ */
