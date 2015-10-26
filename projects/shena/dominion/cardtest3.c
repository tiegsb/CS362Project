#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "assert.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

//=================
//TEST VILLAGE CARD
//=================
int main(int argc, char **argv){
	
	printf("\n\nVillage Card Test \n\n");
	printf("Creating new gameState... \n");
	struct gameState *s = newGame();
	int numCards;
	assert(s != NULL);
	printf("gameState created\n\n");
	int k[10] = {outpost, smithy, embargo, baron, adventurer, village, gardens, mine, great_hall, feast};
	printf("Initializing Game...\n");
	initializeGame(2,k,21,s);
	numCards = s->handCount[s->whoseTurn];
	if(s->outpostPlayed == 0){
		printf("outpostPlayed == 0... Pass!\n");
	}else{
		printf("outPostPlayed == 0... Fail.\n");
	}
	if(s->phase == 0){
		printf("s->phase == 0... Pass!\n");
	}else{
		printf("s->phase == 0... Fail.\n");
	}
	if(s->numActions == 1){
		printf("numActions == 1... Pass!\n");
	}else{
		printf("numActions == 1... Fail.\n");
	}
	if(s->numBuys == 1){
		printf("numBuys == 1... Pass!\n");
	}else{
		printf("numBuys == 1... Fail!\n");
	}
	if(s->playedCardCount == 0){
		printf("playedCardCount == 0... Pass!\n");
	}else{
		printf("playedCardCount == 0... Fail!\n");
	}
	if(s->whoseTurn == 0){
		printf("numBuys == 0... Pass!\n");
	}else{
		printf("numBuys == 0... Fail!\n");
	}
	if(s->handCount[s->whoseTurn] == numCards){
		printf("s->handCount[s->whoseTurn] == numCards... Pass!\n");
	}else{
		printf("s->handCount[s->whoseTurn] == numCards... Fail!\n");
	}
	printf("\nGame initialized\n\n");
	int r = cardEffect(village, 0, 0, 0, s, 0, 0);
	printf("Checking if card count correctly decreased...");
	if(s->handCount[s->whoseTurn] == (numCards)){
		printf(" Success!\n");
	}else{
		printf(" Failed!\n");
	}
	printf("Checking return value...");
	if(r == 0){
		printf(" Success!\n");
	}else{
		printf(" Failed!\n");
	}
	printf("Checking if numActions increased...");
	if(s->numActions == 3){
		printf(" Success!\n");
	}else{
		printf(" Failed!\n");
	}
	
	printf("\n\nVillage Card Test Completed!\n\n");
	
	return 0;
	
}