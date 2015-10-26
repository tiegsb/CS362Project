#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int main() {
    int i, j;
    int seed = 1000;
    int numPlayer = 2;
    int p = 1, r, deckC;
    int shuffled = 0;
    int originalDeck[100];
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;



    printf ("TESTING shuffle():\n");
    for (i = 0; i < 10; i++) {
		#if (NOISY_TEST == 1)
            printf("Test shuffle.\n");
		#endif
		shuffled = 0;
        memset(&G, 23, sizeof(struct gameState));   // clear the game state
        r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
        deckC = G.deckCount[p];
        for (j = 0; j < deckC; j++) {
            originalDeck[j] = G.deck[p][j];
        }
        r = shuffle(p, &G);
        for (j = 0; j < deckC; j++) {
            if (originalDeck[j] != G.deck[p][j]) {
                shuffled++;
            }
        }
        if (shuffled == 0) {
            printf("Error shuffling %d\n", shuffled);
        }
        else {
            printf("Shuffled\n");
        }
        assert(shuffled != 0);
    }

    printf("All tests passed!\n");

    return 0;
}
