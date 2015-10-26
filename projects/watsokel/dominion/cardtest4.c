/* -----------------------------------------------------------------------
* Programmed by: Kelvin Watson
* Filename: cardtest4.c
* Created: 15 Oct 2015
* Last modified: 17 Oct 2015
* Description: Unit tests for dominion.c's steward case in the cardEffect() 
* function.
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

int checkSteward(struct gameState *state, int player, int choice1, int choice2, int choice3){
	/*Check for unexpected transactions*/
	int err=0;
	int bonus=0;
	int k;
	struct gameState oracle;
	memcpy(&oracle,state,sizeof(struct gameState)); //create a reference to compare the steward case to
	int oracleHandCount, oracleCoinCount, oracleDiscardCount;
	int actualHandCount, actualCoinCount, actualDiscardCount;
	/* Replicate game state using oracle, then test against game state */
	cardEffect(steward,choice1,choice2,choice3,state,0,&bonus);
	actualHandCount=state->handCount[player];
	actualCoinCount=state->coins;
	actualDiscardCount=state->discardCount[player];
	if(choice1==1){
		//2 cards will be drawn from deck
		//place two cards from deck into hand in oracle
		for(k=0; k<2; k++){	
			oracle.hand[player][oracle.handCount[player]]=oracle.deck[player][oracle.deckCount[player]];
			++oracle.handCount[player];
			--oracle.deckCount[player];
		}
		--oracle.handCount[player]; //discard played steward
		oracleHandCount=oracle.handCount[player];
		//test against game state
		if(actualHandCount != oracleHandCount){
			printf("    FAIL: choice1==1 Hand count after adding two cards(and discarding played steward)=%d,expected=%d\n",actualHandCount,oracleHandCount);
		} else{
			printf("    PASS: choice1==1 Hand count after adding two cards=%d,expected=%d\n",actualHandCount,oracleHandCount);
		}
	} else if(choice1==2){
		oracle.coins+=2;
		oracleCoinCount=oracle.coins;
		if(actualCoinCount != oracleCoinCount){
			printf("    FAIL: choice1==2 Coins after adding two coins=%d,expected=%d\n",actualCoinCount,oracleCoinCount);
		} else{
			printf("    PASS: choice1==2 Coins after adding two coins=%d,expected=%d\n",actualCoinCount,oracleCoinCount);
		}
	} else{
		discardCard(choice2,player,&oracle,1); //trashed, not added to any pile
		discardCard(choice3,player,&oracle,1);
		oracleDiscardCount=oracle.discardCount[player];
		if(actualDiscardCount != oracleDiscardCount){
			printf("    FAIL: choice1 != 1, != 2; Discard count=%d,expected=%d\n",actualDiscardCount,oracleDiscardCount);
		} else{
			printf("    PASS: choice1 != 1, != 2; Discard count after =%d,expected=%d\n",actualDiscardCount,oracleDiscardCount);
		}		
	}

	printf("  Testing for unexpected transactions against oracle. Checking supply counts...\n");
	err += supplyCheck(state,curse,"curse",oracle.supplyCount[curse]);
	printf("    Checking Victory cards in supply:\n");
	err += supplyCheck(state,estate,"estate",oracle.supplyCount[estate]);
	err += supplyCheck(state,duchy,"duchy",oracle.supplyCount[duchy]);
	err += supplyCheck(state,province,"province",oracle.supplyCount[province]);
	printf("    Checking Treasure cards in supply:\n");	
	err += supplyCheck(state,copper,"copper",oracle.supplyCount[copper]);
	err += supplyCheck(state,silver,"silver",oracle.supplyCount[silver]);
	err += supplyCheck(state,gold,"gold",oracle.supplyCount[gold]);
	
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
	int golds[MAX_HAND];
	int stewards[MAX_HAND];

	for (i = 0; i < MAX_HAND; i++){
		golds[i] = gold;
		stewards[i] = steward;
	}
	int errFlag=0;
	int maxHandCount = 5;
	int maxDeckCount = 10;
	int opponent;
	int choice1,choice2,choice3;
	int choices = 4; //choices rante from 1-3 in steward, so testing 0 and 4 as boundary/edge cases
	printf ("TESTING steward case in cardEffect():\n");
	
	for(p = 0; p<numPlayer; p++){
		printf("Testing player %d\n", p);
		for(choice1 = 0; choice1<choices; choice1++){
			memset(&G, 23, sizeof(struct gameState));   // clear the game state
			r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
			G.whoseTurn=p;
			/*Since player 0 always draws 5 cards on initialization, we must equalize the players' hands and decks*/
			G.deckCount[p] = maxDeckCount;
			opponent = p==0? 1:0;
			
			/* Initialize player's decks */
			G.deckCount[p] = maxDeckCount;
			G.handCount[p] = maxHandCount;                 // set the number of cards on hand
			memcpy(G.hand[p], stewards, sizeof(int) * maxHandCount); //set all cards in current player's hand to steward
			memcpy(G.deck[p], golds, sizeof(int) * maxDeckCount); //set all cards in deck to gold to enable detection of cards drawn			
			
			G.coins = 0; //standardize coin count to enable detection of coin draws
			choice2 = G.hand[p][0]; 
			choice3 = G.hand[p][1];
			//printf("choice2=%d\t choice3=%d\n",choice2,choice3);
			if(checkSteward(&G,p,choice1,choice2,choice3)>0){
				errFlag++;
			}
		}
	}
	
	if(errFlag != 0){
		printf("Some tests failed. See bug1.c for details.\n");  
	}else{
		printf("All tests passed!\n");
	}
	return 0;
}