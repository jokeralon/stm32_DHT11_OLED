#include "bsp_usart.h"

/*********************************************
 * @function��USART_GPIO_Config
 *
 * @param��None
 *
 * 		@arg��None
 * 
 * @note���������ų�ʼ��
 * 
 * @retval��None
 *********************************************/

void USART_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	/* ��ʱ�� */
	RCC_USARTGPIOCmdFun(RCC_USARTGPIODef, ENABLE);
	/* ������� */
	GPIO_DeInit(USART_PORT);
	/* ѡ������ */
	GPIO_InitStruct.GPIO_Pin = USART_RX_PIN;
	/* ����ģʽ  �������� */
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(USART_PORT, &GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Pin = USART_TX_PIN;
	/* ���ÿ�©��� */
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(USART_PORT, &GPIO_InitStruct);
}


/*********************************************
 * @function��USART_Mode_Config
 *
 * @param��None
 *
 * 		@arg��None
 * 
 * @note�����ڳ�ʼ��
 * 
 * @retval��None
 *********************************************/
void USART_Mode_Config(int BAUDRATE)
{
	USART_InitTypeDef		USART_InitStruct;
	/* ��ʱ�� */
	RCC_USARTDEVCmdFun(RCC_USARTEDVDef, ENABLE);
	
	/* ����������� */
	USART_DeInit(USARTx);
	/* ������ */
	USART_InitStruct.USART_BaudRate = BAUDRATE;
	/* Ӳ������ */
	USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	/* ģʽ */
	USART_InitStruct.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	/* У�� */
	USART_InitStruct.USART_Parity = USART_Parity_No;
	/* ֹͣλ */
	USART_InitStruct.USART_StopBits = USART_StopBits_1;
	/* �ֽڳ��� */
	USART_InitStruct.USART_WordLength = USART_WordLength_8b;
	/* ��ʼ������ */
	USART_Init(USARTx, &USART_InitStruct);
	/* �򿪴��� */
	USART_Cmd(USARTx, ENABLE);
}

void USART_Config(int BAUDRATE)
{
	
	USART_GPIO_Config();
	USART_Mode_Config(BAUDRATE);
}

/*********************************************
 * @function��USART_SendByte
 *
 * @param��data
 *
 * 		@arg�����͵�����
 * 
 * @note�����ڷ���һ�ֽ�����
 * 
 * @retval��None
 *********************************************/
void USART_SendByte(char data)
{
	/* ����8λ���� */
	USART_SendData(USARTx, data);
	/* �ȴ�������� */
	while(USART_GetFlagStatus(USARTx, USART_FLAG_TXE) != SET);
}

/*********************************************
 * @function��USART_SendStr
 *
 * @param��*data
 *
 * 		@arg�����͵��ַ���
 * 
 * @note�����ڷ����ַ���
 * 
 * @retval��None
 *********************************************/
void USART_SendStr(char *data)
{
	do{
		USART_SendByte(*data);
		data++;
	}while(*data != '\0');
}

/*********************************************
 * @function��USART_GetByte
 *
 * @param��None
 *
 * 		@arg��None
 * 
 * @note�����ڽ�������
 * 
 * @retval�������յ������ݣ����û���򷵻ؿ�
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

/* printf�ض��� */
int fputc(int ch, FILE *f)
{
	USART_SendByte((u8)ch);
	return ch;
}

/* getchar�ض��� */
int getc(FILE *f )
{
	return (int)USART_ReceiveData(USARTx);
}
