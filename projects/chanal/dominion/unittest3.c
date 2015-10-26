/***********************************************************************
* Author : Allan Chan
* ONID: chanal
* Class: CS362
* Filename: unittest3.c
*
* Description:
*   Unit Test 3 that tests the shuffle() function.
*	Testing two decks of 5 for player 1 and player 2.
*	Player 1's deck should shuffle and not Player 2's deck.
*	
*
************************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <time.h>

//set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int main(){
	srand(time(NULL));
	int gameSeed = rand() % 1000 + 1;
	int i;
	int numPlayer = 2;
	int handCount = 5;
	int deck1Shuffle = 0;
	int deck2Shuffle = 0;
	int k[10] = {adventurer, council_room, feast, gardens, mine,
				 remodel, smithy, village, baron, great_hall};

	/*Load deck with cards*/
	int deck1[5] = {adventurer, province, feast, copper, gold};
	int deck2[5] = {smithy, silver, copper, gold, adventurer};
	int deck1Copy[5];
	int deck2Copy[5];
	struct gameState G;

	/*Clear the game state*/
	memset(&G, 23, sizeof(struct gameState));

	/*Initialize the game*/
	initializeGame(numPlayer, k, gameSeed, &G);

	/*Set cards to , player 1 = [0], player 2 = [1]*/
	memcpy(G.deck[0], deck1, sizeof(int)*handCount);
	memcpy(G.deck[1], deck2, sizeof(int)*handCount);
	G.handCount[0] = G.handCount[1] = handCount;

	/*Copy both decks*/
	for(i = 0; i < handCount; i++) {
		deck1Copy[i] = G.deck[0][i];
		deck2Copy[i] = G.deck[1][i];
	}


#if (NOISY_TEST == 1)
	printf("Test, Deck 1 shuffle\n");
#endif

	//Before shuffle
	printf("Player 0's deck before shuffle: %d, %d, %d, %d, %d \n", G.deck[0][0], G.deck[0][1], G.deck[0][2], G.deck[0][3], G.deck[0][4]);
	printf("Player 1's deck before shuffle: %d, %d, %d, %d, %d \n", G.deck[1][0], G.deck[1][1], G.deck[1][2], G.deck[1][3], G.deck[1][4]);

	//Shuffle Player 1's deck [0]
	//assert(shuffle(0, &G) == 0);	//commented out assertions
	shuffle(0, &G);

	//After shuffle
	printf("Player 0's deck after shuffle: %d, %d, %d, %d, %d \n", G.deck[0][0], G.deck[0][1], G.deck[0][2], G.deck[0][3], G.deck[0][4]);
	printf("Player 1's deck after shuffle: %d, %d, %d, %d, %d \n", G.deck[1][0], G.deck[1][1], G.deck[1][2], G.deck[1][3], G.deck[1][4]);


	for(i = 0; i < handCount; i++){
		if(G.deck[0][i] == deck1Copy[i]){
			deck1Shuffle++;	//Increment if card same position
		}
		if(G.deck[1][i] != deck2Copy[i]){
			deck2Shuffle++;	//Should not increment since Player 2's deck should not have shuffled
		}
	}

	assert(deck1Shuffle <= 4); //Shuffled cards can be in the same position for a deck of 5 cards
	assert(deck2Shuffle == 0); //Deck 2 should not have shuffled and should have cards in same position

#if (NOISY_TEST == 1)
	printf( "Deck 1 has %d cards in same position after shuffle, can be <= 4\n", deck1Shuffle);
	printf( "Deck 2 has %d cards in a different position, should not have shuffled\n", deck2Shuffle);
	if(deck1Shuffle <= 4 && deck2Shuffle == 0) {
		printf( "Test PASSED\n\n");
	} else {
		printf( "Test FAILED\n\n");
	}
#endif

	return 0;
}