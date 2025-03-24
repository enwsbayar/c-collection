/*
Complete the function scramble(str1, str2)
that returns true if a portion of str1 characters can be rearranged to match str2, otherwise returns false.

Notes:

Only lower case letters will be used (a-z). No punctuation or digits will be included.
Performance needs to be considered.
Input strings s1 and s2 are null terminated.
Examples
scramble('rkqodlw', 'world') ==> True
scramble('cedewaraaossoqqyt', 'codewars') ==> True
scramble('katas', 'steak') ==> False
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <stdbool.h>

bool scramble(char* ,char* );

int main( )
{
    char firstString[] = "rkqodlw";
    char secondString[] = "world";

    if(scramble(firstString,secondString))
    {
        printf("True");
    }
    else
    {
        printf("False");
    }
    return 0;
}

bool scramble(char* str1, char* str2)
{
    int count1[256] = {0};
    int count2[256] = {0};

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    for(int i = 0;str2[i] != '\0';i++)
    {
        count2[str2[i]]++;
    }

    for(int j = 0;str1[j] != '\0';j++)
    {
        count1[str1[j]]++;
    }
    for(int k = 0;k < 256;k++)
    {
        if(count2[k]>count1[k])
        {
            return false;
        }
    }
    return true;
}