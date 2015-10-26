//############################################################
// Filename: cardtest4.c
// Unit Test Objective: Tests the executeGreatHallCard method
//                      in dominion.c. This validates the
//                      behavior for the Great Hall card.
//############################################################

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>

#define DEBUG 0
#define NOISY_TEST 1

void CheckPlayerHasOneCardAddedToHand();
void CheckPlayerHasOneActionAdded();
void TestAmountOfCoinsInSupplyDidNotChange();
void CheckGreatHallCardWasPutIntoPlayedPile();
void CheckOtherPlayersNotAffected(); 
void TestAmountOfGreatHallsInSupplyDidNotChange();
void initializeStartGameDeck(struct gameState *state);
void replaceLastCardInHandWithGreatHall(struct gameState *state);

int main () {
	printf ("Card Testing: executeGreatHallCard().\n");

	// Player who plays the Great Hall card should have 1 card added to their hand from
	// the their deck.
	CheckPlayerHasOneCardAddedToHand();

	// Player who plays the Great Hall card should have 1 action added.
	CheckPlayerHasOneActionAdded();

	// Player should have their Great Hall card added to the played pile after using it
	CheckGreatHallCardWasPutIntoPlayedPile();

	// Check that other player's deck and hands were not affected.
	CheckOtherPlayersNotAffected();

	// Check that the coin supply did not change.
	TestAmountOfCoinsInSupplyDidNotChange();

	// Check the amounts of great halls in the supply did not change
	TestAmountOfGreatHallsInSupplyDidNotChange();

	return 0;
}

void CheckPlayerHasOneCardAddedToHand()
{
	int k[10] = {adventurer, council_room, feast, gardens, mine,
	             remodel, smithy, village, baron, great_hall
	            };

	struct gameState G;
	int player1 = 0;
	memset(&G, 23, sizeof(struct gameState)); // Clear the game state
	initializeGame(2, k, 1, &G);
	initializeStartGameDeck(&G);

	printf("Testing...Player 1 has 1 card added to their hand after Great Hall is played.\n");
	int preHandCount = G.handCount[player1];
	int preDeckCount = G.deckCount[player1];
	int cardRemovedFromDeck = G.deck[player1][G.deckCount[player1] - 1];
	replaceLastCardInHandWithGreatHall(&G);
	int handPos = 4;
	executeGreatHallCard(&G, player1, handPos);

	int postDeckCount = G.deckCount[player1];
	int postHandCount = G.handCount[player1];

	// Check hand count
	if (postHandCount != preHandCount)
	{
		printf("Test Failed: Expected hand count: %d. Actual hand count %d.\n", preHandCount, postHandCount);
	}
	else
	{
		printf("Test Passed: Expected hand count: %d. Actual hand count %d.\n", preHandCount, postHandCount);
	}

	// Check deck count
	if (postDeckCount != preDeckCount - 1)
	{
		printf("Test Failed: Expected deck count: %d. Actual deck count %d.\n", preDeckCount - 1, postDeckCount);
	}
	else
	{
		printf("Test Passed: Expected deck count: %d. Actual deck count %d.\n", preDeckCount - 1, postDeckCount);
	}

	// Check card removed from deck was added to hand
	if (cardRemovedFromDeck != G.hand[player1][G.handCount[player1] - 1])
	{
		printf("Test Failed: Card was not taken from the top of the deck.\n");
	}
	else
	{
		printf("Test Passed: Card was taken from the top of the deck.\n");
	}
}

void CheckPlayerHasOneActionAdded()
{
	int k[10] = {adventurer, council_room, feast, gardens, mine,
	             remodel, smithy, village, baron, great_hall
	            };

	struct gameState G;
	int player1 = 0;
	memset(&G, 23, sizeof(struct gameState)); // Clear the game state
	initializeGame(2, k, 1, &G);

	printf("Testing...Player 1 has one action added.\n");
	int preActionNumber = G.numActions;
	replaceLastCardInHandWithGreatHall(&G);
	int handPos = 4;
	executeGreatHallCard(&G, player1, handPos);

	int postActionNumber = G.numActions;

	// Check number of actions
	if (postActionNumber != preActionNumber + 1)
	{
		printf("Test Failed: Expected action count %d. Actual action count %d.\n", preActionNumber + 1, postActionNumber);
	}
	else
	{
		printf("Test Passed: Expected action count %d. Actual action count %d.\n", preActionNumber + 1, postActionNumber);
	}
}

