/* -----------------------------------------------------------------------
* Programmed by: Kelvin Watson
* Filename: cardtest2.c
* Created: 15 Oct 2015
* Last modified: 15 Oct 2015
* Description: Unit tests for dominion.c 's adventurerEffect() function
* NOTE: Due to a bug introduced in assignment 1, the unit test will fail
* when coppers are drawn in adventurerEffect()
* -----------------------------------------------------------------------
*/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int supplyCheck(struct gameState *S, int cardType, const char* cardName, int expectedCount){
	int err=0;
	if(S->supplyCount[cardType] != expectedCount){
		#if (NOISY_TEST==1)
		printf("      FAIL: number of %s cards=%d, expected=%d\n",cardName,S->supplyCount[cardType],expectedCount);
		#endif 
		err++;
	} else{
		#if (NOISY_TEST==1)
		printf("      PASS: number of %s=%d, expected=%d\n",cardName,S->supplyCount[cardType],expectedCount);
		#endif 
	}
	return err;
}

int checkAdventurerEffect(struct gameState *state, int player, int treasureCard){
	int err=0; //used in place of assertion failure: test passed=0; assertion failure=1
	//if treasureCard is a copper, an infinite loop will happen
	//this block causes an infinite loop since coppers do not count in the buggy adventurerEffect function
	int r = adventurerEffect(state, player);
	if(r != 0){
		#if (NOISY_TEST==1)
		printf("  FAIL, return value=%d, expected=%d\n", r, 0);
		#endif 
		err++;
	} else{
		#if (NOISY_TEST==1)
		printf("  PASS, return value=%d, expected=%d\n", r, 0);
		#endif 
	}
	int expectedTreasureCount=2;
	int silverOrGoldCount=0;
	//int copperCount=0;
	//count the treasures in the hand
	int h;
	for(h=0; h<state->handCount[player]; h++){
		if(treasureCard != copper){ //bug introduced will cause infinite loop if coppers are counted
			if(state->hand[player][h]==treasureCard){
				silverOrGoldCount++;
			}
		} /*else { 
		if(state->hand[player][h]==treasureCard){
			copperCount++;
		}
	}	*/
	}
	if(silverOrGoldCount != expectedTreasureCount){
		printf("  FAIL, treasureCount=%d, expected=%d\n", silverOrGoldCount, expectedTreasureCount);
		printf("  NOTE: If treasure is 4 (copper), failed unit test is expected due to bug introduced in assignment 1.\n");
		err++;
	}else{
		printf("  PASS, treasureCount=%d, expected=%d\n", silverOrGoldCount, expectedTreasureCount);	  
	}

	/*Check for unexpected transactions*/
	printf("  Testing for unexpected transactions. Checking supply counts...\n");
	err += supplyCheck(state,curse,"curse",10);
	printf("    Checking Victory cards in supply:\n");
	err += supplyCheck(state,estate,"estate",8);
	err += supplyCheck(state,duchy,"duchy",8);
	err += supplyCheck(state,province,"province",8);
	printf("    Checking Treasure cards in supply:\n");	
	err += supplyCheck(state,copper,"copper",60-(7*2));
	err += supplyCheck(state,silver,"silver",40);
	err += supplyCheck(state,gold,"gold",30);
	
	return err;
}


int main() {
	int i,p,r;
	int seed = 1000;
	int numPlayer = 2;
	int k[10] = {adventurer, council_room, feast, gardens, mine
		, remodel, smithy, village, baron, great_hall};
	struct gameState G;
	// arrays of all coppers, silvers, and golds
	int adventurers[MAX_HAND];
	int coppers[MAX_HAND];
	int silvers[MAX_HAND];
	int golds[MAX_HAND];
	for (i = 0; i < MAX_HAND; i++){
		adventurers[i] = adventurer;
		coppers[i] = copper;
		silvers[i] = silver;
		golds[i] = gold;
	}
	
	int errFlag=0;
	int maxHandCount = 5; 
	int maxDiscardCount = 5;
	int maxDeckCount = 10;
	int treasureCard;
	
	printf ("TESTING adventurerEffect():\n");

	for(p = 0; p<numPlayer; p++){
		for(treasureCard = copper; treasureCard<=gold; treasureCard++){
			printf("Testing player %d, and treasure card %d\n", p,treasureCard);
			memset(&G, 23, sizeof(struct gameState));   // clear the game state
			r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
			G.handCount[p] = maxHandCount;                 // set the number of cards on hand
			G.deckCount[p] = maxDeckCount; 
			G.discardCount[p] = maxDiscardCount;
			memcpy(G.hand[p], adventurers, sizeof(int) * maxHandCount); //set all cards in hand to adventurer
			if(treasureCard == gold){
				memcpy(G.deck[p], golds, sizeof(int) * maxDeckCount); // set all the cards to gold
				memcpy(G.discard[p], golds, sizeof(int) * maxDiscardCount); // set all the cards to gold
			} else if (treasureCard == silver){
				memcpy(G.deck[p], silvers, sizeof(int) * maxDeckCount); // set all the cards to silver
				memcpy(G.discard[p], silvers, sizeof(int) * maxDiscardCount); // set all the cards to silver
			} else{
				memcpy(G.deck[p], coppers, sizeof(int) * maxDeckCount); // set all the cards to copper
				memcpy(G.discard[p], silvers, sizeof(int) * maxDiscardCount); // set all the cards to copper
			}
			if(checkAdventurerEffect(&G,p,treasureCard) > 0){
				errFlag++;
			}
		}
	}


	if(errFlag != 0){
		printf("Some tests failed.\n");
		printf("NOTE: Some tests may have failed due to bugs introduced in assignment 1. These tests have detected those bugs. See above results for explanation.\n");
	}else{
		printf("All tests passed!\n");
	}
	return 0;
}