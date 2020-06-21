#ifndef	__BSP_I2C_H
#define __BSP_I2C_H
#include "stm32f10x.h"
#include "../bsp_usart/bsp_usart.h"
typedef uint8_t u8;
static void i2c_Delay(void)
{
	uint8_t i;

	/*　
	 	下面的时间是通过逻辑分析仪测试得到的。
    工作条件：CPU主频72MHz ，MDK编译环境，1级优化
  
		循环次数为10时，SCL频率 = 205KHz 
		循环次数为7时，SCL频率 = 347KHz， SCL高电平时间1.5us，SCL低电平时间2.87us 
	 	循环次数为5时，SCL频率 = 421KHz， SCL高电平时间1.25us，SCL低电平时间2.375us 
	*/
	for (i = 0; i < 10; i++);
}

/*  								I2C 						  */
#define I2Cx		I2C1
#define I2C_PORT		GPIOB
#define I2C_SCL_PIN			GPIO_Pin_6
#define I2C_SDA_PIN			GPIO_Pin_7


#define I2C_SCL_H	GPIO_SetBits(I2C_PORT, I2C_SCL_PIN)					/*  SCL置高  */
#define I2C_SCL_L	GPIO_ResetBits(I2C_PORT, I2C_SCL_PIN)				/*  SCL置低  */
#define I2C_SDA_H	GPIO_SetBits(I2C_PORT, I2C_SDA_PIN)					/*  SDA置高  */
#define I2C_SDA_L	GPIO_ResetBits(I2C_PORT, I2C_SDA_PIN)				/*  SDA置低  */

#define I2C_GET_SDA		((I2C_PORT->IDR & I2C_SDA_PIN) !=0 )		/*  读取SDA  */

void I2C_Config(void);																				/*  I2C初始化  */
void I2C_SendReg(u8 DevAddr,u8 RegAddr, u8 data);							/*  写寄存器  */
#endif /* __BSP_I2C_H */
