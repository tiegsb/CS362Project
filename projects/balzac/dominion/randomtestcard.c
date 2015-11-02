/* Random tester for the Steward card*/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <math.h>
#include <stdlib.h>

int checkStewardCard(int p, int handPos, int ch1, int ch2, int ch3,
						struct gameState *post, int failed)
{
	int incoming_failed = failed;
	int test1 = 0;
	int test2 = 0;
	int test3 = 0;
	
	struct gameState pre; /*start a new game*/
	memcpy (&pre, post, sizeof(struct gameState)); /*Make a copy of game state*/
	
	//printf ("steward_card() PRE: p %d HC %d DeC %d DiC %d\n",
	//p, pre.handCount[p], pre.deckCount[p], pre.discardCount[p]);
	
	steward_card(p, handPos, ch1, ch2, ch3, post);
	
	//printf ("steward_card() POST: p %d HC %d DeC %d DiC %d\n",
	//p, post->handCount[p], post->deckCount[p], post->discardCount[p]);
	
	if(ch1 == 1)
	{
		/*checks if 2 cards added, accounts for when steward card is discarded*/
		if(post->handCount[p] == pre.handCount[p] + 1 || post->handCount[p] == pre.handCount[p] + 2)
		{
			//printf ("PASS - Player %d has received 2 cards.\n", p);
		}
		else
		{
			//printf ("FAIL - Player %d has not received 2 cards.\n", p);
			failed++;
			test1 = 1;
		}
	}
	else if(ch1 == 2)
	{
		if(post->coins == pre.coins + 2)
		{
			//printf ("PASS - Player %d has received 2 coins.\n", p);
		}
		else
		{
			//printf ("FAIL - Player %d has not received 2 coins.\n", p);
			failed++;
			test2 = 1;
		}
	}
	else
	{
		/*checks if 2 cards discarded, 2 if steward card was discard and 3 if steward card was 
		not discarded*/
		if (post->handCount[p] == pre.handCount[p] - 2 || post->handCount[p] == pre.handCount[p] - 3)
		{
			//printf ("PASS - 2 cards discarded.\n");
		}
		else
		{
			//printf ("FAIL - 2 cards NOT discarded.\n");
			failed++;
			test3 = 1;
		}
	}
		
	if (incoming_failed < failed)
	{
		printf ("adventurer_card() PRE: p %d HC %d DeC %d DiC %d\n",
		p, pre.handCount[p], pre.deckCount[p], pre.discardCount[p]);
	
		printf ("adventurer_card() POST: p %d HC %d DeC %d DiC %d\n",
		p, post->handCount[p], post->deckCount[p], post->discardCount[p]);
		
		if (test1 == 1)
		{
			printf ("FAIL - Player %d has not received 2 cards.\n\n", p);
		}
		
		if (test2 == 1)
		{
			printf ("FAIL - Player %d has not received 2 coins.\n\n", p);
		}
		
		if (test3 == 1)
		{
			printf ("FAIL - 2 cards NOT discarded.\n\n");
		}
	}
	
	return failed;
}

int main () {
 
	int failed = 0;
	//int deckCount = 0;
	int number_of_tests = 5000;

	printf ("Testing steward_card().\n");

	printf ("RANDOM TESTS.\n");

	int n;
	for (n = 0; n < number_of_tests; n++)
	{
		int choice1 = 0;
		for(choice1 = 0; choice1 <= 2; choice1++) {
			int seed;
			//int handCount = 4;
			int p;
			//int choice1 = 0;
			int choice2 = 0;
			int choice3 = 0;
			int handPos = 1; /*Assume steward card is in hand position 1*/
			
			int k[10] = {adventurer, council_room, feast, gardens, mine,
				   remodel, smithy, village, baron, great_hall};

			struct gameState G;

			seed = rand();
			p = floor(Random() * 2);
			initializeGame(2, k, seed, &G);
			G.deckCount[p] = floor(Random() * MAX_DECK);
			G.discardCount[p] = floor(Random() * MAX_DECK);
			G.handCount[p] = floor(Random() * MAX_HAND); 
			failed = checkStewardCard(p, handPos, choice1, choice2, choice3, &G, failed);	
			memset(&G, 23, sizeof(struct gameState)); 
		}
	}

	printf ("%d out of %d Tests failed\n",failed , number_of_tests * 3);

	exit(0);

	/*printf ("SIMPLE FIXED TESTS.\n");
	
	for (p = 0; p < 2; p++) {
		for (deckCount = 0; deckCount < 5; deckCount++) {
			for(choice1 = 0; choice1 <= 2; choice1++) {
				memset(&G, 23, sizeof(struct gameState)); 
				initializeGame(2, k, 1, &G);
				G.deckCount[p] = deckCount;
				G.discardCount[p] = 5 - deckCount;
				memset(G.deck[p], 0, sizeof(int) * deckCount);
				G.handCount[p] = handCount;
				checkStewardCard(p, handPos, choice1, choice2, choice3, &G, failed);	
			}	
		}
	}
	*/
	return 0;
}




