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
	//��ʼ������
	Initboard(mine, ROWS, COLS, '0');
	Initboard(show, ROWS, COLS, '*');

	//��ӡ����
	//displayboard(mine, ROW, COL);
	displayboard(show, ROW, COL);

	//������
	setmine(mine, ROW, COL);
	//displayboard(mine, ROW, COL);
	//�Ų���
	findmine(mine, show, ROW, COL);
	
}
int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�������������ѡ��\n");
			break;
		}
	} while (input);
	return 0;
}