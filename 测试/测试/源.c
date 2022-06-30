#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>



void Print(int* a, int n)
{
    int i = 0;
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}



void QuSort(int* a, int left, int right)
{
    if (left >= right)
    {
        return;
    }
    int begin = left;
    int end = right;
    int pit = begin;
    int key = a[pit];
    while (begin < end)
    {
        while (begin < end && a[end] <= key)
        {
            end--;
        }
        a[pit] = a[end];
        pit = end;
            
        while (begin < end && a[begin] >= key)
        {
            begin++;
        }
        a[pit] = a[begin];
        pit = begin;
    }
    pit = begin;
    a[pit] = key;
    QuSort(a, left, pit - 1);
    QuSort(a, pit + 1, right);
}



int main()
{
   /* int arr[] = { 2,6,1,7,3,5,0,9,7,8,4 };
    Print(arr, sizeof(arr) / sizeof(arr[0]));
    QuSort(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);
    Print(arr, sizeof(arr) / sizeof(arr[0]));*/






    int i = 0;
    int j = 0;
    for (i = 1; i <= 9; i++)
    {
        for (j = 1; j <= i; j++)
        {
            printf("%2d*%2d=%2d ", i, j, i * j);
        }
        printf("\n");

    }
    return 0;
}
