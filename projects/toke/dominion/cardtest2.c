//############################################################
// Filename: cardtest2.c
// Unit Test Objective: Tests the executeAdventurerCard method
//                      in dominion.c. This validates the
//                      behavior for the Adventurer card.
//############################################################

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>

#define DEBUG 0
#define NOISY_TEST 1

void CheckPlayerHasTwoExtraTreasureCards();
void CheckThatTreasureCardsWereTakenInOrderFromDeck();
void CheckThatOtherPlayersWereNotAffectedByAction();
void CheckThatCardsCanBeDrawnFromEmptyDeck();
void CheckThatNoneTreasureCardsAreDiscarded();
void TestAmountOfCoinsInSupplyDidNotChange();
void initializeStartGameDeck(struct gameState *state);
void emptyDeckAndAddToDiscard(struct gameState *state);

int main () {

	printf ("Card Testing: executeAdventurerCard().\n");

	// Player who plays the adventurer card should have two extra treasure cards
	// in their hand.
	CheckPlayerHasTwoExtraTreasureCards();

	// Check that the treasure cards were taken in order from the deck.
	CheckThatTreasureCardsWereTakenInOrderFromDeck();

	// Check that only the player who plays the action card is affected. Check
	// everyone else's deck and hand counts.
	CheckThatOtherPlayersWereNotAffectedByAction();

	// Check that cards can still be drawn from an empty deck, but a full
	// discard pile.
	CheckThatCardsCanBeDrawnFromEmptyDeck();

	// Check that we discard all the cards that were drawn from the deck that
	// were not treasure cards.
	CheckThatNoneTreasureCardsAreDiscarded();

	// Check that the coins in the card supply were not affected
	TestAmountOfCoinsInSupplyDidNotChange();

	return 0;
}

void CheckPlayerHasTwoExtraTreasureCards()
{
	int k[10] = {adventurer, council_room, feast, gardens, mine,
	             remodel, smithy, village, baron, great_hall
	            };

	struct gameState G;
	int player1 = 0;
	memset(&G, 23, sizeof(struct gameState)); // Clear the game state
	initializeGame(2, k, 1, &G);

	printf("Testing...Player 1 has 2 more treasure cards in their hand after adventurer is played.\n");
	int preHandCount = G.handCount[player1];
	executeAdventurerCard(0, &G, player1);
	int postHandCount = G.handCount[player1];
	if (postHandCount != preHandCount + 2)
	{
		printf("Test Failed: Expected handcount was %d. Actual handcount was %d.\n", preHandCount + 2, postHandCount);
	}
	else
	{
		printf("Test Passed: Expected handcount was %d. Actual handcount was %d.\n", preHandCount + 2, postHandCount);
	}
}

void CheckThatTreasureCardsWereTakenInOrderFromDeck()
{
	int k[10] = {adventurer, council_room, feast, gardens, mine,
	             remodel, smithy, village, baron, great_hall
	            };

	struct gameState G;
	int player1 = 0;
	memset(&G, 23, sizeof(struct gameState)); // Clear the game state
	initializeGame(2, k, 1, &G);
	initializeStartGameDeck(&G);

	printf("Testing...Treasure cards were taken in order from the deck.\n");
	int preDeckCount = G.deckCount[player1];
	int preHandCount = G.handCount[player1];
	int firstTreasureCardToBeRemovedFromDeck = G.deck[player1][preDeckCount - 1];
	int secondTreasureCardToBeRemovedFromDeck = G.deck[player1][preDeckCount - 2];
	executeAdventurerCard(0, &G, player1);

	int postHandCount = G.handCount[player1];
	int postDeckCount = G.deckCount[player1];
	int firstTreasureCardToBeAddedToHand = G.hand[player1][preHandCount];
	int secondTreasureCardToBeAddedToHand = G.hand[player1][preHandCount + 1];

	// Check hand count
	if (postHandCount != preHandCount + 2)
	{
		printf("Test Failed: Expected handcount was %d. Actual handcount was %d.\n", preHandCount + 2, postHandCount);
	}
	else
	{
		printf("Test Passed: Expected handcount was %d. Actual handcount was %d.\n", preHandCount + 2, postHandCount);
	}

	// Check deck count
	if (postDeckCount != preDeckCount - 2)
	{
		printf("Test Failed: Expected deckCount was %d. Actual deckCount was %d.\n", preDeckCount - 2, postDeckCount);
	}
	else
	{
		printf("Test Passed: Expected deckCount was %d. Actual deckCount was %d.\n", preDeckCount - 2, postDeckCount);
	}

	// Check that cards were added in order
	if ((firstTreasureCardToBeRemovedFromDeck != firstTreasureCardToBeAddedToHand)
	        || (secondTreasureCardToBeRemovedFromDeck != secondTreasureCardToBeAddedToHand))
	{
		printf("Test Failed: Treasures were not added in order from deck to hand.\n");
	}
	else
	{
		printf("Test Passed: Treasures were added in order from deck to hand.\n");
	}

	// Check that the cards added to the hand are copper cards. At this point, a players
	// deck should only contain copper cards
	if ((firstTreasureCardToBeAddedToHand != copper)
	        || (secondTreasureCardToBeAddedToHand != copper))
	{
		printf("Test Failed: Card(s) added to the hand were not treasure cards.\n");
	}
	else
	{
		printf("Test Passed: Card(s) added to the hand were treasure cards.\n");
	}
}

