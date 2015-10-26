/* Card Test 1 - Smithy Card

*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include "interface.h"

void smithyTest()
{
	int seed = 1000;
	int numPlayer = 2;
	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    struct gameState G;
	struct gameState S;
	int cardCount = 5;
	int cardsInHand[cardCount];
	int player = 0;
	int player2 = 1;
	int i =0;

	initializeGame(numPlayer, k, seed, &G);
	G.handCount[player] = cardCount;
	
	cardsInHand[0] = smithy;
    cardsInHand[1] = copper;
	cardsInHand[2] = copper;
	cardsInHand[3] = copper;
	cardsInHand[4] = copper;
	
	memcpy(G.hand[player], cardsInHand, sizeof(int) * cardCount);
	printf ("Player 1 - Number of Cards in Hand: %d\n", G.handCount[player]);
	printf ("Player 1 - Number of Cards in Deck: %d\n", G.deckCount[player]);
	printf ("Player 1 - Number of Cards in Discard: %d\n", G.discardCount[player]);
	
	printf ("Player 2 - Number of Cards in Hand: %d\n", G.handCount[player2]);
	printf ("Player 2 - Number of Cards in Deck: %d\n", G.deckCount[player2]);
	printf ("Player 2 - Number of Cards in Discard: %d\n", G.discardCount[player2]);
	
	printf ("Activate Smithy Card\n");
	memcpy(&S, &G, sizeof(struct gameState));
	smithyCard(i, player, 0, &G);
	
	if(G.handCount[player] == 7){
		printf ("PASS - Player 1: 7 cards in hand\n");
	} else {
		printf ("FAIL - Player 1: %d cards in hand\n", G.handCount[player]);
	}
	
	if(G.deckCount[player] == 2){
		printf ("PASS - Player 1: 2 cards in deck\n");
	} else {
		printf ("FAIL - Player 1: %d cards in deck\n", G.handCount[player]);
	}
	
	if (G.discardCount[player] > 0){
		printf ("PASS - Player 1: Discard count equals 1\n");
	} else {
		printf ("FAIL - Player 1: Discard count equals %d\n", G.discardCount[player]);
	}
	
	if(G.handCount[player2] == S.handCount[player2]){
		printf ("PASS - Player 2: hand count unchanged\n");
	} else {
		printf ("FAIL - Player 2: hand count changed: %d\n", G.handCount[player2]);
	}
	
	if(G.deckCount[player2] == S.deckCount[player2]){
		printf ("PASS - Player 2: deck count unchanged\n");
	} else {
		printf ("FAIL - Player 2: deck count changed: %d\n", G.deckCount[player2]);
	}
	
	if(G.discardCount[player2] == S.discardCount[player2]){
		printf ("PASS - Player 2: discard count unchanged\n");
	} else {
		printf ("FAIL - Player 2: discard count changed: %d\n", G.discardCount[player2]);
	}
}

int main(){
	smithyTest();
	return 0;
}