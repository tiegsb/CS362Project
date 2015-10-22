/* -----------------------------------------------------------------------
* Programmed by: Kelvin Watson
* Filename: unittest2.c
* Created: 10 Oct 2015
* Last modified: 14 Oct 2015
* Description: Unit tests for dominion.c 's discardCard() function

* ***NOTE: Some of these unit tests fail. Professor Christi is aware of this.
* Please see Piazza post where I notify Professor Christi that I may have
* discovered a possible bug with this unit test:
* https://piazza.com/class/iespjuw0jz7jg?cid=47 ***
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

int checkDiscardCard(int handPos, int player, struct gameState* state,int handCount, int discardedCard){
	int errFlag=0; //used in place of assertion failure: test passed=0; assertion failure=1
	int r = discardCard(handPos,player,state,0);
	if(r != 0){
#if (NOISY_TEST==1)
		printf("  FAIL, return value=%d, expected=%d\n", r, 0);
#endif 
	} else{
#if (NOISY_TEST==1)
		printf("  PASS, return value=%d, expected=%d\n", r, 0);
#endif 
	}
	//assert(r==0);
	//check handCount
	if(state->handCount[player] != (handCount-1)){
#if (NOISY_TEST==1)
		printf("  FAIL, handCount=%d, expected=%d\n", state->handCount[player], (handCount-1));
#endif    
		errFlag=1; //set error flag
	} else {
#if (NOISY_TEST==1)
		printf("  PASS handCount=%d, expected=%d\n", state->handCount[player], (handCount-1));
#endif
	}
	//assert(state->handCount[player] == (handCount-1));
	//check discard pile for the card discarded
	if(state->discardCount[player] != 1){
#if (NOISY_TEST==1)
		printf("  FAIL, discardCount=%d, expected=%d\n", state->discardCount[player], 1);
#endif    
		errFlag=1; //set error flag
	} else {
#if (NOISY_TEST==1)
		printf("  PASS discardCount=%d, expected=%d\n", state->discardCount[player], 1);
#endif
	}

	if(state->discard[player][(state->discardCount[player])-1] != discardedCard){
#if (NOISY_TEST==1)
		printf("  FAIL, discardedCard=%d, expected=%d\n", state->discard[player][(state->discardCount[player])-1], discardedCard);
#endif    
		errFlag=1; //set error flag
	} else {
#if (NOISY_TEST==1)
		printf("  PASS, discardedCard=%d, expected=%d\n",state->discard[player][(state->discardCount[player])-1] , discardedCard);
#endif
	}
	//assert(state->discard[player][(state->discardCount[player])-1] == discardedCard);

	/*Check for unexpected transactions*/
	printf("  Testing for unexpected transactions. Checking supply counts...\n");
	errFlag += supplyCheck(state,curse,"curse",10);
	printf("    Checking Victory cards in supply:\n");
	errFlag += supplyCheck(state,estate,"estate",8);
	errFlag += supplyCheck(state,duchy,"duchy",8);
	errFlag += supplyCheck(state,province,"province",8);
	printf("    Checking Treasure cards in supply:\n");	
	errFlag += supplyCheck(state,copper,"copper",60-(7*2));
	errFlag += supplyCheck(state,silver,"silver",40);
	errFlag += supplyCheck(state,gold,"gold",30);
	
	return errFlag;
}


int main() {
	int i,p,r;
	int seed = 1000;
	int numPlayers = 2;
	int k[10] = {adventurer, sea_hag, council_room, feast, gardens, mine
		, remodel, smithy, baron, salvager};
	struct gameState G;
	int handPos,handCount;
	int maxHandCount = 5;
	int estates[MAX_HAND];
	int golds[MAX_HAND];
	int err=0;

	for (i = 0; i < MAX_HAND; i++){
		estates[i] = estate;
	}

	for (i = 0; i < MAX_HAND; i++){
		golds[i] = gold;
	}

	printf ("TESTING discardCard():\n");

	for (p = 0; p < numPlayers; p++){
		for(handCount=0; handCount<=maxHandCount; handCount++){
			for(handPos = 0; handPos < handCount; handPos++){
				printf("Testing player %d and discard card position of %d:\n", p, handPos);
				memset(&G, 23, sizeof(struct gameState));   // clear game state
				r=initializeGame(numPlayers, k, seed, &G);  // initialize new game
				G.handCount[p] = handCount;                 // set the number of cards on hand
				if(handCount>0){
					memcpy(G.hand[p], estates, sizeof(int) * handCount); //set all cards in hand to estate
					//printf("setting handPos=%d to be gold\n",handPos);
					if(handCount) G.hand[p][handPos]=gold; //set one card to be gold
				}
				//printf("G.hand[p][gold]=%d\n",G.hand[p][handPos]);
				if(checkDiscardCard(handPos,p,&G,handCount,gold) == 1){ //attempt to remove the single gold card
					err++;
				}
			}
		}
	}

	if(err != 0){
		printf("Some tests failed. See bug1.c for details.\n");
	} else {
		printf("All tests passed!\n");
	}

	return 0;
}