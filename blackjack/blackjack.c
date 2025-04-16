///////////////////////////////////////////////////////////////////////////////
///////NOTE:I couldn't implement the case where Ace is 1 or 11 properly.///////
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int generateRandomNumber();
int getCardValue(int card);
void reduceSelectedCardStorage(int cardStorage[13], int randomNumber);
void visualizeAndPrintCards(int randomNumber, int isHidden);
int calculateHand(int hand[], int count);

int main() {
    srand(time(NULL));

    int stack, bet, check = 1, randomNumber, hitOrStand, playerTotal, dealerTotal, playerHand[10], dealerHand[10];
    int playerCount = 0, dealerCount = 0, n = 1, m = 1;
    int cardStorage[13] = {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4};

    printf("Please enter your stack amount: ");
    scanf("%d", &stack);

    start:
    while (check) {
        printf("Please enter your bet amount: ");
        scanf("%d", &bet);

        if (bet > stack) {
            printf("Wrong bet amount.\n");
            goto start;
        }

        printf("Dealing the cards...\n");
        sleep(1);

        dealerHand[dealerCount++] = generateRandomNumber();
        reduceSelectedCardStorage(cardStorage, dealerHand[dealerCount - 1]);
        dealerHand[dealerCount++] = generateRandomNumber();
        reduceSelectedCardStorage(cardStorage, dealerHand[dealerCount - 1]);

        printf("Dealer's cards:\n");
        visualizeAndPrintCards(dealerHand[0], 1); 
        sleep(1);
        visualizeAndPrintCards(dealerHand[1], 0); 
        sleep(1);

        printf("Your cards:\n");
        playerHand[playerCount++] = generateRandomNumber();
        reduceSelectedCardStorage(cardStorage, playerHand[playerCount - 1]);
        playerHand[playerCount++] = generateRandomNumber();
        reduceSelectedCardStorage(cardStorage, playerHand[playerCount - 1]);

        visualizeAndPrintCards(playerHand[0], 0);
        sleep(1);
        visualizeAndPrintCards(playerHand[1], 0);
        sleep(1);

        while (1) {
            playerTotal = calculateHand(playerHand, playerCount);
            printf("Your total: %d\n", playerTotal);

            if (playerTotal > 21) {
                printf("Bust! You lose.\n");
                stack -= bet; 
                break; 
            }

            printf("Hit = 1, Stand = 0: ");
            scanf("%d", &hitOrStand);

            if (hitOrStand == 0) {
                break;
            }

            if (hitOrStand == 1) {
                playerHand[playerCount++] = generateRandomNumber();
                reduceSelectedCardStorage(cardStorage, playerHand[playerCount - 1]);
                visualizeAndPrintCards(playerHand[playerCount - 1], 0);
                sleep(1);
                sleep(1);
            }
        }

        if (playerTotal <= 21) {
            printf("\nDealer's turn:\n");
            printf("Dealer's hidden card:\n ");
            visualizeAndPrintCards(dealerHand[0], 0);
            sleep(1);
            dealerTotal = calculateHand(dealerHand, dealerCount);
            while (dealerTotal < 17) {
                dealerHand[dealerCount++] = generateRandomNumber();
                reduceSelectedCardStorage(cardStorage, dealerHand[dealerCount - 1]);
                visualizeAndPrintCards(dealerHand[dealerCount - 1], 0);
                sleep(1);
                dealerTotal = calculateHand(dealerHand, dealerCount);
                sleep(1);
            }

            printf("\nYour total: %d | Dealer total: %d\n", playerTotal, dealerTotal);

            if (dealerTotal > 21 || playerTotal > dealerTotal) {
                printf("You win!\n");
                stack += bet;
            } else if (playerTotal < dealerTotal) {
                printf("Dealer wins.\n");
                stack -= bet;
            } else {
                printf("It's a tie.\n");
            }
        }

        printf("\nYour stack: %d\n", stack);

        if (stack <= 0) {
            printf("You are out of money!\n");
            break;
        }

        printf("\nDo you want to play again? (1 = Yes, 0 = No): ");
        scanf("%d", &check);
        if (check == 0) {
            break;
        }

        playerCount = 0;
        dealerCount = 0;
    }

    return 0;
}

int generateRandomNumber() {
    return (rand() % 13) + 1;
}

int getCardValue(int card) {
    if (card == 1) return 11; 
    if (card > 10) return 10; 
    return card;
}

void reduceSelectedCardStorage(int cardStorage[13], int randomNumber) {
    int cardStorageLocation = randomNumber - 1;
    cardStorage[cardStorageLocation] -= 1;
}

