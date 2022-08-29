/**************************************************/
/* Author     : farouk                            */
/* Version    : V01                               */
/* Date       : 16 March 2022                     */
/**************************************************/
#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

#include "STD_TYPES.h"
/* Register Definition */


#define RCC_BASE_ADDRESS	0x40023800
#define RCC_CR        (*((u32 *)(RCC_BASE_ADDRESS+0x00)))
#define RCC_PLLCFGR   (*((u32 *)(RCC_BASE_ADDRESS+0x04)))
#define RCC_CFGR      (*((u32 *)(RCC_BASE_ADDRESS+0x08)))
#define RCC_CIR		  (*((u32 *)(RCC_BASE_ADDRESS+0x0C)))
#define RCC_AHB1RSTR  (*((u32 *)(RCC_BASE_ADDRESS+0x10)))
#define RCC_AHB2RSTR  (*((u32 *)(RCC_BASE_ADDRESS+0x14)))
#define RCC_APB1RSTR  (*((u32 *)(RCC_BASE_ADDRESS+0x20)))
#define RCC_APB2RSTR  (*((u32 *)(RCC_BASE_ADDRESS+0x24)))
#define RCC_AHB1ENR   (*((u32 *)(RCC_BASE_ADDRESS+0x30)))
#define RCC_AHB2ENR   (*((u32 *)(RCC_BASE_ADDRESS+0x34)))
#define RCC_APB1ENR	  (*((u32 *)(RCC_BASE_ADDRESS+0x40)))
#define RCC_APB2ENR	  (*((u32 *)(RCC_BASE_ADDRESS+0x44)))

/* clock sources */
#define RCC_HSE_CRYSTAL      0
#define RCC_HSE_RC           1
#define RCC_HSI              2
#define RCC_PLL              3

/* PLL Options */
#define RCC_PLL_IN_HSI_DIV_2  0
#define RCC_PLL_IN_HSE_DIV_2  1
#define RCC_PLL_IN_HSE        2

#endif 
