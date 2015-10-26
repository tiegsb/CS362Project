/*
 * Jason Gourley
 * gourleja@oregonstate.edu
 * CS362-400
 * Assignment 3 - cardtest2.c
 * Description : Unit tests for Adventurer card
 */

#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "rngs.h"

#define CARDNAME  "adventurer"
#define BASESEED    10

/*
 * Description:     Test the return values of the adventurer card
 * Preconditions:   The games state has been initialized, the seed and method name to test are passed
 * Postconditions:  The general messages and any failed test messages are displayed
 */
int testCard(char* currentTest, int seed, struct gameState *state)
{
    int i;
    int testsPassed = 0;
    int testsFailed = 0;
    int expectedValue = 0;

    printf ("\n\n-------------------------------------------------------------------------------\n");
    printf ("-------------------------------------------------------------------------------\n");
    printf ("Testing Method  : %s()\n", currentTest);
    printf ("Seed            : %i\n", seed);

    //Check increase of cards in hand

    int currentPlayer = whoseTurn(state);
    int drawntreasure=0;
    int handPos = 0;
    int temphand[MAX_HAND];// moved above the if statement
    int z = 0;// this is the counter for the temp hand
    int cardDrawn;

    //Check reduction of cards in hand
    expectedValue = state->handCount[currentPlayer] - 1;
    cardAdventurer(temphand, z, cardDrawn, drawntreasure, handPos, currentPlayer, state);
    if(state->handCount[currentPlayer] < expectedValue) {
        printf("  TEST FAIL    : Adventurer remove card from hand failed\n");
        testsFailed++;
    } else {testsPassed++;}

    //Check addition of cards to hand
    expectedValue = state->handCount[currentPlayer];
    cardAdventurer(temphand, z, cardDrawn, drawntreasure, handPos, currentPlayer, state);
    if(state->handCount[currentPlayer] - expectedValue > 1) {
        printf("  TEST FAIL    : Adventurer add correct number of cards to hand failed\n");
        testsFailed++;
    } else {testsPassed++;}

    //Check hand size with lack of treasure cards to add to hand
    state->deckCount[currentPlayer] = 10;
    int card = 0;
    for (i = 0; i < 500; i++)
    {
      state->deck[currentPlayer][i] = card;
      state->discard[currentPlayer][i] = card;
    }
    expectedValue = state->handCount[currentPlayer] - 1;
    cardAdventurer(temphand, z, cardDrawn, drawntreasure, handPos, currentPlayer, state);
    if(state->handCount[currentPlayer] != expectedValue) {
        printf("  TEST FAIL    : Adventurer no treasure available but cards to hand failed\n");
        testsFailed++;
    } else {testsPassed++;}

    printf ("    Tests Passed    : %i\n", testsPassed);
    printf ("    Tests Failed    : %i\n", testsFailed);
    printf ("-------------------------------------------------------------------------------\n\n");

    return 0;
}


/*
 * Preconditions:   The user can pass a seed value for testing or it defaults to a set value
 * Postconditions:  Exit the test program normally
 */
int main (int argc, char** argv)
{

    // Setup Game Seed
    int seed;
    char* currentTest = CARDNAME;
    if(argv[1]) {
        seed = atoi(argv[1]);
    } else {
        seed = BASESEED;
    }

    // Initialize Game State
    struct gameState G;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    initializeGame(2, k, seed, &G);

    testCard(currentTest,seed, &G);

    return 0;
}
