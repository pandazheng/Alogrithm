//
//  main.c
//  QueueDemo
//
//  Created by panda zheng on 15/5/13.
//  Copyright (c) 2015年 panda zheng. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>



typedef char ElemType;

typedef struct QNode
{
    ElemType data;
    struct QNode *next;
}QNode,*QueuePtr;

typedef struct
{
    QueuePtr front; //队头指针
    QueuePtr rear;  //队尾指针
}LinkQueue;

void InitQueue(LinkQueue *q)
{
    //初始化一个空队列
    q->front = q->rear = (QueuePtr)malloc(sizeof(QNode));
    if (!q->front)
    {
        printf("create front failed\n");
        return;
    }
    q->front->next = NULL;
}

void EnQueue(LinkQueue *q,ElemType e)
{
    QueuePtr p;
    p = (QueuePtr)malloc(sizeof(QNode));
    p->data = e;
    p->next = NULL;
    q->rear->next = p;
    q->rear = p;
}

void DeQueue(LinkQueue *q,ElemType *e)
{
    QueuePtr p;
    if (q->front == q->rear)
    {
        return;
    }
    
    p = q->front->next;
    *e = p->data;
    q->front->next = p->next;
    if (q->rear == p)
        q->rear = q->front;
    free(p);
}

int main(int argc, const char * argv[]) {

    ElemType e;
    LinkQueue q;
    InitQueue(&q);
    printf("Please input a string into a queue\n");
    scanf("%c",&e);
    while (e != '@')
    {
        EnQueue(&q, e);
        scanf("%c",&e);
    }
    printf("The string into the queue is \n");
    while (q.front != q.rear)
    {
        DeQueue(&q, &e);
        printf("%c",e);
    }
    printf("\n");
    return 0;
}
