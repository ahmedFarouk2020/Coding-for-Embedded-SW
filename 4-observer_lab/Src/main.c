#include "stm32f4xx.h"
#include "Client.h"
#include "device.h"



int main(void)
{
	/*initialize pin5 portA as output*/
	RCC->AHB1ENR |=(1<<0);

	GPIOA->MODER |=(1<<10);
	GPIOA->MODER &=~(1<<11);

	/*initialize pin0 portA as input - pullup*/
    GPIOA->MODER &=~(1<<0);
    GPIOA->MODER &=~(1<<1);

    GPIOA->PUPDR |= (1<<2);
    GPIOA->PUPDR &= ~(1<<1);

    Client_Init();
	while(1)
	{
		Get_Data();

		// delay
		for(int i=1000;i;i--);

		Handle_data();

		// delay
        for(int i=1000;i;i--);
	}

}




