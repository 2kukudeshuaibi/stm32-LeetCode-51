#include <reg52.h>
#include "time0.h"


void time0_init()
{
   TMOD&=0xf0;
   TMOD|=0x01;
   TL0=0;
   TH0=0;
   TR0=0;
   TF0=0;
}

void timer_setcounter(uint value)
{
    TH0=value/256;
    TL0=value%256;
}

uint timer_getcounter()
{
    return (TH0<<8)|TL0;
}

void timer_run(uchar flag)
{
   TR0=flag;
}