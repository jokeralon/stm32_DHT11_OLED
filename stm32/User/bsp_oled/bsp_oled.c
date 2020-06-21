#include "bsp_oled.h"

/*********************************************
 * @function��_delay_ms
 *
 * @param��time
 *
 * 		@arg����ʱ��ʱ�� ms
 * 
 * @note����ʱ���� ����
 * 
 * @retval��None
 *********************************************/
void _delay_ms(u16 time)
{    
   u16 i=0;  
   while(time--)
   {
      i=12000;  //�Լ�����
      while(i--) ;    
   }
}

/*********************************************
 * @function��SSD1306_WriteCmd
 *
 * @param��cmd
 *
 * 		@arg������
 * 
 * @note����SSD1306���Ϳ�������
 * 
 * @retval��None
 *********************************************/
void SSD1306_WriteCmd(u8 cmd)
{
	/*  SSD1306_ADDR | 0x00   : ��������  */
	/*  				0x00					������ģʽ  */
	/*  				 cmd					������      */
	I2C_SendReg( SSD1306_ADDR | 0x00, 0x00, cmd);
}
/*********************************************
 * @function��SSD1306_WriteData
 *
 * @param��data
 *
 * 		@arg������
 * 
 * @note����SSD1306��������
 * 
 * @retval��None
 *********************************************/
void SSD1306_WriteData(u8 data)
{	
	/*  SSD1306_ADDR | 0x00   : ��������  */
	/*  				0x00					������ģʽ  */
	/*  				 cmd					������      */
	I2C_SendReg( SSD1306_ADDR | 0x00, 0x40, data);
}

/*********************************************
 * @function��OLED_Init
 *
 * @param��None
 *
 * 		@arg��None
 * 
 * @note��OLED��ʼ�����ٷ��ֲ�
 * 
 * @retval��None
 *********************************************/

void OLED_Init()
{
	 SysTick_Delay_ms(1000);
	//SSD1306��λ֮��Ĭ�ϵ���ҳѰַ��ʽ
  
  SSD1306_WriteCmd(0xAE);//--display off
  
  SSD1306_WriteCmd(0x00);//--set low column address
  SSD1306_WriteCmd(0x10);//--set high column address
  SSD1306_WriteCmd(0x40);//--set start line address  
  
  SSD1306_WriteCmd(0xB0);//--set page address
  
  SSD1306_WriteCmd(0x81);// contract control
  SSD1306_WriteCmd(0xFF);//--128   
  SSD1306_WriteCmd(0xA1);//set segment re-map  0 to 127 
  SSD1306_WriteCmd(0xA6);//set normal  display  
  SSD1306_WriteCmd(0xA8);//set multiplex ratio(1 to 64)
  SSD1306_WriteCmd(0x3F);//--1/32 duty
  
  SSD1306_WriteCmd(0xC8);//Com scan direction
  SSD1306_WriteCmd(0xD3);//set display offset
  SSD1306_WriteCmd(0x00);//no offset
	
  SSD1306_WriteCmd(0xD5);//set display clock divide ratio/oscillator frequency  
  SSD1306_WriteCmd(0x80);//
	
  SSD1306_WriteCmd(0xD8);//set area color mode off
  SSD1306_WriteCmd(0x05);//
	
  SSD1306_WriteCmd(0xD9);//Set Pre-Charge Period
  SSD1306_WriteCmd(0xF1);//
	
  SSD1306_WriteCmd(0xDA);//set com pin  hardware configuartion
  SSD1306_WriteCmd(0x12);//
	
  SSD1306_WriteCmd(0xDB);//set Vcomh
  SSD1306_WriteCmd(0x30);//0x20,0.77xVcc
	
  SSD1306_WriteCmd(0x8D);//set charge pump enable
  SSD1306_WriteCmd(0x14);//
	
  SSD1306_WriteCmd(0xAF);//--turn on oled panel
}

/*********************************************
 * @function��OLED_SetPos
 *
 * @param��x
 *
 * 		@arg��x��
 * 
* @param��y
 *
 * 		@arg��y��
 * 
 * @note�����ù��λ��
 * 
 * @retval������ֵ˵����
 *********************************************/
void OLED_SetPos(uint8_t x, uint8_t y) 
{ 
  //����3���Ĵ���ֻ��ҳѰַ��ģʽ����Ч	
  SSD1306_WriteCmd(0xb0+y);             //ҳ��ַ����     0xb0~0xb7
  SSD1306_WriteCmd(((x&0xf0)>>4)|0x10); //�и�λ��ַ����
  SSD1306_WriteCmd((x&0x0f));           //�е�λ��ַ����
} 
 

/*********************************************
 * @function��OLED_DisplayOn
 *
 * @param��None
 *
 * 		@arg��None
 * 
 * @note������OLED��ʾ
 * 
 * @retval��None
 *********************************************/
void OLED_DisplayOn(void)
{
  SSD1306_WriteCmd(0X8D);  //SET DCDC����
  SSD1306_WriteCmd(0X14);  //DCDC ON
  SSD1306_WriteCmd(0XAF);  //DISPLAY ON
}
 
/*********************************************
 * @function��OLED_DisplayOff
 *
 * @param��None
 *
 * 		@arg��None
 * 
 * @note���ر�OLED��ʾ
 * 
 * @retval��None
 *********************************************/  
