/* -----------------------------------------------------------------------
 * Unit test to check whether isGameOver ends game properly
 *
 * unittest1: unittest1.c dominion.o rngs.o
 *      gcc -o unittest1 -g  unittest1.c dominion.o rngs.o $(CFLAGS)
 *
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main() {
    int seed = 1000;
	int numPlayer = 2;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
	
	printf("Testing number of certain cards to see when game is over.\n");
	
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    initializeGame(numPlayer, k, seed, &G); 	// initialize a new game
	
	
	// check if game over for province counts
	printf("Test 1: Determine how many province cards it takes to end game.\n");
	
	G.supplyCount[province] = 1;
	
	if(isGameOver(&G))
		printf("Failed: 1 province card left ends game.\n");
	
	else
		printf("Passed: 1 province card left doesn't end game.\n");
	
	G.supplyCount[province]--;
	
	if(isGameOver(&G))
		printf("Passed: 0 province cards left ends game.\n\n");
	
	else
		printf("Failed: 0 province cards left doesn't end game.\n\n");

	
	// check if game over for kingdom card counts
	printf("Test 2: Determine what sets of kingdom cards gone ends the game.\n");
	memset(&G, 23, sizeof(struct gameState));   // clear the game state
    initializeGame(numPlayer, k, seed, &G); 	// initialize a new game
	
	G.supplyCount[adventurer] = 0;
	if(isGameOver(&G))
		printf("Failed: 1 set of kingdom cards gone ends game.\n");
	
	else
		printf("Passed: 1 set of kingdom cards gone doesn't end game.\n");
	
	G.supplyCount[council_room] = 0;
	if(isGameOver(&G))
		printf("Failed: 2 sets of kingdom cards gone ends game.\n");
	
	else
		printf("Passed: 2 sets of kingdom cards gone doesn't end game.\n");
	
	G.supplyCount[feast] = 0;
	if(isGameOver(&G))
		printf("Passed: 3 sets of kingdom cards gone ends game.\n\n");
	
	else
		printf("Failed: 3 sets of kingdom cards gone doesn't end game.\n\n");
	
	// check if game over for coin card counts
	printf("Test 3: Determine how many sets of treasure cards gone ends the game.\n");
	memset(&G, 23, sizeof(struct gameState));   // clear the game state
    initializeGame(numPlayer, k, seed, &G); 	// initialize a new game
	
	G.supplyCount[gold] = 0;
	if(isGameOver(&G))
		printf("Failed: 1 set of treasure cards gone ends game.\n");
	
	else
		printf("Passed: 1 set of treasure cards doesn't end game.\n");
	
	G.supplyCount[silver] = 0;
	if(isGameOver(&G))
		printf("Failed: 2 sets of treasure cards gone ends game.\n");
	
	else
		printf("Passed: 2 sets of treasure cards gone doesn't end game.\n");
	
	G.supplyCount[copper] = 0;
	if(isGameOver(&G))
		printf("Passed: 3 sets of treasure cards gone ends game.\n\n");
	
	else
		printf("Failed: 3 sets of treasure cards doesn't end game.\n\n");

    return 0;
}
