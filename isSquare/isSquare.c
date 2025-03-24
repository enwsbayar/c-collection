/*
Given an integral number, determine if it's a square number.
*/

#include <stdbool.h>
#include <stdio.h>
#include <math.h>

bool isSquare(int );

int main( )
{
    int number;
    scanf("%d",&number);
    if(isSquare(number))
    {
        printf("True");
    }
    else
    {
        printf("False");
    }
}

bool isSquare(int number)
{
    if(number>=0)
    {
        int n = sqrt(number);
        if(n*n==number)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
    
}