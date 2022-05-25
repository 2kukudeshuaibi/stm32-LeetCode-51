#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct tt
{
    int date;
    struct tt* add;
}typedef tt;

int main()
{
    tt* list = NULL;
    tt* tail = NULL;
    int n = 0;
    int i = 0;
    int tmp = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &tmp);
        tt* pd = (tt*)malloc(sizeof(tt));
        pd->date = tmp;
        pd->add = NULL;

        if (list == NULL)
        {
            list = pd;
            tail = pd;
        }
        else
        {
            tail->add = pd;
            tail = pd;
        }
    }
    tt* cur1 = list;
    tt* cur2 = list;
    tt* cur3 = list;

    for (i = 0; i < 1; i++)
    {
        cur2 = cur2->add;
    }
    for (i = 0; i < 2; i++)
    {
        cur3 = cur3->add;
    }
    list = cur2;
    cur1->add = cur3;
    cur2->add = cur1;

    tt* prev = NULL;
    tt* cur4 = list;
    while (cur4->add != NULL)
    {
        prev = cur4;
        cur4 = cur4->add;
    }
    tt* cur5 = list;
    for (i = 0; i < n - 3; i++)
    {
        cur5 = cur5->add;
    }
    cur5->add = cur4;
    cur4->add = prev;
    prev->add = NULL;

    for (i = 0; i < n; i++)
    {
        printf("%d ", list->date);
        list = list->add;
    }
    return 0;
}