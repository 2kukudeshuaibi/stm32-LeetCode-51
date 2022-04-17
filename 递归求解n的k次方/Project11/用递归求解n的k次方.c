#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
int Pow(int a, int b)
{
	if (b == 0)
	{
		return 1;
	}
	else if (b == 1)
	{
		return a;
	}
	else
	{
		return a * Pow(a, b - 1);
	}

}
int main()
{
	int n = 0;
	int k = 0;
	scanf("%d %d", &n, &k);
	int ret = Pow(n, k);
	printf("%d ", ret);
	return 0;
}