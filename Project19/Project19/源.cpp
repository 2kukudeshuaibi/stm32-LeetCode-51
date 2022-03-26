#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
int main()
{
    int hour = 0;
    int minute = 0;
    int m = 0;
    scanf("%d:%d %d", &hour, &minute, &m);
    int h = ((m / 60)+hour)%24;
    int f = (m % 60)+minute;
    
    if (f >= 60)
    {
        h=h + 1;
        f=f - 60;
    }
   
    printf("%02d:%02d", h, f);
    return 0;
}