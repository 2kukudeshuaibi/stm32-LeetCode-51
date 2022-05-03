#include <reg52.h>

#define uchar unsigned char
#define uint  unsigned int
#define ulong unsigned long

//写指令
void LCD_zhiling(uchar command);
//写数据
void LCD_shuju(uchar date);

//初始化
void LCD_Init();
//设置显示位置
void setshow(uchar h,uchar l);
//显示一个字符
void showchar(uchar h,uchar l,char a);
//显示字符串
void showstr(uchar h,uchar l,char* p);
//显示数字
void shownum(uchar h,uchar l,uint number,uchar len);