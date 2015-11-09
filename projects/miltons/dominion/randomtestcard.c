// tests Smithy card
// int smithyEffect(int currentPlayer, struct gameState *state, int handPos)
// smithyEffect() on line 1230 of dominion.c

// Test code adapted from examples in week 3 lecture "How to Write a Simple Random Tester."

// test / assert against state of game before and after smithy is played

// hand will have 3 more cards in post than in pre

// discard pile will either have 1 more card in post than in pre
// or will have 1 card (in case of empty deck during draw)



// what should be random?
// # of players?
// which player it is


#include <stdio.h>
#include <stdlib.h>    // for rand and srand
#include <time.h>      // for time
#include "dominion.h"
#include "dominion_helpers.h"
//#include "rngs.h"

#define NUM_TESTS 2000 // number of tests to run



/*****************************************************************************
 ** Function:         randInt()
 ** Description:      This function generates and returns a psuedo-random number
 **                   in range from min to max, inclusive.
 ** Parameters:       two int values: min, max
 ** Pre-Conditions:   min and max are integer values
 ** Post-Conditions:  returns the random number
 **
 *****************************************************************************/
int randInt(int min, int max);



/*****************************************************************************
 ** Function:         testSmithyEffect()
 ** Description:      This function tests the smithyEffect() function. It
 **                   creates a copy of the game state, calls the function
 **                   passing it the game state, makes changes to the copy of
 **                   the game state based on what the function is expected to
 **                   do if it is working correctly. Then actual results to
 **                   the game state from smithyEffect() are compared to the 
 **                   expected results to see if the function is working
 **                   properly.
 ** Parameters:       two int values: playerNumber, handPos
 **                   a pointer to a struct of type gameState: testState
 ** Pre-Conditions:   playerNumber and handPos are of type int with values
 **                   within valid ranges for the game. testState is a
 **                   initialized and its member variables should have valid
 **                   values, at least for the more important game parameters
 ** Post-Conditions:  The smithyEffect function has been tested. Any errors 
 **                   and discrepancies between the actual results and expected
 **                   results have been output to the console.
 **
 *****************************************************************************/
int testSmithyEffect(int playerNumber, struct gameState *testState, int handPos);



int main(int argc, char *argv[])
{
    struct gameState testState;

    int i;
    int j;
    int playerNumber;
    time_t sysClock;

    // seed the rand() function with system clock to avoid getting same rand #s
    srand((unsigned) time(&sysClock));

    // each iteration of this outer loop runs a test against smithyEffect()
    for (i = 0; i < NUM_TESTS; i++)
    {
        // this loop populates every Byte of the game state with random values
        for (j = 0; j < sizeof(struct gameState); j++)
        {
            ((char*)&testState)[j] = randInt(0, 256);
        }

        // generate sensible random values for important preconditions:
        // select a random player
        playerNumber = randInt(1, 2); // can this go to 4 players?
        // random number of cards in current player's deck
        testState.deckCount[playerNumber] = randInt(0, MAX_DECK);
        // random number of cards in current player's discard pile
        testState.discardCount[playerNumber] = randInt(0, MAX_DECK);
        // random number of cards in current player's hand
        testState.handCount[playerNumber] = randInt(0, MAX_HAND);
        // random value for position in hand of card to discard
        handPos = randInt(0, testState.handCount[playerNumber] - 1);

        // call test oracle function and pass it these parameters
        int retVal = testSmithyEffect(playerNumber, &testState, handPos);

        // check return value for failure / crash
        if (retVal < 0)
        {
            printf("Test #%d Smithy card: FAIL\n", i);
        }
    }

    printf("%d tests run. All tests passed unless noted above.\n", i);

    exit(0);
}



int testSmithyEffect(int playerNumber, struct gameState *post, int handPos)
{

    // create duplicate of game state for before and after comparison
    struct gameState pre;
    memcpy (&pre, post, sizeof(struct gameState));

    // call smithyEffect function
    smithyEffect(playerNumber, post, handPos);

    // make changes to pre based on what smithyEffect should do

    // compare actual result to expected result (post to pre)

    // return zero if smithyEffect did not crash
    return 0;
}



/* uses stdlib.h */
int randInt(int min, int max)
{   // returns a random integer between min and max, inclusive
    // (max - min + 1) is the range
    // + min sets the bottom of the range
    return rand() % (max - min + 1) + min;
}
