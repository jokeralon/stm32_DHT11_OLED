#ifndef	__BSP_OLED_H
#define __BSP_OLED_H
#include "stm32f10x.h"
#include "../bsp_systick/bsp_systick.h"
#include "../bsp_i2c/bsp_i2c.h"
#include "../bsp_usart/bsp_usart.h"
#include "stdbool.h"
#include "codetab.h"
/* Write Command */
#define SSD1306_Mode_CMD		0x00


/* Write Data */
#define SSD1306_Mode_DATA		0x40

#define         MAX_COLUMN	  128
#define         MAX_ROW		  64

#define SSD1306_ADDR	0x78
void OLED_Init(void);
void OLED_Clear(void);
void OLED_ShowCN(uint8_t x,uint8_t y,uint8_t index);
void OLED_ShowNum(uint8_t x,uint8_t y,uint8_t *num,uint8_t Char_Size);
void OLED_ShowString(uint8_t x,uint8_t y,char *str,uint8_t Char_Size);
void OLED_ShowChar(uint8_t x,uint8_t y,uint8_t chr,uint8_t Char_Size);
#endif	/* __BSP_OLED_H	*/
