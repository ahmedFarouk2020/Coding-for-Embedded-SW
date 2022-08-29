#include "poller.h"
#include "Controller.h"
#include "TC72.h"
#include "USART.h"
#include "utils.h"

char_type polling_enabled = 1;
uint32_type polling_counter = 1;
uint32_type counter = 0;
extern uint32_type poller_auto_reload;

extern volatile float32_type ActualTemprature;

void Poll(void)
{
	if ((polling_enabled == (char_type)1) && (counter == (uint32_type)0))
	{
	    ActualTemprature = TC72_GetTemperature();
		USART_Transmit("TEMP: ");
		USART_Transmit(convertIntegerToString((uint16_type)ActualTemprature));
	    /* Set temperature to 30 */
		Controller_Manage();
	}
	counter = (counter + (uint32_type)1) % ((uint32_type)polling_counter);
}

void StartPolling(void) { polling_enabled = (char_type)1; }

void StopPolling(void) { polling_enabled = (char_type)0; }

void SetPollingTime(uint32_type polling_time)
{
	polling_counter = polling_time / poller_auto_reload;
}
