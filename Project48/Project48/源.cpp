#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

int main()
{
    int left = 0;
    int right = 0;
    scanf("%d %d", &left, &right);
    int i = 0;
    for (i = left; i <= right; i++)
    {
        int a = i;
        int sum = 0;
        while (a)
        {
            sum = sum + pow(a % 10, 4);
            a /= 10;
        }
        if (sum == i)
        {
            printf("%d ", i);
        }

    }
    return 0;
}