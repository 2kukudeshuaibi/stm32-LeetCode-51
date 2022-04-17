#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string>
#include<assert.h>
int main()
{
	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
	int c = a ^ b;
	int i = 0;
	int count = 0;
	for (i = 0; i < 32; i++)
	{
		if ((c >> &1) == 1)
		{
			count++;
		}
	}
	printf("%d", count);
	return 0;
}