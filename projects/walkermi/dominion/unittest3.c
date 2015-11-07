// Author: Michael Walker
// Assignment 3: unittest3.c
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


int compareGameStates(struct gameState* preState, struct gameState* postState, int maxDeck, int maxHand, int maxPlayers, int currentPlayer);

int main(int argc, const char * argv[]) {

    // seed random
    srand(time(NULL));
    int seed;
    
    // game/test set-up values
    int numPlayer = 2;
    int maxHandCount = 5;
    int gameCards[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    struct gameState state;
    struct gameState preState;
    int gameStateCompareReturnValue;
    
    // loop variables
    int i, player, handCount, discardHandPosition, trashFlagSet;
    
    // arrays of all adventurers
    int adventurers[MAX_HAND];
    for (i = 0; i < MAX_HAND; i++) {
        adventurers[i] = adventurer;
    }
    
    printf ("TESTING discardCard():\n");
    
    // Perform each test on each player
    for (player = 0; player < numPlayer; ++player) {
        
        // Perform test on each hand count
        for (handCount = 1; handCount <= maxHandCount; ++handCount) {
    
            // Perform test on each hand position
            for (discardHandPosition = 0; discardHandPosition < handCount; ++discardHandPosition) {
                
                // Perform test on both Trash Flag values
                for (trashFlagSet = 0; trashFlagSet <= 1; ++trashFlagSet) {
#if (NOISY_TEST == 1)
                    printf("Player: %i, Hand Count: %i, Discard Hand Position: %i\n", player + 1, handCount, discardHandPosition);
#endif
                    // clear game state
                    memset(&state, 23, sizeof(struct gameState));
                    
                    // initialize new game
                    seed = rand() % 1000 + 1;
                    assert(initializeGame(numPlayer, gameCards, seed, &state) == 0);
                    
                    // set players hand count
                    state.handCount[player] = handCount;
                    
                    
// BEG Test 1: Only Selected Card Removed From Players Hand
#if (NOISY_TEST == 1)
                    printf("Test 1: Only Selected Card Removed From Players Hand and Game State is not Improperly Altered\n");
#endif
                    // set all cards in hand to Adventurer Cards
                    memcpy(state.hand[player], adventurers, sizeof(int) * handCount);
                    
                    // set card to discard to Gold Card
                    state.hand[player][discardHandPosition] = gold;
                    
                    // save game state prior to discardCard() call
                    preState = state;
                    
                    // call function to test
                    assert(discardCard(discardHandPosition, player, &state, trashFlagSet) == 0);
                    
                    // verify hand has one less card
#if (NOISY_TEST == 1)
                    printf("Expected Hand Count: %i, Actual Hand Count: %i\n", handCount - 1, state.handCount[player]);
#endif
                    assert(state.handCount[player] == handCount - 1);
                    
#if (NOISY_TEST == 1)
                    printf("Expected: Hand Does Not Have Gold Card\n");
#endif
                    // verify hand does not include Gold Card
                    for (i = 0; i < handCount - 1; ++i) {
                        assert (state.hand[player][i] != gold);
                    }
#if (NOISY_TEST == 1)
                    printf("Actual: Hand Does Not Have Gold Card\n");
#endif
// END Test 1: Only Selected Card Removed From Players Hand
    
    
    
                    if (trashFlagSet == 0) {
// BEG Test 2: Selected Card IS Added to Played Pile if Trash Flag NOT Set
#if (NOISY_TEST == 1)
                    printf("Test 2: Selected Card IS Added to Played Pile if Trash Flag NOT Set\n");
#endif
                    // verify card is in played card pile
#if (NOISY_TEST == 1)
                    printf("Expected: Played Card Pile has Gold Card\n");
#endif
                    assert (state.playedCards[state.playedCardCount - 1] == gold);
#if (NOISY_TEST == 1)
                    printf("Actual: Played Card Pile has Gold Card\n");
#endif
// END Test 2: Selected Card IS Added to Played Pile if Trash Flag NOT Set
                    }
    
    
    
                    else {
// BEG Test 3: Selected Card NOT Added to Played Pile if Trash Flag IS Set
#if (NOISY_TEST == 1)
                        printf("Test 3: Selected Card NOT Added to Played Pile if Trash Flag IS Set\n");
#endif
                        // verify card is NOT in played card pile
#if (NOISY_TEST == 1)
                        printf("Expected: Played Card Pile Does NOT have Gold Card\n");
#endif
                        if (state.playedCardCount > 0) {
                            assert (state.playedCards[state.playedCardCount - 1] != gold);
                        }
#if (NOISY_TEST == 1)
                        printf("Actual: Played Card Pile Does NOT have Gold Card\n");
#endif
// END Test 3: Selected Card NOT Added to Played Pile if Trash Flag IS Set
                    }
                    
// BEG Test 4: Game State is Not Altered Other Than Current Player Hand, Hand Count, Played Pile, and Played Pile Count
#if (NOISY_TEST == 1)
                    printf("Test 4: Game State is not Altered Other Than Current Player Hand, Hand Count, Played Pile, and Played Pile Count\n");
#endif
                    gameStateCompareReturnValue = compareGameStates(&preState, &state, MAX_DECK, maxHandCount, numPlayer, player);
#if (NOISY_TEST == 1)
                    printf("Expected: Game State Compare Return Value = 0, Actual: Game State Compare Return Value = %i\n", gameStateCompareReturnValue);
#endif
                    assert(gameStateCompareReturnValue == 0);
// END Test 4: Game State is not Altered Other Than Current Player Hand, Hand Count, Played Pile, and Played Pile Count
                }
            }
        }
    }
    printf ("TESTING OF discardCard() COMPLETED SUCCESSFULLY\n");
    return 0;
}


int compareGameStates(struct gameState* preState, struct gameState* postState, int maxDeck, int maxHand, int maxPlayers, int currentPlayer) {
    // comment out tests if not applicable for test
    // add custom tests below
    
    
    // default state comparisons:
    int i, ii;
    if (preState->numPlayers != postState->numPlayers)
        return 1;
    for (i = 0; i < treasure_map + 1; ++i) {
        if (preState->supplyCount[i] != postState->supplyCount[i])
            return 2;
    }
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
    **/
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
    /**
    for (i = 0; i < maxDeck; ++i) {
        if (preState->playedCards[i] != postState->playedCards[i])
            return 17;
    }
    if (preState->playedCardCount != postState->playedCardCount)
        return 18;
    **/
    
    
    // custom state comparisons:
    for (i = 0; i < maxPlayers; ++i) {
        for (ii = 0; ii < maxHand; ++ii) {
            if ((preState->hand[i][ii] != postState->hand[i][ii]) && i != currentPlayer)
                return 19;
        }
    }
    for (i = 0; i < maxPlayers; ++i) {
        if ((preState->handCount[i] != postState->handCount[i]) && i != currentPlayer)
            return 20;
    }

    return 0;
}
