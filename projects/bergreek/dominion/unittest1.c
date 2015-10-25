#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main() {
    int seed = 1000;
    int maxBonus = 10;
    int p, r;
    int bonus;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int handCount;
    int maxHandCount = 5;
    int coppers[MAX_HAND];
    int silvers[MAX_HAND];
    int golds[MAX_HAND];

    int i;
    for (i = 0; i < MAX_HAND; i++)
    {
        coppers[i] = copper;
        silvers[i] = silver;
        golds[i] = gold;
    }

    printf ("TESTING updateCoins():\n");
    for (p = 0; p < 2; p++)
    {
        for (handCount = 1; handCount <= maxHandCount; handCount++)
        {
            for (bonus = 0; bonus <= maxBonus; bonus++)
            {
                printf("Test player %d with %d treasure card(s) and %d bonus.\n", p, handCount, bonus);
                memset(&G, 23, sizeof(struct gameState));   
                r = initializeGame(2, k, seed, &G); 
                G.handCount[p] = handCount;                 
                
                memcpy(G.hand[p], coppers, sizeof(int) * handCount);
                updateCoins(p, &G, bonus);
                printf("G.coins = %d, expected = %d\n", G.coins, handCount * 1 + bonus);
                assert(G.coins == handCount * 1 + bonus); 

                memcpy(G.hand[p], silvers, sizeof(int) * handCount); 
                updateCoins(p, &G, bonus);
                printf("G.coins = %d, expected = %d\n", G.coins, handCount * 2 + bonus);
                assert(G.coins == handCount * 2 + bonus); 

                memcpy(G.hand[p], golds, sizeof(int) * handCount); 
                updateCoins(p, &G, bonus);
                printf("G.coins = %d, expected = %d\n", G.coins, handCount * 3 + bonus);
                assert(G.coins == handCount * 3 + bonus); 
            }
        }
    }

    printf("All tests passed!\n");

    return 0;
}