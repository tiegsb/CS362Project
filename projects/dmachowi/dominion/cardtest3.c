/*************************************************************************************************
 * Author:                 Drew Machowicz
 * Date Created:           October 19, 2015
 * Last Modification Date: October 25, 2015
 * File Name:              unittest3.c
 * Overview:
 *   Unit tests for council room
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
    int crFlag = 0;
    //here you can choose number of players, between 2 and 4
    int numPlayers = 2;
    //here you can choose player number, starting at 0, up to # of players -1
    int player = 0;
    //players start with 5 cards
    int handNum = 5;
    //this one should pass
    //array to hold current cards
	int currHand[handNum];
	int handPos=0;
    //kingdom cards uses for tets
    int k[10] = {adventurer, ambassador, embargo, smithy, village, feast, mine, gardens, baron, council_room};

	while (player <= numPlayers){
		crFlag = 0;
		i = 0;
		handNum = 5;
		currHand[0] = copper;  //worth 1
    	currHand[1] = silver;  //worth 3
   		currHand[2] = estate;    //
    	currHand[3] = remodel; //can trash a card
    	currHand[4] = council_room; 

    	struct gameState newGame;
    	memcpy(newGame.hand[player], currHand, sizeof(int)*handNum);
    	//itnialzieGame supplies all the supplyCounts of cards
    	printf("Testing playCouncil_Room Fuction for player %d...\n", player);
   		printf("Intializing Game...\n");
    	initializeGame(numPlayers, k, seed, &newGame);

    	printf("Check council room card is in hand of player %d...\n", player);
    	for(i = 0; i < handNum; i++) {
    		if (currHand[i] == council_room) {
    			printf("council room is in hand...\n");
    			crFlag = 1;
    			handPos = i;
    			break;
    		} else {
    			continue;
    		}
    	}


    	int deckCountBefore = newGame.deckCount[player]; //should be -3
    	int discardCountBefore = newGame.discardCount[player]; //shoudl be +1
    	int handCounts[numPlayers];
    	int numOfBuysBefore = 0;
    	int j = 0;
    	for(j=0; j<=numPlayers; j++) {
    		//curr player +3, others plus+1
    		handCounts[i]=newGame.handCount[i];
    	}
    	numOfBuysBefore = newGame.numBuys;
    	playCouncil_Room(&newGame, handPos);

    	if (!crFlag) {
    		printf("No Council Room Card In Hand!\n");
    	} else {
		//plus 4 cards, -1 for discard
    		if((handCounts[player]+3) == newGame.handCount[player]) {
    			printf("Passed! current player handcount is correct\n");
    		} else {
    			printf("Failed! current player handcount is wrong\n");
    		}
		//plus 1 buy
    		if (numOfBuysBefore++ == newGame.numBuys){
    			printf("Passed! Number of buys is correct!\n");
    		} else {
    			printf("Failed! Number of buys is wrong!\n");
    		}
    	//deck count - 3
    		if((deckCountBefore-3) == newGame.deckCount[player]){
    			printf("Passed! Deck count is correct!\n");
    		} else {
    			printf("Failed! Deck count is wrong!\n");
    			printf("Should be %d but it is %d \n",(deckCountBefore-3), newGame.deckCount[player]);
    		}
    	//discard count +1
    		if((discardCountBefore++)==newGame.discardCount[player]){
    			printf("Passed! Discard count is correct\n");
    		} else {
    			printf("Failed! Discard count is wrong!\n");
    		}
		//all other players hand +1
			for(j = 0; j<numPlayers; j++){
				if (j == player) {
					continue;
				} else {
					if ((handCounts[i]++) == newGame.handCount[i]){
						printf("Player %d handcount is correct\n",i);
					} else {
						printf("Player %d handcount is incorrect\n",i);
					}
				}
			}    	
    	}
    	player++;
    }
	return 0;
}