#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
void menu()
{
	printf("****************\n");
	printf("****1:��ʼ******\n");
	printf("****0:����*****\n");
	printf("****************\n");
}
void game()
{
	int ret = rand() % 100 + 1;
	int b = 0;
	printf("��Ϸ��ʼ��ѡ��");
	while (1)
	{
		scanf("%d", &b);
		if (b > ret)
		{
			printf("�´���\n");
		}
		else if (b < ret)
		{
			printf("��С��");
		}
		else
		{
			printf("��ϲ��¶���\n");
			break;
		}
	}
}
int main()
{
	int a = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			game();
			break;
		case 0:
			printf("��Ϸ����\n");
			break;
		}
	} while (a);
	return 0;
}