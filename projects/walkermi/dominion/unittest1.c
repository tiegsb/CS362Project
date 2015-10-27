// Author: Michael Walker
// Assignment 3: unittest1.c
// Class: CS 362
// Works Cited: testUpdateCoins.c from class' Canvas Portal


#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <time.h>



// Set NOISY_TEST to 0 to Remove printf's From Output
#define NOISY_TEST 1



int main() {
    
    // seed random
    srand(time(NULL));
    int seed;
    
    // game/test set-up values
    int numPlayer = 2;
    int maxBonus = 10;
    int maxHandCount = 5;
    int gameCards[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    struct gameState state;
    
    // loop variables
    int i, player, handCount, bonus;
    
    // arrays of all coppers, silvers, golds, and adventurer
    int coppers[MAX_HAND];
    int silvers[MAX_HAND];
    int golds[MAX_HAND];
    int adventurers[MAX_HAND];
    for (i = 0; i < MAX_HAND; i++) {
        coppers[i] = copper;
        silvers[i] = silver;
        golds[i] = gold;
        adventurers[i] = adventurer;
    }
    
    printf ("TESTING updateCoins():\n");
    
    // Perform each test on each player
    for (player = 0; player < numPlayer; ++player) {
        
        // Perform test on each hand count
        for (handCount = 1; handCount <= maxHandCount; ++handCount) {
            
            // Perform test on each bonus value
            for (bonus = 0; bonus <= maxBonus; ++bonus) {
                
#if (NOISY_TEST == 1)
                printf("Player: %i, Hand Count: %i, Bonus: %i\n", player, handCount, bonus);
#endif
        
                // clear game state
                memset(&state, 23, sizeof(struct gameState));
                
                // initialize new game
                seed = rand() % 1000 + 1;
                assert(initializeGame(numPlayer, gameCards, seed, &state) == 0);
                
                // set players hand count
                state.handCount[player] = handCount;
        
                
                
// BEG Test 1: Hands With No Treasure Cards Sets Coin Count to Bonus Value
#if (NOISY_TEST == 1)
                printf("Test 1: Hands With No Treasure Cards Sets Coin Count to Bonus Value\n");
#endif
                // set all cards in hand to Adventurer Cards
                memcpy(state.hand[player], adventurers, sizeof(int) * handCount);

                // set initial coin count to zero
                state.coins = 0;
                
                // call updateCoins() and verify correct return value
                assert(updateCoins(player, &state, bonus) == 0);
                
#if (NOISY_TEST == 1)
                printf("Expected Coins: %i, Actual Coins: %i\n", bonus, state.coins);
#endif
                assert(state.coins == bonus);
// END Test 1: Hands With No Treasure Cards Sets Coin Count to Bonus Value
    
                
                
                
// BEG Test 2: Coin Count is Reset at Beginning of Function
#if (NOISY_TEST == 1)
                printf("Test 2: Coin Count is Reset at Beginning of Function\n");
#endif
                // set initial coin count to bonus value
                state.coins = bonus;
                
                // call updateCoins() and verify correct return value
                assert(updateCoins(player, &state, bonus) == 0);
                
#if (NOISY_TEST == 1)
                printf("Expected Coins: %i, Actual Coins: %i\n", bonus, state.coins);
#endif
                assert(state.coins == bonus);
// END Test 2: Coin Count is Reset at Beginning of Function

    
                
    
// BEG Test 3: Tresasure Cards Add Their Appropriate Value to state->coins AND Every Card in Hand is Considered
#if (NOISY_TEST == 1)
                printf("Test 3: Tresasure Cards Add Their Appropriate Value to state->coins AND Every Card in Hand is Considered\n");
#endif
                // set all cards in hand to Copper Cards
                memcpy(state.hand[player], coppers, sizeof(int) * handCount);
                
                // call updateCoins() and verify correct return value
                assert(updateCoins(player, &state, bonus) == 0);
                
#if (NOISY_TEST == 1)
                printf("ALL COPPER: Expected Coins: %i, Actual Coins: %i\n", bonus + handCount * 1, state.coins);
#endif
                assert(state.coins == bonus + handCount * 1);
                
                
                // set all cards in hand to Silver Cards
                memcpy(state.hand[player], silvers, sizeof(int) * handCount);
                
                // call updateCoins() and verify correct return value
                assert(updateCoins(player, &state, bonus) == 0);
                
#if (NOISY_TEST == 1)
                printf("ALL SILVER: Expected Coins: %i, Actual Coins: %i\n", bonus + handCount * 2, state.coins);
#endif
                assert(state.coins == bonus + handCount * 2);
                
                
                // set all cards in hand to Gold Cards
                memcpy(state.hand[player], golds, sizeof(int) * handCount);
                
                // call updateCoins() and verify correct return value
                assert(updateCoins(player, &state, bonus) == 0);
                
#if (NOISY_TEST == 1)
                printf("ALL GOLD: Expected Coins: %i, Actual Coins: %i\n", bonus + handCount * 3, state.coins);
#endif
                assert(state.coins == bonus + handCount * 3);
// END Test 3: Tresasure Cards Add Their Appropriate Value to state->coins AND Every Card in Hand is Considered
            }
        }
    }
    printf ("TESTING of updateCoins() COMPLETED SUCCESSFULLY\n");
    return 0;
}