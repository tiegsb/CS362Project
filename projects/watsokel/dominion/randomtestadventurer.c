/* -----------------------------------------------------------------------
* Programmed by: Kelvin Watson
* Filename: randomtestadventurer.c
* Created: 27 Oct 2015
* Last modified: 27 Oct 2015
* Description: Random tests for adventurerEffect2() method
* -----------------------------------------------------------------------
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#define DEBUG 0
#define NOISY_TEST 1

int checkAdventurerEffect(struct gameState *post, int player) {
	struct gameState oracle;
	memcpy (&oracle, post, sizeof(struct gameState));
	int errCount=0;
	int actualPostTreasureCount;
	int oraclePreTreasureCount, oraclePostTreasureCount;
	int actualHandCount, oracleHandCount;
	//int actualDeckCount, oracleDeckCount;
	int h;
	
	//int actualHandBeforeCall[] = post->hand[player];
	
	oraclePreTreasureCount=0;
	
	//count treasure cards in hand prior to call
	for(h=0; h<oracle.handCount[player]; h++){
		if(	oracle.hand[player][h] == copper ||
			oracle.hand[player][h] == silver ||
			oracle.hand[player][h] == gold){
				++oraclePreTreasureCount;
			}
	}
	
	
	int r = adventurerEffect2(post,player);
		
	if(r != 0){
		printf("  FAIL, return value=%d, expected=%d\n", r, 0);
		errCount++;
	}else{
		printf("  PASS, return value=%d, expected=%d\n", r, 0);
	}
	
	oraclePostTreasureCount = oraclePreTreasureCount+2;

	actualPostTreasureCount=0;
	for(h=0; h<post->handCount[player]; h++){
		if(	post->hand[player][h] == copper ||
			post->hand[player][h] == silver ||
			post->hand[player][h] == gold){
				++actualPostTreasureCount;
			}
	}

	if(actualPostTreasureCount != oraclePostTreasureCount){
		printf("  FAIL, treasure count=%d, expected=%d\n", actualPostTreasureCount, oraclePostTreasureCount);
		errCount++;
	}else{
		printf("  PASS, treasure count=%d, expected=%d\n", actualPostTreasureCount, oraclePostTreasureCount);
	}


	actualHandCount = post->handCount[player];
	oracleHandCount = oracle.handCount[player]+2;

	if(actualHandCount != oracleHandCount){
		printf("  FAIL, hand count=%d, expected=%d\n", actualHandCount, oracleHandCount);
		errCount++;
	}else{
		printf("  PASS, hand count=%d, expected=%d\n", actualHandCount, oracleHandCount);
	}
	
	
	/*actualDeckCount = post->deckCount[player];
	oracleDeckCount=oracle.deckCount[player];
	
	if(actualDeckCount != oracleDeckCount){
		printf("  FAIL, deck count=%d, expected=%d\n", actualDeckCount, oracleDeckCount);
		errCount++;
	}else{
		printf("  PASS, deck count=%d, expected=%d\n", actualDeckCount, oracleDeckCount);
	}*/
	return errCount;
}

int main () {

	int i, n, p, j;	
	int randDeckCount, randDiscardCount, randHandCount;
	int errFlag=0;
	//int k[10] = {adventurer, council_room, feast, gardens, mine,
	//	remodel, smithy, village, baron, great_hall};

	int adventurers[MAX_HAND];
	int estates[MAX_HAND];
	int silvers[MAX_HAND];
	int golds[MAX_HAND];
	for (i = 0; i < MAX_HAND; i++){
		adventurers[i] = adventurer;
		estates[i] = estate;
		silvers[i] = silver;
		golds[i] = gold;
	}
	
	
	struct gameState G;

	printf ("Testing drawCard.\n");

	printf ("RANDOM TESTS.\n");

	SelectStream(2);
	PutSeed(3);

	for (n = 0; n < 2000; n++) {
		for (i = 0; i < sizeof(struct gameState); i++) {
			((char*)&G)[i] = (int)(Random() * 256);
		}
		p = (int)(Random() * 2);
		randDeckCount = G.deckCount[p] = (int)(Random() * MAX_DECK);
		randDiscardCount = G.discardCount[p] = (int)(Random() * MAX_DECK);
		randHandCount = G.handCount[p] = (int)(Random() * MAX_HAND);
		
		//Instead of setting all cards to silver, randomly generate an assortment of all cards
		for(j=0;j<randHandCount;j++){
			G.hand[p][j]=(int)(Random()*26);
		}
		for(j=0;j<randDiscardCount;j++){
			G.discard[p][j]=(int)(Random()*26);
		}
		for(j=0;j<randDeckCount;j++){
			G.deck[p][j]=(int)(Random()*26);
		}

		//printf("p=%d,G.deckCount[p]=%d,G.discardCount[p]=%d,G.handCount[p]=%d\n",p,G.deckCount[p],G.discardCount[p],G.handCount[p]);
		errFlag = checkAdventurerEffect(&G,p);
	}

	if(errFlag != 0){
		printf("Some tests failed.\n");
	} else {
		printf("ALL TESTS PASSED!\n");
	}
	return 0;
}