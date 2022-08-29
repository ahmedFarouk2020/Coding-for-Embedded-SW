/*
 * DIO_Cfg.c
 *
 *  Created on: Mar 23, 2022
 *      Author: moham
 */

#include "DIO_Cfg.h"

const DIO_ChannelConfigType DIO_ConfigParam[DIO_NUM_OF_CHANNELS] =
{
    {/*Channel-0*/
     0,
     0,
     1,
     0,
	 0
    },
    {/*channel -1*/
     0,
     1,
     1,
     0,
	 0
    },
    {/*channel -2*/
     0,
     2,
     1,
     0,
	 0
    },
    {/*channel -3*/
     0,
     3,
     1,
     0,
	 0
    },
    {/*channel -4*/
     0,
     4,
     1,
     0,
	 0
    },
    {/*channel -5*/
     1,
     0,
     0,
     1,
     0
    },
    {/*channel -6*/
     1,
     1,
     0,
     1,
     0
    },
    {/*channel -7*/
     1,
     2,
     0,
     1,
     0
    },
    {/*channel -8*/
     1,
     3,
     0,
     2,
     0
    },
};


const DIO_ChannelGroupConfigType DIO_ChannelGroupList[DIO_NUM_OF_CHANNELGROUPS] = {
       {
            {0,1,2,3},
            4
       },
       {
            {5,6,7,8},
            4
      }
};
