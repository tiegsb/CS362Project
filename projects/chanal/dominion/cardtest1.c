/***********************************************************************
* Author : Allan Chan
* ONID: chanal
* Class: CS362
* Filename: cardtest1.c
*
* Description:
*	Tests the smithy card card effect
*	
*	Smithy card effect should draw 3 cards and place it in player's hand
*	when played
*
*	A bug was introduced in the code for smithyCard and should fail a test here
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


int main(){

	srand(time(NULL));
	int gameSeed = rand() % 1000 + 1;
	int p = 0; //player 1
	int numPlayer = 2;
	int handCount = 5;
	int k[10] = {adventurer, council_room, feast, gardens, mine,
				 remodel, smithy, village, baron, great_hall};

	/*Load hand with cards*/
	int testHand1[5];

	testHand1[0] = adventurer;
	testHand1[1] = copper;
	testHand1[2] = silver;
	testHand1[3] = gold;
	testHand1[4] = smithy;

	struct gameState G;

	/*Clear the game state*/
	memset(&G, 23, sizeof(struct gameState));

	/*Initialize the game*/
	initializeGame(numPlayer, k, gameSeed, &G);

	/*Set cards to testHand1, player 1 = [p]*/
	G.handCount[p] = handCount;
	memcpy(G.hand[p], testHand1, sizeof(int)*handCount);

	int i, cardStatus;
	char c[25]; /*Used to assign int to char*/

	printf("Checking if Smithy card is present in player %d's hand...\n", p);

	/*Display the player's cards in hand and determine if smithy is present*/
	for(i = 0; i < G.handCount[p]; i++){
		cardNumToName(G.hand[p][i], c);	//Converts card number to string
		printf( "%s, ", c);
		if(strcmp(c, "Smithy") == 0){
			cardStatus = 1;	//Card is present in hand
		}
	}

	if(cardStatus == 1){
		printf("\nTest PASSED, card is present in player %d's hand\n\n", p);
	} else {
		printf("\nTest FAILED, card is not present in player %d's hand\n\n", p);
	}

	cardStatus = 0;	/*Reset status to 0*/

	printf("Playing Smithy card and testing...\n");
	smithyCard(p, &G, 4);	//Play smithy card from 4th hand pos

	/*Check if hand count is +3 after play of Smithy*/
	if(G.handCount[p] == 7){
		printf("Test PASSED, player %d's hand received +3 cards\n\n", p);
	} else {
		printf("Test FAILED, player %d's hand DID NOT receive +3 cards\n\n", p);
	}

	/*Check if smithy card has been discarded from hand after card effects*/
	for(i = 0; i < G.handCount[p]; i++){
		cardNumToName(G.hand[p][i], c);	//Converts card number to string
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