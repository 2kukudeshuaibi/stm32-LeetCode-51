#include <reg52.h>
//#define uchar unsigned char
//#define uint  unsigned int


void LCD_WriteCommand(unsigned char command);//写指令函数
void LCD_Writedate(unsigned char date);//写数据函数
void LCD_Init();//初始化
void LCD_Showchar(unsigned char l,unsigned char c,unsigned char n);//写一个字符
void LCD_showstring(unsigned char l,unsigned char c,unsigned char* str);//写字符串
void LCD_shownum(unsigned char l,unsigned char c,unsigned int number,unsigned char len);//写无符号数
void LCD_showsnum(unsigned char l,unsigned char c,int number,unsigned char len);//写有符号数
void LCD_showhexnum(unsigned char l,unsigned char c,unsigned int num,unsigned char len);//显示16进制
void LCD_showbinnum(unsigned char l,unsigned char c,unsigned int num,unsigned char len);//显示2进制