void visualizeAndPrintCards(int randomNumber, int isHidden) {
    if (isHidden) {
        printf("-------------------\n");
        printf("| * * * *         |\n");
        printf("| * * *           |\n");
        printf("| * *             |\n");
        printf("| *   Hidden      |\n");
        printf("|      Card      *|\n");
        printf("|              * *|\n");
        printf("|            * * *|\n");
        printf("|          * * * *|\n");
        printf("-------------------\n");
    } else {
        switch (randomNumber) {
          case 1:
            printf("-------------------\n");
            printf("|                 |\n");
            printf("|        ^        |\n");
            printf("|       / \\       |\n");
            printf("|      /   \\      |\n");
            printf("|     /_____\\     |\n");
            printf("|    /       \\    |\n");
            printf("|   /         \\   |\n");
            printf("|                 |\n");
            printf("-------------------\n");
            break;

          case 2:
            printf("-------------------\n");
            printf("|                 |\n");
            printf("|     -------     |\n");
            printf("|            |    |\n");
            printf("|     -------     |\n");
            printf("|    |            |\n");
            printf("|    |            |\n");
            printf("|     -------     |\n");
            printf("|                 |\n");
            printf("-------------------\n");
            break;

          case 3:
            printf("-------------------\n");
            printf("|                 |\n");
            printf("|     -------     |\n");
            printf("|            |    |\n");
            printf("|     -------     |\n");
            printf("|            |    |\n");
            printf("|            |    |\n");
            printf("|     -------     |\n");
            printf("|                 |\n");
            printf("-------------------\n");
            break;

          case 4:
            printf("-------------------\n");
            printf("|                 |\n");
            printf("|        /|       |\n");
            printf("|       / |       |\n");
            printf("|      /  |       |\n");
            printf("|     /   |       |\n");
            printf("|    <----|--     |\n");
            printf("|         |       |\n");
            printf("|                 |\n");
            printf("-------------------\n");
            break;

          case 5:
            printf("-------------------\n");
            printf("|                 |\n");
            printf("|     -------     |\n");
            printf("|    |            |\n");
            printf("|     -------     |\n");
            printf("|            |    |\n");
            printf("|            |    |\n");
            printf("|     -------     |\n");
            printf("|                 |\n");
            printf("-------------------\n");
            break;

          case 6:
            printf("-------------------\n");
            printf("|                 |\n");
            printf("|     -------     |\n");
            printf("|    |            |\n");
            printf("|     -------     |\n");
            printf("|    |       |    |\n");
            printf("|    |       |    |\n");
            printf("|     -------     |\n");
            printf("|                 |\n");
            printf("-------------------\n");
            break;

          case 7:
            printf("-------------------\n");
            printf("|                 |\n");
            printf("|    -------->    |\n");
            printf("|           /     |\n");
            printf("|          /      |\n");
            printf("|         /       |\n");
            printf("|        /        |\n");
            printf("|       /         |\n");
            printf("|                 |\n");
            printf("-------------------\n");
            break;

          case 8:
            printf("-------------------\n");
            printf("|                 |\n");
            printf("|     -------     |\n");
            printf("|    |       |    |\n");
            printf("|     -------     |\n");
            printf("|    |       |    |\n");
            printf("|    |       |    |\n");
            printf("|     -------     |\n");
            printf("|                 |\n");
            printf("-------------------\n");
            break;
            
          case 9:
            printf("-------------------\n");
            printf("|                 |\n");
            printf("|     -------     |\n");
            printf("|    |       |    |\n");
            printf("|     ------/     |\n");
            printf("|          /      |\n");
            printf("|         /       |\n");
            printf("|       --        |\n");
            printf("|                 |\n");
            printf("-------------------\n");
            break;

          case 10:
            printf("-------------------\n");
            printf("|                 |\n");
            printf("|   .    _____    |\n");
            printf("|  /|   |     |   |\n");
            printf("|   |   |     |   |\n");
            printf("|   |   |     |   |\n");
            printf("|   |   |     |   |\n");
            printf("|  _|_  |_____|   |\n");
            printf("|                 |\n");
            printf("-------------------\n");
            break;

          case 11:
            printf("-------------------\n");
            printf("|                 |\n");
            printf("|     |------     |\n");
            printf("|           |     |\n");
            printf("|           |     |\n");
            printf("|           |     |\n");
            printf("|   |       |     |\n");
            printf("|    \\_____/      |\n");
            printf("|                 |\n");
            printf("-------------------\n");
            break;

          case 12:
            printf("-------------------\n");
            printf("|                 |\n");
            printf("|      *****      |\n");
            printf("|     *     *     |\n");
            printf("|     *     *     |\n");
            printf("|     *     *     |\n");
            printf("|      ******     |\n");
            printf("|           **    |\n");
            printf("|                 |\n");
            printf("-------------------\n");
            break;

          case 13:
            printf("-------------------\n");
            printf("|                 |\n");
            printf("|     |    /      |\n");
            printf("|     |   /       |\n");
            printf("|     |__/        |\n");
            printf("|     |  \\        |\n");
            printf("|     |   \\       |\n");
            printf("|     |    \\      |\n");
            printf("|                 |\n");
            printf("-------------------\n");
            break;
        }
    }
}

int calculateHand(int hand[], int count) {
  int total = 0, aces = 0;
  for (int i = 0; i < count; i++) {
      int value = getCardValue(hand[i]);
      total += value;
      if (hand[i] == 1) aces++; 
  }

  while (aces > 0 && total + 10 <= 21) {
      total += 10; 
      aces--;
  }

  return total;
}
