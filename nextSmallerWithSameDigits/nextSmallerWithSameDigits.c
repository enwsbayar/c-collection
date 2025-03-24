/*
Write a function that takes a positive integer and returns the next
smaller positive integer containing the same digits.

For example:

nextSmaller(21) == 12
nextSmaller(531) == 513
nextSmaller(2071) == 2017
Return -1 (for Haskell: return Nothing, for Rust: return None),
when there is no smaller number that contains the same digits.
Also return -1 when the next smaller number with the same digits would require the leading digit to be zero.

nextSmaller(9) == -1
nextSmaller(111) == -1
nextSmaller(135) == -1
nextSmaller(1027) == -1 // 0721 is out since we don't write numbers with leading zeros
some tests will include very large numbers.
test data only employs positive integers.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <stdbool.h>

long long nextSmallerNumber(long long number);

int main( )
{
    printf("%lld",nextSmallerNumber(123456798));
}

long long nextSmallerNumber(long long number)
{
    int count[10] = {0};
    int temp = number;
    int temp2 = number;
    int temp3 = number;
    while(temp > 0)
    {
        count[temp % 10] += 1;
        temp /= 10;
    }
    while(temp2 > 0)
    {
        int count2[10] = {0};
        temp2 -= 1;
        temp3 = temp2;
        while(temp3 > 0)
        {
            count2[temp3 % 10] += 1;
            temp3 /= 10;
        }
        int counter = 0;
        for(int i = 0;i < 10;i++)
        {
            if(count[i] == count2[i])
            {
                counter++;
            }
            if(counter == 10)
            {
            return temp2;
            }
        }
        
    }
    return -1;
}