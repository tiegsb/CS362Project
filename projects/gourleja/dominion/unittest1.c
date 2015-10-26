/*
 * Jason Gourley
 * gourleja@oregonstate.edu
 * CS362-400
 * Assignment 3 - unittest1.c
 * Description : Unit tests for isGameOver method
 */

#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "rngs.h"

#define METHODNAME  "isGameOver"
#define BASESEED    10

/*
 * Description:     Test the return values of the isGameOver method
 * Preconditions:   The games state has been initialized, the seed and method name to test are passed
 * Postconditions:  The general messages and any failed test messages are displayed
 */
int testMethod(char* currentTest, int seed, struct gameState *state)
{
    int i;
    int testsPassed = 0;
    int testsFailed = 0;
    int expectedValue = 0;

    printf ("\n\n-------------------------------------------------------------------------------\n");
    printf ("-------------------------------------------------------------------------------\n");
    printf ("Testing Method  : %s()\n", currentTest);
    printf ("Seed            : %i\n", seed);

    //check new game produces the correct value
    expectedValue = 1;
    if(isGameOver(state) == expectedValue) {
        printf("  TEST FAIL    : Newly initialized game failed\n");
        testsFailed++;
    } else {testsPassed++;}

    //check a lack of province cards produces the correct value
    expectedValue = 0;
    state->supplyCount[province] = 0;
    if(isGameOver(state) == expectedValue) {
        printf("  TEST FAIL    : Province supply out check failed\n");
        testsFailed++;
    } else {testsPassed++;}

    //check that when 3 supply piles are empty produces the correct value
    expectedValue = 0;
    state->supplyCount[province] = 1;
    for(i=0; i<3; i++){
        state->supplyCount[i] = 0;
    }
    if(isGameOver(state) == expectedValue) {
        printf("  TEST FAIL    : 3 card supply out check failed\n");
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

