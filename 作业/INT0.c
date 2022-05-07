#include "INT0.h"
#include <reg52.h>

void INT0init()
{
    IT0=1;
    IE0=0;
    EA=1;
    EX0=1;
    PX0=1;
}

//void INT0zduan() interrupt 0
//{
//  
//}