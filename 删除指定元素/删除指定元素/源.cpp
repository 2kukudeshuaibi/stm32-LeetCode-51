#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int n = 0;
    scanf("%d", &n);
    int i = 0;
    int arr[100] = { 0 };
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int m = 0;
    int count = 0;
    scanf("%d", &m);
    for (i = 0; i < n; i++)
    {
        if (arr[i] == m)
        {
            int k = 0;
            for (k = i; k < n - 1; k++)
            {
                arr[k] = arr[k + 1];
            }
            i--;
            n--;
        }
    }
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}