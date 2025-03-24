/*
In this kata you get the start number and the end number of a region and should return
the count of all numbers except numbers with a 5 in it.
The start and the end number are both inclusive!
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int dontGiveMeFive(int ,int );

int main( )
{
    int start,end;
    scanf("%d%d",&start,&end);

    printf("%d",dontGiveMeFive(start,end));
    
    return 0;
}

int dontGiveMeFive(int start,int end)
{
    int counter = 0;
    for(int i=start;i<=end;i++)
    {
        if(i%5==0 && i%10!=0)
        {
            continue;
        }
        else
        {
            counter++;
        }
    }
    return counter;
}