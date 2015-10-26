#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main()
{
    int i;
    int pass = 0;
    int fail = 0;
    int seed = 1000;
    int numPlayers = 2;
    struct gameState G;

    int kings[10] = {adventurer, council_room, feast, gardens, mine,
                     remodel, smithy, village, baron, great_hall};

    printf("*****Testing isGameOver function*****\n");

    initializeGame(numPlayers, kings, seed, &G);
    int retValue = 0;

    G.supplyCount[province] = 1;
    retValue = isGameOver(&G);

    printf("Provinces = 1. Expected return value = 0\n");
    if(retValue == 1)
    {
        printf("Test failed: return value = 1. Game should be over when number of provinces are equal to 0\n");
        fail++;
    }
    else {
        printf("Test passed: return value = 0. Game is not over until provinces are equal to 0\n");
        pass++;
    }

    G.supplyCount[province] = 0;
    retValue = isGameOver(&G);

    printf("Provinces = 0. Expected return value = 1\n");
    if(retValue == 0)
    {
        printf("Test failed: return value = 0.\n");
        fail++;
    }
    else {
        printf("Test passed: return value = 1. Game is over when no provinces remain.\n");
        pass++;
    }
    for(i = 0; i < 3; i++) {

        G.supplyCount[i] = 0;
    }

    retValue = isGameOver(&G);
    printf("Three supply counts = 0. Expected return value = 1\n");
    if(retValue == 1)
    {
        printf("Test passed: return value = 1.\n");
        pass++;
    }
    else {
        printf("Test failed: return value = 0.\n");
        fail++;
    }
    printf("Provinces = 0. Expected return value = 1.\n");

    if(retValue == 0)
    {
        printf("Test failed: return value = 0.\n");
        fail++;
    }
    else {
        printf("Test passed: return value = 1.\n");
        pass++;
    }
    isGameOver(&G);

    printf("%d tests passed, %d tests failed\n", pass, fail);
    printf("\n");

    return 0;
}
