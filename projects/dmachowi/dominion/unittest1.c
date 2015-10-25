/*************************************************************************************************
 * Author:                 Drew Machowicz
 * Date Created:           October 19, 2015
 * Last Modification Date: October 23, 2015
 * File Name:              unittest1.c
 * Overview:
 *   Unit tests for getCost function. I am testing for the correct cost of the cards. First this
 *   means that no card can cost more than 8 (province card is 8), and that no cost is 7. I am 
 *   also checking that the card number is a valid number, meaning it is between 0 and 25 inclusive.
 ************************************************************************************************/
#include "dominion.h"
#include "interface.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int testGetCost(int cardNumber) {
	//26 cards
	int r;
	r = getCost(cardNumber);

    if (r == -1) {
        printf("Fail! Invalid Card Number!\n");
    } else if (r == 7 || r > 8) {
        printf("Fail! Invalid Card Price\n");
    } else {
        printf("Pass! Card Price and Card Number are Valid\n");
    }
    return 0;
}

int main() {
    //to make sure only 0-25 is a valid card
    printf("Testing GetCost with numbers -1 to 30\n");
    int i = -1;
    for (i = -1; i <= 30; i++) {
        printf("i is %d\n",i);
        testGetCost(i);
    }
    printf("\nTesting GetCost Complete\n");
    return 0;
}

