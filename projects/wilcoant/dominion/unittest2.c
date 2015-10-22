/* -----------------------------------------------------------------------
 * unit test for get cost -----------------------------------------------------------------------
 */
//used provided testUpdateCoins.c shell provided in OSU Fall CS362
//modified some initialation variables to test boundaries more completely
 
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
    int numPlayer = 2;   //add for loop condition to iterate up to 4
    int maxBonus = 10;
    int p, r, handCount;
    int bonus;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int maxHandCount = 5;  //number of cards in each player's hand 
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

    printf ("TESTING shuffle():\n");
    while (numPlayer < MAX_PLAYERS)
    {
        for (p = 0; p < numPlayer; p++)
        {
            for (handCount = 0; handCount <= maxHandCount; handCount++)
            {//start at handcount 0 to test return -1 status
                
#if (NOISY_TEST == 1)
                    printf("Test player %d with %d handcounts(s).\n", p, handCount)
#endif
                    memset(&G, 23, sizeof(struct gameState));   // clear the game state
                    r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
                    G.handCount[p] = handCount;                 // set the number of cards on hand
                    memcpy(G.hand[p], coppers, sizeof(int) * handCount); // set all the cards to copper
                    updateCoins(p, &G, bonus);
#if (NOISY_TEST == 1)
                    printf("G.coins = %d, expected = %d\n", G.coins, handCount * 1 + bonus);
#endif
                    assert(G.coins == handCount * 1 + bonus); // check if the number of coins is correct
    
                    memcpy(G.hand[p], silvers, sizeof(int) * handCount); // set all the cards to silver
                    updateCoins(p, &G, bonus);
#if (NOISY_TEST == 1)
                    printf("G.coins = %d, expected = %d\n", G.coins, handCount * 2 + bonus);
#endif
                    assert(G.coins == handCount * 2 + bonus); // check if the number of coins is correct
    
                    memcpy(G.hand[p], golds, sizeof(int) * handCount); // set all the cards to gold
                    updateCoins(p, &G, bonus);
#if (NOISY_TEST == 1)
                    printf("G.coins = %d, expected = %d\n", G.coins, handCount * 3 + bonus);
#endif
                    assert(G.coins == handCount * 3 + bonus); // check if the number of coins is correct
                
            }
            //start at 2 players
        }//exit top for loop 
   numPlayer++; //increase numPlayer by one maxing at 4 to test game state for 2 - 4 players 
   }//exit while loop 

    printf("All tests passed!\n");

    return 0;
}
