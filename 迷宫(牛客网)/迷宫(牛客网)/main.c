#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>



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

int main()
{
	int n = 0, m = 0;
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


	PrintMaze(maze, n, m);


	for (i = 0; i < n; i++)
	{
		free(maze[i]);
		maze[i] = NULL;
	}
	free(maze);
	return 0;
}