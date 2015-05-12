//
//  main.c
//  GcdAndLcm
//
//  Created by panda zheng on 15/5/12.
//  Copyright (c) 2015年 panda zheng. All rights reserved.
//

#include <stdio.h>

//最大公约数
int gcd(int a,int b)
{
    int min;
    if (a <= 0 || b <= 0)
        return -1;
    if (a > b)
        min = b;
    else
        min = a;
    
    while (min)
    {
        if (a % min == 0 && b % min == 0)
        {
            return min;
        }
        min--;
    }
    
    return -1;
}

//最大公倍数
int lcm(int a,int b)
{
    int max;
    if (a <= 0 || b <= 0)
        return -1;
    if (a > b)
        max = a;
    else
        max = b;
    
    while (max)
    {
        if (max % a == 0 && max % b == 0)
        {
            return max;
        }
        max++;
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    int a,b;
    printf("please input two digit for getting for GCD and LCM\n");
    scanf("%d %d",&a,&b);
    
    printf("The GCD of %d and %d is %d\n",a,b,gcd(a,b));
    
    printf("The LCM of %d and %d is %d\n",a,b,lcm(a,b));
    return 0;
}
