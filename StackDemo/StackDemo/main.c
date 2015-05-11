//
//  main.c
//  StackDemo
//
//  Created by panda zheng on 15/5/11.
//  Copyright (c) 2015年 panda zheng. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define STACK_INIT_SIZE 20
#define STACKINCREMENT 10

typedef char ElemType;

typedef struct
{
    ElemType *base;
    ElemType *top;
    int stacksize;
}SqStack;

void initStack(SqStack *s)
{
    /*内存中开辟一段续的空间*/
    s->base = (ElemType*)malloc(STACK_INIT_SIZE * sizeof(ElemType));
    if (s->base == NULL)
    {
        printf("分配空间失败\n");
        return;
    }
    s->top = s->base;
    s->stacksize = STACK_INIT_SIZE;
}

void Push(SqStack *s,ElemType e)
{
    if (s->top - s->base >= s->stacksize)
    {
        s->base = (ElemType*)realloc(s->base, (s->stacksize + STACKINCREMENT) * sizeof(ElemType));
        if (s->base)
        {
            printf("重新申请空间失败\n");
            return;
        }
        s->top = s->base + s->stacksize;
        s->stacksize = s->stacksize + STACKINCREMENT;
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

void ClearStack(SqStack *s)
{
    s->top = s->base;
}

void DestoryStack(SqStack *s)
{
    int i,len;
    len = s->stacksize;
    for (i = 0 ; i < len ; i++)
    {
        free(s->base);
        s->base++;
    }
    s->base = s->top = NULL;
    s->stacksize = 0;
}

int StackLen(SqStack s)
{
    return (int)(s.top - s.base);
}

int main(int argc, const char * argv[]) {
    
    
    ElemType c;
    SqStack s;
    int len,i,sum = 0;
    
    printf("Please input a Binary digit\n");
    
    initStack(&s);
    scanf("%c",&c);
    while (c!= '#')
    {
        Push(&s, c);
        scanf("%c",&c);
    }
    getchar();
    
    len = StackLen(s);
    
    for (i = 0 ; i <len ; i++)
    {
        Pop(&s, &c);
        sum = sum + (c-48) * pow(2, i);
    }
    printf("Decimal is %d\n",sum);
    return 0;
}
