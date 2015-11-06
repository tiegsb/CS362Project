/*************************************************
* Name: Solomon Huynh
* Class: CS362 Software Engineering 2
* Term: Fall 2015
* File: randomtestcard.c
* Description: Random testing on the smithyCard function.
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

    printf("Testing smithyCard function:\n");
    printf("Random test running 2000 times...\n");
    int i;
    int player;
    int smithyPosition;
    int removalError = 0;
    int drawError = 0;
    int discardError = 0;
    //Randomly loops though each of the four players
    for(i = 0; i < 2000; i++){
        //Initialize game with 4 players
        initializeGame(4, k, seed, &G);

        //Randomly picks between four players
        player = rand() % 4;

        //Randomly picks the position to place the smithy card
        smithyPosition = rand() % 10;

        //Set up whose turn it is
        G.whoseTurn = player;

        //Reset the played cards count
        G.playedCardCount = 0;

        //Put the smithy card in the player's hands
        G.hand[player][smithyPosition] = smithy;
        G.handCount[player] = 1;

        //Run smithy card
        smithyCard(&G, smithyPosition);

        //Confirm if smithyCard is removed from the hand
        if(G.hand[player][smithyPosition] == smithy)
            removalError++;

        //Check if the total cards in hand is 3
        if(G.handCount[player] != 3)
            drawError++;

        //Check if the card is discarded into the played pile
        if(G.playedCardCount != 1)
            discardError++;

    }

    //Print out the test results
    printf("Removal errors are: %d\n", removalError);
    printf("Draw errors are: %d\n", drawError);
    printf("Draw errors are: %d\n", discardError);
    printf("\nTesting complete...\n");

    return 0;

}
