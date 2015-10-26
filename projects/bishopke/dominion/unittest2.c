// Keenan Bishop
// unittest2.c
// isGameOver() test
// from template

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
//#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 0

void test_isGameOver(){
	int i;
	int seed = 1000;
	int numPlayer = 2; //2 players
	int r; 
	//set kindom cards to a normalish set
	int k[10] = {adventurer, council_room, feast, gardens, mine,
			 remodel, smithy, village, baron, great_hall};
	struct gameState G;

	printf ("TESTING isGameOver():\n");
	//Game end states:
	//all province cards are bought/gone
	//any 3 piles are depleted

	//initialize a new game for testing
	r = initializeGame(numPlayer, k, seed, &G);

	//initial test should return 0, as game should not be over at the beginning
	if(isGameOver(&G)){
		printf("FAIL: isGameOver(): post-game initialization\n");
	}
	else{
		printf("PASS: isGameOver(): post-game initialization\n");
	}
	
	//Emptying the supply of Province Cards should end the game
	//testing 0 to 8 (two players amount)
	for(i = 0; i < 9; i++){
		G.supplyCount[province] = i;
		if(i == 0){
			if(isGameOver(&G)){
				printf("PASS: isGameOver(): 0 province cards returned game over state\n");
			}
			else{
				printf("FAIL: isGameOver(): 0 province cards did not return game over state\n");
			}
		}
		else{
			if(!isGameOver(&G)){
				printf("PASS: isGameOver(): %d province cards returned game in progress\n", i);
			}
			else{
				printf("FAIL: isGameOver(): %d province cards returned game over state!\n", i);
			}
		}	
	}

	//test for 3 pile ending, as described here
	//http://wiki.dominionstrategy.com/index.php/Three-pile_ending	

	//1st scenario
	//silver, gold, copper cards all gone		
	memset(&G, 0, sizeof(struct gameState));
	r = initializeGame(numPlayer, k, seed, &G);	

	//deplete copper
	G.supplyCount[copper] = 0;
	if(isGameOver(&G)){
		printf("FAIL: isGameOver(): ended at 1 pile depleted!\n");
	}

	//deplete silver
	G.supplyCount[silver] = 0;
	if(isGameOver(&G)){
		printf("FAIL: isGameOver(): ended at 2 piles depleted!\n");
	}

	//deplete gold
	G.supplyCount[gold] = 0;
	if(isGameOver(&G)){
		printf("PASS: isGameOver(): ended at 3 piles depleted!\n");
	}
	else{
		printf("FAIL: isGameOver(): did not end at 3 piles depleted!\n");
	}

	//2nd scenario
	//3 kingdom card piles depleted
	memset(&G, 0, sizeof(struct gameState));
	r = initializeGame(numPlayer, k, seed, &G);	


	//deplete feast
	G.supplyCount[feast] = 0;
	if(isGameOver(&G)){
		printf("FAIL: isGameOver(): ended at 1 pile depleted!\n");
	}

	//deplete mine
	G.supplyCount[mine] = 0;
	if(isGameOver(&G)){
		printf("FAIL: isGameOver(): ended at 2 piles depleted!\n");
	}

	//deplete baron
	G.supplyCount[baron] = 0;
	if(isGameOver(&G)){
		printf("PASS: isGameOver(): ended at 3 piles depleted!\n");
	}
	else{
		printf("FAIL: isGameOver(): did not end at 3 piles depleted!\n");
	}

	//3rd scenario
	//1 kingdom pile, 1 treasure pile, 1 victory card pile missing
	memset(&G, 0, sizeof(struct gameState));
	r = initializeGame(numPlayer, k, seed, &G);	
	
	//deplete silver
	G.supplyCount[silver] = 0;
	if(isGameOver(&G)){
		printf("FAIL: isGameOver(): ended at 1 pile depleted!\n");
	}

	//deplete mine
	G.supplyCount[mine] = 0;
	if(isGameOver(&G)){
		printf("FAIL: isGameOver(): ended at 2 piles depleted!\n");
	}

	//deplete estate
	G.supplyCount[estate] = 0;
	if(isGameOver(&G)){
		printf("PASS: isGameOver(): ended at 3 piles depleted!\n");
	}
	else{
		printf("FAIL: isGameOver(): did not end at 3 piles depleted!\n");
	}

}

int main(){
	test_isGameOver();
	return 0;
}
