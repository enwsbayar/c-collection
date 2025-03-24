/*
Usually when you buy something, you're asked whether your credit card number,
phone number or answer to your most secret question is still correct.
However, since someone could look over your shoulder, you don't want that shown on your screen.
Instead, we mask it.

Your task is to write a function maskify, which changes all but the last four characters into '#'.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

const char* maskify(const char* );

int main( )
{
    char string[150];

    fgets(string,sizeof(string),stdin);
    printf("%s",maskify(string));

    return 0;
}

const char* maskify(const char* string)
{
    
    char* result = (char*)malloc(strlen(string) * sizeof(char));
    for(int i=0;i<strlen(string)-5;i++)
    {
        result[i] = '#';
    }
    result[strlen(string)-5]=string[strlen(string)-5];
    result[strlen(string)-4]=string[strlen(string)-4];
    result[strlen(string)-3]=string[strlen(string)-3];
    result[strlen(string)-2]=string[strlen(string)-2];

    return result;
}