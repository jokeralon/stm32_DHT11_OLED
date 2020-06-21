#include "bsp_dht11.h"


/*********************************************
 * @function：DHT11_OutputMode
 *
 * @param：None
 *
 * 		@arg：None
 * 
 * @note：DHT11 DATA引脚输出模式
 * 
 * @retval：None
 *********************************************/
void DHT11_OutputMode(void)
{
	
	GPIO_InitTypeDef	GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Pin = DHT11_DATA_PIN;
	/*  推挽输出  */
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(DHT11_DATA_PROT, &GPIO_InitStruct);
}
/*********************************************
 * @function：DHT11_OutputMode
 *
 * @param：None
 *
 * 		@arg：None
 * 
 * @note：DHT11 DATA引脚输入模式
 * 
 * @retval：None
 *********************************************/
void DHT11_InputMode(void)
{
	GPIO_InitTypeDef	GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Pin = DHT11_DATA_PIN;
	/*  浮空输入  */
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(DHT11_DATA_PROT, &GPIO_InitStruct);
}

/*********************************************
 * @function：DHT11_Config
 *
 * @param：None
 *
 * 		@arg：None
 * 
 * @note：配置DHT11 DATA引脚
 * 
 * @retval：None
 *********************************************/

void DHT11_Config(void)
{
	GPIO_InitTypeDef	GPIO_InitStruct;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	
	GPIO_InitStruct.GPIO_Pin = DHT11_DATA_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(DHT11_DATA_PROT, &GPIO_InitStruct);
	
	DHT11_DATA_H;
}

/*********************************************
 * @function：DHT11_ReadByte
 *
 * @param：None
 *
 * 		@arg：None
 * 
 * @note：读取DHT11模块一字节数据
 * 
 * @retval：temp 获取DHT11模块数据
 *********************************************/

u8 DHT11_ReadByte(void)
{
	u8 i, temp=0;
	for(i=0; i<8; i++)
	{
		while( DHT11_READ_DATA != 1);
		SysTick_Delay_us(40);
		if( DHT11_READ_DATA == 1)
		{
			while( DHT11_READ_DATA == 1);
			temp|=(uint8_t)(0x01<<(7-i));
		}else
		{
			temp&=(uint8_t)~(0x01<<(7-i));
		}
	}
	
	return temp;
}


u8 DHT11_ReadData(DHT11_Data_TypeDef *DHT11_Data)
{
	
	DHT11_OutputMode();
	DHT11_DATA_L;
	SysTick_Delay_ms(18);
	DHT11_DATA_H;
	SysTick_Delay_us(30);
	DHT11_InputMode();
	
	if(DHT11_READ_DATA == 0)
	{
		while( DHT11_READ_DATA == 0);
		while( DHT11_READ_DATA == 1);
		/* 湿度高八位 */
		DHT11_Data->humi_int = DHT11_ReadByte();
		DHT11_Data->humi_deci = DHT11_ReadByte();
		DHT11_Data->temp_int = DHT11_ReadByte();
		DHT11_Data->temp_deci = DHT11_ReadByte();
		DHT11_Data->check_sum = DHT11_ReadByte();
		DHT11_OutputMode();
		DHT11_DATA_H;
		if(DHT11_Data->check_sum == DHT11_Data->humi_int + DHT11_Data->humi_deci + DHT11_Data->temp_int+ DHT11_Data->temp_deci)
			return SUCCESS;
		else 
			return ERROR;
	}else
	return ERROR;
	
}
