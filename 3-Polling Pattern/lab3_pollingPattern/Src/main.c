#include "stm32f4xx.h"
#include "PollerTimer.h"
#include "poller.h"



int main(void)
{
    RCC->AHB1ENR |=(1<<0);

    /*initialize pin6 portA as output*/
    GPIOA->MODER |=(1<<10);
    GPIOA->MODER &=~(1<<11);


    /*initialize pin0 portA as input - pullup*/
    GPIOA->MODER &=~(1<<0);
    GPIOA->MODER &=~(1<<1);

    GPIOA->PUPDR |= (1<<2);
    GPIOA->PUPDR &= ~(1<<1);



    StartTimer();
    EnableInterrupt();
    SetPollingTime(500);
    StartPolling();

    while(1)
    {

    }

}

void TIM2_IRQHandler(void)
{
    TIM2->SR &=~(1<<0);
    CallPollingFunction();
}


