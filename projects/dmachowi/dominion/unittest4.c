/*************************************************************************************************
 * Author:                 Drew Machowicz
 * Date Created:           October 19, 2015
 * Last Modification Date: October 23, 2015
 * File Name:              unittest4.c
 * Overview:
 *   Unit tests for discard card function 
 ************************************************************************************************/
#include "dominion.h"
#include "interface.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int checkDiscardCard() {
	 //seed for initialize game
    int seed = 12345;
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
    currHand[4] = curse; //don't want it

    struct gameState newGame;

    //kingdom cards uses for tets
    int k[10] = {adventurer, ambassador, embargo, smithy, village, feast, mine, gardens, baron, council_room};
    int i = 0;
    // //create new game

    printf("Testing DiscardCard Fuction...\n");
    printf("Intializing Game...\n");
    initializeGame(numPlayers, k, seed, &newGame);
    printf("Copying premade hand to current player's hand\n");
    memcpy(newGame.hand[player], currHand, sizeof(int)*handNum);
    printf("Calling DiscardCard function...\n");

    int playedCardCountBefore = 0;
    int handCountBefore = 0;
    for(i = 4; i >= 0; i--) {
    	//trash flag is 0
    	playedCardCountBefore = newGame.playedCardCount;
    	handCountBefore = newGame.handCount[player];
		discardCard(i, player, &newGame, i);
		if (newGame.playedCards[newGame.playedCardCount] == newGame.hand[player][i]){
			if (playedCardCountBefore++ == newGame.playedCardCount) {
				if ((i == (newGame.handCount[player]-1)) && (handCountBefore-- == newGame.handCount[player])) {
					printf("Passed!\n");
				} else if ((newGame.handCount[player] == 1) && (handCountBefore-- == newGame.handCount[player])) {
					printf("Passed!\n"); 
				} else if ((newGame.hand[player][i] == newGame.hand[player][newGame.handCount[player]-1]) &&
							((newGame.hand[player][newGame.handCount[player]-1]) == -1) && 
							(handCountBefore-- == newGame.handCount[player])) {
					printf("passed!\n");

				} else {
					printf("nope\n");
				}
				
			} else {
				printf("not passed, played card count is off!\n");
			}	
		} else {
			printf("not passed, played card is wrong!!\n");
		}
		
	}
	return 0;
}

 int main() {
    checkDiscardCard();
    return 0;
}