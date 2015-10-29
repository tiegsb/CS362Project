/*************************************************************************************************
 * Author:                 Drew Machowicz
 * Date Created:           October 19, 2015
 * Last Modification Date: October 23, 2015
 * File Name:              unittest3.c
 * Overview:
 *   Unit tests for gain card function
 ************************************************************************************************/
#include "dominion.h"
#include "interface.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int testGainCard() {
	//intialization steps below borrowed from unittest2
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
    memcpy(newGame.hand[player], currHand, sizeof(int)*handNum);


    //kingdom cards uses for tets
    int k[10] = {adventurer, ambassador, embargo, smithy, village, feast, mine, gardens, baron, council_room};

    //itnialzieGame supplies all the supplyCounts of cards
    printf("Testing GainCard Fuction with toFlag at 0...\n");
    printf("Intializing Game...\n");
    initializeGame(numPlayers, k, seed, &newGame);
    printf("Testing toFlag 0\n");


    int i = 0;
    int handCardsBefore = 0;
    int discardCardsBefore = 0;
    int deckCountBefore = 0;
    int supplyCountBefore = 0;
    int toFlag = 0;
    //this tests for toFlag to 0 for all cards in current hand
    for (i = 0; i <= handNum; i++) {
    	//check cards in hand before
    	handCardsBefore = newGame.handCount[player];
    	discardCardsBefore = newGame.discardCount[player];
    	deckCountBefore = newGame.deckCount[player];
    	supplyCountBefore = newGame.supplyCount[newGame.hand[player][i]];

    	gainCard(newGame.hand[player][i], &newGame, toFlag, player);

    	//handcount the same
    	if (handCardsBefore == newGame.handCount) {
    		//discardcount one more
    		if (discardCardsBefore++ == newGame.discardCount[player]) {
    			//deckcountthe same
    			if (deckCountBefore == newGame.deckCount[player]) {
    				//supplypos one less
    				if ((supplyCountBefore--) == newGame.supplyCount[newGame.hand[player][i]]) {
    					printf("Passed! Card counts correct!\n");
    				} else {
    					printf("Supply count off\n");
    				}
    			} else {
    				printf("Deck count off\n");
    			}
    		} else {
    			printf("Discard count off\n");
    		}
    		
    	} else {
    		printf("hand count off\n");
    	}
    }

 
    currHand[0] = copper;  //worth 1
    currHand[1] = silver;  //worth 3
    currHand[2] = estate;    //
    currHand[3] = remodel; //can trash a card
    currHand[4] = curse; //don't want it

    struct gameState newGame2;
    memcpy(newGame2.hand[player], currHand, sizeof(int)*handNum);


    //itnialzieGame supplies all the supplyCounts of cards
    printf("Testing UpdateCoins Fuction...\n");
    printf("Intializing Game...\n");
    initializeGame(numPlayers, k, seed, &newGame2);
    printf("Testing toFlag 0\n");

    handCardsBefore = 0;
    discardCardsBefore = 0;
    deckCountBefore = 0;
    toFlag = 1;
    supplyCountBefore = 0;
    //this tests for toFlag to 0 for all cards in current hand
    for (i = 0; i <= handNum; i++) {
    	//check cards in hand before
    	handCardsBefore = newGame2.handCount[player];
    	discardCardsBefore = newGame2.discardCount[player];
    	deckCountBefore = newGame2.deckCount[player];
    	supplyCountBefore = newGame2.supplyCount[newGame2.hand[player][i]];


    	gainCard(newGame2.hand[player][i], &newGame2, toFlag, player);

    	//handcount the same
    	if (handCardsBefore == newGame2.handCount) {
    		//discardcount the same
    		if (discardCardsBefore == newGame2.discardCount[player]) {
    			//deckcount one more
    			if (deckCountBefore++ == newGame2.deckCount[player]) {
    				//supplypos one less
    				if (supplyCountBefore-- == newGame2.supplyCount[newGame2.hand[player][i]]) {
    					                       printf("Passed! Card counts correct!\n");
                    } else {
                        printf("Supply count off\n");
                    }
                } else {
                    printf("Deck count off\n");
                }
            } else {
                printf("Discard count off\n");
            }
            
        } else {
            printf("hand count off\n");
        }
    }
    currHand[0] = copper;  //worth 1
    currHand[1] = silver;  //worth 2
    currHand[2] = estate;    //
    currHand[3] = remodel; //can trash a card
    currHand[4] = curse; //don't want it

    struct gameState newGame3;
    memcpy(newGame3.hand[player], currHand, sizeof(int)*handNum);


    //itnialzieGame supplies all the supplyCounts of cards
    printf("Testing UpdateCoins Fuction...\n");
    printf("Intializing Game...\n");
    initializeGame(numPlayers, k, seed, &newGame3);
    printf("Testing toFlag 0\n");

    handCardsBefore = 0;
    discardCardsBefore = 0;
    deckCountBefore = 0;
    supplyCountBefore = 0;
    toFlag = 2;
    //this tests for toFlag to 0 for all cards in current hand
    for (i = 0; i <= handNum; i++) {
    	//check cards in hand before
    	handCardsBefore = newGame3.handCount[player];
    	discardCardsBefore = newGame3.discardCount[player];
    	deckCountBefore = newGame3.deckCount[player];
    	supplyCountBefore = newGame3.supplyCount[newGame3.hand[player][i]];

    	gainCard(newGame3.hand[player][i], &newGame3, toFlag, player);

    	//handcount one more
    	if (handCardsBefore++ == newGame3.handCount) {
    		//discardcount the same
    		if (discardCardsBefore == newGame3.discardCount[player]) {
    			//deckcount the same
    			if (deckCountBefore == newGame3.deckCount[player]) {
    				//supplypos one less
    				if (supplyCountBefore-- == newGame3.supplyCount[newGame3.hand[player][i]]) {
                        printf("Passed! Card counts correct!\n");
                    } else {
                        printf("Supply count off\n");
                    }
                } else {
                    printf("Deck count off\n");
                }
            } else {
                printf("Discard count off\n");
            }
            
        } else {
            printf("hand count off\n");
        }
    }
	return 0;
}

 int main() {
    testGainCard();
    return 0;
}