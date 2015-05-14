//
//  main.c
//  TreeDemo
//
//  Created by panda zheng on 15/5/14.
//  Copyright (c) 2015年 panda zheng. All rights reserved.
//

//输入方式
//ABC@@D@@E@F@@  @代标空格

#include <stdio.h>
#include <stdlib.h>

typedef struct BiTNode
{
    char data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

//创建二叉树
void CreateBiTree(BiTree *T)
{
    char c;
    scanf("%c",&c);
    if (c == ' ')
        *T = NULL;
    else
    {
        *T = (BiTNode*)malloc(sizeof(BiTNode));
        (*T)->data = c;
        CreateBiTree(&((*T)->lchild));
        CreateBiTree(&((*T)->rchild));
    }
}

//访问二叉树结点，输出包含D字符结点位于二叉树中的层数
void visit(char c,int level)
{
    if ('D' == c)
    {
        printf("%c is at %d level of BiTree\n",c,level);
    }
}

//遍历二叉树
void PreOrderTraverse(BiTree T,int level)
{
    if (T)
    {
        visit(T->data, level);
        PreOrderTraverse(T->lchild, level+1);
        PreOrderTraverse(T->rchild, level+1);
    }
}

int main(int argc, const char * argv[]) {

    int level = 1;
    printf("CreateTree......\n");
    BiTree T = NULL;  //最开始Ｔ指向空
    CreateBiTree(&T);   //创建二叉树
    PreOrderTraverse(T, level);   //遍历二叉树，找到包含D字符结点位于二叉树中的层数s
    return 0;
}
