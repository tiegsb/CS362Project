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
    int seed = 1000;
    int success = 1;
    int count = 0, preCount = 0;
    int numPlayer = 2;
    int maxBonus = 10;
    int p = 0, r, deckC;
    int shuffled = 0;
    int originalDeck[100];
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;

    printf ("TESTING smithyCard():\n");
    for (i = 0; i < 10; i++) {
        memset(&G, 23, sizeof(struct gameState));   // clear the game state
        r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
        for (m = 0; m < 5; m++) {
        	
        	preCount = G.handCount[p];
        	#if (NOISY_TEST == 1)
                printf("Card in players hand before smithy: %d\n", preCount);
            #endif
            smithyCard(p, &G, count, j);
            count = G.handCount[p];
            #if (NOISY_TEST == 1)
                printf("Card in players hand after smithy: %d\n", count);
                printf("Should be %d\n", preCount +2);
            #endif
            if (preCount + 2 != count) {
                printf("TEST FAILED\n");
                success = 0;
            }
        }
    }
	if (success) {
        printf("All tests passed!\n");
	}
    return 0;
}
