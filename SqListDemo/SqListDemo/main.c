//
//  main.c
//  SqListDemo
//
//  Created by panda zheng on 15/5/10.
//  Copyright (c) 2015年 panda zheng. All rights reserved.
//

#include <stdio.h>

#define MAXSIZE 10

/*静态顺序表的各种操作*/

//插入元素
void insertElem(int Sqlist[],int *len,int i,int x)
{
    int t;
    
    if ( i < 1 || i > *len)
    {
        printf("插入元素位置错误\n");
    }
    
    for (t = *len - 1 ; t >= i - 1 ; t--)
        Sqlist[t+1] = Sqlist[t];
    
    Sqlist[i-1] = x;
    
    *len = *len + 1;
}

//删除元素 删除第i个元素
void DeleteElem(int Sqlist[],int *len,int i)
{
    int t;
    
    if (i < 1 || i > *len - 1)
    {
        printf("删除元素的位置错误");
    }
    
    for (t = i ; t <= *len - 1 ; t++)
        Sqlist[t - 1] = Sqlist[t];
    
    *len = *len - 1;
}

int main(int argc, const char * argv[]) {
    
    int Sqlist[MAXSIZE];
    int i;
    int len;
    
    printf("输入6个整数: ");
    for (i = 0 ; i < 6 ; i++)
    {
        scanf("%d",&Sqlist[i]);
    }
    
    len = 6;
    printf("SqList:\n");
    for (i = 0 ; i < 6 ; i++)
    {
        printf("%d ",Sqlist[i]);
    }
    printf("\n");
    
    insertElem(Sqlist, &len, 3, 5);
    for (i = 0 ; i < len ; i++)
    {
        printf("%d ",Sqlist[i]);
    }
    printf("\n");
    
    DeleteElem(Sqlist, &len, 4);
    for (i = 0 ; i < len ; i++)
    {
        printf("%d ",Sqlist[i]);
    }
    
    return 0;
}
