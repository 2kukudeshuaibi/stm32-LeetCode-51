#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int camp(const void* b1, const void* b2)
{
    return *(int*)b1 - *(int*)b2;
}
int main() {
    int n = 0;
    int m = 0;
    scanf("%d %d", &n, &m);
    int sum = 0;
    sum = n + m;
    int i = 0;
    int count = 0;
    int arr1[100] = { 0 };
    int arr2[100] = { 0 };
    int arr3[200] = { 0 };
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr1[i]);
    }
    for (i = 0; i < m; i++)
    {
        scanf("%d", &arr2[i]);
    }
    for (i = 0; i < n; i++)
    {
        arr3[i] = arr1[i];
    }
    for (i = n; i < sum; i++)
    {

        arr3[i] = arr2[count];
        count++;
    }
    qsort(arr3, sum, 4, camp);
    for (i = 0; i < sum; i++)
    {
        printf("%d ", arr3[i]);
    }
    return 0;
}