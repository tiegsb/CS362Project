#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main()
{
    int player = 1;
    int card = 0;

    int i;
    int pass = 0;
    int fail = 0;
    int seed = 1000;
    int numPlayers = 2;
    struct gameState G;

    int kings[10] = {adventurer, council_room, feast, gardens, mine,
                     remodel, smithy, village, baron, great_hall};

    printf("*****Testing fullDeckCount function*****\n");

    initializeGame(numPlayers, kings, seed, &G);
    int retValue = 0;


    retValue = fullDeckCount(player,card,&G);

    if(retValue == 0)
    {
        printf("Test passed: return value = 0.\n");
        pass++;
    }
    else {
        printf("Test failed: return value = 1.\n");
        fail++;
    }
    printf("%d tests passed, %d tests failed\n", pass, fail);

    printf("\n");


    return 0;
}
