/*
 * timer_config.h
 *
 *  Created on: Mar 4, 2022
 *      Author: Farouk
 */

#ifndef INC_TIMER_CONFIG_H_
#define INC_TIMER_CONFIG_H_

/*
 *  Don't change those if you don't know what you are doing :)
 */
#define F_CLK          8000UL		 // CPU_CLK
#define PRELOAD_VALUE  0xfff0UL


/************ Options **********/

#define EDGE_ALIGNED_UP       (0<<4)
#define EDGE_ALIGNED_DOWN     (1<<4)
#define CENTER_ALIGNED_MODE1  (1<<5)
#define CENTER_ALIGNED_MODE2  (2<<5)
#define CENTER_ALIGNED_MODE3  (3<<5)

#define TIM_MODE 	EDGE_ALIGNED_UP

/*
 * OVER_UNDER_FLOW , ALL_SRCS
 */
#define OVER_UNDER_FLOW  (1<<2)
#define ALL_SRCS		 0x00
#define EVENT_SRC	ALL_SRCS


// Config this with the time period you want
#define WAIT_PERIOD_IN_MS  1000



#endif /* INC_TIMER_CONFIG_H_ */
