#include <stdio.h>
void printBoard(char board[9][9]);

void moveWhitePawn(char board[9][9],int startRowLocation, int startCollumnLocation, int targetRowLocation, int targetCollumnLocation);

void moveBlackPawn(char board[9][9],int startRowLocation, int startCollumnLocation, int targetRowLocation, int targetCollumnLocation);

int canWhitePawnCapture(char board[9][9],int startRowLocation, int startCollumnLocation, int targetRowLocation, int targetCollumnLocation);

int canBlackPawnCapture(char board[9][9],int startRowLocation, int startCollumnLocation, int targetRowLocation, int targetCollumnLocation);

void moveWhiteRook(char board[9][9],int startRowLocation, int startCollumnLocation, int targetRowLocation, int targetCollumnLocation);

void moveBlackRook(char board[9][9], int startRowLocation, int startCollumnLocation, int targetRowLocation, int targetCollumnLocation);

void moveWhiteKnight(char board[9][9], int startRowLocation, int startCollumnLocation, int targetRowLocation, int targetCollumnLocation);

int main()
{
    char board[9][9] = {{"/12345678"},{"1ABCDECBA"},{"2WWWWWWWW"},{"3oooooooo"},{"4oooooooo"},{"5oooJoooo"},{"6oooooooo"},{"7SSSSSSSS"},{"8JKLMNLKJ"}};
    int startRowLocation, startCollumnLocation, targetRowLocation, targetCollumnLocation;

    printf("Chess game.Info:\nW for White Pawn\nA for White Rook.\nB for White Knight.\nC for White Bishop.\nD for White Queen.\nE for White King.\n---------\nS for Black Pawn\nJ for Black Rook.\nK for Black Knight.\nL for Black Bishop.\nM for Black Queen.\nN for Black King.\n");

    printBoard(board);

    while (1)
    {
        int startRowLocation = 0, startCollumnLocation = 0, targetRowLocation = 0, targetCollumnLocation = 0;
        scanf("%d %d", &startRowLocation, &startCollumnLocation);
        scanf("%d %d", &targetRowLocation, &targetCollumnLocation);
        moveBlackRook(board, startRowLocation, startCollumnLocation, targetRowLocation, targetCollumnLocation);
    }
}

//----------------------------------------------------------------------------------------------------------------//
// PRINT BOARD FUNCTION
//----------------------------------------------------------------------------------------------------------------//
void printBoard(char board[9][9])
{
    printf("---------\n");
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
    printf("---------\n");
}

//----------------------------------------------------------------------------------------------------------------//
// CAN WHITE PAWN CAPTURE FUNCTION
//----------------------------------------------------------------------------------------------------------------//
int canWhitePawnCapture(char board[9][9], int startRowLocation, int startCollumnLocation, int targetRowLocation, int targetCollumnLocation)
{
    char targetPiece = board[targetRowLocation][targetCollumnLocation];

    if (targetRowLocation - startRowLocation == 1)
    {
        if (startCollumnLocation - targetCollumnLocation == 1 || targetCollumnLocation - startCollumnLocation == 1)
        {
            if (targetPiece == 'o')
            {
                return 0;
            }
            if (targetPiece == 'W' || targetPiece == 'A' || targetPiece == 'B' || targetPiece == 'C' || targetPiece == 'D' || targetPiece == 'E')
            {
                return 0;
            }
            return 1;
        }
    }
    return 0;
}

//----------------------------------------------------------------------------------------------------------------//
// CAN BLACK PAWN CAPTURE FUNCTION
//----------------------------------------------------------------------------------------------------------------//
int canBlackPawnCapture(char board[9][9], int startRowLocation, int startCollumnLocation, int targetRowLocation, int targetCollumnLocation)
{
    char targetPiece = board[targetRowLocation][targetCollumnLocation];

    if (startRowLocation - targetRowLocation == 1)
    {
        if (targetCollumnLocation - startCollumnLocation == 1 || startCollumnLocation - targetCollumnLocation == 1)
        {
            if (targetPiece == 'o')
            {
                return 0;
            }
            if (targetPiece == 'S' || targetPiece == 'J' || targetPiece == 'K' || targetPiece == 'L' || targetPiece == 'M' || targetPiece == 'N')
            {
                return 0;
            }
            return 1;
        }
    }
    return 0;
}

