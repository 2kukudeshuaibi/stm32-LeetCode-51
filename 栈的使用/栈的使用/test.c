#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<assert.h>

struct Stack
{
    char* a;
    int top;
    int capacity;
}typedef ST;

void Stackinit(ST* ps)
{
    assert(ps);
    ps->a = (char*)malloc(sizeof(char) * 4);
    ps->capacity = 4;
    ps->top = 0;
}
void StackDestory(ST* ps)
{
    assert(ps);
    free(ps->a);
    ps->a = NULL;
    ps->capacity = ps->top = 0;
}
//ÈëÕ»
void Stackpush(ST* ps, char x)
{
    assert(ps);
    if (ps->top == ps->capacity)
    {
        char* tmp = (char*)realloc(ps->a, ps->capacity * 2 * sizeof(char));
        ps->a = tmp;
        ps->capacity *= 2;
    }
    ps->a[ps->top] = x;
    ps->top++;
}
//³öÕ»
void Stackpop(ST* ps)
{
    assert(ps);
    assert(ps->top > 0);
    ps->top--;
}
char Stacktop(ST* ps)
{
    assert(ps);
    return ps->a[ps->top - 1];
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



bool isValid(char* s)
{
    ST st;
    int flag = 0;
    Stackinit(&st);
    while (*s != '\0')
    {
        switch (*s)
        {
        case '{':
        case '[':
        case '(':
        {
            Stackpush(&st, *s);
            s++;
            break;
        }
        case '}':
        case ']':
        case ')':
        {
            if (StackEmpty(&st))
            {
                StackDestory(&st);
                return false;
            }
            char top = Stacktop(&st);
            Stackpop(&st);
            if ((*s == '}' && top != '{') || (*s == ']' && top != '[') || (*s == ')' && top != '('))
            {
                StackDestory(&st);
                return false;
            }
            else
            {
                s++;
            }
            break;
        }
        }
    }
    bool ret = StackEmpty(&st);
    StackDestory(&st);

    return ret;
}


int main()
{
    char* arr = "{[]";
    int a = isValid(arr);
    printf("%d ", a);
    return 0;
}