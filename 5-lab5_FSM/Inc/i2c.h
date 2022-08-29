#ifndef INC_I2C_H_
#define INC_I2C_H_

void I2C1_INIt(void);
void I2C1_READ(char slaveAddres,char memoryAddress,char data[],int n);
#endif /* INC_I2C_H_ */
