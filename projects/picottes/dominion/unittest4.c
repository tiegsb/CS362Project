#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int main() {
    int i, j, m;
    int deckCounter;
    int seed = 1000;
    int count;
    int numPlayer = 2;
    int p = 0, r, deckC;
    int shuffled = 0;
    int originalDeck[100];
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;

    printf ("TESTING handCard():\n");
    for (i = 0; i < 10; i++) {
        memset(&G, 23, sizeof(struct gameState));   // clear the game state
        r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
        for (m = 0; m < 5; m++) {
        	drawCard(p, &G);
        	deckC = handCard(m, &G);
        	#if (NOISY_TEST == 1)
                printf("Card in players hand: %d, Card from handCard() %d\n", G.hand[p][m], deckC);
            #endif
            assert(G.hand[p][m] == deckC);
        }
    }

    printf("All tests passed!\n");

    return 0;
}
