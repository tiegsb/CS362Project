/*
*	CS362 - Assignment 3 - cardtest2.c
*	Card Test #2: This program runs the following 6 tests 
*		to ensure the Village card implementation is correct:
*			1. Player gets 2 actions
*			2. Player gets 1 card
*			3. Village doesn't affect other player's deck
*			4. Village doesn't affect other player's hand
*			5. Village doesn't grant additional actions
*			6. Village doesn't grant additional buys
*			7. Village gets discarded


Village Card: Whenever a player has more than 2 cards in their deck count,
the village card will get discarded. This ensures that a majority of the time
the village card functions correctly. On the occasion that a player has less
than 2 cards in their deck count, they will draw an additional card.
* 
*	Author: Carol D. Toro
*	Date: 10/20/2015
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <time.h>


// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1
int main()
{
	/*initialize variables needed*/
	int	i;
	int k[10] = { adventurer, council_room, feast, gardens, mine,
		remodel, smithy, village, baron, great_hall };
	int gameSeed;
	int numPlayer = 2;
	struct gameState Game;
	int currentActions, expectedActions, currentBuys, expectedBuys, testActionsBefore, testActionsAfter;
	int result, currentNumCards, numCardsAfter, cardType, currentCards[10], cardsAfter[10];
	const char* cardNames[] = { "curse", "estate", "duchy", "province", "copper", "silver", "gold", "adventurer", "council_room", "feast", "gardens", "mine", "remodel", "Adventurer", "village", "baron", "great_hall", "minion", "steward", "tribute", "ambassador", "cutpurse", "embargo", "outpost", "salvager", "sea_hag", "treasure_map" };
	
	/*Keep track of P0s deck & hand before & after*/
	int p_0_deckBeforeVillage[MAX_DECK];
	//int p_0_deckAfterAdventurer[MAX_DECK];
	//int p_0_handBeforeAdventurer[MAX_HAND];
	int p_0_handAfterVillage[MAX_HAND];

	/*Keep track of P1s deck before & after*/
	int p_1_deckBeforeVillage[MAX_DECK];
	int p_1_deckAfterVillage[MAX_DECK];
	int p_1_handBeforeVillage[MAX_HAND];
	int p_1_handAfterVillage[MAX_HAND];

	/*initialize array of silver filled hands, starting with Adventurer*/
	int silverHand[MAX_HAND];
	for (i = 0; i < MAX_HAND; i++)
	{
		if (i == 0)
			silverHand[i] = village;
		else
			silverHand[i] = silver;
	}

	/*initialize array of copper filled hands*/
	int copperHand[MAX_HAND];
	for (i = 0; i < MAX_HAND; i++)
	{
		if (i == 0)
			copperHand[i] = village;
		else
			copperHand[i] = copper;
	}


	/*Starting Test #1*/
#if (NOISY_TEST==1)
	printf("Starting cardtest1.c which checks villageCard() \n");
	printf("\n Starting Test #1 - player receives 2 additional actions \n");
#endif
	/*initialize gameSeed*/
	gameSeed = rand() % 1000 + 1;

	/*clear the game state*/
	memset(&Game, 23, sizeof(struct gameState));

	/*initialize game*/
	initializeGame(numPlayer, k, gameSeed, &Game);

	/*load player 0 hands with silverHand array */
	memcpy(Game.hand[0], silverHand, sizeof(int) * MAX_HAND);

	updateCoins(0, &Game, 0);

	currentNumCards = (numHandCards(&Game));

	cardType = handCard(0, &Game);

	testActionsBefore = Game.numActions;

	/*play the Village card*/
	result = playCard(0, 1, 2, 3, &Game);

	expectedActions = 2;
	currentActions = Game.numActions;

#if (NOISY_TEST==1)
	if (expectedActions == currentActions)
	{
		printf("\t Current actions = %d, Expected actions = %d\n", currentActions, expectedActions);
		printf("Test #1 passed. \n");
	}
	else
	{
		printf("\t Current actions = %d, Expected actions = %d\n", currentActions, expectedActions);
		printf("Test #1 FAILED! Player did not receive 2 actions from Village. \n");
	}

