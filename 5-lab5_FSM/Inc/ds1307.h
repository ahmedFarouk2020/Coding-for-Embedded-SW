/*
 * ds1307.h
 *
 *  Created on: Apr 22, 2022
 *      Author: moham
 */

#ifndef INC_DS1307_H_
#define INC_DS1307_H_

void Time_ReadData(char memoryAddress,char data[],int n);
void Time_ManageDataRead(void);

#endif /* INC_DS1307_H_ */
