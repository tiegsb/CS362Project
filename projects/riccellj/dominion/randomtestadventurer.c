#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

#define NOISY_TEST 1

int main(int argc, char *argv[]){
	srand(time(null));
	int seed	
   	int players = 2;
	int gameCards[10] = {sea_hag, council_room, feast, garden, cutpurse, remodel, smithy, village, baron, great_hall};
	int maxHandCount = 100;
	struct gameState state;
	struct gameState pre;
	int gameStateCompare;
	int status;
	int err = 0;
	int cntr;
	int choice1 = 0;
	int choice2 = 0;
	int choice3 = 0;
   	int bonus = 0;
	int handPos;
	int adventurers[MAX_HAND];
	int mines[MAX_HAND];
	int golds[MAX_HAND]
	int i,j,player,handCount;
	int loops = 1000;

	for(i=0; i<MAX_HAND; i++){
		adventurers[MAX_HAND] = adventurer;
		mines[MAX_HAND] = mine;
		golds[i] = gold;
	
	}
   
return 0;
}
