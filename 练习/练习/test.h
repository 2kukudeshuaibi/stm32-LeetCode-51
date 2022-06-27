#pragma once
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


/*
˳���
���ܣ�ͷ�� β��
	  ͷɾ βɾ
	  ��ӡ ����
	  ������� ���ɾ��
*/
typedef int SLDataType;
typedef struct seqlist
{
	SLDataType* arr;
	int size;
	int capa;
}sl;
void SeqListInit(sl* psl);//��ʼ��
void SeqListDestory(sl* psl);//����
void SeqListPrint(sl* psl);//��ӡ
void Check(sl* psl);//���ռ�
void SeqListPushBack(sl* psl, SLDataType x);//β��
void SeqListPopback(sl* psl, SLDataType x);//βɾ
void SeqListPushFront(sl* psl, SLDataType x);//ͷ��
void SeqListPopFront(sl* psl, SLDataType x);//ͷɾ
int SeqListFind(sl* psl, SLDataType x);//����
void SeqListInsert(sl* psl, int pos, SLDataType x);//��posλ�ò���
void SeqListErase(sl* psl, int pos);//ɾ��posλ��




/*
����
���ܣ�ͷ�� β��
	  ͷɾ βɾ
	  ��ӡ ����
	  ������� ���ɾ��
*/
typedef int SList;
typedef struct slist
{
	struct slist* next;
	SList val;
}slist;

void slistprint(slist* head);//��ӡ
void slistpushback(slist** head, SList x);//β��
void slistpushfront(slist** head, SList x);//ͷ��
void slistpopback(slist** head);//βɾ
void slistpopfront(slist** head);//ͷɾ
slist* find(slist* head, SList x);//����
void slistInsert(slist** head, slist* pos, SList x);//posǰ����x
void slistErase(slist** head, slist* pos);


/*
˫������
���ܣ�ͷ�� β��
	  ͷɾ βɾ
	  ��ӡ ����
	  ������� ���ɾ��
*/
typedef int list;
typedef struct sxlist
{
	struct sxlist* next;
	struct sxlist* prev;
	list val;
}sxlist;
sxlist* listinit();
void listdestory(sxlist* phead);
void listprint(sxlist* phead);
void listpushback(sxlist* phead, list date);
void listpushfront(sxlist* phead, list date);
void listpopback(sxlist* phead);
void listpopfront(sxlist* phead);
sxlist* listfind(sxlist* phead, list date);
void listinsert(sxlist* pos, list date);
void listErase(sxlist* pos);


