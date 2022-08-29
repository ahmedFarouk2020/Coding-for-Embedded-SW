/*
 * device.c
 *
 *  Created on: Mar 31, 2022
 *      Author: moham
 */
#include "stm32f4xx.h"
#include "device.h"

unsigned char data;

unsigned char Get_Data(void)
{
    // read pin
    data = ( (1<<0) & GPIOA->IDR)?1:0;
	return data;
}
