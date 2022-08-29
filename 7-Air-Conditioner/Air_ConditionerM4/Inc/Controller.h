/*
 * Controller.h
 *
 *  Created on: Apr 20, 2022
 *      Author: Farouk
 */

#ifndef INC_CONTROLLER_H_
#define INC_CONTROLLER_H_

#include "utils.h"

void Controller_Init(void);
void Controller_CalculateActuateSig(void);
float32_type Controller_MapToPwmLevels(void);
void Controller_SetDesiredTemp(unsigned char temp);
void Controller_Manage(void);



#endif /* INC_CONTROLLER_H_ */
