/***************************************
 * 				GPIO_Private.h
 * contains private functions for this module
 *
 * Author: Farouk
 *
 * Date: 3-18-2021
 *
 */


#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H





#define NUMBER_OF_PORTS		2
#define NUMBER_OF_GPIO_REG	10

/**********
 * PORT_ID: Base address
 
 * REG_ID: offset of registers
 
 * Return the definition of the register
 #define GPIO_REG(PORT_ID,REG_ID) 	((unsigned int*)((PORT_ID)+(REG_ID)))
*/





typedef struct {
    volatile unsigned int MODER;
    volatile unsigned int OTYPER;
    volatile unsigned int OSPEEDR;
    volatile unsigned int PUPDR;
    volatile unsigned int IDR;
    volatile unsigned int ODR;
    volatile unsigned int BSRR;
    volatile unsigned int LCKR;
    volatile unsigned int AFRL;
    volatile unsigned int AFRR;
}DIO_Regs;

/* Register Definition of PortA */
#define GPIOA_BASE_ADDRESS ((DIO_Regs*)0x40020000)
/* Register Definition of PortB */
#define GPIOB_BASE_ADDRESS ((DIO_Regs*)0x40020400)





#endif
