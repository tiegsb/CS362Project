/* Card Test 2 - Adventurer Card

*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include "interface.h"

void adventurerTest()
{
	int seed = 1000;
	int numPlayer = 2;
	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    struct gameState G;
	struct gameState S;
	int cardCount = 5;
	int cardsInHand[cardCount];
	int cardsInDeck[cardCount];
	int player = 0;
	int player2 = 1;
	int bonus = 0;
	
	int drawntreasure = 0;
	int cardDrawn = 0;
	int z = 0;
	int temphand[MAX_HAND];

	initializeGame(numPlayer, k, seed, &G);
	G.handCount[player] = cardCount;
	G.deckCount[player] = cardCount;
	
	cardsInHand[0] = adventurer;
    cardsInHand[1] = estate;
	cardsInHand[2] = estate;
	cardsInHand[3] = estate;
	cardsInHand[4] = copper;
	
	cardsInDeck[0] = copper;
    cardsInDeck[1] = copper;
	cardsInDeck[2] = copper;
	cardsInDeck[3] = copper;
	cardsInDeck[4] = copper;
	
	memcpy(G.hand[player], cardsInHand, sizeof(int) * cardCount);
	memcpy(G.deck[player], cardsInDeck, sizeof(int) * cardCount);
	
	printf ("Player 1 - Number of Cards in Hand: %d\n", G.handCount[player]);
	printf ("Player 1 - Number of Cards in Deck: %d\n", G.deckCount[player]);
	printf ("Player 1 - Number of Cards in Discard: %d\n", G.discardCount[player]);
	
	updateCoins(player, &G, bonus);
	printf ("Player 1 - Coin Total: %d\n", G.coins);
	
	printf ("Player 2 - Number of Cards in Hand: %d\n", G.handCount[player2]);
	printf ("Player 2 - Number of Cards in Deck: %d\n", G.deckCount[player2]);
	printf ("Player 2 - Number of Cards in Discard: %d\n", G.discardCount[player2]);
	
	printf ("Activate Adventurer Card\n");
	memcpy(&S, &G, sizeof(struct gameState));
	adventurerCard(drawntreasure, cardDrawn, player, z, temphand, &G);
	updateCoins(player, &G, bonus);
	
	if(G.handCount[player] == 6){
		printf ("PASS - Player 1: 6 cards in hand\n");
	} else {
		printf ("FAIL - Player 1: %d cards in hand\n", G.handCount[player]);
	}
	
	if(G.deckCount[player] < 5){
		printf ("PASS - Player 1: Less than 5 cards in deck, %d\n", G.deckCount[player]);
	} else {
		printf ("FAIL - Player 1: %d cards in deck\n", G.deckCount[player]);
	}
	
	if (G.discardCount[player] > 0){
		printf ("PASS - Player 1: Discard count equals greater than 0\n");
	} else {
		printf ("FAIL - Player 1: Discard count equals %d\n", G.discardCount[player]);
	}
	
	if (G.coins == (S.coins + 2)){
		printf ("PASS - Player 2: Coin total increased by 2\n");
	} else {
		printf ("FAIL - Player 1: Coin total after two copper drawn: %d\n", G.coins);
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
	adventurerTest();
	return 0;
}