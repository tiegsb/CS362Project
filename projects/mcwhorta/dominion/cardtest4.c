#include "dominion.h"
#include "interface.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main() {
    int seed = 12345;
    int i = 0;
    int advFlag = 0;
    int numPlayers = 2;
    int player = 0;
    int handNum = 5;
    int currHand[handNum];
    int k[10] = {adventurer, ambassador, embargo, smithy, village, feast, mine, gardens, baron, council_room};

while (player <= numPlayers){
    advFlag = 0;
    i = 0;
    handNum = 5;
    currHand[0] = copper;  //worth 1
    currHand[1] = silver;  //worth 3
    currHand[2] = estate;    //
    currHand[3] = remodel; //can trash a card
    currHand[4] = adventurer; 

    struct gameState newGame;
    memcpy(newGame.hand[player], currHand, sizeof(int)*handNum);
    //itnialzieGame supplies all the supplyCounts of cards
    printf("TESTING adventurer card\n");
    initializeGame(numPlayers, k, seed, &newGame);

    for(i = 0; i < handNum; i++) {
    	if (currHand[i] == adventurer) {
    		advFlag = 1;
    		break;
    	} else {
    		continue;
    	}
    }


    int drawntreasureBefore, drawntreasureAfter = 0;
    int handNumBefore = handNum;
    int deckCountBefore = newGame.deckCount[player];
    int discardCountBefore = newGame.discardCount[player];

    if (!advFlag) {
    	printf("No Adventurer Card In Hand!\n");
    } else {
    	//check number of treasuare cards before
    	for (i = 0; i <= handNum; i++){
    		if ((currHand[i] == copper) || (currHand[i] == silver) || (currHand[i] == gold)){
    			drawntreasureBefore++;
    		}
    	}

    	if ((deckCountBefore + discardCountBefore) != (newGame.deckCount[player] + newGame.discardCount[player])){
		printf("TESTS FAILED\n");
    	}


    	//check hand has two more cards
    	if (handNumBefore+2 != newGame.handCount[player]) {
		printf("TESTS FAILED\n");
    	}

    	//check hand has two more treasure cards
    	for (i = 0; i <= handNum; i++){
    		if ((currHand[i] == copper) || (currHand[i] == silver) || (currHand[i] == gold)){
    			drawntreasureAfter++;
    		}
    	}
    	if ((drawntreasureBefore+2) != drawntreasureAfter){
		printf("TESTS FAILED");
    	}
    }
    player++;
    }
	return 0;
}
