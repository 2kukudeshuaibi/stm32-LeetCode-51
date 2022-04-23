#include <reg52.h>
#include "LCD1602.h"

sbit qd=P3^1;

uchar flag = 0;
uchar arr1[10] = { 0,1,2,3,4,5,6,7,8,9 };
uchar arr2[6] = { 0 };
uchar mima[6] = { 1,6,2,8,4,1};


void delay1(uint i)
{
   uint j;
   for(j=0;j<i;j++);
}
uchar keyscan()
{
    uchar k = 0;
    
    while (k == 0)
    {
        uchar tmp;
        P1 = 0x7f;
        tmp = P1;
        tmp = tmp & 0x0f;
        if (tmp != 0x0f)
        {
            delay(50);
            if (tmp != 0x0f)
            {
                switch (tmp)
                {
                case 0x07:k = 1; break;
                case 0x0b:k = 2; break;
                case 0x0d:k = 3; break;
                case 0x0e:k = 4; break;
                }
            }
        }
        while (P1 != 0x7f);
        P1 = 0xbf;
        tmp = P1;
        tmp = tmp & 0x0f;
        if (tmp != 0x0f)
        {
            delay(50);
            if (tmp != 0x0f)
            {
                switch (tmp)
                {
                case 0x07:k = 5; break;
                case 0x0b:k = 6; break;
                case 0x0d:k = 7; break;
                case 0x0e:k = 8; break;
                }
            }
        }
        while (P1 != 0xbf);
        P1 = 0xdf;
        tmp = P1;
        tmp = tmp & 0x0f;
        if (tmp != 0x0f)
        {
            delay(50);
            if (tmp != 0x0f)
            {
                switch (tmp)
                {
                case 0x07:k = 9; break;
                }
            }
        }
        while (P1 != 0xdf);
    }
    return k;
}

void main()
{
    uchar tmp;
    uchar i;
    LCD_zhiling(0x01);
    delay1(2000);
    initLCD();
    while (1)
    {
        for (i = 1; i <= 6; i++)
        {
            tmp = keyscan();
            shownum(2, i, arr1[tmp], 1);
            arr2[i - 1] = tmp;
        }
        while (qd);
        i = 0;
        while (i<6 && flag==0)
        {
            
            if (arr2[i] != mima[i])
            {
                flag = 1;
            }
            else
            {
                i++;
            }
        }
        if (flag == 0)
        {
            showstr(2,10,"Correct");
            break;
        }
        else
        {
            showstr(2,10,"error");
            delay1(30000);
            LCD_zhiling(0x01);
            delay(2000);
            initLCD();
        }
        
    }
    while(1);
}