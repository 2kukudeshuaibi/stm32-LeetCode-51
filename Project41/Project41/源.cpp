#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int main()
{
    int n = 0;
    scanf("%d", &n);
    int arr1[1001] = { 0 };
    int arr2[1001] = { 0 };
    int i = 0;
    int j = 0;
    int sum = 0;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr1[i]);
    }
    for (i = 0; i < n; i++)
    {
        int count = 0;
        for (j = 0; j < n; j++)
        {
            if (arr1[i] == arr2[j])
            {
                count++;
                sum++;
            }
        }
        if (count == 0)
        {
            arr2[i] = arr1[i];
        }
    }
    for (i = 0; i < n; i++)
    {
        if (arr2[i] != 0)
        {
            printf("%d ", arr2[i]);
        }
    }
    return 0;
}