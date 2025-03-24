/*
Given a sequence of numbers, find the largest pair sum in the sequence.

For example

[10, 14, 2, 23, 19] -->  42 (= 23 + 19)
[99, 2, 2, 23, 19]  --> 122 (= 99 + 23)
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>

int main( )
{
    int numbers[5] = {2,5,6,8,9};
    printf("%lld",largestPairSum(5,numbers));
    return 0;

}

long long int largestPairSum(size_t length, const int* ptr)
{
    long long firstNum = INT_MIN,secondNum = INT_MIN,counter=0;
    long long result=0;

    for(int i=0;i<length;i++)
    {
        if(ptr[i] > firstNum)
        {
            firstNum = ptr[i];
        }
    }

    for(int k=0;k<length;k++)
    {
        if(ptr[k]==firstNum)
        {
            counter++;
        }
    }

    if(counter>=2)
    {
        result = 2*firstNum;
    }
    else
    {
        for(int j=0;j<length;j++)
        {
            if(ptr[j]>secondNum&&ptr[j]<firstNum)
            {
                secondNum = ptr[j];
            }
        }
        result = firstNum+secondNum;
    }
    return result;
}