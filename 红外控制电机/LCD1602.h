#include <reg52.h>
#include "Public.h"


void LCD_zhiling(uchar command);//ָ��

void LCD_shuju(uchar date);//����

void LCD_Init();//���ʻ�

void LCD_setshow(uchar h,uchar l);//������ʾλ��

void showchar(uchar h,uchar l,char a);//��ʾһ���ַ�

void shownumber(uchar h,uchar l,uint num,uchar len);//��ʾ����

void showHEX(uchar h,uchar l,uint num,uchar len);//��ʾ16��������

void showstr(uchar h,uchar l,char* p);//��ʾ�ַ���
