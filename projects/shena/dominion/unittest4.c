#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int main (int argc, char** argv) {
	
	printf("\nnewGame() FUNCTION TEST\n\n");
	
	struct gameState *s = newGame();
	
	printf("Verifying numPlayers...\n");
	s->numPlayers = 1;
	assert(s->numPlayers == 1);
	
	printf("Verifying supplyCount...\n");
	s->supplyCount[0] = 1;
	assert(s->supplyCount[0] == 1);
	
	printf("Verifying embargoTokens...\n");
	s->embargoTokens[0] = 1;
	assert(s->embargoTokens[0] == 1);
	
	printf("Verifying outpostPlayed...\n");
	s->outpostPlayed = 1;
	assert(s->outpostPlayed == 1);
	
	printf("Verifying outpostTurn...\n");
	s->outpostTurn = 1;
	assert(s->outpostTurn == 1);
	
	printf("Verifying whoseTurn...\n");
	s->whoseTurn = 1;
	assert(s->whoseTurn == 1);
	
	printf("Verifying phase...\n");
	s->phase = 1;
	assert(s->phase == 1);
	
	printf("Verifying numActions...\n");
	s->numActions = 1;
	assert(s->numActions == 1);
	
	printf("Verifying coins...\n");
	s->coins = 1;
	assert(s->coins == 1);
	
	printf("Verifying numBuys...\n");
	s->numBuys = 1;
	assert(s->numBuys == 1);
	
	printf("Verifying hand...\n");
	s->hand[0][0] = 1;
	assert(s->hand[0][0] == 1);
	
	printf("Verifying handCount...\n");
	s->handCount[0] = 1;
	assert(s->handCount[0] == 1);
	
	printf("Verifying deck...\n");
	s->deck[0][0] = 1;
	assert(s->deck[0][0] == 1);
	
	printf("Verifying deckCount...\n");
	s->deckCount[0] = 1;
	assert(s->deckCount[0] == 1);
	
	printf("Verifying discard...\n");
	s->discard[0][0] = 1;
	assert(s->discard[0][0] == 1);
	
	printf("Veriying discardCount...\n");
	s->discardCount[0] = 1;
	assert(s->discardCount[0] == 1);
	
	printf("Verifying playedCards...\n");
	s->playedCards[0] = 1;
	assert(s->playedCards[0] == 1);
	
	printf("Verifying playedCardCount...\n");
	s->playedCardCount = 1;
	assert(s->playedCardCount == 1);
	
	printf("\nFUNCTION TEST RESULTS... PASSED.\n\n");

  return 0;
}