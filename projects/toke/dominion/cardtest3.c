//############################################################
// Filename: cardtest3.c
// Unit Test Objective: Tests the executeVillageCard method
//                      in dominion.c. This validates the
//                      behavior for the Village card.
//############################################################

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>

#define DEBUG 0
#define NOISY_TEST 1

void CheckPlayerHasOneCardAddedToHand();
void CheckPlayerHasTwoActionsAdded();
void CheckVillageCardWasPutIntoPlayedPile();
void CheckOtherPlayersNotAffected();
void TestAmountOfCoinsInSupplyDidNotChange();
void initializeStartGameDeck(struct gameState *state);
void replaceLastCardInHandWithVillage(struct gameState *state);

int main () {

	printf ("Card Testing: executeVillageCard().\n");

	// Player who plays the Village card should have 1 card added to their hand from
	// the their deck.
	CheckPlayerHasOneCardAddedToHand();

	// Player who plays the Village card should have 2 actions added.
	CheckPlayerHasTwoActionsAdded();

	// Player should have their village card added to the played pile after using it
	CheckVillageCardWasPutIntoPlayedPile();

	// Check that other player's deck and hands were not affected.
	CheckOtherPlayersNotAffected();

	// Check that the coin supply did not change.
	TestAmountOfCoinsInSupplyDidNotChange();

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

	printf("Testing...Player 1 has 1 card added to their hand after village is played.\n");
	int preHandCount = G.handCount[player1];
	int preDeckCount = G.deckCount[player1];
	int cardRemovedFromDeck = G.deck[player1][G.deckCount[player1] - 1];
	replaceLastCardInHandWithVillage(&G);
	int handPos = 4;
	executeVillageCard(&G, player1, handPos);

	int postDeckCount = G.deckCount[player1];
	int postHandCount = G.handCount[player1];

	// Check hand count
	if (postHandCount != preHandCount)
	{
		printf("Test Failed: Incorrect number of cards were added.\n");
	}
	else
	{
		printf("Test Passed: Correct number of cards were added.\n");
	}

	// Check deck count
	if (postDeckCount != preDeckCount - 1)
	{
		printf("Test Failed: Incorrect number of cards were removed from deck.\n");
	}
	else
	{
		printf("Test Passed: Correct number of cards were removed from deck.\n");
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

void CheckPlayerHasTwoActionsAdded()
{
	int k[10] = {adventurer, council_room, feast, gardens, mine,
	             remodel, smithy, village, baron, great_hall
	            };

	struct gameState G;
	int player1 = 0;
	memset(&G, 23, sizeof(struct gameState)); // Clear the game state
	initializeGame(2, k, 1, &G);

	printf("Testing...Player 1 has two actions added.\n");
	replaceLastCardInHandWithVillage(&G);
	int handPos = 4;
	int preActionNumber = G.numActions;
	executeVillageCard(&G, player1, handPos);

	int postActionNumber = G.numActions;

	// Check number of actions
	if (postActionNumber != preActionNumber + 2)
	{
		printf("Test Failed: Expected action count %d. Actual action count %d.\n", preActionNumber + 2, postActionNumber);
	}
	else
	{
		printf("Test Passed: Expected action count %d. Actual action count %d.\n", preActionNumber + 2, postActionNumber);
	}
}

void CheckVillageCardWasPutIntoPlayedPile()
{
	int k[10] = {adventurer, council_room, feast, gardens, mine,
	             remodel, smithy, village, baron, great_hall
	            };

	struct gameState G;
	int player1 = 0;
	memset(&G, 23, sizeof(struct gameState)); // Clear the game state
	initializeGame(2, k, 1, &G);
	initializeStartGameDeck(&G);

	printf("Testing...Player 1 has their village card put in the played pile.\n");
	replaceLastCardInHandWithVillage(&G);
	int handPos = 4;
	int preDiscardCount = G.discardCount[player1];
	int prePlayedCardCount = G.playedCardCount;
	executeVillageCard(&G, player1, handPos);

	int postDiscardCount = G.discardCount[player1];
	int postPlayedCardCount = G.playedCardCount;

	// Check that card added to hand was not village
	if (G.hand[player1][G.handCount[player1] - 1] == village)
	{
		printf("Test Failed: Village was not removed from hand correctly.\n");
	}
	else
	{
		printf("Test Passed: Village was removed from hand correctly.\n");
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

	// Check that village was added to the played pile
	int topOfPlayedPileCard = G.playedCards[G.playedCardCount - 1];
	if ((topOfPlayedPileCard != village)
	        || (postPlayedCardCount != prePlayedCardCount + 1))
	{
		printf("Test Failed: Village added to the played pile incorrectly.\n");
	}
	else
	{
		printf("Test Passed: Village added to the played pile correctly.\n");
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
	replaceLastCardInHandWithVillage(&G);
	int handPos = 4;
	executeVillageCard(&G, player1, handPos);

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
	replaceLastCardInHandWithVillage(&G);
	int handPos = 4;
	executeVillageCard(&G, player1, handPos);
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

void replaceLastCardInHandWithVillage(struct gameState *state)
{
	state->hand[0][4] = village;
}