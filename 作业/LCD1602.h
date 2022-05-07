#include "public.h"

void LCD_zhiling(uchar command);
void LCD_shuju(uchar date);
void LCD_Init();
void setshow(uchar h,uchar l);
void showstr(uchar h,uchar l,char* p);
uint LCD_Pow(uint num,uchar len);
void shownumber(uchar h,uchar l,uint number,uchar len);
void showHex(uchar h,uchar l,uint number,uchar len);