/*************************************************
* Name: Solomon Huynh
* Class: CS362 Software Engineering 2
* Term: Fall 2015
* File: unittest4.c
* Description: Testing getCost function using random testing methods.
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

    /*Sets up the card cost of each card into an array.
    Index       Card Name       Cost    |   Index       Card Name       Cost
    0           Curse           0           1           estate          2
    2           duchy           5           3           province        8
    4           copper          0           5           silver          3
    6           gold            6           7           adventurer      6
    8           council_room    5           9           feast           4
    10          gardens         4           11          mine            5
    12          remodel         4           13          smithy          4
    14          village         3           15          baron           4
    16          great_hall      3           17          minion          5
    18          steward         3           19          tribute         5
    20          ambassador      3           21          cutpurse        4
    22          embargo         2           23          outpost         5
    24          salvager        4           25          sea_hag         4
    26          treasure_map    4
    */
    int cardCost[27] = {0, 2, 5, 8, 0, 3, 6, 6, 5, 4, 4, 5, 4, 4, 3, 4, 3, 5, 3, 5, 3, 4, 2, 5, 4, 4, 4};

    //Sets up a random seed based on the time
    srand(time(NULL));


    //Begin testing on function "int getCost(int cardNumber)"
    printf("Testing getCost:\n");
    printf("Random method\n");

    int i;
    int cost, cardIndex;
    for(i = 0; i < 2000; i++){
        //Randomly choose a number from 0-26 (number of available cards to choose from)
        cardIndex = rand() % 27;

        cost = getCost(cardIndex);
        assert(cost == cardCost[cardIndex]);
    }

    printf("All assertion tests are successful\n\n");

    return 0;
}


