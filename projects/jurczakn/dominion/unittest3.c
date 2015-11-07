/* -----------------------------------------------------------------------
 * Demonstration of how to write unit tests for dominion-base
 * Include the following lines in your makefile:
 *
 * testUpdateCoins: testUpdateCoins.c dominion.o rngs.o
 *      gcc -o testUpdateCoins -g  testUpdateCoins.c dominion.o rngs.o $(CFLAGS)
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int main() {
    int result, r;
    int seed = 1000;
    int numPlayer = 2;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;

    printf ("TESTING isGameOver():\n");
   
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    r = initializeGame(numPlayer, k, seed, &G); // initialize a new game

    printf("Test 1: empty province\n");
    G.supplyCount[province] = 0;
    result = isGameOver(&G);
    printf("Result: %d, Expected: 1\n", result);
    if (result == 1){
	printf("Success\n");
    }
    else{
	printf("Failure\n");
    }

    printf("Test 2: empty treasure\n");
    memset(&G, 23, sizeof(struct gameState));    // clear the game state
    r = initializeGame(numPlayer, k, seed, &G);  // initialize a new game
    G.supplyCount[copper] = 0;
    G.supplyCount[silver] = 0;
    G.supplyCount[gold] = 0;
    result = isGameOver(&G);
    printf("Result: %d, Expected: 1\n", result);
    if (result == 1){
	printf("Success\n");
    }
    else{
	printf("Failure<===================\n");
    }

    printf("Test 3: empty estate duchy and curse\n");
    memset(&G, 23, sizeof(struct gameState));    // clear the game state
    r = initializeGame(numPlayer, k, seed, &G);  // initialize a new game
    G.supplyCount[estate] = 0;
    G.supplyCount[duchy] = 0;
    G.supplyCount[curse] = 0;
    result = isGameOver(&G);
    printf("Result: %d, Expected: 1\n", result);
    if (result == 1){
	printf("Success\n");
    }
    else{
	printf("Failure<====================\n");
    }
    
    printf("Test 4: 3 empty action cards\n");
    memset(&G, 23, sizeof(struct gameState));    // clear the game state
    r = initializeGame(numPlayer, k, seed, &G);  // initialize a new game
    G.supplyCount[adventurer] = 0;
    G.supplyCount[smithy] = 0;
    G.supplyCount[village] = 0;
    result = isGameOver(&G);
    printf("Result: %d, Expected: 1\n", result);
    if (result == 1){
	printf("Success\n");
    }
    else{
	printf("Failure\n");
    }

    printf("Test 5: 2 empty action cards\n");
    memset(&G, 23, sizeof(struct gameState));    // clear the game state
    r = initializeGame(numPlayer, k, seed, &G);  // initialize a new game
    G.supplyCount[smithy] = 0;
    G.supplyCount[village] = 0;
    result = isGameOver(&G);
    printf("Result: %d, Expected: 0\n", result);
    if (result == 0){
	printf("Success\n");
    }
    else{
	printf("Failure\n");
    }

    printf("Test 6: empty 3 action cards not in play\n");
    memset(&G, 23, sizeof(struct gameState));    // clear the game state
    r = initializeGame(numPlayer, k, seed, &G);  // initialize a new game
    G.supplyCount[baron] = 0;
    G.supplyCount[cutpurse] = 0;
    G.supplyCount[salvager] = 0;
    result = isGameOver(&G);
    printf("Result: %d, Expected: 0\n", result);
    if (result == 0){
	printf("Success\n");
    }
    else{
	printf("Failure\n");
    }

    printf("Test 7: all cards full\n");
    memset(&G, 23, sizeof(struct gameState));    // clear the game state
    r = initializeGame(numPlayer, k, seed, &G);  // initialize a new game
    result = isGameOver(&G);
    printf("Result: %d, Expected: 0\n", result);
    if (result == 0){
	printf("Success\n");
    }
    else{
	printf("Failure\n");
    }

    printf("All tests finished for isGameOver()\n");

    return 0;
}
