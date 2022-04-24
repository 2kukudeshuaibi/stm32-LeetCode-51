#include <reg52.h>
#include "lcd1602.h"
#include <string.h>
#include <math.h>
sbit LCD_EN=P2^7;
sbit LCD_RS=P2^6;
sbit LCD_RW=P2^5;
#define LCD_DatePort P0

void LCD_delay1ms()
{
   unsigned char i,j;
   i=2;
   j=239;
   do
   {
       while(--j);
     
   }while(--i);
}

//дָ��
void LCD_WriteCommand(unsigned char command)
{
   LCD_RW=0;
   LCD_RS=0;
   LCD_DatePort=command;
   LCD_EN=1;
   LCD_delay1ms();
   LCD_EN=0;
   LCD_delay1ms();
}
//д����
void LCD_Writedate(unsigned char date)
{
   LCD_RW=0;
   LCD_RS=1;
   LCD_DatePort=date;
   LCD_EN=1;
   LCD_delay1ms();
   LCD_EN=0;
   LCD_delay1ms();
}
//��ʼ��
void LCD_Init()
{
   LCD_WriteCommand(0x38);
   LCD_WriteCommand(0x0c);
   LCD_WriteCommand(0x06);
   LCD_WriteCommand(0x01);
}

//������ʾλ��
void setac(unsigned char l,unsigned char c)
{
  if(l==1)
   {
       LCD_WriteCommand(0x80+(c-1));
   }
   else
   {
       LCD_WriteCommand(0x80+(c-1)+0x40);
   }
}

//��ʾһ���ַ�
void LCD_Showchar(unsigned char l,unsigned char c,unsigned char n)
{
   setac(l,c);
   LCD_Writedate(n);
}
//��ʾ�ַ���
void LCD_showstring(unsigned char l,unsigned char c,unsigned char* str)
{
   unsigned char i;
   unsigned char len=strlen(str);
   setac(l,c);
   for(i=0;i<len;i++)
   {
      LCD_Writedate(*(str+i));
   }
}
//���η�
int LCD_POW(int x,int y)
{
   int i=0;
   int tmp = 1;
   for(i=0;i<y;i++)
   {
      tmp=tmp*x;
   }
   return tmp;
}
//��ʾ�޷�������
void LCD_shownum(unsigned char l,unsigned char c,unsigned int number,unsigned char len)
{
   unsigned int i,tmp;
   setac(l,c);
   for(i=len;i>0;i--)
   {
      tmp=number/LCD_POW(10,i-1)%10;
      LCD_Writedate(0x30+tmp);
   }
}
//��ʾ�з�����
void LCD_showsnum(unsigned char l,unsigned char c,int number,unsigned char len)
{
   unsigned int i,tmp;
   setac(l,c);
   if(number>0)
   {
      LCD_Writedate('+');
      tmp=number;
      
   }
   else
   {
      LCD_Writedate('-');
      tmp=-number;
   }
   for(i=len;i>0;i--)
   {
      
      LCD_Writedate(0x30+tmp/LCD_POW(10,i-1)%10);
   }
}

//��ʾ16����
void LCD_showhexnum(unsigned char l,unsigned char c,unsigned int num,unsigned char len)
{
   unsigned int i,tmp;
   setac(l,c);
   for(i=len;i>0;i--)
   {
      tmp=num/LCD_POW(16,i-1)%16;
      if(tmp<10)
      {
         LCD_Writedate(0x30+tmp);
      }
      else
      {
         LCD_Writedate(0x37+tmp);
      }
   }
}
//��ʾ������
void LCD_showbinnum(unsigned char l,unsigned char c,unsigned int num,unsigned char len)
{
   unsigned int i,tmp;
   setac(l,c);
   for(i=len;i>0;i--)
   {
      tmp=num/LCD_POW(2,i-1)%2;
      LCD_Writedate(0x30+tmp);
   }
}