/*
Given an array of integers, find the one that appears an odd number of times.

There will always be only one integer that appears an odd number of times.

Examples
[7] should return 7, because it occurs 1 time (which is odd).
[0] should return 0, because it occurs 1 time (which is odd).
[1,1,2] should return 2, because it occurs 1 time (which is odd).
[0,1,0,1,0] should return 0, because it occurs 3 times (which is odd).
[1,2,2,3,3,3,4,3,3,3,2,2,1] should return 4, because it appears 1 time (which is odd).
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <stdbool.h>

int findOdd(size_t length, const int* numbers);

int main( )
{
    int numbers[5] = {0,1,0,1,0};

    printf("%d",findOdd(5,numbers));
}

int findOdd(size_t length ,const int* numbers)
{
    for(int i = 0;i < length;i++)
    {
        int counter = 0;
        for(int j = 0;j < length;j++)
        {
            if(numbers[i] == numbers[j])
            {
                counter++;
            }
        }
        if(counter % 2 == 1)
        {
            return numbers[i];
        }
    }
    return -1;
}


