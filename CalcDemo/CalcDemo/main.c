//
//  main.c
//  CalcDemo
//
//  Created by panda zheng on 15/5/13.
//  Copyright (c) 2015年 panda zheng. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define STACK_INIT_SIZE 20

#define STACK_INCREMENT 10

typedef char ElemType;

typedef struct
{
    ElemType *base;
    ElemType *top;
    int stacksize;
}SqStack;

void InitStack(SqStack *s)
{
    //内存开辟
    s->base = (ElemType*)malloc(STACK_INIT_SIZE * sizeof(ElemType));
    if (!s->base)
    {
        printf("malloc failed\n");
        return;
    }
    
    s->top = s->base;
    s->stacksize = 0;
}

void Push(SqStack *s,ElemType e)
{
    if (s->top - s->base >= s->stacksize)
    {
        s->base = (ElemType*)realloc(s->base, (s->stacksize + STACK_INCREMENT)*sizeof(ElemType));
        if (!s->base)
        {
            printf("realloc failed\n");
            return;
        }
        s->top = s->base + s->stacksize;
        s->stacksize = s->stacksize + STACK_INCREMENT;
    }
    *(s->top) = e;
    s->top++;
}

void Pop(SqStack *s,ElemType *e)
{
    if (s->top == s->base)
        return;
    *e = *(--s->top);
}

int StackLen(SqStack *s)
{
    return (unsigned)s->top - (unsigned)s->base;
}

int main(int argc, const char * argv[]) {
    SqStack s;
    char c,e;
    
    InitStack(&s);
    
    printf("请输入中缀表达式，以#作为结束标志:");
    scanf("%c",&c);
    
    while (c != '#')
    {
        while ( c >= '0' && c <= '9')
        {
            printf("%c",c);
            scanf("%c",&c);
            if (c < '0' || c > '9')
            {
                printf(" ");
            }
        }
        
        if (')' == c)
        {
            Pop(&s, &e);
            while ( '(' != e) {
                printf("%c ",e);
                Pop(&s, &e);
            }
        }
        else if ('+' == c || '-' == c)
        {
            if ( !StackLen(&s))
            {
                Push(&s, c);
            }
            else
            {
                do
                {
                    Pop(&s, &e);
                    if ('(' == e)
                    {
                        Push(&s, e);
                    }
                    else
                    {
                        printf("%c ",e);
                    }
                }while ( StackLen(&s) && '(' != e);
                Push(&s, c);
            }
        }
        else if ('*' == c || '/' == c || '(' == c)
        {
            Push(&s, c);
        }
        else if ('#' == c)
        {
            break;
        }
        else
        {
            printf("\n用户输入错误!\n");
            return -1;
        }
        scanf("%c",&c);
    }
    
    while (StackLen(&s)) {
        Pop(&s, &e);
        printf("%c ",e);
    }
    return 0;
}
