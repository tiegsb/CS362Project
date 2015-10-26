/*************************************************************************************************
 * Author:                 Drew Machowicz
 * Date Created:           October 19, 2015
 * Last Modification Date: October 23, 2015
 * File Name:              unittest2.c
 * Overview:
 *   Unit tests for updateCoins function. This tests that a hand updates the coins correctly.
 *   I created a hand that contains 3 coin card (one copper, silver, gold), 1 bonus card, and
 *   one non-bonus card. The total should be 12 coins. The function checks that the returned 
 *   value is in fact 12. 
 ************************************************************************************************/
#include "dominion.h"
#include "interface.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int testUpdateCoins() {
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
    currHand[1] = silver;  //worth 2
    currHand[2] = gold;    //worth 3
    currHand[3] = minion; //this gives plus 2 for bonus
    currHand[4] = gardens; //no bonus
    int bonus = 2; //set to 2 for the festival card

    struct gameState newGame;

    //kingdom cards uses for tets
    int k[10] = {adventurer, ambassador, embargo, smithy, village, feast, mine, gardens, baron, council_room};

    // //create new game

    printf("Testing UpdateCoins Fuction...\n");
    printf("Intializing Game...\n");
    initializeGame(numPlayers, k, seed, &newGame);
    printf("Copying premade hand to current player's hand\n");
    memcpy(newGame.hand[player], currHand, sizeof(int)*handNum);
    printf("Calling update Coins function...\n");
    updateCoins (player, &newGame, bonus);

    //coin count should be 1 + 2 + 3 + 2 =8
    if (newGame.coins == 8) {
    	printf("Pass! UpdateCoin value is correct\n");
    } else {
    	printf("Fail! UpdateCoin value is incorrect\n");
    }
    return 0;
}

int main() {
    testUpdateCoins();
    printf("Testing UpdateCoins Complete...\n");
    return 0;
}