#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include "math.h"

int main (int argc, char** argv) {
	struct gameState G;
	struct gameState *q = &G;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy};
	int p = rand();
	int i;
	int r;

	printf ("-------------------------Testing shuffle function:------------------\n");

	initializeGame(2, k, p , q);

	printf ("Before shuffle.\n");
	for (i = 0; i < 10; i++)
	{
		if (q->deck[1][i] == estate)
		{
			printf ("estate\n");
		}
		if (q->deck[1][i] == copper)
		{
			printf ("copper\n");
		}
	}

	r = shuffle(1, q);
	assert (r == 0);
	printf ("After shuffle.\n");

	for (i = 0; i < 10; i++)
	{
		if (q->deck[1][i] == estate)
		{
			printf ("estate\n");
		}
		if (q->deck[1][i] == copper)
		{
			printf ("copper\n");
		}
	}
	return 0;
}
