#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
int two_find(int a[], int k, int s)
{
	int left = 0;
	int right = s - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (a[mid] < k)
		{
			left = mid++;
		}
		else if (a[mid] > k)
		{
			right = mid--;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int key = 7;
	int sz = sizeof(arr) / sizeof(arr[0]);
	int ret = two_find(arr, key, sz);
	if (-1 == ret)
	{
		printf("找不到");
	}
	else
	{
		printf("找到了： ret=%d\n", ret);
	}
	return 0;
}
