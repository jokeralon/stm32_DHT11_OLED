#include "bsp_i2c.h"



/*  I2C ����ģʽ  0: ���ģ��     1: Ӳ��I2C  */
#define I2C_MODE		1


/*********************************************
 * @function��I2C_GPIO_Config
 *
 * @param��None
 *
 * 		@arg��None
 * 
 * @note����ʼ��I2C GPIO����
 * 
 * @retval��None
 *********************************************/
void I2C_GPIO_Config()
{
	GPIO_InitTypeDef	GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
#if I2C_MODE == 0
	/* I2C	SCL */
	GPIO_InitStruct.GPIO_Pin	= I2C_SCL_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_OD;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(I2C_PORT, &GPIO_InitStruct);
	/* I2C	SDA	*/
	GPIO_InitStruct.GPIO_Pin	= I2C_SDA_PIN;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_OD;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
#else
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_OD;
	GPIO_InitStruct.GPIO_Pin = I2C_SCL_PIN | I2C_SDA_PIN;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	
#endif
	GPIO_Init(I2C_PORT, &GPIO_InitStruct);
}

/*********************************************
 * @function��I2C_Mode_Config
 *
 * @param��None
 *
 * 		@arg��None
 * 
 * @note����ʼ��Ӳ��I2C
 * 
 * @retval��None
 *********************************************/

void I2C_Mode_Config()
{
	I2C_InitTypeDef	I2C_InitStruct;
	/*  ��ʼ��  */
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C1, ENABLE);
	/*  �Զ�Ӧ��  */
	I2C_InitStruct.I2C_Ack = I2C_Ack_Enable;
	/*  ָ����ַ����  */
	I2C_InitStruct.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;
	/*  ����  */
	I2C_InitStruct.I2C_ClockSpeed = 400000;
	/*  ռ�ձ�  */
	I2C_InitStruct.I2C_DutyCycle = I2C_DutyCycle_16_9;
	/*  ģʽ  */
	I2C_InitStruct.I2C_Mode = I2C_Mode_I2C;
	/*  ָ������I2C��ַ  */
	I2C_InitStruct.I2C_OwnAddress1 = 0xc0;
	
	I2C_Init(I2Cx, &I2C_InitStruct);
	I2C_Cmd(I2Cx, ENABLE);
	
}


/*******************************************************************************/
#if I2C_MODE == 0
void I2C_Config(void)
{
	I2C_GPIO_Config();
}

/*********************************************
 * @function��I2C_SendStart
 *
 * @param��None
 *
 * 		@arg��None
 * 
 * @note�����I2C������ʼ�ź�
 * 
 * @retval��None
 *********************************************/
void I2C_SendStart()
{
	//��ʼ�ź�				SDA��SCLʱ�����ɸ߱��
	//ʱ����SCL ����  SDA�ɸ�����
	I2C_SDA_H;
	i2c_Delay();
	I2C_SCL_H;
	i2c_Delay();
	I2C_SDA_L;
	i2c_Delay();
	I2C_SCL_L;
}
/*********************************************
 * @function��I2C_SendStop
 *
 * @param��None
 *
 * 		@arg��None
 * 
 * @note�����I2C���ͽ����ź�
 * 
 * @retval��None
 *********************************************/
void I2C_SendStop()
{
	//��ʼ�ź�				SDA��SCLʱ�����ɵͱ��
	//ʱ����SCL ����  SDA�ɵͱ��
	I2C_SDA_L;
	i2c_Delay();
	I2C_SCL_H;
	i2c_Delay();
	I2C_SDA_H;
	i2c_Delay();
	I2C_SCL_L;
	
}

/*********************************************
 * @function��I2C_GetAck
 *
 * @param��None
 *
 * 		@arg��None
 * 
 * @note�����I2C��λ��״̬
 * 
 * @retval��0��æµ   1������
 *********************************************/
u8 I2C_GetAck()
{
	u8 re;
	I2C_SDA_H;
	i2c_Delay();
	I2C_SCL_H;
	i2c_Delay();
	if(I2C_GET_SDA)
		re = 0;
	else
		re = 1;
	I2C_SCL_L;
	i2c_Delay();
	return re;
}

/*********************************************
 * @function��I2C_SendByte
 *
 * @param��data
 *
 * 		@arg������
 * 
 * @note��I2C����һ�ֽ�����
 * 
 * @retval��None
 *********************************************/
void I2C_SendByte(u8 data)
{
	u8 num;
	for(num=0; num<8; num++)
	{
		if(data & 0x80)
			I2C_SDA_H;
		else
			I2C_SDA_L;
		i2c_Delay();
		I2C_SCL_H;
		i2c_Delay();
		I2C_SCL_L;
		data <<= 1;
		i2c_Delay();
	}
	I2C_SDA_H;//�ͷ�SDA��
	I2C_SCL_L;
}

/*********************************************
 * @function��I2C_SendReg
 *
 * @param��DevAddr
 *
 * 		@arg����λ����ַ
 *
 * @param��RegAddr
 *
 * 		@arg���Ĵ�����ַ
 *
 * @param��data
 *
 * 		@arg��Ҫ���͵�����
 *
 * @note������λ��ָ���ļĴ�����������
 * 
 * @retval��None
 *********************************************/
void I2C_SendReg(u8 DevAddr,u8 RegAddr, u8 data)
{
	// ʱ�� �� ���Ϳ�ʼ�ź� -> ������λ����ַ -> �ȴ�æµ���� -> ���ͼĴ�����ַ -> ��������
	I2C_SendStart();
	I2C_SendByte(DevAddr);
	/*  �ȴ�æµ����  */
	while( I2C_GetAck() != 1 );
	I2C_SendByte(RegAddr);
	while( I2C_GetAck() != 1 );
	I2C_SendByte(data);
	while( I2C_GetAck() != 1 );
	I2C_SendStop();
}

#else

void I2C_Config(void)
{
	I2C_GPIO_Config();
	I2C_Mode_Config();
}

void I2C_SendReg(u8 DevAddr,u8 RegAddr, u8 data)
{
	I2C_GenerateSTART(I2Cx, ENABLE);
	while(I2C_CheckEvent(I2Cx, I2C_EVENT_MASTER_MODE_SELECT) == ERROR);
	
	I2C_Send7bitAddress(I2Cx, DevAddr, I2C_Direction_Transmitter);
	while(I2C_CheckEvent(I2Cx, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED)  == ERROR );
	
	I2C_SendData(I2Cx, RegAddr);
	while( I2C_CheckEvent( I2Cx, I2C_EVENT_MASTER_BYTE_TRANSMITTING) == ERROR);
	
	I2C_SendData(I2Cx, data);
	while( I2C_CheckEvent( I2Cx, I2C_EVENT_MASTER_BYTE_TRANSMITTING) == ERROR);
	
	I2C_GenerateSTOP(I2Cx, ENABLE);
}

#endif

