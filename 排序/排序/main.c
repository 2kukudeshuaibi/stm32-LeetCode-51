#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void PrintInsort(int* arr, int n)//��ӡ����
{
	int i = 0;

	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}


void InsertSort(int* a, int n)//��������
{
	int i = 0;
	for (i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (a[end] < tmp)
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

void ShellSort(int* a, int n)//ϣ������
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

//�ѵĴ���
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





void bubblesort(int* a, int n)//ð������
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


void Selectsort(int* a, int n)//ѡ������
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



void Quicksort(int* a, int left, int right)//��������
{
	if (right <= left)
	{
		return;
	}
	int begin = left;
	int end = right;
	int pivot = begin;
	int key = a[begin];
	while (begin < end)
	{
		//������С
		while (begin < end && a[end] >= key)
		{
			end--;
		}
		a[pivot] = a[end];//�ҵ��� ��С�ķŽ���
		pivot = end;//ˢ�¿�

		//�����Ҵ�
		while (begin < end && a[begin] <= key)
		{
			begin++;
		}
		a[pivot] = a[begin];//�ҵ��� �Ѵ�ķŽ���
		pivot = begin;//ˢ�¿�
	}
	pivot = begin;
	a[pivot] = key;
	Quicksort(a,left, pivot-1);
	Quicksort(a,pivot + 1, right);
}




void TestHeapsort()
{
	int arr[] = { 3,5,1,2,8,4,9,7,6,0 };
	int arr1[] = { 0,1,2,3,4,5,6,7,8,9 };
	Quicksort(arr,0, sizeof(arr) / sizeof(int)-1);
	PrintInsort(arr, sizeof(arr) / sizeof(int));
}

int main()
{
	TestHeapsort();
	return 0;
}