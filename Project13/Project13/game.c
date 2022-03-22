#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"
void menu()
{
	printf("**********************************\n");
	printf("*******   1:playe          *******\n");
	printf("*******   0:exit           *******\n");
	printf("**********************************\n");
}

void game()
{
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	//初始化棋盘
	Initboard(mine, ROWS, COLS, '0');
	Initboard(show, ROWS, COLS, '*');

	//打印棋盘
	//displayboard(mine, ROW, COL);
	displayboard(show, ROW, COL);

	//布置雷
	setmine(mine, ROW, COL);
	//displayboard(mine, ROW, COL);
	//排查雷
	findmine(mine, show, ROW, COL);
	
}
int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("请选择:");
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
			printf("输入错误，请重新选择\n");
			break;
		}
	} while (input);
	return 0;
}