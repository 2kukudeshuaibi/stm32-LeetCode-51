#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}



void PrintInsort(int* arr, int n)//´òÓ¡Êý×é
{
	int i = 0;

	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void Selectsort(int* a, int n)
{
	int begin = 0;
	int end = n - 1;
	while (begin < end)
	{
		int min = begin;
		int max = begin;
		for (int i = begin; i <= end; i++)
		{
			if (a[i] < a[min])
			{
				min = i;
			}
			if (a[i] > a[max])
			{
				max = i;
			}
		}

		Swap(&a[begin], &a[max]);
		if (begin == min)
		{
			min = max;
		}
		Swap(&a[min], &a[end]);
		begin++;
		end--;
	}
}


void TestHeapsort()
{
	int arr[] = { 3,5,1,2,8,4,9,7,6,0 };
	int arr1[] = { 0,1,2,3,4,5,6,7,8,9 };
	Selectsort(arr1, sizeof(arr1) / sizeof(int));
	PrintInsort(arr1, sizeof(arr1) / sizeof(int));
}

int main()
{
	TestHeapsort();
	return 0;
}