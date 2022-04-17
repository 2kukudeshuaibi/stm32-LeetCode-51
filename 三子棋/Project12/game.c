#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include"game.h"
//初始化
void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}
//打印
void Displayboard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}printf("\n");
		int a = 0;
		for (a = 0; a < col; a++)
		{
			printf("---");
			if (a < col - 1)
			{
				printf("|");
			}
		}printf("\n");
	}
}
//玩家走
void playermove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;

	printf("请输入坐标\n");
	while (1)
	{
		scanf("%d%d", &x, &y);
		////判断合法性
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//判断占用
			if (board[x-1][y-1] == ' ')
			{
				board[x-1][y-1] = '*';
				break;
			}
			else
			{
				printf("坐标被占用，请重新输入\n");
			}
		}
		else
		{
			printf("输入非法请重新输入\n");
		}
	}
}
//电脑走
void computermove(char board[ROW][COL], int row, int col)
{
	while (1)
	{
		int x = rand() % row;
		int y = rand() % col;
		//判断占用
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}
int man_mei(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;//棋盘没满
			}
		}
	}
	return 1;
}

//判断输赢
char iswin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	//判断行
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] != ' ')
		{
			return board[i][1];
		}
	}
	//判断列
	for (j = 0; j < col; j++)
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[2][j] != ' ')
		{
			return board[1][j];
		}
	}
	//判断主对角线
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2]&&board[1][1]!=' ')
	{
		return board[1][1];
	}
	//判断次对角线
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0]&&board[1][1]!=' ')
	{
		return board[1][1];
	}
	//判断平局
	int o = man_mei(board,row,col);
	if (o == 1)
	{
		return 'Q';
	}
	return 'c';
}