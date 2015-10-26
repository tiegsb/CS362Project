/*
* Card Test 1: Smithy
*
* In this unit test, we will be testing the function playSmithy().
* Smithy is a card that when played, allows the player to draw three cards.
*
* Input: handpos (index where smithy is located), currentPlayer, and state.
* Output: The top three cards from deck should be moved to hand, and smithy should be discarded
* 
* To test that the function does as we ask it to, we will construct random tests that tests for a
* number of hand, deck, and discard piles.  The random number will be constrained to 1/2 the MAX set
* values (500) because there really can only be around 300 cards in play at a time (thus we are not
* concerned with overflowing our hand or deck or discard by testing the extremes in terms of count.
* Obviously this would over run and overwrite values in our struct causing major problems in the game)
*
*/

#include "dominion.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdio.h>

void fuzzState(struct gameState *);
int randomNumber(int, int);
int percentChanceIsOne(int);
int totalCardCount(int, struct gameState *);

int main(int argc, char * argv[]) {
	int test_trials = 10000;
	
	if (argc > 1) {
		test_trials = atoi(argv[1]);
		if (test_trials < 1) {
			printf("Usage: cardtest1 <trials>\r\n");
			exit(1);
		}
	}
	
	srand(time(NULL));
	
	//new gameState
	struct gameState * gs = malloc(sizeof(struct gameState));
	struct gameState * stateCopy = malloc(sizeof(struct gameState));
	
	int trial;
	int returnValue;
	int numberOfErrors = 0;
	int playerNum;
	
	int emptyHand;
	int emptyDiscard;
	int emptyDeck;
	int emptyThree;	//not enough cards?
	int handPos;
	int drawCards;
	
	printf("Card Test 1\r\n");
	printf("Conducting %d random trials.\r\n", test_trials);
	
	for (trial = 0; trial < test_trials; trial++) {
		
		printf("TRIAL %d\r\n", trial);
		
		
		fuzzState(gs);

		//semi-randomize inputs (within reason)
		playerNum = randomNumber(2, MAX_PLAYERS) - 2;
		emptyDeck = percentChanceIsOne(5);
		emptyDiscard = percentChanceIsOne(5);
		emptyHand = percentChanceIsOne(5);
		emptyThree = percentChanceIsOne(1);
		
		if (emptyDeck == 1 || emptyThree == 1) {
			gs->deckCount[playerNum] = 0;
		} else { 
			gs->deckCount[playerNum] = randomNumber(1, 300);
		}
		
		if (emptyHand == 1 || emptyThree == 1) {
			gs->handCount[playerNum] = 1;					//leave room for Smithy card
		} else { 
			gs->handCount[playerNum] = randomNumber(2, 300);
		}
		
		if (emptyDiscard == 1 || emptyThree == 1) {
			gs->discardCount[playerNum] = 0;
		} else {
			gs->discardCount[playerNum] = randomNumber(1, 300);
		}
		
		gs->playedCardCount = randomNumber(0,gs->handCount[playerNum]);
		
		/*gs->deckCount[playerNum] = randomNumber(5, 300);
		gs->discardCount[playerNum] = randomNumber(5, 300);
		gs->handCount[playerNum] = randomNumber(5, 300);
		*/
		
		
		//set smithy card
		handPos = randomNumber(0, gs->handCount[playerNum]-1);
		gs->hand[playerNum][handPos] = smithy;
		
		//create copy for comparison later
		memcpy(stateCopy, gs, sizeof(struct gameState));
		
		//RUN FUNCTION
		returnValue = playSmithy(handPos, playerNum, gs);
		
		//Check state
		if (stateCopy->deckCount[playerNum] < 3) {
			if (gs->discardCount[playerNum] != 1) {
				printf("discardCount is not as expected.  Expected: 1, Actual: %d\r\n", gs->discardCount[playerNum]);
				numberOfErrors++;
			}
		} else {
			if (gs->discardCount[playerNum] != stateCopy->discardCount[playerNum] + 1) {
				printf("discardCount is not as expected.  Expected: %d, Actual: %d\r\n",stateCopy->discardCount[playerNum] + 1, gs->discardCount[playerNum]);
				numberOfErrors++;
			}			
		}
		
		//check top of discard for smithy
		if (gs->discard[playerNum][ gs->discardCount[playerNum] - 1 ] != smithy){
			printf("top of discard mismatch. Expected: %d, Actual %d\r\n", smithy, gs->discard[playerNum][ gs->discardCount[playerNum] - 1 ]);
			numberOfErrors++;
		}
		
		
		if (stateCopy->discardCount[playerNum] + stateCopy->deckCount[playerNum] >= 3) {
			drawCards = 3;
		} else {
			drawCards = stateCopy->discardCount[playerNum] + stateCopy->deckCount[playerNum];
		}
		
		//drawCards should be drawCards less pluss smithy
		if (gs->discardCount[playerNum] + gs->deckCount[playerNum] - drawCards + 1 != stateCopy->discardCount[playerNum] + stateCopy->deckCount[playerNum]) {
			printf("deck + discard count is not as expected.  Expected: %d, Actual: %d\r\n",stateCopy->discardCount[playerNum] + stateCopy->deckCount[playerNum] - drawCards + 1, gs->discardCount[playerNum] + gs->deckCount[playerNum]);
			numberOfErrors++;
		}
		
		//Hand Should have drawCards extra cards minus smithy
		if (gs->handCount[playerNum] != stateCopy->handCount[playerNum] + drawCards - 1) {
			printf("handCount is not as expected.  Expected: %d, Actual: %d\r\n",stateCopy->handCount[playerNum] + drawCards - 1, gs->handCount[playerNum]);
			numberOfErrors++;
		}


	}	
	
	printf("Card Test 1 Complete\r\n");
	printf("Number of errors found: %d\r\n", numberOfErrors);
	

	free(gs);
	free(stateCopy);
	return 0;
}

void fuzzState(struct gameState * state) {
	int i;
	
	unsigned char * ptr = (unsigned char *)state;
	
	for (i = 0; i < sizeof(struct gameState); i++) {
		ptr[i] = (unsigned char)(rand()%256);
	}
}

int randomNumber(int from, int to) {
	int a, b;
	if (from < to) {
		a = from;
		b = to;
	} else {
		a = to;
		b = from;
	}
	
	return rand() % ((b - a) + 1) + a;
}

int percentChanceIsOne(int probability) {
	if ( probability > (rand() % 100)) {
		return 1;
	} else {
		return 0;
	}
}

int totalCardCount(int playerNum, struct gameState * gs) {
	return (gs->deckCount[playerNum] + gs->discardCount[playerNum] + gs->handCount[playerNum]);
}
