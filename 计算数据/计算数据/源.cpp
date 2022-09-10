#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

struct mpow
{
	double a;
	int b;
};


double fun(struct mpow* arr,int n)
{
	double sum = 0;
	int i = 0;
	for (i = 0; i < n; i++)
	{
		sum+=pow(arr[i].a, arr[i].b);
	}
	return sum;
}


int main()
{
	int tmp = 0;
	struct mpow arr[4] = { 12,0,9,2,23,1,7,2 };
	printf("%lf", fun(arr, 4));
	return 0;
}