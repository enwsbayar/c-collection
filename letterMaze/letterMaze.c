#include <stdio.h>
#define GRIDROWS 10
#define GRIDCOLUMNS 10

int checkEnd(char grid[10][10], char letter, int gridRowLocation, int gridColumnLocation, int check);

void printGrid(char grid[10][10]);

void mod0Left(char grid[10][10], char letter, int* gridRowLocation, int* gridColumnLocation);

void mod1Right(char grid[10][10], char letter, int* gridRowLocation, int* gridColumnLocation);

void mod2Up(char grid[10][10], char letter, int* gridRowLocation, int* gridColumnLocation);

void mod3Down(char grid[10][10], char letter, int* gridRowLocation, int* gridColumnLocation);

int main()
{
  int gridRowLocation = 0, gridColumnLocation = 0, check = 1, number, order = 0;
  char grid[10][10] = {"A.........","..........","..........","..........","..........","..........","..........","..........","..........",".........."};
  char alphabet[26] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
  char letter = alphabet[order];
  printGrid(grid);
  while(check)
  {
    scanf("%d",&number);
    printf("%d\n",number);

    switch(number%4)
    {
      case 0:
      if(gridColumnLocation == 0)
      {
        break;
      }

        if(grid[gridRowLocation][gridColumnLocation-1] == '.')
        {
          order++;
          letter = alphabet[order];
          mod0Left(grid, letter, &gridRowLocation, &gridColumnLocation);
          printGrid(grid);
        }

      break;
      case 1:
      if(gridColumnLocation == 9)
      {
        break;
      }

      if(grid[gridRowLocation][gridColumnLocation+1] == '.')
        {
          order++;
          letter = alphabet[order];
          mod1Right(grid, letter, &gridRowLocation, &gridColumnLocation);
          printGrid(grid);
        }
      break;
      case 2:
      if(gridRowLocation == 0)
      {
        break;
      }

      if(grid[gridRowLocation-1][gridColumnLocation] == '.')
        {
          order++;
          letter = alphabet[order];
          mod2Up(grid, letter, &gridRowLocation, &gridColumnLocation);
          printGrid(grid);
        }
      break;
      case 3:
      if(gridRowLocation == 9)
      {
        break;
      }

      if(grid[gridRowLocation+1][gridColumnLocation] == '.')
        {
          order++;
          letter = alphabet[order];
          mod3Down(grid, letter, &gridRowLocation, &gridColumnLocation);
          printGrid(grid);
        }
      break;

      default:
      break;
    }
    check = checkEnd(grid, letter, gridRowLocation, gridColumnLocation, check);
  }

  return 0;
} 

void printGrid(char grid[10][10])
{
  int rows,columns;
  for(int rows = 0;rows < GRIDROWS;rows++)
  {
    for(int columns = 0;columns < GRIDCOLUMNS;columns++)
    {
      printf("%c",grid[rows][columns]);
    }
    printf("\n");
  }
}

void mod0Left(char grid[10][10], char letter, int* gridRowLocation, int* gridColumnLocation)
{
  (*gridColumnLocation)--;
  grid[*gridRowLocation][*gridColumnLocation] = letter;
}

void mod1Right(char grid[10][10], char letter, int* gridRowLocation, int* gridColumnLocation)
{
  (*gridColumnLocation)++;
  grid[*gridRowLocation][*gridColumnLocation] = letter;
}

void mod2Up(char grid[10][10], char letter, int* gridRowLocation, int* gridColumnLocation)
{
  (*gridRowLocation)--;
  grid[*gridRowLocation][*gridColumnLocation] = letter;
}

void mod3Down(char grid[10][10], char letter, int* gridRowLocation, int* gridColumnLocation)
{
  (*gridRowLocation)++;
  grid[*gridRowLocation][*gridColumnLocation] = letter;
}

int checkEnd(char grid[10][10], char letter, int gridRowLocation, int gridColumnLocation,int check)
{
  if(letter == 'Z')
  {
    check = 0;
    return check;
  }
  if(grid[gridRowLocation+1][gridColumnLocation] != '.' && grid[gridRowLocation-1][gridColumnLocation] != '.' && grid[gridRowLocation][gridColumnLocation+1] != '.' && grid[gridRowLocation][gridColumnLocation-1] != '.')
  {
    check = 0;
    return check;
  }
}

