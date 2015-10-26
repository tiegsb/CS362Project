/*
 * Title: unittest3.c
 * Author: Dustin Chase
 * Email: chased@oregonstate.edu
 * Date: 10/25/2015
 * Description: Testing function getCost()
 * Testing for: - Are all card costs accurate? 
 */

 #include "dominion.h"
 #include "dominion_helpers.h"
 #include <string.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include "rngs.h"
 #include "interface.h"
 #include <time.h>
 #include <assert.h>
 
int cardCost[27] = {0, 2, 5, 8, 0, 3, 6, 6, 5, 4, 4, 5, 4, 4, 3, 4, 3, 5, 3, 5, 3, 4, 2, 5, 4, 4, 4};

int main () {
srand(time(NULL));

int i; 
int cost; 

for (i = 0; i < 3000; i++) {
	int test = rand() % 27;
	cost = getCost(test);
	assert(cost == cardCost[test]);
}

printf("\nAll card cost tests passed!\n");

return 0; 
}