// Keenan Bishop
// unittest4.c
// getCost()
// from template

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>



void test_getCost(){
	//get cost is just a switch lookup, so we need to test all cases
	printf ("TESTING getCost():\n");
	//variable for confirming all passed
	int all_pass = 1;

	//if block!
	if (getCost(curse) != 0){printf("FAIL: getCost(curse) != 0\n"); all_pass = 0;}
	if (getCost(estate) != 2){printf("FAIL: getCost(estate) != 2\n"); all_pass = 0;}
	if (getCost(duchy) != 5){printf("FAIL: getCost(duchy) != 5\n"); all_pass = 0;}
	if (getCost(province) != 8){printf("FAIL: getCost(province) != 8\n"); all_pass = 0;}
	if (getCost(copper) != 0){printf("FAIL: getCost(copper) != 0\n"); all_pass = 0;}
	if (getCost(silver) != 3){printf("FAIL: getCost(silver) != 3\n"); all_pass = 0;}
	if (getCost(gold) != 6){printf("FAIL: getCost(curse) != 6\n"); all_pass = 0;}
	if (getCost(adventurer) != 6){printf("FAIL: getCost(adventurer) != 6\n"); all_pass = 0;}
	if (getCost(council_room) != 5){printf("FAIL: getCost(council_room) != 5\n"); all_pass = 0;}
	if (getCost(feast) != 4){printf("FAIL: getCost(feast) != 4\n"); all_pass = 0;}
	if (getCost(gardens) != 4){printf("FAIL: getCost(gardens) != 5\n"); all_pass = 0;}
	if (getCost(mine) != 5){printf("FAIL: getCost(mine) != 5\n"); all_pass = 0;}
	if (getCost(remodel) != 4){printf("FAIL: getCost(remodel) != 4\n"); all_pass = 0;}
	if (getCost(smithy) != 4){printf("FAIL: getCost(smithy) != 4\n"); all_pass = 0;}
	if (getCost(village) != 3){printf("FAIL: getCost(village) != 3\n"); all_pass = 0;}
	if (getCost(baron) != 4){printf("FAIL: getCost(baron) != 4\n"); all_pass = 0;}
	if (getCost(great_hall) != 3){printf("FAIL: getCostgreat_hall) != 3\n"); all_pass = 0;}
	if (getCost(minion) != 5){printf("FAIL: getCost(minion) != 5\n"); all_pass = 0;}
	if (getCost(steward) != 3){printf("FAIL: getCost(steward) != 3\n"); all_pass = 0;}
	if (getCost(tribute) != 5){printf("FAIL: getCost(tribute) != 5\n"); all_pass = 0;}
	if (getCost(ambassador) != 3){printf("FAIL: getCost(ambassador) != 3\n"); all_pass = 0;}
	if (getCost(cutpurse) != 4){printf("FAIL: getCost(cutpurse) != 4\n"); all_pass = 0;}
	if (getCost(embargo) != 2){printf("FAIL: getCost(embargo) != 2\n"); all_pass = 0;}
	if (getCost(outpost) != 5){printf("FAIL: getCost(outpost) != 5\n"); all_pass = 0;}
	if (getCost(salvager) != 4){printf("FAIL: getCost(salvager) != 4\n"); all_pass = 0;}
	if (getCost(sea_hag) != 4){printf("FAIL: getCost(sea_hag) != 4\n"); all_pass = 0;}
	if (getCost(treasure_map) != 4){printf("FAIL: getCost(treasure_map) != 4\n"); all_pass = 0;}
	//value not included test!
	if (getCost(-1) != -1){printf("FAIL: getCost(not_a_card) != -1\n"); all_pass = 0;}

	//final test statement
	if(all_pass){
		printf("PASS: getCost: passed all tests!\n");
	}
	else{
		printf("FAIL: getCost: one or more tests failed!\n");
	}	





}

int main(){
	test_getCost();
	return 0;
}
