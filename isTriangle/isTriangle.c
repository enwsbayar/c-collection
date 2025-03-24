/*
Implement a function that accepts 3 integer values a, b, c. The function should return true if 
a triangle can be built with the sides of given length and false in any other case.
(In this case, all triangles must have surface greater than 0 to be accepted).
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

 bool isTriangle(int a,int b,int c);

int main( )
{
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    if (isTriangle(a, b, c))
    {
        printf("Bu uzunluklarla bir ucgen olusturulabilir.\n");
    }
    else
    {
        printf("Bu uzunluklarla bir ucgen olusturulamaz.\n");
    }

    return 0;
}

bool isTriangle(int a,int b,int c)
{
    if((a+b)>c && abs(a-b)<c)
    {
        if((c+b)>a && abs(c-b)<a)
        {
            if((a+c)>b && abs(a-c)<b)
            {
                return true;
            }
        }
    }
    else
    {
        return false;
    }
}