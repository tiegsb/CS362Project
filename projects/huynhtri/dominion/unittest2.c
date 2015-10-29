/*************************************************
* Name: Solomon Huynh
* Class: CS362 Software Engineering 2
* Term: Fall 2015
* File: unittest2.c
* Description: Testing updateCoins function using random testing methods.
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

    //Begin testing on function "int updateCoins(int player, struct gameState *state, int bonus)"
    printf("Testing updatesCoins:\n");
    printf("Random method\n");

    int i, j;
    int testFunction;
    int totalCoins;
    int bonus;
    G.handCount[0] = 5;

    for(i = 0; i < 100; i++){
        totalCoins = 0;
        bonus = rand() % 10;
        totalCoins += bonus;
        //Supplies the hand with a random cards and adds up the total coins in hand
        for(j = 0; j < 5; j++){
            G.hand[0][j] = rand() % 27;
            if(G.hand[0][j] == 4)
                totalCoins += 1;
            if(G.hand[0][j] == 5)
                totalCoins += 2;
            if(G.hand[0][j] == 6)
                totalCoins += 3;
        }

        testFunction = updateCoins(0, &G, bonus);

        assert(totalCoins == G.coins);
    }

    printf("All assertion tests are successful\n\n");

    return 0;

}
