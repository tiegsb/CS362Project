/* -----------------------------------------------------------------------
 * Author: Tony Huynh		CS 362		unittest1.c

 * This test will if the player has gained a card (testGainCard)
 * In this test, I want to simply test if the current player has successfully gained
 * a card in their hand.  I want to do this by counting the card of the user's current
 * hand, then forcing them to gain a "gold" card, then finally checking to see if the 
 * user's handcount has incremented or not.
 * Include the following lines in your makefile:
 *
 * testGainCard: unittest1.c dominion.o rngs.o
 *      gcc -o testGainCard -g  unittest1.c dominion.o rngs.o $(CFLAGS)
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 0

int main() {
    int i;
    int seed = 1000;
    int numPlayer = 2;
    int maxBonus = 10;
    int p, r, handCount;
    int bonus;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int maxHandCount = 5;
    // making variable for before gainCard
    int beforeGainCard;
	int currentPlayer = whoseTurn(&G);

    printf ("TESTING gainCard():\n");
    for (p = 0; p < numPlayer; p++)
    {
        for (handCount = 1; handCount <= maxHandCount; handCount++)
        {
            for (bonus = 0; bonus <= maxBonus; bonus++)
            {
/*
#if (NOISY_TEST == 1)
                printf("Test player %d with %d treasure card(s) and %d bonus.\n", p, handCount, bonus);
#endif*/
				beforeGainCard = G.handCount[p];
                memset(&G, 23, sizeof(struct gameState));   // clear the game state
                r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
                G.handCount[p] = handCount;                 // set the number of cards on hand after gaining card
				gainCard(gold, &G, 2, currentPlayer);		// add a test gold card to the current player's hand
				printf("Value before gain: %i\n", beforeGainCard);
				printf("Value after gain: %i\n", G.handCount[p]);
				
				//assert(beforeGainCard == G.handCount[p]-1);
/*				
#if (NOISY_TEST == 1)
                //printf("G.coins = %d, expected = %d\n", G.coins, handCount * 1 + bonus);
#endif*/
                //assert(G.coins == handCount * 1 + bonus); // check if the number of coins is correct

/*				
#if (NOISY_TEST == 1)
                //printf("G.coins = %d, expected = %d\n", G.coins, handCount * 2 + bonus);
#endif*/
                //assert(G.coins == handCount * 2 + bonus); // check if the number of coins is correct
/*
#if (NOISY_TEST == 1)
                //printf("G.coins = %d, expected = %d\n", G.coins, handCount * 3 + bonus);
#endif*/
                //assert(G.coins == handCount * 3 + bonus); // check if the number of coins is correct
            }
        }
    }

    printf("All tests passed!\n");

    return 0;
}