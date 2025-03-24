/*
Greed is a dice game played with five six-sided dice.
Your mission, should you choose to accept it, is to score a throw according to these rules. You will always be given an array with five six-sided dice values.

 Three 1's => 1000 points
 Three 6's =>  600 points
 Three 5's =>  500 points
 Three 4's =>  400 points
 Three 3's =>  300 points
 Three 2's =>  200 points
 One   1   =>  100 points
 One   5   =>   50 point
A single die can only be counted once in each roll.
For example, a given "5" can only count as part of a triplet (contributing to the 500 points) or as a single 50 points, but not both in the same roll.

Example scoring

 Throw       Score
 ---------   ------------------
 5 1 3 4 1   250:  50 (for the 5) + 2 * 100 (for the 1s)
 1 1 1 3 1   1100: 1000 (for three 1s) + 100 (for the other 1)
 2 4 4 5 4   450:  400 (for three 4s) + 50 (for the 5)
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <stdbool.h>

int score(const int* );

int main( )
{
    int dice[5] = {1,1,1,3,1};
    printf("%d",score(dice));
}

int score(const int* dice)
{
    int oneCounter = 0,twoCounter = 0,threeCounter = 0,fourCounter = 0,fiveCounter = 0,sixCounter = 0,score = 0;
    for(int i = 0;i < 5;i++)
    {
        if(dice[i] == 1)
        {
            oneCounter++;
        }
        else if(dice[i] == 2)
        {
            twoCounter++;
        }
        else if(dice[i] == 3)
        {
            threeCounter++;
        }
        else if(dice[i] == 4)
        {
            fourCounter++;
        }
        else if(dice[i] == 5)
        {
            fiveCounter++;
        }
        else if(dice[i] == 6)
        {
            sixCounter++;
        }
    }
    if(twoCounter / 3 >= 1)
    {
        score += 200;
    }
    if(threeCounter / 3 >= 1)
    {
        score += 300;
    }
    if(fourCounter / 3 >= 1)
    {
        score += 400;
    }
    if(sixCounter / 3 >= 1)
    {
        score += 600;
    }
    if(oneCounter / 3 >= 1)
    {
        score += 1000 + (oneCounter % 3) * 100;
    }
    else
    {
        score += (oneCounter % 3) * 100;
    }
    if(fiveCounter / 3 >= 1)
    {
        score += 5000 + (fiveCounter % 3) * 50;
    }
    else
    {
        score += (fiveCounter % 3) * 50;
    }
    return score;
}