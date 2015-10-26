//
//  unittest3.c
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
    int i, p, h, s, r;//p is player, h is the hand, s is set in the hand, r is initialize
    int seed = 1000;
    int numPlayer = 2;
    int maxBonus = 10;
    int handSize=7;
    int random;
    int k[10] = {adventurer, council_room, feast, gardens, mine
        , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    struct gameState D;
    int maxHandCount = 5;
    // arrays of all coppers, silvers, and golds
    int testhand[MAX_HAND];
    
    printf("Test by creating hand\n");
    for (i = 0; i < handSize; i++)
    {
        random = (int)(Random() * 10);
        testhand[i] = k [random];
    }
    
    printf ("TESTING discardCard(): \n");
    for (p = 0; p < MAX_PLAYERS; p++)
    {
        for (h = 1; h <= handSize; h++)
        {
            for (s = 1; s <= handSize; s++)
            {
#if (NOISY_TEST == 1)
                printf("Test player %d with %d card(s) in hand the card position in hand: %d, with trash flag: %d.\n", p, h, s, 0);
#endif
                memset(&G, 23, sizeof(struct gameState));   // clear the game state
                r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
                G.handCount[p] = h;                 // set the number of cards in hand
                memcpy(G.hand[p], testhand, sizeof(int) * MAX_HAND);
                D=G;
                discardCard(s, p, &G, 0);
#if (NOISY_TEST == 1)
                printf("Card discarded = %d, expected = %d\n", G.playedCards[G.playedCardCount - 1], D.hand[p][s]);
#endif
                assert(G.playedCards[G.playedCardCount - 1] == D.hand[p][s]);
                
                
#if (NOISY_TEST == 1)
                printf("Cards in hand = %d, expected = %d\n", G.handCount[p], D.handCount[p] - 1);
#endif
                assert(G.handCount[p] == D.handCount[p] - 1);
                
                for(i=0; i < G.handCount[p]; i++)
                    assert(G.hand[p][i]!= -1);
#if (NOISY_TEST == 1)
                printf("Player = %d, cards in hand = %d, position of card in hand = %d and trash flag = %d\n", p, h, s, 1);
#endif
                G=D;
                discardCard(s,p, &G, 1);
#if (NOISY_TEST == 1)
                printf("Discard = %d, expected = %d\n", G.playedCardCount, D.playedCardCount);
#endif
                assert(G.playedCardCount == D.playedCardCount);
            }
        }
    }
    
    printf("All tests passed!\n");
    
    return 0;
}
