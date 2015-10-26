/*************************************************
* Name: Solomon Huynh
* Class: CS362 Software Engineering 2
* Term: Fall 2015
* File: cardtest3.c
* Description: Testing councilRoomCard function.
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

    printf("Testing councilRoomCard function:\n");
    int i, j;
    //Loops through all four players for testing purposes
    for(i = 0; i < 4; i++){
        //Initialize game with 4 players
        initializeGame(4, k, seed, &G);

        printf("\nTesting player %d\n", i + 1);
        //Set up whose turn it is
        G.whoseTurn = i;

        //Reset the played cards for the next player
        G.playedCards[0] = -1;
        G.playedCardCount = 0;

        //Set up the number of buys
        G.numBuys = 0;

        //Sets each player's hand count to 0
        for(j = 0; j < 4; j++)
            G.handCount[j] = 0;

        //Put the council room card in the player's hands
        G.hand[i][0] = council_room;
        G.handCount[i] = 1;

        printf("Playing council room card...\n");

        //Run council room card
        councilRoomCard(&G, 0);

        //Confirm if council room card is removed from the hand
        if(G.hand[i][0] != council_room)
            printf("Confirmed removal of council room card: PASS\n");
        else
            printf("Confirmed removal of council room card: FAIL\n");

        //Check if the total cards in hand is 4
        if(G.handCount[i] == 4)
            printf("Confirmed 4 card drawn in hand: %d - PASS\n", G.handCount[i]);
        else
            printf("Confirmed 4 card drawn in hand: %d - FAIL\n", G.handCount[i]);

        //Confirm if the number of buys is 1
        if(G.numBuys == 1)
            printf("Confirmed 1 number of buy added: %d - PASS\n", G.numBuys);
        else
            printf("Confirmed 1 number of buy added: %d - FAIL\n", G.numBuys);

        //Confirm if the hand count for all OTHER players is 1
        for(j = 0; j < 4; j++){
            if(j != i){
                if(G.handCount[j] == 1)
                    printf("Confirmed 1 card drawn from player %d: %d - PASS\n", j + 1, G.handCount[j]);
                else
                    printf("Confirmed 1 card drawn from player %d: %d - FAIL\n", j + 1, G.handCount[j]);
            }
        }
    }

    printf("\nTesting complete...\n\n");

    return 0;

}
