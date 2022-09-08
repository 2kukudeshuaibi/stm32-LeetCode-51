#include <stdio.h>
#include <string.h>
#include <ctype.h>


#if 1
float fun(int m,int n)
{
	int i = 0;
	int sum1 = 1;
	int sum2 = 1;
	int sum3 = 1;
	float res = 0;

	for (i = 1; i <= m; i++)
	{
		sum1 = sum1 * i;
	}
	for (i = 1; i <= n; i++)
	{
		sum2 = sum2 * i;
	}
	for (i = 1; i <= m-n; i++)
	{
		sum3 = sum3 * i;
	}
	res = sum1 / (sum2 * sum3);



	return res;
}

#endif

int main()
{
	float a = fun(12, 8);
	printf("%.2f\n", a);
	return 0;
}