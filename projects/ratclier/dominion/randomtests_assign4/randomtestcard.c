//
// *****************************************************************************
// 
// Author:    Erik Ratcliffe
// Date:      November 8, 2015
// Project:   Assignment 4 - Random Tests
// Filename:  randomtestcard.c
// Class:     CS 362 (Fall 2015)
//
// *****************************************************************************
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "unittest_helpers.h"
#include "randomtest_helpers.h"

#define testRuns 30000

// Test the treasure map card
//
// NOTE: YOU ADDED A BUG: changed the code that trashes both treasure
// map cards to no longer trash them (trashFlag changed from 1 to -1).
//
// From the Dominion Card Game Wiki (dominioncg.wikia.com):
//
// Trash this and another copy of treasure map from your hand. If you do
// trash two treasure maps, gain 4 gold cards, putting them on top of your
// deck.
//
// If you play this and you do not have another treasure map card in your
// hand, you gain nothing. Two cards are required to get gold.
//
// If there aren't enough gold cards left, you gain what you can.
//
int testTreasureMapCard(struct gameState *state, int handPos)
{
    struct gameState *origState;  // copy of game state
    int origNumTreasureMap = 0;   // orig number of treasure map cards
    int newNumTreasureMap  = 0;   // new number of treasure map cards
    int origTopGolds       = 0;   // orig number of golds at top of deck
    int newTopGolds        = 0;   // new number of golds at top of deck
    int idx                = 0;   // loop iterator
    int passFlag           = 1;   // signals whether or not a test passed (default: true)
    int currentPlayer = state->whoseTurn;

    // Make a copy of the original game state
    //
    origState = copyState(state);

    // Run the treasure map card function
    //
    treasureMapCard(state, handPos);

    // Determine original number of treasure map cards in hand
    //
    for(idx = 0; idx < origState->handCount[currentPlayer]; idx++)
    {
        if(origState->hand[currentPlayer][idx] == treasure_map)
            origNumTreasureMap++;
    }

    // Determine new number of treasure map cards in hand
    //
    for(idx = 0; idx < state->handCount[currentPlayer]; idx++)
    {
        if(state->hand[currentPlayer][idx] == treasure_map)
            newNumTreasureMap++;
    }

    // See how many cards on top of the original deck were golds (if any)
    //
    for(idx = origState->deckCount[currentPlayer]-1; idx > 0 && idx > *(origState->deck[currentPlayer])-5; idx--)
    {
        if(origState->deck[currentPlayer][idx] == gold)
            origTopGolds++;
    }

    // See how many cards on top of the new deck are golds (if any)
    //
    for(idx = state->deckCount[currentPlayer]-1; idx > 0 && idx > *(state->deck[currentPlayer])-5; idx--)
    {
        if(state->deck[currentPlayer][idx] == gold)
            newTopGolds++;
    }

    // See if golds were added correctly
    //
    if(origNumTreasureMap >= 2)
    {
        // We started with two treasure map cards. See how many were
        // discarded.
        //
        if(origNumTreasureMap - newNumTreasureMap == 2)
        {
            // We discarded two treasure map cards. Check golds.
            //
            if(newTopGolds == 4 && newTopGolds - origTopGolds == 4)
            {
                printf("treasureMapCard: PASS two TMs discarded, four golds added to top of deck\n");
            }
            else 
            {
                printf("treasureMapCard: FAIL two TMs discarded, four golds not added to top of deck\n");
                passFlag = 0;
            }
        }
        // We did not discard two treasure map cards. Check golds.
        //
        if(newTopGolds == 4 && newTopGolds - origTopGolds == 4)
        {
            printf("treasureMapCard: FAIL did not discard two TMs, four golds added to top of deck\n");
            passFlag = 0;
        }
        else 
        {
            printf("treasureMapCard: PASS did not discard two TMs, golds not added to top of deck\n");
        }
    }
    else 
    {
        // We started with one treasure map card. Discarding it does
        // nothing but discard a card. Check to make sure no golds were
        // added to the top of the deck.
        //
        if(newTopGolds == 4 && newTopGolds - origTopGolds == 4)
        {
            printf("treasureMapCard: FAIL did not discard two TMs, four golds added to top of deck\n");
            passFlag = 0;
        }
        else 
        {
            printf("treasureMapCard: PASS did not discard two TMs, golds not added to top of deck\n");
        }
    }

    // Report what, if anything, changed in the game state
    //
    if(passFlag == 0)
    {
        whatChanged(origState, state);
    }
    printf("\n");

    // Free up origState pointer
    //
    free(origState);

    return 0;
}


