#define _CRT_SECURE_NO_WARNINGS 1
#define ROW 3
#define COL 3
#include<stdlib.h>
#include<time.h>
#include<stdio.h>
//��ʼ������
void InitBoard(char board[ROW][COL], int row, int col);
//��ӡ����
void Displayboard(char board[ROW][COL], int row, int col);
//�����
void playermove(char board[ROW][COL], int row, int col);
//������
void computermove(char board[ROW][COL], int row, int col);
//�ж���Ӯ
char iswin(char board[ROW][COL],int row,int col);