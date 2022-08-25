#include "touch.h"
#include "stdio.h"
#include "math.h"
#include "stdlib.h"

u16 sta=0;
u16 arrx[10]={0};
u16 arry[10]={0};
float xfac=0.0;
float yfac=0.0;
short xoff=0;
short yoff=0;

void TP_Write_byte(u8 data)
{
	u8 i=0;
	for(i=0;i<8;i++)
	{
		if(data&(0x80))
		{
			TDIN=1;
		}
		else
		{
			TDIN=0;
		}
		data<<=1;
		TCLK=0;
		delay_us(1);
		TCLK=1;
	}
}

u16 TP_Read_AD(u8 cmd)
{
	u8 i=0;
	u16 tmp=0;
	TDIN=0;
	TCLK=0;
	TCS=0;
	TP_Write_byte(cmd);
	delay_us(6);
	TCLK=0;
	delay_us(1);
	TCLK=1;
	delay_us(1);
	TCLK=0;
	for(i=0;i<16;i++)
	{
		tmp<<=1;
		TCLK=0;
		delay_us(1);
		TCLK=1;
		if(DOUT)
		{
			tmp++;
		}
	}
	tmp>>=4;
	TCS=1;
	return tmp;
}

u16 TP_Read_XOY(u8 xy)
{
	u8 i = 0;
	u8 j = 0;
	u16 arr[40]={0};
	u32 sum=0;
	u16 tmp=0;
	for(i=0;i<40;i++)
	{
		arr[i]=TP_Read_AD(xy);
	}
	for(i=0;i<40-1;i++)
	{
		for(j=0;j<40-1-i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				tmp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=tmp;
			}
		}
	}
	for(i=1;i<40-1;i++)
	{
		sum+=arr[i];
	}
	tmp=sum/(40-2*1);
	return tmp;
}

u8 CMD_RDX=0XD0;
u8 CMD_RDY=0X90;

u8 TP_Read_XY(u16* x,u16* y)
{
	u16 xtmp=0;
	u16 ytmp=0;
	xtmp=TP_Read_XOY(CMD_RDX);
	ytmp=TP_Read_XOY(CMD_RDY);
	*x=xtmp;
	*y=ytmp;
	return 1;
}

u8 TP_Read_XY2(u16* x,u16* y)
{
	u16 x1=0,y1=0;
	u16 x2=0,y2=0;
	TP_Read_XY(&x1,&y1);
	TP_Read_XY(&x2,&y2);
	if(((x2<=x1&&x1<x2+50)||(x1<=x2&&x2<x1+50))&&((y2<=y1&&y1<y2+50)||(y1<=y2&&y2<y1+50)))
	{
		*x=(x1+x2)/2;
		*y=(y1+y2)/2;
		return 1;
	}
	else
	{
		return 0;
	}
}

void TP_Drow_Touch_Point(u16 x,u16 y,u16 color)
{
	TFTLCD_Draw_Line(x-12,y,x+13,y,color);
	TFTLCD_Draw_Line(x,y-12,x,y+13,color);
	TFTLCD_Dot(x+1,y+1,color);
	TFTLCD_Dot(x-1,y+1,color);
	TFTLCD_Dot(x+1,y-1,color);
	TFTLCD_Dot(x-1,y-1,color);
	LCD_Draw_Circle(x,y,6);
}

u8 TP_Scan(u8 tp)
{
	if(PEN==0)
	{
		if(tp)
		{
			TP_Read_XY2(&arrx[0],&arry[0]);
		}
		else if(TP_Read_XY2(&arrx[0],&arry[0]))
		{
			arrx[0]=arrx[0]*xfac+xoff;
			arry[0]=arry[0]*yfac+yoff;
		}
		if((sta&TP_PRES_DOWN)==0)
		{
			sta=TP_PRES_DOWN|TP_CATH_PRES;
			arrx[4]=arrx[0];
			arry[4]=arry[0];
		}
	}
	else
	{
		if(sta&TP_PRES_DOWN)
		{
			sta&=~(1<<7);
		}
		else
		{
			arrx[4]=0;
			arry[4]=0;
			arrx[0]=0xffff;
			arry[0]=0xffff;
		}
	}
	return sta&TP_PRES_DOWN;
}


