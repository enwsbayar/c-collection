/*
Write a function named sumDigits which takes a number as input and
returns the sum of the absolute value of each of the number's decimal digits.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int sumDigits(int );

int main( )
{
    int number;
    scanf("%d",&number);
    printf("%d",sumDigits(number));
    return 0;
}

int sumDigits(int number)
{
    int remainder,total=0;
    while(number!=0)
    {
        remainder = abs(number%10);
        total += remainder;
        number = number/10;
    }
    return total;
}