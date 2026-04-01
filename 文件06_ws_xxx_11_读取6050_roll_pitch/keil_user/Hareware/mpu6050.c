#include "mpu6050.h"

IMU_ID_READ IMU_ID=WHO_AM_I_MPU6050;
static uint8_t imu_address=ICM20689_ADRESS;
uint8_t imu_read[5];

sensor  mpu;
lpf_param accel_lpf_param,gyro_lpf_param;
lpf_buf gyro_filter_buf[3],accel_filter_buf[3];

void mpu6050_mainloop(void)
{
	if(!f_50ms_mpu6050)return;
	f_50ms_mpu6050=0;
	
	//MPU6050_Read_Data(&gyro,&accel,&temperature);
	imu_data_sampling();
//	mpu_dmp_get_data();
}


uint8_t mpu6050_init(void)//MPU6050初始化
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
	//待温度稳定后，自动校准陀螺仪零偏
	mpu.accel_scale.x=1.0f;
	mpu.accel_scale.y=1.0f;
	mpu.accel_scale.z=1.0f;
	
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

/***************************************************
函数名: void imu_data_sampling(void)
说明:	IMU数据采样/校准/滤波
****************************************************/
void imu_data_sampling(void)
{
	if(mpu.lpf_init==0)
	{
		set_cutoff_frequency(200, 50,&gyro_lpf_param); //姿态角速度反馈滤波参数 
		set_cutoff_frequency(200, 30,&accel_lpf_param);//姿态解算加计修正滤波值
		mpu.lpf_init=1;
	}
	mpu.last_temperature_raw=mpu.temperature_raw;
	//陀螺仪/陀螺仪数据采集
	MPU6050_Read_Data(&mpu._gyro_dps_raw,&mpu._accel_g_raw,&mpu.temperature_raw);
	//陀螺仪数据低通滤波
	mpu.gyro_dps_raw.x=LPButterworth(mpu._gyro_dps_raw.x,&gyro_filter_buf[0],&gyro_lpf_param);
	mpu.gyro_dps_raw.y=LPButterworth(mpu._gyro_dps_raw.y,&gyro_filter_buf[1],&gyro_lpf_param);
	mpu.gyro_dps_raw.z=LPButterworth(mpu._gyro_dps_raw.z,&gyro_filter_buf[2],&gyro_lpf_param);		
	//加速度数据低通滤波
	mpu.accel_g_raw.x=LPButterworth(mpu._accel_g_raw.x,&accel_filter_buf[0],&accel_lpf_param);
	mpu.accel_g_raw.y=LPButterworth(mpu._accel_g_raw.y,&accel_filter_buf[1],&accel_lpf_param);
	mpu.accel_g_raw.z=LPButterworth(mpu._accel_g_raw.z,&accel_filter_buf[2],&accel_lpf_param);	
	//温度传感器数据一阶低通滤波
	mpu.temperature_filter=0.75f*mpu.temperature_raw+0.25f*mpu.temperature_filter;
	//得到校准后的角速度、加速度、磁力计数据
	vector3f_sub(mpu.gyro_dps_raw,mpu.gyro_offset,&mpu.gyro_dps);

	mpu.accel_g.x=mpu.accel_scale.x*mpu.accel_g_raw.x-mpu.accel_offset.x;
	mpu.accel_g.y=mpu.accel_scale.y*mpu.accel_g_raw.y-mpu.accel_offset.y;
	mpu.accel_g.z=mpu.accel_scale.z*mpu.accel_g_raw.z-mpu.accel_offset.z;  	

	//通过三轴加速度计,计算水平观测角度
	float ax,ay,az;
	ax=mpu.accel_g.x;
	ay=mpu.accel_g.y;
	az=mpu.accel_g.z;

	mpu.rpy_obs_deg[0]=-57.3f*atan(ax*invSqrt(ay*ay+az*az)); //横滚角roll
	mpu.rpy_obs_deg[1]= 57.3f*atan(ay*invSqrt(ax*ax+az*az)); //俯仰角pitch
//	mpu.rpy_obs_deg[2]= 57.3f*atan(az*invSqrt(ax*ax+ay*ay)); //航向角yaw
//	//俯仰轴姿态角卡尔曼滤波
//	mpu.rpy_kalman_deg[1]=kalman_filter(mpu.rpy_obs_deg[1],mpu.gyro_dps.x);
}


/***************************************************
函数名: vector3f_sub(vector3f a,vector3f b,vector3f *c)
说明:	向量作差
入口:	vector3f a-被减数
			vector3f b-减数
			vector3f *c-差
****************************************************/
void vector3f_sub(vector3f a,vector3f b,vector3f *c)
{
	c->x=a.x-b.x;
	c->y=a.y-b.y;
	c->z=a.z-b.z;
}