#endif


#if (NOISY_TEST==1)
	printf("\n Starting Test #1 - player receives 1 card after playing Great Hall \n");
#endif
	/*initialize gameSeed*/
	gameSeed = rand() % 1000 + 1;

	/*clear the game state*/
	memset(&Game, 23, sizeof(struct gameState));

	/*initialize game*/
	initializeGame(numPlayer, k, gameSeed, &Game);

	/*load player 0 hands with silverHand array & player 1 with copper*/
	memcpy(Game.hand[0], silverHand, sizeof(int) * MAX_HAND);
	memcpy(Game.hand[1], copperHand, sizeof(int) * MAX_HAND);

	updateCoins(0, &Game, 0);

	currentNumCards = (numHandCards(&Game));


	for (i = 0; i < currentNumCards; i++)
	{
		currentCards[i] = handCard(i, &Game);
		//printf(" %s ", cardNames[currentCards[i]]);
	}

	cardType = handCard(0, &Game);

	/*play the smithy card*/
	result = playCard(0, 1, 2, 3, &Game);

	numCardsAfter = (numHandCards(&Game));


	for (i = 0; i < numCardsAfter; i++)
	{
		cardsAfter[i] = handCard(i, &Game);
		//printf(" %s ", cardNames[cardsAfter[i]]);
	}

#if (NOISY_TEST==1)
	if ((numCardsAfter) == 5)
	{
		printf("\t Current cards = %d, Expected cards = %d\n", numCardsAfter, 5);
		printf(" Test #2 passed. Player received 1 card. \n");
	}
	else
	{
		printf("\t \nGame state = %d, Expected state = %d\n", numCardsAfter, 5);
		printf(" Test #2 FAILED! Player did not receive 1 card. \n");
	}
#endif










	numCardsAfter = (numHandCards(&Game));

	/*Copy the hand after the Adventure was played*/
	for (i = 0; i < numCardsAfter; i++)
	{
		p_0_handAfterVillage[i] = Game.hand[0][i];
	}


#if (NOISY_TEST==1)
	if (p_0_handAfterVillage[currentNumCards] == p_0_deckBeforeVillage[currentNumCards - 1] && p_0_handAfterVillage[currentNumCards + 1] == p_0_deckBeforeVillage[currentNumCards - 2])
	{
		printf("\t Current card = %d, Expected card = %d\n", p_0_handAfterVillage[currentNumCards], p_0_deckBeforeVillage[currentNumCards - 1]);
		printf("\t Current card = %d, Expected card = %d\n", p_0_handAfterVillage[currentNumCards+1], p_0_deckBeforeVillage[currentNumCards - 2]);
		printf(" Test #1 passed. Player received the expected cards\n");
	}
	else
	{
		printf("\t Current card = %d, Expected card = %d\n", p_0_handAfterVillage[currentNumCards], p_0_deckBeforeVillage[currentNumCards - 1]);
		printf("\t Current card = %d, Expected card = %d\n", p_0_handAfterVillage[currentNumCards + 1], p_0_deckBeforeVillage[currentNumCards - 2]);
		printf(" Test #1 FAILED! Player did not receive expected cards. \n");
	}

#endif



	/*Starting Test #2*/
#if (NOISY_TEST==1)
	printf("\n Starting Test #2 - player receives treasures from own deck \n");
#endif
	/*initialize gameSeed*/
	gameSeed = rand() % 1000 + 1;

	/*clear the game state*/
	memset(&Game, 23, sizeof(struct gameState));

	/*initialize game*/
	initializeGame(numPlayer, k, gameSeed, &Game);

	/*load player 0 hands with silverHand array & player 1 with copper*/
	memcpy(Game.hand[0], silverHand, sizeof(int) * MAX_HAND);
	memcpy(Game.hand[1], copperHand, sizeof(int) * MAX_HAND);


	/*Save player 0's deck*/
	for (i = 0; i < 10; i++)
	{
		p_0_deckBeforeVillage[i] = Game.deck[0][i];
	}

	updateCoins(0, &Game, 0);

	currentNumCards = (numHandCards(&Game));

	cardType = handCard(0, &Game);

	/*play the adventurer card*/
	result = playCard(0, 1, 2, 3, &Game);

	numCardsAfter = (numHandCards(&Game));

	/*Copy the hand after the Adventure was played*/
	for (i = 0; i < numCardsAfter+2; i++)
	{
		p_0_handAfterVillage[i] = Game.hand[0][i];
	}


