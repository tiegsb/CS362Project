// Author: Michael Walker
// Assignment 3: cardtest4.c
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
    int gameCards[10] = {sea_hag, council_room, feast, gardens, cutpurse, remodel, adventurer, smithy, baron, great_hall};
    struct gameState state;
    struct gameState preState;
    int gameStateCompareReturnValue;
    int tracker;
    int errors = 0;
    
    // card function parameters
    int choice1 = 0;
    int choice2 = 0;
    int choice3 = 0;
    int bonus = 0;
    int handPos;
    
    // loop variables
    int i, player, handCount;
    
    // arrays of all mines and adventurers
    int mines[MAX_HAND];
    int golds[MAX_HAND];
    for (i = 0; i < MAX_HAND; i++) {
        mines[i] = mine;
        golds[i] = gold;
    }
    
    printf ("TESTING Village Card:\n");
    
    // Perform each test on each player
    for (player = 0; player < numPlayer; ++player) {
        
        // Perform test on each hand count
        for (handCount = 1; handCount <= maxHandCount; ++handCount) {
            
#if (NOISY_TEST == 1)
            printf("Player: %i, Hand Count: %i\n", player + 1, handCount);
#endif
            // get index of Village card
            handPos = handCount - 1;
            
            // clear game state
            memset(&state, 23, sizeof(struct gameState));
            
            // initialize new game
            seed = rand() % 1000 + 1;
            assert(initializeGame(numPlayer, gameCards, seed, &state) == 0);
            
            // set current player
            state.whoseTurn = player;
            
            // set all cards in hand to Mine Cards
            memcpy(state.hand[player], mines, sizeof(int) * handCount);
            
            // set last card in current player's hand to Village Card
            state.hand[player][handPos] = village;
            
            // set players hand count
            state.handCount[player] = handCount;
            
            // save game state prior to discardCard() call
            preState = state;
            
            // call function to test
            assert(cardEffect(state.hand[player][handPos], choice1, choice2, choice3, &state, handPos, &bonus) == 0);
            
            
            
            
// BEG Test 1: Village is Discarded From Hand to Played Pile
#if (NOISY_TEST == 1)
            printf("Test 1: Village is Discarded From Hand to Played Pile\n");
#endif
            
#if (NOISY_TEST == 1)
            printf("Expected: Village Card Not In Hand\n");
#endif
            tracker = 0;
            for (i = 0; i < state.handCount[player]; ++i) {
                if (state.hand[player][i] == village)
                    tracker++;
            }
            
            if (tracker != 0) {
                printf("ERROR: Village Card Still In Hand\n");
                errors++;
            }
            
#if (NOISY_TEST == 1)
            if (tracker == 0)
                printf("Actual: Village Card Not In Hand\n");
#endif
            
            
#if (NOISY_TEST == 1)
            printf("Expected: Village Card in Played Pile\n");
#endif
            tracker = 0;
            for (i = 0; i < state.playedCardCount; ++i) {
                if (state.playedCards[i] == village)
                    tracker++;
            }
            
            if (tracker == 0) {
                printf("ERROR: Village Card Not In Played Pile\n");
                errors++;
            }
            
#if (NOISY_TEST == 1)
            if (tracker != 0)
                printf("Actual: Village Card in Played Pile\n");
#endif
// END Test 1: Village is Discarded From Hand to Played Pile
            

// BEG Test 2: One Card is Drawn From Deck
#if (NOISY_TEST == 1)
            printf("Test 2: One Card is Drawn From Deck\n");
#endif
            
#if (NOISY_TEST == 1)
            printf("Expected Deck Count: %i, Actual Deck Count: %i\n", preState.deckCount[player] - 1, state.deckCount[player]);
#endif
            
            if (preState.deckCount[player] - 1 > state.deckCount[player]) {
                printf("ERROR: More Than One Cards Drawn\n");
                errors++;
            }
            else if (preState.deckCount[player] - 1 < state.deckCount[player]) {
                printf("ERROR: Less Than One Cards Drawn\n");
                errors++;
            }
// END Test 2: One Card is Drawn From Deck
            
            
// BEG Test 3: One Card is Addded to Hand
#if (NOISY_TEST == 1)
            printf("Test 3: One Card is Added to Hand\n");
#endif
            tracker = 0;
            for (i = 0; i < state.handCount[player]; ++i) {
                if (state.hand[player][i] != village)
                    tracker++;
            }
            
#if (NOISY_TEST == 1)
            printf("Expected Hand Count: %i, Actual Hand Count: %i\n", preState.handCount[player], tracker);
#endif
            if (preState.handCount[player] > tracker) {
                printf("ERROR: Less Than One Card Added to Hand\n");
                errors++;
            }
            else if (preState.handCount[player] < tracker) {
                printf("ERROR: More Than One Card Added to Hand\n");
                errors++;
            }
// END Test 3: One Card is Addded to Hand
            
            
// BEG Test 4: Current Player's Actions Are Increased By Two
#if (NOISY_TEST == 1)
            printf("Test 4: Current Player's Actions Are Increased By Two\n");
#endif
            
#if (NOISY_TEST == 1)
            printf("Expected Num Actions: %i, Actual Num Actions: %i\n", preState.numActions + 2, state.numActions);
#endif
            if (preState.numActions + 2 != state.numActions) {
                printf("ERROR: Two Actions NOT Added To Current Player\n");
                errors++;
            }
// END Test 4: Current Player's Actions Are Increased By Two
            
            
            
// BEG Test 5: If Deck is Empty When Village Card is Played, Discard Pile is Added to Deck
#if (NOISY_TEST == 1)
            printf("Test 5: If Deck is Empty When Village Card is Played, Discard Pile is Added to Deck\n");
#endif
            // set deck count to zero
            state.deckCount[player] = 0;
            
            // set all cards in hand to Mine Cards
            memcpy(state.hand[player], mines, sizeof(int) * state.handCount[player]);
            
            // add village card to hand
            state.handCount[player]++;
            state.hand[player][handCount - 1] = village;
            
            // set discard pile to be 1 gold card
            state.discardCount[player] = 1;
            memcpy(state.discard[player], golds, sizeof(int) * state.discardCount[player]);
            
            // call function to test
            assert(cardEffect(state.hand[player][handPos], choice1, choice2, choice3, &state, state.handCount[player] - 1, &bonus) == 0);
            
            // scan hand and tally number of treasure cards
            tracker = 0;
            for (i = 0; i < state.handCount[player]; ++i) {
                if (state.hand[player][i] == gold) {
                    tracker++;
                }
            }
            
#if (NOISY_TEST == 1)
            printf("Expected Additional Cards In Hand: %i, Actual Additional Cards In Hand: %i\n", 1, tracker);
#endif
            assert(tracker == 1);
// END Test 5: If Deck is Empty When Village Card is Played, Discard Pile is Added to Deck
            
            
// BEG Test 6: Game State Is Not Altered Other Than Current Player's Hand & Count, Deck & Count, Actions, and Played Pile
#if (NOISY_TEST == 1)
            printf("Test 6: Game State Is Not Altered Other Than Current Player's Hand & Count, Deck & Count, Actions, and Played Pile\n");
#endif
            gameStateCompareReturnValue = compareGameStates(&preState, &state, MAX_DECK, maxHandCount, numPlayer, player);
            
#if (NOISY_TEST == 1)
            printf("Expected: Game State Compare Return Value = 0, Actual: Game State Compare Return Value = %i\n", gameStateCompareReturnValue);
#endif
            assert(gameStateCompareReturnValue == 0);
// END Test 6: Game State Is Not Altered Other Than Current Player's Hand & Count, Deck & Count, Actions, and Played Pile
            
        }
    }
    if (errors == 0)
        printf ("TESTING OF Village Card COMPLETED SUCCESSFULLY\n");
    else
        printf ("TESTING OF Village Card COMPLETED WITH ERRORS\n");
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
    
    return 0;
}