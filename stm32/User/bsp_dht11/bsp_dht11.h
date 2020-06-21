#ifndef __BSP_DHT11_H
#define __BSP_DHT11_H
#include "stm32f10x.h"
#include "../bsp_systick/bsp_systick.h"
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint64_t u64;

typedef struct
{
	char   humi_int;		//湿度的整数部分
	char   humi_deci;	 	//湿度的小数部分
	char   temp_int;	 	//温度的整数部分
	char   temp_deci;	 	//温度的小数部分
	char   check_sum;	 	//校验和            
} DHT11_Data_TypeDef;

/*  				DHT11					  */
#define DHT11_DATA_PIN		GPIO_Pin_7
#define DHT11_DATA_PROT		GPIOC

#define DHT11_DATA_H			GPIO_SetBits(DHT11_DATA_PROT, DHT11_DATA_PIN)
#define DHT11_DATA_L			GPIO_ResetBits(DHT11_DATA_PROT, DHT11_DATA_PIN)

#define DHT11_READ_DATA		GPIO_ReadInputDataBit(DHT11_DATA_PROT, DHT11_DATA_PIN)


u8 DHT11_ReadData(DHT11_Data_TypeDef *DHT11_Data);		/*  获取数据  */
void DHT11_Config(void);															/*  初始化    */
#endif  /* __BSP_DHT11_H */
