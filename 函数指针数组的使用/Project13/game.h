#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define EASY_CONUT 10

#define ROW 9
#define COL 9
#define ROWS 11
#define COLS 11

//��ʼ������
void Initboard(char board[ROWS][COLS], int rows, int cols, char set);


//��ӡ����
void displayboard(char board[ROWS][COLS],int row,int col);

//������
void setmine(char mine[ROWS][COLS],int row,int col);

//�ų���
void findmine(char mine[ROWS][COLS],char show[ROWS][COLS], int row,int col);