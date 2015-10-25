/* Author: Ashok Nayar
 * cs362, Fall 2015
 * Assignment 3: Unit Testing
 * unittest4.c (Testing fullDeckCount())
 */


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"


// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1


int main() {
    int i;
    int seed = 1000;
    int numPlayer = 2;

    int p, r;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int testCard = adventurer;

    printf("Testing fullDeckCount()\n");

    // Loop over each player
    for (p = 0; p <numPlayer; p++)
    {
        r = initializeGame(numPlayer, k, seed, &G); // Intialize game
        
        // Set sizes of deck, discard pile, and hand
        G.deckCount[p] =  MAX_DECK;
        G.discardCount[p] = MAX_DECK;
        G.handCount[p] = MAX_HAND;
        
        // Fill the deck, discard pile, and hand with the same type of card
        for (i = 0; i<MAX_DECK; i++)
        {
            G.deck[p][i] = 13;
            G.discard[p][i] = 13;
            G.hand[p][i] = 13;
        }
#if (NOISY_TEST == 1)
        printf("***Test for player %d\n\n",p);
#endif
        // Call the function and look for the test card. These tests
        // should return 0 as all the cards in each deck are different
        // From the test card
#if (NOISY_TEST == 1)
        printf("Testing card %d for player %d\n",testCard, p);
        printf("Expected: %d, Received: %d  \n",0, fullDeckCount(p, testCard,&G));
#endif
        assert(fullDeckCount(p,testCard , &G) == 0);

        // Add a single test card to each deck
        G.deck[p][0] = testCard;
        G.discard[p][0] = testCard;
        G.hand[p][0] = testCard;
        
        // There is one test card in each deck (3 total) so the value
        // Return by the function should be 3.
#if (NOISY_TEST == 1)
        printf("Testing card %d for player %d\n",testCard, p);
        printf("Expected: %d, Received: %d  \n",3, fullDeckCount(p, testCard,&G));
#endif
        assert(fullDeckCount(p,testCard , &G) == 3);

        // Make each deck entirely out of test cards
        for (i = 0; i<MAX_DECK; i++)
        {
            G.deck[p][i] = testCard;
            G.discard[p][i] = testCard;
            G.hand[p][i] = testCard;
        }
        
        // Each deck now has only test cards. The function should now
        // return the combined size of each deck
#if (NOISY_TEST == 1)
        printf("Testing card %d for player %d\n",testCard, p);
        printf("Expected: %d, Received: %d  \n",MAX_DECK + MAX_DECK + MAX_HAND, fullDeckCount(p, testCard,&G));
#endif
        
        assert(fullDeckCount(p,testCard , &G) == (MAX_DECK + MAX_DECK + MAX_HAND) );

        printf("\n");
    }
    

    printf("All tests passed!\n");

    return 0;
}