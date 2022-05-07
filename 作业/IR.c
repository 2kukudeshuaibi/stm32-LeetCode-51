#include "IR.h"
#include "LCD1602.h"

uchar start=0;
uchar date[4];
uchar pdate;

uint time;

uchar add;
uchar command;
uchar dateflag;
uchar repeatflag;


void IRInit()
{
    Time0Init();
    INT0init();
}

uchar getdateflag()
{
    if(dateflag)
    {
         dateflag=0;
         return 1;
    }
    return 0;
}

uchar getrepeatflag()
{
     if(repeatflag)
     {
         repeatflag=0;
         return 1;
     }
     return 0;
}

uchar getadd()
{
     return add;
}

uchar getcommand()
{
     return command;
}

void INT0zduan() interrupt 0
{
    if(start==0)
    {
        Time0set(0);
        Time0run(1);
        start=1;
    }
    else if(start==1)
    {
        time=Gettime();
        Time0set(0);
        if(time>=13500-900 && time<=13500+900)
        {
            start=2;
        }
        else if(time>=11250-900 && time<=11250+900)
        {
            repeatflag=1;
            Time0run(0);
            start=0;
        }
        else
        {
            start=1;
        }
    }
    else if(start==2)
    {
        time=Gettime();
        Time0set(0);
        if(time>=1120-500 && time<=1120+500)
        {
             date[pdate/8]&=~(0x01<<(pdate%8));
             pdate++;
        }
        else if(time>=2250-500 && time<=2250+500)
        {
             date[pdate/8]|=(0x01<<(pdate%8));
             pdate++;
        }
        else
        {
             pdate=0;
             start=1;
        }
        if(pdate>=32)
        {
             pdate=0;
             if(date[0]==~date[1] && date[2]==~date[3])
             {
                   add=date[0];
                   command=date[2];
                   dateflag=1;
             }
             start=0;
             Time0run(0);
        }
    }
}



