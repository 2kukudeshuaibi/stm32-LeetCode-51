#include<stdio.h>
int add(int x, int y)
{
	return x + y;
}
int sub(int x, int y)
{
	return x - y;
}

int main()
{
	int(*arr[2])(int, int) = { add,sub };
	//arr���Ǻ���ָ������ - �����ŵĶ���ͬ���͵ĺ���
		int a = 5;
	int b = 3;
	int c = arr[1](a, b);
	printf("%d", c);
	return 0;
}