#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

//��ʼ������
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



//��ӡ����
void displayboard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("--------------ɨ����Ϸ------------\n");
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
	printf("--------------ɨ����Ϸ------------\n");
}


//������
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
//�ж���Χ����
static int get_mine(char mine[ROWS][COLS], int x, int  y)
{
	return (mine[x - 1][y] + mine[x - 1][y - 1] + mine[x][y - 1] + mine[x + 1][y - 1] + mine[x + 1][y] + mine[x + 1][y + 1] + mine[x][y + 1] + mine[x - 1][y + 1]) -( 8 * '0');
		 
		  		  

}

//�Ų���
void findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	//1�������Ų������
	//2��������괦�ǲ�������
	     //(1):���ף���ը���ˡ�
	     //(2):û���ף���ʾ��Χ�׵�����  ��ʾ��Ϣ��show����ȥ��Ϸ����
	int x = 0;
	int y = 0;
	int win = 0;
	while (win<ROW*COL- EASY_CONUT)
	{
		printf("�������Ų������\n");
		scanf("%d%d", &x, &y);
		//�ж�����ķǷ���
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("���ź��㱻ը����\n");
				displayboard(mine, row, col);
				break;
			}
			else //�����׵������ͳ��������Χ�׵�����
			{
				win++;
				int count = get_mine (mine, x, y);
				show[x][y] = '0' + count;
				displayboard(show, row, col);
			}
		}
		else
		{
			printf("��������Ƿ�������������\n");
		}
	}
	if (win == row * col - EASY_CONUT)
	{
		printf("��ϲ�����׳ɹ�\n");
		displayboard(mine, row, col);
	}
}