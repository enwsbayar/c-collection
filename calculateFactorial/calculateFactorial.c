/*
In mathematics, the factorial of integer n is written as n!. It is equal to
the product of n and every integer preceding it. For example: 5! = 1 x 2 x 3 x 4 x 5 = 120

Your mission is simple: write a function that takes an integer n and returns the value of n!.

You are guaranteed an integer argument. For any values outside the non-negative range,
return null, nil or None (return an empty string "" in C and C++). For non-negative numbers
a full length number is expected for example, return 25! =  "15511210043330985984000000"  as a string.

For more on factorials, see http://en.wikipedia.org/wiki/Factorial
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <stdbool.h>

char* factorial(int n);

int main( )
{
    printf("%s",factorial(5));
}

char* factorial(int n)
{
    char* result = (char*)malloc(300 * sizeof(char));
    int intResult = 1;
    for(int i = 1;i <= n;i++)
    {
        intResult *= i;
    }
    int length = 0;
    int tempIntResult = intResult;
    while(tempIntResult > 0)
    {
        tempIntResult /= 10;
        length++;
    }

    int counter = length - 1;

    while(intResult > 0)
    {
        result[counter] = '0' + (intResult % 10);
        intResult /= 10;
        counter--;
    }
    result[length] = '\0';
    return result;
}