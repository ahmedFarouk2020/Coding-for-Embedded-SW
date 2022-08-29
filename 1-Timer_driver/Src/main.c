#include "STD_TYPES.h"
#include "GPIO_Interface.h"
#include "timer_interface.h"



unsigned char data = (unsigned char)0;

int main(void)
{

	GPIO_EnableClk(PORTA);
	GPIO_Init(PORTA, PIN0, OUTPUT_PUSHPULL);

	TIM_Init();
	TIM_EnableEventTrig();

	while(1)
	{}

}


void TIM2_IRQHandler(void) {
	TIM_ClrIntFlag();
    data = (1 ^ data) & 1;
    GPIO_WritePin(PORTA, PIN0, data);
}
