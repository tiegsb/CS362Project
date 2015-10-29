/* -----------------------------------------------------------------------
 * Unit Test for updateCoins()
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

    printf ("TESTING updateCoins():\n");
    for (p = 2; p >= numPlayer; p++){
        
    	memset(&G, 23, sizeof(struct gameState));   // clear the game state
    	r = initializeGame(numPlayer, k, seed, &G); // initialize a new game

        G.handCount[1] = 5;
        
        G.hand[1][0] = 0;
        G.hand[1][1] = 0;
        G.hand[1][2] = 0;
        G.hand[1][3] = 0;
        G.hand[1][4] = 0;

        updateCoins(1, &G, 0);
        printf("Expected coin score = 0, Actual coin score = %d\n", G.coins);
        if (G.coins == 0) {
            printf("Coin score TEST PASSED\n\n");
        } else {
            printf("Coin score TEST FAILED\n\n");
        }

        G.hand[1][0] = copper;
        G.hand[1][1] = 0;
        G.hand[1][2] = 0;
        G.hand[1][3] = copper;
        G.hand[1][4] = 0;

        updateCoins(1, &G, 0);
        printf("Expected coin score = 2, Actual coin score = %d\n", G.coins);
        if (G.coins == 2) {
            printf("Coin score TEST PASSED\n\n");
        } else {
            printf("Coin score TEST FAILED\n\n");
        }

        G.hand[1][0] = copper;
        G.hand[1][1] = 0;
        G.hand[1][2] = copper;
        G.hand[1][3] = copper;
        G.hand[1][4] = 0;

        updateCoins(1, &G, 0);
        printf("Expected coin score = 3, Actual coin score = %d\n", G.coins);
        if (G.coins == 3) {
            printf("Coin score TEST PASSED\n\n");
        } else {
            printf("Coin score TEST FAILED\n\n");
        }

        G.hand[1][0] = copper;
        G.hand[1][1] = copper;
        G.hand[1][2] = copper;
        G.hand[1][3] = 0;
        G.hand[1][4] = copper;

        updateCoins(1, &G, 0);
        printf("Expected coin score = 4, Actual coin score = %d\n", G.coins);
        if (G.coins == 4) {
            printf("Coin score TEST PASSED\n\n");
        } else {
            printf("Coin score TEST FAILED\n\n");
        }

        G.hand[1][0] = copper;
        G.hand[1][2] = copper;
        G.hand[1][3] = copper;
        G.hand[1][3] = copper;
        G.hand[1][4] = copper;

        updateCoins(1, &G, 0);
        printf("Expected coin score = 5, Actual coin score = %d\n", G.coins);
        if (G.coins == 5) {
            printf("Coin score TEST PASSED\n\n");
        } else {
            printf("Coin score TEST FAILED\n\n");
        }

        G.hand[1][0] = silver;
        G.hand[1][1] = silver;
        G.hand[1][2] = 0;
        G.hand[1][3] = copper;
        G.hand[1][4] = copper;

        updateCoins(1, &G, 0);
        printf("Expected coin score = 6, Actual coin score = %d\n", G.coins);
        if (G.coins == 6) {
            printf("Coin score TEST PASSED\n\n");
        } else {
            printf("Coin score TEST FAILED\n\n");
        }

        G.hand[1][0] = gold;
        G.hand[1][1] = silver;
        G.hand[1][2] = copper;
        G.hand[1][3] = copper;
        G.hand[1][4] = gold;

        updateCoins(1, &G, 0);
        printf("Expected coin score = 10, Actual coin score = %d\n", G.coins);
        if (G.coins == 10) {
            printf("Coin score TEST PASSED\n\n");
        } else {
            printf("Coin score TEST FAILED\n\n");
        }

        G.hand[1][0] = silver;
        G.hand[1][1] = gold;
        G.hand[1][2] = silver;
        G.hand[1][3] = gold;
        G.hand[1][4] = copper;

        updateCoins(1, &G, 0);
        printf("Expected coin score = 11, Actual coin score = %d\n", G.coins);
        if (G.coins == 11) {
            printf("Coin score TEST PASSED\n\n");
        } else {
            printf("Coin score TEST FAILED\n\n");
        }

        G.hand[1][0] = gold;
        G.hand[1][1] = gold;
        G.hand[1][2] = gold;
        G.hand[1][3] = gold;
        G.hand[1][4] = gold;

        updateCoins(1, &G, 0);
        printf("Expected coin score = 15, Actual coin score = %d\n", G.coins);
        if (G.coins == 15) {
            printf("Coin score TEST PASSED\n\n");
        } else {
            printf("Coin score TEST FAILED\n\n");
        }

    	return 0;
	}
}