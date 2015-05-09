//
//  main.c
//  CrapsGame
//
//  Created by panda zheng on 15/5/9.
//  Copyright (c) 2015年 panda zheng. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIN 0
#define LOST 1
#define CONTINUE 2

int rollDice()
{
    return rand() % 6 + rand() % + 2;
}

int main(int argc, const char * argv[]) {
    int firstRoll = 1;
    int gameStatus = CONTINUE;
    int sumOfDice;
    int firstPoint = 0;
    char c;
    
    srand((unsigned int)time(0));
    
    printf("Craps赌博游戏，按Enter键开始游戏");
    
    while(1)
    {
        getchar();
        
        if (firstRoll)
        {
            sumOfDice = rollDice();
            printf("\n玩家掷出点数的和: %d\n",sumOfDice);
            
            switch (sumOfDice)
            {
                case 7:
                case 11:
                    gameStatus = WIN;
                    break;
                case 2:
                case 3:
                case 12:
                    gameStatus = LOST;
                    break;
                default:
                    firstRoll = 0;
                    gameStatus = CONTINUE;
                    firstPoint = sumOfDice;
                    break;
            }
        }
        else
        {
            sumOfDice = rollDice();
            printf("\n玩家掷出点数和: %d\n",sumOfDice);
            
            if (sumOfDice == firstPoint)
                gameStatus = WIN;
            else if (sumOfDice == 7)
                gameStatus = LOST;
        }
        
        if (gameStatus == CONTINUE)
        {
            puts("未分胜负，再掷一次\n");
        }
        else
        {
            if (gameStatus == WIN)
                puts("玩家胜");
            else
                puts("玩家输");
            
            printf("再来一次？");
            scanf("%c",&c);
            if (c == 'n')
            {
                puts("游戏结束");
                break;
            }
            firstRoll = 1;
        }
    }
    
    return 0;
}
