//
//  main.c
//  ListDemo
//
//  Created by panda zheng on 15/5/10.
//  Copyright (c) 2015年 panda zheng. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10


typedef int ElemType;    //将int定义为ElemType

typedef struct
{
    int *elem;    //数组data，存储位置就是线性表存储空间的存储位置
    int length;   //线性表的最大存储容量,MAXSIZE
    int listsize;  //线性表的长度 length
}SqList;

//初始化一个顺序表
void initSqList(SqList *L)
{
    L->elem = (int *)malloc(MAXSIZE * sizeof(ElemType));
    L->length = 0;
    L->listsize = MAXSIZE;
}

//向顺序表中插入元素
void InsertElemt(SqList *L,int i,ElemType item)
{
    ElemType *base , *insertPtr , *p;
    if (i < 1 || i > L->length + 1)
    {
        printf("Insert Element failed\n");
        return;
    }
    
    if (L->length >= L->listsize)
    {
        base = (ElemType*)realloc(L->elem, (L->listsize+100)*sizeof(ElemType));
        L->elem = base;
        L->listsize = L->listsize + 100;
    }
    
    insertPtr = &(L->elem[i-1]);
    for (p = &(L->elem[L->length - 1]) ; p >= insertPtr ; p--)
    {
        *(p+1) = *p;
    }
    * insertPtr = item;
    L->length++;
}

//从顺序表中删除元素
void DeleElem(SqList *L,int i)
{
    ElemType *q,*delPtr;
    if ( i < 1 || i > L->length + 1)
    {
        printf("Delete Element failed\n");
        return;
    }
    
    delPtr = &(L->elem[i-1]);
    q = L->elem + L->length - 1;
    for (++delPtr ; delPtr <= q ; delPtr++)
    {
        *(delPtr - 1) = * delPtr;
    }
    L->length--;
    
}

int main(int argc, const char * argv[]) {
    SqList l;
    int i;
    
    initSqList(&l);
    for (i = 0 ; i < 15 ; i++)
        InsertElemt(&l, i+1, i+1);
    
    printf("The content of the list is \n");
    for (i = 0 ; i < 15 ; i++)
        printf("%d ",l.elem[i]);
    printf("\n");
    DeleElem(&l, 5);
    printf("Delete the fifth element\n");
    for (i = 0 ; i < l.length ; i++)
    {
        printf("%d ",l.elem[i]);
    }
    printf("\n");
    return 0;
}
