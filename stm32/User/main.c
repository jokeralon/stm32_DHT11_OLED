#include "stm32f10x.h"
#include "./bsp_usart/bsp_usart.h"
#include "./bsp_dht11/bsp_dht11.h"
#include "./bsp_systick/bsp_systick.h"
#include "./bsp_i2c/bsp_i2c.h"
#include "./bsp_oled/bsp_oled.h"
#include "string.h"

void OLED_Test(char *humi_h,char *humi_l,char *temp_h,char *temp_l,uint8_t Char_Size);
int main(void)
{
	u8 flag;
	char temp[4][10];
	DHT11_Data_TypeDef DHT11_Data;
	
	USART_Config(9600);
	DHT11_Config();
	I2C_Config();
	OLED_Init();
	
	while(1)
	{
		flag = DHT11_ReadData(&DHT11_Data);
		
		if(flag)
		{
			
			sprintf(temp[0], "%d", DHT11_Data.humi_int);
			sprintf(temp[1], "%d", DHT11_Data.humi_deci);
			sprintf(temp[2], "%d", DHT11_Data.temp_int);
			sprintf(temp[3], "%d", DHT11_Data.temp_deci);
		}else
		{
			printf("获取数据失败！\r\n");
		}
		SysTick_Delay_ms(2000);
		OLED_Test( (char *)temp[0], (char *)temp[1], (char *)temp[2],(char *)temp[3], 16);
		printf("湿度: %s.%s	 ", temp[0], temp[1]);
		printf("  温度: %s.%s\r\n", temp[2],temp[3]);
	}
}

void OLED_Test(char *humi_h,char *humi_l,char *temp_h,char *temp_l,uint8_t Char_Size)
{
	
  OLED_Clear(); 
	
	
	OLED_ShowCN(32,0,0);
	OLED_ShowCN(48,0,1);
	OLED_ShowCN(64,0,2);
	OLED_ShowCN(80,0,3);
	
	/* 一个字符串8X16 */
	/* x轴一个字符串间距单位8， 0-127 	一行最多16个字符*/
	/* y轴一个字符串间距单位2，	0-7 		最多4行字符*/
	
  OLED_ShowString(24,2,(char *)("Humi:"),Char_Size);
	OLED_ShowString(72,2,(char *)(humi_h),Char_Size);
	OLED_ShowString(88,2,(char *)("."),Char_Size);
	OLED_ShowString(96,2,(char *)(humi_l),Char_Size);
	
	OLED_ShowString(24,4,(char *)("Temp:"),Char_Size);
	OLED_ShowString(72,4,(char *)(temp_h),Char_Size);
	OLED_ShowString(88,4,(char *)("."),Char_Size);
	OLED_ShowString(96,4,(char *)(temp_l),Char_Size);

 
}
