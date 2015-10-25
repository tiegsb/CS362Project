/*************************************************************************************************
 * Author:                 Drew Machowicz
 * Date Created:           October 19, 2015
 * Last Modification Date: October 25, 2015
 * File Name:              cardtest1.c
 * Overview:
 *   Unit tests for remodel card
 ************************************************************************************************/
#include "dominion.h"
#include "interface.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
//choice 1 is card to trash, choice2 is card to gain

int main() {
	//intialization steps below borrowed from unittest2
    //seed for initialize game
    int seed = 12345;
    int i = 0;
    int rmFlag = 0;
    int trashFlag=0;
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
    int k[10] = {adventurer, ambassador, embargo, smithy, village, feast, mine, gardens, embargo, council_room};

	while (player <= numPlayers){
		rmFlag = 0;
		i = 0;
		handNum = 5;
		currHand[0] = copper;  //worth 1
    	currHand[1] = silver;  //worth 3
   		currHand[2] = estate;    //
    	currHand[3] = remodel; //can trash a card
    	currHand[4] = curse;   //lets trash this

    	struct gameState newGame;
    	memcpy(newGame.hand[player], currHand, sizeof(int)*handNum);
    	//itnialzieGame supplies all the supplyCounts of cards
    	printf("Testing playRemodel Fuction for player %d...\n", player);
   		printf("Intializing Game...\n");
    	initializeGame(numPlayers, k, seed, &newGame);

    	printf("Check remodel card is in hand of player %d...\n", player);
    	for(i = 0; i < handNum; i++) {
    		if (currHand[i] == remodel) {
    			printf("remodel is in hand...\n");
    			rmFlag = 1;
    			handPos = i;
    			break;
    		} else {
    			continue;
    		}
    	}


    	int discardCountBefore = newGame.discardCount[player]; //shoudl be +1
    	int handCountBefore = newGame.handCount[player];
    	int holder = 0; //gets -1 if new card is too expensive
    	//check discard trashed
    	//check new card goes to discard pile, so hand is -2, discard and trash
    	//void playRemodel(struct gameState *state, int handPos, int choice1, int choice2)


    	if (!rmFlag) {
    		printf("No Council Room Card In Hand!\n");
    	} else {
    	//try buying adventurer, shouldnt work becasue its too expensive
 	    //trashing the curse card, buy embargo that costs 2 so should work
    		playRemodel(&newGame, handPos, currHand[4], adventurer);
    		// if (holder == -1) {
    		// 	printf("Passed! Cannot buy a card that is more than +2 than trashed card\n");
    		// }

			playRemodel(&newGame, handPos, currHand[4], embargo);
			//check hand discarded remodel  
			rmFlag=0;
			for(i=0; i<newGame.handCount[player]; i++){
				if(newGame.hand[player][i] == remodel){
					rmFlag=1;
					printf("Fail! Remodel not discarded!\n");
					break;
				}
			}	
			if(!rmFlag) {
				printf("Pass! Remodel card was discarded\n");
			}
			//check it is in discard pile
			if(newGame.discard[player][newGame.discardCount[player]] != remodel){
				printf("Fail! Remodel not in discard pile last spot\n");
			} else {
				printf("Passed! Remodel in last discard pile spot\n");
			}
			//check curse is removed from hand
			for(i=0; i<newGame.handCount[player]; i++){
				if(newGame.hand[player][i] == curse){
					trashFlag=1;
					printf("Fail! Curse not trashed!\n");
					break;
				}
			}	
			// //check return is 0
			// if(holder != 0) {
			// 	printf("Fail! Return value not 0\n");
			// } else {
			// 	printf("Pass! Return value is 0\n");
			// }

			//hand should be two less
			if((handCountBefore-2)==newGame.handCount[player]){
				printf("Passed! Hand count is correct!\n");
			} else {
				printf("Failed! Hand count is wrong\n");
			}
			//discard should be two more
			if((discardCountBefore+2)==newGame.discardCount[player]){
				printf("Passed! discard count is correct!\n");
			} else {
				printf("Failed! discard count is wrong\n");
			}
		}
    	player++;
    }
	return 0;
}