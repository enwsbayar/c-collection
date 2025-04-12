#include <stdio.h>
#define GRIDROWS 10
#define GRIDCOLLUMNS 10

int checkEnd(char grid[10][10], char letter, int gridRowLocation, int gridCollumnLocation, int check);

void printGrid(char grid[10][10]);

void mod0Left(char grid[10][10], char letter, int* gridRowLocation, int* gridCollumnLocation);

void mod1Right(char grid[10][10], char letter, int* gridRowLocation, int* gridCollumnLocation);

void mod2Up(char grid[10][10], char letter, int* gridRowLocation, int* gridCollumnLocation);

void mod3Down(char grid[10][10], char letter, int* gridRowLocation, int* gridCollumnLocation);

int main()
{
  int gridRowLocation = 0, gridCollumnLocation = 0, check = 1, number, order = 0;
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
      if(gridCollumnLocation == 0)
      {
        break;
      }

        if(grid[gridRowLocation][gridCollumnLocation-1] == '.')
        {
          order++;
          letter = alphabet[order];
          mod0Left(grid, letter, &gridRowLocation, &gridCollumnLocation);
          printGrid(grid);
        }

      break;
      case 1:
      if(gridCollumnLocation == 9)
      {
        break;
      }

      if(grid[gridRowLocation][gridCollumnLocation+1] == '.')
        {
          order++;
          letter = alphabet[order];
          mod1Right(grid, letter, &gridRowLocation, &gridCollumnLocation);
          printGrid(grid);
        }
      break;
      case 2:
      if(gridRowLocation == 0)
      {
        break;
      }

      if(grid[gridRowLocation-1][gridCollumnLocation] == '.')
        {
          order++;
          letter = alphabet[order];
          mod2Up(grid, letter, &gridRowLocation, &gridCollumnLocation);
          printGrid(grid);
        }
      break;
      case 3:
      if(gridRowLocation == 9)
      {
        break;
      }

      if(grid[gridRowLocation+1][gridCollumnLocation] == '.')
        {
          order++;
          letter = alphabet[order];
          mod3Down(grid, letter, &gridRowLocation, &gridCollumnLocation);
          printGrid(grid);
        }
      break;

      default:
      break;
    }
    check = checkEnd(grid, letter, gridRowLocation, gridCollumnLocation, check);
  }

  return 0;
} 

void printGrid(char grid[10][10])
{
  int rows,collumns;
  for(int rows = 0;rows < GRIDROWS;rows++)
  {
    for(int collumns = 0;collumns < GRIDCOLLUMNS;collumns++)
    {
      printf("%c",grid[rows][collumns]);
    }
    printf("\n");
  }
}

void mod0Left(char grid[10][10], char letter, int* gridRowLocation, int* gridCollumnLocation)
{
  (*gridCollumnLocation)--;
  grid[*gridRowLocation][*gridCollumnLocation] = letter;
}

void mod1Right(char grid[10][10], char letter, int* gridRowLocation, int* gridCollumnLocation)
{
  (*gridCollumnLocation)++;
  grid[*gridRowLocation][*gridCollumnLocation] = letter;
}

void mod2Up(char grid[10][10], char letter, int* gridRowLocation, int* gridCollumnLocation)
{
  (*gridRowLocation)--;
  grid[*gridRowLocation][*gridCollumnLocation] = letter;
}

void mod3Down(char grid[10][10], char letter, int* gridRowLocation, int* gridCollumnLocation)
{
  (*gridRowLocation)++;
  grid[*gridRowLocation][*gridCollumnLocation] = letter;
}

int checkEnd(char grid[10][10], char letter, int gridRowLocation, int gridCollumnLocation,int check)
{
  if(letter == 'Z')
  {
    check = 0;
    return check;
  }
  if(grid[gridRowLocation+1][gridCollumnLocation] != '.' && grid[gridRowLocation-1][gridCollumnLocation] != '.' && grid[gridRowLocation][gridCollumnLocation+1] != '.' && grid[gridRowLocation][gridCollumnLocation-1] != '.')
  {
    check = 0;
    return check;
  }
}

