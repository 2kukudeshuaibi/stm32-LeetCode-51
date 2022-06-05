#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
typedef struct Queue
{
    struct Queue* next;
    int date;
}q;

typedef struct Q
{
    q* head;
    q* tail;
}queue;
void QueueInit(queue* pq);
void Queuedestory(queue* pq);

//队尾入
void Queuepush(queue* pq, int x);

//队头出
void Queuepop(queue* pq);

int Queuefront(queue* pq);
int Queueback(queue* pq);

int Queuesize(queue* pq);
int QueueEmpty(queue* pq);



typedef struct
{
    queue q1;
    queue q2;
} MyStack;

void QueueInit(queue* pq)
{
    assert(pq);

    pq->head = NULL;
    pq->tail = NULL;
}

void Queuedestory(queue* pq)
{
    assert(pq);
    q* cur = pq->head;
    while (cur)
    {
        q* next = cur->next;
        free(cur);
        cur = next;
    }
    pq->head = NULL;
    pq->tail = NULL;
}

void Queuepush(queue* pq, int x)
{
    assert(pq);
    q* new = (q*)malloc(sizeof(q));
    if (new == NULL)
    {
        printf("malloc fail\n");
        return;
    }
    new->date = x;
    new->next = NULL;
    if (pq->head == NULL)
    {
        pq->head = new;
        pq->tail = new;
    }
    else
    {
        pq->tail->next = new;
        pq->tail = pq->tail->next;
    }
}

void Queuepop(queue* pq)
{
    assert(pq);
    assert(pq->head);

    if (pq->head->next == NULL)
    {
        free(pq->head);
        pq->head = pq->tail = NULL;
    }
    else
    {
        q* next = pq->head->next;
        free(pq->head);
        pq->head = next;
    }
}

int Queuefront(queue* pq)
{
    assert(pq);
    assert(pq->head);
    return pq->head->date;
}

int Queueback(queue* pq)
{
    assert(pq);
    assert(pq->head);


    return pq->tail->date;
}
int Queuesize(queue* pq)
{
    q* cur = pq->head;
    int size = 0;
    while (cur)
    {
        size++;
        cur = cur->next;
    }
    return size;
}
int QueueEmpty(queue* pq)
{
    assert(pq);
    return pq->head == NULL;
}

MyStack* myStackCreate()
{
    MyStack* ps = (MyStack*)malloc(sizeof(MyStack));
    if (ps == NULL)
    {
        printf("malloc fail\n");
        exit(-1);
    }
    QueueInit(&ps->q1);
    QueueInit(&ps->q2);

    return ps;
}

void myStackPush(MyStack* obj, int x)
{
    if (!QueueEmpty(&obj->q1))
    {
        Queuepush(&obj->q1, x);
    }
    else
    {
        Queuepush(&obj->q2, x);
    }

}

int myStackPop(MyStack* obj)
{
    queue* empty = &(obj->q1);
    queue* nonempty = &(obj->q2);
    if (!QueueEmpty(&(obj->q1)))
    {
        empty = &obj->q2;
        nonempty = &obj->q1;
    }
    while (Queuesize(nonempty) > 1)
    {
        Queuepush(empty, Queuefront(nonempty));
        Queuepop(nonempty);
    }
    int top = Queuefront(nonempty);
    Queuepop(nonempty);
    return top;
}

int myStackTop(MyStack* obj)
{
    if (!QueueEmpty(&obj->q1))
    {
        return Queueback(&obj->q1);
    }
    else
    {
        return Queueback(&obj->q2);
    }
}

bool myStackEmpty(MyStack* obj)
{
    return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
}

void myStackFree(MyStack* obj)
{
    Queuedestory(&obj->q1);
    Queuedestory(&obj->q2);

    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);

 * int param_2 = myStackPop(obj);

 * int param_3 = myStackTop(obj);

 * bool param_4 = myStackEmpty(obj);

 * myStackFree(obj);
*/

int main()
{
    return 0;
}