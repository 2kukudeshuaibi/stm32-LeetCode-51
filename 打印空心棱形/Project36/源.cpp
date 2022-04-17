#define _CRT_SECURE_NO_WARNINGS 1
#include<string.h>
#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    char arr[100][100];
    int n = 0;
    int i = 0;
    int j = 0;

    while (scanf("%d", &n) != EOF)
    {
        for (i = 0; i < 100; i++)
        {
            for (j = 0; j < 100; j++)
            {
                arr[i][j] = ' ';
            }
        }
        for (i = 0; i < n; i++)
        {
            for (j = 0; j <= i; j++)
            {
                if (j == 0)
                {
                    arr[i][j] = '*';
                }
                if (j == i)
                {
                    arr[i][j] = '*';
                }
                if (i == n - 1)
                {
                    arr[i][j] = '*';
                }
            }
        }
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                printf("%c ", arr[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}