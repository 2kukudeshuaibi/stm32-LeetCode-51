#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROWS 11
#define COLS 11
#define ROW 9
#define COL 9

//难度选择
#define EASY 10


//初始化
void Initboard(char board[ROWS][COLS],int row,int col,char ret);


//打印棋盘
void displayboard(char board[ROWS][COLS], int row,int col);

//布置雷
void setmine(char mine[ROWS][COLS], int row, int col);

//排查雷
void find_mine(char mine[ROWS][COLS], char show[ROWS][COLS], int row,int col);

//标记雷
void b_signed(char show[ROWS][COLS], int row, int col);