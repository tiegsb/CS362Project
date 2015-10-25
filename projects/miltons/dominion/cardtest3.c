// tests Council Room card
// int councilRoomEffect(int currentPlayer, struct gameState *state, int handPos)

#include<stdio.h>
#include "dominion.h"
//#include "dominion_helpers.h"
//#include "rngs.h"

int main(int argc, char *argv[])
{
    int retVal = councilRoomEffect(0, gameState, 0);
    if (retVal == 0)
    {
        printf("Council Room card: PASS\n");
    }
    else
    {
        printf("Council Room card: FAIL\n");
    }
    return 0;
}
