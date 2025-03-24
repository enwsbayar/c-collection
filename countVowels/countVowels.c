/*
Return the number (count) of vowels in the given string.
We will consider a, e, i, o, u as vowels for this Kata (but not y).
The input string will only consist of lower case letters and/or spaces.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int getCount(char*);

int main( )
{
    char string[100];
    fgets(string,sizeof(string),stdin);
    getCount(string);

    return 0;
}

int getCount(char* ptr)
{
    int length = strlen(ptr),i,counter=0;
    for(i=0;i<length;i++)
    {
        if (ptr[i] == 'a' || ptr[i] == 'e' || ptr[i] == 'i' || ptr[i] == 'o' || ptr[i] == 'u')
        {
            counter++;
        }
    }
    return counter;
}
