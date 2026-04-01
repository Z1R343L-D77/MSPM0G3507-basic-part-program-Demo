#ifndef __DRV_OLED_H
#define __DRV_OLED_H


#define XLevelL  	0x00
#define XLevelH  	0x10
#define XLevel    ((XLevelH&0x0F)*16+XLevelL)
#define Max_Column 	128
#define Max_Row  	64
#define Brightness 	0xCF
#define X_WIDTH 	128
#define Y_WIDTH 	64


void OLED_WrDat(unsigned char IIC_Data);
void OLED_WrCmd(unsigned char IIC_Command);
void OLED_Set_Pos(unsigned char x, unsigned char y) ;


void oled_init(void);

void write_6_8_number(unsigned char x,unsigned char y, float number);
void LCD_clear_L(unsigned char x,unsigned char y);
void LCD_P6x8Char(unsigned char x,unsigned char  y,unsigned char ucData);
void LCD_P6x8Str(unsigned char x,unsigned char  y,char ch[]);
void OLED_Fill(unsigned char bmp_dat);
void OLED_CLS(void);
void display_6_8_number(unsigned char x,unsigned char y, float number);
void display_6_8_string(unsigned char x,unsigned char  y,char ch[]);
void display_6_8_number_pro(unsigned char x,unsigned char y, float number);

void write_6_8_number_f1(unsigned char x,unsigned char y, float number);
void display_6_8_number_f1(unsigned char x,unsigned char y, float number);


#endif
