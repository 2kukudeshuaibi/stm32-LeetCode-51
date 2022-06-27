#define _CRT_SECURE_NO_WARNINGS 1

#include "Queue.h"




void Prevorder(BT* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	printf("%c ", root->date);
	Prevorder(root->left);
	Prevorder(root->right);
}

void Inorder(BT* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	Inorder(root->left);
	printf("%c ", root->date);
	Inorder(root->right);
}

void Postorder(BT* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	Postorder(root->left);
	Postorder(root->right);
	printf("%c ", root->date);
}


int Treesize(BT* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return 1+Treesize(root->left)+Treesize(root->right);
}


int TreeLeafsize(BT* root)
{
	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}
	else
	{
		return TreeLeafsize(root->left) + TreeLeafsize(root->right);
	}
}



void Leveorder(BT* root)
{
	queue q;
	QueueInit(&q);
	if (root)
	{
		Queuepush(&q,root);
	}
	while (!QueueEmpty(&q))
	{
		BT* front = Queuefront(&q);
		Queuepop(&q);
		printf("%c ", front->date);

		if (front->left)
		{
			Queuepush(&q,front->left);
		}

		if (front->right)
		{
			Queuepush(&q, front->right);
		}
	}



	Queuedestory(&q);
}


void destory(BT* root)
{
	if (root == NULL)
	{
		return;
	}
	destory(root->left);
	destory(root->right);
	free(root);
	root = NULL;
}


int main()
{
	BT* A = (BT*)malloc(sizeof(BT));
	BT* B = (BT*)malloc(sizeof(BT));
	BT* C = (BT*)malloc(sizeof(BT));
	BT* D = (BT*)malloc(sizeof(BT));
	BT* E = (BT*)malloc(sizeof(BT));
	A->date = 'A';
	A->left = B;
	A->right = C;

	
	B->date = 'B';
	B->left = D;
	B->right = E;

	
	C->date = 'C';
	C->left = NULL;
	C->right = NULL;


	
	D->date = 'D';
	D->left = NULL;
	D->right = NULL;


	
	E->date = 'E';
	E->left = NULL;
	E->right = NULL;
	//Prevorder(A);
	//Inorder(A);

	/*int size = TreeLeafsize(A);
	printf("%d ", size);*/
	//Postorder(A);

	//destory(A);

	Leveorder(A);
	return 0;
}