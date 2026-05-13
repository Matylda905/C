//BLACK JACK

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int playerCard1, playerCard2, playerTotal;
    int dealerCard1, dealerCard2, dealerTotal;
    char playAgain;

    srand(time(0)); // Seed the random number generator

    do {
        // Deal cards to player
        playerCard1 = rand() % 11 + 1; // Card value between 1 and 11
        playerCard2 = rand() % 11 + 1; // Card value between 1 and 11
        playerTotal = playerCard1 + playerCard2;

        // Deal cards to dealer
        dealerCard1 = rand() % 11 + 1; // Card value between 1 and 11
        dealerCard2 = rand() % 11 + 1; // Card value between 1 and 11
        dealerTotal = dealerCard1 + dealerCard2;

        printf("Player's cards: %d and %d (Total: %d)\n", playerCard1, playerCard2, playerTotal);
        printf("Dealer's cards: %d and %d (Total: %d)\n", dealerCard1, dealerCard2, dealerTotal);

        if (playerTotal > 21) {
            printf("Player busts! Dealer wins.\n");
        } else if (dealerTotal > 21) {
            printf("Dealer busts! Player wins.\n");
        } else if (playerTotal > dealerTotal) {
            printf("Player wins!\n");
        } else if (dealerTotal > playerTotal) {
            printf("Dealer wins!\n");
        } else {
            printf("It's a tie!\n");
        }

        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &playAgain);
    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}