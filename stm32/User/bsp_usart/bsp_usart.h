#ifndef __BSP_USART_H
#define __BSP_USART_H

/* ����printf���� */
#include "stdio.h"
#include "stm32f10x.h"
typedef uint8_t u8;


#define __USART1  1
#define __USART2 	2
#define __USART3  3
/* ����ʹ�õĴ��� */
#define __USART			__USART1

#if	__USART == 1 //����1

	//GPIO ���ź궨��
	#define USART_TX_PIN		GPIO_Pin_9
	#define USART_PORT			GPIOA
	#define USART_RX_PIN		GPIO_Pin_10
	
	//USART ���ں궨��
	#define USARTx			USART1

	#define RCC_USARTDEVCmdFun		RCC_APB2PeriphClockCmd
	#define RCC_USARTEDVDef				RCC_APB2Periph_USART1
	#define RCC_USARTGPIOCmdFun		RCC_APB2PeriphClockCmd
	#define RCC_USARTGPIODef			RCC_APB2Periph_GPIOA
	
#elif __USART == 2 //����2
	#define USARTx			USART2

	#define RCC_USARTCmdFun		RCC_APB1PeriphClockCmd
	#define RCC_USARTDef			RCC_APB1Periph_USART2
	
#endif

void USART_Config(int BAUDRATE);//���ڳ�ʼ������
void USART_SendByte(char data);//�����ֽ�
void USART_SendStr(char *data);//�����ַ���

char USART_GetByte(void);//��������
#endif  /* __BSP_USART_H */
