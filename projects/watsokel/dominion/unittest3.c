/* -----------------------------------------------------------------------
* Programmed by: Kelvin Watson
* Filename: unittest3.c
* Created: 10 Oct 2015
* Last modified: 21 Oct 2015
* Description: Unit tests for dominion.c 's isGameOver() function
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

int checkIsGameOver(struct gameState *state){
	return isGameOver(state);
}

int main() {
	int i,r;
	int seed = 1000;
	int numPlayer = 2;
	int k[10] = {adventurer, council_room, feast, gardens, mine
		, remodel, smithy, village, baron, great_hall};
	struct gameState G;
	// arrays of all coppers, silvers, and golds
	int coppers[MAX_HAND];
	int silvers[MAX_HAND];
	int golds[MAX_HAND];
	for (i = 0; i < MAX_HAND; i++)
	{
		coppers[i] = copper;
		silvers[i] = silver;
		golds[i] = gold;
	}
	int errFlag=0;
	int gameOver;
	
	printf ("TESTING isGameOver():\n");

	//printf("Test player %d with %d treasure card(s) and %d bonus.\n", p, handCount, bonus);
	memset(&G, 23, sizeof(struct gameState));   // clear the game state
	r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
	for(i=7; i>=-1; i--){
		G.supplyCount[province]--;
		printf("  Testing province count=%d\n",G.supplyCount[province]);
		gameOver = isGameOver(&G);
		if(i!=0){
			if(gameOver != 0){
				printf("    isGameOver(): FAIL, gameOver=%d, expected=%d\n",isGameOver(&G),0);
				errFlag++;
			} else{
				printf("    isGameOver(): PASS, gameOver=%d, expected=%d\n",isGameOver(&G),0);   
			}
		}else{
			if(gameOver != 1){
				printf("    isGameOver(): FAIL, gameOver=%d, expected=%d\n",isGameOver(&G),1);
				errFlag++;
			} else{
				printf("    isGameOver(): PASS, gameOver=%d, expected=%d\n",isGameOver(&G),1);   
			}            
		}     
	}
	

	memset(&G, 23, sizeof(struct gameState));   // clear the game state
	r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
	/* Deplete supply one at a time and test gameOver status */
	for(i=0; i<3; i++){
		printf("  Testing depletion of %d supply counts",i+1);
		if(i==0){
			G.supplyCount[copper]=0;
			gameOver = isGameOver(&G);
			if(gameOver==1){
				printf("    isGameOver(): FAIL, gameOver=%d, expected=%d\n",isGameOver(&G),0);
				errFlag++;
			} else{
				printf("    isGameOver(): PASS, gameOver=%d, expected=%d\n",isGameOver(&G),0);   	
			}
		}
		else if(i==1){
			G.supplyCount[silver]=0;  
			gameOver = isGameOver(&G);
			if(gameOver==1){
				printf("    isGameOver(): FAIL, gameOver=%d, expected=%d\n",isGameOver(&G),0);
				errFlag++;
			} else{
				printf("    isGameOver(): PASS, gameOver=%d, expected=%d\n",isGameOver(&G),0);   	
			}
		}else{
			G.supplyCount[gold]=0;
			gameOver = isGameOver(&G);
			if(gameOver==0){
				printf("    isGameOver(): FAIL, gameOver=%d, expected=%d\n",isGameOver(&G),1);
				errFlag++;
			} else{
				printf("    isGameOver(): PASS, gameOver=%d, expected=%d\n",isGameOver(&G),1);   	
			}
		}
	}     

	if(errFlag != 0){
		printf("Some tests failed. See bug1.c for details.\n");  
	}else{
		printf("All tests passed!\n");
	}
	return 0;
}