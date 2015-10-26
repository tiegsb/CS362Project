#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>
#include "rngs.h"

#define NOISY_TEST 1

int handCreate(struct gameState*);


int main() {
    int seed = 1000;
    int numPlayer = 2;
    int p;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int maxHandCount = 5;
    srand(seed);
    


    initializeGame(numPlayer, k, seed, &G);     //initialize a new game
    handCreate(&G);
    printf ("TESTING update coins: \n");
//for (int i = 0; i < 50000; i++) {
    for (p = 0; p < numPlayer; p++)
    {   
        int expectedCopper = 0;
        int expectedSilver = 0;
        int expectedGold = 0;
        G.handCount[p] = maxHandCount;
        for (int i = 0; i < maxHandCount; i++) {
            if (G.hand[p][i] == copper) {
                expectedCopper += 1;
            }
            else if (G.hand[p][i] == silver) {
                expectedSilver += 1;
            }
            else if (G.hand[p][i] == gold) {
                expectedGold += 1;
            }
        }
        int bonus = rand() % 10;
        updateCoins(p, &G, bonus);
        int expectedCoins = expectedGold * 3 + expectedSilver * 2 + expectedCopper + bonus;
#if (NOISY_TEST == 1)
        printf("Passed OUTPUT: %d RESULT: %d\n", expectedCoins, G.coins);
#endif
        assert(expectedCoins == G.coins);
        endTurn(&G);
        }
    //}
    printf("All tests passed!\n");
    return 0;
}

int handCreate (struct gameState *G) {
    int maxHandCount = 5;
    enum CARD deck[] = {gold, silver, smithy, gold, copper, village, copper};
    for (int i = 0; i < G->numPlayers; i++) {
        for (int j = 0; j < maxHandCount; j++) {
            G->hand[i][j] = deck[rand() % 7];
        }
    }
    return 0;
}