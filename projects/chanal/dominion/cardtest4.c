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
	int p = 0; //player 1
	int numPlayer = 2;
	int handCount = 5;
	int k[10] = {adventurer, council_room, feast, gardens, mine,
				 remodel, smithy, village, baron, great_hall};

	struct gameState* GS = newGame();

	initializeGame(numPlayer, k, gameSeed, GS);

	GS->handCount[p] = handCount;

	GS->hand[p][0] = copper;
	GS->hand[p][1] = copper;
	GS->hand[p][2] = copper;
	GS->hand[p][3] = smithy;
	GS->hand[p][4] = salvager; //5th card in hand is salvager

	printf("Playing Salvager card and testing...\n");

	/*Checking handcount and cards in hand before playing council room*/
	printf("Hand count before Salvager is %d...\n",  GS->handCount[p]);
	int i = 0, cardStatus;
	char c[25];

	printHand(p, GS);	//Prints players' hand before card use

	for(i = 0; i < numHandCards(GS); i++){
		cardNumToName(GS->hand[p][i], c);	//Converts card number to string
		if(strcmp(c, "Salvager") == 0){
			cardStatus = 1;	//Card is present in hand
		}
	}

	/*Check if Salvager card is in hand before use*/
	if(cardStatus == 1){
		printf("Test PASSED, card is present in player %d's hand\n\n", p);
	} else {
		printf("Test FAILED, card is NOT present in player %d's hand\n\n", p);
	}

	printf("Playing salvager card now with no choice...\n");
	salvagerCard(GS, 0, p, 4);	//Play salvager card, no choice
	cardStatus = 0; //Reset to zero

	/*Checking handcount and cards in hand after playing Salvager*/
	printHand(p, GS);
	printf("Hand count after Salvager is %d...\n",  GS->handCount[p]);
	for(i = 0; i < GS->handCount[p]; i++){
		cardNumToName(GS->hand[p][i], c);	//Converts card number to string
		if(strcmp(c, "Salvager") == 0){
			cardStatus = 1;	//Card is present in hand
		}
	}

	/*Check if Salvager card is in hand*/
	if(cardStatus == 0){
		printf("Test PASSED, card is NOT present in player %d's hand\n\n", p);
	} else {
		printf("Test FAILED, card is present in player %d's hand\n\n", p);
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
	if( numHandCards(GS) == 4){
		printf("Test PASSED, %d cards left in player %d's hand\n\n",  numHandCards(GS), p);
	} else {
		printf("Test FAILED, %d cards left in player %d's hand\n\n",  numHandCards(GS), p);
	}

	printf("Testing coin state after playing Salvager...\n");
	/*Test if coins is +3 after no choice card discarded (copper, copper, silver)*/
	if(GS->coins == 3){
		printf("Test PASSED, current coins is %d\n", GS->coins);
	} else {
		printf("Test FAILED, current coins is %d\n", GS->coins);	
	}

	printf("---------------------------------------------\n\n");


	struct gameState* state = newGame();

	initializeGame(numPlayer, k, gameSeed, state);

	state->handCount[p] = handCount;

	state->hand[p][0] = copper;
	state->hand[p][1] = copper;
	state->hand[p][2] = copper;
	state->hand[p][3] = smithy;
	state->hand[p][4] = salvager; //5th card in hand is salvager

	printf("Playing Salvager card and testing...\n");

	/*Checking handcount and cards in hand before playing council room*/
	printf("Hand count before Salvager is %d...\n",  state->handCount[p]);
	i = 0; 
	cardStatus = 0;

	printHand(p, state);	//Prints players' hand before card use

	for(i = 0; i < numHandCards(state); i++){
		cardNumToName(state->hand[p][i], c);	//Converts card number to string
		if(strcmp(c, "Salvager") == 0){
			cardStatus = 1;	//Card is present in hand
		}
	}

	/*Check if Salvager card is in hand before use*/
	if(cardStatus == 1){
		printf("Test PASSED, card is present in player %d's hand\n\n", p);
	} else {
		printf("Test FAILED, card is NOT present in player %d's hand\n\n", p);
	}

	printf("Playing salvager card now with choice == 3 to discard smithy for coin bonus...\n");
	salvagerCard(state, 3, p, 4);	//Play salvager card, no choice
	cardStatus = 0; //Reset to zero

	/*Checking handcount and cards in hand after playing Salvager*/
	printHand(p, state);
	printf("Hand count after Salvager is %d...\n",  state->handCount[p]);
	for(i = 0; i < state->handCount[p]; i++){
		cardNumToName(state->hand[p][i], c);	//Converts card number to string
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
	if(state->numBuys == 2){
		printf("Test PASSED, Player %d has +1 numBuys\n\n", p);
	} else {
		printf("Test FAILED, Player %d has incorrect number of numBuys\n\n", p);
	}


	/*Originally 5 cards in hand, discard salvager and choice*/
	printf("Testing for hand count after not discarding choice...\n");
	if( numHandCards(state) == 3){
		printf("Test PASSED, %d cards left in player %d's hand\n\n",  numHandCards(state), p);
	} else {
		printf("Test FAILED, %d cards left in player %d's hand\n\n",  numHandCards(state), p);
	}

	/*Test if coins is +7 after smithy discarded (copper, copper, copper) + smithy 4 coin bonus*/
	printf("Testing for coin bonus after discard of choice card...\n");
	if(state->coins == 7){
		printf("Test PASSED, current coins is %d\n\n", state->coins);
	} else {
		printf("Test FAILED, current coins is %d\n\n", state->coins);	
	}

	return 0;
}