/*************************************************
* Name: Solomon Huynh
* Class: CS362 Software Engineering 2
* Term: Fall 2015
* File: randomtestadventurer.c
* Description: Random testing on the adventurerCard function.
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

    printf("Testing adventurerCard function:\n");
    int i, j;
    int randomNumber;
    int numCopper = 0;
    int numSilver = 0;
    int numGold = 0;
    //Loops through all four players for testing purposes
    for(i = 0; i < 20; i++){
        printf("\nTest number %d\n", i + 1);
        //Initialize game with 4 players
        initializeGame(2, k, seed, &G);
        G.whoseTurn = 0;

        //Put the adventurer card in the player's hands
        G.hand[0][0] = adventurer;
        G.handCount[0] = 1;

        //Randomly generate cards in the deck
        for(j = 0; j < 50; j++){
            randomNumber = rand() % 50;
            if(randomNumber >= 27 && randomNumber < 35)
                G.deck[0][j] = 4;
            else if(randomNumber >=35 && randomNumber < 42)
                G.deck[0][j] = 5;
            else if(randomNumber >=42 && randomNumber < 50)
                G.deck[0][j] = 6;
            else
                G.deck[0][j] = randomNumber;
        }
        G.deckCount[0] = 50;

        printf("Playing adventurer card...\n");

        //Run adventurer card
        adventurerCard(&G);

        //Confirm if adventurer card is removed from the hand
        if(G.hand[0][0] != adventurer)
            printf("Confirmed removal of adventurer card: PASS\n");
        else
            printf("Confirmed removal of adventurer card: FAIL\n");

        //Check if the total cards in hand is 2
        if(G.handCount[0] == 2)
            printf("Confirmed total cards on hand is 2: %d - PASS\n", G.handCount[i]);
        else
            printf("Confirmed total cards on hand is 2: %d - FAIL\n", G.handCount[i]);

        //Increases the count of each coin type chosen
        for(j = 0; j < 2; j++){
            if(G.hand[0][j] == copper)
                numCopper++;
            if(G.hand[0][j] == silver)
                numSilver++;
            if(G.hand[0][j] == gold)
                numGold++;
        }

        printf("Position 1 is: %d\n", G.hand[0][0]);
        printf("Position 2 is: %d\n", G.hand[0][1]);
        printf("Position 3 is: %d\n", G.hand[0][2]);
    }

    printf("\nNumber of bronze coins selected from test: %d\n", numCopper);
    printf("Number of silver coins selected from test: %d\n", numSilver);
    printf("Number of gold coins selected from test: %d\n", numGold);
    printf("\nTesting complete...\n\n");

    return 0;

}
