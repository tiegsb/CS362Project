/* -----------------------------------------------------------------------
 * Unit Test for steward_card()
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

    printf ("TESTING steward_card():\n");
    for (p = 2; p >= numPlayer; p++){
        
    	memset(&G, 23, sizeof(struct gameState));   // clear the game state
    	r = initializeGame(numPlayer, k, seed, &G); // initialize a new game

        G.handCount[1] = 5;
        G.discardCount[1] = 0;
        G.deckCount[1] = 5;
        G.coins = 0;

        G.handCount[0] = 5;
        G.discardCount[0] = 5;
        G.deckCount[0] = 5;

        steward_card(1, &G, 3, 1, 0, 0);
        
        printf ("Testing choice1 = 1:\n\n");
        printf("Expected handCount = 6, Actual handCount = %d\n", G.handCount[1]);
        if (G.handCount[1] == 6) {
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

        printf("Expected deckCount = 3, Actual deckCount = %d\n", G.deckCount[1]);
        if (G.deckCount[1] == 3) {
            printf("TEST PASSED\n\n");
        } else {
            printf("TEST FAILED\n\n");
        }

        printf("Expected # of coins = 0, Actual # of coins = %d\n", G.coins);
        if (G.coins == 0) {
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

        printf("Expected ohter player's discardCount = 5, Actual other player's discardCount = %d\n", G.discardCount[0]);
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

        G.handCount[1] = 5;
        G.discardCount[1] = 0;
        G.deckCount[1] = 5;
        G.coins = 0;

        G.handCount[0] = 5;
        G.discardCount[0] = 5;
        G.deckCount[0] = 5;

        steward_card(1, &G, 3, 2, 0, 0);

        printf ("Testing choice1 = 2:\n\n");
        printf("Expected handCount = 4, Actual handCount = %d\n", G.handCount[1]);
        if (G.handCount[1] == 4) {
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

        printf("Expected deckCount = 5, Actual deckCount = %d\n", G.deckCount[1]);
        if (G.deckCount[1] == 5) {
            printf("TEST PASSED\n\n");
        } else {
            printf("TEST FAILED\n\n");
        }

        printf("Expected # of coins = 2, Actual # of coins = %d\n", G.coins);
        if (G.coins == 2) {
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

        printf("Expected ohter player's discardCount = 5, Actual other player's discardCount = %d\n", G.discardCount[0]);
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

        G.handCount[1] = 5;
        G.discardCount[1] = 0;
        G.deckCount[1] = 5;
        G.coins = 0;

        G.handCount[0] = 5;
        G.discardCount[0] = 5;
        G.deckCount[0] = 5;

        steward_card(1, &G, 3, 3, 0, 0);

        printf ("Testing choice1 = 3:\n\n");
        
        printf("Expected handCount = 2, Actual handCount = %d\n", G.handCount[1]);
        if (G.handCount[1] == 2) {
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

        printf("Expected deckCount = 5, Actual deckCount = %d\n", G.deckCount[1]);
        if (G.deckCount[1] == 5) {
            printf("TEST PASSED\n\n");
        } else {
            printf("TEST FAILED\n\n");
        }

        printf("Expected # of coins = 0, Actual # of coins = %d\n", G.coins);
        if (G.coins == 0) {
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

        printf("Expected ohter player's discardCount = 5, Actual other player's discardCount = %d\n", G.discardCount[0]);
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