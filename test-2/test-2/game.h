#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROWS 11
#define COLS 11
#define ROW 9
#define COL 9

//�Ѷ�ѡ��
#define EASY 10


//��ʼ��
void Initboard(char board[ROWS][COLS],int row,int col,char ret);


//��ӡ����
void displayboard(char board[ROWS][COLS], int row,int col);

//������
void setmine(char mine[ROWS][COLS], int row, int col);

//�Ų���
void find_mine(char mine[ROWS][COLS], char show[ROWS][COLS], int row,int col);

//�����
void b_signed(char show[ROWS][COLS], int row, int col);