void CheckGreatHallCardWasPutIntoPlayedPile()
{
	int k[10] = {adventurer, council_room, feast, gardens, mine,
	             remodel, smithy, village, baron, great_hall
	            };

	struct gameState G;
	int player1 = 0;
	memset(&G, 23, sizeof(struct gameState)); // Clear the game state
	initializeGame(2, k, 1, &G);
	initializeStartGameDeck(&G);

	printf("Testing...Player 1 has their Great Hall card put in the played pile.\n");
	replaceLastCardInHandWithGreatHall(&G);
	int handPos = 4;
	int preDiscardCount = G.discardCount[player1];
	int prePlayedCardCount = G.playedCardCount;
	executeGreatHallCard(&G, player1, handPos);

	int postDiscardCount = G.discardCount[player1];
	int postPlayedCardCount = G.playedCardCount;

	// Check that card added to hand was not Great Hall 
	if (G.hand[player1][G.handCount[player1] - 1] == great_hall)
	{
		printf("Test Failed: Great Hall was not removed from hand correctly.\n");
	}
	else
	{
		printf("Test Passed: Great Hall was removed from hand correctly.\n");
	}

	// Check that the discard pile count stayed the same
	if (postDiscardCount != preDiscardCount)
	{
		printf("Test Failed: Discard count is incorrect.\n");
	}
	else
	{
		printf("Test Passed: Discard count is correct.\n");
	}

	// Check that Great Hall  was added to the played pile
	int topOfPlayedPileCard = G.playedCards[G.playedCardCount - 1];
	if ((topOfPlayedPileCard != great_hall)
	        || (postPlayedCardCount != prePlayedCardCount + 1))
	{
		printf("Test Failed: Great Hall added to the played pile incorrectly.\n");
	}
	else
	{
		printf("Test Passed: Great Hall added to the played pile correctly.\n");
	}
}

void CheckOtherPlayersNotAffected()
{
	int k[10] = {adventurer, council_room, feast, gardens, mine,
	             remodel, smithy, village, baron, great_hall
	            };

	struct gameState G;
	int player1 = 0;
	int player2 = 1;
	memset(&G, 23, sizeof(struct gameState)); // Clear the game state
	initializeGame(2, k, 1, &G);
	initializeStartGameDeck(&G);

	printf("Testing...Action did not affect another player's handCount or deckCount.\n");
	int preDeckCount = G.deckCount[player2];
	int preHandCount = G.handCount[player2];
	replaceLastCardInHandWithGreatHall(&G);
	int handPos = 4;
	executeGreatHallCard(&G, player1, handPos);

	int postHandCount = G.handCount[player2];
	int postDeckCount = G.deckCount[player2];

	// Check hand count
	if (postHandCount != preHandCount)
	{
		printf("Test Failed: Other player's handCount was affected.\n");
	}
	else
	{
		printf("Test Passed: Other player's handCount was not affected.\n");
	}

	// Check deck count
	if (postDeckCount != preDeckCount)
	{
		printf("Test Failed: Other player's deckCount was affected.\n");
	}
	else
	{
		printf("Test Passed: Other player's deckCount was not affected.\n");
	}
}

void TestAmountOfCoinsInSupplyDidNotChange()
{
	int k[10] = {adventurer, council_room, feast, gardens, mine,
	             remodel, smithy, village, baron, great_hall
	            };

	struct gameState G;
	int player1 = 0;

	printf("Testing...The amount of coins in the coin supply did not change.\n");
	memset(&G, 23, sizeof(struct gameState)); // Clear the game state
	initializeGame(2, k, 1, &G);

	int preCopper = G.supplyCount[copper];
	int preSilver = G.supplyCount[silver];
	int preGold = G.supplyCount[gold];
	replaceLastCardInHandWithGreatHall(&G);
	int handPos = 4;
	executeGreatHallCard(&G, player1, handPos);
	int postCopper = G.supplyCount[copper];
	int postSilver = G.supplyCount[silver];
	int postGold = G.supplyCount[gold];
	if ((postCopper != preCopper)
	        || (postSilver != preSilver)
	        || (postGold != preGold))
	{
		printf("Test Failed: The amount of coins in the supply changed.\n");
	}
	else
	{
		printf("Test Passed: The amount of coins in the supply is unchanged.\n");
	}
}

void TestAmountOfGreatHallsInSupplyDidNotChange()
{
	int k[10] = {adventurer, council_room, feast, gardens, mine,
	             remodel, smithy, village, baron, great_hall
	            };

	struct gameState G;
	int player1 = 0;

	printf("Testing...The amount of Great Halls in the coin supply did not change.\n");
	memset(&G, 23, sizeof(struct gameState)); // Clear the game state
	initializeGame(2, k, 1, &G);

	int preGreatHall = G.supplyCount[great_hall];
	replaceLastCardInHandWithGreatHall(&G);
	int handPos = 4;
	executeGreatHallCard(&G, player1, handPos);
	int postGreatHall = G.supplyCount[great_hall];
	if (postGreatHall != preGreatHall)
	{
		printf("Test Failed: The amount of Great Halls in the supply changed.\n");
	}
	else
	{
		printf("Test Passed: The amount of Great Halls in the supply is unchanged.\n");
	}
}

void initializeStartGameDeck(struct gameState *state)
{
	int i, j;
	for (i = 0; i < 2; ++i)
	{
		state->deckCount[i] = 0;
		for (j = 0; j < 3; j++)
		{
			state->deck[i][j] = estate;
			state->deckCount[i]++;
		}
		for (j = 3; j < 10; j++)
		{
			state->deck[i][j] = copper;
			state->deckCount[i]++;
		}
	}
}

void replaceLastCardInHandWithGreatHall(struct gameState *state)
{
	state->hand[0][4] = great_hall;
}