// Name: Billy Kerns
// File: randomtestadventurer.c
// adventurer

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <time.h>
#include <stdlib.h>

#define NOISY_TEST 0

int checkAdventureRandom(struct gameState *pre, int currentPlayer, int z, int cardDrawn, int n);

int main(){
	struct gameState G;
	int n;
	int p;
	int r;
	int t;
	int cardDrawn;
	int u;
	int turn;
	int addTreasure;
	int errorCount = 0;
	cardDrawn = -1;
	srand(time(NULL));
	enum CARD randomCard[27] = {curse, estate, duchy, province, copper, silver, gold, adventurer, council_room, feast, gardens,
							mine, remodel, smithy, village, baron, great_hall, minion, steward, tribute, ambassador, cutpurse,
							embargo, outpost, salvager, sea_hag, treasure_map};
	int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
	printf("-------------------------Testing Card: Adventurer-------------------------\n\n");
	for(n = 0; n < 5000; n++){
		p = (rand() % (MAX_PLAYERS-1));
		initializeGame(p+1, k, 1000, &G);
		for(t = 0; t < sizeof(struct gameState); t++){//fill gameState with junk
			((char*)&G)[t] = (rand() % (256));
		}
		for(u = 0; u <= p; u++){
			addTreasure = 0;
			G.deckCount[u] = (rand() % (MAX_DECK));//player deckCount = between 0 and MAX_DECK
			G.discardCount[u] = (rand() % (MAX_DECK));//player discardCount = between 0 and MAX_DECK
			G.handCount[u] = (rand() % (MAX_HAND));//player handCount = between 0 and MAX_hand

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
		G.numPlayers = p + 1;
		turn = (rand() % (p+1));
		G.whoseTurn = turn;//random turn
		errorCount += checkAdventureRandom(&G, turn, 0, cardDrawn, n);
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
int checkAdventureRandom(struct gameState *pre, int currentPlayer, int z, int cardDrawn, int n){	
	struct gameState post;
	memcpy (&post, pre, sizeof(struct gameState));
	int i;
	int tempHand[MAX_HAND];
	int t;
	int funErrors = 0;
	int treasure = 0;
	int postTreasure = 0;
	int deckPreTreasure = 0;
	adventureCard(0, &post, currentPlayer, tempHand, z, cardDrawn);	

	for(i = 0; i < pre->handCount[currentPlayer]; i++){
		if(pre->hand[currentPlayer][i]==copper || pre->hand[currentPlayer][i]==gold || pre->hand[currentPlayer][i]==silver){
			treasure++;//get orriginal amount of treasure in hand
		}
	}

	for(i = 0; i < post.handCount[currentPlayer]; i++){
		if(post.hand[currentPlayer][i]==copper || post.hand[currentPlayer][i]==gold || post.hand[currentPlayer][i]==silver){
			postTreasure++;//get amount of treasure after adventure card has been played
		}
	}
	
	for (t=0; t < pre->numPlayers; t++){//check other players' stats to make sure they haven't changed
		if(pre->handCount[t] != post.handCount[t]){
			if(t != currentPlayer){//if it's current player their stuff is probably different
				#if(NOISY_TEST == 1)
				printf("Iteration #: %d	Test 1 failed\n", n);
				printf("Expected: Player %d handCount = %d	Actual: Player %d handCount = %d\n\n", t, pre->handCount[t], t, post.handCount[t]);
				#endif
				funErrors++;
			}
		}
		if(pre->discardCount[t] != post.discardCount[t]){
			if(t != currentPlayer){//check other players discardCount to make sure it wasn't changed
				#if(NOISY_TEST == 1)
				printf("Iteration #: %d	Test 3 failed\n", n);
				printf("Expected: Player %d discardCount = %d	Actual: Player %d discardCount = %d\n\n", t, pre->discardCount[t], t, post.discardCount[t]);
				#endif
				funErrors++;
			}
		}
		if(pre->deckCount[t] != post.deckCount[t]){
			if(t != currentPlayer){//check other players deckCounts to make sure it wasn't changed
				#if(NOISY_TEST == 1)
				printf("Iteration #: %d	Test 4 failed\n", n);
				printf("Expected: Player %d deckCount = %d	Actual: Player %d deckCount = %d\n\n", t, pre->deckCount[t], t, post.deckCount[t]);
				#endif
				funErrors++;
			}
		}
	}
	if(treasure+2 != postTreasure){//possibly not 2 treasure cards in player's deck or discard||||||Won't happen.  I force add two treasure card to deck to prevent very small chance of user having 1 or less treasure cards which causes adverture card to segfault
		for(i=0; i < pre->deckCount[currentPlayer]; i++){
			if(pre->deck[currentPlayer][i]==copper || pre->deck[currentPlayer][i]==silver || pre->deck[currentPlayer][i]==gold){
				deckPreTreasure++;//check to see how many treasure cards are in deck
			}
		}
		for(i=0; i < pre->discardCount[currentPlayer]; i++){
			if(pre->discard[currentPlayer][i]==copper || pre->discard[currentPlayer][i]==silver || pre->discard[currentPlayer][i]==gold){
				deckPreTreasure++;//check to see how many treasure cards are in discard
			}
		}
		if(deckPreTreasure >= 2){//if we found more than two treasure then the fuction did not add two cards to hand even though they were avaiable
			#if(NOISY_TEST == 1)
			printf("Iteration #: %d	Test 6 failed\n", n);
			printf("Expected: pre deck and discard to have less than two treasures	Actual: Pre deck and discard have more than two treasures but were not added to hand\n\n");
			#endif
			funErrors++;
		}
		else if(deckPreTreasure == 1){//if only one treasure is found then player hand count should go up by zero 
			if(post.handCount[currentPlayer] != pre->handCount[currentPlayer]){
				#if(NOISY_TEST == 1)
				printf("Iteration #: %d	Test 7 failed\n", n);
				printf("Expected: handCount = %d	Actual: handCount = %d\n\n", pre->handCount[currentPlayer], post.handCount[currentPlayer]);
				#endif
				funErrors++;
			}
		}
		else if(deckPreTreasure == 0){//No treasure in deck or discard
			if(treasure != postTreasure){//No treasure to add so they should be the same as postTreasure was not incremented
				#if(NOISY_TEST == 1)
				printf("Iteration #: %d	Test 8 failed\n", n);
				printf("Expected: Post treasure = %d	Actual: Post treasure = %d\n\n", treasure, postTreasure);
				#endif
				funErrors++;
			}
		}
	}
	if(pre->deckCount[currentPlayer] == 0 && post.deckCount[currentPlayer] == 0 && deckPreTreasure > 1){//if pre deckCount is zero the then the function should
		#if(NOISY_TEST == 1)									    //add to discard from deck increasing post deckCount if
		printf("Iteration #: %d	Test 9 failed\n", n);						    //two treasure cards are available
		printf("Discard was not add to deck when deckCount = 0\n");
		#endif
		funErrors++;
	}
	if(pre->handCount[currentPlayer]+1 != post.handCount[currentPlayer] && treasure + 2 == postTreasure){//check that card was discarded
		#if(NOISY_TEST == 1)
		printf("Iteration #: %d	Test 10 failed\n", n);
		printf("Expected: Post handCount = %d	Actual: Post handCount = %d\n\n", pre->handCount[currentPlayer] + 1, post.handCount[currentPlayer]);
		#endif
		funErrors++;
	}
	return funErrors;
}
