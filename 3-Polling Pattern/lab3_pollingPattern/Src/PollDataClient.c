/*
 * PollDataClient.c
 *
 *  Created on: Mar 31, 2022
 *      Author: moham
 */
#include "stm32f4xx.h"
#include "PollingDataClient.h"

void Handle_data(unsigned char data)
{
	if(data == 0) // button is pressed
	{
		GPIOA->ODR |= (1u<<5);
	}
	else // button isn't pressed
	{
		GPIOA->ODR &= ~(1u<<5);
	}
}
