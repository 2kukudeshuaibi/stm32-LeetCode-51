#include <stdio.h>
#include <stdbool.h>


void swap(char* p1, char* p2,int wit)
{
	char tmp = 0;
	int i = 0;
	for (i = 0; i < wit; i++)
	{
		tmp = *p1;
		*p1 = *p2;
		*p2 = tmp;
		p1++;
		p2++;
	}
}


int cmp(const void* p1, const void* p2)
{
	return *(int*)p1 - *(int*)p2;
}

void my_qsort(void* base, int numsize, int wit, int(*cmp)(const void*, const void*))
{
	int i = 0;
	int j = 0;
	for (i = 0; i < numsize - 1; i++)
	{
		for (j = 0; j < numsize - 1 - i; j++)
		{
			if (cmp((char*)base+j*wit,(char*)base+(j+1)*wit)>0)
			{
				swap((char*)base + j * wit, (char*)base + (j + 1) * wit, wit);
			}
		}
	}
}

int fun1(int* arr, int n)
{
	int i = 0;
	int j = 0;
	int tmp = 0;
	int count = 0;
	for (i = 0; i < n; i++)
	{
		tmp = arr[i] + 1;
		
		for (j = 0; j < n; j++)
		{
			if (tmp == arr[j])
				count++;
		}
	}

	return count;
}

int fun2(int* arr, int n)
{
	int count = 0;
	int i = 0;
	my_qsort(arr, n, sizeof(int), cmp);
	int num = 1;
	for (i = 0; i < n; i++)
	{
		if (arr[i] != arr[i - 1])
		{
			if (arr[i - 1] + 1 == arr[i])
				count += num;
			num = 1;
		}
		else
		{
			num++;
		}
	}

	return count;
}




int main()
{
	int arr[] = { 1,2,3 };
	
	

	printf("%d", fun2(arr, sizeof(arr) / sizeof(int)));
	return 0;
}