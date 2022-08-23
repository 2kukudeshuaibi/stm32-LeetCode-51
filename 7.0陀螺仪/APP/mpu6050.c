#include "mpu6050.h"

u8 MPU6050_Init(void) 								//初始化MPU6050
{
	u8 res;
	IIC_Init();//初始化IIC总线
	MPU6050_Write_Byte(MPU6050_PWR_MGMT1_REG,0X80);	//复位MPU6050
    delay_ms(100);
	MPU6050_Write_Byte(MPU6050_PWR_MGMT1_REG,0X00);	//唤醒MPU6050
	MPU6050_Set_Gyro_Fsr(3);					//陀螺仪传感器,±2000dps
	MPU6050_Set_Accel_Fsr(0);					//加速度传感器,±2g
	MPU6050_Set_Rate(50);						//设置采样率50Hz
	MPU6050_Write_Byte(MPU6050_INT_EN_REG,0X00);	//关闭所有中断
	MPU6050_Write_Byte(MPU6050_USER_CTRL_REG,0X00);	//I2C主模式关闭
	MPU6050_Write_Byte(MPU6050_FIFO_EN_REG,0X00);	//关闭FIFO
	MPU6050_Write_Byte(MPU6050_INTBP_CFG_REG,0X80);	//INT引脚低电平有效
	res=MPU6050_Read_Byte(MPU6050_DEVICE_ID_REG);
	if(res==MPU6050_ADDR)//器件ID正确
	{
		MPU6050_Write_Byte(MPU6050_PWR_MGMT1_REG,0X01);	//设置CLKSEL,PLL X轴为参考
		MPU6050_Write_Byte(MPU6050_PWR_MGMT2_REG,0X00);	//加速度与陀螺仪都工作
		MPU6050_Set_Rate(50);						//设置采样率为50Hz
 	}else return 1;
	return 0;
}
u8 MPU6050_Write_Len(u8 addr,u8 reg,u8 len,u8 *buf)//IIC连续写
{
	u8 i = 0;
	IIC_Start();
	IIC_Send_Byte((MPU6050_ADDR<<1)|0);
	if(IIC_Wait_Ack())
	{
		IIC_Stop();
		return 1;
	}
	IIC_Send_Byte(reg);
	IIC_Wait_Ack();
	for(i=0;i<len;i++)
	{
		IIC_Send_Byte(buf[i]);
		if(IIC_Wait_Ack())
	    {
			IIC_Stop();
			return 1;
		}
	}
	IIC_Stop();
	return 0;
}
u8 MPU6050_Read_Len(u8 addr,u8 reg,u8 len,u8 *buf) //IIC连续读 
{
	IIC_Start(); 
	IIC_Send_Byte((addr<<1)|0);//发送器件地址+写命令	
	if(IIC_Wait_Ack())	//等待应答
	{
		IIC_Stop();		 
		return 1;		
	}
    IIC_Send_Byte(reg);	//写寄存器地址
    IIC_Wait_Ack();		//等待应答
    IIC_Start();
	IIC_Send_Byte((addr<<1)|1);//发送器件地址+读命令	
    IIC_Wait_Ack();		//等待应答 
	while(len)
	{
		if(len==1)*buf=IIC_Read_Byte(0);//读数据,发送nACK 
		else *buf=IIC_Read_Byte(1);		//读数据,发送ACK  
		len--;
		buf++; 
	}    
    IIC_Stop();	//产生一个停止条件 
	return 0;
}
u8 MPU6050_Write_Byte(u8 reg,u8 data)				//IIC写一个字节
{
	IIC_Start();
	IIC_Send_Byte((MPU6050_ADDR<<1)|0);
	if(IIC_Wait_Ack())
	{
		IIC_Stop();
		return 1;
	}
	IIC_Send_Byte(reg);
	IIC_Wait_Ack();
	IIC_Send_Byte(data);
	if(IIC_Wait_Ack())
	{
		IIC_Stop();
		return 1;
	}
	IIC_Stop();
	return 0;
}
u8 MPU6050_Read_Byte(u8 reg)						//IIC读一个字节
{
	u8 tmp=0;
	IIC_Start();
	IIC_Send_Byte((MPU6050_ADDR<<1)|0);
	IIC_Wait_Ack();
	IIC_Send_Byte(reg);
	IIC_Wait_Ack();
	IIC_Start();
	IIC_Send_Byte((MPU6050_ADDR<<1)|1);
	IIC_Wait_Ack();
	tmp=IIC_Read_Byte(0);
	IIC_Stop();
	return tmp;
}

u8 MPU6050_Set_Gyro_Fsr(u8 fsr)
{
	return MPU6050_Write_Byte(MPU6050_GYRO_CFG_REG,fsr<<3);
}
u8 MPU6050_Set_Accel_Fsr(u8 fsr)
{
	return MPU6050_Write_Byte(MPU6050_ACCEL_CFG_REG,fsr<<3);
}
u8 MPU6050_Set_LPF(u16 lpf)
{
	u8 data=0;
	if(lpf>=188)data=1;
	else if(lpf>=98)data=2;
	else if(lpf>=42)data=3;
	else if(lpf>=20)data=4;
	else if(lpf>=10)data=5;
	else data=6; 
	return MPU6050_Write_Byte(MPU6050_CFG_REG,data);//设置数字低通滤波器  
}
u8 MPU6050_Set_Rate(u16 rate)
{
	u8 data;
	if(rate>1000)rate=1000;
	if(rate<4)rate=4;
	data=1000/rate-1;
	data=MPU6050_Write_Byte(MPU6050_SAMPLE_RATE_REG,data);	//设置数字低通滤波器
 	return MPU6050_Set_LPF(rate/2);	//自动设置LPF为采样率的一半
}
u8 MPU6050_Set_Fifo(u8 sens)
{
	
}


short MPU6050_Get_Temperature(void)
{
	u8 buf[2]; 
    short raw;
	float temp;
	MPU6050_Read_Len(MPU6050_ADDR,MPU6050_TEMP_OUTH_REG,2,buf); 
    raw=((u16)buf[0]<<8)|buf[1];  
    temp=36.53+((double)raw)/340;  
    return temp*100;
}
u8 MPU6050_Get_Gyroscope(short *gx,short *gy,short *gz)
{
	u8 buf[6],res;  
	res=MPU6050_Read_Len(MPU6050_ADDR,MPU6050_GYRO_XOUTH_REG,6,buf);
	if(res==0)
	{
		*gx=((u16)buf[0]<<8)|buf[1];  
		*gy=((u16)buf[2]<<8)|buf[3];  
		*gz=((u16)buf[4]<<8)|buf[5];
	} 	
    return res;
}
u8 MPU6050_Get_Accelerometer(short *ax,short *ay,short *az)
{
	u8 buf[6],res;  
	res=MPU6050_Read_Len(MPU6050_ADDR,MPU6050_ACCEL_XOUTH_REG,6,buf);
	if(res==0)
	{
		*ax=((u16)buf[0]<<8)|buf[1];  
		*ay=((u16)buf[2]<<8)|buf[3];  
		*az=((u16)buf[4]<<8)|buf[5];
	} 	
    return res;
}