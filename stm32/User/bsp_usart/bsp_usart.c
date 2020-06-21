#include "bsp_usart.h"

/*********************************************
 * @function：USART_GPIO_Config
 *
 * @param：None
 *
 * 		@arg：None
 * 
 * @note：串口引脚初始化
 * 
 * @retval：None
 *********************************************/

void USART_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	/* 开时钟 */
	RCC_USARTGPIOCmdFun(RCC_USARTGPIODef, ENABLE);
	/* 清除配置 */
	GPIO_DeInit(USART_PORT);
	/* 选择引脚 */
	GPIO_InitStruct.GPIO_Pin = USART_RX_PIN;
	/* 设置模式  浮空输入 */
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(USART_PORT, &GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Pin = USART_TX_PIN;
	/* 复用开漏输出 */
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(USART_PORT, &GPIO_InitStruct);
}


/*********************************************
 * @function：USART_Mode_Config
 *
 * @param：None
 *
 * 		@arg：None
 * 
 * @note：串口初始化
 * 
 * @retval：None
 *********************************************/
void USART_Mode_Config(int BAUDRATE)
{
	USART_InitTypeDef		USART_InitStruct;
	/* 开时钟 */
	RCC_USARTDEVCmdFun(RCC_USARTEDVDef, ENABLE);
	
	/* 清除串口配置 */
	USART_DeInit(USARTx);
	/* 波特率 */
	USART_InitStruct.USART_BaudRate = BAUDRATE;
	/* 硬件控制 */
	USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	/* 模式 */
	USART_InitStruct.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	/* 校验 */
	USART_InitStruct.USART_Parity = USART_Parity_No;
	/* 停止位 */
	USART_InitStruct.USART_StopBits = USART_StopBits_1;
	/* 字节长度 */
	USART_InitStruct.USART_WordLength = USART_WordLength_8b;
	/* 初始化串口 */
	USART_Init(USARTx, &USART_InitStruct);
	/* 打开串口 */
	USART_Cmd(USARTx, ENABLE);
}

void USART_Config(int BAUDRATE)
{
	
	USART_GPIO_Config();
	USART_Mode_Config(BAUDRATE);
}

/*********************************************
 * @function：USART_SendByte
 *
 * @param：data
 *
 * 		@arg：发送的数据
 * 
 * @note：串口发送一字节数据
 * 
 * @retval：None
 *********************************************/
void USART_SendByte(char data)
{
	/* 发送8位数据 */
	USART_SendData(USARTx, data);
	/* 等待发送完成 */
	while(USART_GetFlagStatus(USARTx, USART_FLAG_TXE) != SET);
}

/*********************************************
 * @function：USART_SendStr
 *
 * @param：*data
 *
 * 		@arg：发送的字符串
 * 
 * @note：串口发送字符串
 * 
 * @retval：None
 *********************************************/
void USART_SendStr(char *data)
{
	do{
		USART_SendByte(*data);
		data++;
	}while(*data != '\0');
}

/*********************************************
 * @function：USART_GetByte
 *
 * @param：None
 *
 * 		@arg：None
 * 
 * @note：串口接收数据
 * 
 * @retval：返回收到的数据，如果没有则返回空
 *********************************************/
char USART_GetByte(void)
{
	if(USART_GetFlagStatus(USARTx, USART_FLAG_RXNE) == SET)
	{
		char data;
		data = USART_ReceiveData(USARTx);
		USART_ClearFlag(USARTx, USART_FLAG_RXNE);
		return data;
	}
	return '\0';
}

/* printf重定向 */
int fputc(int ch, FILE *f)
{
	USART_SendByte((u8)ch);
	return ch;
}

/* getchar重定向 */
int getc(FILE *f )
{
	return (int)USART_ReceiveData(USARTx);
}
