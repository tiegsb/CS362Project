#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main() {
    int i, j;
    int seed = 1000;
    int p, r;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int handCount;
    int discardCount;
    int canBuy;
    int coins;
    int cost;

    printf ("TESTING buyCard():\n");
    p = 0;
    for (i = 0; i < 10; i++)
    {
        printf("Test buy card %d.\n", k[i]);
        r = initializeGame(2, k, seed, &G);
        handCount = G.handCount[p];
        discardCount = G.discardCount[p];
        coins = G.coins;

        // No buys
        G.numBuys = 0;
        buyCard(k[i], &G);
        printf("hand count = %d, expected = %d\n", G.handCount[p], handCount);
        //assert(G.handCount[p] == handCount);
        printf("coins = %d, expected = %d\n", G.coins, coins);
        assert(G.coins == coins);

        // No supply
        r = initializeGame(2, k, seed, &G); 
        G.supplyCount[k[i]] = 0;
        buyCard(k[i], &G);
        printf("hand count = %d, expected = %d\n", G.handCount[p], handCount);
        //assert(G.handCount[p] == handCount);
        printf("coins = %d, expected = %d\n", G.coins, coins);
        assert(G.coins == coins);

        // Test various coin amounts
        for (j = 0; j < 8; j++)
        {
            r = initializeGame(2, k, seed, &G); 
            canBuy = 1;
            G.coins = j;
            coins = j;
            cost = getCost(k[i]);
            if (G.coins >= cost) 
                canBuy = 0;
            buyCard(k[i], &G);
            if (canBuy == 0)
            {
                printf("hand count = %d, expected = %d\n", G.handCount[p], handCount);
                //assert(G.handCount[p] == handCount + 1);
                printf("discard count = %d, expected = %d\n", G.discardCount[p], discardCount + 1);
                assert(G.discardCount[p] == discardCount + 1);
                printf("coins = %d, expected = %d\n", G.coins, coins - cost);
                assert(G.coins == coins - cost);
            }
            if (canBuy == 1)
            {
                printf("hand count = %d, expected = %d\n", G.handCount[p], handCount);
                //assert(G.handCount[p] == handCount);
                printf("discard count = %d, expected = %d\n", G.discardCount[p], discardCount);
                assert(G.discardCount[p] == discardCount);
                printf("coins = %d, expected = %d\n", G.coins, coins);
                assert(G.coins == coins);
            } 
        }
    }
        
    printf("All tests passed!\n");

    return 0;
}