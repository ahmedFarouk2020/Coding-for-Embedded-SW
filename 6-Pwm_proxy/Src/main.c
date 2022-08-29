#include "RCC_interface.h"
#include "DIO.h"
#include "Pwm_interface.h"
int main()
{
    RCC_voidInitSysClock();
    RCC_voidEnableClock(RCC_AHB1, 0);// GPIOA
    RCC_voidEnableClock(RCC_AHB1, 1);// GPIOB
    RCC_voidEnableClock(RCC_APB1, 1);// TIM3

    DIO_Init();
    Pwm_Init();

    while(1);
}
