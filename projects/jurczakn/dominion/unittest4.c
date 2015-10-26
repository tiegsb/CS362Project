/* -----------------------------------------------------------------------
 * Demonstration of how to write unit tests for dominion-base
 * Include the following lines in your makefile:
 *
 * testUpdateCoins: testUpdateCoins.c dominion.o rngs.o
 *      gcc -o testUpdateCoins -g  testUpdateCoins.c dominion.o rngs.o $(CFLAGS)
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int main() {
    int i;
    time_t t;
    int seed = 1000;
    int numPlayer = 4;
    int tests = 100;
    int p, r, handCount, deckCount, discardCount, handTotal, testHandTotal;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int maxHandCount = 5;
    int maxDeckCount = MAX_DECK;
    int maxDiscardCount = MAX_DECK;
    int cards[MAX_DECK];

    for (i = 0; i < MAX_DECK; i++){
	if ( i % 3 == 2){
	    cards[i] = gold;
	}
	else{
	    cards[i] = silver;
	}
    }

    p = 0;
    srand((unsigned) time(&t));

    printf ("TESTING fullDeckCount():\n");
    for (i = 0; i < tests; i++){
	handCount = rand() %maxHandCount;
	deckCount = rand() %maxDeckCount;
	discardCount = rand() %maxDiscardCount;
	memset(&G, 23, sizeof(struct gameState));   //clear gameState
	r = initializeGame(numPlayer, k, seed, &G);
	G.deckCount[p] = deckCount;
	G.handCount[p] = handCount;
	G.discardCount[p] = discardCount;
	memcpy(G.hand[p], cards, sizeof(int) * handCount);
	memcpy(G.deck[p], cards, sizeof(int) * deckCount);
	memcpy(G.discard[p], cards, sizeof(int) *discardCount);
        handTotal = handCount/3;
	handTotal += deckCount/3;
	handTotal += discardCount/3;
        testHandTotal = fullDeckCount(p, gold, &G);
	printf("Test #%d:\n", i);
	printf("Full count: %d, Expected: %d\n", testHandTotal, handTotal);
	if (testHandTotal == handTotal){
		printf("Success\n");
	}
	else{
		printf("Failure<==============");
	}
    }

#if (NOISY_TEST == 1)
    printf("All tests ended in fullDeckCount()\n");
#endif

    return 0;
}
