#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int main()
{
	int a = 0;
	printf("������Ҫ���ҵ���\n");
	scanf("%d", &a);
	int b = 0;
	int count = 0;
	for (b = 0; b < 32; b++)
	{
		if ((a>>b & 1) == 1)
		{
			count++;
		}
	}
	printf("�ܹ���: %d ��һ \n", count);
	return 0;
}