//----------------------------------------------------------------------------------------------------------------//
// MOVE WHITE PAWN FUNCTION
//----------------------------------------------------------------------------------------------------------------//
void moveWhitePawn(char board[9][9], int startRowLocation, int startCollumnLocation, int targetRowLocation, int targetCollumnLocation)
{
    char startPiece = board[startRowLocation][startCollumnLocation];
    char targetPiece = board[targetRowLocation][targetCollumnLocation];

    if (canWhitePawnCapture(board, startRowLocation, startCollumnLocation, targetRowLocation, targetCollumnLocation))
    {
        board[targetRowLocation][targetCollumnLocation] = 'W';
        board[startRowLocation][startCollumnLocation] = 'o';
        printBoard(board);
        return;
    }
    if (targetCollumnLocation == startCollumnLocation)
    {
        if (startPiece != 'W')
        {
            printf("Wrong start location.\n");
            return;
        }

        if (startRowLocation == 2 && (targetRowLocation - startRowLocation <= 2))
        {
            if (targetPiece == 'o')
            {
                board[targetRowLocation][targetCollumnLocation] = 'W';
                board[startRowLocation][startCollumnLocation] = 'o';
                printBoard(board);
                return;
            }
        }
        else if (targetPiece == 'o' && targetRowLocation - startRowLocation == 1)
        {
            board[targetRowLocation][targetCollumnLocation] = 'W';
            board[startRowLocation][startCollumnLocation] = 'o';
            printBoard(board);
            return;
        }
    }
    printf("The White Pawn can't go there.\n");
}

//----------------------------------------------------------------------------------------------------------------//
// MOVE BLACK PAWN FUNCTION
//----------------------------------------------------------------------------------------------------------------//
void moveBlackPawn(char board[9][9], int startRowLocation, int startCollumnLocation, int targetRowLocation, int targetCollumnLocation)
{
    char startPiece = board[startRowLocation][startCollumnLocation];
    char targetPiece = board[targetRowLocation][targetCollumnLocation];

    if (canBlackPawnCapture(board, startRowLocation, startCollumnLocation, targetRowLocation, targetCollumnLocation))
    {
        board[targetRowLocation][targetCollumnLocation] = 'S';
        board[startRowLocation][startCollumnLocation] = 'o';
        printBoard(board);
        return;
    }

    if (targetCollumnLocation == startCollumnLocation)
    {
        if (startPiece != 'S')
        {
            printf("Wrong start location.\n");
            return;
        }

        if (startRowLocation == 7 && (startRowLocation - targetRowLocation <= 2))
        {
            if (targetPiece == 'o')
            {
                board[targetRowLocation][targetCollumnLocation] = 'S';
                board[startRowLocation][startCollumnLocation] = 'o';
                printBoard(board);
                return;
            }
        }
        else if (targetPiece == 'o' && startRowLocation - targetRowLocation == 1)
        {
            board[targetRowLocation][targetCollumnLocation] = 'S';
            board[startRowLocation][startCollumnLocation] = 'o';
            printBoard(board);
            return;
        }
    }
    printf("The Black Pawn can't go there.\n");
}

