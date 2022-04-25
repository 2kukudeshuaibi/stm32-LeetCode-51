#include "contact.h"


//������ϵ������
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

//ð������
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


//��ʼ��
void Initcontact(Contact* pc)
{
	pc->sz = 0;
	memset(pc->date, 0, sizeof(pc->date));
}


//������ϵ��
void Addcontact(Contact* pc)
{
	if (pc->sz == MAX)
	{
		printf("ͨѶ¼�������޷����\n");
		return;
	}
	printf("����������:");
	scanf("%s", pc->date[pc->sz].name);
	printf("����������:");
	scanf("%d", &(pc->date[pc->sz].age));
	printf("�������Ա�:");
	scanf("%s", pc->date[pc->sz].sex);
	printf("������绰:");
	scanf("%s", pc->date[pc->sz].tele);
	printf("�������ַ:");
	scanf("%s", pc->date[pc->sz].addr);

	pc->sz++;
	printf("���ӳɹ�\n");
}


//��ӡͨѶ¼
void Printcontact(const Contact* pc)
{
	int i = 0;
	//��ӡ����
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
	for (i = 0; i < pc->sz; i++)
	{
		printf("%-20s\t%-5d\t%-5s\t%-12s\t%-20s\n", pc->date[i].name, pc->date[i].age, pc->date[i].sex, pc->date[i].tele, pc->date[i].addr);
	}
}

//ɾ����ϵ��
void Delecontact(Contact* pc)
{
	char name[MAX_NAME] = { 0 };
	if (pc->sz == 0)
	{
		printf("ͨѶ¼Ϊ�գ�����ɾ��\n");
		return;
	}
	//����Ҫɾ������
	printf("������Ҫɾ������ϵ��������");
	scanf("%s", name);
	int pos = Findbyname(pc, name);
	if (pos == -1)
	{
		printf("Ҫɾ�����˲�����\n");
		return;
	}
	//ɾ��
	int i = 0;
	for (i = pos; i < pc->sz-1; i++)
	{
		pc->date[i] = pc->date[i + 1];
	}
	pc->sz--;
	printf("ɾ���ɹ�\n");
}

//������ϵ��
void Searchcontact(const Contact* pc)
{
	char name[MAX_NAME];
	printf("������Ҫ���ҵ���ϵ������\n");
	scanf("%s", name);
	int pos = Findbyname(pc, name);
	if (pos == -1)
	{
		printf("Ҫ���ҵ���ϵ�˲�����\n");
		return;
	}
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
	printf("%-20s\t%-5d\t%-5s\t%-12s\t%-20s\n", pc->date[pos].name, pc->date[pos].age, pc->date[pos].sex, pc->date[pos].tele, pc->date[pos].addr);
}


//�޸���ϵ��
void Modifycontact(Contact* pc)
{
	char name[MAX_NAME];
	printf("������Ҫ�޸ĵ���ϵ������\n");
	scanf("%s", name);
	int pos = Findbyname(pc, name);
	if (pos == -1)
	{
		printf("Ҫ�޸ĵ���ϵ�˲�����\n");
		return;
	}
	printf("����������:");
	scanf("%s", pc->date[pos].name);
	printf("����������:");
	scanf("%d", &(pc->date[pos].age));
	printf("�������Ա�:");
	scanf("%s", pc->date[pos].sex);
	printf("������绰:");
	scanf("%s", pc->date[pos].tele);
	printf("�������ַ:");
	scanf("%s", pc->date[pos].addr);
	printf("�޸ĳɹ�\n");
}

int str_name(const void* b1, const void* b2)
{
	return ((Contact*)b1)->date->name - ((Contact*)b2)->date->name;
}


int str_age(const void* b1, const void* b2)
{
	return ((struct Contact*)b1)->date->age - ((struct Contact*)b2)->date->age;
}

//����
void Sortcontact(Contact* pc)
{
	int a = 0;
	printf("���������������� 1  ���������������� 2  :");
	scanf("%d", &a);
	if (a == 1)
	{
		my_qsort(pc, pc->sz, sizeof(people), str_name);
	}
	else if (a == 2)
	{
		my_qsort(pc, pc->sz, sizeof(people), str_age);
	}
	printf("����ɹ�\n");
}

