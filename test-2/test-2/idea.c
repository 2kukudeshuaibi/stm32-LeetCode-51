#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

//初始化棋盘
void Initboard(char board[ROWS][COLS], int row, int col, char ret)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < ROWS; i++)
	{
		for (j = 0; j < COLS; j++)
		{
			board[i][j] = ret;
		}
	}
}


//打印棋盘
void displayboard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	int a = 0;
	printf("-----------------------------扫雷游戏----------------------\n");
	for (a = 0; a <= row; a++)
	{
		printf("%d ", a);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			
			printf("%c ", board[i][j]);
		}
		printf("\n");
		int b = 0;
	}
	printf("-----------------------------扫雷游戏----------------------\n");
}


//布置雷
void setmine(char mine[ROWS][COLS], int row, int col)
{
	int count = 0;
	while (count<EASY)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (x >= 1 && x <= row && y >= 1 && y <= col && mine[x][y] == '0')
		{
			count++;
			mine[x][y] = '1';
		}

	}
}

int getcount(char mine[ROWS][COLS], int x, int y)
{
	return(mine[x - 1][y - 1] + mine[x - 1][y] + mine[x - 1][y + 1] + mine[x][y - 1] + mine[x][y + 1] + mine[x + 1][y - 1] + mine[x + 1][y] + mine[x + 1][y + 1]) - 8 * '0';
}


//排查雷
void find_mine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int count = 0;
	while (count<ROW*COL-EASY)
	{
		printf("请输入要排查的坐标\n");
		scanf("%d%d", &x, &y);

		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '0')
			{
				count++;
				

				show[x][y] = getcount(mine, x, y) + '0';
				displayboard(show, ROW, COL);
			}
			else
			{
				printf("很遗憾你被炸死了\n");
				displayboard(mine, ROW, COL);
				break;
			}
		}
		else
		{
			printf("输入的坐标非法，请重新输入\n");
		}
	}
	if (count == row * col - EASY)
	{
		printf("恭喜你雷已经排除完了\n");
	}
}



//标记雷
void b_signed(char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("请输入你要标记的坐标\n");
	scanf("%d%d", &x, &y);
	show[x][y] = 'x';
	displayboard(show, ROW, COL);
}