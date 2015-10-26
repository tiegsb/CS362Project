/*
Name: Rhett Guyer
Class: CS 362
Date: 10/25/15

Goal: The goal of this program is to test the "getCost" function.
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int checkCost(int cardNum, int quotedPrice, const char *Cards){
	int cardPrice = getCost(cardNum);
	if(cardPrice != quotedPrice && cardNum>=0 && cardNum<=26){
		printf("ERROR - The price of %d for the %s card is not equal to the quoted price of %d.\n",cardPrice, Cards, quotedPrice);
		return -1;
	}
	else if(cardPrice != -1 && (cardNum<0 || cardNum>26)){
		printf("ERROR - The input of %d into the getCost function did not produce te expected result of -1.", cardNum);
		return -1;
	}
	return 0;
}

int main (){
	
	int checkErr = 0;
	
	const char *Cards[27];
	Cards[0] = "curse";
	Cards[1] = "estate";
	Cards[2] = "duchy";
	Cards[3] = "province";
    Cards[4] = "copper";
    Cards[5] =  "silver";
    Cards[6] =  "gold";
    Cards[7] =  "adventurer";
    Cards[8] =  "council_room";
    Cards[9] =  "feast";
    Cards[10] =  "gardens";
    Cards[11] =  "mine";
    Cards[12] =  "remodel";
    Cards[13] =  "smithy";
    Cards[14] =  "village";
    Cards[15] =  "baron";
    Cards[16] =  "great_hall";
    Cards[17] =  "minion";
    Cards[18] =  "steward";
    Cards[19] =  "tribute";
    Cards[20] =  "ambassador";
    Cards[21] =  "cutpurse";
    Cards[22] =  "embargo";
    Cards[23] =  "outpost";
    Cards[24] =  "salvager";
    Cards[25] =  "sea_hag";
    Cards[26] =  "treasure_map";
    
	//Check cost of cards 1 through 27 that are listed in the game.
	checkErr += checkCost(0,0,Cards[0]);
	checkErr += checkCost(1,2,Cards[1]);
	checkErr += checkCost(2,5,Cards[2]);
	checkErr += checkCost(3,8,Cards[3]);
	checkErr += checkCost(4,0,Cards[4]);
	checkErr += checkCost(5,3,Cards[5]);
	checkErr += checkCost(6,6,Cards[6]);
	checkErr += checkCost(7,6,Cards[7]);
	checkErr += checkCost(8,5,Cards[8]);
	checkErr += checkCost(9,4,Cards[9]);
	checkErr += checkCost(10,4,Cards[10]);
	checkErr += checkCost(11,5,Cards[11]);
	checkErr += checkCost(12,4,Cards[12]);
	checkErr += checkCost(13,4,Cards[13]);
	checkErr += checkCost(14,3,Cards[14]);
	checkErr += checkCost(15,4,Cards[15]);
	checkErr += checkCost(16,3,Cards[16]);
	checkErr += checkCost(17,5,Cards[17]);
	checkErr += checkCost(18,3,Cards[18]);
	checkErr += checkCost(19,5,Cards[19]);
	checkErr += checkCost(20,3,Cards[20]);
	checkErr += checkCost(21,4,Cards[21]);
	checkErr += checkCost(22,2,Cards[22]);
	checkErr += checkCost(23,5,Cards[23]);
	checkErr += checkCost(24,4,Cards[24]);
	checkErr += checkCost(25,4,Cards[25]);
	checkErr += checkCost(26,4,Cards[26]);
	
	//Check that return value of -1 is returned for input outside the 1 to 27 range.
	checkErr += checkCost(27,5,Cards[27]);
	checkErr += checkCost(-1,5,Cards[-1]);
	checkErr += checkCost(500,10,Cards[500]);
	
	if(checkErr == 0){
		printf("All Tests Passed");
	}
	else{
		printf("One or more teses Failed");
	}
	
	return 0;	
}

