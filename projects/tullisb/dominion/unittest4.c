/* -----------------------------------------------------------------------
* Ben Tullis
* CS362
* Testing getCost()
* -----------------------------------------------------------------------
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

#define assert_msg(x) for ( ; !(x) ; assert(x) )
// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 0

int main() {
	srand(time(NULL));
	int cards[] = { curse, estate, duchy, province, copper, silver,
		gold, adventurer, council_room, feast, gardens, mine, remodel,
		smithy, village, baron, great_hall, minion, steward, tribute,
		ambassador, cutpurse, embargo, outpost, salvager, sea_hag,treasure_map };
	int costs[] = { 0, 2, 5, 8, 0, 3, 6, 6, 5, 4, 4, 
		5, 4, 4, 3, 4, 3, 5, 3, 5, 3, 4, 2, 5, 4, 4, 4 };
	int rCard;
	int cost;
	int iterations = 10000;

	printf("\nTESTING getCost():\n");
	for (int i = 0; i < iterations; i++)
	{
		rCard = rand() % 27;
		cost = getCost(rCard);
#if (NOISY_TEST == 1)
		printf("rCard: %d; cost %d; costs[rCard] %d\n", rCard, cost, costs[rCard]);
#endif

		assert_msg(costs[rCard] == cost)	// check if vlaue of costs at index rCard == returned valued of cost
		{
			printf("ASSERTION 'costs[rCard] == cost' FAILED: File: %s, Line: %d, rCard: %d; cost %d; costs[rCard] %d",
				__FILE__, __LINE__ - 2, rCard, cost, costs[rCard]); //Failure Message
		}
	}

	printf("All tests passed!\n");

	return 0;
}