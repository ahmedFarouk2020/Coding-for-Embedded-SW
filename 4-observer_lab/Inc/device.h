/*
 * device.h
 *
 *  Created on: Mar 31, 2022
 *      Author: moham
 */

#ifndef INC_DEVICE_H_
#define INC_DEVICE_H_

unsigned char Get_Data(void);
unsigned char subscribe(void (*ptr)(unsigned char));
void unsubscribe(unsigned char ID);
void notify (void);

#endif /* INC_DEVICE_H_ */
