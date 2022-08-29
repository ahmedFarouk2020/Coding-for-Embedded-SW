#include "stm32f4xx.h"
#include "DIO.h"

			

int main(void)
{
    unsigned short int channelgroup_data = (unsigned short int)0;
	DIO_Init();

	DIO_ChannelGroupRead(1, &channelgroup_data);

	DIO_ChannelGroupWrite(0, (unsigned char)channelgroup_data);


	while(1)
	{
//		for(int i =0 ;i< 500000;i++){}
//		GPIOA->ODR ^= (1<<1);
	}

}


