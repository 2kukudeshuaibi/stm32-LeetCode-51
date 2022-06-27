#define _CRT_SECURE_NO_WARNINGS 1

#include "test.h"


/*
˳���
���ܣ�ͷ�� β��
      ͷɾ βɾ
	  ��ӡ ����
	  ������� ���ɾ��
*/
void SeqListInit(sl* psl)
{
	psl->arr = NULL;
	psl->size = 0;
	psl->capa = 0;
}

void SeqListDestory(sl* psl)
{
	free(psl->arr);
	psl->arr = NULL;
	psl->size = 0;
	psl->capa = 0;
}

void SeqListPrint(sl* psl)
{
	int i = 0;
	for (i = 0; i < psl->size; i++)
	{
		printf("%d ", psl->arr[i]);
	}
	printf("\n");
}


void Check(sl* psl)
{
	if (psl->size == psl->capa)
	{
		int new = psl->capa == 0 ? 1 : psl->capa * 2;
		SLDataType* tmp = (SLDataType*)realloc(psl->arr, sizeof(SLDataType) * new);
		if (tmp == NULL)
		{
			printf("����ʧ��\n");
			return;
		}
		else
		{
			printf("���ݳɹ�\n");
			psl->arr = tmp;
			psl->capa = new;
		}
	}
}
void SeqListPushBack(sl* psl, SLDataType x)
{
	Check(psl);
	psl->arr[psl->size] = x;
	psl->size++;
}

void SeqListPopback(sl* psl, SLDataType x)
{
	if (psl->size == 0)
	{
		printf("ɾ����\n");
		return;
	}
	psl->size--;
}

void SeqListPushFront(sl* psl, SLDataType x)
{
	Check(psl);
	int end = psl->size-1;
	while (end >= 0)
	{
		psl->arr[end + 1] = psl->arr[end];
		end--;
	}
	psl->arr[0] = x;
	psl->size++;
}

void SeqListPopFront(sl* psl, SLDataType x)
{
	int i = 0;
	if (psl->size == 0)
	{
		printf("ɾ����\n");
		return;
	}
	for (i = 0; i < psl->size-1; i++)
	{
		psl->arr[i] = psl->arr[i + 1];
	}
	psl->size--;
}

int SeqListFind(sl* psl, SLDataType x)
{
	int pos = 0;
	for (pos = 0; pos < psl->size; pos++)
	{
		if (psl->arr[pos] == x)
		{
			return pos;
		}
	}
	return -1;
}

void SeqListInsert(sl* psl, int pos, SLDataType x)
{
	Check(psl);
	psl->size++;
	int end = psl->size - 1;
	while (end >= pos)
	{
		psl->arr[end + 1] = psl->arr[end];
		end--;
	}
	psl->arr[pos] = x;

}
void SeqListErase(sl* psl, int pos)
{
	int end = pos;
	while (end < psl->size)
	{
		psl->arr[end] = psl->arr[end + 1];
		end++;
	}
	psl->size--;
}



/*
����
���ܣ�ͷ�� β��
	  ͷɾ βɾ
	  ��ӡ ����
	  ������� ���ɾ��
*/


void slistprint(slist* head)
{
	//assert(head);
	slist* cur = head;
	while (cur != NULL)
	{
		printf("%d ", cur->val);
		cur = cur->next;
	}
	printf("\n");
}

void slistpushback(slist** head, SList x)
{
	//assert(head);
	slist* new = (slist*)malloc(sizeof(slist));
	new->next = NULL;
	new->val = x;
	if (*head == NULL)
	{
		*head = new;
	}
	else
	{
		slist* tail = *head;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = new;
	}
}


void slistpushfront(slist** head, SList x)
{
	slist* new = (slist*)malloc(sizeof(slist));
	new->next = NULL;
	new->val = x;

	slist* cur = *head;
	*head = new;
	(*head)->next = cur;
}

void slistpopback(slist** head)
{
	slist* tmp = *head;
	slist* cur = NULL;
	if (*head == NULL)
	{
		return;
	}
	else if (tmp->next == NULL)
	{
		*head = NULL;
		free(tmp);
		tmp = NULL;
	}
	while (tmp->next != NULL)
	{
		cur = tmp;
		tmp = tmp->next;
	}
	free(tmp);
	tmp = NULL;
	cur->next = NULL;
}
void slistpopfront(slist** head)
{
	if (*head == NULL)
	{
		return;
	}
	slist* tmp = *head;
	*head = (*head)->next;
	free(tmp);
	tmp = NULL;
}

