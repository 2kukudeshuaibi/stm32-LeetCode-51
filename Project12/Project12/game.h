#define _CRT_SECURE_NO_WARNINGS 1
#define ROW 3
#define COL 3
#include<stdlib.h>
#include<time.h>
#include<stdio.h>
//初始化棋盘
void InitBoard(char board[ROW][COL], int row, int col);
//打印棋盘
void Displayboard(char board[ROW][COL], int row, int col);
//玩家走
void playermove(char board[ROW][COL], int row, int col);
//电脑走
void computermove(char board[ROW][COL], int row, int col);
//判断输赢
char iswin(char board[ROW][COL],int row,int col);