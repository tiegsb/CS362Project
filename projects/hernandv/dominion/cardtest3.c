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

	GS->hand[p][4] = village; //5th card in hand is village

	printf("Playing Village card and testing...\n");

	/*Checking handcount and cards in hand before playing village*/
	printf("Hand count before village is %d...\n", GS->handCount[p]);
	int i = 0, cardStatus;
	char c[25];
	for(i = 0; i < GS->handCount[p]; i++){
		cardNumToName(GS->hand[p][i], c);	//Converts card number to string
		printf( "%s, ", c);
		if(strcmp(c, "Village") == 0){
			cardStatus = 1;	//Card is present in hand
		}
	}

	/*Check if village card is in hand before use*/
	if(cardStatus == 1){
		printf("\nTest PASSED, card is present in player %d's hand\n\n", p);
	} else {
		printf("\nTest FAILED, card is NOT present in player %d's hand\n\n", p);
	}

	villageCard(p, GS, 4);	//Play village card

	cardStatus = 0; //Reset to zero

	/*Checking handcount and cards in hand after playing village*/
	printf("Hand count after village is %d...\n", GS->handCount[p]);
	for(i = 0; i < GS->handCount[p]; i++){
		cardNumToName(GS->hand[p][i], c);	//Converts card number to string
		printf( "%s, ", c);
		if(strcmp(c, "Village") == 0){
			cardStatus = 1;	//Card is present in hand
		}
	}

	/*Check if village card is in hand*/
	if(cardStatus == 0){
		printf("\nTest PASSED, card is NOT present in player %d's hand\n\n", p);
	} else {
		printf("\nTest FAILED, card is present in player %d's hand\n\n", p);
	}

	printf("Testing for correct number of cards drawn...\n");
	/*Check current state player's handcount +1 cards after discard is 5 cards*/
	if(GS->handCount[p] == 5){
		printf("Test PASSED, Player %d drew +1 cards\n\n", p);
	} else {
		printf("Test FAILED, Player %d drew incorrect amount of cards\n\n", p);
	}

	printf("Testing for correct number of actions...\n");
	/*Check if numActions is incremented*/
	if(GS->numActions == 3){
		printf("Test PASSED, Player %d has +2 numActions\n\n", p);
	} else {
		printf("Test FAILED, Player %d has incorrect number of numActions\n\n", p);
	}

	printf("Checking if card is in played pile...\n");
	/*Check if card is in played pile*/
	if(GS->playedCards[p] == village){
		printf("Test PASSED, Village is in played pile\n\n");
	} else {
		printf("Test FAILED, Village is NOT in played pile\n\n");
	}

	return 0;

}