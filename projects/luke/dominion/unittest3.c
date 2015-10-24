//This unit test will test the shuffle() function.

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

	printf("Test shuffle() function:\n");

	srand(time(NULL));
	int numberPlayer = 2;
	int player1 = 0;
	int randomSeed = rand() % 1000 + 1;
	int i;
	int deck[5];
	int k[10] = {adventurer, council_room, feast, gardens, mine,
				 remodel, smithy, village, baron, great_hall};
	struct gameState G;


	//Clear the game state
	memset(&G, 23, sizeof(struct gameState));

	//initialize game
	initializeGame(numberPlayer, k, randomSeed, &G);

	deck[0]=1;
	deck[1]=5;
	deck[2]=8;
	deck[3]=9;
	deck[4]=4;

	memcpy(G.hand[player1], deck, sizeof(int)*5);

	int savedOldDeck[5];

	printf("****************************************************\n");
	printf("Test if deck as been shuffled\n");
	printf("****************************************************\n");

	for(i=0; i<G.deckCount[player1]; i++) {
		
		savedOldDeck[i]=G.deck[player1][i];
		printf("OLD DECK %d\n", G.deck[player1][i]);

	}

	shuffle(player1, &G);

	for(i=0; i<G.deckCount[player1]; i++) {
		
		printf("NEW DECK %d\n", G.deck[player1][i]);
	}

	if ((G.deck[player1][0] != savedOldDeck[0]) || (G.deck[player1][1] != savedOldDeck[1]) || 
		(G.deck[player1][2] != savedOldDeck[2]) || (G.deck[player1][3] != savedOldDeck[3]) || 
		(G.deck[player1][4] != savedOldDeck[4])) {
		printf("This deck has been shuffled.\n");
		printf("TEST PASSED\n");
	} else {
		printf("TEST FAILED\n");
	}

	
	return 0;
	 


}