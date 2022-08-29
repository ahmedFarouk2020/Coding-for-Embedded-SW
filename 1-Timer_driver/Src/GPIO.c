/***************************************
 * 				GPIO.c
 * contains implementation of all module's functions
 *
 * Author: Farouk
 *
 * Date: 3-12-2021
 *
 */


#include "GPIO_Private.h"
#include "GPIO_Interface.h"
#include "GPIO_Config.h"

#define NUMBER_OF_PORTS     ((unsigned char)2)

DIO_Regs* GPIOA = GPIOA_BASE_ADDRESS;
DIO_Regs* GPIOB = GPIOB_BASE_ADDRESS;

DIO_Regs* GPIO[NUMBER_OF_PORTS] = {GPIOA, GPIOB};


void GPIO_EnableClk(unsigned char portID)
{
    unsigned int* const RCC_AHB1ENR = ((unsigned int*)(0x40023800+0x30));
	*RCC_AHB1ENR |= (unsigned int)((unsigned int)1 <<portID);
}

void GPIO_Init(unsigned char portID, unsigned char PIN_NO, unsigned char PIN_Dir)
{
	
		/* clear this bit field (MODER) */
		GPIO[portID]->MODER &= (unsigned int)( ~((unsigned int)3 << (2U*PIN_NO)) );
		/* assign value for the bit field */
		GPIO[portID]->MODER |= (unsigned int)( ((unsigned int)PIN_Dir>>4) << (2U*PIN_NO) ); /* 0x10 */

		if ((PIN_Dir>>(unsigned char)4) == (unsigned char)0)  /* input */
		{
			/* clear bit field (PUPDR) */
		    GPIO[portID]->PUPDR &= (unsigned int)( ~((unsigned int)3 << (PIN_NO*2U)) );
			/* assign value for the bit field */
		    GPIO[portID]->PUPDR |= (unsigned int)( ((unsigned int)PIN_Dir & 0x0fU) <<(PIN_NO*2U) );
		}

		else /* output or AF */
		{
			/* clear the bit field (OTYPER) */
		    GPIO[portID]->OTYPER &= (unsigned int)( ~((unsigned int)1 << PIN_NO) );
			/* assign value for the bit field */
		    GPIO[portID]->OTYPER |= (unsigned int)((PIN_Dir & (unsigned int)0x0f) <<PIN_NO);
		}

		
}

void GPIO_WritePin(unsigned char portID, unsigned char PIN_NO, unsigned char Data)
{
	/* filtering Data */
	if(Data != (unsigned char)0) { Data=(unsigned char)1; }

	
	/* clear bits (ODR) */
	GPIO[portID]->ODR &= (unsigned int)( ~((unsigned int)1<< PIN_NO) );
	/* assign "Data" to bits */
	GPIO[portID]->ODR |= (unsigned int)((unsigned int)Data << PIN_NO);
	
}

unsigned char GPIO_ReadPin(unsigned char portID, unsigned char PIN_NO)
{
	unsigned char PinState = 255;

	PinState = (unsigned char)( GPIO[portID]->IDR & ((unsigned int)1<<PIN_NO) ) >> PIN_NO;

	return PinState;
}









