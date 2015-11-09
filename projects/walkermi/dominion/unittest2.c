// Author: Michael Walker
// Assignment 3: unittest2.c
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

int main(int argc, const char * argv[]) {
    // seed random
    srand(time(NULL));
    int seed;
    
    // game/test set-up values
    int numPlayer = 2;
    int numCardTypes = 27;
    int maxDeck = 15;
    int maxDiscard = 10;
    int maxHandCount = 5;
    int gameCards[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    struct gameState state;
    int count;
    int randNegativeDeckCardNum;
    int randNegativeDiscardNum;
    int randNegativeHandCardNum;
    int totalRandNegativeCards;
    
    // loop variables
    int i, player, cardType, deckCount, discardCount, handCount;
    
    // arrays of cards deck count is looking for (positive) and not looking for (negative)
    int cardTypePositve[MAX_HAND];
    int cardTypeNegative[MAX_HAND];
    for (i = 0; i < MAX_HAND; i++) {
        cardTypeNegative[i] = 27;
    }
    
    printf ("TESTING fullDeckCount():\n");
    
    // Perform each test on each player
    for (player = 0; player < numPlayer; ++player) {
        
        // Perform each test on card type
        for (cardType = 0; cardType < numCardTypes; ++cardType) {
            
            // set postive cards to current card type being searched for
            for (i = 0; i < MAX_HAND; i++) {
                cardTypePositve[i] = cardType;
            }
            
            // Perform each test on each deck count
            for (deckCount = 0; deckCount <= maxDeck; ++deckCount) {
                
                // Perform each test on each discard pile count
                for (discardCount = 0; discardCount <= maxDiscard; ++discardCount) {
                    
                    // Perform each test on each hand count
                    for (handCount = 0; handCount <= maxHandCount; ++handCount) {
                     
                        // clear game state
                        memset(&state, 23, sizeof(struct gameState));
                        
                        // initialize new game
                        seed = rand() % 1000 + 1;
                        assert(initializeGame(numPlayer, gameCards, seed, &state) == 0);
                        
                        // set players deck, discard, and hand count
                        state.deckCount[player] = deckCount;
                        state.discardCount[player] = discardCount;
                        state.handCount[player] = handCount;
                        
#if (NOISY_TEST == 1)
                        printf("Player: %i, Deck Count: %i, Discard Count: %i, Hand Count: %i, Card Type: %i\n", player, deckCount, discardCount, handCount, cardType);
#endif
                        
                        
// BEG Test 1: All Cards in Deck, Discard, and Hand are Counted
#if (NOISY_TEST == 1)
                        printf("Test 1: All Cards in Deck, Discard, and Hand are Counted\n");
#endif

                        // set all cards in deck to current positive card type
                        memcpy(state.deck[player], cardTypePositve, sizeof(int) * deckCount);
                        
                        // set all cards in discard to current positive card type
                        memcpy(state.discard[player], cardTypePositve, sizeof(int) * discardCount);
                        
                        // set all cards in hand to current positive card type
                        memcpy(state.hand[player], cardTypePositve, sizeof(int) * handCount);
                        
                        count = fullDeckCount(player, cardType, &state);
                        
#if (NOISY_TEST == 1)
                        printf("Expected Count: %i, Actual Count: %i\n", deckCount + handCount + discardCount, count);
#endif
                        assert(count == deckCount + handCount + discardCount);
// END Test 1: Hands With No Treasure Cards Sets Coin Count to Bonus Value
                        
                        
                        
                        
// Beg Test 2: Cards Not Currently Searched for are Not Included in Count
#if (NOISY_TEST == 1)
                        printf("Test 2: Cards Not Currently Searched for are Not Included in Count\n");
#endif
                        // randomly insert number of negative cards to insert in deck, discard, and hand
                        randNegativeDeckCardNum = 0;
                        randNegativeDiscardNum = 0;
                        randNegativeHandCardNum = 0;
                        if (deckCount != 0)
                            randNegativeDeckCardNum = rand() % deckCount + 1;
                        if (discardCount != 0)
                            randNegativeDiscardNum = rand() % discardCount + 1;
                        if (handCount != 0)
                            randNegativeHandCardNum = rand() % handCount + 1;
                        totalRandNegativeCards = randNegativeDeckCardNum + randNegativeDiscardNum + randNegativeHandCardNum;
                        
                        // set all cards in deck to current positive card type
                        memcpy(state.deck[player], cardTypeNegative, sizeof(int) * randNegativeDeckCardNum);
                        
                        // set all cards in discard to current positive card type
                        memcpy(state.discard[player], cardTypeNegative, sizeof(int) * randNegativeDiscardNum);
                        
                        // set all cards in hand to current positive card type
                        memcpy(state.hand[player], cardTypeNegative, sizeof(int) * randNegativeHandCardNum);
                        
                        count = fullDeckCount(player, cardType, &state);
                        
#if (NOISY_TEST == 1)
                        printf("Number of Negative Cards: %i, Expected Count: %i, Actual Count: %i\n", totalRandNegativeCards, deckCount + handCount + discardCount - totalRandNegativeCards, count);
#endif
                        assert(count == deckCount + handCount + discardCount - totalRandNegativeCards);
// END Test 2: Cards Not Currently Searched for are Not Included in Count
                    }
                }
            }
        }
    }
    
    printf ("TESTING of fullDeckCount() COMPLETED SUCCESSFULLY\n");
    return 0;
}
