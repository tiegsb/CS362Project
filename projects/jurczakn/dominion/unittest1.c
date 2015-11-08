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

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int getValue(int card, int num, int total){

	if (card == 0){
		return num * -1;
	}
	else if (card == 1){
		return num * 1;
	}
	else if (card == 2){
		return num * 3;
	}
	else if (card == 3){
		return num * 6;
	}
	else if (card == 4){
		return num * 1;
	}
	else if (card == 5){
		return total / 10;
	}
	return -1000;
}

int main() {
    int i;
    int seed = 1000;
    int numPlayer = 2;
    int p, r, handCount, deckCount, discardCount, vh, vd, vds, score, cards, testScore;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int maxHandCount = 5;
    int maxDeckCount = 5;
    int maxDiscardCount = 5;
    // arrays of all victory cards
    /*int curses[MAX_DECK];
    int estates[MAX_DECK];
    int duchys[MAX_DECK];
    int provinces[MAX_DECK];
    int great_halls[MAX_DECK];
    int gardenss[MAX_DECK];*/
    int victoryCards[6][MAX_DECK];
    for (i = 0; i < MAX_DECK; i++)
    {
        victoryCards[0][i] = curse;
        victoryCards[1][i] = estate;
        victoryCards[2][i] = duchy;
	victoryCards[3][i] = province;
	victoryCards[4][i] = great_hall;
	victoryCards[5][i] = gardens;
    }

    printf ("TESTING scoreFor():\n");
    for (p = 0; p < numPlayer; p++)
    {
	for (vh = 0; vh < 6; vh++){
        for (handCount = 1; handCount <= maxHandCount; handCount++)
        {
	    for (vd = 0; vd < 6; vd++){
            for (deckCount = 0; deckCount <= maxDeckCount; deckCount++)
            {
		for (vds = 0; vds < 6; vds++){
		for (discardCount = 0; discardCount <= maxDiscardCount; discardCount++){
		cards = handCount + deckCount + discardCount;
#if (NOISY_TEST == 1)
                printf("Test player %d with %d victory card(s).\n", p, cards);
		printf("%d of card number %d in hand\n", handCount, vh);
		printf("%d of card number %d in deck\n", deckCount, vd);
		printf("%d of card number %d in discard\n", discardCount, vds);
#endif
		cards = handCount + deckCount + discardCount;
		score = 0;				    // clear score
                memset(&G, 23, sizeof(struct gameState));   // clear the game state
                r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
                G.handCount[p] = handCount;                 // set the number of cards on hand
		G.deckCount[p] = deckCount;		    // set the number of cards in deck
		G.discardCount[p] = discardCount;	    // set the number in discard
                memcpy(G.hand[p], victoryCards[vh], sizeof(int) * handCount);
		memcpy(G.deck[p], victoryCards[vd], sizeof(int) * deckCount);
		memcpy(G.discard[p], victoryCards[vds], sizeof(int) * discardCount);
		score = getValue(vh, handCount, cards) + getValue(vd, deckCount, cards) + getValue(vds, discardCount, cards);
		testScore = scoreFor (p, &G);
#if (NOISY_TEST == 1)
		printf("Score calculated: %d, Expected: %d\n", testScore, score);
		if (score == testScore){
			printf("SUCCESS\n");
		}
		else {
			printf("FAILURE<=============================\n");
		}
#endif
		
		}
		}
            }
	    }
	}
	}
    }
#if (NOISY_TEST == 1)
    printf("All tests ended in scoreFor()\n");
#endif

    return 0;
}
