#define _CRT_SECURE_NO_WARNINGS 1
#include <math.h>
#include <stdio.h>


void print_shuzu(int* arr, int len)
{
	int i = 0;
	for (i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void bubble(int* arr, int len)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < len - 1; i++)
	{
		for (j = 0; j < len - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				Swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}

void InsertSort(int* a, int n)
{
	int i = 0;
	for (i = 0; i < n-1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}
			
		}
		a[end + 1] = tmp;
	}
}

int main()
{
	int arr[] = { 2,5,1,7,3,9,0,4,6,8 };
	print_shuzu(arr, sizeof(arr) / sizeof(arr[0]));

	//bubble(arr, sizeof(arr) / sizeof(arr[0]));
	InsertSort(arr, sizeof(arr) / sizeof(arr[0]));
	print_shuzu(arr, sizeof(arr) / sizeof(arr[0]));

	return 0;
}