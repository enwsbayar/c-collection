/*
Reverse Number is a number which is the same when reversed.

For example, the first 20 Reverse Numbers are:

0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 22, 33, 44, 55, 66, 77, 88, 99, 101
TASK:

You need to return the nth reverse number. (Assume that reverse numbers start from 0 as shown in the example.)
NOTES:

1 < n <= 100000000000
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <stdbool.h>

long long int findReverseNumber(long long int );

int main( )
{
    printf("%lld",findReverseNumber(100));

    return 0;
}

long long int findReverseNumber(long long int number)
{
    number = number - 1;
    long long counter = 0;
    for(long long int i = 2;i <=100000000000;i++)
    {
        long long int temp = i;
        long long int reversed = 0;
        while (temp != 0)
        {
            long long int digit = temp % 10;
            reversed = reversed * 10 + digit;
            temp /= 10;
        }
        if(i == reversed)
        {
            counter++;
        }
        if(counter == number)
        {
            return i;
        }
    }
    return 0;
}
