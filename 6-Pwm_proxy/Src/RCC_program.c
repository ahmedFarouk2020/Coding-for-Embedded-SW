/**************************************************/
/* Author     : farouk                            */
/* Version    : V01                               */
/* Date       : 16 March 2022                     */
/**************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

void RCC_voidInitSysClock()
{
    #if   RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
        RCC_CR   = 0x00090000;        /* ENABLE HSE WITH NO BYPASS AND ENABLE CSS */
        RCC_CFGR = 0x00000001;		 /* CHOOSE SYS CLK TO BE HSE */
    #elif RCC_CLOCK_TYPE == RCC_HSE_RC
        RCC_CR   = 0x000d0000;         /* ENABLE HSE WITH BYPASS AND ENABLE CSS */
		RCC_CFGR = 0x00000001;		 /* CHOOSE SYS CLK TO BE HSE */
    #elif RCC_CLOCK_TYPE == RCC_HSI
        RCC_CR   = 0x00000081;          /* ENABLE HSI WIHT NO TRIM */
		RCC_CFGR = 0x00000000;			/* CHOOSE SYS CLK TO BE HSE */
    #elif RCC_CLOCK_TYPE == RCC_PLL
    #endif
}

void RCC_voidEnableClock(u8 Copy_n8BusId, u8 Copy_u8PerId)
{
    if (Copy_u8PerId <= 31)
    {
        switch (Copy_n8BusId)
        {
            case RCC_AHB1   : SET_BIT(RCC_AHB1ENR , Copy_u8PerId);  break;
			case RCC_AHB2   : SET_BIT(RCC_AHB2ENR , Copy_u8PerId);  break;
            case RCC_APB1   : SET_BIT(RCC_APB1ENR , Copy_u8PerId);  break;
            case RCC_APB2   : SET_BIT(RCC_APB2ENR , Copy_u8PerId);  break;
        }
    }
    else
    {
         /* return error */
    }
}


void RCC_VoidDisableClock(u8 Copy_n8BusId, u8 Copy_u8PerId)
{
    if (Copy_u8PerId <= 31)
    {
        switch (Copy_n8BusId)
        {
			case RCC_AHB1   : CLR_BIT(RCC_AHB1ENR , Copy_u8PerId); break;
			case RCC_AHB2   : CLR_BIT(RCC_AHB2ENR , Copy_u8PerId); break;
            case RCC_APB1   : CLR_BIT(RCC_APB1ENR , Copy_u8PerId); break;
            case RCC_APB2   : CLR_BIT(RCC_APB2ENR , Copy_u8PerId); break;
        }
    }
    else
    {
         /* return error */
    }
}
