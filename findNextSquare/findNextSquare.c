/*
Complete the findNextSquare method that finds the next integral
perfect square after the one passed as a parameter.
Recall that an integral perfect square is an integer n
such that sqrt(n) is also an integer.

If the argument is itself not a perfect square then return
either -1 or an empty value like None or null,
depending on your language. You may assume the argument
is non-negative.
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

long long int findNextSquare(long long int);

int main() {
    long long int number;
    scanf("%lld", &number); 
    printf("%lld\n", findNextSquare(number)); 

    return 0;
}

long long int findNextSquare(long long int n) {
    long long int a = sqrt(n);
    if (a * a != n) {
        return -1;
    }
    long long int nexta = a + 1;
    return nexta * nexta;
}