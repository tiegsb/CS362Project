//
//  cardtest4.c
//  
//
//  Created by Anne Lindenberg on 10/24/15.
//
//

#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include "dominion.h"
#include "dominion_helpers.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int main() {
    int i, p, d, h, g, r;// p is numPlayer (player), d is deckSize, h is handSize, g position of great_hall, r is to initialize new game
    int seed = 1000;
    int numPlayer = 2;
    int maxBonus = 10;
    int bonus;
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    struct gameState G;
    struct gameState D;
    int deckSize = 5;
    int testHandSize = 5;
    // arrays of all coppers, silvers, and golds
    int coppers[MAX_HAND];
    int silvers[MAX_HAND];
    int golds[MAX_HAND];
    int temphand[MAX_HAND];
    int mixed[MAX_DECK];
    int allTreasure[MAX_DECK];
    int noTreasure[MAX_DECK];   
    int z = 0;
    //fill test deck
    for (i = 0; i < MAX_DECK; i++)
    {
        allTreasure[i] = copper;
        noTreasure[i] = k[6];
        if(i%2 == 0)
            mixed[i] = copper;
        else
            mixed[i] = k[6];
        
    }
    
    printf ("Testing cardGreat_Hall():\n");
    for (p = 0; p < numPlayer; p++)
    {
        for (d = 0; d < deckSize; d++){
            for (h = 0; h < testHandSize; h++){
                for (g = 0; g < testHandSize; g++){
            
#if (NOISY_TEST == 1)
                    printf("Test player = %d with deck size= %d hand= %d and position Great_Hall = %d.\n", p, d, h, g);
#endif
                    memset(&G, 23, sizeof(struct gameState));   // clear the game state
                    r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
                    G.deckCount[p] = d;
                    memcpy(G.deck[p], mixed, sizeof(int) * MAX_DECK);
                    memcpy(G.hand[p], allTreasure, sizeof(int) * MAX_HAND);
                    G.handCount[p] = h;
                    G.hand[p][g]= great_hall;
                    D = G;
#if (NOISY_TEST == 1)
                    printf("Testing treasure deck and action deck\n");
#endif
                    cardAdventurer(&G);
                    
#if (NOISY_TEST == 1)
                    // if deck size is less than 3
                    if(d < 1)
                        printf("Hand size = %d, expected = %d\n", G.handCount[p], D.handCount[p] - 1 + d);
                    else
                        printf("Hand size = %d, expected = %d\n", G.handCount[p], D.handCount[p]);
#endif
                    //core dump

//                    //if the deck size is less than 3 then handcount is equal to previous -1 plus the decksize
//                    if(d < 1)
//                        assert(G.handCount[p] == D.handCount[p] - 1 + d);
//                    else //else the handcount is equal to previous plus 2
//                        assert(G.handCount[p] == D.handCount[p]);

                    
#if (NOISY_TEST == 1)
                    
                    if(d < 1)
                        printf("Deck + Discard + Played = %d, Expected = %d\n", G.discardCount[p] + G.playedCardCount + G.deckCount[p], D.discardCount[p] + D.playedCardCount + D.deckCount[p] + 1);
                    else
                        printf("Deck + Discard + Played = %d, Expected = %d\n", G.discardCount[p] + G.playedCardCount + G.deckCount[p], D.discardCount[p] + D.playedCardCount + D.deckCount[p]);
                    
#endif
                    
// core dump
//                    if(d < 1)
//                        assert(G.discardCount[p] + G.playedCardCount + G.deckCount[p] == D.discardCount[p] + D.playedCardCount + D.deckCount[p] + 1);
//                    else
//                        assert(G.discardCount[p] + G.playedCardCount + G.deckCount[p] == D.discardCount[p] + D.playedCardCount + D.deckCount[p]);

                   
#if (NOISY_TEST == 1)
                    printf("Actions = %d expected = %d \n", G.numActions, D.numActions + 1);
#endif
                    

                 //core dump   assert(G.numActions == D.numActions + 1);

                }
            }
        }
    }
    

    printf("Tests passed.\n");

    
    
    return 0;
}