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
	//�洢����
	char board[ROW][COL];
	//��ʼ��
	InitBoard(board, ROW, COL);
	//��ӡ����
	Displayboard(board,ROW,COL);
	int count = 0;
	char ret = 0;
	while (1)
	{
		//�����
		printf("�����\n");
		playermove(board, ROW, COL);
		Displayboard(board, ROW, COL);
		ret=iswin(board, ROW, COL);
		if (ret != 'c')
			break;
		//������
		printf("������\n");
		computermove(board, ROW, COL);
		Displayboard(board, ROW, COL);
		ret=iswin(board, ROW, COL);
		if (ret != 'c')
			break;
	}
	if (ret == '*')
	{
		printf("���Ӯ\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ\n");
	}
	else 
	{
		printf("ƽ��\n");
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
		printf("��ѡ��");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("��������Ϸ\n");
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (input);
	return 0;
}