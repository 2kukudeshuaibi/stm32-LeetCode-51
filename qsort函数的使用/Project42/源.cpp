#define _CRT_SECURE_NO_WARNINGS 1
#include<string.h>
#include<stdio.h>
#include<iostream>
#include<math.h>
#include<stdlib.h>
int cmp_int(const void* e1, const void* e2)
{
	return *(int*)e2 - *(int*)e1;
}

void print_t(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void test1()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	print_t(arr, sz);
	qsort(arr, sz, sizeof(arr[0]), cmp_int);
	print_t(arr, sz);
}

struct stu
{
	char name[20];
	int age;
};

int str_age(const void* e1, const void* e2)
{
	return ((struct stu*)e1)->age - ((struct stu*)e2)->age;
}

int str_name(const void* e1, const void* e2)
{
	return strcmp(((struct stu*)e1)->name, ((struct stu*)e2)->name);
}

void print1(struct stu* s, int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf(" %s %d ", s[i].name, s[i].age);
	}
	printf("\n");
}


void test2()
{
	struct stu s[] = { {"zhangsan",30},{"lisi",34},{"wangwu",20} };
	int sz = sizeof(s) / sizeof(s[0]);
	print1(s, sz);
	qsort(s, sz, sizeof(s[0]), str_age);
	print1(s, sz);

	qsort(s, sz, sizeof(s[0]), str_name);
	print1(s, sz);
}



int main()
{
	test1();
	test2();
	return 0;
}