#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
typedef struct Tree
{
	struct Tree* left;
	struct Tree* right;
	char val;
}BT;

BT* CreatTree(char* str, int* pi)
{
	if (str[*pi] == '#')
	{
		++(*pi);
		return NULL;
	}
	BT* root = (BT*)malloc(sizeof(BT));
	root->val = str[*pi];
	++(*pi);
	root->left = CreatTree(str,pi);
	root->right= CreatTree(str, pi);
	return root;
}

void inorder(BT* root)
{
	if (root == NULL)
	{
		return;
	}
	inorder(root->left);

	printf("%c ", root->val);

	inorder(root->right);


}

int main()
{
	char str[100];
	scanf("%s", str);
	int i = 0;
	BT* tree = CreatTree(str, &i);

	inorder(tree);
	return 0;
}