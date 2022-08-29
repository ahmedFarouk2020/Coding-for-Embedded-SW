/*
 * device.c
 *
 *  Created on: April 16, 2022
 *      Author: Farouk
 */
#include "stm32f4xx.h"
#include "device.h"
#include "device_Config.h"

extern void (*functions_ptr[MAX_NUM_CLIENTS])(unsigned char);

unsigned char data;


unsigned char Get_Data(void)
{
    // read pin
    data = ( (1<<0) & GPIOA->IDR)?1:0;

	notify();

	return data;
}

void notify (void){

	// call all update functions
    unsigned char count;

    for(count=0; count<MAX_NUM_CLIENTS; count++) {

        if(functions_ptr[count] != NULL) {
            functions_ptr[count](data);
        }

    }
}

unsigned char subscribe(void (*ptr)(unsigned char)){

	unsigned char subscriptionId = 0;
	unsigned char count;
	for(count=0; count<MAX_NUM_CLIENTS; count++) {

        if(functions_ptr[count] == NULL) {
            functions_ptr[count] = ptr;
            subscriptionId = count;
        }
        else { /* continue */ }
	}
	return subscriptionId;
}

void unsubscribe(unsigned char ID)
{
    functions_ptr[ID] = NULL;
}
