//
// *****************************************************************************
// 
// Author:    Erik Ratcliffe
// Date:      October 25, 2015
// Project:   Assignment 3 - Unit Tests
// Filename:  unittest_helpers.c
// Class:     CS 362 (Fall 2015)
//
// *****************************************************************************
//

#include <stdio.h>
#include "dominion.h"


// Walk through the new game state and see what changed compared to
// original game state
//
int whatChanged(struct gameState *origState, struct gameState *state)
{
    int idx1, idx2, idx3;  // loop iterators

    printf("\n>>> STATE CHANGES: for all players:\n");

    if(origState->numPlayers != state->numPlayers)
        printf("numPlayers changed! Orig: %d, New: %d\n", origState->numPlayers, state->numPlayers);
    if(origState->outpostPlayed != state->outpostPlayed)
        printf("outpostPlayed changed! Orig: %d, New: %d\n", origState->outpostPlayed, state->outpostPlayed);
    if(origState->outpostTurn != state->outpostTurn)
        printf("outpostTurn changed! Orig: %d, New: %d\n", origState->outpostTurn, state->outpostTurn);
    if(origState->whoseTurn != state->whoseTurn)
        printf("whoseTurn changed! Orig: %d, New: %d\n", origState->whoseTurn, state->whoseTurn);
    if(origState->phase != state->phase)
        printf("phase changed! Orig: %d, New: %d\n", origState->phase, state->phase);
    if(origState->numActions != state->numActions)
        printf("numActions changed! Orig: %d, New: %d\n", origState->numActions, state->numActions);
    if(origState->coins != state->coins)
        printf("coins changed! Orig: %d, New: %d\n", origState->coins, state->coins);
    if(origState->numBuys != state->numBuys)
        printf("numBuys changed! Orig: %d, New: %d\n", origState->numBuys, state->numBuys);
    if(origState->playedCardCount != state->playedCardCount)
        printf("playedCardCount changed! Orig: %d, New: %d\n", origState->playedCardCount, state->playedCardCount);

    for(idx1 = 0; idx1 < MAX_DECK; idx1++)
    {
        if(origState->playedCards[idx1] != state->playedCards[idx1])
            printf("playedCards[%d] changed! Orig: %d, New: %d\n", idx1, origState->playedCards[idx1], state->playedCards[idx1]);
    }

    for(idx1 = 0; idx1 <= (treasure_map); idx1++)
    {
        if(origState->supplyCount[idx1] != state->supplyCount[idx1])
            printf("supplyCount[%d] changed! Orig: %d, New: %d\n", idx1, origState->supplyCount[idx1], state->supplyCount[idx1]);
        if(origState->embargoTokens[idx1] != state->embargoTokens[idx1])
            printf("embargoTokens[%d] changed! Orig: %d, New: %d\n", idx1, origState->embargoTokens[idx1], state->embargoTokens[idx1]);
    }

    for(idx3 = 0; idx3 < state->numPlayers; idx3++)
    {
        printf("\n>>> STATE CHANGES: specific to player %d:\n", idx3);
        if(origState->handCount[idx3] != state->handCount[idx3])
            printf("handCount[%d] changed! Orig: %d, New: %d\n", idx3, origState->handCount[idx3], state->handCount[idx3]);
        if(origState->deckCount[idx3] != state->deckCount[idx3])
            printf("deckCount[%d] changed! Orig: %d, New: %d\n", idx3, origState->deckCount[idx3], state->deckCount[idx3]);
        if(origState->discardCount[idx3] != state->discardCount[idx3])
            printf("discardCount[%d] changed! Orig: %d, New: %d\n", idx3, origState->discardCount[idx3], state->discardCount[idx3]);

        for(idx2 = 0; idx2 < MAX_HAND; idx2++)
        {
            if(origState->hand[idx3][idx2] != state->hand[idx3][idx2])
                printf("hand[%d][%d] changed! Orig: %d, New: %d\n", idx3, idx2, origState->hand[idx3][idx2], state->hand[idx3][idx2]);
        }

        for(idx2 = 0; idx2 < MAX_DECK; idx2++)
        {
            if(origState->deck[idx3][idx2] != state->deck[idx3][idx2])
                printf("deck[%d][%d] changed! Orig: %d, New: %d\n", idx3, idx2, origState->deck[idx3][idx2], state->deck[idx3][idx2]);
            if(origState->discard[idx3][idx2] != state->discard[idx3][idx2])
                printf("discard[%d][%d] changed! Orig: %d, New: %d\n", idx3, idx2, origState->discard[idx3][idx2], state->discard[idx3][idx2]);
        }
    }

    return 0;
}


// Make a deep copy of the game state for later comparison
//
struct gameState *copyState(struct gameState *state)
{
    int idx1, idx2;               // loop index vars
    struct gameState *origState;  // copy of game state

    origState = newGame();        // set up the new game state struct

    // Make a copy of the game state
    //
    origState->numPlayers      = state->numPlayers;
    origState->outpostPlayed   = state->outpostPlayed;
    origState->outpostTurn     = state->outpostTurn;
    origState->whoseTurn       = state->whoseTurn;
    origState->phase           = state->phase;
    origState->numActions      = state->numActions;
    origState->coins           = state->coins;
    origState->numBuys         = state->numBuys;
    origState->playedCardCount = state->playedCardCount;

    for(idx1 = 0; idx1 < MAX_PLAYERS; idx1++)
    {
        origState->handCount[idx1]    = state->handCount[idx1];
        origState->deckCount[idx1]    = state->deckCount[idx1];
        origState->discardCount[idx1] = state->discardCount[idx1];

        for(idx2 = 0; idx2 < MAX_HAND; idx2++)
        {
            origState->hand[idx1][idx2] = state->hand[idx1][idx2];
        }

        for(idx2 = 0; idx2 < MAX_DECK; idx2++)
        {
            origState->deck[idx1][idx2]    = state->deck[idx1][idx2];
            origState->discard[idx1][idx2] = state->discard[idx1][idx2];
        }
    }

    for(idx1 = 0; idx1 < MAX_DECK; idx1++)
    {
        origState->playedCards[idx1] = state->playedCards[idx1];
    }

    for(idx1 = 0; idx1 < (treasure_map+1); idx1++)
    {
        origState->supplyCount[idx1]   = state->supplyCount[idx1];
        origState->embargoTokens[idx1] = state->embargoTokens[idx1];
    }

    return origState;
}


