#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
void menu()
{
	printf("****************\n");
	printf("****1:开始******\n");
	printf("****0:结束*****\n");
	printf("****************\n");
}
void game()
{
	int ret = rand() % 100 + 1;
	int b = 0;
	printf("游戏开始请选择");
	while (1)
	{
		scanf("%d", &b);
		if (b > ret)
		{
			printf("猜大了\n");
		}
		else if (b < ret)
		{
			printf("猜小了");
		}
		else
		{
			printf("恭喜你猜对了\n");
			break;
		}
	}
}
int main()
{
	int a = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择：");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			game();
			break;
		case 0:
			printf("游戏结束\n");
			break;
		}
	} while (a);
	return 0;
}