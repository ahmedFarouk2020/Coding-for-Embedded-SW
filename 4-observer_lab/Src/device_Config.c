/*
 * device_Config.c
 *
 *  Created on: Apr 29, 2022
 *      Author: Farouk
 */

#include "device_Config.h"

void (*functions_ptr[MAX_NUM_CLIENTS])(unsigned char) = {0,0,0,0,0};
