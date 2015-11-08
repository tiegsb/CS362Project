// tests Smithy card
// int smithyEffect(int currentPlayer, struct gameState *state, int handPos)

// test / assert against state of game before and after smithy is played

// hand will have 3 more cards in post than in pre

// discard pile will either have 1 more card in post than in pre
// or will have 1 card (in case of empty deck during draw)

#include <stdio.h>
#include "dominion.h"
#include "dominion_helpers.h"
//#include "rngs.h"

int main(int argc, char *argv[])
{
    struct gameState testState;
    int retVal = smithyEffect(0, &testState, 0);
    if (retVal == 0)
    {
        printf("Smithy card: PASS\n");
    }
    else
    {
        printf("Smithy card: FAIL\n");
    }
    return 0;
}
