#include "my_i2c.h"



//************I2C 写寄存器函数******************
/**
 * 向指定I2C设备的寄存器写入数据。
 * @param DevAddr I2C设备地址。
 * @param reg_addr 要写入的寄存器地址。
 * @param reg_data 指向要写入数据的指针。
 * @param count 要写入的数据字节数。
 */
void I2C_WriteReg(uint8_t DevAddr,uint8_t reg_addr, uint8_t *reg_data, uint8_t count)
{
    unsigned char I2Ctxbuff[8] = {0x00};
    I2Ctxbuff[0] = reg_addr;
    unsigned char i, j = 1;
    for (i = 0; i < count; i++) 
	{
        I2Ctxbuff[j] = reg_data[i];
        j++;
    }
    DL_I2C_fillControllerTXFIFO(I2C_0_INST, &I2Ctxbuff[0], count + 1);
    /* 等待I2C空闲 */
    while (!(DL_I2C_getControllerStatus(I2C_0_INST) & DL_I2C_CONTROLLER_STATUS_IDLE));
    DL_I2C_startControllerTransfer(I2C_0_INST, DevAddr,DL_I2C_CONTROLLER_DIRECTION_TX, count + 1);
    while (DL_I2C_getControllerStatus(I2C_0_INST) & DL_I2C_CONTROLLER_STATUS_BUSY_BUS);
    /* 等待I2C空闲 */
    while (!(DL_I2C_getControllerStatus(I2C_0_INST) & DL_I2C_CONTROLLER_STATUS_IDLE));
    DL_I2C_flushControllerTXFIFO(I2C_0_INST);
}

//************I2C 读寄存器函数******************
/**
 * 从指定I2C设备的寄存器读取数据。
 * @param DevAddr I2C设备地址。
 * @param reg_addr 要读取的寄存器地址。
 * @param reg_data 指向接收数据的指针。
 * @param count 要读取的数据字节数。
 */
void I2C_ReadReg(uint8_t DevAddr,uint8_t reg_addr, uint8_t *reg_data, uint8_t count)
{
    DL_I2C_fillControllerTXFIFO(I2C_0_INST, &reg_addr, count);
    /* 等待I2C空闲 */
    while (!(DL_I2C_getControllerStatus(I2C_0_INST) & DL_I2C_CONTROLLER_STATUS_IDLE));
    DL_I2C_startControllerTransfer(I2C_0_INST, DevAddr, DL_I2C_CONTROLLER_DIRECTION_TX, 1);
    while (DL_I2C_getControllerStatus(I2C_0_INST) & DL_I2C_CONTROLLER_STATUS_BUSY_BUS);
    /* 等待I2C空闲 */
    while (!(DL_I2C_getControllerStatus(I2C_0_INST) &DL_I2C_CONTROLLER_STATUS_IDLE));
    DL_I2C_flushControllerTXFIFO(I2C_0_INST);
    /* 向目标发送读请求 */
    DL_I2C_startControllerTransfer(I2C_0_INST, DevAddr, DL_I2C_CONTROLLER_DIRECTION_RX, count);
    for (uint8_t i = 0; i < count; i++) 
	{
        while (DL_I2C_isControllerRXFIFOEmpty(I2C_0_INST));
        reg_data[i] = DL_I2C_receiveControllerData(I2C_0_INST);
    }
}

/**********************************************************************/
/**
 * 向指定I2C设备的单个寄存器写入单个字节的数据。
 * @param SlaveAddress I2C设备地址。
 * @param REG_Address 寄存器地址。
 * @param REG_data 要写入的数据。
 */
void single_writei2c(unsigned char SlaveAddress,unsigned char REG_Address,unsigned char REG_data)
{
    I2C_WriteReg(SlaveAddress,REG_Address,&REG_data,1);
}

/**
 * 从指定I2C设备的单个寄存器读取单个字节的数据。
 * @param SlaveAddress I2C设备地址。
 * @param REG_Address 寄存器地址。
 * @return 读取到的数据。
 */
unsigned char single_readi2c(unsigned char SlaveAddress,unsigned char REG_Address)
{
    uint8 data=0;
    I2C_ReadReg(SlaveAddress,REG_Address,&data,1);
    return data;
}

/**
 * 从指定I2C设备的寄存器读取多个字节的数据。
 * @param addr I2C设备地址。
 * @param regAddr 要读取的寄存器地址。
 * @param data 指向接收数据的指针。
 * @param length 要读取的数据字节数。
 */
void i2creadnbyte(uint8_t addr, uint8_t regAddr, uint8_t *data, uint8_t length)
{
    I2C_ReadReg(addr, regAddr,data,length);
}



















