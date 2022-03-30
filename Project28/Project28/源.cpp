#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string>
#include<string.h>
#include<stdio.h>
int main()
{
	char arr[13];
	scanf("%s", arr);
	int i, j;
	int s = 0;
	for (i = 0, j = 1; i < 11; i++)
	{
		if (arr[i] != '-')
		{
			s += (arr[i] - '0') * j;
			j++;
		}
	}
	int m = s % 11;
	if (arr[12] == 'X' && m == 10)
	{
		printf("Right");
	}
	else
	{
		if (m == arr[12] - '0')
		{
			printf("Right");
		}
		else
		{
			for (int n = 0; n < 12; n++)
			{
				printf("%c", arr[n]);
			}
			if (m == 10)
			{
				printf("X");
			}
			else
			{
				printf("%d", m);
			}
		}
	}
	return 0;
}