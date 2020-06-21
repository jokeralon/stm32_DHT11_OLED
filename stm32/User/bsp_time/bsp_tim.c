#include "bsp_tim.h"
void Bssic_NVIC_Config(void)
{
	NVIC_InitTypeDef NVIC_InitStruct;
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	
	NVIC_InitStruct.NVIC_IRQChannel = TIM7_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 1;
	NVIC_InitStruct.NVIC_IRQChannelCmd  = ENABLE;
	
	NVIC_Init(&NVIC_InitStruct);
}
void Basic_TIM_Config(void)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM7,ENABLE);
	
	TIM_TimeBaseInitStruct.TIM_Period = 1000-1; //ARR 自动重装载寄存器
	TIM_TimeBaseInitStruct.TIM_Prescaler = 72-1;//PSC 预分频器
	
	
	TIM_TimeBaseInit(TIM7, &TIM_TimeBaseInitStruct );
	TIM_ClearFlag(TIM7 ,TIM_FLAG_Update);
	TIM_ITConfig(TIM7, TIM_IT_Update, ENABLE);
	
	TIM_Cmd(TIM7, ENABLE);
	Bssic_NVIC_Config();
	
	
}