slist* find(slist* head, SList x)
{
	slist* cur = head;
	while (cur != NULL)
	{
		if (cur->val == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
void slistInsert(slist** head, slist* pos, SList x)
{
	slist* new = (slist*)malloc(sizeof(slist));
	new->next = NULL;
	new->val = x;

	slist* list = *head;
	slist* prev = NULL;
	while (list)
	{
		if (list->val == pos->val)
		{
			if (list == *head)
			{
				*head = new;
				(*head)->next = pos;
			}
			else
			{
				prev->next = new;
				new->next = list;
				break;
			}
		}
		else
		{
			prev = list;
			list = list->next;
		}
	}
}
void slistErase(slist** head, slist* pos)
{
	slist* list = *head;
	slist* prev = NULL;
	while (list->next != pos)
	{
		list = list->next;
	}
	list->next = pos->next;
	free(pos);
	pos = NULL;
}



/*
˫������
���ܣ�ͷ�� β��
	  ͷɾ βɾ
	  ��ӡ ����
	  ������� ���ɾ��
*/


sxlist* buylist(list date)
{
	sxlist* new = (sxlist*)malloc(sizeof(sxlist));
	new->next = NULL;
	new->prev = NULL;
	new->val = date;
	return new;
}


sxlist* listinit()
{
	sxlist* phead = buylist(0);
	phead->next = phead;
	phead->prev = phead;
	return phead;
}
void listdestory(sxlist* phead)
{
	sxlist* cur = phead->next;
	while (cur != phead)
	{
		sxlist* tmp = cur->next;
		free(cur);
		cur = tmp;
	}
	free(phead);
	phead = NULL;

}
void listprint(sxlist* phead)
{
	sxlist* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->val);
		cur = cur->next;
	}
	printf("\n");
}
void listpushback(sxlist* phead, list date)
{
	listinsert(phead,date);
}
void listpushfront(sxlist* phead, list date)
{
	listinsert(phead->next, date);
}


void listpopback(sxlist* phead)
{
	listErase(phead->prev);
}
void listpopfront(sxlist* phead)
{
	listErase(phead->next);
}

sxlist* listfind(sxlist* phead, list date)
{
	sxlist* tmp = phead->next;
	while (tmp != phead)
	{
		if (tmp->val == date)
		{
			return tmp;
		}
		tmp = tmp->next;
	}
	return NULL;
}
void listinsert(sxlist* pos, list date)
{
	sxlist* new = buylist(date);
	sxlist* prev = pos->prev;


	prev->next = new;
	pos->prev = new;
	new->next = pos;
	new->prev = prev;
}
void listErase(sxlist* pos)
{
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
	pos = NULL;
}


/*
ջ
���ܣ���ջ ��ջ
	  ȡջ��Ԫ�� ��ȡԪ�ظ���
	  �п�
*/

void StackInit(st* ps)
{
	ps->a = (STdate*)malloc(sizeof(STdate)*4);
	ps->top = 0;
	ps->capacity = 4;
}
void StackPush(st* ps, STdate date)
{
	if (ps->top == ps->capacity)
	{
		STdate* new = (STdate*)realloc(ps->a, sizeof(STdate) * 2);
		ps->capacity += 2;
	}
	ps->a[ps->top] = date;
	ps->top++;
}
void StackPop(st* ps)
{
	ps->top--;
}
STdate StackTop(st* ps)
{
	return ps->a[ps->top - 1];
}
int StackSize(st* ps)
{
	return ps->top;
}
int StackEmpty(st* ps)
{
	return ps->top == 0;
}
void StackDestory(st* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->top = ps->capacity = 0;
}




/*
����
���ܣ���� ����
	  �п�
*/


// ��ʼ������
void QueueInit(Queue* q)
{
	q->head = NULL;
	q->tail = NULL;
}
// ��β�����
void QueuePush(Queue* q, QDataType data)
{
	QNode* new = (QNode*)malloc(sizeof(QNode));
	new->Next = NULL;
	new->date = data;
	if (q->head == NULL)
	{
		q->head = new;
		q->tail = new;
	}
	else
	{
		q->tail->Next = new;
		q->tail = new;
	}
}
// ��ͷ������
void QueuePop(Queue* q)
{

	QNode* tmp = q->head;
	q->head = q->head->Next;
	free(tmp);
	if (q->head == NULL)
	{
		q->tail = q->head;
	}
	tmp = NULL;
}
// ��ȡ����ͷ��Ԫ��
QDataType QueueFront(Queue* q)
{
	return q->head->date;
}
// ��ȡ���ж�βԪ��
QDataType QueueBack(Queue* q)
{
	return q->tail->date;
}
// ��ȡ��������ЧԪ�ظ���
int QueueSize(Queue* q)
{
	int size = 0;
	QNode* cur = q->head;
	while (cur != NULL)
	{
		size++;
		cur = cur->Next;
	}
}
// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* q)
{
	return q->head == NULL;
}
// ���ٶ���
void QueueDestroy(Queue* q)
{
	QNode* cur = q->head;
	while (cur != NULL)
	{
		QNode* next = cur->Next;
		free(cur);
		cur = next;
	}
	q->head = NULL;
	q->tail = NULL;
}


void printqueue(Queue* q)
{
	QNode* cur = q->head;
	while (cur != NULL)
	{
		printf("%d ", cur->date);
		cur = cur->Next;
	}
	printf("\n");

}