#if (NOISY_TEST==1)
	if (p_0_handAfterVillage[currentNumCards] == p_0_deckBeforeVillage[currentNumCards - 3] && p_0_handAfterVillage[currentNumCards + 1] == p_0_deckBeforeVillage[currentNumCards - 4])
	{
		printf("\t Current card = %s, Expected card = %s\n", cardNames[p_0_handAfterVillage[currentNumCards]], cardNames[p_0_deckBeforeVillage[currentNumCards - 3]]);
		printf("\t Current card = %s, Expected card = %s\n", cardNames[p_0_handAfterVillage[currentNumCards + 1]], cardNames[p_0_deckBeforeVillage[currentNumCards - 4]]);
		printf(" Test #2 passed. Player received treasure cards from deck \n");
	}
	else
	{
		printf("\t Current card = %s, Expected card = %s\n", cardNames[p_0_handAfterVillage[currentNumCards]], cardNames[p_0_deckBeforeVillage[currentNumCards - 3]]);
		printf("\t Current card = %s, Expected card = %s\n", cardNames[p_0_handAfterVillage[currentNumCards + 1]], cardNames[p_0_deckBeforeVillage[currentNumCards - 4]]);
		printf(" Test #2 FAILED! Player did not receive treasure cards from own deck. \n");
	}

#endif

	/*Starting Test #3*/
#if (NOISY_TEST==1)
	printf("\n Starting Test #3 - Adventurer doesn't affect other player's deck \n");
#endif

	/*initialize gameSeed*/
	gameSeed = rand() % 1000 + 1;

	/*clear the game state*/
	memset(&Game, 23, sizeof(struct gameState));

	/*initialize game*/
	initializeGame(numPlayer, k, gameSeed, &Game);

	/*load player 0 hands with silverHand array & player's 1 deck with copper*/
	memcpy(Game.hand[0], silverHand, sizeof(int) * MAX_HAND);
	memcpy(Game.deck[1], copperHand, sizeof(int) * MAX_HAND);


	/*save player 1's deck*/
	for (i = 0; i < 10; i++)
	{
		p_1_deckBeforeVillage[i] = Game.deck[1][i];
	}

	/* P0 plays the Adventurer card*/
	result = playCard(0, 1, 2, 3, &Game);

	numCardsAfter = (numHandCards(&Game));

	/*Copy p1's deck after the Adventurer was played*/
	for (i = 0; i < 10; i++)
	{
		p_1_deckAfterVillage[i] = Game.deck[1][i];
	}

#if (NOISY_TEST==1)
	if (memcmp(p_1_deckBeforeVillage, p_1_deckAfterVillage, 10) == 0)
	{
		printf("Test #3 passed and other player's deck was not affected! \n");
	}
	else
	{
		printf("Test #3 FAILED! Other player's deck was affected by Adventurer! \n");
	}
#endif

	/*Starting Test #4*/
#if (NOISY_TEST==1)
	printf("\n Starting Test #4 - adventurer doesn't affect other player's hand \n");
