#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isItPossible(const char* field);

int main() 
{
    if (isItPossible("0XX_0XX_0")) 
    {
        printf("True");
    } else 
    {
        printf("False");
    }
    return 0;
}

bool isItPossible(const char* field) 
{
    int counter1 = 0, counter2 = 0, counter3 = 0;
    for (int i = 0; i < strlen(field); i++) 
    {
        if (field[i] == 'X') 
        {
            counter1++;
        } else if (field[i] == '0') 
        {
            counter2++;
        } 
        else 
        {
            counter3++;
        }
    }
    if (counter1 > counter2 + 1 || counter1 < counter2)
    {
        return false;
    }

    // Check if both 'X' and '0' have a winning line
    bool xWins = (field[0] == 'X' && field[1] == 'X' && field[2] == 'X') ||
                 (field[3] == 'X' && field[4] == 'X' && field[5] == 'X') ||
                 (field[6] == 'X' && field[7] == 'X' && field[8] == 'X') ||
                 (field[0] == 'X' && field[3] == 'X' && field[6] == 'X') ||
                 (field[1] == 'X' && field[4] == 'X' && field[7] == 'X') ||
                 (field[2] == 'X' && field[5] == 'X' && field[8] == 'X') ||
                 (field[0] == 'X' && field[4] == 'X' && field[8] == 'X') ||
                 (field[2] == 'X' && field[4] == 'X' && field[6] == 'X');

    bool oWins = (field[0] == '0' && field[1] == '0' && field[2] == '0') ||
                 (field[3] == '0' && field[4] == '0' && field[5] == '0') ||
                 (field[6] == '0' && field[7] == '0' && field[8] == '0') ||
                 (field[0] == '0' && field[3] == '0' && field[6] == '0') ||
                 (field[1] == '0' && field[4] == '0' && field[7] == '0') ||
                 (field[2] == '0' && field[5] == '0' && field[8] == '0') ||
                 (field[0] == '0' && field[4] == '0' && field[8] == '0') ||
                 (field[2] == '0' && field[4] == '0' && field[6] == '0');

    if (xWins && oWins) 
    {
        return false;
    }

    if (xWins && counter1 == counter2) 
    {
        return false;
    }

    if (oWins && counter1 > counter2) 
    {
        return false;
    }

    return true;
}
