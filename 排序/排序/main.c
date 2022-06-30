#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


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
	for (i = 0; i < n - 1; i++)
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

void ShellSort(int* a, int n)//希尔排序
{
	int gap = n;
	while (gap > 1)
	{
		    gap /= 2;
			int i = 0;
			for (i = 0; i < n - gap; i++)
			{
				int end = i;
				int tmp = a[end + gap];
				while (end >= 0)
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

//堆的创建
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
	while (chiled < n)
	{
		if ((chiled + 1 < n) && a[chiled + 1] < a[chiled])
		{
			chiled += 1;
		}
		if (a[chiled] < a[parent])
		{
			Swap(&a[chiled], &a[parent]);
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
	int i = (n - 1 - 1) / 2;
	for (i; i >= 0; i--)
	{
		AdJustDwon(a, n, i);
	}
	int end = n - 1;
	int c = 0;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdJustDwon(a, end,0);
		end--;
	}
}





void bubblesort(int* a, int n)//冒泡排序
{
	int i = 0;
	int j = 0;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - 1 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				Swap(&a[j], &a[j + 1]);
			}
		}
	}
}


void Selectsort(int* a, int n)//选择排序
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
		Swap(&a[min], &a[end]);
		begin++;
		end--;
	}
}


int GetMid(int* a, int left, int right)//三数取中
{
	int mid = (left + right) / 2;
	if (a[mid] > a[left])
	{
		if (a[left] > a[right])
		{
			return left;
		}
		else if (a[mid] < a[right])
		{
			return mid;
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
		else if (a[left] < a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
}

void Quicksort(int* a, int left, int right)//快速排序
{
	if (right <= left)
	{
		return;
	}
	
	int pivot = Partsort3(a, left, right);

	//[left,right]
	//[left,pivot-1] pivot [pivot+1,right]

	if (pivot - 1 - left > 10)
	{
		Quicksort(a, left, pivot - 1);
	}
	else
	{
		InsertSort(a + left, pivot - 1 - left + 1);
	}
	if (right - pivot - 1 > 10)
	{
		Quicksort(a, pivot + 1, right);
	}
	else
	{
		InsertSort(a + pivot + 1, right - pivot - 1 + 1);
	}
}

int Partsort1(int* a, int left, int right)//挖坑法
{
	int mid = GetMid(a, left, right);


	Swap(&a[left], &a[mid]);

	int begin = left;
	int end = right;
	int pivot = begin;
	int key = a[begin];
	while (begin < end)
	{
		//从右找小
		while (begin < end && a[end] >= key)
		{
			end--;
		}
		a[pivot] = a[end];//找到了 把小的放进坑
		pivot = end;//刷新坑

		//从左找大
		while (begin < end && a[begin] <= key)
		{
			begin++;
		}
		a[pivot] = a[begin];//找到了 把大的放进坑
		pivot = begin;//刷新坑
	}
	pivot = begin;
	a[pivot] = key;


	return pivot;
}



int Partsort2(int* a, int left, int right)//左右指针
{
	int mid = GetMid(a, left, right);
	Swap(&a[left], &a[mid]);

	int begin = left;
	int end = right;
	int keyi = begin;
	while (begin < end)
	{
		while ((begin < end) && (a[end] >= a[keyi]))
		{
			end--;
		}

		while ((begin < end) && (a[begin] <= a[keyi]))
		{
			begin++;
		}

		Swap(&a[begin], &a[end]);

	}
	Swap(&a[begin], &a[keyi]);

	return begin;
}


int Partsort3(int* a, int left, int right)//前后指针
{
	int key = left;
	int prev = left;
	int cur = left + 1;
	while (cur <= right)
	{
		if (a[cur] < a[key] && ++prev!=cur)
		{
			
			Swap(&a[cur],&a[prev]);
		}
		cur++;
		
	}
	Swap(&a[key], &a[prev]);
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
	_Merge(a, mid + 1, right, tmp);



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
	int* tmp = (int*)malloc(sizeof(int) * n);
	_Merge(a, 0, n - 1, tmp);
	int i = 0;
	/*for (i = 0; i < n; i++)
	{
		a[i] = tmp[i];
	}*/
	free(tmp);
	tmp = NULL;

}


void TestHeapsort()
{
	
	int arr[] = { 3,5,1,2,8,4,9,7,6,0 };
	int arr1[] = { 0,1,2,3,4,5,6,7,8,9 };
	//Quicksort(arr,0, sizeof(arr) / sizeof(int)-1);
	Merge(arr, sizeof(arr) / sizeof(int));
	PrintInsort(arr, sizeof(arr) / sizeof(int));
}

int main()
{
	TestHeapsort();
	
	
	
	int i = 0;
	
	return 0;
}
