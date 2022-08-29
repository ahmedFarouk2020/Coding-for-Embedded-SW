#include "stm32f4xx.h"
#include "i2c.h"

void I2C1_INIt(void)
{
	// Enable clock GPIOB
	RCC->AHB1ENR |=1;
	//set PB8 , PB9 to alternate mode
	GPIOB->MODER &=~(1U<<16);
	GPIOB->MODER |= (1U<<17);
	GPIOB->MODER &=~(1U<<18);
	GPIOB->MODER |= (1U<<19);
	// set alternate function
	GPIOB->AFR[1] &=~(0xffu);
	GPIOB->AFR[1] |= (0x44u);
	//Set PB8 ,PB9 to open drain
	GPIOB->OTYPER |= (1U<<8);
	GPIOB->OTYPER |= (1U<<9);
	//Set pull up
	GPIOB->PUPDR |= (1U<<16);
	GPIOB->PUPDR &=~(1U<<17);
	GPIOB->PUPDR |= (1U<<18);
	GPIOB->PUPDR &=~(1U<<19);
	//Enable clock I2C1
	RCC->APB1ENR |= (1U<<21);
	// set and reset reset mode (for reinitialization)
	I2C1->CR1 |= (1U<<15);
	I2C1->CR1 |=~(1U<<15);
	//SET The peripheral input clock
	I2C1->CR2 = (1U<<3); //8 Mhz
	// Set I2C to standard mode
	I2C1->CCR = 80;
	// SET RISE TIME
	I2C1->TRISE = 17;
	// ENABLE I2C1
	I2C1->CR1|=(1U<<0);
}

void I2C1_READ(char slaveAddres,char memoryAddress,char data[],int n)
{
	volatile int tmp;

	// CHECK IF THE BUS IS BUSY
	while(I2C1->SR2 &(1U<<1)){}



	// Generate start
	I2C1->CR1 |= (1U<<8);
	// WAIT UNTIL START FLAG IS SET
	while(!(I2C1->SR1 &(1U<<0))){}



	// Transmit slave address + WRITE
	I2C1->DR = slaveAddres<<1;
	// WAIT UNTIL ADDRESS FLAG IS SET
	while(!(I2C1->SR1 &(1U<<1))){}
	// CLEAR THE ADDRESS FLAG
	tmp = I2C1->SR2;


	// TRANSMITT MEMORY ADDRESS
	I2C1->DR = memoryAddress;
	// WAIT UNTIL DATA REGISTER IS EMPTY
	while(!(I2C1->SR1 & (1U<<7))){}


	//RESTART
	// Generate start
	I2C1->CR1 |= (1U<<8);
	// WAIT UNTIL START FLAG IS SET
	while(!(I2C1->SR1 &(1U<<0))){}


	// Transmit slave address + READ
	I2C1->DR = slaveAddres<<1|(1U<<0);
	// WAIT UNTIL ADDRESS FLAG IS SET
	while(!(I2C1->SR1 &(1U<<1))){}
	// CLEAR THE ADDRESS FLAG
	tmp = I2C1->SR2;

	//RECIEVE DATA
	for(int i =0 ; i<n;i++)
	{
		while(!(I2C1->SR1 & (1<<6))){}
		data[i] = (char)I2C1->DR;
	}


	// stop
	// CLear ACK
	I2C1->CR1 &=~(1U<<10);
	// Generate stop
	I2C1->CR1 |=(1U<<9);

}
