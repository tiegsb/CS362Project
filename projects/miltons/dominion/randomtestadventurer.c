// tests Adventurer card
// int adventurerEffect(int currentPlayer, int drawntreasure, int temphand[MAX_HAND], struct gameState *state, int cardDrawn, int z)

// test / assert against state of game before and after adventurer is played

#include <stdio.h>
#include "dominion.h"
#include "dominion_helpers.h"
//#include "rngs.h"

int main(int argc, char *argv[])
{
    struct gameState testState;
    int retVal = adventurerEffect(0, 0, 0, &testState, 0, 0);
    if (retVal == 0)
    {
        printf("Adventurer card: PASS\n");
    }
    else
    {
        printf("Adventurer card: FAIL\n");
    }
    return 0;
}
