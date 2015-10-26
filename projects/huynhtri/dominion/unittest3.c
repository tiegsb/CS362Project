/*************************************************
* Name: Solomon Huynh
* Class: CS362 Software Engineering 2
* Term: Fall 2015
* File: unittest3.c
* Description: Testing buyCard function using simple testing methods.
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

    //Pulled from playdom.c
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
        sea_hag, tribute, smithy};

    //Initialize the game state and variables needed to run buyCard
    struct gameState G;
    int seed = 1000; //Sets up the seed number

    //Initializes the game with 2 players only
    initializeGame(2, k, seed, &G);

    //Begin testing on function "int buyCard(int supplyPos, struct gameState *state)"
    printf("Testing buyCard:\n");

    int i, j;
    int testFunction;

    //Supplies all card types with i cards
    for(i = 0; i < 27; i++){
        G.supplyCount[i] = 10;
    }

    //Tests the number of buys left and assert to ensure the errors are correct
    for(i = 0; i < 27; i++){
        G.numBuys = i;
        G.coins = 10;
        //If numBuys is 0, tests if the buy function errors
        if(G.numBuys == 0){
            testFunction = buyCard(i, &G);
            assert(testFunction == -1);
        }
        else{
            testFunction = buyCard(i, &G);
            assert(G.numBuys == (i - 1));
        }
    }

    //Supplies all card types with i cards
    for(i = 0; i < 27; i++){
        G.supplyCount[i] = 4;
    }

    //Tests the supply count and assert to ensure the errors are correct
    for(i = 0; i < 5; i++){
        for(j = 0; j < 27; j++){
            G.numBuys = 5;
            G.coins = 10;

            //If supplyCount for the card is 0, tests if the buy function errors
            if(G.supplyCount[j] == 0){
                testFunction = buyCard(j, &G);
                assert(testFunction == -1);
            }
            else{
                testFunction = buyCard(j, &G);
                assert(G.supplyCount[j] == (4 - i - 1));
            }
        }
    }

    //Supplies all card types with i cards
    for(i = 0; i < 27; i++){
        G.supplyCount[i] = 4;
    }

    //Tests the coin count and assert to ensure the errors are correct
    for(i = 0; i < 10; i++){
        G.numBuys = 5;
        G.coins = i;

        //If there isn't enough coins, the test function will check if the buy function returns -1 with an assert
        if(G.coins < getCost(6)){
            testFunction = buyCard(6, &G);
            assert(testFunction == -1);
        }
        else{
            testFunction = buyCard(6, &G);
            assert(G.coins == (i - getCost(6)));
        }
    }

    printf("All assertion tests are successful\n\n");

    return 0;
}
