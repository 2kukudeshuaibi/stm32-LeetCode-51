#pragma once

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define MAX_NAME 20
#define MAX_SEX 10
#define MAX_TELE 12
#define MAX_ADDR 30
#define MAX 1000
#define DEFAULT_SZ 3
#define INC_sz 2




//定义结构体类型
typedef struct people
{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	int age;
	char tele[MAX_TELE]; 
	char addr[MAX_ADDR];
}people;


//静态版本
////通讯录
//typedef struct Contact
//{
//	people date[MAX];//存放添加进来的人的信息
//	int sz;//记录当前通讯录中有效信息的个数
//}Contact;



//动态版本
typedef struct Contact
{
	people *date;//指向动态申请的空间 存放添加进来的人的信息
	int sz;//记录当前通讯录中有效信息的个数
	int capacity;//记录当前通讯录的最大容量

}Contact;



//初始化通讯录
void Initcontact(Contact* pc);
//增加联系人
void Addcontact(Contact* pc);
//打印通讯录
void Printcontact(const Contact* pc);
//删除联系人
void Delecontact(Contact* pc);
//查找指定联系人
void Searchcontact(const Contact* pc);
//修改联系人
void Modifycontact(Contact* pc);
//排序
void Sortcontact(Contact* pc);

//退出程序
void Destorycontact(Contact* pc);

//保持通讯录
void Savecontact(Contact* pc);


//加载文件内容到通讯录
void Loadcontact(Contact* pc);

//检测增容
void check_size(Contact* pc);