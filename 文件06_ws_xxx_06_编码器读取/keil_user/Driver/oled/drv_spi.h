#ifndef drv_spi_h
#define drv_spi_h



#define OLED_RST_Clr() DL_GPIO_clearPins(GPIO_OLED_PORT, GPIO_OLED_RST_PIN)
#define OLED_RST_Set() DL_GPIO_setPins(GPIO_OLED_PORT, GPIO_OLED_RST_PIN)

#define OLED_DC_Clr() DL_GPIO_clearPins(GPIO_OLED_PORT, GPIO_OLED_DC_PIN)
#define OLED_DC_Set() DL_GPIO_setPins(GPIO_OLED_PORT, GPIO_OLED_DC_PIN)


#define OLED_CS_Clr()  DL_GPIO_clearPins(GPIO_OLED_PORT, GPIO_OLED_CS_PIN)
#define OLED_CS_Set()  DL_GPIO_setPins(GPIO_OLED_PORT, GPIO_OLED_CS_PIN)


void SPI_LCD_WrDat(unsigned char dat);
void SPI_LCD_WrCmd(unsigned char cmd);


#endif




