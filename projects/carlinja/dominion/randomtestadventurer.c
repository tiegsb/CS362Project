
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <time.h>





void tempAdventurer(struct gameState *state)
{
	int z = 0;
	int currentPlayer = whoseTurn(state);
	int temphand[MAX_HAND];
	int cardDrawn;
	int drawntreasure = 0;

	while (drawntreasure <= 2) {
		if (state->deckCount[currentPlayer] <1) {//if the deck is empty we need to shuffle discard and add to deck
			shuffle(currentPlayer, state);
		}
		drawCard(currentPlayer, state);
		cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer] - 1];//top card of hand is most recently drawn card.
		if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
			drawntreasure++;
		else {
			temphand[z] = cardDrawn;
			state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
			z++;
		}
	}
	while (z - 1 >= 0) {
		state->discard[currentPlayer][state->discardCount[currentPlayer]++] = temphand[z - 1]; // discard all cards in play that have been drawn
		z = z - 1;
	}
	return 0;
}
//Int testAdventure()
//Pre: None;
//Post: returns number of failures, as an int
//Desc: Runs my tests with the adventure card. Returns number of failures

int testAdventurer()
{


	int i;
	int seed = 1000;
	int numPlayer = 2;
	int maxBonus = 10;
	int k[10] = { adventurer, council_room, feast, gardens, mine
		, remodel, smithy, village, baron, great_hall };
	int testPlayer = 1;
	int handCount = 5;
	int testerCard = 0;
	int correctTesterCard = 0;
	
	//initialize gamestate
	struct gameState G;


	//loading hand with 5 cards first, hardcoded in

	int firstHand[5];

	//place specific cards in each possible spot

	firstHand[0] = copper;
	firstHand[1] = silver;
	firstHand[2] = gold;
	firstHand[3] = smithy;
	firstHand[4] = adventurer;


	initializeGame(numPlayer, k, seed, &G);

	//set specifics for new game state

	G.handCount[testPlayer] = handCount;

	//place cards in test player's hand

	memcpy(G.hand[testPlayer], firstHand, sizeof(int) * handCount);
	//now going to test various deckcounts and go into adventurer function
	for (i = 0; i < 50; i++) {
		G.deckCount[testPlayer] = rand() % 10 + 5;
		testerCard = G.deckCount[testPlayer];
		correctTesterCard = testerCard + 2;
		tempAdventurer(&G);

		if (G.deckCount[testPlayer] == correctTesterCard)
		{
			printf("Passed. Expected %d, got %d\n", correctTesterCard, G.deckCount[testPlayer]);
		}
		else if (G.deckCount[testPlayer] == testerCard)
		{
			printf("Failed. No cards added. Expected %d, got %d\n", correctTesterCard, G.deckCount[testPlayer]);
		}
		else
			printf("Failed. Expected %d, got %d\n", correctTesterCard, G.deckCount[testPlayer]);
	}




}

int main()
{
	srand(time(NULL));
	testAdventurer();

	return 0;
}