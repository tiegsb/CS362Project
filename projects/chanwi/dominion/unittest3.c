/* Unit Test 3 - scoreFor()

*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"

void scoreForTest()
{
	int seed = 1000;
	int numPlayer = 2;
	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    struct gameState G;
	int cardCount = 5;
	int cardsInHand[cardCount];
	int cardsInDeck[cardCount];
	int cardsInDiscard[cardCount];
	int player = 0;
	int victoryPoints = 0;
	
	initializeGame(numPlayer, k, seed, &G);
	G.handCount[player] = cardCount;
	
	printf ("Hand: province, estate, duchy, village, gardens\n");
	cardsInHand[0] = province;
    cardsInHand[1] = estate;
	cardsInHand[2] = duchy;
	cardsInHand[3] = village;
	cardsInHand[4] = gardens;
	
	memcpy(G.hand[player], cardsInHand, sizeof(int) * cardCount);
	victoryPoints = scoreFor(player, &G);
	
	if (victoryPoints == 10){
		printf ("PASSED - Victory Total equals 10\n");
	} else {
		printf ("FAILED - Victory Total equals %d\n", victoryPoints);
	}
	
	G.deckCount[player] = cardCount;
	printf ("Hand: province, estate, duchy, village, gardens\n");
	printf ("Deck: estate, estate, estate, duchy, duchy\n");
	cardsInDeck[0] = estate;
	cardsInDeck[1] = estate;
	cardsInDeck[2] = estate;
	cardsInDeck[3] = duchy;
	cardsInDeck[4] = duchy;
	
	memcpy(G.deck[player], cardsInDeck, sizeof(int) * cardCount);
	victoryPoints = scoreFor(player, &G);
	
	if (victoryPoints == 19){
		printf ("PASSED - Victory Total equals 19\n");
	} else {
		printf ("FAILED - Victory Total equals %d\n", victoryPoints);
	}
	
	G.discardCount[player] = cardCount;
	printf ("Hand: province, estate, duchy, village, gardens\n");
	printf ("Deck: estate, estate, estate, duchy, duchy\n");
	printf ("Discard: estate, estate, copper, copper, copper\n");
	cardsInDiscard[0] = estate;
	cardsInDiscard[1] = estate;
	cardsInDiscard[2] = copper;
	cardsInDiscard[3] = copper;
	cardsInDiscard[4] = copper;
	
	memcpy(G.discard[player], cardsInDiscard, sizeof(int) * cardCount);
	victoryPoints = scoreFor(player, &G);
	
	if (victoryPoints == 21){
		printf ("PASSED - Victory Total equals 21\n");
	} else {
		printf ("FAILED - Victory Total equals %d\n", victoryPoints);
	}
	
}

int main(){
	scoreForTest();
	return 0;
}