//************I2C 写寄存器函数******************
/**
 * 向指定I2C设备的寄存器写入数据。
 * @param DevAddr I2C设备地址。
 * @param reg_addr 要写入的寄存器地址。
 * @param reg_data 指向要写入数据的指针。
 * @param count 要写入的数据字节数。
 */
u8 I2C2_WriteReg(uint8_t DevAddr,uint8_t reg_addr,uint8_t count,uint8_t *reg_data)
{
    unsigned char I2Ctxbuff[8] = {0x00};
    I2Ctxbuff[0] = reg_addr;
    unsigned char i, j = 1;
    for (i = 0; i < count; i++) 
	{
        I2Ctxbuff[j] = reg_data[i];
        j++;
    }
    DL_I2C_fillControllerTXFIFO(I2C_0_INST, &I2Ctxbuff[0], count + 1);
    /* 等待I2C空闲 */
    while (!(DL_I2C_getControllerStatus(I2C_0_INST) & DL_I2C_CONTROLLER_STATUS_IDLE));
    DL_I2C_startControllerTransfer(I2C_0_INST, DevAddr,DL_I2C_CONTROLLER_DIRECTION_TX, count + 1);
    while (DL_I2C_getControllerStatus(I2C_0_INST) & DL_I2C_CONTROLLER_STATUS_BUSY_BUS);
    /* 等待I2C空闲 */
    while (!(DL_I2C_getControllerStatus(I2C_0_INST) & DL_I2C_CONTROLLER_STATUS_IDLE));
    DL_I2C_flushControllerTXFIFO(I2C_0_INST);
	    return 0;
}

//************I2C 读寄存器函数******************
/**
 * 从指定I2C设备的寄存器读取数据。
 * @param DevAddr I2C设备地址。
 * @param reg_addr 要读取的寄存器地址。
 * @param reg_data 指向接收数据的指针。
 * @param count 要读取的数据字节数。
 */
u8 I2C2_ReadReg(uint8_t DevAddr,uint8_t reg_addr, uint8_t count, uint8_t *reg_data)
{
    DL_I2C_fillControllerTXFIFO(I2C_0_INST, &reg_addr, count);
    /* 等待I2C空闲 */
    while (!(DL_I2C_getControllerStatus(I2C_0_INST) & DL_I2C_CONTROLLER_STATUS_IDLE));
    DL_I2C_startControllerTransfer(I2C_0_INST, DevAddr, DL_I2C_CONTROLLER_DIRECTION_TX, 1);
    while (DL_I2C_getControllerStatus(I2C_0_INST) & DL_I2C_CONTROLLER_STATUS_BUSY_BUS);
    /* 等待I2C空闲 */
    while (!(DL_I2C_getControllerStatus(I2C_0_INST) &DL_I2C_CONTROLLER_STATUS_IDLE));
    DL_I2C_flushControllerTXFIFO(I2C_0_INST);
    /* 向目标发送读请求 */
    DL_I2C_startControllerTransfer(I2C_0_INST, DevAddr, DL_I2C_CONTROLLER_DIRECTION_RX, count);
    for (uint8_t i = 0; i < count; i++) 
	{
        while (DL_I2C_isControllerRXFIFOEmpty(I2C_0_INST));
        reg_data[i] = DL_I2C_receiveControllerData(I2C_0_INST);
    }
	return 0;
}

/**********************************************************************/
/**
 * 向指定I2C设备的单个寄存器写入单个字节的数据。
 * @param SlaveAddress I2C设备地址。
 * @param REG_Address 寄存器地址。
 * @param REG_data 要写入的数据。
 */
void single2_writei2c(unsigned char SlaveAddress,unsigned char REG_Address,unsigned char REG_data)
{
    I2C_WriteReg(SlaveAddress,REG_Address,&REG_data,1);
}

/**
 * 从指定I2C设备的单个寄存器读取单个字节的数据。
 * @param SlaveAddress I2C设备地址。
 * @param REG_Address 寄存器地址。
 * @return 读取到的数据。
 */
unsigned char single2_readi2c(unsigned char SlaveAddress,unsigned char REG_Address)
{
    uint8 data=0;
    I2C_ReadReg(SlaveAddress,REG_Address,&data,1);
    return data;
}

/**
 * 从指定I2C设备的寄存器读取多个字节的数据。
 * @param addr I2C设备地址。
 * @param regAddr 要读取的寄存器地址。
 * @param data 指向接收数据的指针。
 * @param length 要读取的数据字节数。
 */
void i2c2readnbyte(uint8_t addr, uint8_t regAddr, uint8_t *data, uint8_t length)
{
    I2C_ReadReg(addr, regAddr,data,length);
}












