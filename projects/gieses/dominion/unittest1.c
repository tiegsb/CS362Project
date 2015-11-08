#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define NOISY_TEST 0

//test getCost function
int main(){
	int i, card;
	printf("Testing getCost() function:\n");
	
	//check ranges to include numbers outside of our range, and our range
	for (i = -1; i < 30; i++){
		card = getCost(i);
		if (i == -1){ //under range
			assert(card == -1);
			#if (NOISY_TEST == 1)
			printf("Passed!\n");
			#endif
		}
		if (i == 0){ //curse
			assert(card == 0);
			#if (NOISY_TEST == 1)
			printf("Passed!\n");
			#endif
		}
		if (i == 1){ //estate
			assert(card == 2);
			#if (NOISY_TEST == 1)
			printf("Passed!\n");
			#endif
		}
		if (i == 2){ //duchy
			assert(card == 5);
			#if (NOISY_TEST == 1)
			printf("Passed!\n");
			#endif
		}
		if (i == 3){ //province
			assert(card == 8);
			#if (NOISY_TEST == 1)
			printf("Passed!\n");
			#endif
		}
		if (i == 4){ //copper
			assert(card == 0);
			#if (NOISY_TEST == 1)
			printf("Passed!\n");
			#endif
		}
		if (i == 5){ //silver
			assert(card == 3);
			#if (NOISY_TEST == 1)
			printf("Passed!\n");
			#endif
		}
		if (i == 6){ //gold
			assert(card == 6);
			#if (NOISY_TEST == 1)
			printf("Passed!\n");
			#endif
		}
		if (i == 7){ //adventurer
			assert(card == 6);
			#if (NOISY_TEST == 1)
			printf("Passed!\n");
			#endif
		}
		if (i == 8){ //council_room
			assert(card == 5);
			#if (NOISY_TEST == 1)
			printf("Passed!\n");
			#endif
		}
		if (i == 9){ //feast
			assert(card == 4);
			#if (NOISY_TEST == 1)
			printf("Passed!\n");
			#endif
		}
		if (i == 10){ //gardens
			assert(card == 4);
			#if (NOISY_TEST == 1)
			printf("Passed!\n");
			#endif
		}
		if (i == 11){ //mine
			assert(card == 5);
			#if (NOISY_TEST == 1)
			printf("Passed!\n");
			#endif
		}
		if (i == 12){ //remodel
			assert(card == 4);
			#if (NOISY_TEST == 1)
			printf("Passed!\n");
			#endif
		}
		if (i == 13){ //smithy
			assert(card == 4);
			#if (NOISY_TEST == 1)
			printf("Passed!\n");
			#endif
		}
		if (i == 14){ //village
			assert(card == 3);
			#if (NOISY_TEST == 1)
			printf("Passed!\n");
			#endif
		}
		if (i == 15){ //baron
			assert(card == 4);
			#if (NOISY_TEST == 1)
			printf("Passed!\n");
			#endif
		}
		if (i == 16){ //great_hall
			assert(card == 3);
			#if (NOISY_TEST == 1)
			printf("Passed!\n");
			#endif
		}
		if (i == 17){ //minion
			assert(card == 5);
			#if (NOISY_TEST == 1)
			printf("Passed!\n");
			#endif
		}
		if (i == 18){ //steward
			assert(card == 3);
			#if (NOISY_TEST == 1)
			printf("Passed!\n");
			#endif
		}
		if (i == 19){ //tribute
			assert(card == 5);
			#if (NOISY_TEST == 1)
			printf("Passed!\n");
			#endif
		}
		if (i == 20){ //ambassador
			assert(card == 3);
			#if (NOISY_TEST == 1)
			printf("Passed!\n");
			#endif
		}
		if (i == 21){ //cutpurse
			assert(card == 4);
			#if (NOISY_TEST == 1)
			printf("Passed!\n");
			#endif
		}
		if (i == 22){ //embargo
			assert(card == 2);
			#if (NOISY_TEST == 1)
			printf("Passed!\n");
			#endif
		}
		if (i == 23){ //outpost
			assert(card == 5);
			#if (NOISY_TEST == 1)
			printf("Passed!\n");
			#endif
		}
		if (i == 24){ //salvager
			assert(card == 4);
			#if (NOISY_TEST == 1)
			printf("Passed!\n");
			#endif
		}
		if (i == 25){ //sea_hag
			assert(card == 4);
			#if (NOISY_TEST == 1)
			printf("Passed!\n");
			#endif
		}
		if (i == 26){ //treasure_map
			assert(card == 4);
			#if (NOISY_TEST == 1)
			printf("Passed!\n");
			#endif
		}
		if (i == 27){ //over range
			assert(card == -1);
			#if (NOISY_TEST == 1)
			printf("Passed!\n");
			#endif
		}
	}
	//check outliers
	card = getCost(-1000);
	assert(card == -1);
	#if (NOISY_TEST == 1)
	printf("Passed!\n");
	#endif
	card = getCost(1000);
	assert(card == -1);
	#if (NOISY_TEST == 1)
	printf("Passed!\n");
	#endif
	card = getCost(-10000);
	assert(card == -1);
	#if (NOISY_TEST == 1)
	printf("Passed!\n");
	#endif
	card = getCost(10000);
	assert(card == -1);
	#if (NOISY_TEST == 1)
	printf("Passed!\n");
	#endif
	
	printf("All tests passed!\n");
	
	return 0;
}