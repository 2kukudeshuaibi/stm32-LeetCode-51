#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include"game.h"
//��ʼ��
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
//��ӡ
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
//�����
void playermove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;

	printf("����������\n");
	while (1)
	{
		scanf("%d%d", &x, &y);
		////�жϺϷ���
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//�ж�ռ��
			if (board[x-1][y-1] == ' ')
			{
				board[x-1][y-1] = '*';
				break;
			}
			else
			{
				printf("���걻ռ�ã�����������\n");
			}
		}
		else
		{
			printf("����Ƿ�����������\n");
		}
	}
}
//������
void computermove(char board[ROW][COL], int row, int col)
{
	while (1)
	{
		int x = rand() % row;
		int y = rand() % col;
		//�ж�ռ��
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
				return 0;//����û��
			}
		}
	}
	return 1;
}

//�ж���Ӯ
char iswin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	//�ж���
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] != ' ')
		{
			return board[i][1];
		}
	}
	//�ж���
	for (j = 0; j < col; j++)
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[2][j] != ' ')
		{
			return board[1][j];
		}
	}
	//�ж����Խ���
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2]&&board[1][1]!=' ')
	{
		return board[1][1];
	}
	//�жϴζԽ���
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0]&&board[1][1]!=' ')
	{
		return board[1][1];
	}
	//�ж�ƽ��
	int o = man_mei(board,row,col);
	if (o == 1)
	{
		return 'Q';
	}
	return 'c';
}