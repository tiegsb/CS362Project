/**********************************************************
 * Dalena Pham
 * CS 362 - Assignment 3
 * unittest1.c
 * Unit test for function getCost()
 * *******************************************************/

#include "assert.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <stdlib.h>

// Helper function to test getCost()
void helper(char* card, int card_num, int expected_cost) {
	int r = getCost(card_num); 
	printf("%s: %d ",card, expected_cost);
	if(r != expected_cost)
		printf("FAILURE\n"); 
	else 
		printf("PASS\n");  
}

int main() {

	printf("TESTING getCost(): \n"); 

	helper("curse", 0, 0); 
	helper("estate", 1, 2); 
	helper("duchy", 2, 5); 
	helper("province", 3, 8); 

	helper("copper", 4, 0); 
	helper("silver", 5, 3); 
	helper("gold", 6, 6); 

	helper("adventurer", 7, 6); 
	helper("council room", 8, 5); 
	helper("feast", 9, 4); 
	helper("gardens", 10, 4); 
	helper("mine", 11, 5); 
	helper("remodel", 12, 4); 
	helper("smithy", 13, 4); 
	helper("village", 14, 3); 
	helper("baron", 15, 4); 
	helper("great hall", 16, 3); 
	helper("minion", 17, 5); 
	helper("steward", 18, 3); 
	helper("tribute", 19, 5); 
	helper("ambassador", 20, 3); 
	helper("cutpurse", 21, 4); 
	helper("embargo", 22, 2); 
	helper("outpost", 23, 5); 
	helper("salvager", 24, 4); 
	helper("sea hag", 25, 4); 
	helper("treasure map", 26, 4); 

	
	helper("TESTING ENUM 27 (OUT OF BOUNDS)", 27, -1); 
	helper("NEGATIVE NUMBER TEST", -300, -1); 
	helper("LARGE NUMBER", 1000000, -1); 
	
	printf("\n"); 

	return 0; 
}
