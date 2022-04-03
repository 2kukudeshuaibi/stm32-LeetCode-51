#include<stdio.h>
int main()
{
    int n = 0;
    int arr[1000] = { 0 };
    int i = 0;

    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < n; i++)
    {
        int j = 0;
        for (j = 0; j < n - i; j++)
        {
            int tmp = 0;
            if (arr[j] > arr[j + 1])
            {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
    int ch = arr[n - 1] - arr[0];
    printf("%d", ch);
    return 0;
}