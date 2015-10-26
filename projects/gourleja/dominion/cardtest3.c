/*
 * Jason Gourley
 * gourleja@oregonstate.edu
 * CS362-400
 * Assignment 3 - cardtest3.c
 * Description : Unit tests for great_hall card
 */

#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "rngs.h"

#define CARDNAME  "great_hall"
#define BASESEED    10

/*
 * Description:     Test the return values of the great_hall card
 * Preconditions:   The games state has been initialized, the seed and method name to test are passed
 * Postconditions:  The general messages and any failed test messages are displayed
 */
int testCard(char* currentTest, int seed, struct gameState *state)
{
    int i;
    int testsPassed = 0;
    int testsFailed = 0;
    int expectedValue = 0;
    int bonus = 0;

    printf ("\n\n-------------------------------------------------------------------------------\n");
    printf ("-------------------------------------------------------------------------------\n");
    printf ("Testing Method  : %s()\n", currentTest);
    printf ("Seed            : %i\n", seed);

    //Check increase of cards in hand
    expectedValue = state->handCount[state->whoseTurn];
    cardEffect(great_hall,0,0,0,state, 0, &bonus);
    if(state->handCount[state->whoseTurn] != expectedValue) {
        printf("  TEST FAIL    : great_hall card add card to hand failed\n");
        testsFailed++;
    } else {testsPassed++;}

    //Check increase of cards in hand
    expectedValue = state->numActions + 1;
    cardEffect(great_hall,0,0,0,state, 0, &bonus);
    if(state->numActions != expectedValue) {
        printf("  TEST FAIL    : great_hall card add number of actions failed\n");
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
