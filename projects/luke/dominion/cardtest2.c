//test adventurer card

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <time.h>

int main() {

	srand(time(NULL));
	int numberPlayer = 2;
	int player1 = 0;
	int randomSeed = rand() % 1000 + 1;
	int k[10] = {adventurer, council_room, feast, gardens, mine,
				 remodel, smithy, village, baron, great_hall};
	struct gameState G;
	int temphand[MAX_HAND];
	int drawntreasure=0;
	int cardDrawn=0;
	int newDiscardCnt;
	int newHandCnt;
	int i;

	//expect a 'healthy card' to reveal cards from deck until 2 Treasure cards are hit.
	//then put those card in your hand and discard the other revealed cards.

	//1) Test that 2 cards (1 card gained in hand because of this one played)
	// are accumulated in hand and all other cards are discarded.

	int discardCnt;
	int handCount;

	//Clear the game state
	memset(&G, 23, sizeof(struct gameState));

	//initialize game
	initializeGame(numberPlayer, k, randomSeed, &G);

	discardCnt=G.discardCount[player1];
	handCount=G.handCount[player1];

	adventurerCard(temphand, 0, cardDrawn, player1, drawntreasure, &G);

	newDiscardCnt=G.deckCount[player1];
	newHandCnt=G.handCount[player1];

	printf("OLD HAND CNT: %d\n", handCount);
	printf("NEW HAND CNT: %d\n", newHandCnt);

	if(newDiscardCnt != discardCnt) {
		printf("Discard test successful.\n");
	} else {
		printf("Discard test failed.\n");
	}

	if(newHandCnt == (handCount+1)) {
		printf("Hand count test successful.\n");
	} else {
		printf("Hand count test failed.\n");
	}

	//check the number of drawn treasure and make sure it's 2
	// if(drawntreasure == 2) {
	// 	printf("Correct number of treasure drawn.\n");
	// } else {
	// 	printf("Wrong number of treasure drawn.\n");
	// }

	//2)check to see if the last added cards in the hand are indeed treasures

	// //Clear the game state
	// memset(&G, 23, sizeof(struct gameState));

	// //initialize game
	// initializeGame(numberPlayer, k, randomSeed, &G);

	int newestCard1;
	int newestCard2;

	newestCard1=G.hand[player1][G.handCount[player1]-1];
	newestCard2=G.hand[player1][G.handCount[player1]-2];

	//Tresure cards are: copper=4, silver=5, gold=6
	printf("NEW CARD 1 is %d\n", newestCard1);
	printf("NEW CARD 2 is %d\n", newestCard2);

	for(i=0; i<G.handCount[player1]; i++) {
		printf("CARDS IN HAND: %d\n", G.hand[player1][i]);
	}







}