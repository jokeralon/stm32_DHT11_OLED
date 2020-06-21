#include "bsp_systick.h"

void SysTick_Delay_ms(uint16_t time)
{
	SysTick_Config( SystemClockSpeed / 1000);	//1ms
	while(time--)
	{
		/* 当计数器的值减小到 0 的时候，CRTL 寄存器的位 16 会置 1 */
		while( !( (SysTick->CTRL)&(1<<16) ) );
	}
	/* 关闭 SysTick 计时器 */
	SysTick->CTRL &= ~ SysTick_CTRL_ENABLE_Msk;
	
}
void SysTick_Delay_us(uint16_t time)
{
	SysTick_Config( SystemClockSpeed / 1000000);	//1ms
	while(time--)
	{
		/* 当计数器的值减小到 0 的时候，CRTL 寄存器的位 16 会置 1 */
		while( !( (SysTick->CTRL)&(1<<16) ) );
	}
	/* 关闭 SysTick 计时器 */
	SysTick->CTRL &= ~ SysTick_CTRL_ENABLE_Msk;
	
}
