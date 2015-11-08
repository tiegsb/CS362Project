/*
 * Jason Gourley
 * gourleja@oregonstate.edu
 * CS362-400
 * Assignment 3 - unittest3.c
 * Description : Unit tests for playCard method
 */

#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "rngs.h"

#define METHODNAME  "playCard"
#define BASESEED    10

/*
 * Description:     Test the return values of the playCard method
 * Preconditions:   The games state has been initialized, the seed and method name to test are passed
 * Postconditions:  The general messages and any failed test messages are displayed
 */
int testMethod(char* currentTest, int seed, struct gameState *state)
{
    int i;
    int testsPassed = 0;
    int testsFailed = 0;
    int expectedValue = 0;
    int expectedState = 0;
    int actualValue = 0;
    int actualState = 0;

    printf ("\n\n-------------------------------------------------------------------------------\n");
    printf ("-------------------------------------------------------------------------------\n");
    printf ("Testing Method  : %s()\n", currentTest);
    printf ("Seed            : %i\n", seed);

    int supplyPos = 1;

    //check incorrect phase produces the correct error value
    expectedValue = -1;
    state->phase = 0;
    actualValue = playCard(0, -1, -1, -1, state);
    if(actualValue != expectedValue) {
        printf("  TEST FAIL    : Phase check failed\n");
        testsFailed++;
    } else {testsPassed++;}

    //check incorrect phase produces the correct error value
    expectedValue = -1;
    state->numActions = 0;
    actualValue = playCard(0, -1, -1, -1, state);
    if(actualValue != expectedValue) {
        printf("  TEST FAIL    : Phase check failed\n");
        testsFailed++;
    } else {testsPassed++;}

    //check incorrect card type produces the correct error value
    expectedValue = -1;
    state->numActions = 1;
    state->hand[whoseTurn(state)][0] = 0;
    actualValue = playCard(0, -1, -1, -1, state);
    if(actualValue != expectedValue) {
        printf("  TEST FAIL    : Action card check failed\n");
        testsFailed++;
    } else {testsPassed++;}

    //check for correct action decrement value
    expectedValue = 0;
    state->numActions = 1;
    state->hand[whoseTurn(state)][0] = 7;
    actualValue = playCard(0, -1, -1, -1, state);
    if(actualValue != expectedValue) {
        printf("  TEST FAIL    : Actions decrement check failed\n");
        testsFailed++;
    } else {testsPassed++;}

    //check for correct coin increment value
    expectedValue = state->coins + 2;
    state->numActions = 2;
    state->hand[whoseTurn(state)][0] = 17;
    actualValue = playCard(0, 1, -1, -1, state);
    if(state->coins != expectedValue) {
        printf("  TEST FAIL    : Coin increment check failed\n");
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
    char* currentTest = METHODNAME;
    if(argv[1]) {
        seed = atoi(argv[1]);
    } else {
        seed = BASESEED;
    }

    // Initialize Game State
    struct gameState G;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    initializeGame(2, k, seed, &G);

    testMethod(currentTest,seed, &G);
    return 0;
}
