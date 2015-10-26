/* Unit Test 4 - scoreFor()

*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"

void getCostTest()
{
printf ("Cost of curse is equal to 0 - ");
	if (getCost(0) == 0){
		printf ("PASS\n");
	} else {
		printf ("FAIL\n");
	}
	
printf ("Cost of estate is equal to 2 - ");
	if (getCost(1) == 2){
		printf ("PASS\n");
	} else {
		printf ("FAIL\n");
	}
	
printf ("Cost of duchy is equal to 5 - ");
	if (getCost(2) == 5){
		printf ("PASS\n");
	} else {
		printf ("FAIL\n");
	}
	
printf ("Cost of province is equal to 8 - ");
	if (getCost(3) == 8){
		printf ("PASS\n");
	} else {
		printf ("FAIL\n");
	}
	
printf ("Cost of copper is equal to 0 - ");
	if (getCost(4) == 0){
		printf ("PASS\n");
	} else {
		printf ("FAIL\n");
	}
	
printf ("Cost of silver is equal to 3 - ");
	if (getCost(5) == 3){
		printf ("PASS\n");
	} else {
		printf ("FAIL\n");
	}
	
printf ("Cost of gold is equal to 6 - ");
	if (getCost(6) == 6){
		printf ("PASS\n");
	} else {
		printf ("FAIL\n");
	}
	
printf ("Cost of adventurer is equal to 6 - ");
	if (getCost(7) == 6){
		printf ("PASS\n");
	} else {
		printf ("FAIL\n");
	}
	
printf ("Cost of council_room is equal to 5 - ");
	if (getCost(8) == 5){
		printf ("PASS\n");
	} else {
		printf ("FAIL\n");
	}
	
printf ("Cost of feast is equal to 4 - ");
	if (getCost(9) == 4){
		printf ("PASS\n");
	} else {
		printf ("FAIL\n");
	}
	
printf ("Cost of gardens is equal to 4 - ");
	if (getCost(10) == 4){
		printf ("PASS\n");
	} else {
		printf ("FAIL\n");
	}
	
printf ("Cost of mine is equal to 5 - ");
	if (getCost(11) == 5){
		printf ("PASS\n");
	} else {
		printf ("FAIL\n");
	}
	
printf ("Cost of remodel is equal to 4 - ");
	if (getCost(12) == 4){
		printf ("PASS\n");
	} else {
		printf ("FAIL\n");
	}
	
printf ("Cost of smithy is equal to 4 - ");
	if (getCost(13) == 4){
		printf ("PASS\n");
	} else {
		printf ("FAIL\n");
	}
	
printf ("Cost of village is equal to 3 - ");
	if (getCost(14) == 3){
		printf ("PASS\n");
	} else {
		printf ("FAIL\n");
	}
	
printf ("Cost of baron is equal to 4 - ");
	if (getCost(15) == 4){
		printf ("PASS\n");
	} else {
		printf ("FAIL\n");
	}
	
printf ("Cost of great_hall is equal to 3 - ");
	if (getCost(16) == 3){
		printf ("PASS\n");
	} else {
		printf ("FAIL\n");
	}
	
printf ("Cost of minion is equal to 5 - ");
	if (getCost(17) == 5){
		printf ("PASS\n");
	} else {
		printf ("FAIL\n");
	}
	
printf ("Cost of steward is equal to 3 - ");
	if (getCost(18) == 3){
		printf ("PASS\n");
	} else {
		printf ("FAIL\n");
	}
	
printf ("Cost of tribute is equal to 5 - ");
	if (getCost(19) == 5){
		printf ("PASS\n");
	} else {
		printf ("FAIL\n");
	}
	
printf ("Cost of ambassador is equal to 3 - ");
	if (getCost(20) == 3){
		printf ("PASS\n");
	} else {
		printf ("FAIL\n");
	}
	
printf ("Cost of cutpurse is equal to 4 - ");
	if (getCost(21) == 4){
		printf ("PASS\n");
	} else {
		printf ("FAIL\n");
	}
	
printf ("Cost of embargo  is equal to 2 - ");
	if (getCost(22) == 2){
		printf ("PASS\n");
	} else {
		printf ("FAIL\n");
	}
	
printf ("Cost of outpost is equal to 5 - ");
	if (getCost(23) == 5){
		printf ("PASS\n");
	} else {
		printf ("FAIL\n");
	}
	
printf ("Cost of salvager is equal to 4 - ");
	if (getCost(24) == 4){
		printf ("PASS\n");
	} else {
		printf ("FAIL\n");
	}
	
printf ("Cost of sea_hag is equal to 4 - ");
	if (getCost(25) == 4){
		printf ("PASS\n");
	} else {
		printf ("FAIL\n");
	}
	
printf ("Cost of treasure_map is equal to 4 - ");
	if (getCost(26) == 4){
		printf ("PASS\n");
	} else {
		printf ("FAIL\n");
	}

printf ("If Card does not exist return -1 - ");
	if (getCost(27) == -1){
		printf ("PASS\n");
	} else {
		printf ("FAIL\n");
	}
}

int main(){
	getCostTest();
	return 0;
}