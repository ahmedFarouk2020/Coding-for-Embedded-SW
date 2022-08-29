/*
 * DIO_Cfg.c
 *
 *  Created on: Mar 23, 2022
 *      Author: moham
 */

#include "DIO_Cfg.h"

const DIO_ChannelConfigType DIO_ConfigParam[DIO_NUM_OF_CHANNELS] =
{
    {/*Channel-0 TIM3CH1 */
     1,
     4,
     2,/* AF */
     0,
     0,
     2 /* AF2 */
    },
    {/*Channel-1 TIM2CH1 */
     0,
     5,
     2,/* AF */
     0,
     0,
     2 /* AF2 */
    },
};


const DIO_ChannelGroupConfigType DIO_ChannelGroupList[DIO_NUM_OF_CHANNELGROUPS] = {
       {
            {0,1,2,3},
            4
       }
};
