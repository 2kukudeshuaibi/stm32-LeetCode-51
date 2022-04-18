#include <reg52.h>

sbit rw=P2^5;
sbit rs=P2^6;
sbit en=P2^7;


#define uchar unsigned char
#define uint  unsigned int
	
void delay(uint i);//��ʱ����
void zhiling(uchar num);//ָ���
void shuju(uchar date);//���ݺ���
void init();//��ʼ��
void show1(char* str1);//1����ʾ
void show2(char* str2);//2����ʾ

void main()
{
	 int k = 0;
	 init();
	 show1("I Like YOU");
	 show2("Qi Jin Bo");
	 
	 for(k=0;k<16;k++)
	{
		 zhiling(0x18);
		 delay(400);
	}
	while(1);
}



//��ʱ����
void delay(uint i)
{
	 uint x,y;
	 for(x=i;x>0;x--)
	{
		for(y=110;y>0;y--);
	}
}

//ָ���
void zhiling(uchar num)
{
   rw=0;
	 rs=0;
	 en=0;
	 P0=num;
	 delay(5);
	 en=1;
	 delay(5);
	 en=0;
}

//���ݺ���
void shuju(uchar date)
{
	 rs=1;
	 rw=0;
	 en=0;
	 P0=date;
	 delay(5);
	 en=1;
	 delay(5);
	 en=0;
}

//��ʼ������
void init()
{
	 zhiling(0x38);
	 zhiling(0x0f);
	 zhiling(0x06);
	 zhiling(0x01);
}

//��ʾ
void show1(char* str1)
{
	 zhiling(0x80+0x10);
	 while(*str1!='\0')
	 {
		  
		  shuju(*str1);
		  delay(5);
		  str1++;
	 }
	 
}
//2����ʾ
void show2(char* str2)
{
	 zhiling(0x80+0x50);
	 while(*str2!='\0')
	 {
		  shuju(*str2);
		  delay(5);
		  str2++;
	 }
}