//----------------------------------------------------------------------------------------------------------------//
//MOVE WHITE ROOK FUNCTION
//----------------------------------------------------------------------------------------------------------------//
void moveWhiteRook(char board[9][9], int startRowLocation, int startCollumnLocation, int targetRowLocation, int targetCollumnLocation)
{
  char startPiece = board[startRowLocation][startCollumnLocation];
  char targetPiece = board[targetRowLocation][targetCollumnLocation];

  if(startPiece != 'A')
  {
    printf("Wrong start location.\n");
    return;
  }

  if(startCollumnLocation == targetCollumnLocation)
  {
    if (targetRowLocation > startRowLocation) 
    {
      for (int i = 1; i < targetRowLocation - startRowLocation; i++) 
      {
        if (board[startRowLocation + i][startCollumnLocation] != 'o') 
        {
          printf("The White Rook can't go there.\n");
          return;
        }
      }
    } 
    else 
    {
      for (int i = 1; i < startRowLocation - targetRowLocation; i++) 
      {
        if (board[startRowLocation - i][startCollumnLocation] != 'o') 
        {
          printf("The White Rook can't go there.\n");
          return;
        }
      }
    }
    if(targetPiece == 'o' || targetPiece == 'S' || targetPiece == 'J' || targetPiece == 'K' || targetPiece == 'L' || targetPiece == 'M' || targetPiece == 'N')
    {
      board[targetRowLocation][targetCollumnLocation] = 'A';
      board[startRowLocation][startCollumnLocation] = 'o';
      printBoard(board);
    }
    else if(targetPiece == 'W' || targetPiece == 'A' || targetPiece == 'B' || targetPiece == 'C' || targetPiece == 'D' || targetPiece == 'E')
    {
      printf("The White Rook can't go there.\n");
    }
  
  } 
  else if(startRowLocation == targetRowLocation)
  {
    if (targetCollumnLocation > startCollumnLocation) 
    {
      for (int i = 1; i < targetCollumnLocation - startCollumnLocation; i++) {
        if (board[startRowLocation][startCollumnLocation + i] != 'o') {
          printf("The White Rook can't go there.\n");
          return;
        }
      }
    } 
    else 
    { 
      for (int i = 1; i < startCollumnLocation - targetCollumnLocation; i++) {
        if (board[startRowLocation][startCollumnLocation - i] != 'o') {
          printf("The White Rook can't go there.\n");
          return;
        }
      }
    }
    if(targetPiece == 'o' || targetPiece == 'S' || targetPiece == 'J' || targetPiece == 'K' || targetPiece == 'L' || targetPiece == 'M' || targetPiece == 'N')
    {
      board[targetRowLocation][targetCollumnLocation] = 'A';
      board[startRowLocation][startCollumnLocation] = 'o';
      printBoard(board);
    }
    else if(targetPiece == 'W' || targetPiece == 'A' || targetPiece == 'B' || targetPiece == 'C' || targetPiece == 'D' || targetPiece == 'E')
    {
      printf("The White Rook can't go there.\n");
    }
  }
  else
  {
    printf("The White Rook can't go there.\n");
  }
}
//----------------------------------------------------------------------------------------------------------------//
//MOVE BLACK ROOK FUNCTION
//----------------------------------------------------------------------------------------------------------------//
void moveBlackRook(char board[9][9], int startRowLocation, int startCollumnLocation, int targetRowLocation, int targetCollumnLocation)
{
    char startPiece = board[startRowLocation][startCollumnLocation];
    char targetPiece = board[targetRowLocation][targetCollumnLocation];

    if (startPiece != 'J')
    {
        printf("Wrong start location.\n");
        return;
    }

    if (startCollumnLocation == targetCollumnLocation)
    {
        if (targetRowLocation > startRowLocation)
        {
            for (int i = 1; i < targetRowLocation - startRowLocation; i++)
            {
                if (board[startRowLocation + i][startCollumnLocation] != 'o')
                {
                    printf("The Black Rook can't go there.\n");
                    return;
                }
            }
        }
        else
        {
            for (int i = 1; i < startRowLocation - targetRowLocation; i++)
            {
                if (board[startRowLocation - i][startCollumnLocation] != 'o')
                {
                    printf("The Black Rook can't go there.\n");
                    return;
                }
            }
        }
    }
    else if (startRowLocation == targetRowLocation)
    {
        if (targetCollumnLocation > startCollumnLocation)
        {
            for (int i = 1; i < targetCollumnLocation - startCollumnLocation; i++)
            {
                if (board[startRowLocation][startCollumnLocation + i] != 'o')
                {
                    printf("The Black Rook can't go there.\n");
                    return;
                }
            }
        }
        else
        {
            for (int i = 1; i < startCollumnLocation - targetCollumnLocation; i++)
            {
                if (board[startRowLocation][startCollumnLocation - i] != 'o')
                {
                    printf("The Black Rook can't go there.\n");
                    return;
                }
            }
        }
    }
    else
    {
        printf("The Black Rook can't go there.\n");
        return;
    }

    if (targetPiece == 'o' || targetPiece == 'W' || targetPiece == 'A' || targetPiece == 'B' || targetPiece == 'C' || targetPiece == 'D' || targetPiece == 'E')
    {
        board[targetRowLocation][targetCollumnLocation] = 'J';
        board[startRowLocation][startCollumnLocation] = 'o';
        printBoard(board);
    }
    else
    {
        printf("The Black Rook can't go there.\n");
    }
}



