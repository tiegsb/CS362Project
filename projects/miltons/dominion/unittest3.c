// tests drawCard() function
// int drawCard(int player, struct gameState *state)

#include<stdio.h>
#include "dominion.h"
#include "dominion_helpers.h"
//#include "rngs.h"

int main(int argc, char *argv[])
{
    struct gameState testState;
    int retVal = drawCard(0, &testState);
    if (retVal == 0)
    {
        printf("drawCard(): PASS\n");
    }
    else
    {
        printf("drawCard(): FAIL\n");
    }
    return 0;
}
