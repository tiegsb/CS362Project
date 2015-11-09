/*
Brian Tiegs
CS 362 - Assignment 4
Random Test Treasure Map Card

Test randomizes game state and tests the following conditions:
-change in game state
-change in other player's states
-correct value returned when the number of treasure maps in the player's hand is less than 2
-change in player's state when the number of treasure maps in the player's hand is less than 2
-correct value returned when the number of treasure maps in the player's hand is 2 or greater
-correct number of gold cards added to player's hand when the number of treasure maps in the player's hand is 2 or greater
-change in discard pile when the number of treasure maps in the player's hand is 2 or greater
-treasure map cards discarded from hand when the number of treasure maps in the player's hand is 2 or greater
-gold cards removed from supply count when the number of treasure maps in the player's hand is 2 or greater

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
void randomizeGame(struct gameState *state, int seed, int *handPos)
{
	int i, j;
	int numPlayers;
	int kingCards[NUM_K_CARDS];
	int cardCheck;

	//get random number of players between 2 and 4
	numPlayers = Random() * (MAX_PLAYERS - 1) + 2;

	//randomize kingdom cards
	selectKingdomCards(seed, kingCards);

	//check if treasure map card is in kingdom cards
	cardCheck = 0;
	for(i = 0; i < NUM_K_CARDS; i++){
		if(kingCards[i] == treasure_map)
			cardCheck = 1;
	}

	//add treasure map card to kingdom cards if not present
	if(cardCheck == 0)
		kingCards[0] = treasure_map;

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
		state->handCount[i] = Random() * 21 + 1; //keep hand count low, handCount should be at least 1 to accommodate treasure map card
		if(state->handCount[i] == 20)
			state->handCount[i] = Random() * 150;
		state->deckCount[i] = Random() * 150;
		state->discardCount[i] = Random() * 150;
	}

	//randomly add 1 treasure map card to player's hand
	*handPos = Random() * state->handCount[state->whoseTurn];
	state->hand[state->whoseTurn][*handPos] = treasure_map;

	//randomize supply cards
	for(i = 0; i < treasure_map + 1; i++){
		state->supplyCount[i] = Random() * 20;
	}

	return;
}

//runs and checks for correctness of treasure map card
int checkTreasureMap(struct gameState *post, int seed, int *handPosArg)
{
	int i, j, returnValue, treasureMapCount, postTreasureMapCount, goldCount;
	int test1 = 0;
	int test2 = 0;
	int test3 = 0;
	int test4 = 0;
	int test5 = 0;
	int test6 = 0;
	int test7 = 0;
	int test8 = 0;
	int test9 = 0;
	struct gameState pre;
	int player = post->whoseTurn;
	int handPos = *handPosArg;

	//save state before function is called
	memcpy(&pre, post, sizeof(struct gameState));

	//call treasure map function
	returnValue = cardEffect(treasure_map, 0, 0, 0, post, handPos, 0);

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

	//count treasure map cards in hand
	treasureMapCount = 0;
	for(i = 0; i < pre.handCount[player]; i++){
		if(pre.hand[player][i] == treasure_map)
			treasureMapCount++;
	}

	//check for correct return value and for no changes to player's state when the number of treasure map cards in the player's hand is less than 2
	if(treasureMapCount < 2){
		//test 3
		//check for correct return value
		if(returnValue != -1){test3 = 1;}

		//test 4
		//check no changes made to player's state
		for(i = 0; i < MAX_HAND; i++){
			if(pre.hand[player][i] != post->hand[player][i]){test4 = 1;}
		}
		for(i = 0; i < MAX_DECK; i++){
			if(pre.deck[player][i] != post->deck[player][i]){test4 = 1;}
			if(pre.discard[player][i] != post->discard[player][i]){test4 = 1;}
		}
		if(pre.handCount[player] != post->handCount[player]){test4 = 1;}
		if(pre.deckCount[player] != post->deckCount[player]){test4 = 1;}
		if(pre.discardCount[player] != post->discardCount[player]){test4 = 1;}
	}else{
		//check for correct return value and for correct changes to player's state when the number of treasure map cards in the player's hand is 2 or greater
		//test 5
		//check for correct return value
		if(returnValue != 1){test5 = 1;}

		//test6
		//check the correct amount of gold cards were added to players deck (max 4 depending on supply)
		//get number of gold available in supply
		goldCount = pre.supplyCount[gold];

		//set max golds if necessary
		if(goldCount > 4)
			goldCount = 4;

		//check deck for correct addition of gold cards
		if(pre.deckCount[player] != post->deckCount[player] - goldCount){test6 = 1;}
		for(i = 0; i < goldCount; i++){
			if(post->deck[player][post->deckCount[player] - 1 - i] != gold){test6 = 1;}
		}

		//test 7
		//check no changes made to player's discard pile
		for(i = 0; i < MAX_DECK; i++){
			if(pre.discard[player][i] != post->discard[player][i]){test7 = 1;}
		}
		if(pre.discardCount[player] != post->discardCount[player]){test7 = 1;}

		//test 8
		//check hand for removal of treasure map cards
		if(pre.handCount[player] != post->handCount[player] + 2){test8 = 1;}
		//check hand for 2 less treasure maps
		postTreasureMapCount = 0;
		for(i = 0; i < post->handCount[player]; i++){
			if(post->hand[player][i] == treasure_map)
				postTreasureMapCount++;
		}
		if(treasureMapCount != postTreasureMapCount + 2){test8 = 1;}

		//test 9
		//check for change in supplyCount for gold cards
		if(pre.supplyCount[gold] != post->supplyCount[gold] + goldCount){test9 = 1;}
	}

	//print error message and return correct value
	#if(NOISY_TEST == 1)
		printf("Test %d: Seed: %d - ", (seed - SEED_START + 1), seed);
	#endif

	if(test1 != 0 || test2 != 0 || test3 != 0 || test4 != 0 || test5 != 0 || test6 != 0 || test7 != 0 || test8 != 0 || test9 != 0){
		#if(NOISY_TEST == 1)
			printf("FAILED\n");
			if(test1 != 0){
				printf("  game state changed\n");
			}
			if(test2 != 0){
				printf("  other player's state changed\n");
			}
			if(test3 != 0){
				printf("  returns incorrect value when the number of treasure maps in the player's hand is less than 2\n");
			}
			if(test4 != 0){
				printf("  player's state has changed when the number of treasure maps in the player's hand is less than 2\n");
			}
			if(test5 != 0){
				printf("  returns incorrect value when the number of treasure maps in the player's hand is 2 or greater\n");
			}
			if(test6 != 0){
				printf("  incorrect number of gold cards added to player's hand when the number of treasure maps in the player's hand is 2 or greater\n");
			}
			if(test7 != 0){
				printf("  discard pile changed when the number of treasure maps in the player's hand is 2 or greater\n");
			}
			if(test8 != 0){
				printf("  treasure map cards not discarded from hand when the number of treasure maps in the player's hand is 2 or greater\n");
			}
			if(test9 != 0){
				printf("  gold cards not removed from supply count when the number of treasure maps in the player's hand is 2 or greater\n");
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
	int seed, handPos;
	struct gameState state;
	int passCount = 0;
	int failCount = 0;
	int testCount = 0;

	#if(NOISY_TEST == 1)
		printf("Starting tests for \"Treasure Map Card\"...\n\n");
	#endif

	//test 5000 randomized games starting at SEED_START
	for(seed = SEED_START; seed <= 10000; seed++){

		//randomize game
		randomizeGame(&state, seed, &handPos);

		//check treasure map card
		if(checkTreasureMap(&state, seed, &handPos) == 0){
			passCount++;
		}else{
			failCount++;
		}
		testCount++;
	}

	#if(NOISY_TEST == 1)
		//print summary
		printf("\nTesting complete for \"Treasure Map Card\"\n\n");
		printf("Summary:\n");
		printf("Tests run: %d\nTests passed: %d\nTests failed: %d\n\n", testCount, passCount, failCount);
	#endif

	return 0;
}
