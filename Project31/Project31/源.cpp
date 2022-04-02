#define _CRT_SECURE_NO_WARNINGS 1
#include<string.h>
#include<iostream>
#include<stdio.h>
#include<stdio.h>
int main()
{
    int n = 0;
    int i = 0;
    int j = 0;
    int a = 0;
    int b = 0;
    while (scanf("%d", &n) != EOF)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n - i; j++)
            {
                printf(" ");
            }
            for (a = 0; a <= i; a++)
            {
                printf("* ");
            }printf("\n");
        }
        if (i + 1 == n + 1)
        {
            for (j = 0; j <= n; j++)
            {
                printf("* ");
            }printf("\n");
        }
        for (i = 0; i < n; i++)
        {
            for (j = 0; j <= i; j++)
            {
                printf(" ");
            }
            for (a = 0; a < n - i; a++)
            {
                printf("* ");
            }
            printf("\n");
        }
    }
    return 0;
}