#include <reg51.h>
#include <intrins.h>
sbit s1 = P3 ^ 1;
sbit s2 = P3 ^ 0;
sbit s3 = P3 ^ 2;
sbit s4 = P3 ^ 3;

void delay(unsigned int i);//延时函数声明;

void main()
{
    while (1)
    {
        if (s1 == 0)//第一种模式
        {
            while (1)
            {
                P2 = 0x00;
                if (s2 == 0 || s3 == 0 || s4 == 0)
                {
                    break;
                }
            }
        }
        if (s2 == 0)//第二种模式
        {
            while (1)
            {
                P2 = 0xaa;
                delay(5000);
                P2 = 0x55;
                delay(5000);
                if (s1 == 0 || s3 == 0 || s4 == 0)
                {
                    break;
                }
            }
        }
        if (s3 == 0)
        {
            while (1)
            {
                P2 = 0x0f;
                if (s1 == 0 || s2 == 0 || s4 == 0)
                {
                    break;
                }
            }
        }
        if (s4 == 0)
        {
            while (1)
            {
                P2 = 0xf0;
                if (s1 == 0 || s2 == 0 || s3 == 0)
                {
                    break;
                }
            }
        }
    }
}


void delay(unsigned int i)
{
    unsigned int k;
    for (k = 0; k < i; k++);
}