#include <reg52.h>
#include "lcd1602.h"
#include "ds1302.h"

uchar DS1302_time[]={0,32,18,22,4,5,22};
void DS1302_Settime();//设置时间
void DS1302_readtime();//读时间
uchar miao;
uchar fen=0;
uchar shi=0;
uchar bcd1=0;
uchar bcd2=0;
uchar bcd3=0;

void delay(unsigned int i)
{
   unsigned int k;
   for(k=0;k<i;k++);
}
void init()
{
   LCD_Init();
   LCD_showstring(1,4,"2022-04-22");
   LCD_showstring(2,5,"00-00-00");
}
void main()
{
   init();
   DS1302_init();
   DS1302_Settime();
   while(1)
   {
      DS1302_readtime();
      LCD_shownum(2,11,DS1302_time[0],2);
      LCD_shownum(2,8,DS1302_time[1],2);
      LCD_shownum(2,5,DS1302_time[2],2);
      LCD_shownum(1,12,DS1302_time[3],2); 
      LCD_shownum(1,9,DS1302_time[4],2);
      LCD_shownum(1,16,DS1302_time[5],1);
      LCD_shownum(1,6,DS1302_time[6],2);
   }
}



void DS1302_Settime()
{
    DS1302_WriteByte(0x8e,0x00);
    DS1302_WriteByte(0x80,DS1302_time[0]/10*16+DS1302_time[0]%10);//秒
    DS1302_WriteByte(0x82,DS1302_time[1]/10*16+DS1302_time[1]%10);//分
    DS1302_WriteByte(0x84,DS1302_time[2]/10*16+DS1302_time[2]%10);//时
    DS1302_WriteByte(0x86,DS1302_time[3]/10*16+DS1302_time[3]%10);//天
    DS1302_WriteByte(0x88,DS1302_time[4]/10*16+DS1302_time[4]%10);//月
    DS1302_WriteByte(0x8a,DS1302_time[5]/10*16+DS1302_time[5]%10);//周
    DS1302_WriteByte(0x8c,DS1302_time[6]/10*16+DS1302_time[6]%10);//年
    DS1302_WriteByte(0x8e,0x80);
}

void DS1302_readtime()
{
   unsigned char tmp;
   tmp=DS1302_ReadByte(0x81);
   DS1302_time[0]=tmp/16*10+tmp%16;//秒
   
   tmp=DS1302_ReadByte(0x83);
   DS1302_time[1]=tmp/16*10+tmp%16;//分

   tmp=DS1302_ReadByte(0x85);
   DS1302_time[2]=tmp/16*10+tmp%16;//时

   tmp=DS1302_ReadByte(0x87);
   DS1302_time[3]=tmp/16*10+tmp%16;//天
   
   tmp=DS1302_ReadByte(0x89);
   DS1302_time[4]=tmp/16*10+tmp%16;//月
  
   tmp=DS1302_ReadByte(0x8b);
   DS1302_time[5]=tmp/16*10+tmp%16;//周

   tmp=DS1302_ReadByte(0x8d);
   DS1302_time[6]=tmp/16*10+tmp%16;//年
}