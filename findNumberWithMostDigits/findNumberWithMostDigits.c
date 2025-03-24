/*
Find the number with the most digits.

If two numbers in the argument array have the same number of digits,
return the first one in the array.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>


int findLongest(int* ,size_t);

int main( )
{
    int numbers[] = {1, 1065, 10};
    printf("%d",findLongest(numbers,3));
}

int findLongest(int* ptr, size_t n)
{
    int result = 0, tempLength = 0;
    for(int i = 0;i < n;i++)
    {
        int temp = ptr[i], length = 0;

        while(temp != 0)
        {
            temp /= 10;
            length++;
        }
        if(length > tempLength)
        {
            result = ptr[i];
            tempLength = length;
        }
    }
    return result;

}