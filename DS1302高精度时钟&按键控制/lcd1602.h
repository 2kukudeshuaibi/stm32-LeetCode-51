#include <reg52.h>
//#define uchar unsigned char
//#define uint  unsigned int


void LCD_WriteCommand(unsigned char command);//дָ���
void LCD_Writedate(unsigned char date);//д���ݺ���
void LCD_Init();//��ʼ��
void LCD_Showchar(unsigned char l,unsigned char c,unsigned char n);//дһ���ַ�
void LCD_showstring(unsigned char l,unsigned char c,unsigned char* str);//д�ַ���
void LCD_shownum(unsigned char l,unsigned char c,unsigned int number,unsigned char len);//д�޷�����
void LCD_showsnum(unsigned char l,unsigned char c,int number,unsigned char len);//д�з�����
void LCD_showhexnum(unsigned char l,unsigned char c,unsigned int num,unsigned char len);//��ʾ16����
void LCD_showbinnum(unsigned char l,unsigned char c,unsigned int num,unsigned char len);//��ʾ2����