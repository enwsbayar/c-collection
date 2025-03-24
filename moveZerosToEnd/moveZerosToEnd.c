/*
Write an algorithm that takes an array and moves all of the zeros to the end,
preserving the order of the other elements.

move_zeros(10, int [] {1, 2, 0, 1, 0, 1, 0, 3, 0, 1}); // -> int [] {1, 2, 1, 1, 3, 1, 0, 0, 0, 0}

*/



#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <stdbool.h>

void moveZeros(size_t ,int* );

int main( )
{
    int numbers[10] = {1, 2, 0, 1, 0, 1, 0, 3, 0, 1};
    moveZeros(10,numbers);
    for(int m = 0;m < 10;m++)
    {
        printf("%d\t",numbers[m]);
    }
}

void moveZeros(size_t len,int* ptr)
{
    int ptrcopy[len];
    for(int a = 0;a < len;a++)
    {
        ptrcopy[a] = ptr[a];
    }

    int counter = 0;

    for(int i = 0;i < len; i++)
    {
        if(ptrcopy[i] != 0)
        {
            ptr[counter] = ptrcopy[i];
            counter++;
        }
    }
    for(int k = counter; k < len;k++)
    {
        ptr[k] = 0;
    }
}

