#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<iostream>
int main()
{
    int ch = 0;
    while (ch >= 0 && ch <= 100)
    {
        scanf("%d", &ch);
        if (ch >= 60)
        {
            printf("Pass\n");
        }
        else
        {
            printf("Fail\n");
        }
    }
    return 0;
}