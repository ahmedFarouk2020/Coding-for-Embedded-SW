/*
 * timer.c
 *
 *  Created on: Mar 4, 2022
 *      Author: Farouk
 */

#include "Pwm_config.h"
#include "Pwm_interface.h"
#include "stm32f4xx.h"


#define TIM2_INTERRPT_ID 28
#define TIM_START (1<<0)

TIM_TypeDef* timers[] = {TIM2, TIM3, TIM4, TIM5};

void Pwm_Init(void)
{
    RCC->APB1ENR |= (1<< RCC_APB1ENR_TIM3EN_Pos);
    /*Enable timer interrupt NVIC*/
    //NVIC_EnableIRQ(TIM3_IRQn);

/*
 * prescaler = (WAIT_PERIOD_IN_MS * F_clk) / PRELOAD
 */
    // set prescaler
    TIM3->PSC = 1000;//(WAIT_PERIOD_IN_MS *F_CLK)/ PRELOAD_VALUE;
    TIM3->ARR = 100; //PRELOAD_VALUE;
    TIM3->SR = 0;

    //Channel 1 config
    TIM3->CCMR1 |= (6UL << 4);    //Set OutputCompare mode to PWM
    TIM3->CCMR1 &= ~(3UL << 0);   //CC to output
    TIM3->CCER &= ~(1UL << 1);      //Output Compare polarity to active high
    TIM3->CCER |= (1UL << 0);       //Capture compare output enable

    //Set the Pulse width
    TIM3->CCR1 = 10;//10% duty cycle

    TIM3->CR1 = (TIM_MODE | TIM_START | ALL_SRCS);

}


void Pwm_ChangeDutyCycle(unsigned char duty_cycle)
{
    if( (duty_cycle<=100) || (duty_cycle>=0) ) {
        TIM3->CCR1 = (unsigned int)duty_cycle;
    }
}


unsigned char Pwm_Status(void)
{
	return (TIM3->SR & 1);
}

void Pwm_ClrIntFlag(void)
{
	TIM3->SR &= ~(1<<0);
}

void Pwm_EnableEventTrig(void)
{
	// enable event trigger sources
	TIM3->DIER |= 1;

}


void Pwm_DisableEventTrig(void)
{
	// disable event trigger sources
	TIM3->DIER &= ~1;
}