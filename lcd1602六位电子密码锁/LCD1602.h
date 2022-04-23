#include <reg52.h>

#define uchar unsigned char
#define uint  unsigned int

void delay(uchar i);
void LCD_zhiling(uchar date);
void LCD_shuju(uchar date);
void initLCD();
void setshow(uchar h,uchar l);
void showstr(uchar h,uchar l,uchar* p);
void shownum(uchar h,uchar l,uint number,uchar len);