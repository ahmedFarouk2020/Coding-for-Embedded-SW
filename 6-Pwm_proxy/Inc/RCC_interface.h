/**************************************************/
/* Author     : farouk                            */
/* Version    : V01                               */
/* Date       : 16 March 2022                     */
/**************************************************/
#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

#include "STD_TYPES.h"

/* BUS TYPE */
#define RCC_AHB1   0
#define RCC_AHB2   1
#define RCC_APB1   2
#define RCC_APB2   3

void RCC_voidInitSysClock(void);
void RCC_voidEnableClock(u8 Copy_n8BusId, u8 Copy_u8PerId);
void RCC_voidDisableClock(u8 Copy_n8BusId, u8 Copy_u8PerId);



#endif 
