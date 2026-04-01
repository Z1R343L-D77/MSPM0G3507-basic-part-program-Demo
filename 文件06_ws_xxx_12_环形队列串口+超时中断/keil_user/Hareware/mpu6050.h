#ifndef _MPU6050_H
#define _MPU6050_H

#include "common_inc.h"

#define IMU_ICM20689_ID  0x98
//****************************************
// MPU6050

typedef enum
{
	WHO_AM_I_MPU6050  =0x68,
	WHO_AM_I_ICM20689 =0x98,
	WHO_AM_I_ICM20608D=0xAE,
	WHO_AM_I_ICM20608G=0xAF,
	WHO_AM_I_ICM20602=0x12,
}IMU_ID_READ;

enum 
{
	_ROL=0,
	_PIT,
	_YAW
};

enum 
{
	ROL=0,
	PIT,
	YAW
};

typedef struct
{
  float x;
  float y;
}vector2f;

typedef struct
{
  float x;
  float y;
  float z;
}vector3f;


typedef struct
{
	vector3f _gyro_dps_raw,gyro_dps_raw;//raw原始值
	vector3f _accel_g_raw,accel_g_raw;
	float temperature_raw,last_temperature_raw;

	float vbat;
	//校准后的数据
	vector3f gyro_dps;
	vector3f accel_g;
	float temperature_filter;
	
	float rpy_deg[3];//角度
	float rpy_obs_deg[3];//观测姿态角度
	
	vector3f gyro_offset;
	vector3f accel_scale,accel_offset;
	
	u8 lpf_init;
	
}sensor;
extern sensor  mpu;




#define GYRO_CALIBRATION_COFF 0.0152672f;
#define GRAVITY_RAW 8192.0f



#define	SMPLRT_DIV		0x19
#define	MPU_CONFIG		0x1A
#define	GYRO_CONFIG		0x1B
#define	ACCEL_CONFIG  0x1C
#define ACCEL_CONFIG2 0x1D
#define	ACCEL_XOUT_H	0x3B
#define	ACCEL_XOUT_L	0x3C
#define	ACCEL_YOUT_H	0x3D
#define	ACCEL_YOUT_L	0x3E
#define	ACCEL_ZOUT_H	0x3F
#define	ACCEL_ZOUT_L	0x40
#define	TEMP_OUT_H		0x41
#define	TEMP_OUT_L		0x42
#define	GYRO_XOUT_H		0x43
#define	GYRO_XOUT_L		0x44
#define	GYRO_YOUT_H		0x45
#define	GYRO_YOUT_L		0x46
#define	GYRO_ZOUT_H		0x47
#define	GYRO_ZOUT_L		0x48
#define	PWR_MGMT_1		0x6B
#define	WHO_AM_I		  0x75
#define USER_CTRL		  0x6A
#define INT_PIN_CFG		0x37

#define ICM20689_ADRESS		0x68

#define DEG2RAD (PI / 180.0f)
#define RAD2DEG (180.0f / PI)

uint8_t mpu6050_init(void);

void mpu6050_mainloop(void);

void MPU6050_Read_Data(vector3f *gyro,vector3f *accel,float *temperature);

void imu_data_sampling(void);

void vector3f_sub(vector3f a,vector3f b,vector3f *c);



#endif 
