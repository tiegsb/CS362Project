/*************************************************************************************************
 * Author:                 Drew Machowicz
 * Date Created:           October 19, 2015
 * Last Modification Date: October 17, 2015
 * File Name:              unittest2.c
 * Overview:
 *   Unit tests for adventurer card
 ************************************************************************************************/
#include "dominion.h"
#include "interface.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main() {

	//intialization steps below borrowed from unittest2
    //seed for initialize game
    int seed = 12345;
    int i = 0;
    int advFlag = 0;
    //here you can choose number of players, between 2 and 4
    int numPlayers = 2;
    //here you can choose player number, starting at 0, up to # of players -1
    int player = 0;
    //players start with 5 cards
    int handNum = 5;
    //this one should pass
    //array to hold current cards
	int currHand[handNum];
    //kingdom cards uses for tets
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
    printf("Testing playAdventurer Fuction for player %d...\n", player);
    printf("Intializing Game...\n");
    initializeGame(numPlayers, k, seed, &newGame);

    printf("Check adventurer card is in hand of player %d...\n", player);
    for(i = 0; i < handNum; i++) {
    	if (currHand[i] == adventurer) {
    		printf("Adventurer is in hand...\n");
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
    	playAdventurer(&newGame);

    	if ((deckCountBefore + discardCountBefore) == (newGame.deckCount[player] + newGame.discardCount[player])){
    		printf("Passed! Discard + Deck counts are the same before and after (no new or disappeared cards)\n");
    	} else {
    		if (deckCountBefore + discardCountBefore > (newGame.deckCount[player] + newGame.discardCount[player])) {
    			printf("Failed! There are cards missing!\n");
    		} else {
    			printf("Failed! There are too many cards!\n");
    		}
    	}


    	//check hand has two more cards
    	if (handNumBefore+2 == newGame.handCount[player]) {
    		printf("Passed! Number of cards in the hand is correct\n");
    	} else {
    		printf("Failed! Number of cards in hand is wrong!\n");
    	}

    	//check hand has two more treasure cards
    	for (i = 0; i <= handNum; i++){
    		if ((currHand[i] == copper) || (currHand[i] == silver) || (currHand[i] == gold)){
    			drawntreasureAfter++;
    		}
    	}
    	if ((drawntreasureBefore+2) == drawntreasureAfter){
    		printf("Passed! Number of treasure cards is correct!\n");
    	} else {
    		printf("Failed! Number of treasure cards is incorrect!\n");
    	}
    }
    player++;
    }
	return 0;
}
