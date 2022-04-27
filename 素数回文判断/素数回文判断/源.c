#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
long long bianhui(long long num)
{
    long long a = num;
    while (a > 9)
    {
        a /= 10;
        num = (num * 10 + a % 10);
    }
    return num;
}

int issushu(long long a)
{
    int i = 0;
    int tmp = sqrt(a);
    for (i = 2; i <= tmp; i++)
    {
        if (a % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    long long num = 0;
    scanf("%lld", &num);
    long long tmp = bianhui(num);
    if (issushu(tmp))
    {
        printf("prime\n");
    }
    else
    {
        printf("noprime\n");
    }
    return 0;
}