/* Card Test 3 - Village Card

*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include "interface.h"

void villageTest()
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

	initializeGame(numPlayer, k, seed, &G);
	G.handCount[player] = cardCount;
	G.numActions = 1;
	
	cardsInHand[0] = village;
    cardsInHand[1] = copper;
	cardsInHand[2] = copper;
	cardsInHand[3] = copper;
	cardsInHand[4] = copper;
	
	memcpy(G.hand[player], cardsInHand, sizeof(int) * cardCount);
	printf ("Player 1 - Number of Cards in Hand: %d\n", G.handCount[player]);
	printf ("Player 1 - Number of Cards in Deck: %d\n", G.deckCount[player]);
	printf ("Player 1 - Number of Cards in Discard: %d\n", G.discardCount[player]);
	printf ("Player 1 - Number of Actions: %d\n", G.numActions);
	
	printf ("Player 2 - Number of Cards in Hand: %d\n", G.handCount[player2]);
	printf ("Player 2 - Number of Cards in Deck: %d\n", G.deckCount[player2]);
	printf ("Player 2 - Number of Cards in Discard: %d\n", G.discardCount[player2]);
	
	printf ("Activate Village Card\n");
	memcpy(&S, &G, sizeof(struct gameState));
	villageCard(player, 0, &G);
	G.numActions = G.numActions - 1;
	
	if(G.handCount[player] == 5){
		printf ("PASS - Player 1: 5 cards in hand\n");
	} else {
		printf ("FAIL - Player 1: %d cards in hand\n", G.handCount[player]);
	}
	
	if(G.deckCount[player] == 4){
		printf ("PASS - Player 1: 4 cards in deck\n");
	} else {
		printf ("FAIL - Player 1: %d cards in deck\n", G.handCount[player]);
	}
	
	if (G.discardCount[player] == 1){
		printf ("PASS - Player 1: Discard count equals 1\n");
	} else {
		printf ("FAIL - Player 1: Discard count equals %d\n", G.discardCount[player]);
	}
	
	if (G.numActions == 2){
		printf ("PASS - Player 1: Number of Actions equal to 2\n");
	} else {
		printf ("FAIL - Player 1: Number of Actions equal to %d\n", G.numActions);
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
	villageTest();
	return 0;
}