int main(int argc, char *argv[])
{
    int numPlayers       = 2;      // default number of players
    int randomSeed       = 1000;   // random seed for the game
    int handPos;                   // card in play
    int idx              = 0;      // loop iterator
    int idx2             = 0;      // loop iterator, misc value holder
    int testRunNum       = 0;      // which test run we're on
    int card             = 0;      // for card assignment loops
    int deckSize         = 0;      // holds random deck sizes
    int kingdomCards[10] = {adventurer, gardens, embargo, village, minion, treasure_map, cutpurse, sea_hag, tribute, smithy};

    // Seed the randomizer
    //
    srand(time(NULL));
    
    for(testRunNum = 1; testRunNum <= testRuns; testRunNum++)
    {
        //
        // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
        // >>> TEST 0: no adjustments, just a straight run-through...
        // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
        //

        // New game
        //
        struct gameState *state;    // holds the updated game state
        state = newGame();
        initializeGame(numPlayers, kingdomCards, randomSeed, state);

        printf("\n");

        for(idx = 0; idx < numPlayers; idx++)
        {
            printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
            printf(">>> TEST 0 RUN %d: no adjustments, player %d, just a straight run-through...\n", testRunNum, idx);
            printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n");

            // Set the current player
            //
            state->whoseTurn = idx;

            handPos = state->hand[idx][0];
            testTreasureMapCard(state, handPos);
        }

        //
        // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
        // >>> TEST 1: random deck size, no treasure map cards...
        // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
        //

        // New game
        //
        free(state);
        state = newGame();
        initializeGame(numPlayers, kingdomCards, randomSeed, state);

        // Set up a random deck size from normal (10, which needs to be
        // changed to 9 because it's 0 indexed) and MAX_DECK (which also
        // needs to be reduced by 1)
        //
        deckSize = randomByRange(9, MAX_DECK - 1);

        printf("\n");

        for(idx = 0; idx < numPlayers; idx++)
        {
            printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
            printf(">>> TEST 1 RUN %d: deck size %d, player %d, no treasure map cards...\n", testRunNum, deckSize, idx);
            printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n");

            // Set the current player
            //
            state->whoseTurn = idx;

            // Set the new deck size
            //
            state->deckCount[idx] = deckSize;

            // Fill the deck with random non-treasure-map cards. 27
            // cards total, so get a number from 0 to 26
            //
            for(idx2 = 0; idx2 < state->deckCount[idx2]; idx2++)
            {
                while(card == treasure_map)
                {
                    card = randomByRange(0, treasure_map);
                }
                state->deck[idx][idx2] = card;
            }

            handPos = state->hand[idx][0];
            testTreasureMapCard(state, handPos);
        }

        //
        // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
        // >>> TEST 2: random deck size, only one treasure map card...
        // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
        //

        // New game
        //
        free(state);
        state = newGame();
        initializeGame(numPlayers, kingdomCards, randomSeed, state);

        // Set up a random deck size from normal (10, which needs to be
        // changed to 9 because it's 0 indexed) and MAX_DECK (which also
        // needs to be reduced by 1)
        //
        deckSize = randomByRange(9, MAX_DECK - 1);

        for(idx = 0; idx < numPlayers; idx++)
        {
            printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
            printf(">>> TEST 2 RUN %d: deck size %d, player %d, one treasure card...\n", testRunNum, deckSize, idx);
            printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n");

            // Set the current player
            //
            state->whoseTurn = idx;

            // Set the new deck size
            //
            state->deckCount[idx] = deckSize;

            // Fill the deck with random non-treasure-map cards. 27
            // cards total, so get a number from 0 to 26
            //
            for(idx2 = 0; idx2 < state->deckCount[idx2]; idx2++)
            {
                while(card == treasure_map)
                {
                    card = randomByRange(0, treasure_map);
                }
                state->deck[idx][idx2] = card;
            }

            // Slip in one treasure map card 
            //
            gainCard(treasure_map, state, 2, idx);

            handPos = state->hand[idx][0];
            testTreasureMapCard(state, handPos);
        }

        //
        // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
        // >>> TEST 3: random tiny deck size, two treasure map cards....
        // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
        //
        
        // New game
        //
        free(state);
        state = newGame();
        initializeGame(numPlayers, kingdomCards, randomSeed, state);

        deckSize = randomByRange(0, 9);

        for(idx = 0; idx < numPlayers; idx++)
        {
            printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
            printf(">>> TEST 3 RUN %d: tiny deck size %d, player %d, two treasure map cards...\n", testRunNum, deckSize, idx);
            printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n");

            // Set the current player
            //
            state->whoseTurn = idx;

            // Set the new deck size
            //
            state->deckCount[idx] = deckSize;

            // Fill the deck with random non-treasure-map cards. 27
            // cards total, so get a number from 0 to 26
            //
            for(idx2 = 0; idx2 < state->deckCount[idx2]; idx2++)
            {
                while(card == treasure_map)
                {
                    card = randomByRange(0, treasure_map - 1);
                }
                state->deck[idx][idx2] = card;
            }

            // Slip in one treasure map card 
            //
            gainCard(treasure_map, state, 2, idx);
            gainCard(treasure_map, state, 2, idx);

            handPos = state->hand[idx][0];
            testTreasureMapCard(state, handPos);
        }

        // We still have a state pointer to free up...
        //
        free(state);
    }

    return 0;
}


