/*
 * Jason Gourley
 * gourleja@oregonstate.edu
 * CS362-400
 * Assignment 3 - unittest2.c
 * Description : Unit tests for buyCard method
 */

#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "rngs.h"

#define METHODNAME  "buyCard"
#define BASESEED    10

/*
 * Description:     Test the return values of the buyCard method
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

    for(i=0; i<25; i++){
        state->supplyCount[i] = 1;
    }

    int supplyPos = 1;

    //check lack of buys produces the correct error
    expectedValue = -1;
    state->numBuys = 0;
    if(buyCard(supplyPos,state) != expectedValue) {
        printf("  TEST FAIL    : No buys left check failed\n");
        testsFailed++;
    } else {testsPassed++;}

    //check lack of cards
    state->numBuys = 1;
    state->supplyCount[supplyPos] = 0;
    if(buyCard(supplyPos,state) != expectedValue) {
        printf("  TEST FAIL    : No cards left check failed\n");
        testsFailed++;
    } else {testsPassed++;}
    state->supplyCount[supplyPos] = 1;

    //check lack of coins produces the correct error
    state->numBuys = 1;
    state->coins = 0;
    supplyPos = 1;
    if(buyCard(supplyPos,state) != expectedValue) {
        printf("  TEST FAIL    : No coins left check failed\n");
        testsFailed++;
    } else {testsPassed++;}

    //check coin value is correct after call
    state->numBuys = 1;
    state->coins = 5;
    expectedValue = 0;
    if(buyCard(supplyPos,state) != expectedValue || state->coins != 3) {
        printf("  TEST FAIL    : coins value check failed\n");
        testsFailed++;
    } else {testsPassed++;}

    //check numbuys value is correct after call
    state->numBuys = 1;
    state->coins = 5;
    state->supplyCount[1] = 1;
    expectedState = 0;
    int buyCardTest = buyCard(supplyPos,state);
    if(buyCardTest != expectedValue || state->numBuys != expectedState) {
        printf("  TEST FAIL    : numBuys value check failed, %i, %i\n", buyCardTest, state->numBuys);
        testsFailed++;
    } else {testsPassed++;}

    // Check card taken has supply reduced
    state->numBuys = 1;
    state->coins = 5;
    state->supplyCount[1] = 1;
    expectedValue = state->supplyCount[supplyPos] - 1;
    int testBuy = buyCard(supplyPos,state);
    if(state->supplyCount[supplyPos] != expectedValue) {
        printf("  TEST FAIL    : Card supply value reduced correctly check failed\n");
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
