#define _CRT_SECURE_NO_WARNINGS 1


#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>




int Partsort1(int* a, int left, int right);

void PrintInsort(int* arr, int n)//打印数组
{
	int i = 0;

	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}


void InsertSort(int* a, int n)//插入排序
{
	int i = 0;
	int end = 0;
	for (i = 0; i < n - 1; i++)
	{
		end = i;
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


void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap)
	{
		gap /= 2;
		int i = 0;
		int end = 0;
		for (i = 0; i < n - gap; i++)
		{
			end = i;
			int tmp = a[end + gap];
			while (end>=0)
			{
				if (a[end] > tmp)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
}

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void AdJustDwon(int* a, int n, int root)
{
	int parent = root;
	int chiled = parent * 2 + 1;

	while (chiled<n)
	{
		if (chiled + 1 < n && a[chiled + 1] > a[chiled])
		{
			chiled++;
		}

		if (a[chiled] > a[parent])
		{
			Swap(&a[parent], &a[chiled]);
			parent = chiled;
			chiled = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapSort(int* a, int n)
{
	int i = (n - 2) / 2;
	for (i; i >= 0; i--)
	{
		AdJustDwon(a, n, i);
	}


	int end = n - 1;
	while (end >= 0)
	{
		Swap(&a[0], &a[end]);
		AdJustDwon(a, end, 0);
		end--;
	}

}

void bubblesort(int* a, int n)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - 1 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				Swap(&a[j+1], &a[j]);
			}
		}
	}
}



void Selectsort(int* a, int n)
{
	int begin = 0;
	int end = n - 1;
	int min = 0;
	int max = 0;
	while (begin < end)
	{
		min = begin;
		max = begin;
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
		Swap(&a[begin], &a[min]);
		if (begin==max)
		{
			max = min;
		}
		Swap(&a[max], &a[end]);
		begin++;
		end--;
	}
}


int GetMid(int* a, int left, int right)
{
	int mid = (left + right) / 2;
	if (a[mid] > a[left])
	{
		if (a[mid] < a[right])
		{
			return mid;
		}
		else if (a[left]>a[right])
		{
			return left;
		}
		else
		{
			return right;
		}

	}
	else
	{
		if (a[mid] > a[right])
		{
			return mid;
		}
		else if (a[right] > a[left])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
}



void Quicksort(int* a, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	
	int pit = Partsort3(a, left, right);


	Quicksort(a, left, pit - 1);
	Quicksort(a, pit + 1, right);

}

int Partsort1(int* a, int left, int right)
{
	int mid = GetMid(a, left, right);
	Swap(&a[left], &a[mid]);


	int begin = left;
	int end = right;
	int pit = begin;
	int key = a[pit];
	while (begin < end)
	{
		while (begin < end && a[end] >= key)
		{
			end--;
		}
		a[pit] = a[end];
		pit = end;
		while (begin < end && a[begin] <= key)
		{
			begin++;
		}
		a[pit] = a[begin];
		pit = begin;
	}
	a[begin] = key;
	pit = begin;

	return pit;
}
int Partsort2(int* a, int left, int right)
{
	int mid = GetMid(a, left, right);
	Swap(&a[left], &a[mid]);


	int begin = left;
	int end = right;
	int key = begin;

	while (begin < end)
	{
		while (begin < end && a[end] >= a[key])
		{
			end--;
		}

		while (begin < end && a[begin] <= a[key])
		{
			begin++;
		}
		Swap(&a[begin], &a[end]);
	}
	Swap(&a[begin], &a[key]);
	return begin;
}
int Partsort3(int* a, int left, int right)
{
	
	int prev = left;
	int cur = left + 1;
	int key = left;

	while (cur <= right)
	{
		if (a[cur] < a[key] && ++prev != cur)
		{
			Swap(&a[cur], &a[prev]);
		}
		cur++;
	}
	Swap(&a[prev], &a[key]);

	return prev;
}



void _Merge(int* a, int left, int right, int* tmp)
{
	if (left >= right)
	{
		return;
	}

	int mid = (left + right) / 2;

	_Merge(a, left, mid, tmp);
	_Merge(a, mid+1, right, tmp);


	int begin1 = left;
	int end1 = mid;

	int begin2 = mid + 1;
	int end2 = right;


	int index = left;
	while ((begin1 <= end1) && (begin2 <= end2))
	{
		if (a[begin1] < a[begin2])
		{
			tmp[index] = a[begin1];
			index++;
			begin1++;
		}
		else
		{
			tmp[index] = a[begin2];
			index++;
			begin2++;
		}
	}

	while (begin1 <= end1)
	{
		tmp[index] = a[begin1];
		index++;
		begin1++;
	}

	while (begin2 <= end2)
	{
		tmp[index] = a[begin2];
		index++;
		begin2++;
	}

	for (int i = left; i <= right; i++)
	{
		a[i] = tmp[i];
	}

}

void Merge(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int)*n);



	_Merge(a, 0, n - 1, tmp);
	free(tmp);
	tmp = NULL;
}



void Test()
{
	int arr[] = { 3,4,1,5,0,9,6,8,2,7 };
	int arr1[] = { 9,8,7,6,5,4,3,2,1,0 };
	int size = sizeof(arr) / sizeof(int);
	//Quicksort(arr, 0, size - 1);
	Merge(arr, size);
	PrintInsort(arr, size);

}


int main()
{
	Test();
	return 0;
}