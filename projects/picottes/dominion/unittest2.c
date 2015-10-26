#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int main() {
    int i, j, h;
    int seed = 1000;
    int numPlayer = 2;
    int r, returnValue;
    int zeroCard = 0;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};

    struct gameState G;
    printf ("TESTING isGameOver():\n");
    
	for (j = 0; j < 2; j++) {
 	   for (h = 0; h <= 3; h++) {
			zeroCard = 0;
			memset(&G, 23, sizeof(struct gameState));
 		   	r = initializeGame(numPlayer, k, seed, &G);
			#if (NOISY_TEST == 1)
 	           printf("Test state with %d province cards and %d supply piles at 0.\n", j, h+1);
			#endif    
    		G.supplyCount[province] = j;
    		for (i = 0; i < h; i++) {
    		   G.supplyCount[i] = 0;
    		   zeroCard++;
    		}
    		returnValue = isGameOver(&G);
			#if (NOISY_TEST == 1)
     	       printf("G.supplyCount[province] = %d, expected = %d\n", G.supplyCount[province], j);
    	       printf("Number of empty card types = %d\n", zeroCard+1);
    	       printf("Game Over Value = %d\n\n", returnValue);
			#endif
        	if (G.supplyCount[province] == 0 || zeroCard == 3) {
				assert(returnValue == 1);
			}
			else {
			    assert(returnValue == 0);
			}
		}
	}

	printf("All tests passed!\n");
    return 0;
}