void TP_ADjust()
{
	u16 pos_temp[4][2]={0};
	u8 cnt=0;
	u16 d1=0,d2=0;
	u32 tem1=0,tem2=0;
	double fac=0.0;
	u16 outtime=0;
	TP_Drow_Touch_Point(20,20,RED);
	sta=0;
	xfac=0;
	while(1)
	{
		TP_Scan(1);
		if((sta&0xc0)==TP_CATH_PRES)
		{
			outtime=0;
			sta&=~(1<<6);
			pos_temp[cnt][0]=arrx[0];
			pos_temp[cnt][1]=arry[0];
			cnt++;
			switch(cnt)
			{
				case 1:
					TP_Drow_Touch_Point(20,20,WHITE);
				    TP_Drow_Touch_Point(320-20,20,RED);
				    break;
				case 2:
					TP_Drow_Touch_Point(320-20,20,WHITE);
				    TP_Drow_Touch_Point(20,480-20,RED);
				    break;
				case 3:
					TP_Drow_Touch_Point(20,480-20,WHITE);
				    TP_Drow_Touch_Point(320-20,480-20,RED);
				    break;
				case 4:
					tem1=abs(pos_temp[0][0]-pos_temp[1][0]);//x1-x2
					tem2=abs(pos_temp[0][1]-pos_temp[1][1]);//y1-y2
					tem1*=tem1;
					tem2*=tem2;
					d1=sqrt(tem1+tem2);//得到1,2的距离
					
					tem1=abs(pos_temp[2][0]-pos_temp[3][0]);//x3-x4
					tem2=abs(pos_temp[2][1]-pos_temp[3][1]);//y3-y4
					tem1*=tem1;
					tem2*=tem2;
					d2=sqrt(tem1+tem2);//得到3,4的距离
					fac=(float)d1/d2;
					if(fac<0.95||fac>1.05||d1==0||d2==0)//不合格
					{
						cnt=0;
 				    	TP_Drow_Touch_Point(320-20,480-20,WHITE);	//清除点4
   	 					TP_Drow_Touch_Point(20,20,RED);					
 						continue;
					}
					tem1=abs(pos_temp[0][0]-pos_temp[2][0]);//x1-x3
					tem2=abs(pos_temp[0][1]-pos_temp[2][1]);//y1-y3
					tem1*=tem1;
					tem2*=tem2;
					d1=sqrt(tem1+tem2);//得到1,3的距离
					
					tem1=abs(pos_temp[1][0]-pos_temp[3][0]);//x2-x4
					tem2=abs(pos_temp[1][1]-pos_temp[3][1]);//y2-y4
					tem1*=tem1;
					tem2*=tem2;
					d2=sqrt(tem1+tem2);//得到2,4的距离
					fac=(float)d1/d2;
					if(fac<0.95||fac>1.05)//不合格
					{
						cnt=0;
 				    	TP_Drow_Touch_Point(320-20,480-20,WHITE);	//清除点4
   	 					TP_Drow_Touch_Point(20,20,RED);								//画点1
 						
						continue;
					}//正确了
								   
					//对角线相等
					tem1=abs(pos_temp[1][0]-pos_temp[2][0]);//x1-x3
					tem2=abs(pos_temp[1][1]-pos_temp[2][1]);//y1-y3
					tem1*=tem1;
					tem2*=tem2;
					d1=sqrt(tem1+tem2);//得到1,4的距离
	
					tem1=abs(pos_temp[0][0]-pos_temp[3][0]);//x2-x4
					tem2=abs(pos_temp[0][1]-pos_temp[3][1]);//y2-y4
					tem1*=tem1;
					tem2*=tem2;
					d2=sqrt(tem1+tem2);//得到2,3的距离
					fac=(float)d1/d2;
					if(fac<0.95||fac>1.05)//不合格
					{
						cnt=0;
 				    	TP_Drow_Touch_Point(320-20,480-20,WHITE);	//清除点4
   	 					TP_Drow_Touch_Point(20,20,RED);								//画点1
 						
						continue;
					}//正确了
					//计算结果
					xfac=(float)(320-40)/(pos_temp[1][0]-pos_temp[0][0]);//得到xfac		 
					xoff=(320-xfac*(pos_temp[1][0]+pos_temp[0][0]))/2;//得到xoff
						  
					yfac=(float)(480-40)/(pos_temp[2][1]-pos_temp[0][1]);//得到yfac
					yoff=(480-yfac*(pos_temp[2][1]+pos_temp[0][1]))/2;//得到yoff 
					FULL_COloc(WHITE);
					
					TFTLCD_Show_String(30,60,(u8*)"Touch adjust OK!",16);
					delay_ms(1000);
					FULL_COloc(WHITE);
					return;
			}
		}
		else
		{
			outtime++;
			if(outtime>1000)
			{
				return;
			}
			delay_ms(10);
		}
	}
}

void TP_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOF, ENABLE);	 //使能PB,PF端口时钟
		
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;				 // PB1端口配置
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);//B1推挽输出
	GPIO_SetBits(GPIOB,GPIO_Pin_1);//上拉
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;				 // PB2端口配置
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		 //上拉输入
	GPIO_Init(GPIOB, &GPIO_InitStructure);//B2上拉输入
	GPIO_SetBits(GPIOB,GPIO_Pin_2);//上拉		
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11|GPIO_Pin_9;	// F9，PF11端口配置
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOF, &GPIO_InitStructure);//PF9,PF11推挽输出
	GPIO_SetBits(GPIOF, GPIO_Pin_11|GPIO_Pin_9);//上拉
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;			// PF10端口配置
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		 //上拉输入
	GPIO_Init(GPIOF, &GPIO_InitStructure);//PF10上拉输入
	GPIO_SetBits(GPIOF,GPIO_Pin_10);//上拉
}