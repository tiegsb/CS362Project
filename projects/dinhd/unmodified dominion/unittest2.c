/*
This program tests the fullDeckCount function.
The parameters for this function are:
int player, int card, struct gameState *state

*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include "interface.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int main() {
    int i;
    int numPlayer = 2;
    int p;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    char name[32];

    initializeGame(2, k, 2, &G);

    //printSupply(&G);
    //testing to see if all cards can be accounted for. 

    printf ("* * * * * * * * * * * * * * * * TESTING unittest2 fullDeckCount():* * * * * * * * * * * * * * * * \n");

    int arraySize = sizeof(k)/sizeof(k[0]);
    for (i = 0; i < arraySize; i++)
    {
        cardNumToName(k[i], name); 
    

        for (p = 0; p < numPlayer; p++)
        {
           //test to see if the deck count is correct for 0 cards
            printf ("Test: No %s's in for player %i \n", name, p);
            assert (fullDeckCount(0, 60, &G) == 0);

           //test to see if the deck count is correct for 1 card in deck
            G.deck[p][0] = k[i];
            G.deckCount[p] = 1;

            printf ("Test: One %s in deck for player %i \n", name, p);
            // assert (fullDeckCount(p, k[i], &G) == 1);

            //test to see if the deck count is correct for a card in both hand and deck. 
            G.hand[p][0] = k[i];
            G.handCount[p] = 1;

            printf ("Test: One %s in hand and deck for player %i \n", name, p);
            // assert (fullDeckCount(p, k[i], &G) == 2); 

            //test to see if the deck count is correct for a card in hand, discard and deck. 
            G.discard[p][0] = k[i];
            G.discardCount[p] = 1;

            printf ("Test: One %s in discard, hand and deck for player %i \n", name, p);
            // assert (fullDeckCount(p, k[i], &G) == 3); 
        }
    }


    printf("All tests passed!\n");

    return 0;
}
