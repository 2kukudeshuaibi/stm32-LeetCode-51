#include <reg52.h>
#include "public.h"

void LCD_Writecommand(u8 command);
void LCD_Writedate(u8 date);
void LCD_Init();
void setshow(u8 h,u8 l);
void xiestring(u8 h,u8 l,char* str);
void LCD_shownum(u8 h,u8 l,int num,u8 len);
void LCD_showchar(u8 h,u8 l,char a);

void LCD_showbinnum(u8 h,u8 l,u16 num,u8 len);