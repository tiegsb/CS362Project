/* -----------------------------------------------------------------------
* Programmed by: Kelvin Watson
* Filename: randomtestadventurer.c
* Created: 27 Oct 2015
* Last modified: 2 Nov 2015
* Description: Assignment 4: Random tests for adventurerEffect2() method
* I needed to create a different buggy version of adventurerEffect() since
* my original version from assignment 2 introduced an infinite loop
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

int checkAdventurerEffect(struct gameState *post, int player, int opponent) {
	struct gameState oracle;
	memcpy (&oracle, post, sizeof(struct gameState));
	int errCount=0;
	
	int actualPostTreasureCount, actualOpponentPostTreasureCount, actualHandCount;
	int actualOpponentHandCount, actualOpponentDiscardCount, actualOpponentDeckCount;
	
	int oracleHandCount, oraclePreTreasureCount, oraclePostTreasureCount;
	int oracleOpponentPreTreasureCount, oracleOpponentPostTreasureCount;
	int oracleOpponentHandCount, oracleOpponentDiscardCount, oracleOpponentDeckCount;
	int h;
		
	oraclePreTreasureCount=0;
	
	//count treasure cards in hand prior to call
	for(h=0; h<oracle.handCount[player]; h++){
		if(	oracle.hand[player][h] == copper ||
			oracle.hand[player][h] == silver ||
			oracle.hand[player][h] == gold){
				++oraclePreTreasureCount;
			}
	}
	oracleOpponentPreTreasureCount=0; //count all treasure cards in opponent's hand prior to call
	for(h=0; h<oracle.handCount[opponent]; h++){
		if(	oracle.hand[opponent][h] == copper ||
			oracle.hand[opponent][h] == silver ||
			oracle.hand[opponent][h] == gold){
				++oracleOpponentPreTreasureCount; 
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
	
	//Check for unwanted transactions in opponent's hand and treasureCount
	printf("Checking for unwanted transactions in opponent's hand and treasure count:");

	oracleOpponentPostTreasureCount = oracleOpponentPreTreasureCount;
	actualOpponentPostTreasureCount=0;
	for(h=0; h<post->handCount[opponent]; h++){
		if(	post->hand[opponent][h] == copper ||
			post->hand[opponent][h] == silver ||
			post->hand[opponent][h] == gold){
				++actualOpponentPostTreasureCount;
			}
	}
	if(actualOpponentPostTreasureCount != oracleOpponentPostTreasureCount){
		printf("  FAIL, opponent treasure count=%d, expected=%d\n", actualOpponentPostTreasureCount, oracleOpponentPostTreasureCount);
		errCount++;
	}else{
		printf("  PASS, opponent treasure count=%d, expected=%d\n", actualOpponentPostTreasureCount, oracleOpponentPostTreasureCount);
	}

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

	int i, n, p, j, op;	
	int randDeckCount, randDiscardCount, randHandCount;
	int opRandDeckCount, opRandDiscardCount, opRandHandCount;
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
		op = p==0? 1:0; //assign opponent
		
		//randomize player's deck, discard and hand counts
		randDeckCount = G.deckCount[p] = (int)(Random() * MAX_DECK);
		randDiscardCount = G.discardCount[p] = (int)(Random() * MAX_DECK);
		randHandCount = G.handCount[p] = (int)(Random() * MAX_HAND);

		//randomize opponent's deck, discard and hand counts
		opRandDeckCount = G.deckCount[op] = (int)(Random() * MAX_DECK);
		opRandDiscardCount = G.discardCount[op] = (int)(Random() * MAX_DECK);
		opRandHandCount = G.handCount[op] = (int)(Random() * MAX_HAND);
		
		//Randomly generate an assortment of all cards for player and opponent
		for(j=0;j<randHandCount;j++){
			G.hand[p][j]=(int)(Random()*26);
			G.hand[op][j]=(int)(Random()*26);
		}
		for(j=0;j<randDiscardCount;j++){
			G.discard[p][j]=(int)(Random()*26);
			G.discard[op][j]=(int)(Random()*26);
		}
		for(j=0;j<randDeckCount;j++){
			G.deck[p][j]=(int)(Random()*26);
			G.deck[op][j]=(int)(Random()*26);
		}

		errFlag = checkAdventurerEffect(&G,p,op);
	}

	if(errFlag != 0){
		printf("Some tests failed.\n");
	} else {
		printf("ALL TESTS PASSED!\n");
	}
	return 0;
}