#define _CRT_SECURE_NO_WARNINGS 1
#include<string.h>
#include<iostream>
#include<stdio.h>
#include<stdio.h>
#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int i = 0;
	int j = 0;
	for (i = 0; i <= 100000; i++)
	{
		int count = 0;
		int a = i;
		while (a)
		{
			count++;
			a /= 10;
		}
		int sum = 0;
		int b = i;
		for (j = 0; j < count; j++)
		{
			int w = 0;
			w = b % 10;
			sum = sum + pow(w, count);
			b /= 10;
		}
		if (sum == i)
		{
			printf("%d ", i);
		}
	}
	return 0;
}