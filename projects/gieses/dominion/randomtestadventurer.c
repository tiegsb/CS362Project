#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define NOISY_TEST 0

//test adventurer function
int main(){
	int i, j;
	int numPlayers = 2;
	int p = 0;
	int seed = 1000;
	int k[10] = {adventurer, council_room, feast, gardens, mine
	           , remodel, smithy, copper, gold, silver};
	struct gameState G;
	int cardFailedHand = 0;
	int cardFailedDiscard = 0;
	int cardFailedPlayed = 0;
	srand(time(NULL));
	int randomNum;
	int countTreasure;
	
	memset(&G, 23, sizeof(struct gameState));
	
	for(i = 0; i < 500; i++){
		initializeGame(numPlayers, k, seed, &G);
		
		//reset treasure count
		countTreasure = 0;
		
		//randomize how many cards are in players hand, always having at least 1 adventurer card
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
		
		//add adventurer card to ensure it is used
		G.hand[p][0] = 7;
		
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
		printf("Pre player hand count: %d\n", G.handCount[p]);
		printf("Pre player discard count: %d\n", G.discardCount[p]);
		printf("Pre discard count: %d\n", G.discardCount[p]);
		#endif
		
		adventurerCard(&G);
	
		#if (NOISY_TEST == 1)
		printf("Post player hand count: %d\n", G.handCount[p]);
		printf("Post player discard count: %d\n", G.discardCount[p]);
		printf("Post discard count: %d\n", G.discardCount[p]);
		#endif
	
		//check last card added to player hand
		if(G.hand[p][G.handCount[p] - 1] == copper || G.hand[p][G.handCount[p] - 1] == silver || G.hand[p][G.handCount[p] - 1] == gold){
			#if (NOISY_TEST == 1)
			printf("Found a card!\n");
			countTreasure++;
			#endif
		}else{
			#if (NOISY_TEST == 1)
			printf("Didn't find a card!\n");
			#endif
		}
		
		//check second to last card added to player hand
		if(G.hand[p][G.handCount[p] - 2] == copper || G.hand[p][G.handCount[p] - 2] == silver || G.hand[p][G.handCount[p] - 2] == gold){
			#if (NOISY_TEST == 1)
			printf("Found a card!\n");
			countTreasure++;
			#endif
		}else{
			#if (NOISY_TEST == 1)
			printf("Didn't find a card!\n");
			#endif
		}
		
		//pre hand should be no more than the hand + 2 after the card is played 
		//since we gain at most 2 cards
		if(preHand <= G.handCount[p] + 2){	
			#if (NOISY_TEST == 1)
			printf("Test passed!\n");
			#endif
		}else{
			#if (NOISY_TEST == 1)
			printf("Test failed!\n");
			#endif
			cardFailedHand++;
		}
		
		//pre discard count should equal or greater than the discard pile
		//after the card is played
		if(preDiscard >= G.discardCount[p] - 2){
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
		
		//check if the number of treasure cards added is correct
		if(countTreasure >= 0 && countTreasure <= 2){
			#if (NOISY_TEST == 1)
			printf("Test passed!\n");
			printf("Card count: %d\n", countTreasure);
			#endif		
		}else{
			#if (NOISY_TEST == 1)
			printf("Test failed!\n");
			printf("Card count: %d\n", countTreasure);
			#endif
		}
	}
	
	#if (NOISY_TEST == 1)
	printf("Card failed hand %d/500, discard %d/500, and played %d/500.\n", cardFailedHand, cardFailedDiscard, cardFailedPlayed);
	#endif
	
	return 0;
}