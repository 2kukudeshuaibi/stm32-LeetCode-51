#include "system.h"
#include "systick.h"
#include "LED.h"
#include "key.h"
#include "usart.h"
#include "tftlcd.h"
#include "spi_flash.h"
#include "mpu6050.h"
#include "inv_mpu.h"
#include "inv_mpu_dmp_motion_driver.h"

void usart1_send_char(u8 c)
{
	while(USART_GetFlagStatus(USART1,USART_FLAG_TC)==RESET);
    USART_SendData(USART1,c);   
} 

//传送数据给匿名四轴上位机软件(V2.6版本)
//fun:功能字. 0XA0~0XAF
//data:数据缓存区,最多28字节!!
//len:data区有效数据个数
void usart1_niming_report(u8 fun,u8*data,u8 len)
{
	u8 send_buf[32];
	u8 i;
	if(len>28)return;	//最多28字节数据 
	send_buf[len+3]=0;	//校验数置零
	send_buf[0]=0X88;	//帧头
	send_buf[1]=fun;	//功能字
	send_buf[2]=len;	//数据长度
	for(i=0;i<len;i++)send_buf[3+i]=data[i];			//复制数据
	for(i=0;i<len+3;i++)send_buf[len+3]+=send_buf[i];	//计算校验和	
	for(i=0;i<len+4;i++)usart1_send_char(send_buf[i]);	//发送数据到串口1 
}

//发送加速度传感器数据和陀螺仪数据
//aacx,aacy,aacz:x,y,z三个方向上面的加速度值
//gyrox,gyroy,gyroz:x,y,z三个方向上面的陀螺仪值
void mpu6050_send_data(short aacx,short aacy,short aacz,short gyrox,short gyroy,short gyroz)
{
	u8 tbuf[12]; 
	tbuf[0]=(aacx>>8)&0XFF;
	tbuf[1]=aacx&0XFF;
	tbuf[2]=(aacy>>8)&0XFF;
	tbuf[3]=aacy&0XFF;
	tbuf[4]=(aacz>>8)&0XFF;
	tbuf[5]=aacz&0XFF; 
	tbuf[6]=(gyrox>>8)&0XFF;
	tbuf[7]=gyrox&0XFF;
	tbuf[8]=(gyroy>>8)&0XFF;
	tbuf[9]=gyroy&0XFF;
	tbuf[10]=(gyroz>>8)&0XFF;
	tbuf[11]=gyroz&0XFF;
	usart1_niming_report(0XA1,tbuf,12);//自定义帧,0XA1
}	

//通过串口1上报结算后的姿态数据给电脑
//aacx,aacy,aacz:x,y,z三个方向上面的加速度值
//gyrox,gyroy,gyroz:x,y,z三个方向上面的陀螺仪值
//roll:横滚角.单位0.01度。 -18000 -> 18000 对应 -180.00  ->  180.00度
//pitch:俯仰角.单位 0.01度。-9000 - 9000 对应 -90.00 -> 90.00 度
//yaw:航向角.单位为0.1度 0 -> 3600  对应 0 -> 360.0度
void usart1_report_imu(short aacx,short aacy,short aacz,short gyrox,short gyroy,short gyroz,short roll,short pitch,short yaw)
{
	u8 tbuf[28]; 
	u8 i;
	for(i=0;i<28;i++)tbuf[i]=0;//清0
	tbuf[0]=(aacx>>8)&0XFF;
	tbuf[1]=aacx&0XFF;
	tbuf[2]=(aacy>>8)&0XFF;
	tbuf[3]=aacy&0XFF;
	tbuf[4]=(aacz>>8)&0XFF;
	tbuf[5]=aacz&0XFF; 
	tbuf[6]=(gyrox>>8)&0XFF;
	tbuf[7]=gyrox&0XFF;
	tbuf[8]=(gyroy>>8)&0XFF;
	tbuf[9]=gyroy&0XFF;
	tbuf[10]=(gyroz>>8)&0XFF;
	tbuf[11]=gyroz&0XFF;	
	tbuf[18]=(roll>>8)&0XFF;
	tbuf[19]=roll&0XFF;
	tbuf[20]=(pitch>>8)&0XFF;
	tbuf[21]=pitch&0XFF;
	tbuf[22]=(yaw>>8)&0XFF;
	tbuf[23]=yaw&0XFF;
	usart1_niming_report(0XAF,tbuf,28);//飞控显示帧,0XAF
}


