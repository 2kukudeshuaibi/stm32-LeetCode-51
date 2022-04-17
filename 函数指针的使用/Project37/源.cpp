#define _CRT_SECURE_NO_WARNINGS 1
#include<string.h>
#include<stdio.h>
#include<iostream>
#include<math.h>
#include<stdio.h>
int main()
{
    int n = 0;
    scanf("%d", &n);
    int arr[100] = { 0 };
    int i = 0;
    int j = 0;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            int tmp = 0;
            if (arr[j] < arr[j + 1])
            {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
    for (i = 0; i <= 4; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}