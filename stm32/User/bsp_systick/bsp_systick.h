#ifndef	__BSP_SYSTICK_H
#define __BSP_SYSTICK_H
#include "stm32f10x.h"

#define SystemClockSpeed 72000000	/*  ����  */

void SysTick_Delay_ms(uint16_t time);/*  ��ʱ ����  */
void SysTick_Delay_us(uint16_t time);/*  ��ʱ ΢��  */
#endif
