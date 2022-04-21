#include <reg52.h>

#define uchar unsigned char
#define uint  unsigned int

uchar tt=0;
uchar shi=0;
uchar fen=0;
uchar miao=0;

uchar tian=21;
uchar yue=4;
uint  nian=2022;


uchar count1=0;
uchar count2=0;



//定义液晶显示屏的按键
sbit rw=P2^5;
sbit rs=P2^6;
sbit en=P2^7;

//定义功能按键
sbit k1=P3^1;
sbit k2=P3^0;
sbit k3=P3^2;

uchar code table[]=" 2022-04-21 TUES";
uchar code table1[]="    00:00:00";
//延时
void delay(uint i)
{
   uint x,y;
   for(x=i;x>0;x--)
   {
     for(y=110;y>0;y--);
   }
}
//指令
void zhiling(uchar com)
{
   rw=0;
   rs=0;
   en=0;
   P0=com;
   delay(5);
   en=1;
   delay(5);
   en=0;
}
//数据
void shuju(uchar date)
{
   rs=1;
   en=0;
   P0=date;
   delay(5);
   en=1;
   delay(5);
   en=0;
}
//初始化
void init()
{
   uchar num;
   en=0;
   zhiling(0x38);
   zhiling(0x0c);
   zhiling(0x06);
   zhiling(0x01);
   zhiling(0x80);
   for(num=0;num<16;num++)
   {
      shuju(table[num]);
      delay(5);
   }
   zhiling(0x80+0x40);
   for(num=0;num<12;num++)
   {
       shuju(table1[num]);
       delay(5);
   }
   TMOD=0x01;
   TH0=(65536-50000)/256;
   TL0=(65536-50000)%256;
   EA=1;
   ET0=1;
   TR0=1;
}


//刷新时间
void shuaxin_sfm(uchar add,uchar date)
{
   uchar shi1,ge1;
   shi1=date/10;
   ge1=date%10;
   zhiling(0x80+0x40+add);
   shuju(0x30+shi1);
   shuju(0x30+ge1);
   
}
//刷新月日
void shuaxin_nyr(uchar add,uchar date)
{
   uchar shi2,ge2;
   shi2=date/10;
   ge2=date%10;
   zhiling(0x80+add);
   shuju(0x30+shi2);
   shuju(0x30+ge2);
}

//刷新年
void shuaxin_n(uchar add,uint date)
{
   uchar qian,bai,shi3,ge3;
   qian=date/1000;
   bai=date/100%10;
   shi3=date/10%10;
   ge3=date%10;
   zhiling(0x80+add);
   shuju(0x30+qian);
   shuju(0x30+bai);
   shuju(0x30+shi3);
   shuju(0x30+ge3);
}
//检测键盘K1
void keyscan1()
{
   if(k1==0)
   {
     delay(5);//消抖
     if(k1==0)
     {
        count1++;
        while(!k1);
        TR0=0;
        if(count1==1)
        {
           zhiling(0x80+0x40+11);
           zhiling(0x0f);
        }
        if(count1==2)
        {
           zhiling(0x80+0x40+8);
           zhiling(0x0f);
        }
        if(count1==3)
        {
           zhiling(0x80+0x40+5);
           zhiling(0x0f);
        }
        if(count1==4)
        {
           zhiling(0x80+10);
           zhiling(0x0f);
        }
        if(count1==5)
        {
           zhiling(0x80+7);
           zhiling(0x0f);
        }
        if(count1==6)
        {
           zhiling(0x80+4);
           zhiling(0x0f);
        }
        if(count1==7)
        {
            count1=0;
            TR0=1;
            zhiling(0x0c);
        }
     }
   }
}
//检测键盘k2
void keyscan2()
{
   if(count1!=0)
   {
      if(k2==0)
      {
         delay(5);
         if(k2==0)
         {
            while(!k2);
            if(count1==1)
            {
               miao++;
               if(miao==60)
               {
                  miao=0;
               }
               shuaxin_sfm(10,miao);
               zhiling(0x80+0x40+11);
            }
            if(count1==2)
            {
               fen++;
               if(fen==60)
               {
                  fen=0;
               }
               shuaxin_sfm(7,fen);
               zhiling(0x80+0x40+8);
            }
            if(count1==3)
            {
               shi++;
               if(shi==24)
               {
                  shi=0;
               }
               shuaxin_sfm(4,shi);
               zhiling(0x80+0x40+5);
            }
            if(count1==4)
            {
               tian++;
               if(tian==30)
               {
                  tian=1;
               }
               shuaxin_nyr(9,tian);
               zhiling(0x80+10);
            }
            if(count1==5)
            {
               yue++;
               if(yue==13)
               {
                  yue=1;
               }
               shuaxin_nyr(6,yue);
               zhiling(0x80+7);
            }
            if(count1==6)
            {
               nian++;
               shuaxin_n(1,nian);
               zhiling(0x80+4);
            }
         }
      }
   }
}

//检测键盘k3
void keyscan3()
{
   if(count1!=0)
   {
      if(k3==0)
      {
         delay(5);
         if(k3==0)
         {
            while(!k3);
            if(count1==1)
            {
               
               if(miao!=0)
               {
                  miao--;
               }
               else
               {
                  miao=59;
               }
               shuaxin_sfm(10,miao);
               zhiling(0x80+0x40+11);
            } 
            if(count1==2)
            {
               if(fen!=0)
               {
                  fen--;
               }
               else
               {
                  fen=59;
               }
               shuaxin_sfm(7,fen);
               zhiling(0x80+0x40+8);
            }
            if(count1==3)
            {
               if(shi!=0)
               {
                  shi--;
               }
               else
               {
                  shi=23;
               }
               shuaxin_sfm(4,shi);
               zhiling(0x80+0x40+5);
            }
            if(count1==4)
            {
               if(tian!=0)
               {
                  tian--;
               }
               else
               {
                  tian=29;
               }
               shuaxin_nyr(9,tian);
               zhiling(0x80+10);
            }
            if(count1==5)
            {
               if(yue!=0)
               {
                  yue--;
               }
               else
               {
                  yue=12;
               }
               shuaxin_nyr(6,yue);
               zhiling(0x80+7);
            }
            if(count1==6)
            {
               nian--;
               if(nian==0)
               {
                  nian=3000;
               }
               shuaxin_n(1,nian);
               zhiling(0x80+4);
            }
         }
      }
   }
}

//主函数
void main()
{
   init();
   while(1)
   {
     keyscan1();
     keyscan2();
     keyscan3();
     if(tt==20)
     {
        tt=0;
        miao++;
        if(miao==60)
        {
           miao=0;
           fen++;
           if(fen==60)
           {
              fen=0;
              shi++;
              if(shi==24)
              {
                 shi=0;
                 tian++;
                 if(tian==30)
                 {
                    tian=1;
                    yue++;
                    if(yue==13)
                    {
                       yue=1;
                       nian++;
                       shuaxin_n(1,nian);
                    }
                    shuaxin_nyr(6,yue);
                 }
                 shuaxin_nyr(9,tian);
              }
              shuaxin_sfm(4,shi);
           }
           shuaxin_sfm(7,fen);
        }
        shuaxin_sfm(10,miao);
     }
   }  
}

void zduan() interrupt 1
{
   TH0=(65536-50000)/256;
   TL0=(65536-50000)%256;
   tt++;
}