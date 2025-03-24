/*
Some numbers have funny properties. For example:

89 --> 8¹ + 9² = 89 * 1
695 --> 6² + 9³ + 5⁴= 1390 = 695 * 2
46288 --> 4³ + 6⁴+ 2⁵ + 8⁶ + 8⁷ = 2360688 = 46288 * 51
Given two positive integers n and p, we want to find a positive integer k, if it exists,
 that the sum of the digits of n raised to consecutive powers starting from p is equal to k * n.


Examples:
n = 89; p = 1 ---> 1 since 8¹ + 9² = 89 = 89 * 1

n = 92; p = 1 ---> -1 since there is no k such that 9¹ + 2² equals 92 * k

n = 695; p = 2 ---> 2 since 6² + 9³ + 5⁴= 1390 = 695 * 2

n = 46288; p = 3 ---> 51 since 4³ + 6⁴+ 2⁵ + 8⁶ + 8⁷ = 2360688 = 46288 * 51
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>

int digPow(int ,int );

int main( )
{
    int n= 114 ,p = 3;

    printf("%d",digPow(n,p));

    return 0;
}

int digPow(int n,int p)
{
    int length = 0,nTemp = n,nTemp2 = n;
    while(nTemp != 0)
    {
        nTemp /= 10;
        length++;
    }
 
    int total = 0,remainder = 0,result;
    while(nTemp2 != 0)
    {
        remainder = nTemp2 % 10;
        total += pow(remainder,length+p-1);
        length--;
        nTemp2 = nTemp2/10;
    }
    if(total % n == 0)
    {
        result = total/n;
    }
    else
    {
        result = -1;
    }
    return result;
}

