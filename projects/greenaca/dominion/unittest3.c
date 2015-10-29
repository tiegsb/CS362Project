/* -----------------------------------------------------------------------
 * Unit test for getCost()
 *
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main() {
    int i;
    int seed = 1000;
    int numPlayer = 2;
    int maxBonus = 10;
    int p, r, handCount;
    int bonus;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int maxHandCount = 5;
    // arrays of all coppers, silvers, and golds
    int coppers[MAX_HAND];
    int silvers[MAX_HAND];
    int golds[MAX_HAND];
    for (i = 0; i < MAX_HAND; i++)
    {
        coppers[i] = copper;
        silvers[i] = silver;
        golds[i] = gold;
    }

    printf ("TESTING getCost():\n");

    char *names[] = {"curse",
"estate",
"duchy",
"province",
"copper",
"silver",
"gold",
"adventurer",
"council_room",
"feast",
"gardens",
"mine", 
"remodel", 
"smithy",
"village",
"baron", 
"great_hall",
"minion", 
"steward", 
"tribute",
"ambassador", 
"cutpurse",
"embargo", 
"outpost",
"salvager", 
"sea_hag",
"treasure_map"
};


    int expected_cost[treasure_map + 1] = {0,2,5,8,0,3,6,6,5,4,4,5,4,4,3,4,3,5,3,5,3,4,2,5,4,4,4};

    int actual_cost[treasure_map + 1];

    for(i = 0; i < treasure_map + 1; i++) {
    	actual_cost[i] = getCost(i);
    }
    
    int j;
    for(j = 0; j < treasure_map + 1; j++) {
    	printf("%s: Expected cost = %d, Actual cost = %d\n", names[j], expected_cost[j], actual_cost[j]);

    	if (expected_cost[j] == actual_cost[j]) {
    		printf("%s card cost TEST PASSED\n\n", names[j]);
    	} else {
            printf("%s card cost TEST FAILED\n\n", names[j]);
        }

    }

    return 0;
}