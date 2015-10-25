#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int main() {
    int i, j, score;
    int seed = 1000;
    int numPlayer = 2;
    int p = 1;
    int r;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};

    struct gameState G;
    printf ("TESTING scoreFor():\n");
    
	for (j = 0; j < 2; j++) {
		memset(&G, 23, sizeof(struct gameState));
 	   	r = initializeGame(numPlayer, k, seed, &G);
 		score = scoreFor(p, &G);
		#if (NOISY_TEST == 1)
 	        printf("Score = %d Should be 0\n", score);
		#endif
		assert(score == 0);
		G.handCount[p] = 6;
		G.discardCount[p] = 6;
		
		G.hand[p][0] = curse;
		G.hand[p][1] = estate;
		G.hand[p][2] = duchy;
		G.hand[p][3] = province;
		G.hand[p][4] = great_hall;
		G.hand[p][5] = gardens;
		for (i = 0; i < 6; i++) {
		    G.discard[p][i] = G.hand[p][i]; 
		    G.deck[p][i] = G.hand[p][i];  
		}
		score = scoreFor(p, &G);
		#if (NOISY_TEST == 1)
 	        printf("Score = %d Should be 30\n", score);
		#endif
		assert(score == 30);  
		
		//drop card
		G.handCount[p] = 5;
		G.discardCount[p] = 5;
		
		G.hand[p][0] = curse;
		G.hand[p][1] = estate;
		G.hand[p][2] = duchy;
		G.hand[p][3] = province;
		G.hand[p][4] = great_hall;

		for (i = 0; i < 5; i++) {
		    G.discard[p][i] = G.hand[p][i]; 
		    G.deck[p][i] = G.hand[p][i];  
		}
		score = scoreFor(p, &G);
		#if (NOISY_TEST == 1)
 	        printf("Score = %d Should be 30\n", score);
		#endif
		assert(score == 30);  
		
		//drop card
		G.handCount[p] = 4;
		G.discardCount[p] = 4;
		
		G.hand[p][0] = curse;
		G.hand[p][1] = estate;
		G.hand[p][2] = duchy;
		G.hand[p][3] = province;

		for (i = 0; i < 4; i++) {
		    G.discard[p][i] = G.hand[p][i]; 
		    G.deck[p][i] = G.hand[p][i];  
		}
		score = scoreFor(p, &G);
		#if (NOISY_TEST == 1)
 	        printf("Score = %d Should be 27\n", score);
		#endif
		assert(score == 27); 
		
		//drop card
		G.handCount[p] = 3;
		G.discardCount[p] = 3;
		
		G.hand[p][0] = curse;
		G.hand[p][1] = estate;
		G.hand[p][2] = duchy;

		for (i = 0; i < 3; i++) {
		    G.discard[p][i] = G.hand[p][i]; 
		    G.deck[p][i] = G.hand[p][i];  
		}
		score = scoreFor(p, &G);
		#if (NOISY_TEST == 1)
 	        printf("Score = %d Should be 9\n", score);
		#endif
		assert(score == 9);
		
		//drop card
		G.handCount[p] = 2;
		G.discardCount[p] = 2;
		
		G.hand[p][0] = curse;
		G.hand[p][1] = estate;

		for (i = 0; i < 2; i++) {
		    G.discard[p][i] = G.hand[p][i]; 
		    G.deck[p][i] = G.hand[p][i];  
		}
		score = scoreFor(p, &G);
		#if (NOISY_TEST == 1)
 	        printf("Score = %d Should be 0\n", score);
		#endif
		assert(score == 0);
		
		//drop card
		G.handCount[p] = 1;
		G.discardCount[p] = 1;
		
		G.hand[p][0] = curse;

		for (i = 0; i < 1; i++) {
		    G.discard[p][i] = G.hand[p][i]; 
		    G.deck[p][i] = G.hand[p][i];  
		}
		score = scoreFor(p, &G);
		#if (NOISY_TEST == 1)
 	        printf("Score = %d Should be -3\n", score);
		#endif
		assert(score == -3);      
	}

	printf("All tests passed!\n");
    return 0;
}
