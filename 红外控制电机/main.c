#include <reg52.h>
#include "Public.h"
#include "LCD1602.h"
#include "Time0.h"
#include "INT0.h"
#include "IR.h"

sbit dj=P1^0;
sbit lsa=P2^2;
sbit lsb=P2^3;
sbit lsc=P2^4;

uchar arr[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};

uchar address;//红外地址
uchar command;//键码值

uchar tt=0;
uchar camp=0;
char num=0;

void smg(unsigned char ge);//数码管显示

void main()
{
   LCD_Init();//初始化LCD
   IR_Init();//初始化红外
   showstr(1,1,"Add  Command");
   showHEX(2,1,00,2);
   showHEX(2,6,00,2);
   while(1)
   {
      if(IR_getdateflag()||IR_getrepeat())
      {
           address=IR_getadd();
           command=IR_getcommand();
           showHEX(2,1,address,2);
           showHEX(2,6,command,2);
      }
      if(command==0x15)
      {
          num--;
          command=0;
      }
      if(command==0x09)
      {
          num++;
          command=0;
      }
      switch(num)
      {
         case 0:camp=0;break;
         case 1:camp=50;break;
         case 2:camp=75;break;
         case 3:camp=100;break;
      }
      if(num>3)
      {
         num=0;
      }
      if(num<0)
      {
         num=0;
      }
      smg(num);
      for(tt=0;tt<100;tt++)
      {
         if(camp>tt)
         {  
             dj=1; 
         }
         else
         {
             dj=0;
         } 
      }
   }
}




void smg(uchar ge)
{
    lsc=1;lsb=1;lsa=1;
    P0=arr[ge];
}


