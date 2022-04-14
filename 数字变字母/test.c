#include <reg51.h>
#include <intrins.h>
sbit LSA=P2^2;
sbit LSB=P2^3;
sbit LSC=P2^4;

void delay(unsigned int i)
{
	unsigned int k = 0;
	for(k = 0;k < i;k++);
}
void init0();
void init1();


unsigned char t0=0;
unsigned char t1=0;
unsigned int num=432;
unsigned char arr[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};


void main()
{
	init0();
	while(1)
	{
		
		if(num >= 398 && t1 < 60)
		{
		  LSC=1;LSB=1;LSA=1;
		  P0=arr[7];
		  delay(200);
		  P0=0x00;
		
		  LSC=1;LSB=1;LSA=0;
		  P0=arr[6];
		  delay(200);
		  P0=0x00;
		
		  LSC=1;LSB=0;LSA=1;
		  P0=arr[5];
		  delay(200);
		  P0=0x00;
		
		  LSC=1;LSB=0;LSA=0;
		  P0=arr[num/100];
		  delay(200);
		  P0=0x00;
		
		  LSC=0;LSB=1;LSA=1;
		  P0=arr[num/10%10];
		  delay(200);
		  P0=0x00;
		
		  LSC=0;LSB=1;LSA=0;
		  P0=arr[num%10];
		  delay(200);
		  P0=0x00;
		}
		else
		{
		  LSC=1;LSB=1;LSA=1;
		  P0=0x76;
		  delay(200);
		  P0=0x00;
		
		  LSC=1;LSB=1;LSA=0;
		  P0=0x79;
		  delay(200);
		  P0=0x00;
		
		  LSC=1;LSB=0;LSA=1;
		  P0=0x38;
		  delay(200);
		  P0=0x00;
		
		  LSC=1;LSB=0;LSA=0;
		  P0=0x38;
		  delay(200);
		  P0=0x00;
		
		  LSC=0;LSB=1;LSA=1;
		  P0=0x3f;
		  delay(200);
		  P0=0x00;
		}
	}
}




void init0()
{
	TMOD=0x11;
	TH0=(65536-50000)/256;
	TL0=(65536-50000)%256;
	EA=1;
	ET0=1;
	TR0=1;
}
void init1()
{
	TH1=(65536-50000)/256;
	TL1=(65536-50000)%256;
	ET1=1;
	TR1=1;
}


 


void zduan0() interrupt 1
{
	TH0=(65536-50000)/256;
	TL0=(65536-50000)%256;
	t0++;
	if(t0==2)
	{
		t0=0;
		
		if(num>398)
		{
			num--;
		}
		if(num==398)
		{
			init1();
			ET0=0;
	    TR0=0;
		}
	}
}

void zduan1() interrupt 3
{
	TH1=(65536-50000)/256;
	TL1=(65536-50000)%256;
	t1++;
	if(t1==60)
	{
		ET1=0;
		TR1=0;
	}
}