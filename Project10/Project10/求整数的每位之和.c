#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
int digitsum(int a)
{
	if (a > 9)
	{
		int c = a % 10;
		return c + digitsum(a / 10);
	}
	else
		return a;
}
int main()
{
	int b = 0;
	scanf("%d", &b);
	int c = digitsum(b);
	printf("%d ", c);
	return 0;
}