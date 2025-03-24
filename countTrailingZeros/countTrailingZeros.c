/*
Write a program that will calculate the number of trailing zeros in a factorial of a given number.

N! = 1 * 2 * 3 *  ... * N

Be careful 1000! has 2568 digits...

For more info, see: http://mathworld.wolfram.com/Factorial.html

Examples
zeros(6) = 1
# 6! = 1 * 2 * 3 * 4 * 5 * 6 = 720 --> 1 trailing zero

zeros(12) = 2
# 12! = 479001600 --> 2 trailing zeros
Hint: You're not meant to calculate the factorial. Find another way to find the number of zeros.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <stdbool.h>

long zeros(long );

int main( )
{
    int number;
    scanf("%d",&number);
    printf("%ld",zeros(number));
}

long zeros(long n)
{
    long int counter = 0;
    for(long int i = 1;i <= n;i++)
    {
        long int temp = i;
        if(i % 5 == 0)
        {
            while(temp % 5 == 0)
            {
                counter++;
                temp/=5;
            }
        }
    }
    return counter; 
}

