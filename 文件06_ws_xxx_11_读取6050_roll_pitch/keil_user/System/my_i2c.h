#ifndef _MY_IIC_H
#define _MY_IIC_H

#include  "common_inc.h"


void single_writei2c(unsigned char SlaveAddress,unsigned char REG_Address,unsigned char REG_data);
unsigned char single_readi2c(unsigned char SlaveAddress,unsigned char REG_Address);
void i2creadnbyte(uint8_t addr, uint8_t regAddr, uint8_t *data, uint8_t length);

u8 I2C2_WriteReg(uint8_t DevAddr,uint8_t reg_addr,uint8_t count,uint8_t *reg_data);
u8 I2C2_ReadReg(uint8_t DevAddr,uint8_t reg_addr, uint8_t count, uint8_t *reg_data);

#endif 
