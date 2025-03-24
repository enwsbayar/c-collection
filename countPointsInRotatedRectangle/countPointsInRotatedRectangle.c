/*
A rectangle with sides equal to even integers a and b is drawn on the Cartesian plane. Its center
(the intersection point of its diagonals) coincides with the point (0, 0), but the sides of the
rectangle are not parallel to the axes; instead, they are forming 45 degree angles with the axes.

How many points with integer coordinates are located inside the given rectangle (including on its sides)?

Example
For a = 6 and b = 4, the output should be 23

The following picture illustrates the example, and the 23 points are marked green.
https://files.gitter.im/myjinxin2015/raYf/blob
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <stdbool.h>

long long rectangleRotation(long long int ,long long int );

int main( )
{
    long long int num1,num2;
    scanf("%lld %lld",&num1,&num2);
    printf("%lld",rectangleRotation(num1,num2));
}

long long rectangleRotation(long long int a,long long int b)
{
    long long int c = (a / 2) * sqrt(2) + 1;
    long long int d = (b / 2) * sqrt(2) + 1;

    if(a % 8 == 0 || b % 8 == 0)
    {
            return (c-1) * (d-1) + c * d -1; 
    }

    return (c-1) * (d-1) + c * d; 
}