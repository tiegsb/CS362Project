// tests Adventurer card
// int adventurerEffect(int currentPlayer, int drawntreasure, int temphand[MAX_HAND], struct gameState *state, int cardDrawn, int z)
// adventurerEffect() is on line 1207 of dominion.c

// test / assert against state of game before and after adventurer is played

// Test code adapted from examples in week 3 lecture "How to Write a Simple Random Tester."

#include <assert.h>    // for assert
#include <stdio.h>
#include <stdlib.h>    // for rand and srand
#include <time.h>      // for time
#include <string.h>    // for memcpy
#include "dominion.h"
#include "dominion_helpers.h"

#define NUM_TESTS 2000 // number of tests to run
#define NUM_PLAYERS  2 



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
 ** Function:         testAdventurerEffect()
 ** Description:      This function tests the adventurerEffect() function. It
 **                   creates a copy of the game state, calls the function
 **                   passing it the game state, makes changes to the copy of
 **                   the game state based on what the function is expected to
 **                   do if it is working correctly. Then actual results to
 **                   the game state from adventurerEffect() are compared to
 **                   the expected results to see if the function is working
 **                   properly.
 ** Parameters:       one int values: playerNumber
 **                   a pointer to a struct of type gameState: testState
 ** Pre-Conditions:   variables are initialized with values in valid ranges
 **                   within valid ranges for the game.
 ** Post-Conditions:  The adventurerEffect function has been tested. Errors
 **                   and discrepancies between the actual results and expected
 **                   results have been output to the console.
 **
 *****************************************************************************/
int testAdventurerEffect(int playerNumber, struct gameState *post);



int main(int argc, char *argv[])
{
    struct gameState testState;

    int i;
    int j;
    int playerNumber;
    int retVal;
    int seed = 1; // better to make this random too?
    time_t sysClock;

    int cards[10] = {adventurer, council_room, feast, gardens, mine, remodel,
                    smithy, village, baron, great_hall};

    // seed the rand() function with system clock to avoid getting same rand #s
    srand((unsigned) time(&sysClock));

    // each iteration of this outer loop runs a test against adventurerEffect()
    for (i = 0; i < NUM_TESTS; i++)
    {
        // this loop populates every Byte of the game state with random values
        for (j = 0; j < sizeof(struct gameState); j++)
        {
            ((char*)&testState)[j] = randInt(0, 256);
        }

        // initialize game to prevent segmentation fault errors
        retVal = initializeGame(NUM_PLAYERS, cards, seed, &testState);

        // generate sensible random values for important preconditions:
        // select a random player
        playerNumber = randInt(1, 2); // can this go to 4 players?
        // random number of cards in current player's deck
        testState.deckCount[playerNumber] = randInt(0, MAX_DECK);
        // random number of cards in current player's discard pile
        testState.discardCount[playerNumber] = randInt(0, MAX_DECK);
        // random number of cards in current player's hand
        testState.handCount[playerNumber] = randInt(0, MAX_HAND);

        // call test oracle function and pass it parameters
        int retVal = testAdventurerEffect(playerNumber, &testState);

        // check return value for failure / crash
        if (retVal < 0)
        {
            printf("Test #%d Adventurer card: FAIL\n", i);
        }
    }

    printf("%d tests run. All tests passed unless noted above.\n", i);

    exit(0);
}



int testAdventurerEffect(int playerNumber, struct gameState *post)
{

// hand should have 2 more cards in post than in pre AND
// discard pile will have same or more cards in post than in pre
// in case where deck doesn't run out of cards before 2 cards are
// drawn

// OR

// hand will have 0 or 1 more cards in post than in pre AND
// either deck and discard pile will be empty

    int retVal = 0;
    int cardsAvailable;
    int drawnTreasure = 0;
    int tempHand[MAX_HAND];
    int cardDrawn = 0; 
    int z = 0;

    // create duplicate of game state for before and after comparison
    struct gameState pre;
    memcpy (&pre, post, sizeof(struct gameState));

    // call adventurerEffect function
    retVal = adventurerEffect(playerNumber, drawnTreasure, tempHand, post, cardDrawn, z);

    // make changes to pre based on what adventurerEffect should do

    // determine how many cards are left between deck and discard pile
    cardsAvailable = pre.deckCount[playerNumber] + pre.discardCount[playerNumber];

    // add 2 cards to hand or as many as are available if less than 2
    if (cardsAvailable >= 2)
        pre.handCount[playerNumber] = pre.handCount[playerNumber] + 2;
    else // 0 cards or 1 card
        pre.handCount[playerNumber] = pre.handCount[playerNumber] + cardsAvailable;

    // make sure adventurerEffect did not crash
    if (retVal < 0)
    {
        printf("adventurerEffect returned a nonzero value\n");
    }
    else
    {
        // compare actual result to expected result (post to pre)
        // to make sure adventurerEffect is working properly
        if (pre.handCount[playerNumber] != post->handCount[playerNumber])
        {
            printf("adventurerEffect did not add the expected number of cards to the player's hand.\n");
            retVal = -1;
        }
    }

    // returns zero if adventurerEffect did not crash
    return retVal;
}



/* uses stdlib.h */
int randInt(int min, int max)
{   // returns a random integer between min and max, inclusive
    // (max - min + 1) is the range
    // + min sets the bottom of the range
    return rand() % (max - min + 1) + min;
}
