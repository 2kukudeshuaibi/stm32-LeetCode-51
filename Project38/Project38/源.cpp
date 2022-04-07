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
	//arr就是函数指针数组 - 里面存放的都是同类型的函数
		int a = 5;
	int b = 3;
	int c = arr[1](a, b);
	printf("%d", c);
	return 0;
}