/*
 * poller.c
 *
 *  Created on: Mar 31, 2022
 *      Author: moham
 */
#include "poller.h"
#include "device.h"
#include "PollingDataClient.h"
#include "ds1307.h"


int polling_enabled= 1;
int polling_counter= 1;
int counter = 0 ;

void Poll(void)
{
	if(polling_enabled && (!counter))
	{
		Time_ManageDataRead();
	}
	counter++;
	counter = counter%polling_counter;
}

void StartPolling(void)
{
	polling_enabled=1;
}

void StopPolling(void)
{
	polling_enabled=0;
}

void SetPollingTime(int polling_time)
{
	polling_counter = polling_time/100;
}
