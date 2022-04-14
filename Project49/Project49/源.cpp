#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

void find_num(int arr[3][3], int* r, int* c, int k)
{
	int x = 0;
	int y = *c - 1;
	while (x < *r && y >= 0)
	{
		if (arr[x][y] > k)
		{
			y--;
		}
		else if (arr[x][y] < k)
		{
			x++;
		}
		else
		{
			*r = x;
			*c = y;
		}
	}
}

int main()
{
	int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
	int k = 7;
	int x = 3;
	int y = 3;
	find_num(arr, &x, &y, k);
	if (x == 3 && y == 3)
	{
		printf("找不到\n");
	}
	else
	{
		printf("坐标是：%d %d\n", x, y);
	}
	return 0;
}