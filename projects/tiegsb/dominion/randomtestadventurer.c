/*
Brian Tiegs
CS 362 - Assignment 4
Random Test Adventurer Card

Test randomizes game state and tests the following conditions:
-change in game state
-change in other player's states
-treasure cards added to player's hand
-discarded cards from deck moved to discard pile

*/

#include "interface.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>


#define DEBUG 0
#define NOISY_TEST 1
#define SEED_START 1

//gets a random card from kingdom cards, treasure cards or estate cards
//used to build random decks
int randomizeCard(int kingCards[NUM_K_CARDS]){
	int randomInt;

	randomInt = Random() * 17;

	if(randomInt < 7)
		return randomInt;
	else
		return (kingCards[randomInt - 7]);
}

//randomizes a complete game
void randomizeGame(struct gameState *state, int seed)
{
	int i, j;
	int numPlayers;
	int kingCards[NUM_K_CARDS];
	int cardCheck;

	//get random number of players between 2 and 4
	numPlayers = Random() * (MAX_PLAYERS - 1) + 2;

	//randomize kingdom cards
	selectKingdomCards(seed, kingCards);

	//check if adventurer card is in kingdom cards
	cardCheck = 0;
	for(i = 0; i < NUM_K_CARDS; i++){
		if(kingCards[i] == adventurer)
			cardCheck = 1;
	}

	//add adventurer card to kingdom cards if not present
	if(cardCheck == 0)
		kingCards[0] = adventurer;

	//initialize the game
	initializeGame(numPlayers, kingCards, seed, state);

	//randomily generate decks for each player
	for(i = 0; i < state->numPlayers; i++){
		for(j = 0; j < MAX_HAND; j++){
			state->hand[i][j] = randomizeCard(kingCards);
		}
		for(j = 0; j < MAX_DECK; j++){
			state->deck[i][j] = randomizeCard(kingCards);
			state->discard[i][j] = randomizeCard(kingCards);
		}
		//randomily generate deck counts for each player
		//handCount should will typically be small
		//skew randomization to favor a small handCount
		state->handCount[i] = Random() * 22; //keep hand count low
		if(state->handCount[i] == 21)
			state->handCount[i] = Random() * 150;
		state->deckCount[i] = Random() * 150;
		state->discardCount[i] = Random() * 150;
	}

	return;
}

