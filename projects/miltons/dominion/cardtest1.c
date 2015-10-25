// tests Smithy card
// int smithyEffect(int currentPlayer, struct gameState *state, int handPos)

#include<stdio.h>
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
