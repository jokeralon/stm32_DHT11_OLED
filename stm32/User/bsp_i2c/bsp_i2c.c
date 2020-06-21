#include "bsp_i2c.h"



/*  I2C 工作模式  0: 软件模拟     1: 硬件I2C  */
#define I2C_MODE		1


/*********************************************
 * @function：I2C_GPIO_Config
 *
 * @param：None
 *
 * 		@arg：None
 * 
 * @note：初始化I2C GPIO引脚
 * 
 * @retval：None
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
 * @function：I2C_Mode_Config
 *
 * @param：None
 *
 * 		@arg：None
 * 
 * @note：初始化硬件I2C
 * 
 * @retval：None
 *********************************************/

void I2C_Mode_Config()
{
	I2C_InitTypeDef	I2C_InitStruct;
	/*  开始终  */
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C1, ENABLE);
	/*  自动应答  */
	I2C_InitStruct.I2C_Ack = I2C_Ack_Enable;
	/*  指定地址长度  */
	I2C_InitStruct.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;
	/*  速率  */
	I2C_InitStruct.I2C_ClockSpeed = 400000;
	/*  占空比  */
	I2C_InitStruct.I2C_DutyCycle = I2C_DutyCycle_16_9;
	/*  模式  */
	I2C_InitStruct.I2C_Mode = I2C_Mode_I2C;
	/*  指定自身I2C地址  */
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
 * @function：I2C_SendStart
 *
 * @param：None
 *
 * 		@arg：None
 * 
 * @note：软件I2C发送起始信号
 * 
 * @retval：None
 *********************************************/
void I2C_SendStart()
{
	//起始信号				SDA在SCL时序中由高变低
	//时序线SCL 拉高  SDA由高拉低
	I2C_SDA_H;
	i2c_Delay();
	I2C_SCL_H;
	i2c_Delay();
	I2C_SDA_L;
	i2c_Delay();
	I2C_SCL_L;
}
/*********************************************
 * @function：I2C_SendStop
 *
 * @param：None
 *
 * 		@arg：None
 * 
 * @note：软件I2C发送结束信号
 * 
 * @retval：None
 *********************************************/
void I2C_SendStop()
{
	//起始信号				SDA在SCL时序中由低变高
	//时序线SCL 拉高  SDA由低变高
	I2C_SDA_L;
	i2c_Delay();
	I2C_SCL_H;
	i2c_Delay();
	I2C_SDA_H;
	i2c_Delay();
	I2C_SCL_L;
	
}

/*********************************************
 * @function：I2C_GetAck
 *
 * @param：None
 *
 * 		@arg：None
 * 
 * @note：检测I2C下位机状态
 * 
 * @retval：0：忙碌   1：正常
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
 * @function：I2C_SendByte
 *
 * @param：data
 *
 * 		@arg：数据
 * 
 * @note：I2C发送一字节数据
 * 
 * @retval：None
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
	I2C_SDA_H;//释放SDA线
	I2C_SCL_L;
}

/*********************************************
 * @function：I2C_SendReg
 *
 * @param：DevAddr
 *
 * 		@arg：下位机地址
 *
 * @param：RegAddr
 *
 * 		@arg：寄存器地址
 *
 * @param：data
 *
 * 		@arg：要发送的数据
 *
 * @note：向下位机指定的寄存器发送数据
 * 
 * @retval：None
 *********************************************/
void I2C_SendReg(u8 DevAddr,u8 RegAddr, u8 data)
{
	// 时许 ： 发送开始信号 -> 发送下位机地址 -> 等待忙碌结束 -> 发送寄存器地址 -> 发送数据
	I2C_SendStart();
	I2C_SendByte(DevAddr);
	/*  等待忙碌结束  */
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

