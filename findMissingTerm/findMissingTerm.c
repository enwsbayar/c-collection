/*
An Arithmetic Progression is defined as one in which there is a constant difference between the consecutive
terms of a given series of numbers. You are provided with consecutive elements of an Arithmetic Progression.
There is however one hitch: exactly one term from the original series is missing from the set of numbers
which have been given to you. The rest of the given series is the same as the original AP. Find the missing term.

You have to write a function that receives a list, list size will always be at least 3 numbers.
The missing term will never be the first or last one.

Example
find_missing((const int[]){1,3,5,9,11}, 5)  => 7
PS: This is a sample question of the facebook engineer challenge on interviewstreet.
I found it quite fun to solve on paper using math, derive the algo that way. Have fun!
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <stdbool.h>

int findMissing(const int* ,size_t );


int main( )
{
    int numbers[4] = {0,0,0,0};
    printf("%d",findMissing(numbers,4));

    return 0;
}

int findMissing(const int* ptr,size_t length)
{
    int counter = 0;
    
    for(int j = 0;j < length;j++)
    {
        if(ptr[j]==ptr[j+1])
        {
            counter++;
        }
    }

    if(counter == length-1)
    {
        return ptr[0];
    }

    int firstGap = ptr[1] - ptr[0];
    int secondGap = ptr[2] - ptr[1];

    if(length == 3)
    {
        if(secondGap == 2*firstGap)
        {
            return ptr[1] + firstGap;
        }
        else
        {
            return ptr[1] - secondGap;
        }
    }

    int mainGap;
    if(firstGap == secondGap)
    {
        mainGap = firstGap;
    }
    else
    {
        int thirdGap = ptr[3] - ptr[2];
        if(thirdGap == firstGap)
        {
            mainGap = thirdGap;
        }
        else if(thirdGap == secondGap)
        {
            mainGap = thirdGap;
        }
    }
    for(int i = 1;i < length;i++)
    {
        if(ptr[i] == ptr[i-1] + mainGap)
        {
            continue;
        }
        else
        {
            return ptr[i]-mainGap;
        }
    }
    return 0;
}