int main()
{
	u8 i=0;
	u8 key=0;
	u8 report=1;
	float pitch=0,roll=0,yaw=0; 		//欧拉角
	short aacx=0,aacy=0,aacz=0;		//加速度传感器原始数据
	short gyrox=0,gyroy=0,gyroz=0;	//陀螺仪原始数据
	short temp=0;
	systick_Init(72);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	LED_Init();
	USART1_Init(256000);
	TFTLCD_Init();
	Key_Init();
	MPU6050_Init();
	TFTLCD_Show_String(110,10,(u8*)"MPU6050 TEST",16);
	while(mpu_dmp_init())
	{
		TFTLCD_Show_String(110,30,(u8*)"MPU6050 ERROR",16);
	}
	TFTLCD_Show_String(110,30,(u8*)"MPU6050 SUCCESS",16);
	
	while(1)
	{
		TFTLCD_Show_String(30,50,(u8*)"Temp  :",16);
	    TFTLCD_Show_String(30,70,(u8*)"Pitch :",16);
	    TFTLCD_Show_String(30,90,(u8*)"Roll  :",16);
	    TFTLCD_Show_String(30,110,(u8*)"Yaw   :",16);
		key=key_scan();
		if(key==1)
		{
			report=!report;
			if(report)
			{
				TFTLCD_Show_String(30,130,(u8*)"UPLOAD ON",16);
			}
			else
			{
				TFTLCD_Show_String(30,130,(u8*)"UPLOADOFF",16);
			}
		}
		
		if(mpu_dmp_get_data(&pitch,&roll,&yaw)==0)
		{
			temp=MPU6050_Get_Temperature();	//得到温度值
			MPU6050_Get_Accelerometer(&aacx,&aacy,&aacz);	//得到加速度传感器数据
			MPU6050_Get_Gyroscope(&gyrox,&gyroy,&gyroz);	//得到陀螺仪数据
			if(report)mpu6050_send_data(aacx,aacy,aacz,gyrox,gyroy,gyroz);//用自定义帧发送加速度和陀螺仪原始数据
			if(report)usart1_report_imu(aacx,aacy,aacz,gyrox,gyroy,gyroz,(int)(roll*100),(int)(pitch*100),(int)(yaw*10));
			if(i%10==0)
			{
				if(temp<0)
				{
					temp=(-temp);
					TFTLCD_Show_Char(87,50,'-',16,0);
				}
				else
				{
					TFTLCD_Show_Char(87,50,'+',16,0);
				}
				TFTLCD_Show_NUM(95,50,temp/100,2);
				TFTLCD_Show_Char(113,50,'.',16,0);
				TFTLCD_Show_NUM(122,50,temp/100,2);
				
				temp=pitch*10;
				if((temp/10)>3)
				{
					LED1=!LED1;
					TFT_FULL_COLOR(YELLOW);
				}
				if((temp>0)&&(temp<3))
				{
					TFT_FULL_COLOR(0xffff);
				}
				if((temp/10)<0)
				{
					LED2=!LED2;
					TFT_FULL_COLOR(RED);
				}
				if(temp<0)
				{
					temp=(-temp);
					TFTLCD_Show_Char(87,70,'-',16,0);
				}
				else
				{
					TFTLCD_Show_Char(87,70,'+',16,0);
				}
				TFTLCD_Show_NUM(95,70,temp/100,2);
				TFTLCD_Show_Char(113,70,'.',16,0);
				TFTLCD_Show_NUM(122,70,temp%10,1);
				
				temp=roll*10;
				if(temp<0)
				{
					temp=(-temp);
					TFTLCD_Show_Char(87,90,'-',16,0);
				}
				else
				{
					TFTLCD_Show_Char(87,90,'+',16,0);
				}
				TFTLCD_Show_NUM(95,90,temp/100,2);
				TFTLCD_Show_Char(113,90,'.',16,0);
				TFTLCD_Show_NUM(122,90,temp%10,1);
				
				temp=yaw*10;
				if(temp<0)
				{
					temp=(-temp);
					TFTLCD_Show_Char(87,110,'-',16,0);
				}
				else
				{
					TFTLCD_Show_Char(87,110,'+',16,0);
				}
				TFTLCD_Show_NUM(95,110,temp/100,2);
				TFTLCD_Show_Char(113,110,'.',16,0);
				TFTLCD_Show_NUM(122,110,temp%10,1);
				TFTLCD_Show_NUM(95,130,123,3);
				
			}
		}
		i++;
	}
	return 0;
}