#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


ST path;

void PrintMaze(int** maze, int n, int m)
{
	int i = 0, j = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			printf("%d ", maze[i][j]);
		}
		printf("\n");
	}
}


int IsPass(int** maze, int n, int m, PT pos)
{
	if (pos.col >= 0 && pos.col < m && pos.row >= 0 && pos.row < n && maze[pos.row][pos.col]==0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


void PrintPath(ST* ps)
{
	ST rpath;
	StackInit(&rpath);
	while (!StackEmpty(&path))
	{
		StackPush(&rpath, StackTop(&path));
		StackPop(&path);
	}

	while (!StackEmpty(&rpath))
	{
		PT tmp = StackTop(&rpath);
		printf("[%d,%d]\n", tmp.row, tmp.col);
		StackPop(&rpath);
	}
}


int Get_Maze_Path(int** maze, int n, int m, PT cur)
{
	StackPush(&path,cur);

	if (cur.row == n - 1 && cur.col == m - 1)
	{
		
		return 1;
	}

	PT next;
	maze[cur.row][cur.col] = 2;

	//ио
	next = cur;
	next.row -= 1;
	if (IsPass(maze, n, m, next))
	{
		
		if (Get_Maze_Path(maze, n, m, next))
		{
			return 1;
		}
	}


	//об
	next = cur;
	next.row += 1;
	if (IsPass(maze, n, m, next))
	{
		
		if (Get_Maze_Path(maze, n, m, next))
		{
			return 1;
		}
	}


	//вС
	next = cur;
	next.col -= 1;
	if (IsPass(maze, n, m, next))
	{
		
		if (Get_Maze_Path(maze, n, m, next))
		{
			return 1;
		}
	}


	//ср
	next = cur;
	next.col += 1;
	if (IsPass(maze, n, m, next))
	{
		
		if (Get_Maze_Path(maze, n, m, next))
		{
			return 1;
		}
	}

	StackPop(&path);

	return 0;
}

int main()
{
	int n = 0, m = 0;
	StackInit(&path);
	scanf("%d %d", &n, &m);
	int** maze = (int**)malloc(sizeof(int*) * n);
	int i = 0, j = 0;
	for (i = 0; i < n; i++)
	{
		maze[i] = (int*)malloc(sizeof(int) * m);
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			scanf("%d", &maze[i][j]);
		}
	}




	//PrintMaze(maze, n, m);

	PT entry = { 0,0 };
	Get_Maze_Path(maze, n, m, entry);

	PrintPath(&path);

	for (i = 0; i < n; i++)
	{
		free(maze[i]);
		maze[i] = NULL;
	}
	free(maze);
	return 0;
}