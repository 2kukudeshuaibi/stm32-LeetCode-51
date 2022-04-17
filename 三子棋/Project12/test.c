#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"game.h"
void menu()
{
	printf("**************************\n");
	printf("*****   1:play   *********\n");
	printf("*****   0:exit   *********\n");
	printf("**************************\n");
}
void game()
{
	//存储数据
	char board[ROW][COL];
	//初始化
	InitBoard(board, ROW, COL);
	//打印函数
	Displayboard(board,ROW,COL);
	int count = 0;
	char ret = 0;
	while (1)
	{
		//玩家走
		printf("玩家走\n");
		playermove(board, ROW, COL);
		Displayboard(board, ROW, COL);
		ret=iswin(board, ROW, COL);
		if (ret != 'c')
			break;
		//电脑走
		printf("电脑走\n");
		computermove(board, ROW, COL);
		Displayboard(board, ROW, COL);
		ret=iswin(board, ROW, COL);
		if (ret != 'c')
			break;
	}
	if (ret == '*')
	{
		printf("玩家赢\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢\n");
	}
	else 
	{
		printf("平局\n");
	}
	Displayboard(board, ROW, COL);
}
int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("请选择：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("三子棋游戏\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新选择\n");
			break;
		}
	} while (input);
	return 0;
}