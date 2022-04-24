#include <reg52.h>
#include "lcd1602.h"
#include "ds1302.h"


sbit k1=P3^1;
sbit k2=P3^0;
sbit k3=P3^2;

uchar DS1302_time[]={0,22,19,24,4,7,22};
uchar count = 0;
uchar miao,fen,shi,tian,yue,zhou,nian;

void DS1302_Settime();//设置时间
void DS1302_readtime();//读时间
void keyscan1();
void keyscan2();
void keyscan3();


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
      keyscan1();
      keyscan2();
      keyscan3();
      if(count==0)
      {
         DS1302_readtime();
         LCD_shownum(2,11,DS1302_time[0],2);//秒
         LCD_shownum(2,8,DS1302_time[1],2);//分
         LCD_shownum(2,5,DS1302_time[2],2);//时
         LCD_shownum(1,12,DS1302_time[3],2); //天
         LCD_shownum(1,9,DS1302_time[4],2);//月
         LCD_shownum(1,16,DS1302_time[5],1);//周
         LCD_shownum(1,6,DS1302_time[6],2);//年
      }
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
void keyscan1()
{
   if(k1==0)
   {
      delay(5);
      if(k1==0)
      {
          count++;
          while(!k1);
          if(count==1)
          {
              LCD_WriteCommand(0x80+0x40+11);
              LCD_WriteCommand(0x0f);
          }

          if(count==2)
          {
              LCD_WriteCommand(0x80+0x40+8);
              LCD_WriteCommand(0x0f);
          }
          if(count==3)
          {
              LCD_WriteCommand(0x80+0x40+5);
              LCD_WriteCommand(0x0f);
          }
          if(count==4)
          {
              LCD_WriteCommand(0x80+15);
              LCD_WriteCommand(0x0f);
          }
          if(count==5)
          {
              LCD_WriteCommand(0x80+12);
              LCD_WriteCommand(0x0f);
          }
          if(count==6)
          {
              LCD_WriteCommand(0x80+9);
              LCD_WriteCommand(0x0f);
          }
          if(count==7)
          {
              LCD_WriteCommand(0x80+6);
              LCD_WriteCommand(0x0f);
          }
          if(count==8)
          {
              count=0;
              LCD_WriteCommand(0x0c);
              DS1302_Settime();
          }
      }
   }
}
void keyscan2()
{
   if(k2==0)
   {
      if(count!=0)
     {
       if(count==1)
       {
          miao=DS1302_time[0];
          miao++;
          if(miao==60)
          {
             miao=0;
          }
          while(!k2);
          DS1302_time[0]=miao;
          LCD_shownum(2,11,DS1302_time[0],2);
          LCD_WriteCommand(0x80+0x40+11);
       }
       if(count==2)
       {
          fen=DS1302_time[1];
          fen++;
          if(fen==60)
          {
             fen=0;
          }
          while(!k2);
          DS1302_time[1]=fen;
          LCD_shownum(2,8,DS1302_time[1],2);
          LCD_WriteCommand(0x80+0x40+8);   
       }
       if(count==3)
       {
          shi=DS1302_time[2];
          shi++;
          if(shi==24)
          {
             shi=0;
          }
          while(!k2);
          DS1302_time[2]=shi;
          LCD_shownum(2,5,DS1302_time[2],2);
          LCD_WriteCommand(0x80+0x40+5);      
       }
       if(count==4)
       {
          zhou = DS1302_time[5];
          zhou++;
          if (zhou == 8)
          {
            zhou = 0;
          }
          while (!k2);
          DS1302_time[5] = zhou;
          LCD_shownum(1, 16, DS1302_time[5], 1);
          LCD_WriteCommand(0x80+15);         
       }
       if(count==5)
       {
           tian = DS1302_time[3];
           tian++;
           while (!k2);
           DS1302_time[3] = tian;
           LCD_shownum(1, 12, DS1302_time[3], 2);
           LCD_WriteCommand(0x80+12);       
       }
       if(count==6)
       {
          yue = DS1302_time[4];
          yue++;
          if (yue == 13)
          {
            yue = 0;
          }
          while (!k2);
          DS1302_time[4] = yue;
          LCD_shownum(1, 9, DS1302_time[4], 2);
          LCD_WriteCommand(0x80+9);
       }
       if(count==7)
       {
          nian=DS1302_time[6];
          nian++;
          if(nian==99)
          {
             nian=0;
          }
          while(!k2);
          DS1302_time[6]=nian;
          LCD_shownum(1,6,DS1302_time[6],2);
          LCD_WriteCommand(0x80+6);          
       }
     }
   }

}

void keyscan3()
{
   if(k3==0)
   {
      if(count!=0)
     {
       if(count==1)
       {
          miao=DS1302_time[0];
          
          if(miao!=0)
          {
             miao--;
          }
          else
          {
             miao=59;
          }
          while(!k3);
          DS1302_time[0]=miao;
          LCD_shownum(2,11,DS1302_time[0],2);
          LCD_WriteCommand(0x80+0x40+11);
       }
       if(count==2)
       {
          fen=DS1302_time[1];
      
          if(fen!=0)
          {
             fen--;
          }
          else
          {
             fen=59;
          }
          while(!k3);
          DS1302_time[1]=fen;
          LCD_shownum(2,8,DS1302_time[1],2);
          LCD_WriteCommand(0x80+0x40+8);   
       }
       if(count==3)
       {
          shi=DS1302_time[2];
          
          if(shi!=0)
          {
             shi--;
          }
          else
          {
             shi=23;
          }
          while(!k3);
          DS1302_time[2]=shi;
          LCD_shownum(2,5,DS1302_time[2],2);
          LCD_WriteCommand(0x80+0x40+5);      
       }
       if(count==4)
       {
          zhou = DS1302_time[5];
          
          if (zhou != 0)
          {
            zhou--;
          }
          else
          {
            zhou=7;
          }
          while (!k3);
          DS1302_time[5] = zhou;
          LCD_shownum(1, 16, DS1302_time[5], 1);
          LCD_WriteCommand(0x80+15);         
       }
       if(count==5)
       {
           tian = DS1302_time[3];
           if(tian!=0)
           {
              tian--;
           }
           else
           {
              tian=30;
           }
           while (!k3);
           DS1302_time[3] = tian;
           LCD_shownum(1, 12, DS1302_time[3], 2);
           LCD_WriteCommand(0x80+12);       
       }
       if(count==6)
       {
          yue = DS1302_time[4];
          
          if (yue != 0)
          {
            yue--;
          }
          else
          {
            yue=12;
          }
          while (!k3);
          DS1302_time[4] = yue;
          LCD_shownum(1, 9, DS1302_time[4], 2);
          LCD_WriteCommand(0x80+9);
       }
       if(count==7)
       {
          nian=DS1302_time[6];
          
          if(nian!=0)
          {
             nian--;
          }
          else
          {
             nian=99;
          }
          while(!k3);
          DS1302_time[6]=nian;
          LCD_shownum(1,6,DS1302_time[6],2);
          LCD_WriteCommand(0x80+6);          
       }
     }
   }

}