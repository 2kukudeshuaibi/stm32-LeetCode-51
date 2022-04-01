#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
    int num = 0;
    scanf("%d", &num);
    int day = 1;
    int i = 0;
    int j = 0;
    int sum = 0;
    for (i = 1; day <= num; i++)
    {
        for (j = 1; j <= i; j++)
        {
            if (day > num)
            {
                break;
            }
            sum = sum + i;
            day++;
        }
    }
    printf("%d", sum);
    return 0;
}