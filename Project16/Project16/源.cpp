#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int x = 0;
	int n = 0;
	scanf("%d%d", &x, &n);
	int a = x + n;
	if (a <= 7)
	{
		printf("%d ", a);
	}
	if (a > 7)
	{
		if (a % 7 != 0)
		{
			printf("%d ", a % 7);
		}
		else
		{
			printf("%d ", 7);
		}
	}
	return 0;
}