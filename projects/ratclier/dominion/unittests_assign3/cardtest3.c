//
// *****************************************************************************
// 
// Author:    Erik Ratcliffe
// Date:      October 25, 2015
// Project:   Assignment 3 - Unit Tests
// Filename:  cardtest3.c
// Class:     CS 362 (Fall 2015)
//
// *****************************************************************************
//

#include <stdio.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "unittest_helpers.h"


// Test the treasure map card
//
// NOTE: YOU ADDED A BUG: changed the code that trashes both treasure
// cards to no longer trash them (trashFlag changed from 1 to -1).
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
int testTreasureMapCard(struct gameState *state, int handPos, int currentPlayer)
{
    int origNumTreasureMap = 0;   // orig number of treasure map cards
    int newNumTreasureMap  = 0;   // new number of treasure map cards
    int origTopGolds       = 0;   // orig number of golds at top of deck
    int newTopGolds        = 0;   // new number of golds at top of deck
    int idx;                      // loop iterator
    struct gameState *origState;  // copy of game state

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
            }
        }
        // We did not discard two treasure map cards. Check golds.
        //
        if(newTopGolds == 4 && newTopGolds - origTopGolds == 4)
        {
            printf("treasureMapCard: FAIL did not discard two TMs, four golds added to top of deck\n");
        }
        else 
        {
            printf("treasureMapCard: PASS did not discard two TMs, golds not added to top of deck\n");
        }
    }
    else 
    {
        // We started with one  treasure map card. Discarding it does
        // nothing but discard a card. Check to make sure no golds were
        // added to the top of the deck.
        //
        if(newTopGolds == 4 && newTopGolds - origTopGolds == 4)
        {
            printf("treasureMapCard: FAIL did not discard two TMs, four golds added to top of deck\n");
        }
        else 
        {
            printf("treasureMapCard: PASS did not discard two TMs, golds not added to top of deck\n");
        }
    }

    // Report what, if anything, changed in the game state
    //
    whatChanged(origState, state);
    printf("\n");

    return 0;
}


int main(int argc, char *argv[])
{
    int numPlayers = 2;      // default number of players
    int randomSeed = 100;    // random seed for the game
    int handPos;             // card in play
    int currentPlayer;       // self explanatory
    struct gameState *state; // holds the new game state
    int kingdomCards[10] = {adventurer, gardens, embargo, village, minion, treasure_map, cutpurse, sea_hag, tribute, smithy};

    // New game
    //
    state = newGame();
    initializeGame(numPlayers, kingdomCards, randomSeed, state);

    printf("\n");

    // Test for one treasure map card
    //
    printf(">>> TESTING: one treasure map card...\n");
    currentPlayer = 0;
    gainCard(treasure_map, state, 2, currentPlayer);
    handPos = state->hand[currentPlayer][0];
    testTreasureMapCard(state, handPos, currentPlayer);

    // New game
    //
    state = newGame();
    initializeGame(numPlayers, kingdomCards, randomSeed, state);

    // Test for two treasure map cards
    //
    printf(">>> TESTING: two treasure map cards...\n");
    gainCard(treasure_map, state, 2, currentPlayer);
    gainCard(treasure_map, state, 2, currentPlayer);
    handPos = state->hand[currentPlayer][0];
    testTreasureMapCard(state, handPos, currentPlayer);

    return 0;
}


