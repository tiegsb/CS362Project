/***********************************************************************
* Author : Allan Chan
* ONID: chanal
* Class: CS362
* Filename: cardtest2.c
*
* Description:
*	Tests the adventurer card card effect
*	
*	The adventurer card is an action card that costs 6 coins and when played has the effect of 
*	revealing cards from your deck until two Treasure cards are drawn. Those two Treasure cards 
*	will then be placed in your hand and the other non-Treasure cards revealed are discarded.
*	
*	Two bugs were introduced to adventurerCard and should fail those tests here
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
	int p = 1; //player 2
	int numPlayer = 2;
	int handCount = 5;
	int k[10] = {adventurer, council_room, feast, gardens, mine,
				 remodel, smithy, village, baron, great_hall};

	/*Load hand with cards*/
	int testHand1[5];

	testHand1[0] = smithy;
	testHand1[1] = copper;
	testHand1[2] = copper;
	testHand1[3] = copper;
	testHand1[4] = adventurer;


	struct gameState G;

	int drawntreasure = 0;
	int cardDrawn = 0;
	int z = 0;
	int temphand[MAX_HAND];

	/*Clear the game state*/
	memset(&G, 23, sizeof(struct gameState));

	/*Initialize the game*/
	initializeGame(numPlayer, k, gameSeed, &G);

	/*Set cards to testHand1, player 1 = [p]*/
	G.handCount[p] = 5;
	memcpy(G.hand[p], testHand1, sizeof(int)*handCount);

	/*Set deck count to zero for shuffle*/
	G.deckCount[p] = 0;

	int i, cardStatus;
	char c[25]; /*Used to assign int to char*/

	printf("Checking if Adventurer card is present in player %d's hand\n", p);
	printf("Player %d has %d cards with 1 Adventurer card\n", p, G.handCount[p]);

	/*Display the player's cards in hand and determine if Adventurer is present*/
	for(i = 0; i < G.handCount[p]; i++){
		cardNumToName(G.hand[p][i], c);	//Converts card number to string
		printf( "%s, ", c);
		if(strcmp(c, "Adventurer") == 0){
			cardStatus = 1;	//Card is present in hand
		}
	}

	if(cardStatus == 1){
		printf("\nTest PASSED, card is present in player %d's hand\n\n", p);
	} else {
		printf("\nTest FAILED, card is not present in player %d's hand\n\n", p);
	}
/////////////////////////////////////////////////////////////////////////////////////////

	//void adventurerCard (int drawntreasure, struct gameState* state, int currentPlayer, int cardDrawn, int temphand[], int z)

	cardStatus = 0;	/*Reset status to 0*/

	printf("Playing Adventurer card and testing, deck count = %d\n", G.deckCount[p]);
	
	/*Play Adventurer card from hand*/
	adventurerCard(drawntreasure, &G, p, cardDrawn, temphand, z);

	/*Check if player's deck is shuffled (if empty) and added to deck after play of Adventurer*/
	if(G.deckCount[p] == 0){
		printf("Test FAILED, player %d's deck was not shuffled and the deck count is %d\n", p, G.deckCount[p]);
	} else {
		printf("Test PASSED, player %d's deck was shuffled and count is %d\n", p, G.deckCount[p]);	
	}


	/*Checks if hand count of player is incremented by two for the two treasures*/
	if(G.handCount[p] == 6){
		printf("Test PASSED, player %d's hand received +2 cards\n\n", p);
	} else {
		printf("Test FAILED, player %d's hand DID NOT receive +2 cards, handcount = %d\n\n", p, G.handCount[p]);
	}

	/*Check if Adventurer card has been discarded from hand after card effects*/
	for(i = 0; i < G.handCount[p]; i++){
		cardNumToName(G.hand[p][i], c);	//Converts card number to string
		printf( "%s, ", c);
		if(strcmp(c, "Adventurer") == 0){
			cardStatus = 1;	//Card is present in hand
		}
		if(strcmp(c, "Copper") || strcmp(c, "Silver") == 0 || strcmp(c, "Gold") == 0){
			drawntreasure++;	//Keep track of number of drawn treasure
		}
	}

	if(cardStatus == 0){
		printf("\nTest PASSED, Adventurer is discarded from player %d's hand after use\n", p);
	} else {
		printf("\nTest FAILED, Adventurer card is NOT discarded from player %d's hand after use\n", p);
	}

	if(drawntreasure == 2){
		printf("Test PASSED, %d treasure was drawn\n\n", drawntreasure);
	} else {
		printf("Test FAILED, improper amount of treasure drawn, actual treasure drawn = %d\n\n", drawntreasure);
	}
	return 0;

}