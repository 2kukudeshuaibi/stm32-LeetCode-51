#include "Time0.h"



void Time0Init()
{
    TMOD=0x01;
    TH0=0;
    TL0=0;
    TF0=0;
    TR0=0;
}

void Time0set(uint value)
{
    TH0=value/256;
    TL0=value%256;
}


uint Gettime()
{
    return (TH0<<8)|TL0;
}

void Time0run(uchar run)
{
   TR0=run;
}


