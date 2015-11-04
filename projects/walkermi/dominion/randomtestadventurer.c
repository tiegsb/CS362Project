// Author: Michael Walker
// Assignment 4: randomtestadventurer.c
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
    int maxHandCount = 100;
    int gameCards[10] = {sea_hag, council_room, feast, gardens, cutpurse, remodel, smithy, village, baron, great_hall};
    struct gameState state;
    struct gameState preState;
    int gameStateCompareReturnValue;
    int tracker;
    int errors = 0;
    int cardCounter;
    
    // card function parameters
    int choice1 = 0;
    int choice2 = 0;
    int choice3 = 0;
    int bonus = 0;
    int handPos;
    
    // loop variables
    int i, ii, player, handCount;
    int iterations = 1000;
    
    // arrays of all mines and adventurers
    int mines[MAX_HAND];
    int adventurers[MAX_HAND];
    int golds[MAX_HAND];
    for (i = 0; i < MAX_HAND; i++) {
        mines[i] = mine;
        adventurers[i] = adventurer;
        golds[i] = gold;
    }
    
    printf ("RANDOM TESTING Adventurer Card:\n");
    
    // Perform each test on each player
    for (ii = 0; ii < iterations; ++ii) {
            
        // choose random handcount
        handCount = rand() % maxHandCount + 1;
        
        // choose random player
        player = rand() % numPlayer;
        
        // choose random hand position for adventure card
        handPos = rand() % handCount;
    
        // clear game state
        memset(&state, 23, sizeof(struct gameState));
        
        // initialize new game with random seed
        seed = rand() % 1000 + 1;
        assert(initializeGame(numPlayer, gameCards, seed, &state) == 0);
        
#if (NOISY_TEST == 1)
        printf("\nITERATION: %i, Player: %i, Hand Count: %i, Hand Pos: %i, Game Seed: %i\n", ii + 1, player + 1, handCount, handPos, seed);
#endif
        
        // set current player
        state.whoseTurn = player;
        
        // set all cards in hand to Mine Cards
        memcpy(state.hand[player], mines, sizeof(int) * handCount);
        
        // set last card in current player's hand to Adventurer Card
        state.hand[player][handPos] = adventurer;
        
        // set players hand count
        state.handCount[player] = handCount;
        
        // save game state prior to discardCard() call
        preState = state;
        
        // call function to test
        assert(cardEffect(state.hand[player][handPos], choice1, choice2, choice3, &state, handPos, &bonus) == 0);
        
        
        
// BEG Test 1: Adventurer Card is Discarded From Hand to Played Pile
#if (NOISY_TEST == 1)
        printf("Test 1: Adventurer Card is Discarded From Hand to Played Pile\n");
#endif
#if (NOISY_TEST == 1)
        printf("Expected: Adventurer Card Not In Hand\n");
#endif
        tracker = 0;
        for (i = 0; i < state.handCount[player]; ++i) {
            if (state.hand[player][i] == adventurer)
                tracker++;
        }
        
        if (tracker != 0) {
            printf("ERROR: Adventurer Card Still In Hand\n");
            errors++;
        }
        
#if (NOISY_TEST == 1)
        if (tracker == 0)
            printf("Actual: Adventurer Card Not In Hand\n");
#endif
        
        
#if (NOISY_TEST == 1)
        printf("Expected: Adventurer Card in Played Pile\n");
#endif
        tracker = 0;
        for (i = 0; i < state.playedCardCount; ++i) {
            if (state.playedCards[i] == adventurer)
                tracker++;
        }
        
        if (tracker == 0) {
            printf("ERROR: Adventurer Card Not In Played Pile\n");
            errors++;
        }
        
#if (NOISY_TEST == 1)
        if (tracker != 0)
            printf("Actual: Adventurer Card in Played Pile\n");
#endif
// END Test 1: Adventurer Card is Discarded From Hand to Played Pile
        
        
        
// BEG Test 2: Cards are Drawn From Deck and Non-Treasure Cards Are Discarded in Discard Pile
#if (NOISY_TEST == 1)
        printf("Test 2: Cards are Drawn From Deck and Non-Treasure Cards Are Discarded in Discard Pile\n");
#endif
        cardCounter = 0;
        for (i = 0; i < state.discardCount[player]; ++i) {
            if (state.discard[player][i] != adventurer) {
                cardCounter++;
            }
        }
        
#if (NOISY_TEST == 1)
        printf("Expected Deck Count: %i, Actual Deck Count: %i\n", preState.deckCount[player] - (cardCounter + 2), state.deckCount[player]);
#endif
        assert(preState.deckCount[player] - (cardCounter + 2) == state.deckCount[player]);
        
#if (NOISY_TEST == 1)
        printf("Expected Drawn Non-Treasure Cards In Discard: %i, Actual Drawn Non-Treasure Cards In Discard: %i\n", preState.deckCount[player] - state.deckCount[player] - 2, cardCounter);
#endif
        assert(preState.deckCount[player] - state.deckCount[player] - 2 == cardCounter);
// END Test 2: Cards are Drawn From Deck and Non-Treasure Cards Are Discarded in Discard Pile
        
        
        
        
// BEG Test 3: Two Treasure Cards added to Hand
#if (NOISY_TEST == 1)
        printf("Test 3: Two Treasure Cards added to Hand\n");
#endif
        tracker = 0;
        for (i = 0; i < state.handCount[player]; ++i) {
            if (state.hand[player][i] == copper || state.hand[player][i] == silver || state.hand[player][i] == gold) {
                tracker++;
            }
        }
        
#if (NOISY_TEST == 1)
        printf("Expected Treasure Card Count in Hand: %i, Actual Treasure Card Count in Hand: %i\n", 2, tracker);
#endif
        assert(tracker == 2);
// END Test 3: Two Treasure Cards added to Hand
        
        
        
        
// BEG Test 4: Hand Count Increases By One (Plus Two Treasure & Minus One Adventurer)
#if (NOISY_TEST == 1)
        printf("Test 4: Hand Count Increases By One (Plus Two Treasure & Minus One Adventurer\n");
#endif
        
#if (NOISY_TEST == 1)
        printf("Expected Hand Count: %i, Actual Hand Count: %i\n", preState.handCount[player] + 1, state.handCount[player]);
#endif
        if (preState.handCount[player] + 1 != state.handCount[player]) {
            errors++;
        }
        
#if (NOISY_TEST == 1)
        if (preState.handCount[player] + 1 != state.handCount[player]) {
            printf("ERROR: Hand Count Not Incremented By One\n");
        }
#endif
// END Test 4: Hand Count Increases By One (Plus Two Treasure & Minus One Adventurer)
        
        
        
// BEG Test 5: If All Cards Are Drawn From Deck Before Adventure Card Resolves, Discard Pile is Added to Deck
#if (NOISY_TEST == 1)
        printf("Test 6: If All Cards Are Drawn From Deck Before Adventure Card Resolves, Discard Pile is Added to Deck\n");
#endif
        // set all cards in deck to Mine Cards
        memcpy(state.deck[player], mines, sizeof(int) * state.deckCount[player]);
        
        // set discard pile to be 2 gold cards
        state.discardCount[player] = 2;
        memcpy(state.discard[player], golds, sizeof(int) * state.discardCount[player]);
        
        // set all cards in hand to Mine Cards
        memcpy(state.hand[player], mines, sizeof(int) * state.handCount[player]);
        
        // add adventurer card to hand
        state.handCount[player]++;
        state.hand[player][state.handCount[player] - 1] = adventurer;
        
        // call adventurer card function
        assert(cardEffect(state.hand[player][state.handCount[player] - 1], choice1, choice2, choice3, &state, handPos, &bonus) == 0);
        
        // scan hand and tally number of treasure cards
        tracker = 0;
        for (i = 0; i < state.handCount[player]; ++i) {
            if (state.hand[player][i] == copper || state.hand[player][i] == silver || state.hand[player][i] == gold) {
                tracker++;
            }
        }
        
#if (NOISY_TEST == 1)
        printf("Expected Treasure Card Count In Hand: %i, Actual Treasure Card Count In Hand: %i\n", 2, tracker);
#endif
        assert(tracker == 2);
// END Test 5: If All Cards Are Drawn From Deck Before Adventure Card Resolves, Discard Pile is Added to Deck
        
        
        
// BEG Test 6: Game State is not Altered Other Than Current Player's Hand & Count, Discard Pile & Count, Deck & Count, and PLayed Pile
#if (NOISY_TEST == 1)
        printf("Test 7: Game State is not Altered Other Than Current Player's Hand & Count, Discard Pile & Count, Deck & Count, and PLayed Pile\n");
#endif
        gameStateCompareReturnValue = compareGameStates(&preState, &state, MAX_DECK, maxHandCount, numPlayer, player);
        
#if (NOISY_TEST == 1)
        printf("Expected: Game State Compare Return Value = 0, Actual: Game State Compare Return Value = %i\n", gameStateCompareReturnValue);
#endif
        assert(gameStateCompareReturnValue == 0);
// END Test 6: Game State is not Altered Other Than Current Player's Hand & Count, Discard Pile & Count, Deck & Count, and PLayed Pile
        
    }
    if (errors == 0)
        printf ("RANDOM TESTING OF Adventurer Card COMPLETED SUCCESSFULLY\n");
    else
        printf ("RANDOM TESTING OF Adventurer Card COMPLETED WITH ERRORS\n");
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
            if ((preState->hand[i][ii] != postState->hand[i][ii]) && (currentPlayer != i))
                return 10;
        }
    }
    for (i = 0; i < maxPlayers; ++i) {
        if ((preState->handCount[i] != postState->handCount[i]) && (currentPlayer != i))
            return 11;
    }
    for (i = 0; i < maxPlayers; ++i) {
        for (ii = 0; ii < maxDeck; ++ii) {
            if ((preState->deck[i][ii] != postState->deck[i][ii]) && (currentPlayer != i))
                return 13;
        }
    }
    for (i = 0; i < maxPlayers; ++i) {
        if ((preState->deckCount[i] != postState->deckCount[i]) && (currentPlayer != i))
            return 14;
    }
    for (i = 0; i < maxPlayers; ++i) {
        for (ii = 0; ii < maxDeck; ++ii) {
            if ((preState->discard[i][ii] != postState->discard[i][ii]) && (currentPlayer != i))
                return 15;
        }
    }
    for (i = 0; i < maxPlayers; ++i) {
        if ((preState->discardCount[i] != postState->discardCount[i]) && (currentPlayer != i))
            return 16;
    }
    
    return 0;
}