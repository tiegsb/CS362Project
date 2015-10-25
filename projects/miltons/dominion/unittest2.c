// tests updateCoins() function
// int updateCoins(int player, struct gameState *state, int bonus)

#include<stdio.h>
#include "dominion.h"
#include "dominion_helpers.h"
//#include "rngs.h"

int main(int argc, char *argv[])
{

//    struct gameState * testState = newGame();

    struct gameState testState;
    int retVal = updateCoins(0, &testState, 0);
    if (retVal == 0)
    {
        printf("updateCoins(): PASS\n");
    }
    else
    {
        printf("updateCoins(): FAIL\n");
    }
    return 0;
}
