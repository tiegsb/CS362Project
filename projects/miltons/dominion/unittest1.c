// tests discardCard() function
// int discardCard(int handPos, int currentPlayer, struct gameState *state, int trashFlag)

#include<stdio.h>
#include "dominion.h" // contains gameState struct definition
#include "dominion_helpers.h"
//#include "rngs.h"

int main(int argc, char *argv[])
{
    struct gameState testState;
    int retVal = discardCard(0, 0, &testState, 0);
    if (retVal == 0)
    {
        printf("discardCard(): PASS\n");
    }
    else
    {
        printf("discardCard(): FAIL\n");
    }
    return 0;
}
