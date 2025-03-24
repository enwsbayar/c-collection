/*
Given a list of integers, determine whether the sum of its elements is odd or even.
Give your answer as a string matching "odd" or "even".
If the input array is empty consider it as: [0] (array with a zero).
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

const char* sumType(int* );

int main()
{
    int numbers[5] = {1,3,5,6,7};
    printf("%s",sumType(numbers));

    return 0;
}

const char* sumType(int* ptr)
{
    int summary=0;
    for(int i=0;i<sizeof(ptr)/sizeof(ptr[0]);i++)
    {
        summary += ptr[i];
    }
    if(summary%2==1)
    {
        return "odd";
    }
    else
    {
        return "even";
    }
    return 0;
}