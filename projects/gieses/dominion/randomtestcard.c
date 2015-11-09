#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define NOISY_TEST 0

//test smithyCard function
int main(){
	int i, j;
	int numPlayers = 2;
	int p = 0;
	int seed = 1000;
	int k[10] = {adventurer, council_room, feast, gardens, mine
	           , remodel, smithy, village, baron, great_hall};
	struct gameState G;
	int cardFailedHand = 0;
	int cardFailedDiscard = 0;
	int cardFailedPlayed = 0;
	srand(time(NULL));
	int randomNum;
	
	memset(&G, 23, sizeof(struct gameState));
	
	for(i = 0; i < 500; i++){
		initializeGame(numPlayers, k, seed, &G);
		
		//randomize how many cards are in players hand, always having at least 1 smithy card
		G.handCount[p] = rand() % 11 + 1;
		#if (NOISY_TEST == 1)
		printf("Hand count is: %d\n", G.handCount[p]);
		#endif
		
		//randomize how many cards are in discard pile, pile can be zero
		G.discardCount[p] = rand() % 11;
		#if (NOISY_TEST == 1)
		printf("Discard count is: %d\n", G.discardCount[p]);
		#endif
		
		int preHand = G.handCount[p];
		int preDiscard = G.discardCount[p];
		
		//add smithy card to ensure it is used
		G.hand[p][0] = 13;
		
		//randomly insert cards into player pile
		for (j = 1; j < G.handCount[p]; j++){
			randomNum = rand() % 10;
			#if (NOISY_TEST == 1)
			printf("Random number for hand: %d\n", randomNum);
			#endif
			G.hand[p][i] = k[randomNum];
			#if (NOISY_TEST == 1)
			printf("Hand card: %d and kingdom card: %d\n", G.hand[p][i], k[randomNum]);
			#endif
		}
		
		//randomly insert cards into discard pile
		for (j = 0; j < G.discardCount[p]; j++){
			randomNum = rand() % 10;
			#if (NOISY_TEST == 1)
			printf("Random number for discard: %d\n", randomNum);
			#endif
			G.discard[p][i] = k[randomNum];
			#if (NOISY_TEST == 1)
			printf("Discard card: %d and kingdom card: %d\n", G.discard[p][i], k[randomNum]);
			#endif
		}
		
		#if (NOISY_TEST == 1)
		printf("Pre player hand count: %d\n", preHand);
		printf("Pre player discard count: %d\n", preDiscard);
		printf("Pre played card count: %d\n", G.playedCardCount);
		#endif
		
		smithyCard(&G, 0);
		
		#if (NOISY_TEST == 1)
		printf("Post player hand count: %d\n", G.handCount[p]);
		printf("Post player discard count: %d\n", G.discardCount[p]);
		printf("Post played card count: %d\n", G.playedCardCount);
		#endif
		
		//pre hand + 3 should be the same as the hand after the card is played
		//since we gain 3 cards playing the smithy card
		if(preHand + 3 == G.handCount[p]){	
			#if (NOISY_TEST == 1)
			printf("Test passed!\n");
			#endif
		}else{
			#if (NOISY_TEST == 1)
			printf("Test failed!\n");
			#endif
			cardFailedHand++;
		}
		
		//pre discard count - 3 should be the same as the discard count after
		//the card is played since the player gains 3 cards
		if(preDiscard - 3 == G.discardCount[p]){
			#if (NOISY_TEST == 1)
			printf("Test passed!\n");
			#endif
		}else{
			#if (NOISY_TEST == 1)
			printf("Test failed!\n");
			#endif
			cardFailedDiscard++;
		}
		
		//the played card should be set to 1 since it is the only card we play
		if(G.playedCardCount != 1){
			#if (NOISY_TEST == 1)
			printf("Test failed!\n");
			#endif
			cardFailedPlayed++;			
		}else{
			#if (NOISY_TEST == 1)
			printf("Test passed!\n");
			#endif
		}
	}
	
	#if (NOISY_TEST == 1)
	printf("Card failed hand %d/500, discard %d/500, and played %d/500.\n", cardFailedHand, cardFailedDiscard, cardFailedPlayed);
	#endif
	
	return 0;
}
    