/*
Simple, given a string of words, return the length of the shortest word(s).
String will never be empty and you do not need to account for different data types.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void shortestWord(char*);
int main( )
{
    char string[100];
    fgets(string,sizeof(string),stdin);
    shortestWord(string);
    return 0;
}

void shortestWord(char* ptr)
{
    int length = strlen(ptr),counter=0,temporaryCounter=50;
    for(int i=0;i<length;i++)
    {
        if(ptr[i] != ' ' && ptr[i] != '\n'&& ptr[i] != '\0')
        {
            counter++;
        }
        else
        {
            if(counter<temporaryCounter)
            {
                temporaryCounter=counter;
            }
            counter = 0;
        }
    }
    printf("%d",temporaryCounter);
}