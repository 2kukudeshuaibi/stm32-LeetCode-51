#include <reg52.h>
#include "ds1302.h"

 
sbit DS1302_SCLK=P3^6;
sbit DS1302_IO=P3^4;
sbit DS1302_CE=P3^5;

void delay1(unsigned int i)
{
   unsigned int k;
   for(k=0;k<i;k++);
}
void DS1302_init()
{
   DS1302_CE=0;
   DS1302_SCLK=0;
}

void DS1302_WriteByte(uchar command,uchar date)
{
   uchar i;

   DS1302_CE=1;
   //写指令
   for(i=0;i<8;i++)
   {
      DS1302_IO=command&(0x01<<i);
      DS1302_SCLK=1;
      DS1302_SCLK=0;
   }
   //写数据
   for(i=0;i<8;i++)
   {
      DS1302_IO=date&(0x01<<i);
      DS1302_SCLK=1;
      DS1302_SCLK=0;
   }
   DS1302_CE=0;
}

uchar DS1302_ReadByte(uchar command)
{
    uchar i;
    uchar date=0x00;
    DS1302_CE=1;
    //写指令
    for(i=0;i<8;i++)
   {
      DS1302_IO=command&(0x01<<i);
      DS1302_SCLK=0;
      delay1(3);
      DS1302_SCLK=1;
      delay1(3);
   }
   //读数据
   DS1302_IO=0;
   for(i=0;i<8;i++)
   {
       DS1302_SCLK=1;
       delay1(3);
       DS1302_SCLK=0;
       delay1(3);
       if(DS1302_IO)
       {
         date|=0x01<<i;
       }
   }
   DS1302_CE=0;
   return date;
}

//void DS1302_Settime()
//{
//    DS1302_WriteByte(0x8e,0x00);
//    DS1302_WriteByte(0x80,DS1302_time[0]/10*16+DS1302_time[0]%10);//秒
//    DS1302_WriteByte(0x82,DS1302_time[1]/10*16+DS1302_time[1]%10);//分
//    DS1302_WriteByte(0x84,DS1302_time[2]/10*16+DS1302_time[2]%10);//时
//    DS1302_WriteByte(0x86,DS1302_time[3]/10*16+DS1302_time[3]%10);//天
//    DS1302_WriteByte(0x88,DS1302_time[4]/10*16+DS1302_time[4]%10);//月
//    DS1302_WriteByte(0x8a,DS1302_time[5]/10*16+DS1302_time[5]%10);//周
//    DS1302_WriteByte(0x8c,DS1302_time[6]/10*16+DS1302_time[6]%10);//年
//    DS1302_WriteByte(0x8e,0x80);
//}

//void DS1302_readtime()
//{
//   unsigned char tmp;
//   tmp=DS1302_ReadByte(0x81);
//   DS1302_time[0]=tmp/16*10+tmp%16;//秒
//   
//   tmp=DS1302_ReadByte(0x83);
//   DS1302_time[1]=tmp/16*10+tmp%16;//分

//   tmp=DS1302_ReadByte(0x85);
//   DS1302_time[2]=tmp/16*10+tmp%16;//时

//   tmp=DS1302_ReadByte(0x87);
//   DS1302_time[3]=tmp/16*10+tmp%16;//天
//   
//   tmp=DS1302_ReadByte(0x89);
//   DS1302_time[4]=tmp/16*10+tmp%16;//月
//  
//   tmp=DS1302_ReadByte(0x8b);
//   DS1302_time[5]=tmp/16*10+tmp%16;//周

//   tmp=DS1302_ReadByte(0x8d);
//   DS1302_time[6]=tmp/16*10+tmp%16;//年
//}