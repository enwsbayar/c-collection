/*
You are going to be given a word. Your job is to return the middle character of the word.
If the word's length is odd, return the middle character.
If the word's length is even, return the middle 2 characters.
*/

const char* middleCharacter(const char* );

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    char word[20];
    fgets(word,sizeof(word),stdin);
    printf("%s",middleCharacter(word));

    return 0;
}

const char* middleCharacter(const char* ptr)
{
    int length = strlen(ptr)-1;
    int half = length/2;
    char* result=NULL;

    if(length%2==0)
    {
        result = (char*)malloc(3 * sizeof(char));
        result[0]=ptr[half-1];
        result[1]=ptr[half];
        result[2]='\0';
    }
    else
    {
        result = (char*)malloc(2 * sizeof(char));
        result[0]=ptr[half];
        result[1]='\0';
    }
    return result;
}