void CheckThatOtherPlayersWereNotAffectedByAction()
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
	executeAdventurerCard(0, &G, player1);

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

void CheckThatCardsCanBeDrawnFromEmptyDeck()
{
	int k[10] = {adventurer, council_room, feast, gardens, mine,
	             remodel, smithy, village, baron, great_hall
	            };

	struct gameState G;
	int player1 = 0;
	memset(&G, 23, sizeof(struct gameState)); // Clear the game state
	initializeGame(2, k, 1, &G);
	initializeStartGameDeck(&G);
	emptyDeckAndAddToDiscard(&G);

	printf("Testing...Cards can be drawn from an empty deck.\n");
	int preHandCount = G.handCount[player1];
	executeAdventurerCard(0, &G, player1);

	int postDeckCount = G.deckCount[player1];
	int postDiscardCount = G.discardCount[player1];
	int firstTreasureCardToBeAddedToHand = G.hand[player1][preHandCount];
	int secondTreasureCardToBeAddedToHand = G.hand[player1][preHandCount + 1];

	// Check that discard pile is empty
	if (postDiscardCount < 0)
	{
		printf("Test Failed: Discard pile is not empty.\n");
	}
	else
	{
		printf("Test Passed: Discard pile is empty.\n");
	}

	// Check that deck has cards in it
	if (postDeckCount <= 0)
	{
		printf("Test Failed: Deck was empty.\n");
	}
	else
	{
		printf("Test Passed: Deck was not empty.\n");
	}

	// Check that two treasures were added to the player's hand
	if ((firstTreasureCardToBeAddedToHand != copper)
	        || (secondTreasureCardToBeAddedToHand != copper))
	{
		printf("Test Failed: Card(s) added to hand were not treasures.\n");
	}
	else
	{
		printf("Test Passed: Card(s) added to hand were treasures.\n");
	}
}

void CheckThatNoneTreasureCardsAreDiscarded()
{
	int k[10] = {adventurer, council_room, feast, gardens, mine,
	             remodel, smithy, village, baron, great_hall
	            };

	struct gameState G;
	int player1 = 0;
	memset(&G, 23, sizeof(struct gameState)); // Clear the game state
	initializeGame(2, k, 1, &G);

	// Set the top of the deck to have 2 estate cards. The rest of
	// the deck will contain coppers.
	int j;
	G.deckCount[player1] = 0;
	for (j = 0; j < 8; j++)
	{
		G.deck[player1][j] = copper;
		G.deckCount[player1]++;
	}
	for (j = 8; j < 10; j++)
	{
		G.deck[player1][j] = estate;
		G.deckCount[player1]++;
	}

	printf("Testing...Non-treasure cards are discarded.\n");
	int preDiscardCount = G.discardCount[player1];
	executeAdventurerCard(0, &G, player1);
	int postDiscardCount = G.discardCount[player1];
	int firstDiscard = G.discard[player1][0];
	int secondDiscard = G.discard[player1][1];

	// Check that discard pile is not empty
	if (postDiscardCount != preDiscardCount + 2)
	{
		printf("Test Failed: Discard pile is empty.\n");
	}
	else
	{
		printf("Test Passed: Discard pile is not empty.\n");
	}

	// Check that two estates were added to the discard pile
	if ((firstDiscard != estate)
	        || (secondDiscard != estate))
	{
		printf("Test Failed: Incorrect cards were discarded.\n");
	}
	else
	{
		printf("Test Passed: Correct cards were discarded.\n");
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
	executeAdventurerCard(0, &G, player1);
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

// Empties the deck for player 1
void emptyDeckAndAddToDiscard(struct gameState *state)
{
	int j, i;

	i = 0;
	for (j = state->deckCount[0] - 1; j >= 0; j--)
	{
		state->discard[0][i] = state->deck[0][j];
		state->discardCount[0]++;
		// printf("adding %d to the discard pile\n", state->discard[0][i]);
		i++;
	}

	state->deckCount[0] = 0; // Empty the deck
}