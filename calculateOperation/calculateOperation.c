/*
Given two numbers and an arithmetic operator (the name of it, as a string),
return the result of the two numbers having that operator used on them.

a and b will both be positive integers, and a will always be the first number in the operation,
and b always the second.

The four operators are "add", "subtract", "divide", "multiply".
*/

double arithmetic(double ,double ,const char* );

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main( )
{
    double firstNumber, secondNumber;
    char string[20];
    scanf("%lf %lf",&firstNumber,&secondNumber);
    scanf("%19s", string);

    printf("%f",arithmetic(firstNumber,secondNumber, string));

    return 0;
}

double arithmetic(double firstNumber,double secondNumber,const char* string)
{
    double result = 0;

    if(strcmp(string,"add")==0)
    {
        result = firstNumber+secondNumber;
    }
    else if(strcmp(string,"subtract")==0)
    {
        result = firstNumber-secondNumber;
    }
    else if(strcmp(string,"divide")==0)
    {
        result = firstNumber/secondNumber;
    }
    else if(strcmp(string,"multiply")==0)
    {
        result = firstNumber*secondNumber;
    }
    return result;
}
