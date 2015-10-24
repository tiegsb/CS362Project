/***********************************************************************
* Author : Allan Chan
* ONID: chanal
* Class: CS362
* Filename: cardtest3.c
*
* Description:
*	Tests the council room card effect
*	
*	The council room card is an action card that provides +4 cards and +1 buy
*	
*	Two bugs were introduced to council room and should fail those tests here
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
	int numPlayer = 4;
	int k[10] = {adventurer, council_room, feast, gardens, mine,
				 remodel, smithy, village, baron, great_hall};

	struct gameState* GS = newGame();

	initializeGame(numPlayer, k, gameSeed, GS);

	GS->hand[p][4] = council_room; //5th card in hand is council room

	printf("Playing Council Room card and testing...\n");

	/*Checking handcount and cards in hand before playing council room*/
	printf("Hand count before council room is %d...\n", GS->handCount[p]);
	int i = 0, cardStatus;
	char c[25];
	for(i = 0; i < GS->handCount[p]; i++){
		cardNumToName(GS->hand[p][i], c);	//Converts card number to string
		printf( "%s, ", c);
		if(strcmp(c, "Council Room") == 0){
			cardStatus = 1;	//Card is present in hand
		}
	}

	/*Check if council room card is in hand before use*/
	if(cardStatus == 1){
		printf("\nTest PASSED, card is present in player %d's hand\n\n", p);
	} else {
		printf("\nTest FAILED, card is NOT present in player %d's hand\n\n", p);
	}

	councilRoomCard(p, GS, 4);	//Play council room card

	cardStatus = 0; //Reset to zero

	/*Checking handcount and cards in hand after playing council room*/
	printf("Hand count after council room is %d...\n", GS->handCount[p]);
	for(i = 0; i < GS->handCount[p]; i++){
		cardNumToName(GS->hand[p][i], c);	//Converts card number to string
		printf( "%s, ", c);
		if(strcmp(c, "Council Room") == 0){
			cardStatus = 1;	//Card is present in hand
		}
	}

	/*Check if council room card is in hand*/
	if(cardStatus == 0){
		printf("\nTest PASSED, card is NOT present in player %d's hand\n\n", p);
	} else {
		printf("\nTest FAILED, card is present in player %d's hand\n\n", p);
	}

	printf("Testing for correct number of cards drawn...\n");
	/*Check current state player's handcount +4 cards after discard is 8 cards*/
	if(GS->handCount[p] == 8){
		printf("Test PASSED, Player %d drew +4 cards\n\n", p);
	} else {
		printf("Test FAILED, Player %d drew incorrect amount of cards\n\n", p);
	}

	printf("Testing for correct number of numBuys...\n");
	/*Check if numbuys is incremented*/
	if(GS->numBuys == 2){
		printf("Test PASSED, Player %d has +1 numBuys\n\n", p);
	} else {
		printf("Test FAILED, Player %d has incorrect number of numBuys\n\n", p);
	}

	printf("Checking if card is in played pile...\n");
	/*Check if card is in played pile*/
	if(GS->playedCards[p] == council_room){
		printf("Test PASSED, Council Room is in played pile\n\n");
	} else {
		printf("Test FAILED, Council Room is NOT in played pile\n\n");
	}

	return 0;

}