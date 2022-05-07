#include "Time0.h"
#include <reg52.h>

void Time0Init()
{
    TMOD=1;
    TH0=0;
    TL0=0;
    TF0=0;
    TR0=0;
}

void Time0run(uchar command)
{
    TR0=command;
}


void Time0set(uint time)
{
    TH0=time/256;
    TL0=time%256;
}

uint Gettime()
{
    return (TH0<<8)|TL0;
}