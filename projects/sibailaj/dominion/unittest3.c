#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"

void testGetCost();

int main(int argc, char *argv[])
{
	testGetCost();
    return 0;
}

void testGetCost() {
    int i;
    int seed = 1000;
    int numPlayer = 2;
    int bonus;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
           sea_hag, tribute, smithy};
    struct gameState G;
		
	initializeGame(numPlayer, k, seed, &G);
	
	//curse:
	assert(getCost(curse) == 0);

    //estate:
	assert(getCost(estate) == 2);
    
    //duchy:
	assert(getCost(duchy) == 5);

    //province:
	assert(getCost(province) == 8);

    //copper:
	assert(getCost(copper) == 0);

    //silver:
	assert(getCost(silver) == 3);

    //gold:
	assert(getCost(gold) == 6);

    //adventurer:
	assert(getCost(adventurer) == 6);
    
    //council_room:
	assert(getCost(council_room) == 5);
      
    //feast:
	assert(getCost(feast) == 4);

    //gardens:
	assert(getCost(gardens) == 4);
      
    //mine:
	assert(getCost(mine) == 5);
      
    //remodel:
	assert(getCost(remodel) == 4);
      
    //smithy:
	assert(getCost(smithy) == 4);
      
    //village:
	assert(getCost(village) == 3);

    //baron:
	assert(getCost(baron) == 4);
      
    //great_hall:
	assert(getCost(great_hall) == 3);
      
    //minion:
	assert(getCost(minion) == 5);
      
    //steward:
	assert(getCost(steward) == 3);
      
    //tribute:
	assert(getCost(tribute) == 5);

    //ambassador:
	assert(getCost(ambassador) == 3);
      
    //cutpurse:
	assert(getCost(cutpurse) == 4);
      
    //embargo: 
	assert(getCost(embargo) == 2);
      
    //outpost:
	assert(getCost(outpost) == 5);
    
    //salvager:
	assert(getCost(salvager) == 4);
      
    //sea_hag:
	assert(getCost(sea_hag) == 4);
    
    //treasure_map:
	assert(getCost(treasure_map) == 4);

    printf("All tests passed!\n");
}