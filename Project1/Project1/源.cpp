#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
int main()
{
	int a = 0;
	int b = 0;
	int c = 1;
	scanf("%d", &b);
	for (a = 1; a <= b; a++)
	{
		c = c * a;
	}
	printf("%d ", c);
	return 0;
}