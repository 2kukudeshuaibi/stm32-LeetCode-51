#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<ctype.h>
int shu(int t, int u)
{
    int count = 0;
    int i = 0;
    int sum = 0;
    for (i = t; i <= u; i++)
    {
        int a = i;
        while (a)
        {
            sum = a % 10;
            if (sum == 2)
            {
                count++;
            }
            a /= 10;
        }
    }
    return count;
}

int main()
{
    int x = 0;
    int y = 0;
    scanf("%d %d", &x, &y);
    int sum = shu(x, y);
    printf("%d", sum);
    return 0;
}