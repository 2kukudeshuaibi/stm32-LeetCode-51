#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
struct Tdate
{
    int date;
    struct Tdate* add;
};
int main()
{
    struct Tdate* list = NULL;
    struct Tdate* tail = NULL;
    int n = 0;
    scanf("%d", &n);
    int i = 0;
    int m = 0;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &m);
        struct Tdate* pn = (struct Tdate*)malloc(sizeof(struct Tdate));
        pn->date = m;
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
    struct Tdate* cur = list;
    int sum = 0;
    while (cur)
    {
        sum = sum + cur->date;
        cur = cur->add;
    }
    printf("%d", sum);
    return 0;
}