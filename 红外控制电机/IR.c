#include "IR.h"

uchar IR_start;//状态切换标志位
uint IR_time;//读取时序的时间


uchar IR_date[4];//存储读来的4个字节的数据
uchar IR_pdate;//控制数据的存储位置



uchar IR_dateflag;
uchar IR_repeatflag;
uchar IR_Add;
uchar IR_command;


void IR_Init()
{
   Time0Init();
   INT0init();
}


uchar IR_getdateflag()
{
    if(IR_dateflag)
    {
         IR_dateflag=0;
         return 1;
    }
    return 0;
}

uchar IR_getrepeat()
{
    if(IR_repeatflag)
    {
        IR_repeatflag=0;
        return 1;
    }
    return 0;
}

uchar IR_getadd()
{
    return IR_Add;
}

uchar IR_getcommand()
{
    return IR_command;
}


void IR_Zduan() interrupt 0
{
    if(IR_start==0)
    {
        
        Time0set(0);
        Time0run(1);
        IR_start=1;
    }
    else if(IR_start==1)
    {
        IR_time=Gettime();
        Time0set(0);
        if((IR_time>13500-900)&&(IR_time<13500+900))
        {
             IR_start=2;
        }
        else if((IR_time>11250-900)&&(IR_time<11250+900))
        {
             IR_repeatflag=1;
             Time0run(0);
             IR_start=0;
        }
        else
        {
             IR_start=1;
        }

    }
    else if(IR_start==2)
    {
        IR_time=Gettime();
        Time0set(0);
        if((IR_time>1120-500)&&(IR_time<1120+500))
        {
             IR_date[IR_pdate/8]&=~(0x01<<IR_pdate%8);
             IR_pdate++;
        }
        else if((IR_time>2250-500)&&(IR_time<2250+500))
        {
             IR_date[IR_pdate/8]|=(0x01<<IR_pdate%8);
             IR_pdate++;
        }
        else
        {
             IR_pdate=0;
             IR_start=1;
        }
        if(IR_pdate>=32)
        {
           IR_pdate=0;
           if(((IR_date[0]) == (~IR_date[1])) && ((IR_date[2]) == (~IR_date[3])))
           {
                IR_Add=IR_date[0];
                IR_command=IR_date[2];
                IR_dateflag=1;
           }
           Time0run(0);           
           IR_start=0;
        }
    }
}