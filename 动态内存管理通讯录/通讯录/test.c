#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "contact.h"



#define MAX 1000
//ͨѶ¼
//1.ͨѶ¼���ܹ����1000���˵���Ϣ
//����+����+�Ա�+�绰+��ַ
//2.�����˵���Ϣ
//3.ɾ��ָ���˵���Ϣ
//4.�޸�ָ���˵���Ϣ
//5.����ָ���˵���Ϣ
//6.����ͨѶ¼����Ϣ

void menu()
{
	printf("****************************************\n");
	printf("****   1.add         2.delete       ****\n");
	printf("****   3.search      4.modify       ****\n");
	printf("****   5.sort        6.print        ****\n");
	printf("****   0.exit                       ****\n");
	printf("****************************************\n");
}
enum select
{
	Exit,
	Add,
	Del,
	Search,
	Modify,
	Sort,
	Print,
};
int main()
{
	int input = 0;
	//����ͨѶ¼
	Contact con;
	//��ʼ��ͨѶ¼
	//��date����һ�������Ŀռ��ڶ�����
	//sz=0
	//capacity ��ʼ��Ϊ��ǰ��������
	Initcontact(&con);
	do
	{
		menu();
		printf("��ѡ��");
		scanf("%d", &input);
		switch (input)
		{
		case Add:
			Addcontact(&con);
			break;
		case Del:
			Delecontact(&con);
			break;
		case Search:
			Searchcontact(&con);
			break;
		case Modify:
			Modifycontact(&con);
			break;
		case Sort:
			Sortcontact(&con);
			break;
		case Print:
			Printcontact(&con);
			break;
		case Exit:
			Savecontact(&con);
			Destorycontact(&con);
			printf("�˳��ɹ�\n");
			break;
		default:
			printf("�����������������\n");
			break;
		}
	} while (input);
	return 0;
}
