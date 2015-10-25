// tests Mine card
// int mineEffect(int currentPlayer, struct gameState *state, int handPos, int choice1, int choice2)

#include<stdio.h>
#include "dominion.h"
#include "dominion_helpers.h"
//#include "rngs.h"

int main(int argc, char *argv[])
{
    struct gameState testState;
    int retVal = mineEffect(0, &testState, 0, 0, 0);
    if (retVal == 0)
    {
        printf("Mine card: PASS\n");
    }
    else
    {
        printf("Mine card: FAIL\n");
    }
    return 0;
}
