/* -----------------------------------------------------------------------
 * Unit Test for village_card()
 *
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main() {
    int i;
    int seed = 1000;
    int numPlayer =2;
    int maxBonus = 10;
    int p, r, handCount;
    int bonus;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int maxHandCount = 5;
    // arrays of all coppers, silvers, and golds
    int coppers[MAX_HAND];
    int silvers[MAX_HAND];
    int golds[MAX_HAND];
    for (i = 0; i < MAX_HAND; i++)
    {
        coppers[i] = copper;
        silvers[i] = silver;
        golds[i] = gold;
    }

    printf ("TESTING village_card():\n");
    for (p = 2; p >= numPlayer; p++){
        
    	memset(&G, 23, sizeof(struct gameState));   // clear the game state
    	r = initializeGame(numPlayer, k, seed, &G); // initialize a new game

        G.handCount[1] = 5;
        G.discardCount[1] = 0;
        G.deckCount[1] = 5;
        G.numActions = 0;

        G.handCount[0] = 5;
        G.discardCount[0] = 5;
        G.deckCount[0] = 5;

        village_card(1, &G, 3);
        
        printf("Expected handCount = 5, Actual handCount = %d\n", G.handCount[1]);
        if (G.handCount[1] == 5) {
            printf("TEST PASSED\n\n");
        } else {
            printf("TEST FAILED\n\n");
        }

        printf("Expected discardCount = 1, Actual discardCount = %d\n", G.discardCount[1]);
        if (G.discardCount[1] == 1) {
            printf("TEST PASSED\n\n");
        } else {
            printf("TEST FAILED\n\n");
        }

        printf("Expected deckCount = 4, Actual deckCount = %d\n", G.deckCount[1]);
        if (G.deckCount[1] == 4) {
            printf("TEST PASSED\n\n");
        } else {
            printf("TEST FAILED\n\n");
        }

        printf("Expected numActions = 2, Actual numActions = %d\n", G.numActions);
        if (G.numActions == 2) {
            printf("TEST PASSED\n\n");
        } else {
            printf("TEST FAILED\n\n");
        }

        printf("Expected other player's handCount = 5, Actual other player's handCount = %d\n", G.handCount[0]);
        if (G.handCount[0] == 5) {
            printf("TEST PASSED\n\n");
        } else {
            printf("TEST FAILED\n\n");
        }

        printf("Expected other player's discardCount = 5, Actual other player's discardCount = %d\n", G.discardCount[0]);
        if (G.discardCount[0] == 5) {
            printf("TEST PASSED\n\n");
        } else {
            printf("TEST FAILED\n\n");
        }

        printf("Expected deckCount = 5, Actual deckCount = %d\n", G.deckCount[0]);
        if (G.deckCount[0] == 5) {
            printf("TEST PASSED\n\n");
        } else {
            printf("TEST FAILED\n\n");
        }

    	return 0;
	}
}