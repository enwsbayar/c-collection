/*
Given an integer as input, can you round it to the next (meaning, "greater than or equal") multiple of 5?

Examples:

input:    output:
0    ->   0
2    ->   5
3    ->   5
12   ->   15
21   ->   25
30   ->   30
-2   ->   0
-5   ->   -5
etc.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>

int roundToNext5(int );

int main( )
{
    int number;
    scanf("%d",&number);
    printf("%d",roundToNext5(number));

    return 0;
}

int roundToNext5(int number)
{
    if(number % 5 == 0)
    {
        return number;
    }
    else
    {
        while(number % 5 != 0)
        {
            number++;
        }
        return number;
    }

}