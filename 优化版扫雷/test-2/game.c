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
	//�洢���ݵ�����
	char mine[ROWS][COLS] = { 0 };

	char show[ROWS][COLS] = { 0 };

	//��ʼ������
	Initboard(mine, ROW, COL,'0');
	Initboard(show, ROW, COL,'*');

	//��ӡ����
	//displayboard(mine, ROW, COL);
	displayboard(show, ROW, COL);

	//������
	setmine(mine, ROW, COL);
	//displayboard(mine, ROW, COL);
	int input = 0;
	while (1)
	{
		printf("����������ף��밴2������������������밴1\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			//�Ų���
			find_mine(mine, show, ROW, COL);
			break;
		case 2:
			//�����
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
		printf("��ѡ��:\n");
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
		}

	} while (input);
	return 0;
}