//runs and checks for correctness of adventurer card
int checkAdventurer(struct gameState *post, int seed)
{
	int i, j, card1, card2, treasureCount;
	int test1 = 0;
	int test2 = 0;
	int test3 = 0;
	int test4 = 0;
	struct gameState pre;
	int player = post->whoseTurn;

	//save state before function is called
	memcpy(&pre, post, sizeof(struct gameState));

	//call adventurer function
	adventurerEffect(player, post);

	//test 1
	//check for unnecessary change in game state
	if(pre.numPlayers != post->numPlayers){test1 = 1;}
	if(pre.outpostPlayed != post->outpostPlayed){test1 = 1;}
	if(pre.outpostTurn != post->outpostTurn){test1 = 1;}
	if(pre.whoseTurn != post->whoseTurn){test1 = 1;}
	if(pre.phase != post->phase){test1 = 1;}
	if(pre.numActions != post->numActions){test1 = 1;}
	if(pre.coins != post->coins){test1 = 1;}
	if(pre.numBuys != post->numBuys){test1 = 1;}
	if(pre.playedCardCount != post->playedCardCount){test1 = 1;}

	for(i = 0; i < (treasure_map + 1); i++){
		if(pre.supplyCount[i] != post->supplyCount[i]){test1 = 1;}
		if(pre.embargoTokens[i] != post->embargoTokens[i]){test1 = 1;}
	}

	//test 2
	//check for unnecessary change in other player's states
	for(i = 0; i < pre.numPlayers; i++){
		//ignore current player's state
		if(i != player){
			for(j = 0; j < MAX_HAND; j++){
				if(pre.hand[i][j] != post->hand[i][j]){test2 = 1;}
			}
			for(j = 0; j < MAX_DECK; j++){
				if(pre.deck[i][j] != post->deck[i][j]){test2 = 1;}
				if(pre.discard[i][j] != post->discard[i][j]){test2 = 1;}
			}
			if(pre.handCount[i] != post->handCount[i]){test2 = 1;}
			if(pre.deckCount[i] != post->deckCount[i]){test2 = 1;}
			if(pre.discardCount[i] != post->discardCount[i]){test2 = 1;}
		}
	}

	//count treasure cards in deck and discard pile
	treasureCount = 0;
	for(i = 0; i < pre.deckCount[player]; i++){
		if(pre.deck[player][i] == copper || pre.deck[player][i] == silver || pre.deck[player][i] == gold)
			treasureCount++;
	}
	for(i = 0; i < pre.discardCount[player]; i++){
		if(pre.discard[player][i] == copper || pre.discard[player][i] == silver || pre.discard[player][i] == gold)
			treasureCount++;
	}

	//if at least 2 treasure cards are in the decks then set treasureCount to 2
	if(treasureCount > 2)
		treasureCount = 2;

	//test 3
	//check to make sure 2 treasure cards were added to hand assuming 2 treasure cards are in decks
	//handCount should have increased by 2
	if(pre.handCount[player] != post->handCount[player] - treasureCount){test3 = 1;}

	//check last cards in hand for treasure cards
	card1 = card2 = gold;
	if(treasureCount >= 1)
		card1 = post->hand[player][post->handCount[player] - 1];
	if(treasureCount == 2)
		card2 = post->hand[player][post->handCount[player] - 2];
	if(card1 != copper && card1 != silver && card1 != gold && card2 != copper && card2 != silver && card2 != gold){test3 = 1;}

	//test 4
	//test if discarded cards from deck moved to discard pile
	//the pre deckCount + discardCount should equal post deckCount + discardCount - 2 assuming 2 treasure cards are in decks
	if(pre.deckCount[player] + pre.discardCount[player] != post->deckCount[player] + post->discardCount[player] + treasureCount){test4 = 1;}

	//print error message and return correct value
	#if(NOISY_TEST == 1)
		printf("Test %d: Seed: %d - ", (seed - SEED_START + 1), seed);
	#endif

	if(test1 != 0 || test2 != 0 || test3 != 0 || test4 != 0){
		#if(NOISY_TEST == 1)
			printf("FAILED\n");
			if(test1 != 0){
				printf("  game state changed\n");
			}
			if(test2 != 0){
				printf("  other player's state changed\n");
			}
			if(test3 != 0){
				printf("  treasure cards were not added to player's hand\n");
			}
			if(test4 != 0){
				printf("  discarded cards from deck were not moved to discard pile\n");
			}
		#endif
		return 1;
	}else{
		#if(NOISY_TEST == 1)
			printf("PASSED\n");
		#endif
		return 0;
	}
}

int main()
{
	int seed;
	struct gameState state;
	int passCount = 0;
	int failCount = 0;
	int testCount = 0;

	#if(NOISY_TEST == 1)
		printf("Starting tests for \"Adventurer Card\"...\n\n");
	#endif

	//test 5000 randomized games starting at SEED_START
	for(seed = SEED_START; seed <= 10000; seed++){

		//randomize game
		randomizeGame(&state, seed);

		//check adventurer card
		if(checkAdventurer(&state, seed) == 0){
			passCount++;
		}else{
			failCount++;
		}
		testCount++;
	}

	#if(NOISY_TEST == 1)
		//print summary
		printf("\nTesting complete for \"Adventurer Card\"\n\n");
		printf("Summary:\n");
		printf("Tests run: %d\nTests passed: %d\nTests failed: %d\n\n", testCount, passCount, failCount);
	#endif

	return 0;
}
