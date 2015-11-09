// Name: Billy Kerns
// File: randomtestcard.c
// village

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <time.h>
#include <stdlib.h>

#define NOISY_TEST 0

int checkVillageRandom(struct gameState *pre, int currentPlayer, int handPos, int n);

int main(){
	struct gameState G;
	int n;
	int p;
	int r;
	int t;
	int cardDrawn;
	int u;
	int turn;
	int errorCount = 0;
	cardDrawn = -1;
	srand(time(NULL));
	enum CARD randomCard[27] = {curse, estate, duchy, province, copper, silver, gold, adventurer, council_room, feast, gardens,
							mine, remodel, smithy, village, baron, great_hall, minion, steward, tribute, ambassador, cutpurse,
							embargo, outpost, salvager, sea_hag, treasure_map};
	int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
	printf("-------------------------Testing Card: Village-------------------------\n\n");
	for(n = 0; n < 5000; n++){
		p = (rand() % (MAX_PLAYERS-1));
		initializeGame(p+1, k, 1000, &G);
		for(t = 0; t < sizeof(struct gameState); t++){//fill gameState with junk
			((char*)&G)[t] = (rand() % (256));
		}
		for(u = 0; u <= p; u++){//fill each player
			G.deckCount[u] = (rand() % (MAX_DECK));//deck count = between 0 and MAX_DECK
			G.discardCount[u] = (rand() % (MAX_DECK));//discardCount = between 0 and MAX_DECK
			G.handCount[u] = (rand() % (MAX_HAND))+1;//handCount = between 0 and MAX_HAND

			for(r = 0; r < G.deckCount[u]; r++){
				int randomInt = (rand() % (26));
				G.deck[u][r] = randomCard[randomInt];//player deck at r = random card
			}
			for(r = 0; r < G.discardCount[u]; r++){
				int randomInt = (rand() % (26));
				G.discard[u][r] = randomCard[randomInt];//player discard at r = random card
			}
			for(r = 0; r < G.handCount[u]; r++){
				int randomInt = (rand() % (26));
				G.hand[u][r] = randomCard[randomInt];//player hand at r = random card
			}
		}
		G.playedCardCount = (rand() % (MAX_DECK-3));
		G.numActions = (rand() % (11));
		G.numPlayers = p + 1;
		turn = (rand() % (p+1));
		G.whoseTurn = turn;
		errorCount += checkVillageRandom(&G, turn, G.handCount[turn]-1, n);
	}
	if(errorCount != 0){
		#if(NOISY_TEST != 1)
		printf("At least 1 test failed.  Define NOISY_TEST to 1 for more information\n");
		printf("Total Test Runs: %d\n", n);
		printf("Passing Tests: %d\n", n - errorCount);
		printf("Failed Tests: %d\n", errorCount);
		#endif
	}
	else {
		printf("All tests passed\n");
	}
	return 0;
}

int checkVillageRandom(struct gameState *pre, int currentPlayer, int handPos, int n){
	struct gameState post;
	memcpy (&post, pre, sizeof(struct gameState));
	int bonus = 0;
	int t;
	int funErrors = 0;
	cardEffect(village, -1, -1, -1, &post, handPos, &bonus);
	if(pre->handCount[currentPlayer] != post.handCount[currentPlayer]){//gain one card but should lose the village card 
		#if(NOISY_TEST == 1)
		printf("Iteration # %d	Test 1 failed\n", n);
		printf("Expected: cardCount = %d	Actual: cardCount = %d\n\n", pre->handCount[currentPlayer], post.handCount[currentPlayer]);
		#endif
		funErrors++;
	}
	if(pre->numActions + 2 != post.numActions){//Should have 2 more actions than original
		#if(NOISY_TEST == 1)
		printf("Iteration # %d	Test 2 failed\n", n);
		printf("Expected: numActions = %d	Actual: numActionst = %d\n\n", pre->numActions + 2, post.numActions);
		#endif
		funErrors++;
	}
	if(pre->discardCount[currentPlayer] + 1 != post.discardCount[currentPlayer]){//discardCount should be incremented
		#if(NOISY_TEST == 1)
		printf("Iteration # %d	Test 3 failed\n", n);
		printf("Expected: discardCount = %d	Actual: discardCount = %d\n\n", pre->discardCount[currentPlayer] + 1, post.discardCount[currentPlayer]);
		#endif
		funErrors++;
	}
	if(post.hand[currentPlayer][post.handCount[currentPlayer]-1] != pre->deck[currentPlayer][pre->deckCount[currentPlayer]-1] && pre->deckCount[currentPlayer] > 0){
		#if(NOISY_TEST == 1)//Card drawn should be last card in deck unless deck was shuffled
		printf("Iteration # %d	Test 7 failed\n", n);
		printf("Expected: drawn card = %d	Actual: drawn card = %d\n\n", pre->deck[currentPlayer][pre->deckCount[currentPlayer]-1], post.hand[currentPlayer][post.handCount[currentPlayer]-1]);
		#endif
		funErrors++;
	}
	for (t=0; t < pre->numPlayers; t++){//check other players' stuff
		if(pre->handCount[t] != post.handCount[t]){
			if(t != currentPlayer){//if current player then it's probably different
				#if(NOISY_TEST == 1)
				printf("Iteration #: %d	Test 4 failed\n", n);
				printf("Expected: Player %d handCount = %d	Actual: Player %d handCount = %d\n\n", t, pre->handCount[t], t, post.handCount[t]);
				#endif
				funErrors++;
			}
		}
		if(pre->discardCount[t] != post.discardCount[t]){
			if(t != currentPlayer){
				#if(NOISY_TEST == 1)
				printf("Iteration # %d	Test 5 failed\n", n);
				printf("Expected: Player %d discardCount = %d	Actual: Player %d discardCount = %d\n\n", t, pre->discardCount[t], t, post.discardCount[t]);
				#endif
				funErrors++;
			}
		}
		if(pre->deckCount[t] != post.deckCount[t]){
			if(t != currentPlayer){
				#if(NOISY_TEST == 1)
				printf("Iteration # %d	Test 6 failed\n", n);
				printf("Expected: Player %d deckCount = %d	Actual: Player %d deckCount = %d\n\n", t, pre->deckCount[t], t, post.deckCount[t]);
				#endif
				funErrors++;
			}
		}
	}
	return funErrors;
}
