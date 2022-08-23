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

//�������ݸ�����������λ�����(V2.6�汾)
//fun:������. 0XA0~0XAF
//data:���ݻ�����,���28�ֽ�!!
//len:data����Ч���ݸ���
void usart1_niming_report(u8 fun,u8*data,u8 len)
{
	u8 send_buf[32];
	u8 i;
	if(len>28)return;	//���28�ֽ����� 
	send_buf[len+3]=0;	//У��������
	send_buf[0]=0X88;	//֡ͷ
	send_buf[1]=fun;	//������
	send_buf[2]=len;	//���ݳ���
	for(i=0;i<len;i++)send_buf[3+i]=data[i];			//��������
	for(i=0;i<len+3;i++)send_buf[len+3]+=send_buf[i];	//����У���	
	for(i=0;i<len+4;i++)usart1_send_char(send_buf[i]);	//�������ݵ�����1 
}

//���ͼ��ٶȴ��������ݺ�����������
//aacx,aacy,aacz:x,y,z������������ļ��ٶ�ֵ
//gyrox,gyroy,gyroz:x,y,z�������������������ֵ
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
	usart1_niming_report(0XA1,tbuf,12);//�Զ���֡,0XA1
}	

//ͨ������1�ϱ���������̬���ݸ�����
//aacx,aacy,aacz:x,y,z������������ļ��ٶ�ֵ
//gyrox,gyroy,gyroz:x,y,z�������������������ֵ
//roll:�����.��λ0.01�ȡ� -18000 -> 18000 ��Ӧ -180.00  ->  180.00��
//pitch:������.��λ 0.01�ȡ�-9000 - 9000 ��Ӧ -90.00 -> 90.00 ��
//yaw:�����.��λΪ0.1�� 0 -> 3600  ��Ӧ 0 -> 360.0��
void usart1_report_imu(short aacx,short aacy,short aacz,short gyrox,short gyroy,short gyroz,short roll,short pitch,short yaw)
{
	u8 tbuf[28]; 
	u8 i;
	for(i=0;i<28;i++)tbuf[i]=0;//��0
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
	usart1_niming_report(0XAF,tbuf,28);//�ɿ���ʾ֡,0XAF
}


int main()
{
	u8 i=0;
	u8 key=0;
	u8 report=1;
	float pitch=0,roll=0,yaw=0; 		//ŷ����
	short aacx=0,aacy=0,aacz=0;		//���ٶȴ�����ԭʼ����
	short gyrox=0,gyroy=0,gyroz=0;	//������ԭʼ����
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
			temp=MPU6050_Get_Temperature();	//�õ��¶�ֵ
			MPU6050_Get_Accelerometer(&aacx,&aacy,&aacz);	//�õ����ٶȴ���������
			MPU6050_Get_Gyroscope(&gyrox,&gyroy,&gyroz);	//�õ�����������
			if(report)mpu6050_send_data(aacx,aacy,aacz,gyrox,gyroy,gyroz);//���Զ���֡���ͼ��ٶȺ�������ԭʼ����
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