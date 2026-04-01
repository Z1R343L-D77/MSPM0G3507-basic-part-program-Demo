#include "mpu6050.h"

IMU_ID_READ IMU_ID=WHO_AM_I_MPU6050;
static uint8_t imu_address=ICM20689_ADRESS;

uint8_t imu_read[5];

vector3f gyro;
vector3f accel;
float temperature;


void mpu6050_mainloop(void)
{
	if(!f_50ms_mpu6050)return;
	f_50ms_mpu6050=0;
	
	MPU6050_Read_Data(&gyro,&accel,&temperature);
}


u8 mpu6050_init(void)//MSP6050初始化
{
	uint8_t fault=0;
	single_writei2c(imu_address,PWR_MGMT_1, 0x81);//软件强制复位81
	delay_ms(100);
	if(IMU_ID==0xFF)
	{
		imu_address=ICM20689_ADRESS+1;
		single_writei2c(imu_address,PWR_MGMT_1, 0x81);//软件强制复位81
		delay_ms(100);	
		IMU_ID=(IMU_ID_READ)(single_readi2c(imu_address,WHO_AM_I));
	}
	switch(IMU_ID)
	{
		case WHO_AM_I_MPU6050:
		{
			single_writei2c(imu_address,PWR_MGMT_1  , 0x80);//软件复位
			delay_ms(200);
			single_writei2c(imu_address,SMPLRT_DIV  , 0x00); // sample rate.  Fsample= 1Khz/(<this value>+1) = 1000Hz
			single_writei2c(imu_address,PWR_MGMT_1  , 0x03); //时钟源 PLL with Z Gyro reference
			single_writei2c(imu_address,MPU_CONFIG  , 0x02); //内部低通滤波频率，加速度计184hz，陀螺仪188hz  //默认0x03	  
			single_writei2c(imu_address,GYRO_CONFIG , 0x08); //500deg/s
			single_writei2c(imu_address,ACCEL_CONFIG, 0x08); // Accel scale 4g (8192 LSB/g)			
		}
		break;
		default:
		{
			fault=1;
		}			
	}
	imu_read[0]=single_readi2c(imu_address,0x19);
	imu_read[1]=single_readi2c(imu_address,0x1A);
	imu_read[2]=single_readi2c(imu_address,0x1B);
	imu_read[3]=single_readi2c(imu_address,0x1C);
	imu_read[4]=single_readi2c(imu_address,0x1D);
	
//	imu_calibration_params_init();	
	return fault;
}


void MPU6050_Read_Data(vector3f *gyro,vector3f *accel,float *temperature)
{
	uint8_t buf[14];
	int16_t temp;
	i2creadnbyte(imu_address,ACCEL_XOUT_H,buf,14);
	switch(IMU_ID)
	{
		case WHO_AM_I_MPU6050:
		{
			accel->x=-(int16_t)((buf[0]<<8)|buf[1]);
			accel->y=-(int16_t)((buf[2]<<8)|buf[3]);
			accel->z= (int16_t)((buf[4]<<8)|buf[5]);	
			temp		=(int16_t)((buf[6]<<8)|buf[7]);
			gyro->x	=-(int16_t)((buf[8]<<8)|buf[9]);
			gyro->y	=-(int16_t)((buf[10]<<8)|buf[11]);
			gyro->z	= (int16_t)((buf[12]<<8)|buf[13]);	
			*temperature=36.53f+(float)(temp/340.0f);	
		}
		break;
		default:
		{
			accel->x=(int16_t)((buf[0]<<8)|buf[1]);
			accel->y=-(int16_t)((buf[2]<<8)|buf[3]);
			accel->z=-(int16_t)((buf[4]<<8)|buf[5]);	
			temp		=(int16_t)((buf[6]<<8)|buf[7]);
			gyro->x	=(int16_t)((buf[8]<<8)|buf[9]);
			gyro->y	=-(int16_t)((buf[10]<<8)|buf[11]);
			gyro->z	=-(int16_t)((buf[12]<<8)|buf[13]);	
			*temperature=36.53f+(float)(temp/340.0f);				
		}
	}
	gyro->x*=GYRO_CALIBRATION_COFF;
	gyro->y*=GYRO_CALIBRATION_COFF;
	gyro->z*=GYRO_CALIBRATION_COFF;
	
    accel->x/=GRAVITY_RAW;
    accel->y/=GRAVITY_RAW;
    accel->z/=GRAVITY_RAW;
}





