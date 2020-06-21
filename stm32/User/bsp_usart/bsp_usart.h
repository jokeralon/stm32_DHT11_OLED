#ifndef __BSP_USART_H
#define __BSP_USART_H

/* 引入printf函数 */
#include "stdio.h"
#include "stm32f10x.h"
typedef uint8_t u8;


#define __USART1  1
#define __USART2 	2
#define __USART3  3
/* 定义使用的串口 */
#define __USART			__USART1

#if	__USART == 1 //串口1

	//GPIO 引脚宏定义
	#define USART_TX_PIN		GPIO_Pin_9
	#define USART_PORT			GPIOA
	#define USART_RX_PIN		GPIO_Pin_10
	
	//USART 串口宏定义
	#define USARTx			USART1

	#define RCC_USARTDEVCmdFun		RCC_APB2PeriphClockCmd
	#define RCC_USARTEDVDef				RCC_APB2Periph_USART1
	#define RCC_USARTGPIOCmdFun		RCC_APB2PeriphClockCmd
	#define RCC_USARTGPIODef			RCC_APB2Periph_GPIOA
	
#elif __USART == 2 //串口2
	#define USARTx			USART2

	#define RCC_USARTCmdFun		RCC_APB1PeriphClockCmd
	#define RCC_USARTDef			RCC_APB1Periph_USART2
	
#endif

void USART_Config(int BAUDRATE);//串口初始化函数
void USART_SendByte(char data);//发送字节
void USART_SendStr(char *data);//发送字符串

char USART_GetByte(void);//接收数据
#endif  /* __BSP_USART_H */
