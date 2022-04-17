#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int find_yue(int a, int b)
{
    int min = 0;
    if (a < b)
    {
        min = a;
    }
    else
    {
        min = b;
    }
    while (1)
    {
        if (a % min == 0 && b % min == 0)
        {
            break;
        }
        min--;
    }
    return min;
}
int find_bei(int a, int b)
{
    int max = a + b;
    while (1)
    {
        if (max % a == 0 && max % b == 0)
        {
            break;
        }
        max++;
    }
    return max;
}
int main()
{
    int a = 0;
    int b = 0;
    scanf("%d %d", &a, &b);
    int yue =find_yue(a, b);
    int bei = find_bei(a, b);
    printf("%d", yue+bei);
    return 0;
}