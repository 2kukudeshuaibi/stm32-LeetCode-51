#define _CRT_SECURE_NO_WARNINGS 1

#pragma once


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tt
{
	int a;
	struct tt* next;
}typedef tt;

void print(tt* phead);//��ӡ
void pushback(tt** phead, int num);//β��
void pushfront(tt** phead, int num);//ͷ��
void deletefront(tt** phead);//ͷɾ
void deleteback(tt** phead);//βɾ

void suijicharu(tt** phead, int x);
void suijidelete(tt** phead, int x);//���ɾ��
void cuihui(tt** phead);//��������

tt* find(tt* phead, int x);

//��posǰ�����x
void slistinsert(tt** phead, tt* pos, int x);
//ɾ��posλ�õ�ֵ
void slisterase(tt** phead, tt* pos);



