#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
void Init(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		arr[i] = 0;
	}
}
void print(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)

	{
		printf("%d ", arr[i]);
	}printf("\n");
}
void reverse(int arr[], int sz)
{
	int a = 0;
	int b = sz - 1;
	int i = 0;
	for (a = 0; a < b; a++, b--)
	{
		i = arr[a];
		arr[a] = arr[b];
		arr[b] = i;
	}
}
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	print(arr, sz);
	reverse(arr, sz);
	print(arr, sz);
	Init(arr, sz);
	print(arr, sz);
	return 0;
}