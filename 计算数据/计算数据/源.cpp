#include <stdio.h>


int fun(int x[],int e,int* sum)
{
	int tmp = 0;
	int count = 0;
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		if (x[i] % e == 0)
		{
			count++;
		}
		else
		{
			tmp += x[i];
		}
	}
	*sum = tmp;
	return count;
}

int main()
{
	
	int x[10] = { 1,7,8,6,10,15,11,13,29,31 };
	int sum = 0;
	int a=fun(x, 3, &sum);
	printf("%d %d ", a, sum);
	return 0;
}