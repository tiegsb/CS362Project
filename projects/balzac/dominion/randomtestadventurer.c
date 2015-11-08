/* Random tester for the Adventurer card*/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <math.h>
#include <stdlib.h>

int checkAdventurerCard(int p, int cardDrawn, int drawnTreasure, int index, int temphand[],
						struct gameState *post, int failed)
{
	int incoming_failed = failed;
	int test1 = 0;
	int test2 = 0;
	int test3 = 0;
	struct gameState pre; /*start a new game*/
	memcpy (&pre, post, sizeof(struct gameState)); /*Make a copy of game state*/
	
	//printf ("adventurer_card() PRE: p %d HC %d DeC %d DiC %d\n",
	//p, pre.handCount[p], pre.deckCount[p], pre.discardCount[p]);
	
	adventurer_card(p, cardDrawn, drawnTreasure, index, temphand, post);
	
	//printf ("adventurer_card() POST: p %d HC %d DeC %d DiC %d\n",
	//p, post->handCount[p], post->deckCount[p], post->discardCount[p]);
	
	/*Check if deck was shuffled when == to 0 */
	if (post->deckCount[p] > pre.deckCount[p] && pre.deckCount[p] <= 0 )
	{
		//printf ("PASS - deckCount now %d, was %d, deck was shuffled\n", post->deckCount[p], pre.deckCount[p]);
	}
	else if (pre.deckCount[p] > 0)
	{
		//printf ("PASS - Deck did not need to shuffled\n");
	}
	else
	{
		//printf ("FAIL - deckCount still %d, did not shuffle\n", post->deckCount[p]);
		failed++;
		test1 = 1;
	}

	
	cardDrawn = post->hand[p][post->handCount[p] -2];
	if(cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
	{
		drawnTreasure++;
	}
	
	cardDrawn = post->hand[p][post->handCount[p] -1];
	if(cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
	{
		drawnTreasure++;
	}

	
	if (drawnTreasure == 2)
	{
		//printf ("PASS - Only two treasure cards were added to hand.\n");
	}
	else
	{
		//printf ("FAIL - Two treasure cards were NOT added to hand.\n");
		failed++;
		test2 = 1;
	}
	
	/*checks if 2 treasure cards added account if adventurer card is discarded*/
	if(post->handCount[p] == pre.handCount[p] + 1 || post->handCount[p] == pre.handCount[p] + 2)
	{
		//printf ("PASS - Player %d has received 2 cards.\n", p);
	}
	else
	{
		//printf ("FAIL - Player %d has not received the proper amount of cards.\n", p);
		failed++;
		test3 = 1;
	}

	if (incoming_failed < failed)
	{
		printf ("adventurer_card() PRE: p %d HC %d DeC %d DiC %d\n",
		p, pre.handCount[p], pre.deckCount[p], pre.discardCount[p]);
	
		printf ("adventurer_card() POST: p %d HC %d DeC %d DiC %d\n",
		p, post->handCount[p], post->deckCount[p], post->discardCount[p]);
		
		if (test1 == 1)
		{
			printf ("FAIL - deckCount still %d, did not shuffle\n", post->deckCount[p]);
		}
		
		if (test2 == 1)
		{
			printf ("FAIL - Two treasure cards were NOT added to hand.\n");
		}
		
		if (test3 == 1)
		{
			printf ("FAIL - Player %d has not received the proper amount of cards.\n", p);
		}
	}
	
	return failed;
}

int main () {
 
	int failed = 0;
	//int deckCount = 0;
	int number_of_tests = 100000;

	printf ("Testing adventurer_card().\n");

	printf ("RANDOM TESTS.\n");

	int n;
	for (n = 0; n < number_of_tests; n++)
	{
		int seed;
		int index = 0;
		int cardDrawn = 0;
		int drawnTreasure = 0;
		int handCount = 4;
		int temphand[MAX_HAND];
		int p;

		int k[10] = {adventurer, council_room, feast, gardens, mine,
			   remodel, smithy, village, baron, great_hall};

		struct gameState G;

		seed = rand();
		p = floor(Random() * 2);
		initializeGame(2, k, seed, &G);
		G.deckCount[p] = floor(Random() * MAX_DECK) -1;/*get some negative values*/
		G.discardCount[p] = 5;/*Increases coverage if discard is 1 or greater*/
		G.handCount[p] = handCount; /*Increases coverage if hand is 4*/
		failed = checkAdventurerCard(p, cardDrawn, drawnTreasure, index, temphand, &G, failed);
		memset(&G, 23, sizeof(struct gameState)); 
	}

	printf ("%d out of %d Tests failed\n",failed , number_of_tests * 3);

	exit(0);

	/*printf ("SIMPLE FIXED TESTS.\n");
	
	for (p = 0; p < 2; p++) {
		for (deckCount = -1; deckCount < 5; deckCount++) {
		  memset(&G, 23, sizeof(struct gameState)); 
		  initializeGame(2, k, 1, &G);
		  G.deckCount[p] = deckCount;
		  G.discardCount[p] = 5 - deckCount;
		  memset(G.deck[p], 0, sizeof(int) * deckCount);
		  G.handCount[p] = handCount;
		  checkAdventurerCard(p, cardDrawn, drawnTreasure, index, temphand, &G, failed);		
		}
	}
	*/
	return 0;
}





  