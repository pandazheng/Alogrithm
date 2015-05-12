//
//  main.c
//  KingLost
//
//  Created by panda zheng on 15/5/12.
//  Copyright (c) 2015年 panda zheng. All rights reserved.
//

#include <stdio.h>
#include <math.h>

int main(int argc, const char * argv[]) {

    int i;
    double sum = 0;
    
    for (i = 1 ; i <= 64 ; i++)
    {
        sum = sum + pow(2, (i-1));
    }
    printf("sum = %f\n",sum);
    return 0;
}
