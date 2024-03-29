/*
 * timer_private.h
 *
 *  Created on: Mar 4, 2022
 *      Author: Farouk
 */

#ifndef INC_PWM_PRIVATE_H_
#define INC_PWM_PRIVATE_H_


#define NVIC_ISER0 *((unsigned int*)(0xE000E100+0x00))
#define NVIC_ISER1 *((unsigned int*)(0xE000E100+0x04))
#define NVIC_ISER2 *((unsigned int*)(0xE000E100+0x08))

#define NVIC_ICER0 *((unsigned int*)(0XE000E180+0x00))
#define NVIC_ICER1 *((unsigned int*)(0XE000E180+0x04))
#define NVIC_ICER2 *((unsigned int*)(0XE000E180+0x08))


//#define RCC_BASE	0x40023800
//#define RCC_APB1ENR *((unsigned int*)(RCC_BASE+0x40))

#define TIM02  0x40000000UL

#define TIM2_CR1  *((volatile unsigned int*) (TIM02+0x00))
#define TIM2_SR   *((volatile unsigned int*) (TIM02+0x10))
#define TIM2_PSC  *((volatile unsigned int*) (TIM02+0x28))
#define TIM2_CNT  *((volatile unsigned int*) (TIM02+0x24))
#define TIM2_ARR  *((volatile unsigned int*) (TIM02+0x2C))
#define TIM2_DIER *((volatile unsigned int*) (TIM02+0x0C))



#define TIM_START (1<<0)



void TIM_EnableNVICInterrupt(unsigned char interrupt_id, unsigned char set_id);
void TIM_disableNVICInterrupt(unsigned char interrupt_id, unsigned char set_id);


#endif /* INC_PWM_PRIVATE_H_ */
