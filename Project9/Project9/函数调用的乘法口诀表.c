#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
void p_kou(int* pa)
{
	int i = 0;
	for (i = 1; i <= *pa; i++)
	{
		int b = 0;
		for (b = 1; b <= i; b++)
		{
			printf("%d*%d=%-2d ", i, b, i * b);
		}printf("\n");
	}
}
int main()
{
	int a = 0;
	printf("请输入数字为您生成相应的乘法口诀表：");
	scanf("%d", &a);
	p_kou(&a);
	return 0;
}