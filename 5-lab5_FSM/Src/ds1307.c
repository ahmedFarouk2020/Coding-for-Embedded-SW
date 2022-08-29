#include "i2c.h"
#include "ds1307.h"


extern void Client_DoActions(void);
char sAddres = 0x44;
char *Time_DataReadBuffer;
char ReadStartAddress;
char ReadDataLength;
unsigned char Time_IsReadRequested;

void Time_ReadData(char memoryAddress,char data[],int n)
{
	Time_DataReadBuffer = data;
	ReadStartAddress = memoryAddress;
	ReadDataLength = n;
	Time_IsReadRequested = (unsigned char)1;
}

#define IDLE          0
#define PROCESSING       1
unsigned char CurrentState = IDLE;
void Time_ManageDataRead(void)
{

    switch(CurrentState)
    {
        case IDLE:
        {
            if(Time_IsReadRequested == 1)
            {
                Time_IsReadRequested = 0;
                CurrentState = PROCESSING;
            }
            else
            {
                // stay at the same state
            }
        }
        break;

        case PROCESSING:
        {
            I2C1_READ(sAddres,ReadStartAddress,Time_DataReadBuffer,ReadDataLength);
            // call client notification function
            Client_DoActions();

            CurrentState = IDLE; // must be the last line in the case (in case of OS)
        }
        break;

    }
}


//void Time_ManageDataRead(void)
//{
//	// wait Time_ReadData to be called and if called
//	if(Time_IsReadRequested)
//	{
//		I2C1_READ(sAddres,ReadStartAddress,Time_DataReadBuffer,ReadDataLength);
//		// call client notification function
//	    /*call any function*/
//
//	}
//	else
//	{
//		/* 		 wait Time_ReadData to be called         */
//	}
//}
