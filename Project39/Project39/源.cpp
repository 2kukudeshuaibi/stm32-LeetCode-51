#define _CRT_SECURE_NO_WARNINGS 1
#include<string.h>
#include<stdio.h>
#include<iostream>
#include<math.h>
int add(int x, int y)
{
	return x + y;
}
int sub(int x, int y)
{
	return x - y;
}
int mul(int x, int y)
{
	return x * y;
}
int diy(int x, int y)
{
	return x / y;
}
void menu()
{
	printf("**************************\n");
	printf("****** 1.add  2.sub ******\n");
	printf("****** 3.mul  4.diy ******\n");
	printf("******** 0.exit  *********\n");
}
int main()
{
	int input = 0;
	int (*arr[5])(int, int) = { NULL,add,sub,mul,diy };
	int x = 0;
	int y = 0;
	int ret = 0;
	do
	{
		menu();
		printf("请选择\n");
		scanf("%d", &input);
		printf("请输入俩个操作数\n");
		scanf("%d %d", &x, &y);
		ret = arr[input](x, y);
		printf("%d \n", ret);
	} while (input);
	return 0;
}