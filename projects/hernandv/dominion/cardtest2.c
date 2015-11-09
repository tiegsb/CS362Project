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

	GS->hand[p][4] = adventurer; //5th card in hand is adventurer
	
	int drawntreasure = 0;
	int newtreasure = 0;
	int cardDrawn = 0;
	int z = 0;
	int temphand[MAX_HAND];

	printf("Playing Adventurer card and testing...\n");

	/*Checking handcount and cards in hand before playing adventurer*/
	printf("Hand count before Adventurer is %d...\n", GS->handCount[p]);
	int i = 0, cardStatus;
	char c[25];
	for(i = 0; i < GS->handCount[p]; i++){
		cardNumToName(GS->hand[p][i], c);	//Converts card number to string
		printf( "%s, ", c);
		if(strcmp(c, "Adventurer") == 0){
			cardStatus = 1;	//Card is present in hand
		}
	}

	/*Check if adventurer card is in hand before use*/
	if(cardStatus == 1){
		printf("\nTest PASSED, card is present in player %d's hand\n\n", p);
	} else {
		printf("\nTest FAILED, card is NOT present in player %d's hand\n\n", p);
	}

	adventurerCard(drawntreasure, GS, p, cardDrawn, temphand, z);	//Play adventurer card

	cardStatus = 0; //Reset to zero

	/*Checking handcount and cards in hand after playing adventurer*/
	printf("Hand count after adventurer is %d...\n", GS->handCount[p]);
	for(i = 0; i < GS->handCount[p]; i++){
		cardNumToName(GS->hand[p][i], c);	//Converts card number to string
		printf( "%s, ", c);
		if(strcmp(c, "Adventurer") == 0){
			cardStatus = 1;	//Card is present in hand
		}
	}

	/*Check if adventurer card is in hand*/
	if(cardStatus == 0){
		printf("\nTest PASSED, card is NOT present in player %d's hand\n\n", p);
	} else {
		printf("\nTest FAILED, card is present in player %d's hand\n\n", p);
	}
	

	/*Check if two treasure cards are drawn and added to hand*/
	
	printf("Testing for correct number of treasure cards added...\n");
	for(i = 0; i < GS->handCount[p]; i++){
		if(GS->hand[p][i] == copper || GS->hand[p][i] == silver || GS->hand[p][i] == gold){
			drawntreasure++;
		}
	}	

	if((drawntreasure - 2) >= 1){
		printf("Test PASSED, two treasure cards are added to player %d's hand\n\n", p);
	} else {
		printf("Test FAILED, %d (NOT 2) treasure cards are added to player %d's hand\n\n", drawntreasure, p);
	}

	return 0;

}