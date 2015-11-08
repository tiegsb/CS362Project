/* Unit Test 1 - isGameOver()

*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"

void isGameOverTest()
{
	int seed = 1000;
	int numPlayer = 2;
	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, treasure_map};
    struct gameState G;

	printf ("UNIT TESTS for isGameOver():\n");
	
	printf ("Game Over Condition: Remaining Province Cards\n");
	initializeGame(numPlayer, k, seed, &G);
	
	printf ("Province Cards Remaining: 2\n");
	
	G.supplyCount[province] = 2;
	if(isGameOver(&G)){
		printf ("FAILED - Game over with 2 Province cards remaining.\n");
	} else {
		printf ("PASSED - Game still in play.\n");
	}
	
	printf ("Province Cards Remaining: 1\n");
	
	G.supplyCount[province] = 1;
	if(isGameOver(&G)){
		printf ("FAILED - Game over with 1 Province cards remaining.\n");
	} else {
		printf ("PASSED - Game still in play.\n");
	}
	
	printf ("Province Cards Remaining: 0\n");
	
	G.supplyCount[province] = 0;
	if(isGameOver(&G)){
		printf ("PASSED - Game over with 0 Province cards remaining.\n");
	} else {
		printf ("FAILED - Game still in play.\n");
	}
	
	printf ("Game Over Condition: Number of Empty Card Stacks\n");
	memset(&G, 0, sizeof(struct gameState));
	initializeGame(numPlayer, k, seed, &G);
	
	G.supplyCount[adventurer] = 5;
	G.supplyCount[council_room] = 5;
	G.supplyCount[treasure_map] = 5;
	G.supplyCount[feast] = 5;
	
	printf ("Empty Stacks: NONE\n");
	
	if(isGameOver(&G)){
		printf ("FAILED - Game over with no empty card stack.\n");
	} else {
		printf ("PASSED - Game still in play.\n");
	}
	
	printf ("Empty Stacks: adventurer\n");
	
	G.supplyCount[adventurer] = 0;
	if(isGameOver(&G)){
		printf ("FAILED - Game over with 1 empty card stacks.\n");
	} else {
		printf ("PASSED - Game still in play.\n");
	}
	
	printf ("Empty Stacks: adventurer, council_room\n");
	
	G.supplyCount[council_room] = 0;
	if(isGameOver(&G)){
		printf ("FAILED - Game over with 2 empty card stacks.\n");
	} else {
		printf ("PASSED - Game still in play.\n");
	}
	
	printf ("Empty Stacks: adventurer, council_room, treasure_map\n");
	
	G.supplyCount[treasure_map] = 0;
	if(isGameOver(&G)){
		printf ("PASSED - Game over with 3 empty card stacks.\n");
	} else {
		printf ("FAILED - Game still in play with 3 empty card stacks.\n");
	}
	G.supplyCount[treasure_map] = 5;
	
	printf ("Empty Stacks: adventurer, council_room, feast\n");
	G.supplyCount[feast] = 0;
	if(isGameOver(&G)){
		printf ("PASSED - Game over with 3 empty card stacks.\n");
	} else {
		printf ("FAILED - Game still in play with 3 empty card stacks.\n");
	}
	
}

int main(){
	isGameOverTest();
	return 0;
}