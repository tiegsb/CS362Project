/* -----------------------------------------------------------------------
 * Unit Test for adventurer_card()
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

    printf ("TESTING adventurer_card():\n");
    for (p = 2; p >= numPlayer; p++){
        
    	memset(&G, 23, sizeof(struct gameState));   // clear the game state
    	r = initializeGame(numPlayer, k, seed, &G); // initialize a new game

        G.handCount[1] = 5;
        G.discardCount[1] = 0;
        G.deckCount[1] = 5;

        G.deck[1][0] = copper;
        G.deck[1][1] = gold;
        G.deck[1][2] = smithy;
        G.deck[1][3] = silver;
        G.deck[1][4] = copper;

        G.hand[1][0] = copper;
        G.hand[1][1] = 0;
        G.hand[1][2] = adventurer;
        G.hand[1][3] = copper;
        G.hand[1][4] = 0;

        G.handCount[0] = 5;
        G.discardCount[0] = 5;
        G.deckCount[0] = 5;

        int temphand[MAX_HAND];
        adventurer_card(1, -1, 0, 0, temphand, &G);

        updateCoins(1, &G, 0);

        printf("Expected coin count = 5, Actual coin count = %d\n", G.coins);
        if (G.coins == 5) {
            printf("TEST PASSED\n\n");
        } else {
            printf("TEST FAILED\n\n");
        }
        
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

        G.handCount[1] = 5;
        G.discardCount[1] = 0;
        G.deckCount[1] = 5;

        G.deck[1][0] = smithy;
        G.deck[1][1] = estate;
        G.deck[1][2] = smithy;
        G.deck[1][3] = 0;
        G.deck[1][4] = province;

        G.hand[1][0] = copper;
        G.hand[1][1] = 0;
        G.hand[1][2] = adventurer;
        G.hand[1][3] = copper;
        G.hand[1][4] = 0;

        G.handCount[0] = 5;
        G.discardCount[0] = 5;
        G.deckCount[0] = 5;

        adventurer_card(1, -1, 0, 0, temphand, &G);

        updateCoins(1, &G, 0);

        printf("Expected coin count = 2, Actual coin count = %d\n", G.coins);
        if (G.coins == 2) {
            printf("TEST PASSED\n\n");
        } else {
            printf("TEST FAILED\n\n");
        }
        
        printf("Expected handCount = 4, Actual handCount = %d\n", G.handCount[1]);
        if (G.handCount[1] == 4) {
            printf("TEST PASSED\n\n");
        } else {
            printf("TEST FAILED\n\n");
        }

        printf("Expected discardCount = 6, Actual discardCount = %d\n", G.discardCount[1]);
        if (G.discardCount[1] == 6) {
            printf("TEST PASSED\n\n");
        } else {
            printf("TEST FAILED\n\n");
        }

        printf("Expected deckCount = 0, Actual deckCount = %d\n", G.deckCount[1]);
        if (G.deckCount[1] == 0) {
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

        G.handCount[1] = 5;
        G.discardCount[1] = 0;
        G.deckCount[1] = 5;

        G.deck[1][0] = smithy;
        G.deck[1][1] = silver;
        G.deck[1][2] = smithy;
        G.deck[1][3] = copper;
        G.deck[1][4] = province;

        G.hand[1][0] = copper;
        G.hand[1][1] = 0;
        G.hand[1][2] = adventurer;
        G.hand[1][3] = copper;
        G.hand[1][4] = 0;

        G.handCount[0] = 5;
        G.discardCount[0] = 5;
        G.deckCount[0] = 5;

        adventurer_card(1, -1, 0, 0, temphand, &G);

        updateCoins(1, &G, 0);

        printf("Expected coin count = 5, Actual coin count = %d\n", G.coins);
        if (G.coins == 5) {
            printf("TEST PASSED\n\n");
        } else {
            printf("TEST FAILED\n\n");
        }
        
        printf("Expected handCount = 6, Actual handCount = %d\n", G.handCount[1]);
        if (G.handCount[1] == 6) {
            printf("TEST PASSED\n\n");
        } else {
            printf("TEST FAILED\n\n");
        }

        printf("Expected discardCount = 3, Actual discardCount = %d\n", G.discardCount[1]);
        if (G.discardCount[1] == 3) {
            printf("TEST PASSED\n\n");
        } else {
            printf("TEST FAILED\n\n");
        }

        printf("Expected deckCount = 1, Actual deckCount = %d\n", G.deckCount[1]);
        if (G.deckCount[1] == 1) {
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