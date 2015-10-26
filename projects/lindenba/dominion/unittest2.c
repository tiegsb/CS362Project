//
//  unittest2.c
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
    int i, p, d; // p is player, d is deck
    int seed = 1000;
    int numPlayer = 2;
    int r, random;
    int k[10] = {adventurer, council_room, feast, gardens, mine
        , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    struct gameState D;
    int testdeck[MAX_DECK];
    int practicedeck = 18;
   
    
    printf ("TESTING shuffle():\n");
    for (p = 0; p < MAX_PLAYERS; p++)
    {
        for (d = 0; d < practicedeck; d++)
        {
        
#if (NOISY_TEST == 1)
                printf("\nTest player %d with deck %d.", p, d);
#endif
                memset(&G, 23, sizeof(struct gameState));   // clear the game state
                r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
            
                for (i = 0; i < d; i++)
                {
                    random = (int)(Random() * 10);
                    testdeck[i] = k [random];
                }
                G.deckCount[p] = d;                 // set the number of cards in hand
                memcpy(G.deck[p], testdeck, sizeof(int) * MAX_DECK);
                D=G;
                shuffle(p, &G);
#if (NOISY_TEST == 1)
                printf("\nNew deck = ");
                for (i = 0; i < D.deckCount[p]; i++)
                printf("%d, ", D.deck[p][i]);

                printf("\nShuffled deck = ");
                for (i = 0; i < G.deckCount[p]; i++)
                printf("%d, ", G.deck[p][i]);
#endif
                assert(D.deck != G.deck);
            printf("\n");
        }
    }
    
    printf("All tests passed!\n");
    
    return 0;
}