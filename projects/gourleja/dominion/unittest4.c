/*
 * Jason Gourley
 * gourleja@oregonstate.edu
 * CS362-400
 * Assignment 3 - unittest4.c
 * Description : Unit tests for endTurn method
 */

#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "rngs.h"

#define METHODNAME  "endTurn"
#define BASESEED    10

/*
 * Description:     Test the return values of the endTurn method
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

    printf ("\n\n-------------------------------------------------------------------------------\n");
    printf ("-------------------------------------------------------------------------------\n");
    printf ("Testing Method  : %s()\n", currentTest);
    printf ("Seed            : %i\n", seed);

    //check that the current players hand count is reset after method call
    expectedValue = 0;
    state->whoseTurn = 0;
    endTurn(state);
    if(state->handCount[0] != expectedValue) {
        printf("TEST FAIL    : Current player hand count reset failed\n");
        testsFailed++;
    } else {testsPassed++;}

    //check that the outposts played is reset after method call
    expectedValue = 0;
    endTurn(state);
    if(state->outpostPlayed != expectedValue) {
        printf("TEST FAIL    : Outpost's Played reset failed\n");
        testsFailed++;
    } else {testsPassed++;}

    //check that the phase value is reset after method call
    expectedValue = 0;
    endTurn(state);
    if(state->phase != expectedValue) {
        printf("TEST FAIL    : Phase reset failed\n");
        testsFailed++;
    } else {testsPassed++;}

    //check that the number of actions is reset after method call
    expectedValue = 1;
    endTurn(state);
    if(state->numActions != expectedValue) {
        printf("TEST FAIL    : Number of Actions reset failed\n");
        testsFailed++;
    } else {testsPassed++;}

    //check that the number of buys available is reset after method call
    expectedValue = 1;
    endTurn(state);
    if(state->numBuys != expectedValue) {
        printf("TEST FAIL    : Number of Buys value reset failed\n");
        testsFailed++;
    } else {testsPassed++;}

    //check that the current players card count is reset after method call
    expectedValue = 0;
    endTurn(state);
    if(state->playedCardCount != expectedValue) {
        printf("TEST FAIL    : Played card count value reset failed\n");
        testsFailed++;
    } else {testsPassed++;}

    //check that the next player is correctly given control after method call, using first player
    state->whoseTurn = 0;
    expectedValue = 1;
    endTurn(state);
    if(state->whoseTurn != expectedValue) {
        printf("TEST FAIL    : Next player value reset failed\n");
        testsFailed++;
    } else {testsPassed++;}

    //check that the next player is correctly given control after method call, using last player
    state->whoseTurn = 1;
    expectedValue = 0;
    endTurn(state);
    if(state->whoseTurn != expectedValue) {
        printf("TEST FAIL    : Next player value reset failed\n");
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
