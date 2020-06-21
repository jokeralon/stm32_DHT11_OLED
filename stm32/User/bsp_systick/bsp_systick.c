#include "bsp_systick.h"

void SysTick_Delay_ms(uint16_t time)
{
	SysTick_Config( SystemClockSpeed / 1000);	//1ms
	while(time--)
	{
		/* ����������ֵ��С�� 0 ��ʱ��CRTL �Ĵ�����λ 16 ���� 1 */
		while( !( (SysTick->CTRL)&(1<<16) ) );
	}
	/* �ر� SysTick ��ʱ�� */
	SysTick->CTRL &= ~ SysTick_CTRL_ENABLE_Msk;
	
}
void SysTick_Delay_us(uint16_t time)
{
	SysTick_Config( SystemClockSpeed / 1000000);	//1ms
	while(time--)
	{
		/* ����������ֵ��С�� 0 ��ʱ��CRTL �Ĵ�����λ 16 ���� 1 */
		while( !( (SysTick->CTRL)&(1<<16) ) );
	}
	/* �ر� SysTick ��ʱ�� */
	SysTick->CTRL &= ~ SysTick_CTRL_ENABLE_Msk;
	
}
