//
// *****************************************************************************
// 
// Author:    Erik Ratcliffe
// Date:      October 25, 2015
// Project:   Assignment 3 - Unit Tests
// Filename:  unittest4.c
// Class:     CS 362 (Fall 2015)
//
// *****************************************************************************
//

#include <stdio.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "unittest_helpers.h"


// Test the isGameOver() function.
//
// gainCard():
// Checks the nunber of provinces or if three supply piles are empty to
// determine if the game is over.
//
// Returns 1 if the game is over.
//
int testIsGameOver(struct gameState *state)
{
    int totalSupplyCount = 0;     // tally of all supplyCounts
    int isGameOverRet;            // return value from isGameOver()
    int idx;                      // loop iterator

    // Run isGameOver()
    //
    isGameOverRet = isGameOver(state);

    for(idx = 0; idx < treasure_map; idx++)
    {
        if(state->supplyCount[idx] == 0)
        {
            totalSupplyCount++;
        }
    }
    
    // If the criteria for a finished game exists...
    //
    if(totalSupplyCount >= 3 || state->supplyCount[province] == 0)
    {
        // Did isGameOver() exit with the correct return value?
        //
        if(isGameOverRet == 1)
        {
            printf("isGameOver: PASS game ended correctly\n");
        }
        else
        {
            printf("isGameOver: FAIL game was not recognized as being over\n");
        }
    }
    else
    {
        // Did isGameOver() exit with the correct return value?
        //
        if(isGameOverRet == 1)
        {
            printf("isGameOver: FAIL game not over, but isGameOver says it is\n");
        }
        else
        {
            printf("isGameOver: PASS game is recognized as still going\n");
        }
    }

    printf("\n");

    return 0;
}


int main(int argc, char *argv[])
{
    int numPlayers = 2;      // default number of players
    int randomSeed = 100;    // random seed for the game
    struct gameState *state; // holds the new state of the game
    int kingdomCards[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};

    // New game
    //
    state = newGame();
    initializeGame(numPlayers, kingdomCards, randomSeed, state);

    printf("\n");

    // Test for a game that should not be over. Game initialization should
    // automatically set up the cards so the game doesn't end before it
    // begins.
    //
    printf(">>> TESTING: isGameOver(), game should not be over...\n");
    testIsGameOver(state);

    //printf("\n");

    // New game
    //
    state = newGame();
    initializeGame(numPlayers, kingdomCards, randomSeed, state);

    // Test for a legit end of game
    //
    printf(">>> TESTING: isGameOver(), game should be over...\n");
    state->supplyCount[province] = 0;
    testIsGameOver(state);

    return 0;
}

