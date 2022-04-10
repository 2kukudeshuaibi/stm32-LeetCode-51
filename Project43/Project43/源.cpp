#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int comp(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}

void smp(char* b1, char* b2,int wit)
{
	int i = 0;
	for (i = 0; i < wit; i++)
	{
		char tmp = 0;
		tmp = *b1;
		*b1 = *b2;
		*b2 = tmp;
		b1++;
		b2++;
	}
}


void print_f(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}
void bubble_sort(void* base, int sz, int wit, int (*cmp)(const void*, const void*))
{
	int i = 0;
	int j = 0;
	for (i = 0; i < sz - 1; i++)
	{
		for (j = 0; j < sz - 1 - i; j++)
		{
			if (comp((char*)base + j * wit, (char*)base + (j + 1) * wit) > 0)
			{
				smp((char*)base + j * wit, (char*)base + (j + 1) * wit,wit);
			}
		}
	}
}



void test()
{
	int arr[] = { 1,3,5,7,9,2,4,6,8,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr,sz,sizeof(arr[0]),comp);
	print_f(arr,sz);
}
int main()
{
	test();
	return 0;
}