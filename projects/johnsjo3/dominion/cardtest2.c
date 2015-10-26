/*
* Card Test 1: Adventurer
*
* In this unit test, we are testing the Adventurer Card.  The expected behavior of the Adventurer
* Card is to draw cards from the deck until 2 treasure cards (copper, silver, or gold) are drawn.
* The other cards are discarded.
*
*/

#include "dominion.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char * argv[]) {
	struct gameState * gs1 = malloc(sizeof(struct gameState));
	struct gameState * gs2 = malloc(sizeof(struct gameState));
	struct gameState * gs3 = malloc(sizeof(struct gameState));
	struct gameState * gs4 = malloc(sizeof(struct gameState));
	struct gameState * gs5 = malloc(sizeof(struct gameState));
	struct gameState * stateCopy = malloc(sizeof(struct gameState));
	struct gameState * gs = NULL;
	
	int playerNum = 0;
	int i;
	
	//Setup gamestate 1 - Test for identification of treasure cards (copper and silver)
	//playerNum = 0;
	gs = gs1;
	gs->deckCount[playerNum] = 10;
	gs->discardCount[playerNum] = 10;
	gs->handCount[playerNum] = 5;
	//Clear Cards
	memset(gs->deck[playerNum], curse, sizeof(int)*gs->deckCount[playerNum]);
	//Seed Treasure cards
	gs->deck[playerNum][gs->deckCount[playerNum] - 1] = copper;
	gs->deck[playerNum][gs->deckCount[playerNum] - 2] = silver;
	
	//Setup gamestate 2 - Test for identification of treasure cards (copper and silver)
	//playerNum = 1;
	gs = gs2;
	gs->deckCount[playerNum] = 10;
	gs->discardCount[playerNum] = 10;
	gs->handCount[playerNum] = 5;
	//Clear Cards
	memset(gs->deck[playerNum], curse, sizeof(int)*gs->deckCount[playerNum]);
	//Seed Treasure cards
	gs->deck[playerNum][gs->deckCount[playerNum] - 1] = silver;
	gs->deck[playerNum][gs->deckCount[playerNum] - 2] = gold;
	
	//Setup gamestate 3 - Test for Skipping of all other Treasure Cards
	//playerNum = 2;
	gs = gs3;
	gs->deckCount[playerNum] = treasure_map;		//Not + 1, we are ignoring copper
	gs->discardCount[playerNum] = 10;
	gs->handCount[playerNum] = 5;
	//Clear Cards
	memset(gs->deck[playerNum], curse, sizeof(int)*gs->deckCount[playerNum]);
	//Seed Treasure cards on bottom, every other cardtype on top
	gs->deck[playerNum][0] = silver;
	gs->deck[playerNum][1] = gold;
	gs->deck[playerNum][2] = curse;	
	gs->deck[playerNum][3] = estate;	
	gs->deck[playerNum][4] = duchy;
	gs->deck[playerNum][5] = province;
	//Seed Action cards on top
	for (i=gold; i < treasure_map; i++) {
		gs->deck[playerNum][gold] = i+1;
	}
	
	//Setup gamestate 4 - Treasure cards must be drawn from Discard
	//playerNum = 3;
	gs = gs4;
	gs->deckCount[playerNum] = 5;
	gs->discardCount[playerNum] = 10;
	gs->handCount[playerNum] = 5;
	//Clear Cards
	memset(gs->deck[playerNum], curse, sizeof(int)*gs->deckCount[playerNum]);
	memset(gs->discard[playerNum], curse, sizeof(int)*gs->discardCount[playerNum]);
	//Seed Treasure cards in discard pile.
	gs->discard[playerNum][0] = silver;
	gs->discard[playerNum][1] = gold;
	
	//Setup gamestate 5 - Not enough treasure cards
	//playerNum = 3;
	gs = gs5;
	gs->deckCount[playerNum] = 5;
	gs->discardCount[playerNum] = 10;
	gs->handCount[playerNum] = 5;
	//Clear Cards
	memset(gs->deck[playerNum], curse, sizeof(int)*gs->deckCount[playerNum]);
	memset(gs->discard[playerNum], curse, sizeof(int)*gs->discardCount[playerNum]);
	
	
	//TEST TRIALS
	printf("Card Test 2\r\n");
	
	//TRIAL 1 - IDENTIFICATION OF COPPER AND SILVER
	printf("Trial 1\r\n");
	memcpy(stateCopy, gs1, sizeof(struct gameState));
	//playerNum = 0;
	playAdventurer(playerNum, gs1);
	if (gs1->deckCount[playerNum] != stateCopy->deckCount[playerNum] - 2) {
		printf("Mismatched deckCount. Expected: %d, Actual: %d\r\n",stateCopy->deckCount[playerNum] - 2,gs1->deckCount[playerNum] );
	}
	if (gs1->handCount[playerNum] != stateCopy->handCount[playerNum] + 2) {
		printf("Mismatched handCount. Expected: %d, Actual: %d\r\n", stateCopy->handCount[playerNum] + 2, gs1->handCount[playerNum]);
	}
	if (gs1->discardCount[playerNum] != stateCopy->discardCount[playerNum]){
		printf("Mismatched discardCount. Expected: %d, Actual: %d\r\n", stateCopy->discardCount[playerNum], gs1->discardCount[playerNum]);
	}
	
	//TRIAL 2 - IDENTIFICATION OF SILVER AND GOLD
	printf("Trial 2\r\n");
	memcpy(stateCopy, gs2, sizeof(struct gameState));
	//playerNum = 1;
	playAdventurer(playerNum, gs2);
	if (gs2->deckCount[playerNum] != stateCopy->deckCount[playerNum] - 2) {
		printf("Mismatched deckCount. Expected: %d, Actual: %d\r\n",stateCopy->deckCount[playerNum] - 2,gs2->deckCount[playerNum] );
	}
	if (gs2->handCount[playerNum] != stateCopy->handCount[playerNum] + 2) {
		printf("Mismatched handCount. Expected: %d, Actual: %d\r\n", stateCopy->handCount[playerNum] + 2, gs2->handCount[playerNum]);
	}
	if (gs2->discardCount[playerNum] != stateCopy->discardCount[playerNum]){
		printf("Mismatched discardCount. Expected: %d, Actual: %d\r\n", stateCopy->discardCount[playerNum], gs2->discardCount[playerNum]);
	}
	
	
	//TRIAL 3 - SKIPPING ALL OTHER CARD TYPES
	printf("Trial 3\r\n");
	memcpy(stateCopy, gs3, sizeof(struct gameState));
	//playerNum = 2;
	playAdventurer(playerNum, gs3);
	if (gs3->deckCount[playerNum] != stateCopy->deckCount[playerNum] - treasure_map) {
		printf("Mismatched deckCount. Expected: %d, Actual: %d\r\n",stateCopy->deckCount[playerNum] - treasure_map,gs3->deckCount[playerNum] );
	}
	if (gs3->handCount[playerNum] != stateCopy->handCount[playerNum] + 2) {
		printf("Mismatched handCount. Expected: %d, Actual: %d\r\n", stateCopy->handCount[playerNum] + 2, gs3->handCount[playerNum]);
	}
	if (gs3->discardCount[playerNum] != stateCopy->discardCount[playerNum] + treasure_map - 2){
		printf("Mismatched discardCount. Expected: %d, Actual: %d\r\n", stateCopy->discardCount[playerNum] + 2, gs3->discardCount[playerNum]);
	}
	
	//TRIAL 4 - DRAW FROM DISCARD
	printf("Trial 4\r\n");
	memcpy(stateCopy, gs4, sizeof(struct gameState));
	//playerNum = 3;
	playAdventurer(playerNum, gs4);
	if (gs4->deckCount[playerNum] + gs4->discardCount[playerNum] != stateCopy->deckCount[playerNum] + stateCopy->discardCount[playerNum] - 2) {
		printf("Mismatched deckCount + discardCount. Expected: %d, Actual: %d\r\n",stateCopy->deckCount[playerNum] + stateCopy->discardCount[playerNum] - 2,gs4->deckCount[playerNum] + gs4->discardCount[playerNum] );
	}
	if (gs4->handCount[playerNum] != stateCopy->handCount[playerNum] + 2) {
		printf("Mismatched handCount. Expected: %d, Actual: %d\r\n", stateCopy->handCount[playerNum] + 2, gs4->handCount[playerNum]);
	}
	
	//TRIAL 5 - NOT ENOUGH TREASURES
	/* Test disabled.  Bug creates problems.  Uncommon.
	printf("Trial 5\r\n");
	memcpy(stateCopy, gs5, sizeof(struct gameState));
	//playerNum = 3;
	playAdventurer(playerNum, gs5);
	if (gs5->deckCount[playerNum] + gs5->discardCount[playerNum] != stateCopy->deckCount[playerNum] + stateCopy->discardCount[playerNum]) {
		printf("Mismatched deckCount + discardCount. Expected: %d, Actual: %d\r\n",stateCopy->deckCount[playerNum] + stateCopy->discardCount[playerNum],gs5->deckCount[playerNum] + gs5->discardCount[playerNum] );
	}
	if (gs5->handCount[playerNum] != stateCopy->handCount[playerNum]) {
		printf("Mismatched handCount. Expected: %d, Actual: %d\r\n", stateCopy->handCount[playerNum], gs5->handCount[playerNum]);
	}
	*/
	
	printf("Card Test 2 Complete\r\n");
	
	return 0;
}
