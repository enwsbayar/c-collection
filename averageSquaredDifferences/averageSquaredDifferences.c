/*
Complete the function that

accepts two integer arrays of equal length
compares the value each member in one array to the corresponding member in the other
squares the absolute value difference between those two values
and returns the average of those squared absolute value difference between each member pair.
Examples
[1, 2, 3], [4, 5, 6]              -->   9   because (9 + 9 + 9) / 3
[10, 20, 10, 2], [10, 25, 5, -2]  -->  16.5 because (0 + 25 + 25 + 16) / 4
[-1, 0], [0, -1]                  -->   1   because (1 + 1) / 2
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <stdbool.h>

double meanSquareError(size_t ,const int* ,const int* );

int main( )
{
    int firstNumbers[3] = {1,2,3}; 
    int secondNumbers[3] = {4,5,6};
    printf("%f",meanSquareError(3,firstNumbers,secondNumbers));

    return 0;
}

double meanSquareError(size_t n,const int* firstPtr,const int* secondPtr)
{
    double result = 0, number = 0;
    for(int i = n-1;i >= 0;i--)
    {
        number = secondPtr[i] - firstPtr[i];
        number = number * number;
        result = result + number;
    }
    result = result/n;
    return result;
}