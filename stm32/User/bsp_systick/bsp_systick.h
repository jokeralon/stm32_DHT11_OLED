#ifndef	__BSP_SYSTICK_H
#define __BSP_SYSTICK_H
#include "stm32f10x.h"

#define SystemClockSpeed 72000000	/*  基数  */

void SysTick_Delay_ms(uint16_t time);/*  延时 毫秒  */
void SysTick_Delay_us(uint16_t time);/*  延时 微秒  */
#endif
