#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define EASY_CONUT 10

#define ROW 20
#define COL 20
#define ROWS 22
#define COLS 22

//≥ı ºªØ∆Â≈Ã
void Initboard(char board[ROWS][COLS], int rows, int cols, char set);


//¥Ú”°∆Â≈Ã
void displayboard(char board[ROWS][COLS],int row,int col);

//≤º÷√¿◊
void setmine(char mine[ROWS][COLS],int row,int col);

//≈≈≥˝¿◊
void findmine(char mine[ROWS][COLS],char show[ROWS][COLS], int row,int col);