//BLACK JACK

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int hracKarta1, hracKarta2, hracSoucet;
    int dealerKarta1, dealerKarta2, dealerSoucet;
    char hratZnovu;

    srand(time(0)); // Inicializace generátoru náhodných čísel

    do {
        // Rozdání karet hráči
        hracKarta1 = rand() % 11 + 1; // Hodnota karty mezi 1 a 11
        hracKarta2 = rand() % 11 + 1; // Hodnota karty mezi 1 a 11
        hracSoucet = hracKarta1 + hracKarta2;

        // Rozdání karet dealerovi
        dealerKarta1 = rand() % 11 + 1; // Hodnota karty mezi 1 a 11
        dealerKarta2 = rand() % 11 + 1; // Hodnota karty mezi 1 a 11
        dealerSoucet = dealerKarta1 + dealerKarta2;

        printf("Hracovy karty: %d a %d (Soucet: %d)\n", hracKarta1, hracKarta2, hracSoucet);
        printf("Dealerovy karty: %d a %d (Soucet: %d)\n", dealerKarta1, dealerKarta2, dealerSoucet);

        if (hracSoucet > 21) {
            printf("Hrac pretahl! Dealer vyhrava.\n");
        } else if (dealerSoucet > 21) {
            printf("Dealer pretahl! Hrac vyhrava.\n");
        } else if (hracSoucet > dealerSoucet) {
            printf("Hrac vyhrava!\n");
        } else if (dealerSoucet > hracSoucet) {
            printf("Dealer vyhrava!\n");
        } else {
            printf("Je to remiza!\n");
        }

        printf("Chcete hrat znovu? (a/n): ");
        scanf(" %c", &hratZnovu);
        
    } while (hratZnovu == 'a' || hratZnovu == 'A');

    return 0;
}