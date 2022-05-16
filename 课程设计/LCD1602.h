#ifndef _LCD1602_H
#define _LCD1602_H

#include "Public.h"

sbit LCD_EN=P2^7;
sbit LCD_RS=P2^6;
sbit LCD_RW=P2^5;

void LCD_Write_zhiling(uchar date);
void LCD_Write_shuju(uchar date);
void LCD_Init();
void LCD_set_show(uchar h,uchar l);
void LCD_Show_str(uchar h,uchar l,char* p);
uint LCD_Pow(uint x,uint y);
void LCD_show_num(uchar h,uchar l,uint number,uchar len);

#endif