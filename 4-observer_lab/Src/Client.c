/*
 * PollDataClient.c
 *
 *  Created on: Mar 31, 2022
 *      Author: moham
 */
#include "stm32f4xx.h"
#include "Client.h"
#include "device.h"

unsigned char ClientData;
unsigned char Client_SubscriptionID;

void Client_Init(void){
    Client_SubscriptionID = subscribe(update);
}

void Client_Stop(void) {
    unsubscribe(Client_SubscriptionID);
}


void update(unsigned char data){
    ClientData = data;
}


void Handle_data(void)
{
    if(ClientData == 0) // button is pressed
    {
        GPIOA->ODR |= (1u<<5);
    }
    else // button isn't pressed
    {
        GPIOA->ODR &= ~(1u<<5);
    }
}
