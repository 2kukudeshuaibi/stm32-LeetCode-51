#include "contact.h"


//查找联系人坐标
int Findbyname(Contact* pc,char name[])
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->date[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}
void swp(char* b1, char* b2,int wit)
{
	int i = 0;
	for (i = 0; i < wit; i++)
	{
		char tmp = *b1;
		*b1 = *b2;
		*b2 = tmp;
		b1++;
		b2++;
	}
}

//冒泡排序
void my_qsort(void* base, int len, int wit, int(*camp)(const void*, const void*))
{
	int i = 0;
	int j = 0;
	for (i = 0; i < len - 1; i++)
	{
		for (j = 0; j < len - 1 - i; j++)
		{
			if ((camp((char*)base + j * wit, (char*)base + (j + 1) * wit)) > 0)
			{
				swp((char*)base + j * wit, (char*)base + (j + 1) * wit, wit);
			}
		}
	}
}


//初始化
void Initcontact(Contact* pc)
{
	pc->sz = 0;
	memset(pc->date, 0, sizeof(pc->date));
}


//增加联系人
void Addcontact(Contact* pc)
{
	if (pc->sz == MAX)
	{
		printf("通讯录已满，无法添加\n");
		return;
	}
	printf("请输入名字:");
	scanf("%s", pc->date[pc->sz].name);
	printf("请输入年龄:");
	scanf("%d", &(pc->date[pc->sz].age));
	printf("请输入性别:");
	scanf("%s", pc->date[pc->sz].sex);
	printf("请输入电话:");
	scanf("%s", pc->date[pc->sz].tele);
	printf("请输入地址:");
	scanf("%s", pc->date[pc->sz].addr);

	pc->sz++;
	printf("增加成功\n");
}


//打印通讯录
void Printcontact(const Contact* pc)
{
	int i = 0;
	//打印标题
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
	for (i = 0; i < pc->sz; i++)
	{
		printf("%-20s\t%-5d\t%-5s\t%-12s\t%-20s\n", pc->date[i].name, pc->date[i].age, pc->date[i].sex, pc->date[i].tele, pc->date[i].addr);
	}
}

//删除联系人
void Delecontact(Contact* pc)
{
	char name[MAX_NAME] = { 0 };
	if (pc->sz == 0)
	{
		printf("通讯录为空，无需删除\n");
		return;
	}
	//查找要删除的人
	printf("请输入要删除的联系人姓名：");
	scanf("%s", name);
	int pos = Findbyname(pc, name);
	if (pos == -1)
	{
		printf("要删除的人不存在\n");
		return;
	}
	//删除
	int i = 0;
	for (i = pos; i < pc->sz-1; i++)
	{
		pc->date[i] = pc->date[i + 1];
	}
	pc->sz--;
	printf("删除成功\n");
}

//查找联系人
void Searchcontact(const Contact* pc)
{
	char name[MAX_NAME];
	printf("请输入要查找的联系人名字\n");
	scanf("%s", name);
	int pos = Findbyname(pc, name);
	if (pos == -1)
	{
		printf("要查找的联系人不存在\n");
		return;
	}
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
	printf("%-20s\t%-5d\t%-5s\t%-12s\t%-20s\n", pc->date[pos].name, pc->date[pos].age, pc->date[pos].sex, pc->date[pos].tele, pc->date[pos].addr);
}


//修改联系人
void Modifycontact(Contact* pc)
{
	char name[MAX_NAME];
	printf("请输入要修改的联系人名字\n");
	scanf("%s", name);
	int pos = Findbyname(pc, name);
	if (pos == -1)
	{
		printf("要修改的联系人不存在\n");
		return;
	}
	printf("请输入名字:");
	scanf("%s", pc->date[pos].name);
	printf("请输入年龄:");
	scanf("%d", &(pc->date[pos].age));
	printf("请输入性别:");
	scanf("%s", pc->date[pos].sex);
	printf("请输入电话:");
	scanf("%s", pc->date[pos].tele);
	printf("请输入地址:");
	scanf("%s", pc->date[pos].addr);
	printf("修改成功\n");
}

int str_name(const void* b1, const void* b2)
{
	return ((Contact*)b1)->date->name - ((Contact*)b2)->date->name;
}


int str_age(const void* b1, const void* b2)
{
	return ((struct Contact*)b1)->date->age - ((struct Contact*)b2)->date->age;
}

//排序
void Sortcontact(Contact* pc)
{
	int a = 0;
	printf("按名字排序请输入 1  按年龄排序请输入 2  :");
	scanf("%d", &a);
	if (a == 1)
	{
		my_qsort(pc, pc->sz, sizeof(people), str_name);
	}
	else if (a == 2)
	{
		my_qsort(pc, pc->sz, sizeof(people), str_age);
	}
	printf("排序成功\n");
}

