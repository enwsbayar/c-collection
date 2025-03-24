/*
At a job interview, you are challenged to write an algorithm to check if a given string,
s, can be formed from two other strings, part1 and part2.

The restriction is that the characters in part1 and part2 should be in the same order as in s.

The interviewer gives you the following example and tells you to figure out the rest from the given test cases.

For example:

'codewars' is a merge from 'cdw' and 'oears':

    s:  c o d e w a r s   = codewars
part1:  c   d   w         = cdw
part2:    o   e   a r s   = oears
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <stdbool.h>

bool isMerge(const char* ,const char*, const char* );

int main( )
{
    if(isMerge("acab","ab","ac"))
    {
        printf("true");
    }
    else
    {
        printf("false");
    }

    return 0;
}

bool isMerge(const char* string,const char* part1,const char* part2)
{
    int counter1 = 0;
    int counter2 = 0;
    int counter3 = 0;
    
    if(strlen(part1) + strlen(part2) > strlen(string) || strlen(part1) + strlen(part2) < strlen(string))
    {
        return false;
    }
    while(counter3 < strlen(string))
    {
        if(string[counter3] == part1[counter1])
        {
            counter1++;
        }
        else if(string[counter3] == part2[counter2])
        {
            counter2++;
        }
        counter3++;
    }
    if(counter1 + counter2 == counter3)
    {
        return true;
    }
    else
    {
        return false;
    }
}