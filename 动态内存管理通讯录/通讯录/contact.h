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




//����ṹ������
typedef struct people
{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	int age;
	char tele[MAX_TELE]; 
	char addr[MAX_ADDR];
}people;


//��̬�汾
////ͨѶ¼
//typedef struct Contact
//{
//	people date[MAX];//�����ӽ������˵���Ϣ
//	int sz;//��¼��ǰͨѶ¼����Ч��Ϣ�ĸ���
//}Contact;



//��̬�汾
typedef struct Contact
{
	people *date;//ָ��̬����Ŀռ� �����ӽ������˵���Ϣ
	int sz;//��¼��ǰͨѶ¼����Ч��Ϣ�ĸ���
	int capacity;//��¼��ǰͨѶ¼���������

}Contact;



//��ʼ��ͨѶ¼
void Initcontact(Contact* pc);
//������ϵ��
void Addcontact(Contact* pc);
//��ӡͨѶ¼
void Printcontact(const Contact* pc);
//ɾ����ϵ��
void Delecontact(Contact* pc);
//����ָ����ϵ��
void Searchcontact(const Contact* pc);
//�޸���ϵ��
void Modifycontact(Contact* pc);
//����
void Sortcontact(Contact* pc);

//�˳�����
void Destorycontact(Contact* pc);

//����ͨѶ¼
void Savecontact(Contact* pc);


//�����ļ����ݵ�ͨѶ¼
void Loadcontact(Contact* pc);

//�������
void check_size(Contact* pc);