void OLED_DisplayOff(void)
{
  SSD1306_WriteCmd(0X8D);  //SET DCDC����
  SSD1306_WriteCmd(0X10);  //DCDC OFF
  SSD1306_WriteCmd(0XAE);  //DISPLAY OFF
}
/*********************************************
 * @function��OLED_Clear
 *
 * @param��None
 *
 * 		@arg��None
 * 
 * @note������
 * 
 * @retval��None
 *********************************************/  
void OLED_Clear(void)  
{  
  uint8_t i,n;	
  
  for(i=0;i<8;i++)  
  {  
    SSD1306_WriteCmd (0xb0+i);    //����ҳ��ַ��0~7��
    SSD1306_WriteCmd (0x00);      //������ʾλ�á��е͵�ַ
    SSD1306_WriteCmd (0x10);      //������ʾλ�á��иߵ�ַ   
    for(n=0;n<128;n++)
      SSD1306_WriteData(0); 
  } //������ʾ
}

/*********************************************
 * @function��OLED_ShowChar
 *
 * @param��uint8_t x
 *
 * 		@arg��x������ x:0~127
 * 
 * @param��uint8_t y
 *
 * 		@arg��y������ y:0~7
 * 
 * @param��uint8_t chr
 *
 * 		@arg����ʾ���ַ�
 * 
 * @param��uint8_t Char_Size
 *
 * 		@arg��Char_Size:ѡ������ 16/12 
 * 
 * @note��ָ��λ����ʾһ���ַ�
 * 
 * @retval��None
 *********************************************/
void OLED_ShowChar(uint8_t x,uint8_t y,uint8_t chr,uint8_t Char_Size)
{      	
  uint8_t c=0,i=0;	
  
  c=chr-' ';//�õ�ƫ�ƺ��ֵ			
  if(x>MAX_COLUMN-1)
  {
    x=0;
    y=y+2;
  }
  if(Char_Size ==16)
  {
    OLED_SetPos(x,y);	
    for(i=0;i<8;i++)
    {
      SSD1306_WriteData(F8X16[c*16+i]);//��д�ϰ벿��
    }
    
    OLED_SetPos(x,y+1);
    for(i=0;i<8;i++)
    {
      SSD1306_WriteData(F8X16[c*16+i+8]);//��д�°벿��
    }
  }
  else
  {	
    OLED_SetPos(x,y);
    for(i=0;i<6;i++)
    {
      SSD1306_WriteData(F6x8[c][i]);
    }
  }
}
 
/*********************************************
 * @function��OLED_ShowString
 *
 * @param��uint8_t x
 *
 * 		@arg��x������ x:0~127
 * 
 * @param��uint8_t y
 *
 * 		@arg��y������ y:0~7
 * 
 * @param��char *str
 *
 * 		@arg����ʾ���ַ���
 * 
 * @param��uint8_t Char_Size
 *
 * 		@arg��Char_Size:ѡ������ 16/12 
 * 
 * @note��ָ��λ����ʾ�ַ���
 * 
 * @retval��None
 *********************************************/
void OLED_ShowString(uint8_t x,uint8_t y,char *str,uint8_t Char_Size)
{
  unsigned char j=0;
  
  while (str[j]!='\0')
  {
    OLED_ShowChar(x,y,str[j],Char_Size);
    x+=8;
    if(x>120)
    {
      x=0;
      y+=2;
    }
    j++;//�ƶ�һ�ξ���һ��page��ȡֵ0-7
  }
}

/*********************************************
 * @function��OLED_ShowNum
 *
 * @param��uint8_t x
 *
 * 		@arg��x������ x:0~127
 * 
 * @param��uint8_t y
 *
 * 		@arg��y������ y:0~7
 * 
 * @param��uint8_t *num
 *
 * 		@arg����ʾ������
 * 
 * @param��uint8_t Char_Size
 *
 * 		@arg��Char_Size:ѡ������ 16/12 
 * 
 * @note��ָ��λ����ʾ����
 * 
 * @retval��None
 *********************************************/
void OLED_ShowNum(uint8_t x,uint8_t y,uint8_t *num,uint8_t Char_Size)
{
  unsigned char j=0;
	
	char ch[255];
	sprintf(ch , "%d", num);
  
  while (ch[j]!='\0')
  {
    OLED_ShowChar(x,y,ch[j],Char_Size);
    x+=8;
    if(x>120)
    {
      x=0;
      y+=2;
    }
    j++;//�ƶ�һ�ξ���һ��page��ȡֵ0-7
  }
}
 

/*********************************************
 * @function��OLED_ShowNum
 *
 * @param��uint8_t x
 *
 * 		@arg��x������ x:0~127
 * 
 * @param��uint8_t y
 *
 * 		@arg��y������ y:0~7
 * 
 * @param��uint8_t index
 *
 * 		@arg���ַ�������λ��
 * 
 * @note��ָ��λ����ʾ����
 * 
 * @retval��None
 *********************************************/
//��ʾ����
//���ں�����16*16��С�ģ����������ʾ4�к���
//index:�ں���ȡģ�е�����
void OLED_ShowCN(uint8_t x,uint8_t y,uint8_t index)
{      			    
  uint8_t t;
	
  OLED_SetPos(x,y);	
  for(t=0;t<16;t++)
  {
    SSD1306_WriteData(OLED[index][t]);
		//SSD1306_WriteData(SBQL[index][t]);
  }	
  
  OLED_SetPos(x,y+1);	
  for(t=0;t<16;t++)
  {	
    SSD1306_WriteData(OLED[index][t+16]);
		//SSD1306_WriteData(SBQL[index][t+16]);
  }					
}

