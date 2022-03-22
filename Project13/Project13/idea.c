#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

//初始化棋盘
void Initboard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] =set;
		}
	}
}



//打印棋盘
void displayboard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("--------------扫雷游戏------------\n");
	int a = 0;
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
	}
	printf("--------------扫雷游戏------------\n");
}


//布置雷
void setmine(char mine[ROWS][COLS], int row, int col)
{
	int count = EASY_CONUT;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (mine[x][y] == '0' && x >= 1 && y >= 1)
		{
			mine[x][y] = '1';
			count--;
		}
	}
}
//判断周围的雷
static int get_mine(char mine[ROWS][COLS], int x, int  y)
{
	return (mine[x - 1][y] + mine[x - 1][y - 1] + mine[x][y - 1] + mine[x + 1][y - 1] + mine[x + 1][y] + mine[x + 1][y + 1] + mine[x][y + 1] + mine[x - 1][y + 1]) -( 8 * '0');
		 
		  		  

}

//排查雷
void findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	//1：输入排查的坐标
	//2：检查坐标处是不是有雷
	     //(1):有雷，被炸死了。
	     //(2):没有雷，显示周围雷的数量  显示信息到show数组去游戏继续
	int x = 0;
	int y = 0;
	int win = 0;
	while (win<ROW*COL- EASY_CONUT)
	{
		printf("请输入排查的坐标\n");
		scanf("%d%d", &x, &y);
		//判断坐标的非法性
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("很遗憾你被炸死了\n");
				displayboard(mine, row, col);
				break;
			}
			else //不是雷的情况下统计坐标周围雷的数量
			{
				win++;
				int count = get_mine (mine, x, y);
				show[x][y] = '0' + count;
				displayboard(show, row, col);
			}
		}
		else
		{
			printf("输入坐标非法，请重新输入\n");
		}
	}
	if (win == row * col - EASY_CONUT)
	{
		printf("恭喜你排雷成功\n");
		displayboard(mine, row, col);
	}
}