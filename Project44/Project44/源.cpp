#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int n = 0;
	scanf("%d", &n);
	int arr[4][4] = { 0 };
	int a = 0;
	int b = n - 1;
	int i = 0;
	int j = 0;
	int count = 0;
	while (count < n * n)
	{
		for (i = a; i <= b; i++)
		{
			arr[a][i] = ++count;
		}
		for (i = a + 1; i <= b; i++)
		{
			arr[i][b] = ++count;
		}
		for (i = b-1; i >= a; i--)
		{
			arr[b][i] = ++count;
		}
		for (i = b - 1; i >= a + 1; i--)
		{
			arr[i][a] = ++count;
		}
		a++;
		b--;
	}
	for (i = 0; i < n; i++)
	{

		for (j = 0; j < n; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}