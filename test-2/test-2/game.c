#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void menu()
{
	printf("*****************************\n");
	printf("******    1: play    ********\n");
	printf("******    0: exit    ********\n");
	printf("*****************************\n");
}

void game()
{
	//存储数据的棋盘
	char mine[ROWS][COLS] = { 0 };

	char show[ROWS][COLS] = { 0 };

	//初始化棋盘
	Initboard(mine, ROW, COL,'0');
	Initboard(show, ROW, COL,'*');

	//打印棋盘
	//displayboard(mine, ROW, COL);
	displayboard(show, ROW, COL);

	//布置雷
	setmine(mine, ROW, COL);
	//displayboard(mine, ROW, COL);
	int input = 0;
	while (1)
	{
		printf("如果你想标记雷，请按2，如果你想输入坐标请按1\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			//排查雷
			find_mine(mine, show, ROW, COL);
			break;
		case 2:
			//标记雷
			b_signed(show, ROW, COL);
			
		}
	}
}

int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("请选择:\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误请重新选择\n");
		}

	} while (input);
	return 0;
}