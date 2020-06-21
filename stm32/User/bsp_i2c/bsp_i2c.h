#ifndef	__BSP_I2C_H
#define __BSP_I2C_H
#include "stm32f10x.h"
#include "../bsp_usart/bsp_usart.h"
typedef uint8_t u8;
static void i2c_Delay(void)
{
	uint8_t i;

	/*��
	 	�����ʱ����ͨ���߼������ǲ��Եõ��ġ�
    ����������CPU��Ƶ72MHz ��MDK���뻷����1���Ż�
  
		ѭ������Ϊ10ʱ��SCLƵ�� = 205KHz 
		ѭ������Ϊ7ʱ��SCLƵ�� = 347KHz�� SCL�ߵ�ƽʱ��1.5us��SCL�͵�ƽʱ��2.87us 
	 	ѭ������Ϊ5ʱ��SCLƵ�� = 421KHz�� SCL�ߵ�ƽʱ��1.25us��SCL�͵�ƽʱ��2.375us 
	*/
	for (i = 0; i < 10; i++);
}

/*  								I2C 						  */
#define I2Cx		I2C1
#define I2C_PORT		GPIOB
#define I2C_SCL_PIN			GPIO_Pin_6
#define I2C_SDA_PIN			GPIO_Pin_7


#define I2C_SCL_H	GPIO_SetBits(I2C_PORT, I2C_SCL_PIN)					/*  SCL�ø�  */
#define I2C_SCL_L	GPIO_ResetBits(I2C_PORT, I2C_SCL_PIN)				/*  SCL�õ�  */
#define I2C_SDA_H	GPIO_SetBits(I2C_PORT, I2C_SDA_PIN)					/*  SDA�ø�  */
#define I2C_SDA_L	GPIO_ResetBits(I2C_PORT, I2C_SDA_PIN)				/*  SDA�õ�  */

#define I2C_GET_SDA		((I2C_PORT->IDR & I2C_SDA_PIN) !=0 )		/*  ��ȡSDA  */

void I2C_Config(void);																				/*  I2C��ʼ��  */
void I2C_SendReg(u8 DevAddr,u8 RegAddr, u8 data);							/*  д�Ĵ���  */
#endif /* __BSP_I2C_H */
