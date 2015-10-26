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
*	A bug was introduced to adventurerCard and should fail those tests here
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
	int i;
	int handCount = 5;
	int cardStatus = 0;
	int numPlayer = 2;
	int k[10] = {adventurer, council_room, feast, gardens, mine,
				 remodel, smithy, village, baron, great_hall};

	struct gameState G;

	/*Clear the game state*/
	memset(&G, 23, sizeof(struct gameState));

	/*Initialize the game*/
	initializeGame(numPlayer, k, gameSeed, &G);

	/*Load hand with adventurer cards*/
	int testhand1[handCount];
	testhand1[0] = smithy;
	testhand1[1] = estate;
	testhand1[2] = estate;
	testhand1[3] = estate;	
	testhand1[4] = adventurer;

	G.handCount[p] = handCount;
	memcpy(G.hand[p], testhand1, sizeof(int)*handCount);

	int drawntreasure = 0;
	int cardDrawn = 0;
	int z = 0;
	int temphand[MAX_HAND];
	char c[25];

	printf("Printing hand before playing adventurer card...\n");

	/*Display the player's cards in hand and determine if Adventurer is present*/
	printHand(p, &G);

	for(i = 0; i < G.handCount[p]; i++){
		cardNumToName(G.hand[p][i], c);	//Converts card number to string
		if(strcmp(c, "Adventurer") == 0){
			cardStatus = 1;	//Card is present in hand
		}
	}

	if(cardStatus == 1){
		printf("Test PASSED, card is present in player %d's hand\n\n", p);
	} else {
		printf("Test FAILED, card is not present in player %d's hand\n\n", p);
	}

	printf("Playing and testing adventurer card...\n");

	/*Play Adventurer card from hand*/
	adventurerCard(drawntreasure, &G, p, cardDrawn, temphand, z);

	/*Display the player's cards in hand and determine if Adventurer is present*/
	for(i = 0; i < G.handCount[p]; i++){
		cardNumToName(G.hand[p][i], c);	//Converts card number to string
		if(strcmp(c, "Adventurer") == 0){
			cardStatus = 1;	//Card is present in hand
		}
	}

	/*****ERROR, Adventurer card is not discarded and is still in hand after adventurerCard()*******/
	printPlayed(p, &G);	//Print the played card --empty--
	printHand(p, &G);	//Shows adventurer is still in hand
	//assert(G.playedCards[0] == adventurer);	/*This failed and is commented out*/

	if(cardStatus == 1){
		printf("Test FAILED, card is still present in player %d's hand\n", p);
	} else {
		printf("Test PASSED, card is NOT present in player %d's hand\n", p);
	}

	/*Check if two treasure cards are drawn and added to hand*/
	for(i = 0; i < G.handCount[p]; i++){
		if(G.hand[p][i] == copper || G.hand[p][i] == silver || G.hand[p][i] == gold){
			drawntreasure++;
		}
	}

	if(drawntreasure == 2){
		printf("Test PASSED, two treasure cards are added to player %d's hand\n\n", p);
	} else {
		printf("Test FAILED, %d (NOT 2) treasure cards are added to player %d's hand\n\n", drawntreasure, p);
	}

	return 0;

}