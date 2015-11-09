// Author: Michael Walker
// Assignment 3: unittest4.c
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


int compareGameStates(struct gameState* preState, struct gameState* postState, int maxDeck, int maxHand, int maxPlayers, int currentPlayer, int currentSupplyPosition);

int main(int argc, const char * argv[]) {
    // seed random
    srand(time(NULL));
    int seed;
    
    // game/test set-up values
    int numPlayer = 2;
    int maxHandCount = 5;
    int gameCards[10] = {curse, estate, duchy, province, copper, silver, gold, adventurer, council_room, feast};
    struct gameState state;
    struct gameState preState;
    int gameStateCompareReturnValue;
    int begginingCardSupplyCount;
    
    // loop variables
    int i, player, handCount, toFlagSet, supplyPosition;
    
    printf ("TESTING gainCard():\n");
    
    // Perform each test on each player
    for (player = 0; player < numPlayer; ++player) {
        
        // Perform test on each hand count
        for (handCount = 1; handCount <= maxHandCount; ++handCount) {
    
            // Perform test on both Trash Flag values
            for (toFlagSet = 0; toFlagSet <= 2; ++toFlagSet) {
    
                for (supplyPosition = 0; supplyPosition < 10; ++supplyPosition) {

                    // clear game state
                    memset(&state, 23, sizeof(struct gameState));
                    
                    // initialize new game
                    seed = rand() % 1000 + 1;
                    assert(initializeGame(numPlayer, gameCards, seed, &state) == 0);
                    
                    // save game state prior to discardCard() call
                    preState = state;
                    
                    // save total supply count prior to drawing cards
                    begginingCardSupplyCount = state.supplyCount[supplyPosition];
    
                    // call function to test
                    assert(gainCard(supplyPosition, &state, toFlagSet, player) == 0);
                    
#if (NOISY_TEST == 1)
                    printf("Player: %i, Hand Count: %i, Supply Position: %i, Supply Card Count: %i\n", player + 1, handCount, supplyPosition, begginingCardSupplyCount);
#endif
                    
    
                    
// BEG Test 1: Card is Removed From Supply Pile
#if (NOISY_TEST == 1)
                    printf("Test 1: Card is Removed From Supply Pile\n");
#endif
                    
#if (NOISY_TEST == 1)
                    printf("Expected Supply Count: %i, Actual Supply Count: %i\n", begginingCardSupplyCount - 1, state.supplyCount[supplyPosition]);
#endif
                    assert((begginingCardSupplyCount - 1) == state.supplyCount[supplyPosition]);
// END Test 1: Card is Removed From Supply Pile
                    
                    
                    
                    if (toFlagSet == 0) {
// BEG Test 2: If toFlag is 0 One Card is Added to Current Player's Discard Pile and Discard Count Incremented
#if (NOISY_TEST == 1)
                        printf("Test 2: If toFlag is 0 One Card is Added to Current Player's Discard Pile and Discard Count Incremented\n");
#endif
                        
#if (NOISY_TEST == 1)
                        printf("Expected Discard Pile Count: %i, Actual Discard Pile Count: %i\n", preState.discardCount[player] + 1, state.discardCount[player]);
#endif
                        assert((preState.discardCount[player] + 1) == state.discardCount[player]);
                        
#if (NOISY_TEST == 1)
                        printf("Expected Added Card Type: %i, Actual Added Card Type: %i\n", supplyPosition, state.discard[player][state.discardCount[player] - 1]);
#endif
                        assert(supplyPosition == state.discard[player][state.discardCount[player] - 1]);
// END Test 2: If toFlag is 0 One Card is Added to Current Player's Discard Pile and Discard Count Incremented
                    }
                    
                    
                    else if (toFlagSet == 1) {
// BEG Test 3: If toFlag is 1 One Card is Added to Current Player's Deck and Deck Count Incremented
#if (NOISY_TEST == 1)
                        printf("Test 3: If toFlag is 1 One Card is Added to Current Player's Deck and Deck Count Incremented\n");
#endif
#if (NOISY_TEST == 1)
                        printf("Expected Deck Count: %i, Actual Deck Count: %i\n", preState.deckCount[player] + 1, state.deckCount[player]);
#endif
                        assert((preState.deckCount[player] + 1) == state.deckCount[player]);
                        
#if (NOISY_TEST == 1)
                        printf("Expected Added Card Type: %i, Actual Added Card Type: %i\n", supplyPosition, state.deck[player][state.deckCount[player] - 1]);
#endif
                        assert(supplyPosition == state.deck[player][state.deckCount[player] - 1]);

// END Test 3: If toFlag is 1 One Card is Added to Current Player's Deck and Deck Count Incremented
                    }
                    
                    else {
// BEG Test 4: If toFlag is 2 One Card is Added to Current Player's Hand and Hand Count Incremented
#if (NOISY_TEST == 1)
                        printf("Test 4: If toFlag is 2 One Card is Added to Current Player's Hand and Hand Count Incremented\n");
#endif
#if (NOISY_TEST == 1)
                        printf("Expected Hand Count: %i, Actual Hand Count: %i\n", preState.handCount[player] + 1, state.handCount[player]);
#endif
                        assert((preState.handCount[player] + 1) == state.handCount[player]);
                        
#if (NOISY_TEST == 1)
                        printf("Expected Added Card Type: %i, Actual Added Card Type: %i\n", supplyPosition, state.hand[player][state.handCount[player] - 1]);
#endif
                        assert(supplyPosition == state.hand[player][state.handCount[player] - 1]);

// END Test 4: If toFlag is 2 One Card is Added to Current Player's Hand and Hand Count Incremented
                    }
                    
                    
                    
// BEG Test 5: Cannot Draw More Cards From Supply Than Available
#if (NOISY_TEST == 1)
                    printf("Test 5: Cannot Draw More Cards From Supply Than Available\n");
#endif
#if (NOISY_TEST == 1)
                    printf("Drawing All %i Remaining Cards...\n", begginingCardSupplyCount - 1);
#endif
                    for (i = 0; i < begginingCardSupplyCount - 1; ++i) {
                        assert(gainCard(supplyPosition, &state, toFlagSet, player) == 0);
                    }
                    
#if (NOISY_TEST == 1)
                    printf("Expected: Card Supply Exhausted\n");
#endif
                    
                    assert(gainCard(supplyPosition, &state, toFlagSet, player) == -1);
                    
#if (NOISY_TEST == 1)
                    printf("Actual: Card Supply Exhausted\n");
#endif
// END Test 5: Cannot Draw More Cards From Supply Than Available
                    
                    
                    
// BEG Test 6: Game State is not Altered Other Than Current Player Hand & Count, Discard Pile & Count, Deck & Count, and Supply Count of Current Supply
#if (NOISY_TEST == 1)
                    printf("Test 6: Game State is not Altered Other Than Current Player Hand & Count, Discard Pile & Count, Deck & Count, and Supply Count of Current Supply\n");
#endif
                    gameStateCompareReturnValue = compareGameStates(&preState, &state, MAX_DECK, maxHandCount, numPlayer, player, supplyPosition);
                    
#if (NOISY_TEST == 1)
                    printf("Expected: Game State Compare Return Value = 0, Actual: Game State Compare Return Value = %i\n", gameStateCompareReturnValue);
#endif
// END Test 6: Game State is not Altered Other Than Current Player Hand & Count, Discard Pile & Count, Deck & Count, and Supply Count of Current Supply
                    
                    
                }
            }
        }
    }
    printf ("TESTING OF gainCard() COMPLETED SUCCESSFULLY\n");
    return 0;
}



