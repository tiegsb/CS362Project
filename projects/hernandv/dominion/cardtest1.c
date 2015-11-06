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

	GS->hand[p][4] = smithy; //5th card in hand is smithy

	printf("Playing Smithy card and testing...\n");

	/*Checking handcount and cards in hand before playing smithy*/
	printf("Hand count before Smithy is %d...\n", GS->handCount[p]);
	int i = 0, cardStatus;
	char c[25];
	for(i = 0; i < GS->handCount[p]; i++){
		cardNumToName(GS->hand[p][i], c);	//Converts card number to string
		printf( "%s, ", c);
		if(strcmp(c, "Smithy") == 0){
			cardStatus = 1;	//Card is present in hand
		}
	}

	/*Check if smithy card is in hand before use*/
	if(cardStatus == 1){
		printf("\nTest PASSED, card is present in player %d's hand\n\n", p);
	} else {
		printf("\nTest FAILED, card is NOT present in player %d's hand\n\n", p);
	}

	smithyCard(p, GS, 4);	//Play smithy card

	cardStatus = 0; //Reset to zero

	/*Checking handcount and cards in hand after playing smithy*/
	printf("Hand count after Smithy is %d...\n", GS->handCount[p]);
	for(i = 0; i < GS->handCount[p]; i++){
		cardNumToName(GS->hand[p][i], c);	//Converts card number to string
		printf( "%s, ", c);
		if(strcmp(c, "Smithy") == 0){
			cardStatus = 1;	//Card is present in hand
		}
	}

	/*Check if smithy card is in hand*/
	if(cardStatus == 0){
		printf("\nTest PASSED, card is NOT present in player %d's hand\n\n", p);
	} else {
		printf("\nTest FAILED, card is present in player %d's hand\n\n", p);
	}

	printf("Testing for correct number of cards drawn...\n");
	/*Check current state player's handcount +3 cards after discard is 5 cards*/
	if(GS->handCount[p] == 7){
		printf("Test PASSED, Player %d drew +3 cards\n\n", p);
	} else {
		printf("Test FAILED, Player %d drew incorrect amount of cards\n\n", p);
	}

	printf("Checking if Smithy Card is in played pile...\n");
	/*Check if card is in played pile*/
	if(GS->playedCards[p] == smithy){
		printf("Test PASSED, Smithy is in played pile\n\n");
	} else {
		printf("Test FAILED, Smithy is NOT in played pile\n\n");
	}

/*Check if smithy card has been discarded from hand after card effects*/
	for(i = 0; i < GS->handCount[p]; i++){
		cardNumToName(GS->hand[p][i], c);	//Converts card number to string
		printf( "%s, ", c);
		if(strcmp(c, "Smithy") != 0){
			cardStatus = 0;	//Card is NOT present in hand
		}
	}

	printf("\nTesting if card is discarded from hand...\n");
	if(cardStatus == 0){
		printf("Test PASSED, Smithy is discarded from player %d's hand after use\n\n", p);
	} else {
		printf("Test FAILED, Smithy card is NOT discarded from player %d's hand after use\n\n", p);
	}

	return 0;

}