/*
This program tests the villageCard function.
The parameters for this function are:
struct gameState *state

*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include "interface.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int main() {

    int i;

    //initialize the game
    struct gameState G;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
    sea_hag, tribute, smithy};

    printf ("Starting game.\n");

    printState(&G);
    printSupply(&G);
    printGamestate(&G);
    printScores(&G);

    initializeGame(2, k, atoi(argv[1]), &G);

    
    printf("All tests passed!\n");

    
    
    return 0;
}
