/* -----------------------------------------------------------------------
* Programmed by: Kelvin Watson
* Filename: cardtest3.c
* Created: 15 Oct 2015
* Last modified: 17 Oct 2015
* Description: Unit tests for dominion.c's sea_hag case in the cardEffect() 
* function.
* NOTE: BUGS IDENTIFIED:
	I am quite confident that the sea_hag case in cardEffect() contains 
	several bugs. Namely, the deck count is erroneously reduced by 3 cards, 
	when the overall deck count should not have changed - i.e. the deck 
	count should have only been decremented once when top of deck was 
	discarded, then incremented when curse card was added. Instead, the deck 
	count was decremented three times and the deck was not incremented when 
	the curse was placed at the top of the pile. Also, the supply count of 
	curse cards was not decremented when the curse card was placed on top 
	of opponents' decks.
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

int checkSeaHag(struct gameState *state, int player, int opponent){
	/*Check for unexpected transactions*/
	int err=0;
	struct gameState oracle;
	memcpy(&oracle,state,sizeof(struct gameState));

	printf("  --Testing oracle against state before call to cardEffect(sea_hag) for player number %d, opponent number %d--\n",player,opponent);

	/* Before discarding, check the identity of the card to be discarded */
	int oracleToBeDiscarded = oracle.deck[opponent][oracle.deckCount[opponent]-1]; //store the discarded card
	int actualToBeDiscarded = state->deck[opponent][oracle.deckCount[opponent]-1];
	if(actualToBeDiscarded != oracleToBeDiscarded){
		printf("    FAIL: Opponent's card to be discarded=%d,expected=%d\n",actualToBeDiscarded,oracleToBeDiscarded);
	}else{
		printf("    PASS: Opponent's card to be discarded=%d,expected=%d\n",actualToBeDiscarded,oracleToBeDiscarded);
	}
	/* Check deck, hand and discard counts against oracle */
	int oracleDeckCount = oracle.deckCount[opponent];
	int actualDeckCount = state->deckCount[opponent];
	if(actualDeckCount != oracleDeckCount){
		printf("    FAIL: Deck count before discarding top of deck=%d,expected=%d\n",actualDeckCount,oracleDeckCount);
	}else{
		printf("    PASS: Deck count before discarding top of deck=%d,expected=%d\n",actualDeckCount,oracleDeckCount);	
	}
	/* Check deck, hand and discard counts against oracle */
	int oracleHandCount = oracle.deckCount[opponent];
	int actualHandCount = state->deckCount[opponent];
	if(actualDeckCount != oracleDeckCount){
		printf("    FAIL: Hand count before discarding top of deck=%d,expected=%d\n",actualHandCount,oracleHandCount);
	}else{
		printf("    PASS: Hand count before discarding top of deck=%d,expected=%d\n",actualHandCount,oracleHandCount);	
	}
	/* Check deck, hand and discard counts against oracle */
	int oracleDiscardCount = oracle.discardCount[opponent];
	int actualDiscardCount = state->discardCount[opponent];
	if(actualDiscardCount != oracleDiscardCount){
		printf("    FAIL: Discard count before discarding top of deck=%d,expected=%d\n",actualDiscardCount,oracleDiscardCount);
	}else{
		printf("    PASS: Discard count before discarding top of deck=%d,expected=%d\n",actualDiscardCount,oracleDiscardCount);	
	}

	printf("  --Testing oracle against call to cardEffect(sea_hag) for player number %d, opponent number %d--\n",player,opponent);

	int bonus=0;
	cardEffect(sea_hag,0,0,0,state,state->hand[player][sea_hag],&bonus);

	/* TEST ORACLE: replicate expected sea_hag action and compare against actual game state*/
	
	/* Take top of opponent's deck and place in discard pile*/
	oracle.discard[opponent][oracle.discardCount[opponent]] = oracleToBeDiscarded;
	/* Decrement deck count and increment discard count*/
	--oracle.deckCount[opponent];
	++oracle.discardCount[opponent];
	/* Test that the card being discarded ends up in top of the discard pile*/
	int oracleDiscardedCard = oracle.discard[opponent][oracle.discardCount[opponent]-1];
	int actualDiscardedCard = state->discard[opponent][state->discardCount[opponent]-1];
	if(actualDiscardedCard != oracleDiscardedCard){
		printf("    FAIL: Card on top of opponent's discard pile after discarding top of deck=%d,expected=%d\n",actualDiscardedCard,oracleDiscardedCard);
	}else{
		printf("    PASS: Card on top of opponent's discard pile after discarding top of deck=%d,expected=%d\n",actualDiscardedCard,oracleDiscardedCard);	
	}
	/* distribute curse from the supply to the top of the opponents' decks*/ 
	oracle.deck[opponent][oracle.deckCount[opponent]] = curse;
	/* increment the deck count */
	++oracle.deckCount[opponent];
	/* decrement supply's curse card count*/
	--oracle.supplyCount[curse];
	/* check that the top of the deck is now a curse */
	int oracleTopOfDeck = oracle.deck[opponent][oracle.deckCount[opponent]-1]; 
	int actualTopOfDeck = state->deck[opponent][state->deckCount[opponent]-1];
	if(actualTopOfDeck != oracleTopOfDeck){
		printf("    FAIL: Card on top of opponent's deck after distributing curse=%d,expected=%d\n",actualTopOfDeck,oracleTopOfDeck);
	}else{
		printf("    PASS: Card on top of opponent's deck after distributing curse=%d,expected=%d\n",actualTopOfDeck,oracleTopOfDeck);	
	}
	/* Check deck counts against oracle */
	oracleDeckCount = oracle.deckCount[opponent];
	actualDeckCount = state->deckCount[opponent];
	if(actualDeckCount != oracleDeckCount){
		printf("    FAIL: Deck count after discarding top of deck=%d,expected=%d\n",actualDeckCount,oracleDeckCount);
	}else{
		printf("    PASS: Deck count after discarding top of deck=%d,expected=%d\n",actualDeckCount,oracleDeckCount);	
	}
	/* check oracle's vs actual's deck count, discard count, top of discard, top of deck*/
	//if(state->)
	//assert(memcmp(&oracle,state,sizeof(struct gameState))==0); //assertion fails due to bug in cardEffect()'s sea_hag case
	
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
	int curses[MAX_HAND];
	int sea_hags[MAX_HAND];
	int duchys[MAX_HAND];	
	int estates[MAX_HAND];
	int mines[MAX_HAND];

	for (i = 0; i < MAX_HAND; i++){
		curses[i] = curse;
		sea_hags[i] = sea_hag;
		duchys[i] = duchy;
		estates[i] = estate;
		mines[i] = mine;
	}
	int errFlag=0;
	int maxHandCount = 5;
	int maxDeckCount = 10;
	int opponent;
	printf ("TESTING sea_hag case in cardEffect():\n");
	
	for(p = 0; p<numPlayer; p++){
		printf("Testing player %d\n", p);
		memset(&G, 23, sizeof(struct gameState));   // clear the game state
		r = initializeGame(numPlayer, k, seed, &G); // initialize a new game

		/*Since player 0 always draws 5 cards on initialization, we must equalize the players' hands and decks*/
		G.deckCount[p] = maxDeckCount;
		opponent = p==0? 1:0;
		
		/* Initialize player's decks */
		G.deckCount[p] = maxDeckCount;
		G.handCount[p] = maxHandCount;                 // set the number of cards on hand
		memcpy(G.hand[p], sea_hags, sizeof(int) * maxHandCount); //set all cards in current player's hand to smithy
		memcpy(G.deck[p], duchys, sizeof(int) * maxDeckCount); //set all cards in deck to gold to enable detection of card draws
		
		/* Initialize opponent's decks */
		G.deckCount[opponent] = maxDeckCount;
		G.handCount[opponent] = maxHandCount;
		memcpy(G.hand[opponent], mines, sizeof(int) * maxHandCount); //set all cards in other players' hands to mines
		memcpy(G.deck[opponent], estates, sizeof(int) * maxDeckCount);//set all cards in oppponent's deck to estates except the top to enable detection of card to be placed in discard
		G.deck[opponent][maxDeckCount-1] = gold; //top of opponent's deck is a gold Treasure card to allow detection of discard
		
		if(checkSeaHag(&G,p,opponent)>0){
			errFlag++;
		}
	}
	
	if(errFlag != 0){
		printf("Some tests failed. See bug1.c for details.\n");  
		printf("NOTE: I am quite confident that the sea_hag case in cardEffect() has several bugs.\n");
	}else{
		printf("All tests passed!\n");
	}
	return 0;
}