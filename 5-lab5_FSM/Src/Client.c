/*
 * Client.c
 *
 *  Created on: Apr 30, 2022
 *      Author: Farouk
 */

#include "stm32f4xx.h"


void Client_DoActions(void)
{
    // Gpio clk enable
    RCC->AHB1ENR |=(1<<0);

    /*initialize pin6 portA as output*/
    GPIOA->MODER |=(1<<10);
    GPIOA->MODER &=~(1<<11);

    GPIOA->ODR |= (1u<<5);// led on
}
