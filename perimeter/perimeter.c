/*
The drawing shows 6 squares the sides of which have a length of 1, 1, 2, 3, 5, 8.
It's easy to see that the sum of the perimeters of these squares is : 4 * (1 + 1 + 2 + 3 + 5 + 8) = 4 * 20 = 80 

Could you give the sum of the perimeters of all the squares in a rectangle when there are
n + 1 squares disposed in the same manner as in the drawing:



Hint:
See Fibonacci sequence


The function perimeter has for parameter n where n + 1 is the number of squares
(they are numbered from 0 to n) and returns the total perimeter of all the squares.

perimeter(5)  should return 80
perimeter(7)  should return 216
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <stdbool.h>

long long int perimeter(long long int );

int main( )
{
    printf("%d",perimeter(7));
}

long long int perimeter(long long int n)
{
    int counter = 0;
    long long int before = 1;
    long long int after = 1;
    long long int temp = after;
    long long int result = 0;
    while(counter<n)
    {
        temp = after;
        after = before + after;
        before = temp;
        result += before;
        counter++;
    }
    return 4*(result+1);
}