#include <stdio.h>
#include <stdlib.h>


typedef struct Node
{
	int data;
	struct Node* next;
}ListNode;


//开辟一个节点


//打印链表
void PrintListNode(ListNode* head)
{
	ListNode* cur = head;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}
//尾插
void ListNodePushBack(ListNode** head, int x)
{
	ListNode* new = (ListNode*)malloc(sizeof(ListNode));
	new->data = x;
	new->next = NULL;
	if (*head == NULL)
	{
		*head = new;
	}
	else
	{
		ListNode* list = *head;
		while (list->next!=NULL)
		{
			list = list->next;
		}
		list->next = new;
	}
}

void ListNodePushFront(ListNode** head, int x)
{
	ListNode* new = (ListNode*)malloc(sizeof(ListNode));
	new->data = x;
	new->next = NULL;
	ListNode* front = *head;
	if (front == NULL)
	{
		front = new;
	}
	else
	{
		new->next = front;
		*head = new;
	}
}

void DeletListNodeBack(ListNode** head)
{
	ListNode* back = *head;
	ListNode* list = NULL;
	if (*head == NULL)
	{
		return;
	}
	else if ((*head)->next == NULL)
	{
		*head = NULL;
		free(back);
	}
	else
	{
		while (back->next != NULL)
		{
			list = back;
			back = back->next;
		}
		list->next = NULL;
		free(back);
		back = NULL;
	}
}

void DeletListNodeFront(ListNode** head)
{
	ListNode* tmp = *head;
	(*head) = (*head)->next;
	free(tmp);
	tmp = NULL;
}

void RanddeletListNode(ListNode** head, int x)
{
	ListNode* cur = *head;
	ListNode* prev = NULL;
	while (cur!=NULL)
	{
		if (cur->data==x)
		{
			ListNode* tmp = cur;
			if (cur == *head)
			{
				(*head) = (*head)->next;
			}
			else
			{
				prev->next = cur->next;
			}
			free(tmp);
			tmp = NULL;
			break;
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
}

ListNode* FindPosListnode(ListNode** head, int x)
{
	ListNode* pos = *head;
	while (pos != NULL)
	{
		if (pos->data == x)
		{
			return pos;
		}
		else
		{
			pos = pos->next;
		}
	}
	return NULL;
}


void RandInListNode(ListNode** head,ListNode* pos, int x)
{
	ListNode* new = (ListNode*)malloc(sizeof(ListNode));
	new->data = x;
	new->next = NULL;

	ListNode* cur = *head;
	ListNode* prev = NULL;
	while (cur)
	{
		if (cur->data == pos->data)
		{
			if (cur == *head)
			{
				*head = new;
				(*head)->next = cur;
				break;
			}
			else
			{
				prev->next = new;
				new->next = cur;
				break;
			}
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
}

ListNode* middleNode(ListNode* head)
{
	ListNode* cur = head;
	ListNode* prev = head;

	while (cur->next && cur)
	{
		
	    cur = cur->next->next;
		prev = prev->next;
	}

	return prev;
}

int main()
{
	int arr[] = { 1,2,3};
	ListNode* head = NULL;
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
	{
		ListNodePushBack(&head, arr[i]);
	}
	ListNode* middle = middleNode(head);
	printf("%d", middle->data);
	return 0;
}