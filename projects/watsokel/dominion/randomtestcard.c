/* -----------------------------------------------------------------------
* Programmed by: Kelvin Watson
* Filename: randomtestcard.c
* Created: 27 Oct 2015
* Last modified: 2 Nov 2015
* Description: Random tests for embargo case in cardEffect() method
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

int checkEmbargo(struct gameState *post, int choice1, int opponent) {
	int errCount=0;
	int actualEmbargoTokenCount, oracleEmbargoTokenCount;
	int actualCoinCount, oracleCoinCount;
	
	int actualOpponentHandCount, oracleOpponentHandCount;
	int actualOpponentDiscardCount, oracleOpponentDiscardCount;
	int actualOpponentDeckCount, oracleOpponentDeckCount;
	
	int c = choice1;
	int bonus=0;
	int r;
	
	//Generate an oracle to compare results
	struct gameState oracle;
	memcpy (&oracle, post, sizeof(struct gameState));
	
	r = cardEffect(embargo, choice1, 0, 0, post, 0, &bonus);
	
	if(c==7 || c==8 || c==9 || c==10 || c==12 || c==13 || c==14
		|| c==16 || c==21 || c==26){
		if(r != 0){
			printf("  FAIL, return value=%d, expected=%d\n", r, 0);
			errCount++;
		}else{
			printf("  PASS, return value=%d, expected=%d\n", r, 0);
		}
		actualEmbargoTokenCount=post->embargoTokens[c];
		oracleEmbargoTokenCount=++oracle.embargoTokens[c];	
		if(actualEmbargoTokenCount != oracleEmbargoTokenCount){
			printf("  FAIL, embargoTokens=%d, expected=%d\n", actualEmbargoTokenCount, oracleEmbargoTokenCount);
			errCount++;
		} else{
			printf("  PASS, embargoTokens=%d, expected=%d\n", actualEmbargoTokenCount, oracleEmbargoTokenCount);
		}
	
	}else{
		if(r != -1){
			printf("  FAIL, r=%d, expected=%d\n", r, -1);
			errCount++;
		}else{
			printf("  PASS, r=%d, expected=%d\n", r, -1);
		}
	}
	
	actualCoinCount = post->coins;
	oracleCoinCount = oracle.coins+2;
	if(actualCoinCount != oracleCoinCount){
		printf("  FAIL, coins=%d, expected=%d\n", actualCoinCount, oracleCoinCount);
		errCount++;
	}else{
		printf("  PASS, coins=%d, expected=%d\n", actualCoinCount, oracleCoinCount);
	}
	
	//Check for unexpected transactions:
	printf("Checking for unexpected transactions in opponent's deck, hand, and discard piles");
	actualOpponentHandCount = post->handCount[opponent];
	oracleOpponentHandCount = oracle.handCount[opponent];
	if(actualOpponentHandCount != oracleOpponentHandCount){
		printf("  FAIL, opponent hand count=%d, expected=%d\n", actualOpponentHandCount, oracleOpponentHandCount);
		errCount++;
	}else{
		printf("  PASS, opponent hand count=%d, expected=%d\n", actualOpponentHandCount, oracleOpponentHandCount);
	}
	
	actualOpponentDiscardCount = post->discardCount[opponent];
	oracleOpponentDiscardCount = oracle.discardCount[opponent];
	if(actualOpponentDiscardCount != oracleOpponentDiscardCount){
		printf("  FAIL, opponent discard count=%d, expected=%d\n", actualOpponentDiscardCount, oracleOpponentDiscardCount);
		errCount++;
	}else{
		printf("  PASS, opponent discard count=%d, expected=%d\n", actualOpponentDiscardCount, oracleOpponentDiscardCount);
	}	
	
	actualOpponentDeckCount = post->deckCount[opponent];
	oracleOpponentDeckCount = oracle.deckCount[opponent];
	if(actualOpponentDeckCount != oracleOpponentDeckCount){
		printf("  FAIL, opponent deck count=%d, expected=%d\n", actualOpponentDeckCount, oracleOpponentDeckCount);
		errCount++;
	}else{
		printf("  PASS, opponent deck count=%d, expected=%d\n", actualOpponentDeckCount, oracleOpponentDeckCount);
	}	
	
	return errCount;
}

int main () {

	int i, n, p, j, op, handPos;
	int randDeckCount, randDiscardCount, randHandCount;
	int choice1;
	int errFlag=0;
	//int k[10] = {adventurer, council_room, feast, gardens, cutpurse,
	//	remodel, smithy, village, treasure_map, great_hall};
	//7,8,9,10,12,13,14,16,21,26
	struct gameState G;

	printf ("Testing embargo case in cardEffect().\n");
	printf ("RANDOM TESTS.\n");

	SelectStream(2);
	PutSeed(3);

	for (n = 0; n < 2000; n++) {
		for (i = 0; i < sizeof(struct gameState); i++) {
			((char*)&G)[i] = (int)(Random() * 256);
		}
		
		p = (int)(Random() * 2);
		op = p==0? 1:0; //assign opponent

		//randomize player's deck, discard and hand counts
		randDeckCount = G.deckCount[p] = (int)(Random() * MAX_DECK);
		randDiscardCount = G.discardCount[p] = (int)(Random() * MAX_DECK);
		randHandCount = G.handCount[p] = (int)(Random() * MAX_HAND);

		//randomize opponent's deck, discard and hand counts
		randDeckCount = G.deckCount[op] = (int)(Random() * MAX_DECK);
		randDiscardCount = G.discardCount[op] = (int)(Random() * MAX_DECK);
		randHandCount = G.handCount[op] = (int)(Random() * MAX_HAND);

		G.playedCardCount = (int)(Random() * (MAX_DECK-10));
		G.whoseTurn = p;
		G.numPlayers = 2;
		
		//randomize coin count
		G.coins = (int)(Random() * 1000);
		
		//randomize hand position
		handPos = (int)(Random()* 5);
		
		//randomize counts of supply cards based on kingdom card k array
		for(j=0; j<treasure_map; j++){	
			if(j==7 || j==8 || j==9 || j==10 || j==12 || j==13 || j==14
			|| j==16 || j==21 || j==26){
				G.supplyCount[j]=(int)(Random()*100);			
			} else {
				G.supplyCount[j]=-1;
			}
		}
		
		//randomize cards in hand for player and opponent
		for(j=0;j<randHandCount;j++){
			G.hand[p][j]=(int)(Random()*26);
			G.hand[op][j]=(int)(Random()*26);
		}
		//randomize discard piles for player and opponent
		for(j=0;j<randDiscardCount;j++){
			G.discard[p][j]=(int)(Random()*26);
			G.discard[op][j]=(int)(Random()*26);
		}
		//randomize cards in deck for player and opponent
		for(j=0;j<randDeckCount;j++){
			G.deck[p][j]=(int)(Random()*26);
			G.deck[op][j]=(int)(Random()*26);
		}
		
		//randomize kingdom card choice
		choice1=((int)(Random()*19))+7;
		
		//check embargo case in cardEffect()
		errFlag = checkEmbargo(&G,choice1,op);
	}

	if(errFlag != 0){
		printf("Some tests failed.\n");
	} else {
		printf("ALL TESTS PASSED!\n");
	}
	return 0;
}