/***********************************************************************
* Author : Allan Chan
* ONID: chanal
* Class: CS362
* Filename: cardtest4.c
*
* Description:
*	Tests the salvagercard effect
*	
*	The salvager card is a +1 buy and trash card for coin bonus to the trashed card
*	
*	One bug were introduced to salvager and should fail those tests here
*
************************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "interface.c"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <time.h>

int main() {

	srand(time(NULL));
	int gameSeed = rand() % 1000 + 1;
	int p = 3; //player 3
	int numPlayer = 4;
	int k[10] = {adventurer, council_room, feast, gardens, mine,
				 remodel, smithy, village, baron, great_hall};

	struct gameState* GS = newGame();

	initializeGame(numPlayer, k, gameSeed, GS);

	GS->handCount[p] = 5;

	GS->hand[p][0] = smithy;
	GS->hand[p][1] = copper;
	GS->hand[p][2] = copper;
	GS->hand[p][3] = copper;
	GS->hand[p][4] = salvager; //5th card in hand is salvager

//void salvagerCard(struct gameState* state, int choice1, int currentPlayer, int handPos);
	printf("Playing Salvager card and testing...\n");

	/*Checking handcount and cards in hand before playing council room*/
	printf("Hand count before Salvager is %d...\n", GS->handCount[p]);
	int i = 0, cardStatus;
	char c[25];
	for(i = 0; i < GS->handCount[p]; i++){
		cardNumToName(GS->hand[p][i], c);	//Converts card number to string
		printf( "%s, ", c);
		if(strcmp(c, "Salvager") == 0){
			cardStatus = 1;	//Card is present in hand
		}
	}

	/*Check if Salvager card is in hand before use*/
	if(cardStatus == 1){
		printf("\nTest PASSED, card is present in player %d's hand\n\n", p);
	} else {
		printf("\nTest FAILED, card is NOT present in player %d's hand\n\n", p);
	}

	salvagerCard(GS, 0, p, 4);	//Play salvager card, no choice
	cardStatus = 0; //Reset to zero

	/*Checking handcount and cards in hand after playing Salvager*/
	printf("Hand count after Salvager is %d...\n", GS->handCount[p]);
	for(i = 0; i < GS->handCount[p]; i++){
		cardNumToName(GS->hand[p][i], c);	//Converts card number to string
		printf( "%s, ", c);
		if(strcmp(c, "Salvager") == 0){
			cardStatus = 1;	//Card is present in hand
		}
	}

	/*Check if Salvager card is in hand*/
	if(cardStatus == 0){
		printf("\nTest PASSED, card is NOT present in player %d's hand\n\n", p);
	} else {
		printf("\nTest FAILED, card is present in player %d's hand\n\n", p);
	}

	printf("Testing for correct number of numBuys...\n");
	/*Check if numbuys is incremented*/
	if(GS->numBuys == 2){
		printf("Test PASSED, Player %d has +1 numBuys\n\n", p);
	} else {
		printf("Test FAILED, Player %d has incorrect number of numBuys\n\n", p);
	}

	/*Originally 5 cards in hand, discard salvager*/
	printf("Testing for hand count after not discarding choice...\n");
	if(GS->handCount[p] == 4){
		printf("Test PASSED, %d cards left in player %d's hand\n", GS->handCount[p], p);
	} else {
		printf("Test FAILED, %d cards left in player %d's hand\n", GS->handCount[p], p);
	}

	/*Test if coins is +3 after no choice card discarded*/
	if(GS->coins == 3){
		printf("Test PASSED, current coins is %d\n", GS->coins);
	} else {
		printf("Test FAILED, current coins is %d\n", GS->coins);	
	}


	return 0;
}