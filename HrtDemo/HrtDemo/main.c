//
//  main.c
//  HrtDemo
//
//  Created by panda zheng on 15/5/10.
//  Copyright (c) 2015年 panda zheng. All rights reserved.
//

#include <stdio.h>

static int count = 0;
//将x上的n个盘子通过y移动到z
void movefunc(int n,char x,char y,char z)
{
    if (n == 1)
    {
        printf("第%d步: %c---->%c\n",++count,x,z);
    }
    else
    {
        movefunc(n-1, x, z, y);
        printf("第%d步: %c---->%c\n",++count,x,z);
        movefunc(n-1, y, x, z);
    }
}

int main(int argc, const char * argv[]) {

    int n;
    printf("请输入有几个盘: ");
    scanf("%d",&n);
    movefunc(n, 'X', 'Y', 'Z');
    printf("一共需要%d步!",count);
    return 0;
}
