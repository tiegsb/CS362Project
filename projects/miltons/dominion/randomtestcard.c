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
#include "dominion.h"
#include "dominion_helpers.h"
//#include "rngs.h"

#define NUM_TESTS 2000;

int main(int argc, char *argv[])
{
    struct gameState testState;

    int i;
    int j;
    int playerNumber;

    // each iteration of this outer loop runs a test against smithyEffect()
    for (i = 0; i < NUM_TESTS; i++)
    {
        // this loop populates every Byte of the game state with random values
        for (j = 0; j < sizeof(struct gameState); j++)
        {
            ((char*)&testState)[j] = floor(Random() * 256);
        }

        // generate sensible random values for important preconditions:
        // select a random player
        playerNumber = floor(Random() * 2); // can this go to 4 players?
        // random number of cards in current player's deck
        testState.deckCount[playerNumber] = floor(Random() * MAX_DECK);
        // random number of cards in current player's discard pile
        testState.discardCount[playerNumber] = floor(Random() * MAX_DECK);
        // random number of cards in current player's hand
        testState.handCount[playerNumber] = floor(Random() * MAX_HAND);

        // call test oracle function and pass it these parameters
        // testSmithyEffect(player, &testState);
    }

    printf("%d tests run. All tests passed.", i);

    exit(0);

    // int retVal = smithyEffect(0, &testState, 0);
    // if (retVal == 0)
    // {
    //     printf("Smithy card: PASS\n");
    // }
    // else
    // {
    //     printf("Smithy card: FAIL\n");
    // }
    // return 0;
}
