#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "contact.h"



#define MAX 1000
//通讯录
//1.通讯录中能够存放1000个人的信息
//名字+年龄+性别+电话+地址
//2.增加人的信息
//3.删除指定人的信息
//4.修改指定人的信息
//5.查找指定人的信息
//6.排序通讯录的信息

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
	//创建通讯录
	Contact con;
	//初始化通讯录
	//给date申请一块连续的空间在堆区上
	//sz=0
	//capacity 初始化为当前最大的容量
	Initcontact(&con);
	do
	{
		menu();
		printf("请选择：");
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
			printf("退出成功\n");
			break;
		default:
			printf("输入错误请重新输入\n");
			break;
		}
	} while (input);
	return 0;
}
