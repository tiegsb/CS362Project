// tests updateCoins() function
// adapted from example code `testUpdateCoins.c` provided by instructor for use as template

#include <stdio.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

int main(int argc, char *argv[])
{
    int retVal;
    int player;
    int numPlayers = 2;
    int handCount;
    int maxHandCount = 5;
    int bonus;
    int maxBonus = 10;
    int seed = 9999; // seed for random number generator
    int k[10] = {adventurer, council_room, feast, gardens, mine,
                 remodel, smithy, village, baron, great_hall}; // kingdom cards
    struct gameState testState;
    int i;
    int coppers[MAX_HAND];
    int silvers[MAX_HAND];
    int golds[MAX_HAND];

    // create arrays of all copper, silver, and gold
    for (i = 0; i < MAX_HAND; i++)
    {
        coppers[i] = copper;
        silvers[i] = silver;
        golds[i] = gold;
    }

    // initialize a new game for testing purposes
    retVal = initializeGame(numPlayers, k, seed, &testState);

    if (retVal == 0)
    {
        printf("Game initialized successfully\n");
    }
    else
    {
        printf("Game failed to initialize.\n");
    }

    // vary the number of players (1 or 2)
    for (player = 1; player <= numPlayers; player++)
    {
        // test with differing numbers of treasure cards (1 to 5)
        for (handCount = 1; handCount <= maxHandCount; handCount++)
        {
            // test with varying bonus amounts (0 to 10 coins)
            for (bonus = 0; bonus <= maxBonus; bonus++)
            {

                printf("Test player %d with %d treasure card(s) and %d bonus.\n", player, handCount, bonus);
// memset(&testState, 23, sizeof(struct gameState));   // clear the game state
// r = initializeGame(numPlayers, k, seed, &testState); // initialize a new game

                // reset coins to zero for each iteration
                testState.coins = 0;

                // set the number of cards in hand
                testState.handCount[player] = handCount;

                // change all the cards in current player's hand to copper treasure cards
                memcpy(testState.hand[player], coppers, sizeof(int) * handCount);
                updateCoins(player, &testState, bonus);

                printf("testState.coins = %d, expected = %d\n", testState.coins, handCount * 1 + bonus);

                // check if the number of coins is correct - use if / else instead of assert to allow
                // execution to continue in spite of failing tests
                if (testState.coins == handCount * 1 + bonus)
                {
                    printf("PASS\n");
                }
                else
                {
                    printf("FAIL\n");
                }

                // change all the cards in current player's hand to silver treasure cards
                memcpy(testState.hand[player], silvers, sizeof(int) * handCount);
                updateCoins(player, &testState, bonus);

                printf("testState.coins = %d, expected = %d\n", testState.coins, handCount * 2 + bonus);

                // check if the number of coins is correct
                if (testState.coins == handCount * 2 + bonus)
                {
                    printf("PASS\n");
                }
                else
                {
                    printf("FAIL\n");
                }

                // change all the cards in current player's hand to gold treasure cards
                memcpy(testState.hand[player], golds, sizeof(int) * handCount);
                updateCoins(player, &testState, bonus);

                printf("testState.coins = %d, expected = %d\n", testState.coins, handCount * 3 + bonus);

                // check if the number of coins is correct
                if (testState.coins == handCount * 3 + bonus)
                {
                    printf("PASS\n");
                }
                else
                {
                    printf("FAIL\n");
                }
            }
        }
    }

    return 0;
}
