/* -----------------------------------------------------------------------
 * Random Test for smithy_card()
 *
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include "mt19937.h"

int main() {
    int i;
    int seed = 1000;
    int numPlayer =2;
    int maxBonus = 10;
    int p, r, handCount;
    int bonus;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G, testG;
    int maxHandCount = 5;
    // arrays of all coppers, silvers, and golds
    int coppers[MAX_HAND];
    int silvers[MAX_HAND];
    int golds[MAX_HAND];

    unsigned long init[4]={0x123, 0x234, 0x345, 0x456}, length=4;
	init_by_array(init, length);
    
    for (i = 0; i < MAX_HAND; i++)
    {
        coppers[i] = copper;
        silvers[i] = silver;
        golds[i] = gold;
    }

    printf ("TESTING smithy_card():\n");
    for (int j = 0; j <= 10000; j++){

    	printf("-------------------------------------------------------\n");
        
    	memset(&G, 23, sizeof(struct gameState));   // clear the game state
    	r = initializeGame(numPlayer, k, seed, &G); // initialize a new game

        G.handCount[1] = genrand_int32() % 12 + 1;
        G.discardCount[1] = genrand_int32() % 35;
        G.deckCount[1] = genrand_int32() % 35 + 3;

        G.handCount[0] = genrand_int32() % 5 + 1;
        G.discardCount[0] = genrand_int32() % 35;
        G.deckCount[0] = genrand_int32() % 35;

        memcpy(&testG, &G, sizeof(struct gameState));

        smithy_card(1, 3, &G);

        printf("Expected handCount = %d, Actual handCount = %d\n", testG.handCount[1] + 2,G.handCount[1]);
        if (G.handCount[1] == testG.handCount[1] + 2) {
            printf("TEST PASSED\n\n");
        } else {
            printf("TEST FAILED\n\n");
        }

        printf("Expected discardCount = %d, Actual discardCount = %d\n", testG.discardCount[1] + 1, G.discardCount[1]);
        if (G.discardCount[1] == testG.discardCount[1] + 1) {
            printf("TEST PASSED\n\n");
        } else {
            printf("TEST FAILED\n\n");
        }

        printf("Expected deckCount = %d, Actual deckCount = %d\n", testG.deckCount[1] - 3, G.deckCount[1]);
        if (G.deckCount[1] == testG.deckCount[1] - 3) {
            printf("TEST PASSED\n\n");
        } else {
            printf("TEST FAILED\n\n");
        }

        printf("Expected other player's handCount = %d, Actual other player's handCount = %d\n", testG.handCount[0], G.handCount[0]);
        if (G.handCount[0] == testG.handCount[0]) {
            printf("TEST PASSED\n\n");
        } else {
            printf("TEST FAILED\n\n");
        }

        printf("Expected ohter player's discardCount = %d, Actual other player's discardCount = %d\n", testG.discardCount[0], G.discardCount[0]);
        if (G.discardCount[0] == testG.discardCount[0]) {
            printf("TEST PASSED\n\n");
        } else {
            printf("TEST FAILED\n\n");
        }

        printf("Expected deckCount = %d, Actual deckCount = %d\n", testG.deckCount[0], G.deckCount[0]);
        if (G.deckCount[0] == testG.deckCount[0]) {
            printf("TEST PASSED\n\n");
        } else {
            printf("TEST FAILED\n\n");
        }

	}
	return 0;
}