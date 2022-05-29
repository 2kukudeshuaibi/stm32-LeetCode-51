#define _CRT_SECURE_NO_WARNINGS 1
#include "list.h"


tt* buylist(int x)
{
    tt* new = (tt*)malloc(sizeof(tt));
    new->date = x;
    new->next = NULL;
    new->prev = NULL;
    return new;
}

tt* listinit()
{
    tt* phead = buylist(0);
    phead->next = phead;
    phead->prev = phead;

    return phead;
}

void listprint(const tt* phead)
{
    tt* cur = phead;
    cur = cur->next;
    while (cur!=phead)
    {
        printf("%d ", cur->date);
        cur = cur->next;
    }
    printf("\n");
}

void listdestory(tt* phead)
{
    tt* cur = phead->next;
    while (cur != phead)
    {
        tt* list = cur->next;
        free(cur);
        cur = list;
    }

    free(phead);
    phead = NULL;

}

void listpushback(tt* phead, int x)
{
    /*tt* tail = phead->prev;
    tt* new = buylist(x);
    tail->next = new;
    new->prev = tail;

    new->next = phead;
    phead->prev = new;*/
    listinsert(phead,x);
}

void listpushfront(tt* phead, int x)
{
    /*tt* new = buylist(x);
    tt* tail = phead->next;
    phead->next = new;
    new->prev = phead;
    
    new->next = tail;
    tail->prev = new;*/
    listinsert(phead->next, x);
}

void listpopfront(tt* phead)
{
    /*assert(phead);
    assert(phead->next != phead);

    tt* list = phead->next;
    tt* sceond = list->next;
    phead->next = sceond;
    sceond->prev = phead;

    free(list);
    list = NULL;*/
    listdele(phead->next);
}
void listpopback(tt* phead)
{
    /*assert(phead);
    assert(phead->next != phead);

    tt* tail = phead->prev;

    phead->prev = tail->prev;
    tail->prev->next = phead;

    free(tail);
    tail = NULL;*/
    listdele(phead->prev);
}

tt* listfind(tt* phead, int x)
{
    tt* list = phead->next;
    while (list != phead)
    {
        if (list->date == x)
        {
            return list;
        }
        else
        {
            list = list->next;
        }
    }
    return  NULL;
}

void listinsert(tt* pos, int x)
{
    assert(pos);
    tt* new = buylist(x);
    tt* list = pos->prev;

    list->next = new;
    new->prev = list;
    new->next = pos;
    pos->prev = new;
}
void listdele(tt* pos)
{
    assert(pos);

    pos->prev->next = pos->next;
    pos->next->prev = pos->prev;

    free(pos);
    pos = NULL;
}