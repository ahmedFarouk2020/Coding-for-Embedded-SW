/**************************************************/
/* Author     : farouk                            */
/* Version    : V01                               */
/* Date       : 16 March 2022                     */
/**************************************************/
#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H

/* CLOCK SOURCES */
#define HSI 0
#define HSE 1
#define PPL 2

/* Options: RCC_HSE_CRYSTAL
            RCC_HSE_RC
            RCC_HSI
            RCC_PLL         */
#define RCC_CLOCK_TYPE    RCC_HSI


/* Options:     RCC_PLL_IN_HSI_DIV_2
                RCC_PLL_IN_HSE_DIV_2
				RCC_PLL_IN_HSE      */
/* Note: Select value only if you have PLL as input clock source */
#if RCC_CLOCK_TYPE == RCC_PLL
#define RCC_PLL_INPUT     RCC_PLL_IN_HSE_DIV_2
#endif


/* Options: 2 to 16 */
/* Note: Select value only if you have PLL as input clock source */
#if RCC_CLOCK_TYPE == RCC_PLL
#define RCC_PLL_MUL_VAL   4
#endif


#endif 
