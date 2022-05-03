#include <reg52.h>
#include "Public.h"


void LCD_zhiling(uchar command);//指令

void LCD_shuju(uchar date);//数据

void LCD_Init();//舒适化

void LCD_setshow(uchar h,uchar l);//设置显示位置

void showchar(uchar h,uchar l,char a);//显示一个字符

void shownumber(uchar h,uchar l,uint num,uchar len);//显示数字

void showHEX(uchar h,uchar l,uint num,uchar len);//显示16进制数字

void showstr(uchar h,uchar l,char* p);//显示字符串
