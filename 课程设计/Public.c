#include "Public.h"

void delay(uint i)
{
    while(i--);
}

void delay1(uint num)
{
    uint i,j;
    for(i=num;i>0;i--)
    {
        for(j=110;j>0;j--);
    }
}

