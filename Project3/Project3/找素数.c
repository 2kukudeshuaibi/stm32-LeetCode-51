#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
int main()
{
	int a = 0;
	int b = 0;
	for (a = 100; a <= 200; a++)
	{
		for (b = 2; b <= a - 1; b++)
		{
			if (a % b == 0)
			{
				break;
			}
		}
		if (a == b)
		{
			printf("%d ", a);
		}

	}
	return 0;
}