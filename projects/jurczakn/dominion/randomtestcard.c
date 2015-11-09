#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

struct gameState makeRandomGameState(int* k){

	struct gameState G;
	unsigned r;
	int i, j, players, pass;
	players = rand() % 3;
	players += 2;
	r = rand();
	for (i = 0; i < 10; i++){
		k[i] = rand() % 20;
		pass = -1;
		while (pass < 0){
			pass = 1;
			for (j = 0; j < i; j++){
				if (k[i] == k[j]){
					k[i] = rand() % 20;
					pass = -1;
				}
			}
		}
	}
	for (i = 0; i < 10; i++){
		switch (k[i]){
			case 0:
				k[i] = adventurer;
				break;			
			case 1:
				k[i] = council_room;
				break;			
			case 2:
				k[i] = feast;
				break;			
			case 3:
				k[i] = gardens;
				break;			
			case 4:
				k[i] = mine;
				break;			
			case 5:
				k[i] = remodel;
				break;			
			case 6:
				k[i] = smithy;
				break;			
			case 7:
				k[i] = village;
				break;			
			case 8:
				k[i] = baron;
				break;			
			case 9:
				k[i] = great_hall;
				break;			
			case 10:
				k[i] = minion;
				break;			
			case 11:
				k[i] = steward;
				break;			
			case 12:
				k[i] = tribute;
				break;			
			case 13:
				k[i] = ambassador;
				break;			
			case 14:
				k[i] = cutpurse;
				break;			
			case 15:
				k[i] = embargo;
				break;			
			case 16:
				k[i] = outpost;
				break;			
			case 17:
				k[i] = salvager;
				break;			
			case 18:
				k[i] = sea_hag;
				break;			
			case 19:
				k[i] = treasure_map;
				break;
		}
	}
	initializeGame(2, k, r, &G);
	return G;
}

int getrandomcard(int *k){

	int card;
	card = rand() % 10;
	return k[card];
}

int getrandomcoin(){

	int coin;
	coin = rand() % 3;
	switch(coin){
		case 0:
			return copper;
			break;
		case 1:
			return silver;
			break;
		case 2:
			return gold;
			break;
	}
	return -1;
}

int main(){
	int i, smithyPosition, p, j, l, result;
	int passing = 0;
	int failing = 0;
	int pf = 1;
	time_t t;
	int k[10];
	struct gameState G;
	int maxHandCount = 5;
	int maxDeckCount = 5;
	int maxDiscardCount = 5;
	int tests = 1000;
	int expectedHand[2+maxHandCount];
	srand((unsigned) time(&t));

	for (i = 0; i < tests; i++){
		printf("Test #%d: \n", i);
		G = makeRandomGameState(k);
		p = rand() % G.numPlayers;
		smithyPosition = rand() % maxHandCount;
		l = 0;
		for (j = 0; j < maxHandCount; j++){
			if (j == smithyPosition)
				G.hand[p][j] = smithy;
			else {
				if (rand() %2 == 1){
					G.hand[p][j] = getrandomcard(k);
				}
				else {
					G.hand[p][j] = getrandomcoin();
				}
				expectedHand[l] = G.hand[p][j];
				l++;
			}
		}
		for (j = 0; j < maxDeckCount; j++){
			if ((rand() %2) == 0){
				G.deck[p][j] = getrandomcoin();
			}
			else{
				G.deck[p][j] = getrandomcard(k);
			}
		}
		for (j = 0; j < maxDiscardCount; j++){
			G.discard[p][j] = getrandomcard(k);
		}
		G.handCount[p] = maxHandCount;
		G.deckCount[p] = maxDeckCount;
		G.discardCount[p] = maxDiscardCount;
		expectedHand[maxHandCount - 1] = G.deck[p][maxDeckCount-1];
		expectedHand[maxHandCount] = G.deck[p][maxDeckCount-2];
		expectedHand[maxHandCount+1] = G.deck[p][maxDeckCount-3];
		G.whoseTurn = p;
		printf("Player %d is playing smithy from hand position %d.\n", p, smithyPosition);
		printf("Hand: \npos0: %d\npos1: %d\npos2: %d\npos3: %d\npos4: %d\n", G.hand[p][0], G.hand[p][1], G.hand[p][2], G.hand[p][3], G.hand[p][4]);
		printf("handCount before: %d\n", G.handCount[p]);
		result = cardEffect(smithy, -1, -1, -1, &G, smithyPosition, 0);
		if (result == -1){
			printf("adventurer call failed<========\n");
			pf = 0;
		}
		//printf("adventurer call result %d\n", result);
		printf("handCount after: %d\n", G.handCount[p]);
		if (G.handCount[p] < maxHandCount+2){
			printf("Failure: too few hand cards<=============\n");
			pf = 0;
		}
		for (j = 0; j < G.handCount[p]; j++){
			if (j > maxDeckCount + 2){
				printf("Failure: hand too large.<========================\n");
				pf = 0;
				break;
			}
			else if (G.hand[p][j] != expectedHand[j]){
				printf("Failure: card in hand pos %d does not match<=========\n", j);
				pf = 0;
				printf("Expected %d, Found %d\n", expectedHand[j], G.hand[p][j]);
			}
		}
		if (pf < 1){
			failing++;
		}
		else passing++;
		pf = 1;
	}
	printf("total test runs: %d, passing test count: %d, failing count: %d\n", tests, passing, failing);
	return 0;
}