int compareGameStates(struct gameState* preState, struct gameState* postState, int maxDeck, int maxHand, int maxPlayers, int currentPlayer, int currentSupplyPosition) {
    // comment out tests if not applicable for test
    // add custom tests below
    
    
    // default state comparisons:
    int i, ii;
    if (preState->numPlayers != postState->numPlayers)
        return 1;
    /**
    for (i = 0; i < treasure_map + 1; ++i) {
        if (preState->supplyCount[i] != postState->supplyCount[i])
            return 2;
    }
     **/
    for (i = 0; i < treasure_map + 1; ++i) {
        if (preState->embargoTokens[i] != postState->embargoTokens[i])
            return 3;
    }
    if (preState->outpostPlayed != postState->outpostPlayed)
        return 4;
    if (preState->outpostTurn != postState->outpostTurn)
        return 5;
    if (preState->whoseTurn != postState->whoseTurn)
        return 6;
    if (preState->phase != postState->phase)
        return 7;
    if (preState->coins != postState->coins)
        return 8;
    if (preState->numBuys != postState->numBuys)
        return 9;
    /**
    for (i = 0; i < maxPlayers; ++i) {
        for (ii = 0; ii < maxHand; ++ii) {
            if (preState->hand[i][ii] != postState->hand[i][ii])
                return 10;
        }
    }
    for (i = 0; i < maxPlayers; ++i) {
        if (preState->handCount[i] != postState->handCount[i])
            return 11;
    }
    for (i = 0; i < maxPlayers; ++i) {
        for (ii = 0; ii < maxDeck; ++ii) {
            if (preState->deck[i][ii] != postState->deck[i][ii])
                return 13;
        }
    }
    for (i = 0; i < maxPlayers; ++i) {
        if (preState->deckCount[i] != postState->deckCount[i])
            return 14;
    }
    for (i = 0; i < maxPlayers; ++i) {
        for (ii = 0; ii < maxDeck; ++ii) {
            if (preState->discard[i][ii] != postState->discard[i][ii])
                return 15;
        }
    }
    for (i = 0; i < maxPlayers; ++i) {
        if (preState->discardCount[i] != postState->discardCount[i])
            return 16;
    }
    **/
    for (i = 0; i < maxDeck; ++i) {
        if (preState->playedCards[i] != postState->playedCards[i])
            return 17;
    }
    if (preState->playedCardCount != postState->playedCardCount)
        return 18;
     
    
    
    // custom state comparisons:
    for (i = 0; i < treasure_map + 1; ++i) {
        if ((preState->supplyCount[i] != postState->supplyCount[i]) && (i != currentSupplyPosition))
            return 19;
    }
    for (i = 0; i < maxPlayers; ++i) {
        for (ii = 0; ii < maxHand; ++ii) {
            if ((preState->hand[i][ii] != postState->hand[i][ii]) && (i != currentPlayer))
                return 20;
        }
    }
    for (i = 0; i < maxPlayers; ++i) {
        if ((preState->handCount[i] != postState->handCount[i]) && (i != currentPlayer))
            return 21;
    }
    for (i = 0; i < maxPlayers; ++i) {
        for (ii = 0; ii < maxDeck; ++ii) {
            if ((preState->deck[i][ii] != postState->deck[i][ii]) && (i != currentPlayer))
                return 22;
        }
    }
    for (i = 0; i < maxPlayers; ++i) {
        if ((preState->deckCount[i] != postState->deckCount[i]) && (i != currentPlayer))
            return 23;
    }
    for (i = 0; i < maxPlayers; ++i) {
        for (ii = 0; ii < maxDeck; ++ii) {
            if ((preState->discard[i][ii] != postState->discard[i][ii]) && (i != currentPlayer))
                return 24;
        }
    }
    for (i = 0; i < maxPlayers; ++i) {
        if ((preState->discardCount[i] != postState->discardCount[i]) && (i != currentPlayer))
            return 25;
    }
    
    return 0;
}