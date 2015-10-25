/*************************************************************************************************
 * Author:                 Drew Machowicz
 * Date Created:           October 19, 2015
 * Last Modification Date: October 25, 2015
 * File Name:              cardtest4.c
 * Overview:
 *   Unit tests for smithy card
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
    int smithyFlag = 0;
    //here you can choose number of players, between 2 and 4
    int numPlayers = 2;
    //here you can choose player number, starting at 0, up to # of players -1
    int player = 0;
    //players start with 5 cards
    int handNum = 5;
    //this one should pass
    //array to hold current cards
	int currHand[handNum];
    currHand[0] = copper;  //worth 1
    currHand[1] = silver;  //worth 3
    currHand[2] = estate;    //
    currHand[3] = remodel; //can trash a card
    currHand[4] = smithy; 

    struct gameState newGame;
    memcpy(newGame.hand[player], currHand, sizeof(int)*handNum);


    //kingdom cards uses for tets
    int k[10] = {adventurer, ambassador, embargo, smithy, village, feast, mine, gardens, baron, council_room};

    //itnialzieGame supplies all the supplyCounts of cards
    printf("Testing playSmithy Fuction...\n");
    printf("Intializing Game...\n");
    initializeGame(numPlayers, k, seed, &newGame);

    printf("Check smithy card is in hand of player 0...\n");
    for(i = 0; i < handNum; i++) {
    	if (currHand[i] == smithy) {
    		printf("Smithy is in hand...\n");
    		smithyFlag = 1;
    		break;
    	} else {
    		continue;
    	}
    }


    int handCountBefore = 0;
    int discardCountBefore = 0;
    int playedCardCountBefore = 0;

    if (!smithyFlag) {
    	printf("No Smithy Card In Hand!\n");
    } else {
    	//hand should plus 3 cards and minus 1 card for discarded smithy
    	//discard count should be one more
    	handCountBefore = newGame.handCount[player];
    	discardCountBefore = newGame.discardCount[player];
    	playedCardCountBefore = newGame.playedCardCount;

    	playSmithy(&newGame, currHand[i]);

    	if ((handCountBefore + 2) == newGame.handCount[player]) {
    		printf("Passed! Hand count is correct!\n");
    	} else {
    		printf("Failed! Hand count is wrong!\n");
    	}

		if ((discardCountBefore++) == newGame.discardCount[player]){
			printf("Passed! Discard Card Count is correct!\n");
		} else {
			printf("Failed! Discard Card Count is wrong!\n");
		}

    	if(playedCardCountBefore++ == newGame.playedCardCount){
    		printf("Passed! Played card count increased\n");
		} else {
			printf("Failed! Played card count is wrong!\n");
		}
	}
	//check for second player
	//intialization steps below borrowed from unittest2
    //seed for initialize game
    i = 0;
    smithyFlag = 0;
    //here you can choose player number, starting at 0, up to # of players -1
    player = 1;
    //this one should pass
    //array to hold current cards
    currHand[0] = copper;  //worth 1
    currHand[1] = silver;  //worth 3
    currHand[2] = estate;    //
    currHand[3] = remodel; //can trash a card
    currHand[4] = smithy; 

    struct gameState newGame2;
    memcpy(newGame2.hand[player], currHand, sizeof(int)*handNum);

    //itnialzieGame supplies all the supplyCounts of cards
    printf("Testing playSmithy Fuction for next player...\n");
    printf("Intializing Game...\n");
    initializeGame(numPlayers, k, seed, &newGame2);

    printf("Check smithy card is in hand of player 1...\n");
    for(i = 0; i < handNum; i++) {
    	if (currHand[i] == smithy) {
    		printf("Smithy is in hand...\n");
    		smithyFlag = 1;
    		break;
    	} else {
    		continue;
    	}
    }


    handCountBefore = 0;
    discardCountBefore = 0;
    playedCardCountBefore = 0;

    if (!smithyFlag) {
    	printf("No Smithy Card In Hand!\n");
    } else {
    	//hand should plus 3 cards and minus 1 card for discarded smithy
    	//discard count should be one more
    	handCountBefore = newGame2.handCount[player];
    	discardCountBefore = newGame2.discardCount[player];
    	playedCardCountBefore = newGame2.playedCardCount;

    	playSmithy(&newGame2, currHand[i]);

    	if ((handCountBefore + 2) == newGame2.handCount[player]) {
    		printf("Passed! Hand count is correct!\n");
    	} else {
    		printf("Failed! Hand count is wrong!\n");
    	}

		if ((discardCountBefore++) == newGame2.discardCount[player]){
			printf("Passed! Discard Card Count is correct!\n");
		} else {
			printf("Failed! Discard Card Count is wrong!\n");
		}

    	if(playedCardCountBefore++ == newGame2.playedCardCount){
    		printf("Passed! Played card count increased\n");
		} else {
			printf("Failed! Played card count is wrong!\n");
		}
	}

	return 0;
}