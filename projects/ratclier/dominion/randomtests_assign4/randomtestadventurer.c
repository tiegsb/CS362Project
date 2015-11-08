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

#define testRuns 13000

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

// Influenced by code from the following webpage:
// http://stackoverflow.com/questions/9571738/picking-random-number-between-two-points-in-c
//
int randomByRange(int min, int max)
{
    int diff = max - min;
    return (int) (((double)(diff+1)/RAND_MAX) * rand() + min);
}


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

    return 0;
}


int main(int argc, char *argv[])
{
    // Things to randomize:
    // - number of players (numPlayers, 2-MAX_PLAYERS)
    // - current player (state->whoseTurn)
    // - kingdom cards?
    int numPlayers = 2;         // number of players
    int randomSeed = 1000;      // random seed for the game
    struct gameState *state;    // holds the updated game state
    int kingdomCards[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    int idx = 0;                // loop iterator
    int idx2 = 0;               // loop iterator, misc value holder
    int card = 0;
    int treasureCardCount = 0;
    int deckSize = 0;
    int testRunNum = 0;

    // Randomize
    //
    srand(time(NULL));
    
    for(testRunNum = 1; testRunNum <= testRuns; testRunNum++)
    {
        // Generate a random number of players between minPlayers and MAX_PLAYERS
        //
        //numPlayers = randomByRange(minPlayers, MAX_PLAYERS);
        //numPlayers = randomByRange(minPlayers, 3);

        //currentPlayer = randomByRange(0, numPlayers - 1);

        // New game
        //
        state = newGame();
        initializeGame(numPlayers, kingdomCards, randomSeed, state);

        // Set up a random deck size from normal (10, which needs to be
        // changed to 9 because it's 0 indexed) and MAX_DECK (which also
        // needs to be reduced by 1)
        //
        deckSize = randomByRange(9, MAX_DECK - 1);

        printf("\n");

        // TEST 1: random deck size up to MAX_DECK, no treasure cards
        //
        for(idx = 0; idx < numPlayers; idx++)
        {
            printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
            printf(">>> TEST 1 RUN %d: deck size %d, player %d, no treasure cards...\n", testRunNum, deckSize, idx);
            printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n");

            // Test adventurer card for a player
            //
            state->whoseTurn = idx;

            // Set up a random deck size from normal (10, which needs to be
            // changed to 9 because it's 0 indexed) and MAX_DECK (which also
            // needs to be reduced by 1)
            //
//            deckSize = randomByRange(9, MAX_DECK - 1);

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

        // New game
        //
        state = newGame();
        initializeGame(numPlayers, kingdomCards, randomSeed, state);

        // Set up a random deck size from normal (10, which needs to be
        // changed to 9 because it's 0 indexed) and MAX_DECK (which also
        // needs to be reduced by 1)
        //
        deckSize = randomByRange(9, MAX_DECK - 1);

        // TEST 2: random deck size up to MAX_DECK, one treasure card
        //
        for(idx = 0; idx < numPlayers; idx++)
        {
            printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
            printf(">>> TEST 2 RUN %d: deck size %d, player %d, one treasure card...\n", testRunNum, deckSize, idx);
            printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n");

            // Test adventurer card for a player
            //
            state->whoseTurn = idx;

            // Set up a random deck size from normal (10, which needs to be
            // changed to 9 because it's 0 indexed) and MAX_DECK (which also
            // needs to be reduced by 1)
            //
//            deckSize = randomByRange(9, MAX_DECK - 1);

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

        // New game
        //
        state = newGame();
        initializeGame(numPlayers, kingdomCards, randomSeed, state);

        deckSize = randomByRange(0, 9);

        // TEST 3: tiny deck size, random cards in deck
        //
        for(idx = 0; idx < numPlayers; idx++)
        {
            printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
            printf(">>> TEST 3 RUN %d: tiny deck size %d, player %d, random cards...\n", testRunNum, deckSize, idx);
            printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n");

            // Test adventurer card for a player
            //
            state->whoseTurn = idx;

            //deckSize = randomByRange(0, MAX_DECK - 1);

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
    }




    return 0;
}


