/*
 * PollDataClient.c
 *
 *  Created on: Mar 31, 2022
 *      Author: moham
 */
#include "stm32f4xx.h"
#include "PollingDataClient.h"

void Handle_data(float data)
{
	if(data>900.0)
	{
		GPIOA->ODR |= (1u<<5);
	}
	else
	{
		GPIOA->ODR &= ~(1u<<5);
	}
}
