//
//  unittest1.c
//  
//
//  Created by Anne Lindenberg on 10/21/15.
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
    int i, p, h, b, r; // p is player, h is hand, and b is bonus, r to initialize game
    int seed = 1000;
    int numPlayer = 2;
    int maxBonus = 10;
    int handCount = 7;
    int bonus;
    int k[10] = {adventurer, council_room, feast, gardens, mine
        , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int maxHandCount = 5;
    // arrays of all coppers, silvers, and golds
    int coppers[MAX_HAND];
    int silvers[MAX_HAND];
    int golds[MAX_HAND];
    
    printf("Creating hand\n");
    for (i = 0; i < handCount; i++)
    {
        coppers[i] = copper;
        silvers[i] = silver;
        golds[i] = gold;
    }
    
    printf ("TESTING updateCoins(): \n");
    for (p = 0; p < MAX_PLAYERS; p++)
    {
        for (h = 1; h <= handCount; h++)
        {
            for (b = 0; b <= maxBonus; b++)
            {
#if (NOISY_TEST == 1)
                printf("Test player %d with %d treasure card(s) and %d bonus.\n", p, h, b);
#endif
                memset(&G, 23, sizeof(struct gameState));   // clear the game state
                r = initializeGame(MAX_PLAYERS, k, seed, &G); // initialize a new game
                G.handCount[p] = h;                 // set the number of cards on hand
                memcpy(G.hand[p], coppers, sizeof(int) * MAX_HAND); // set all the cards to copper
                updateCoins(p, &G, b);
#if (NOISY_TEST == 1)
                printf("Coins = %d, expected = %d\n", G.coins, h * 1 + b);
#endif
                assert(G.coins == h * 1 + b); // check if the number of coins is correct
                
                memcpy(G.hand[p], silvers, sizeof(int) * MAX_HAND); // set all the cards to silver
                updateCoins(p, &G, b);
#if (NOISY_TEST == 1)
                printf("Coins = %d, expected = %d\n", G.coins, h * 2 + b);
#endif
                assert(G.coins == h * 2 + b); // check if the number of coins is correct
                
                memcpy(G.hand[p], golds, sizeof(int) * MAX_HAND); // set all the cards to gold
                updateCoins(p, &G, b);
#if (NOISY_TEST == 1)
                printf("Coins = %d, expected = %d\n", G.coins, h * 3 + b);
#endif
                assert(G.coins == h * 3 + b); // check if the number of coins is correct
            }
        }
    }
    
    printf("All tests passed!\n");
    
    return 0;
}