#endif

	/*initialize gameSeed*/
	gameSeed = rand() % 1000 + 1;

	/*clear the game state*/
	memset(&Game, 23, sizeof(struct gameState));

	/*initialize game*/
	initializeGame(numPlayer, k, gameSeed, &Game);

	/*load player 0 hands with silverHand array & player's 1 deck with copper*/
	memcpy(Game.hand[0], silverHand, sizeof(int) * MAX_HAND);
	memcpy(Game.deck[1], copperHand, sizeof(int) * MAX_HAND);

	/*save player 1's hand*/
	for (i = 0; i < 10; i++)
	{
		p_1_handBeforeVillage[i] = Game.hand[1][i];
	}

	/*P0 plays the Adventurer card*/
	result = playCard(0, 1, 2, 3, &Game);

	numCardsAfter = (numHandCards(&Game));

	/*Copy p1's hand after the Adventurer was played*/
	for (i = 0; i < 10; i++)
	{
		p_1_handAfterVillage[i] = Game.hand[1][i];
	}

#if (NOISY_TEST==1)
	if (memcmp(p_1_handBeforeVillage, p_1_handAfterVillage, 10) == 0)
	{
		printf("Test #4 passed and other player's hand was not affected! \n");
	}
	else
	{
		printf("Test #4 FAILED! Other player's hand was affected by Adventurer! \n");
	}
#endif

	/*Starting Test #5*/
#if (NOISY_TEST==1)
	printf("\n Starting Test #5 - ensure player doesn't receive additional actions \n");
#endif
	/*initialize gameSeed*/
	gameSeed = rand() % 1000 + 1;

	/*clear the game state*/
	memset(&Game, 23, sizeof(struct gameState));

	/*initialize game*/
	initializeGame(numPlayer, k, gameSeed, &Game);

	/*load player 0 hands with silverHand array & player 1 with copper*/
	memcpy(Game.hand[0], silverHand, sizeof(int) * MAX_HAND);
	memcpy(Game.hand[1], copperHand, sizeof(int) * MAX_HAND);

	/*load player's deck with gold*/
	memcpy(Game.deck[0], silverHand, sizeof(int) * MAX_DECK);

	updateCoins(0, &Game, 0);

	currentNumCards = (numHandCards(&Game));

	cardType = handCard(0, &Game);

	/*play the Adventurer card*/
	result = playCard(0, 1, 2, 3, &Game);

	expectedActions = 0;
	currentActions = Game.numActions;

#if (NOISY_TEST==1)
	if (expectedActions == currentActions)
	{
		printf("\t Current actions = %d, Expected actions = %d\n", currentActions, expectedActions);
		printf("Test #5 passed. \n");
	}
	else
	{
		printf("\t Current actions = %d, Expected actions = %d\n", currentActions, expectedActions);
		printf("Test #5 FAILED! Player had additional actions. \n");
	}

#endif

	/*Starting Test #7*/
#if (NOISY_TEST==1)
	printf("\n Starting Test #6 - ensure player doesn't receive additional buys \n");
#endif
	/*initialize gameSeed*/
	gameSeed = rand() % 1000 + 1;

	/*clear the game state*/
	memset(&Game, 23, sizeof(struct gameState));

	/*initialize game*/
	initializeGame(numPlayer, k, gameSeed, &Game);

	/*load player 0 hands with silverHand array & player 1 with copper*/
	memcpy(Game.hand[0], silverHand, sizeof(int) * MAX_HAND);
	memcpy(Game.hand[1], copperHand, sizeof(int) * MAX_HAND);

	/*load player's deck with gold*/
	memcpy(Game.deck[0], silverHand, sizeof(int) * MAX_DECK);

	updateCoins(0, &Game, 0);

	currentNumCards = (numHandCards(&Game));

	cardType = handCard(0, &Game);

	/*play the Adventurer card*/
	result = playCard(0, 1, 2, 3, &Game);

	expectedBuys = 1;
	currentBuys = Game.numBuys;

#if (NOISY_TEST==1)
	if (expectedBuys == currentBuys)
	{
		printf("\t Current buys = %d, Expected buys = %d\n", currentBuys, expectedBuys);
		printf("Test #6 passed.  Player did not have additional buys.\n");
	}
	else
	{
		printf("\t Current buys = %d, Expected buys = %d\n", currentBuys, expectedBuys);
		printf("Test #6 FAILED! Player had additional buys. \n");
	}

#endif


	return 0;

}
