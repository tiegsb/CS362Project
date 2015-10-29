#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "dominion.h"
#include "dominion_helpers.h"

void testShuffle();

int main(int argc, char *argv[])
{
	testShuffle();
    return 0;
}

void testShuffle() {
    int i;
    int seed = 1000;
    int numPlayer = 2;
    int bonus;
	int shuffleResult;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
           sea_hag, tribute, smithy};
    struct gameState G;
	struct gameState G2;
		
	initializeGame(numPlayer, k, seed, &G);
	
	//Make a duplicate of initialized game
	memcpy(&G2, &G, sizeof(G));

	//Shuffle the copied game
	shuffleResult = shuffle(0, &G2);

	//Compare card positions with previous card position
	for (i = 0; i < MAX_DECK; i++) {
		if(G.deck[0][i] == G2.deck[0][i]) {
			printf("Card position same!\n");
		} else {
			printf("Card position shuffled!\n");
		}
  }
}