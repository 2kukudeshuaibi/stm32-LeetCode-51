#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
    int n = 0;
    int h = 0;
    int m = 0;
    int c = 0;
    scanf("%d %d %d", &n, &h, &m);
    c = m % h+m/h;
    printf("%d", n - c);
    return 0;
}