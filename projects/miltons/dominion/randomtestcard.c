// tests Smithy card
// int smithyEffect(int currentPlayer, struct gameState *state, int handPos)
// LINE 1230 of dominion.c

// test / assert against state of game before and after smithy is played

// hand will have 3 more cards in post than in pre

// discard pile will either have 1 more card in post than in pre
// or will have 1 card (in case of empty deck during draw)


// adapted from examples in week 3 lecture "How to Write a Simple Random Tester"

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
 ** Description:      This function 
 ** Parameters:       
 ** Pre-Conditions:   
 ** Post-Conditions:  
 **
 *****************************************************************************/
int testSmithyEffect(int playerNumber, struct gameState *testState);



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

        // call test oracle function and pass it these parameters
        int retVal = testSmithyEffect(playerNumber, &testState);

        // check return value for failure / crash
        if (retVal < 0)
        {
            printf("Test #%d Smithy card: FAIL\n", i);
        }
    }

    printf("%d tests run. All tests passed unless noted above.\n", i);

    exit(0);
}



int testSmithyEffect(int playerNumber, struct gameState *post)
{
    // call smithyEffect function
    //smithyEffect

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
