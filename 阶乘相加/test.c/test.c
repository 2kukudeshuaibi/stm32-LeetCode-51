#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
int main()
{
	int a = 0;
	int b = 0;
	scanf("%d", &b);
	int sum = 1;
	int c = 0;
	for (a = 1; a <= b; a++)
	{
		sum = sum * a;
		c = c + sum;
	}
	printf("%d\n", c);
	return 0;
}