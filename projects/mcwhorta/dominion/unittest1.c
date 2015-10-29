#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define DEBUG 0
#define NOISY_TEST 1

int checkGetCost(int cardNumber) {
	int r;
	r = getCost(cardNumber);
	switch (cardNumber) {

	case curse:
		assert(r==0);
		break;
	case estate:
		assert(r==2);
		break;
	case duchy:
		assert(r==5);
		break;
	case province:
		assert(r == 8);
		break;
	case copper:
		assert(r==0);
		break;
	case silver:
		assert(r==3);
		break;
	case gold:
		assert(r==6);
		break;
	case adventurer:
		assert( r==6);
		break;
	case council_room:
		assert(r== 5);
		break;
	case feast:
		assert(r== 4);
		break;
	case gardens:
		assert(r== 4);
		break;
	case mine:
		assert(r== 5);
		break;
	case remodel:
		assert(r== 4);
		break;
	case smithy:
		assert(r== 4);
		break;
	case village:
		assert(r== 3);
		break;
	case baron:
		assert(r== 4);
		break;
	case great_hall:
		assert(r== 3);
		break;
	case minion:
		assert(r== 5);
		break;
	case steward:
		assert(r== 3);
		break;
	case tribute:
		assert(r==5);
		break;
	case ambassador:
		assert(r== 3);
		break;
	case cutpurse:
		assert(r== 4);
		break;
	case embargo:
		assert(r== 2);
		break;
	case outpost:
		assert(r== 5);
		break;
	case salvager:
		assert(r== 4);
		break;
	case sea_hag:
		assert(r== 4);
		break;
	case treasure_map:
		assert(r== 4);
		break;
	case -1:
		assert (r==-1);
		break;
	}
	return 0;
}

int main() {
	int p;
	printf("TESTING getCost().\n");
	int kingCards[] = {curse, estate, duchy, province, copper, silver, gold,
			adventurer, council_room, feast, gardens, mine, remodel, smithy,
			village, baron, great_hall, minion, steward, tribute, ambassador,
			cutpurse, outpost, salvager, sea_hag, treasure_map, embargo, -1 };
	for (p = 0; p < 28; p++) {
		checkGetCost(kingCards[p]);
	}
	printf("ALL TESTS OK\n\n");
	return 0;
}
