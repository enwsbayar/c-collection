/*
Write a function that will return the count of distinct case-insensitive
alphabetic characters and numeric digits that occur more than once in the input string.
The input string can be assumed to contain only alphabets (both uppercase and lowercase) and numeric digits.

Example
"abcde" -> 0 # no characters repeats more than once
"aabbcde" -> 2 # 'a' and 'b'
"aabBcde" -> 2 # 'a' occurs twice and 'b' twice (`b` and `B`)
"indivisibility" -> 1 # 'i' occurs six times
"Indivisibilities" -> 2 # 'i' occurs seven times and 's' occurs twice
"aA11" -> 2 # 'a' and '1'
"ABBA" -> 2 # 'A' and 'B' each occur twice
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>

int duplicateCount(char* );

int main( )
{
    char string[] = "indivisibility";
    printf("%d",duplicateCount(string));

    return 0;
}

int duplicateCount(char* ptr)
{
    int count[256] = {0};
    int length = strlen(ptr);
    for(int i = 0;i < length;i++)
    {
        int n = tolower(ptr[i]);
        count[n]++;
    }

    int result = 0;

    for(int j = 0;j < 256;j++)
    {
        if(count[j] > 1)
        {
            result++;
        }
    }
    return result;
}

