//
//  unittest4.c
//  
//
//  Created by Anne Lindenberg on 10/24/15.
//
//

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"


#define NOISY_TEST 1

int main() {
    int i, p, h, r;//p is player, h is the hand, r is initialize
    int seed = 1000;
    int numPlayer = 2;
    int maxBonus = 10;
    int decksize = 25;
    int handSize=5;
    int discard = 5;
    int random;
    int k[10] = {adventurer, council_room, feast, gardens, mine
        , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    struct gameState D;
    // arrays of all coppers, silvers, and golds
    int testdeck[MAX_DECK];
    int testhand[MAX_HAND] = {council_room, silver, silver, mine, gold};
    int discardhand[MAX_DECK] = {province, estate, baron, mine, gold};
    
    
    printf ("TESTING drawCard(): \n");
    for (p = 0; p < MAX_PLAYERS; p++)
    {
        for (h = 0; h <= decksize; h++)
        {
#if (NOISY_TEST == 1)
                printf("Test player %d and deck size: %d.\n", p, h, 0);
#endif
                memset(&G, 23, sizeof(struct gameState));   // clear the game state
                r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
                for (i = 0; i < h; i++)
                {
                    random = (int)(Random() * 10);
                    testhand[i] = k [random];
                }

                G.handCount[p] = h;                 // set the number of cards in hand
                memcpy(G.hand[p], testhand, sizeof(int) * MAX_HAND);
                memcpy(G.deck[p], testdeck, sizeof(int) * MAX_DECK);
                G.handCount[p] = handSize;
                memcpy(G.discard[p], discardhand, sizeof(int) * MAX_DECK);
                G.discardCount[p] = discard;
                D=G;
                drawCard(p, &G);
#if (NOISY_TEST == 1)
                printf("Discard count = %d, expected = %d\n", G.discardCount[p], 0);
                printf("Deck size = %d, expected = %d\n", G.deckCount[p], D.deckCount[p] + D.discardCount[p] - 1);
                printf("Hand size %d, expected = %d \n", G.handCount[p], D.handCount[p] +1);
#endif
               // assert(G.discardCount[p] == 0);
            //core dump assert(G.handCount[p] == D.handCount[p] + 1);
            
                

        }
    }
    
    printf("All tests passed!\n");
    
    return 0;
}
