#include <reg52.h>

#define uchar unsigned char
#define uint  unsigned int
#define ulong unsigned long

//дָ��
void LCD_zhiling(uchar command);
//д����
void LCD_shuju(uchar date);

//��ʼ��
void LCD_Init();
//������ʾλ��
void setshow(uchar h,uchar l);
//��ʾһ���ַ�
void showchar(uchar h,uchar l,char a);
//��ʾ�ַ���
void showstr(uchar h,uchar l,char* p);
//��ʾ����
void shownum(uchar h,uchar l,uint number,uchar len);