/*************************************************
* Name: Solomon Huynh
* Class: CS362 Software Engineering 2
* Term: Fall 2015
* File: unittest1.c
* Description: Testing isGameOver function using random testing methods.
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

    //Begin testing on function "int isGameOver(struct gameState *state)"
    printf("Testing isGameOver:\n");
    printf("Random method\n");

    int i, j;
    int randomNumber, functionTest;

    //Sets the counter to 0 for 27 cards. If there is no supply, it'll mark as 1
    int supplyCheck[27];
    for(i = 0; i < 27; i++){
        supplyCheck[i] = 0;
    }

    int count;

    //Supplies all card types with i cards randomly
    for(i = 0; i < 27; i++){
        G.supplyCount[i] = 30;
    }

    //Loops through randomly decrementing one of the 27 supply counts each time to test game over
    for(i = 0; i < 1000; i++){
        count = 0;
        //Sets a random number and decrement the supply count on the card based on the random number
        randomNumber = rand() % 27;
        if(G.supplyCount[randomNumber] != 0)
            G.supplyCount[randomNumber]--;

        //Updates the supplyCheck for any empty ones and updates the count of 0 supply
        if(G.supplyCount[randomNumber] == 0)
            supplyCheck[randomNumber] = 1;
        for(j = 0; j < 27; j++){
            if(supplyCheck[j] == 1)
                count++;
        }

        //Runs isGameOver
        functionTest = isGameOver(&G);

        //Run assert statements to confirm that game over works correctly.
        //Checks if three supply piles are 0
        if(G.supplyCount[3] == 0)
            assert(functionTest == 1);
        else if(count >= 3)
            assert(functionTest == 1);
        else
            assert(functionTest == 0);
    }

    printf("All assertion tests are successful\n\n");

    return 0;

}
