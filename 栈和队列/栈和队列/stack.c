#define _CRT_SECURE_NO_WARNINGS 1

#include "stack.h"

void Stackinit(ST* ps)
{
    assert(ps);
    ps->a = (int*)malloc(sizeof(int)*4);
    ps->capacity = 4;
    ps->top = 0;
}
void StackDestory(ST* ps)
{
    assert(ps);
    free(ps->a);
    ps->a = NULL;
    ps->top = ps->capacity = 0;
}


//入栈
void Stackpush(ST* ps, int x)
{
    assert(ps);
    if (ps->top == ps->capacity)
    {
        int* tmp = (int*)realloc(ps->a, ps->capacity*2*sizeof(int));
        if (tmp == NULL)
        {
            printf("realloc fail\n");
            return;
        }
        ps->a = tmp;
        ps->capacity *= 2;
        printf("增容成功\n");
    }
    ps->a[ps->top] = x;
    ps->top++;
}
//出栈
void Stackpop(ST* ps)
{
    assert(ps);
    assert(ps->top > 0);
    ps->top--;
}

int Stacktop(ST* ps)
{
    assert(ps);
    assert(ps->top > 0);
    return ps->a[ps->top-1];
}
int Stackszie(ST* ps)
{
    assert(ps);
    return ps->top;
}
int StackEmpty(ST* ps)
{
    assert(ps);
    return ps->top == 0;
}
