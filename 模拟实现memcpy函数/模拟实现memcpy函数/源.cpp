#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<ctype.h>

void* my_memcpy(void* b1, const void* b2, int wit)
{
	void* ret = b1;
	int i = 0;
	for (i = 0; i < wit; i++)
	{
		*(char*)b1 = *(char*)b2;
		b1 = (char*)b1 + 1;
		b2 = (char*)b2 + 1;
	}
	return ret;
}

int main()
{
	int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int arr2[10] = { 0 };

	my_memcpy(arr2, arr1, 20);

	return 0;
}