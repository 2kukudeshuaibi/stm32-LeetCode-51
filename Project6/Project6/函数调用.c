#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
void big_xiao(int* max, int* mid, int* x)
{
	if (*max < *mid)
	{
		int d = *max;
		*max = *mid;
		*mid = d;
	}
	if (*max < *x)
	{
		int d = *max;
		*max = *x;
		*x = d;
	}
	if (*mid < *x)
	{
		int d = *mid;
		*mid = *x;
		*x = d;
	}

}
int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	scanf("%d%d%d", &a, &b, &c);
	big_xiao(&a, &b, &c);
	printf("%d %d %d", a, b, c);
	return 0;
}