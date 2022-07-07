#define _CRT_SECURE_NO_WARNINGS 1
#include <math.h>
#include <stdio.h>


int Prinme(int num)
{
	int i = 0;
	for (i = 2; i < num; i++)
	{
		if (num % i == 0)
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
	int num = 0;
	printf("请输入\n");
	while (scanf("%d", &num) != EOF)
	{
		int flag = Prinme(num);
		if (flag == 1)
		{
			printf("%d是素数\n", num);
		}
		else
		{
			printf("%d不是素数\n", num);
		}
	}
	return 0;
}