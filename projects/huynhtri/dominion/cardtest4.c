/*************************************************
* Name: Solomon Huynh
* Class: CS362 Software Engineering 2
* Term: Fall 2015
* File: cardtest4.c
* Description: Testing villageCard function.
**************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "rngs.h"
#include <time.h>

#define DEBUG 0
#define NOISY_TEST 1

int main(){
    srand(time(NULL));
    struct gameState G;
    int seed = 1000;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};

    //Initialize game with 4 players
    initializeGame(4, k, seed, &G);

    printf("Testing villageCard function:\n");
    int i;
    //Loops through all four players for testing purposes
    for(i = 0; i < 4; i++){
        printf("\nTesting player %d\n", i + 1);
        //Set up whose turn it is
        G.whoseTurn = i;

        //Reset the played cards for the next player
        G.playedCards[0] = -1;
        G.playedCardCount = 0;

        //Set up the number of actions to 0
        G.numActions = 0;

        //Put the village card in the player's hands
        G.hand[i][0] = village;
        G.handCount[i] = 1;

        printf("Playing village card...\n");

        //Run village card
        villageCard(&G, 0);

        //Confirm if village card is removed from the hand
        if(G.hand[i][0] != village)
            printf("Confirmed removal of village card: PASS\n");
        else
            printf("Confirmed removal of village card: FAIL\n");

        //Check if the total cards in hand is 1
        if(G.handCount[i] == 1)
            printf("Confirmed 1 card drawn in hand: %d - PASS\n", G.handCount[i]);
        else
            printf("Confirmed 1 card drawn in hand: %d - FAIL\n", G.handCount[i]);

        //Confirm if the number of actions is 2
        if(G.numActions == 2)
            printf("Confirmed 2 actions added: %d - PASS\n", G.numActions);
        else
            printf("Confirmed 2 actions added: %d - FAIL\n", G.numActions);
    }

    printf("\nTesting complete...\n\n");

    return 0;

}
