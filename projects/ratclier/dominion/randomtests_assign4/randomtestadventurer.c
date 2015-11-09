//
// *****************************************************************************
// 
// Author:    Erik Ratcliffe
// Date:      November 8, 2015
// Project:   Assignment 4 - Random Tests
// Filename:  randomtestadventurer.c
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

// Test the adventurer card
//
// NOTE: YOU ADDED A BUG: changed cardDrawn assignment to not place drawn
// card at the end of the hand.
//
// The Adventurer card draws cards from the player's deck until two
// Treasure (coin) cards are drawn. If the drawn card is not a Treasure
// card, it is added to a temporary hand; if it is a Treasure card, it is
// added to the player's hand. At the end of the process, whatever is in
// the temporary hand (which contains no Treasure cards) is discarded.
// 
// If the player's deck is empty when the Adventurer card is played, the
// player's discard pile is shuffled and becomes the player's deck. (This
// seems pointless as the drawCard() function does this already.)
//
// From the Dominion Card Game Wiki (dominioncg.wikia.com):
//
// Reveal cards from your deck until you reveal 2 treasure cards. Put
// those treasure cards in your hand and discard the other revealed cards.
//
// If you have to shuffle in the middle, shuffle. Don't shuffle in the
// revealed cards as these cards do not go to the discard pile until you
// have finished revealing cards. If you run out of cards after shuffling
// and still only have one treasure, you get just that one treasure.
//
int testAdventurerCard(struct gameState *state)
{
    struct gameState *origState;  // copy of game state
    int lastCard;                 // the last card in the hand
    int idx;                      // loop iterator
    int diffDeckCount;            // difference between orig and new deck count
    int diffDiscardCount;         // difference between orig and new discard count
    int passFlag = 1;             // signals whether or not a test passed (default: true)
    int currentPlayer = state->whoseTurn;

    // Make a copy of the original game state
    //
    origState = copyState(state);

    // Run the adventurer card function
    //
    adventurerCard(state);

    // See if handCount increased by two cards
    //
    if(state->handCount[currentPlayer] == origState->handCount[currentPlayer]+2)
    {
        printf("adventurerCard: PASS two new cards added to hand\n");

        // See if last two cards in hand are treasure cards (enum 4-6)
        //
        lastCard = state->handCount[currentPlayer];
        for(idx = 1; idx <=2; idx++)
        {
            if((state->hand[currentPlayer][lastCard-idx] <= copper) && (state->hand[currentPlayer][lastCard-idx] >= gold)) 
            {
                passFlag = 0;
            }
        }
        if(passFlag == 1)
        {
            printf("adventurerCard: PASS last two cards in hand are treasure cards\n");
        }
        else 
        {
            printf("adventurerCard: FAIL at least one of the last two cards in hand is not a treasure card\n");
        }
    }
    else 
    {
        printf("adventurerCard: FAIL two new cards not added to hand\n");
        passFlag = 0;
    }

    // See if the number of discarded cards is correct
    //
    diffDeckCount = origState->deckCount[currentPlayer] - state->deckCount[currentPlayer];
    diffDiscardCount = origState->discardCount[currentPlayer] - state->discardCount[currentPlayer];
    if(diffDiscardCount + 2 == diffDeckCount)
    {
        printf("adventurerCard: PASS correct number of cards discarded\n");
    }
    else 
    {
        printf("adventurerCard: FAIL incorrect number of cards discarded\n");
        passFlag = 0;
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
    int numPlayers        = 2;     // number of players
    int randomSeed        = 1000;  // random seed for the game
    int idx               = 0;     // loop iterator
    int idx2              = 0;     // loop iterator, misc value holder
    int card              = 0;     // for card assignment loops
    int treasureCardCount = 0;     // holds running count of treasure cards
    int deckSize          = 0;     // holds random size of deck
    int testRunNum        = 0;     // which test run we're on
    int kingdomCards[10]  = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};

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

            testAdventurerCard(state);
        }

        //
        // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
        // >>> TEST 1: random deck size, no treasure cards...
        // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
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
            printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
            printf(">>> TEST 1 RUN %d: deck size %d, player %d, no treasure cards...\n", testRunNum, deckSize, idx);
            printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n");

            // Set the current player
            //
            state->whoseTurn = idx;

            // Set the new deck size
            //
            state->deckCount[idx] = deckSize;

            // Fill the deck with random non-treasure cards. 27
            // cards total, so get a number from 0 to 26
            //
            for(idx2 = 0; idx2 < state->deckCount[idx2]; idx2++)
            {
                while(card >= copper && card <= gold)
                {
                    card = randomByRange(0, treasure_map - 1);
                }
                state->deck[idx][idx2] = card;
            }

            testAdventurerCard(state);
        }

        //
        // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
        // >>> TEST 2: random deck size, only one treasure card...
        // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
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

            // Fill the deck with random non-treasure cards. 27
            // cards total, so get a number from 0 to 26
            //
            for(idx2 = 0; idx2 < state->deckCount[idx2]; idx2++)
            {
                while(card >= copper && card <= gold)
                {
                    card = randomByRange(0, treasure_map - 1);
                }
                state->deck[idx][idx2] = card;
            }

            // Slip in one random treasure card at a random location in the deck
            //
            card = randomByRange(copper, gold);
            idx2 = randomByRange(0, deckSize);
            state->deck[idx][idx2] = card;

            testAdventurerCard(state);
        }

        //
        // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
        // >>> TEST 3: random tiny deck size, random cards...
        // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
        //
        
        // New game
        //
        free(state);
        state = newGame();
        initializeGame(numPlayers, kingdomCards, randomSeed, state);

        deckSize = randomByRange(0, 9);

        for(idx = 0; idx < numPlayers; idx++)
        {
            printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
            printf(">>> TEST 3 RUN %d: tiny deck size %d, player %d, random cards...\n", testRunNum, deckSize, idx);
            printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n");

            // Set the current player
            //
            state->whoseTurn = idx;

            // Set the new deck size
            //
            state->deckCount[idx] = deckSize;

            // Fill the deck with random non-treasure cards. 27
            // cards total, so get a number from 0 to 26
            //
            treasureCardCount = 0;
            for(idx2 = 0; idx2 < state->deckCount[idx2]; idx2++)
            {
                card = randomByRange(0, treasure_map - 1);
                if(card >= copper && card <= gold)
                {
                    printf(">>> NOTE: Treasure card added: ");
                    switch(card)
                    {
                        case copper:
                            printf("copper\n");
                            break;
                        case silver:
                            printf("silver\n");
                            break;
                        case gold:
                            printf("gold\n");
                    }
                    treasureCardCount++;
                }
                state->deck[idx][idx2] = card;
            }
            if(treasureCardCount == 0)
            {
                printf(">>> NOTE: No treasure cards in deck!\n");
            }

            testAdventurerCard(state);
        }

        // We still have a state pointer to free up...
        //
        free(state);
    }

    return 0;
}


