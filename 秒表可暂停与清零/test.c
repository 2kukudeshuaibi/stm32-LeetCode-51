#include <reg51.h>

sbit lsa = P2 ^ 2;
sbit lsb = P2 ^ 3;
sbit lsc = P2 ^ 4;

unsigned char arr[] = { 0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f };
unsigned int tt = 0;
unsigned int num = 0;
unsigned int bai = 0, shi = 0, ge = 0;


//延时函数声明
void delay(unsigned int i);
//控制数码管显示
void display(int bai, int shi, int ge);

void main()
{
  P3=0xff;
	TMOD = 1;
	TH0 = (65536 - 50000) / 256;
	TL0 = (65536 - 50000) % 256;
	EA = 1;
	ET0 = 1;
	TR0 = 1;
	while (1)
	{
		if (P3 == 0xfd)
		{
			TR0 = 0;
		}
		if (P3 == 0xfe)
		{
			TR0 = 1;
		}
		if (P3 == 0xfb)
		{
			num = 0;
		}
		bai = num / 100;
		shi = num / 10 % 10;
		ge = num % 10;
		display(bai, shi, ge);
	}
}

void delay(unsigned int i)
{
	unsigned int k = 0;
	for (k = 0; k < i; k++);
}

void display(int bai, int shi, int ge)
{
	lsc = 1; lsb = 1; lsa = 1;
	P0 = arr[bai];
	delay(400);

	lsc = 1; lsb = 1; lsa = 0;
	P0 = arr[shi];
	delay(400);

	lsc = 1; lsb = 0; lsa = 1;
	P0 = arr[ge];
	delay(400);
}

void exter()  interrupt 1
{
	TH0 = (65536 - 10000) / 256;
	TL0 = (65536 - 10000) % 256;
	if (P3 == 0xff)
	{
		tt++;
		if (tt == 1)
		{
			num++;
			tt = 0;
			if (num == 1000)
			{
				num = 0;
			}
		}
	}
}