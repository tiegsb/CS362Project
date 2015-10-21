/* -----------------------------------------------------------------------
* Programmed by: Kelvin Watson
* Filename: cardtest1.c
* Created: 15 Oct 2015
* Last modified: 15 Oct 2015
* Description: Unit tests for dominion.c 's smithyEffect() function
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

int checkSmithyEffect(int player, struct gameState *state, int handPosition){
	int err=0; //used in place of assertion failure: test passed=0; assertion failure=1
	int expectedHandCount = 5;
	int expectedDeckCount = 10;
	int expectedDiscardCount = 0;
	
	int otherPlayer = player==0? 1:0; 
	
	if(state->handCount[player] != expectedHandCount){
		#if (NOISY_TEST==1)
		printf("  BEFORE smithyEffect() call: FAIL, handCount=%d, expected=%d\n", state->handCount[player], expectedHandCount);
		#endif 
		err++;
	} else{
		#if (NOISY_TEST==1)
		printf("  BEFORE smithyEffect() call: PASS, handCount=%d, expected=%d\n", state->handCount[player], expectedHandCount);
		#endif 
	}

	if(state->deckCount[player] != expectedDeckCount){
		#if (NOISY_TEST==1)
		printf("  BEFORE smithyEffect() call: FAIL, deckCount=%d, expected=%d\n", state->deckCount[player], expectedDeckCount);
		#endif 
		err++;
	} else{
		#if (NOISY_TEST==1)
		printf("  BEFORE smithyEffect() call: PASS, deckCount=%d, expected=%d\n", state->deckCount[player], expectedDeckCount);
		#endif 
	}

	if(state->discardCount[player] != expectedDiscardCount){
		#if (NOISY_TEST==1)
		printf("  BEFORE smithyEffect() call: FAIL, discardCount=%d, expected=%d\n", state->discardCount[player], expectedDiscardCount);
		#endif 
		err++;
	} else{
		#if (NOISY_TEST==1)
		printf("  BEFORE smithyEffect() call: PASS, discardCount=%d, expected=%d\n", state->discardCount[player], expectedDiscardCount);
		#endif 
	}

	
	/*print player's hand and deck prior to playing smithy*/
	int i, numSmithys=0, expectedSmithys=5;
	for(i=0; i<state->handCount[player]; i++){
		if(state->hand[player][i] == smithy){
			numSmithys++;
		}
	}
	if(numSmithys != 5){
		#if (NOISY_TEST==1)
		printf("    FAIL: hand contains number of smithys=%d, expected=%d\n",numSmithys,expectedSmithys);
		#endif 
		err++;
	} else{
		printf("    PASS: hand contains number of smithys=%d, expected=%d\n",numSmithys,expectedSmithys);
	}
	
	int r = smithyEffect(player, state, handPosition);
	
	if(r != 0){
		#if (NOISY_TEST==1)
		printf("  AFTER smithyEffect() call: FAIL, return value=%d, expected=%d\n", r, 0);
		#endif 
		err++;
	} else{
		#if (NOISY_TEST==1)
		printf("  AFTER smithyEffect() call: PASS, return value=%d, expected=%d\n", r, 0);
		#endif 
	}
	
	expectedHandCount = 7; //5 in hand + 3 drawn - 1 smithy = 7
	if(state->handCount[player] != expectedHandCount){
		#if (NOISY_TEST==1)
		printf("    FAIL, handCount=%d, expected=%d\n", state->handCount[player], expectedHandCount);
		#endif 
		err++;
	} else{
		#if (NOISY_TEST==1)
		printf("    PASS, handCount=%d, expected=%d\n", state->handCount[player], expectedHandCount);
		#endif 
	}
	expectedDeckCount = 7; //10 in original deck -3 for smithy draw = 7
	if(state->deckCount[player] != expectedDeckCount){
		#if (NOISY_TEST==1)
		printf("    FAIL, deckCount=%d, expected=%d\n", state->deckCount[player], expectedDeckCount);
		#endif 
		err++;
	} else{
		#if (NOISY_TEST==1)
		printf("    PASS, deckCount=%d, expected=%d\n", state->deckCount[player], expectedDeckCount);
		#endif 
	}  
	
	expectedDiscardCount = 1; //10 in original deck -3 for smithy draw = 7
	if(state->discardCount[player] != expectedDiscardCount){
		#if (NOISY_TEST==1)
		printf("    FAIL, discardCount=%d, expected=%d\n", state->discardCount[player], expectedDiscardCount);
		#endif 
		err++;
	} else{
		#if (NOISY_TEST==1)
		printf("    PASS, discardCount=%d, expected=%d\n", state->discardCount[player], expectedDiscardCount);
		#endif 
	}  

	/*print player's hand and deck after playing smithy*/
	numSmithys=0, expectedSmithys=4;
	int numGolds=0;
	int expectedGolds=3;
	for(i=0; i<state->handCount[player]; i++){
		if(state->hand[player][i] == smithy){
			numSmithys++;
		} else if(state->hand[player][i] == gold){
			numGolds++;
		}
	}
	if(numSmithys != 4){
		#if (NOISY_TEST==1)
		printf("    FAIL: hand contains number of smithys=%d, expected=%d\n",numSmithys,expectedSmithys);
		#endif 
		err++;
	} else{
		#if (NOISY_TEST==1)
		printf("    PASS: hand contains number of smithys=%d, expected=%d\n",numSmithys,expectedSmithys);
		#endif 
	}
	if(numGolds != 3){
		#if (NOISY_TEST==1)
		printf("    FAIL: hand contains number of golds=%d, expected=%d\n",numGolds,expectedGolds);
		#endif 
		err++;
	} else{
		#if (NOISY_TEST==1)
		printf("    PASS: hand contains number of golds=%d, expected=%d\n",numGolds,expectedGolds);
		#endif 
	}

	
	/*print player's hand and deck after playing smithy*/


	/*The other player's cards must not have been disturbed*/
	int expectedOtherPlayerHandCount=5;
	int expectedOtherPlayerDeckCount=10;
	
	//check other player's hand and deck
	if(state->handCount[otherPlayer] != expectedOtherPlayerHandCount){
		#if (NOISY_TEST==1)
		printf("    FAIL, otherPlayerHandCount=%d, expected=%d\n", state->handCount[otherPlayer], expectedOtherPlayerHandCount);
		#endif 
		err++;
	} else{
		#if (NOISY_TEST==1)
		printf("    PASS, otherPlayerHandCount=%d, expected=%d\n", state->handCount[otherPlayer], expectedOtherPlayerHandCount);
		#endif 
	}
	if(state->deckCount[otherPlayer] != expectedOtherPlayerDeckCount){
		#if (NOISY_TEST==1)
		printf("    FAIL, otherPlayerDeckCount=%d, expected=%d\n", state->deckCount[otherPlayer], expectedOtherPlayerDeckCount);
		#endif 
		err++;
	} else{
		#if (NOISY_TEST==1)
		printf("    PASS, otherPlayerDeckCount=%d, expected=%d\n", state->deckCount[otherPlayer], expectedOtherPlayerDeckCount);
		#endif 
	} 

	/*print player's hand and deck after playing smithy*/
	int numMines=0, expectedMines=5;
	int numSilvers=0;
	int expectedSilvers=10;
	for(i=0; i<state->handCount[otherPlayer]; i++){
		if(state->hand[otherPlayer][i] == mine){
			numMines++;
		}	
	}
	for(i=0; i<state->deckCount[otherPlayer]; i++){
		if(state->deck[otherPlayer][i] == silver){
			numSilvers++;
		}
	}
	if(numMines != 5){
		#if (NOISY_TEST==1)
		printf("    FAIL: other player's hand contains number of mines=%d, expected=%d\n",numMines,expectedMines);
		#endif 
		err++;
	} else{
		#if (NOISY_TEST==1)
		printf("    PASS: other player's hand contains number of mines=%d, expected=%d\n",numMines,expectedMines);
		#endif 
	}
	if(numSilvers != 10){
		#if (NOISY_TEST==1)
		printf("    FAIL: other player's hand contains number of silvers=%d, expected=%d\n",numSilvers,expectedSilvers);
		#endif 
		err++;
	} else{
		#if (NOISY_TEST==1)
		printf("    PASS: other player's hand contains number of silvers=%d, expected=%d\n",numSilvers,expectedSilvers);
		#endif 
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
	int smithys[MAX_HAND];
	int golds[MAX_HAND];
	int mines[MAX_HAND];
	int silvers[MAX_HAND];
	for (i = 0; i < MAX_HAND; i++){
		smithys[i] = smithy;
	}
	for (i = 0; i < MAX_HAND; i++){
		golds[i] = gold;
	}
	for (i = 0; i < MAX_HAND; i++){
		mines[i] = mine;
	}
	for (i = 0; i < MAX_HAND; i++){
		silvers[i] = silver;
	}
	int errFlag=0;
	int maxHandCount = 5;
	int maxDeckCount = 10;
	
	printf ("TESTING smithyEffect():\n");

	for(p = 0; p<numPlayer; p++){
		printf("Testing player %d\n", p);
		memset(&G, 23, sizeof(struct gameState));   // clear the game state
		r = initializeGame(numPlayer, k, seed, &G); // initialize a new game

		/*Since player 0 always draws 5 cards on initialization, we must equalize the players' hands and decks*/
		G.deckCount[p] = maxDeckCount;
		if(p==0) G.deckCount[p+1] = maxDeckCount;
		else G.deckCount[p-1] = maxDeckCount;
		G.deckCount[p] = maxDeckCount;
		G.handCount[p] = maxHandCount;                 // set the number of cards on hand
		if(p==0) G.handCount[p+1] = maxHandCount;                 // set the number of cards on hand
		else G.handCount[p-1] = maxHandCount;

		//set all cards to different cards in each players' decks to enable detection of card draws
		memcpy(G.hand[p], smithys, sizeof(int) * maxHandCount); //set all cards in current player's hand to smithy
		if(p==0) memcpy(G.hand[p+1], mines, sizeof(int) * maxHandCount); //set all cards in other players' hands to mines
		else memcpy(G.hand[p-1], mines, sizeof(int) * maxHandCount);
		
		memcpy(G.deck[p], golds, sizeof(int) * maxDeckCount); //set all cards in deck to gold to enable detection of card draws
		if(p==0) memcpy(G.deck[p+1], silvers, sizeof(int) * maxDeckCount);
		else memcpy(G.deck[p-1], silvers, sizeof(int) * maxDeckCount);
		
		if(checkSmithyEffect(p, &G, 0) > 0){
			errFlag++;
		}
	}

	if(errFlag != 0){
		printf("Some tests failed. See bug1.c for details.\n");  
	}else{
		printf("All tests passed!\n");
	}
	return 0;
}