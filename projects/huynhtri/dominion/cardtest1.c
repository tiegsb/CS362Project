/*************************************************
* Name: Solomon Huynh
* Class: CS362 Software Engineering 2
* Term: Fall 2015
* File: cardtest1.c
* Description: Testing smithyCard function.
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

    printf("Testing smithyCard function:\n");
    int i;
    //Loops through all four players for testing purposes
    for(i = 0; i < 4; i++){
        printf("\nTesting player %d\n", i + 1);
        //Set up whose turn it is
        G.whoseTurn = i;

        //Reset the played cards for the next player
        G.playedCards[0] = -1;
        G.playedCardCount = 0;

        //Put the smithy card in the player's hands
        G.hand[i][0] = smithy;
        G.handCount[i] = 1;

        printf("Playing smithy card...\n");

        //Run smithy card
        smithyCard(&G, 0);

        //Confirm if smithyCard is removed from the hand
        if(G.hand[i][0] != smithy)
            printf("Confirmed removal of smithy card: PASS\n");
        else
            printf("Confirmed removal of smithy card: Fail\n");

        //Check if the total cards in hand is 2
        if(G.handCount[i] == 3)
            printf("Confirmed 3 cards drawn in hand: %d - PASS\n", G.handCount[i]);
        else
            printf("Confirmed 3 cards drawn in hand: %d - FAIL\n", G.handCount[i]);

        //Check if the card is discarded into the played pile
        if(G.playedCards[0] == smithy)
            printf("Confirmed smithy card (13) in played pile: %d - PASS\n", G.playedCards[0]);
        else
            printf("Confirmed smithy card (13) in played pile: %d - FAIL\n", G.playedCards[0]);
    }

    printf("\nTesting complete...\n\n");

    return 0;

}
