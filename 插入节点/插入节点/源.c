#include <stdio.h>
#include <stdlib.h>
struct tt
{
    int date;
    struct tt* add;
};


int main()
{
    struct tt* list = NULL;
    struct tt* tail = NULL;

    int n = 0;
    int m = 0;
    scanf_s("%d %d", &n, &m);
    int i = 0;
    int tmp = 0;
    for (i = 1; i <= n + 1; i++)
    {
        if (m != i - 1)
        {
            scanf_s("%d", &tmp);
        }
        else
        {
            tmp = m;
        }
        struct tt* pn = (struct tt*)malloc(sizeof(struct tt));
        pn->date = tmp;
        pn->add = NULL;
        if (list == NULL)
        {
            list = pn;
            tail = pn;
        }
        else
        {
            tail->add = pn;
            tail = pn;
        }
    }
    struct tt* cur = list;
    while (cur)
    {
        printf("%d ", cur->date);
        cur = cur->add;
    }
    return 0;
}