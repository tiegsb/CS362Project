/*
*	CS362 - Assignment 3 - cardtest1.c
*	Card Test #1: This program runs the following 7 tests 
*		to ensure the Smithy card implementation is correct:
*		1. Player only receives 3 cards
*		2. Smithy card is discarded & replaced by correct card
*		3. Cards drawn belong to player's deck
*		4. Smithy doesn't affect other player's deck
*		5. Smithy doesn't affect other player's hand
*		6. Player doesn't receive additional action(s)
*		7. Player doesn't receive additional buy(s)
*
*	Author: Carol D. Toro
*	Date: 10/19/2015
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
	int currentActions, expectedActions, currentBuys, expectedBuys;
	int result, currentCards[10], cardsAfter[10], currentNumCards, numCardsAfter, cardType;
	const char* cardNames[] = { "curse", "estate", "duchy", "province", "copper", "silver", "gold", "adventurer", "council_room", "feast", "gardens", "mine", "remodel", "smithy", "village", "baron", "great_hall", "minion", "steward", "tribute", "ambassador", "cutpurse", "embargo", "outpost", "salvager", "sea_hag", "treasure_map" };
	
	/*Keep track of P0s deck & hand before & after*/
	int p_0_deckBeforSmithy[MAX_DECK];
	//int p_0_deckAfterSmithy[MAX_DECK];
	//int p_0_handBeforeSmithy[MAX_HAND];
	int p_0_handAfterSmithy[MAX_HAND];

	/*Keep track of P1s deck before & after*/
	int p_1_deckBeforeSmithy[MAX_DECK];
	int p_1_deckAfterSmithy[MAX_DECK];
	int p_1_handBeforeSmithy[MAX_HAND];
	int p_1_handAfterSmithy[MAX_HAND];

	/*initialize array of gold filled hands, starting with smithy*/
	int goldHand[MAX_HAND];
	for (i = 0; i < MAX_HAND; i++)
	{
		if (i == 0)
			goldHand[i] = smithy;
		else
			goldHand[i] = gold;
	}

	/*initialize array of copper filled hands*/
	int copperHand[MAX_HAND];
	for (i = 0; i < MAX_HAND; i++)
	{
		if (i == 0)
			copperHand[i] = smithy;
		else
			copperHand[i] = copper;
	}


	/*Starting Test #1*/
#if (NOISY_TEST==1)
	printf("Starting cardtest1.c which checks smithyCard() \n");
	printf("\n Starting Test #1 - player only receives 3 cards after playing smithy \n");
#endif
	/*initialize gameSeed*/
	gameSeed = rand() % 1000 + 1;

	/*clear the game state*/
	memset(&Game, 23, sizeof(struct gameState));

	/*initialize game*/
	initializeGame(numPlayer, k, gameSeed, &Game);

	/*load player 0 hands with goldHand array & player 1 with copper*/
	memcpy(Game.hand[0], goldHand, sizeof(int) * MAX_HAND);
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
	if ((numCardsAfter - currentNumCards +1) == 3)
	{
		printf("\t Current cards = %d, Expected cards = %d\n", numCardsAfter, 7);
		printf(" Test #1 passed. Player only received 3 cards\n");
	}
	else
	{
		printf("\t \nGame state = %d, Expected state = %d\n", numCardsAfter, 7);
		printf(" Test #1 FAILED! Player did not receive 3 cards. \n");
	}

#endif
	
	/*Starting Test #2*/
#if (NOISY_TEST==1)
	printf("\n Starting Test #2 - smithy card is discarded & replaced by correct card \n");
#endif

	/*initialize gameSeed*/
	gameSeed = rand() % 1000 + 1;

	/*clear the game state*/
	memset(&Game, 23, sizeof(struct gameState));

	/*initialize game*/
	initializeGame(numPlayer, k, gameSeed, &Game);

	/*load player 0 hands with goldHand array & player's 1 deck with copper*/
	memcpy(Game.hand[0], goldHand, sizeof(int) * MAX_HAND);
	memcpy(Game.deck[1], copperHand, sizeof(int) * MAX_HAND);

	/*Save player 0's deck*/
	for (i = 0; i < 10; i++)
	{
		p_0_deckBeforSmithy[i] = Game.deck[0][i];
	}

	/*save player 1's deck*/
	for (i = 0; i < 10; i++)
	{
		p_1_deckBeforeSmithy[i] = Game.deck[1][i];
	}
	
	/*play the smithy card*/
	result = playCard(0, 1, 2, 3, &Game);

	numCardsAfter = (numHandCards(&Game));

	/*Copy the hand after the Smithy was played*/
	for (i = 0; i < numCardsAfter; i++)
	{
		p_0_handAfterSmithy[i] = Game.hand[0][i];
	}

	if (p_0_deckBeforSmithy[2] == p_0_handAfterSmithy[0])
	{
		printf("\t Received card: %s, Expected card: %s \n", cardNames[p_0_handAfterSmithy[0]], cardNames[p_0_deckBeforSmithy[2]]);
		printf(" Test #2 passed and smithy was replaced by correct card! \n");
	}
	else
	{
		printf("\t Received card: %s, Expected card: %s \n", cardNames[p_0_handAfterSmithy[0]], cardNames[p_0_deckBeforSmithy[2]]);
		printf(" Test #2 FAILED! Smithy was not replaced by correct card! \n");
	}

	/*Starting Test #3*/
#if (NOISY_TEST==1)
	printf("\n Starting Test #3 - player draws cards from own deck \n");
#endif

	/*initialize gameSeed*/
	gameSeed = rand() % 1000 + 1;

	/*clear the game state*/
	memset(&Game, 23, sizeof(struct gameState));

	/*initialize game*/
	initializeGame(numPlayer, k, gameSeed, &Game);

	/*load player 0 hands with goldHand array & player's 1 deck with copper*/
	memcpy(Game.hand[0], goldHand, sizeof(int) * MAX_HAND);
	memcpy(Game.deck[1], copperHand, sizeof(int) * MAX_HAND);

	/*Save player 0's deck*/
	for (i = 0; i < 10; i++)
	{
		p_0_deckBeforSmithy[i] = Game.deck[0][i];
	}

	/*save player 1's deck*/
	for (i = 0; i < 10; i++)
	{
		p_1_deckBeforeSmithy[i] = Game.deck[1][i];
	}

	/*play the smithy card*/
	result = playCard(0, 1, 2, 3, &Game);

	numCardsAfter = (numHandCards(&Game));

	/*Copy the hand after the Smithy was played*/
	for (i = 0; i < numCardsAfter; i++)
	{
		p_0_handAfterSmithy[i] = Game.hand[0][i];
	}
#if (NOISY_TEST==1)
	if (p_0_deckBeforSmithy[2] == p_0_handAfterSmithy[0] && p_0_deckBeforSmithy[3] == p_0_handAfterSmithy[6] && p_0_deckBeforSmithy[4] == p_0_handAfterSmithy[5])
	{
		printf("\t Received card: %s, Expected card: %s \n", cardNames[p_0_handAfterSmithy[0]], cardNames[p_0_deckBeforSmithy[2]]);
		printf("\t Received card: %s, Expected card: %s \n", cardNames[p_0_handAfterSmithy[6]], cardNames[p_0_deckBeforSmithy[3]]);
		printf("\t Received card: %s, Expected card: %s \n", cardNames[p_0_handAfterSmithy[5]], cardNames[p_0_deckBeforSmithy[4]]);
		printf(" Test #3 passed and cards were drawn from player's deck! \n");
	}
	else
	{
		printf("\t Received card: %s, Expected card: %s \n", cardNames[p_0_handAfterSmithy[0]], cardNames[p_0_deckBeforSmithy[2]]);
		printf("\t Received card: %s, Expected card: %s \n", cardNames[p_0_handAfterSmithy[6]], cardNames[p_0_deckBeforSmithy[3]]);
		printf("\t Received card: %s, Expected card: %s \n", cardNames[p_0_handAfterSmithy[5]], cardNames[p_0_deckBeforSmithy[4]]);
		printf(" Test #3 FAILED! Cards not drawn from player's deck! \n");
	}
#endif


	/*Starting Test #4*/
#if (NOISY_TEST==1)
	printf("\n Starting Test #4 - smithy doesn't affect other player's deck \n");
#endif

	/*initialize gameSeed*/
	gameSeed = rand() % 1000 + 1;

	/*clear the game state*/
	memset(&Game, 23, sizeof(struct gameState));

	/*initialize game*/
	initializeGame(numPlayer, k, gameSeed, &Game);

	/*load player 0 hands with goldHand array & player's 1 deck with copper*/
	memcpy(Game.hand[0], goldHand, sizeof(int) * MAX_HAND);
	memcpy(Game.deck[1], copperHand, sizeof(int) * MAX_HAND);


	/*save player 1's deck*/
	for (i = 0; i < 10; i++)
	{
		p_1_deckBeforeSmithy[i] = Game.deck[1][i];
	}

	/* P0 plays the smithy card*/
	result = playCard(0, 1, 2, 3, &Game);

	numCardsAfter = (numHandCards(&Game));

	/*Copy p1's deck after the Smithy was played*/
	for (i = 0; i < 10; i++)
	{
		p_1_deckAfterSmithy[i] = Game.deck[1][i];
	}

#if (NOISY_TEST==1)
	if (memcmp(p_1_deckBeforeSmithy, p_1_deckAfterSmithy, 10)== 0)
	{
		printf("Test #4 passed and other player's deck was not affected! \n");
	}
	else
	{
		printf("Test #4 FAILED! Other player's deck was affected by Smithy! \n");
	}
#endif

	/*Starting Test #5*/
#if (NOISY_TEST==1)
	printf("\n Starting Test #5 - smithy doesn't affect other player's hand \n");
#endif

	/*initialize gameSeed*/
	gameSeed = rand() % 1000 + 1;

	/*clear the game state*/
	memset(&Game, 23, sizeof(struct gameState));

	/*initialize game*/
	initializeGame(numPlayer, k, gameSeed, &Game);

	/*load player 0 hands with goldHand array & player's 1 deck with copper*/
	memcpy(Game.hand[0], goldHand, sizeof(int) * MAX_HAND);
	memcpy(Game.deck[1], copperHand, sizeof(int) * MAX_HAND);

	/*save player 1's hand*/
	for (i = 0; i < 10; i++)
	{
		p_1_handBeforeSmithy[i] = Game.hand[1][i];
	}

	/*P0 plays the smithy card*/
	result = playCard(0, 1, 2, 3, &Game);

	numCardsAfter = (numHandCards(&Game));

	/*Copy p1's hand after the Smithy was played*/
	for (i = 0; i < 10; i++)
	{
		p_1_handAfterSmithy[i] = Game.hand[1][i];
	}

#if (NOISY_TEST==1)
	if (memcmp(p_1_handBeforeSmithy, p_1_handAfterSmithy, 10) == 0)
	{
		printf("Test #5 passed and other player's hand was not affected! \n");
	}
	else
	{
		printf("Test #5 FAILED! Other player's hand was affected by Smithy! \n");
	}
#endif


	/*Starting Test #6*/
#if (NOISY_TEST==1)
	printf("\n Starting Test #6 - ensure player doesn't receive additional actions \n");
#endif
	/*initialize gameSeed*/
	gameSeed = rand() % 1000 + 1;

	/*clear the game state*/
	memset(&Game, 23, sizeof(struct gameState));

	/*initialize game*/
	initializeGame(numPlayer, k, gameSeed, &Game);

	/*load player 0 hands with goldHand array & player 1 with copper*/
	memcpy(Game.hand[0], goldHand, sizeof(int) * MAX_HAND);
	memcpy(Game.hand[1], copperHand, sizeof(int) * MAX_HAND);

	/*load player's deck with gold*/
	memcpy(Game.deck[0], goldHand, sizeof(int) * MAX_DECK);

	updateCoins(0, &Game, 0);

	currentNumCards = (numHandCards(&Game));

	cardType = handCard(0, &Game);

	/*play the smithy card*/
	result = playCard(0, 1, 2, 3, &Game);

	expectedActions = 0;
	currentActions = Game.numActions;

#if (NOISY_TEST==1)
	if (expectedActions == currentActions)
	{
		printf("\t Current actions = %d, Expected actions = %d\n", currentActions, expectedActions);
		printf("Test #6 passed. \n");
	}
	else
	{
		printf("\t Current actions = %d, Expected actions = %d\n", currentActions, expectedActions);
		printf("Test #6 FAILED! Player had additional actions. \n");
	}

#endif

	/*Starting Test #7*/
#if (NOISY_TEST==1)
	printf("\n Starting Test #7 - ensure player doesn't receive additional buys \n");
#endif
	/*initialize gameSeed*/
	gameSeed = rand() % 1000 + 1;

	/*clear the game state*/
	memset(&Game, 23, sizeof(struct gameState));

	/*initialize game*/
	initializeGame(numPlayer, k, gameSeed, &Game);

	/*load player 0 hands with goldHand array & player 1 with copper*/
	memcpy(Game.hand[0], goldHand, sizeof(int) * MAX_HAND);
	memcpy(Game.hand[1], copperHand, sizeof(int) * MAX_HAND);

	/*load player's deck with gold*/
	memcpy(Game.deck[0], goldHand, sizeof(int) * MAX_DECK);

	updateCoins(0, &Game, 0);

	currentNumCards = (numHandCards(&Game));

	cardType = handCard(0, &Game);

	/*play the smithy card*/
	result = playCard(0, 1, 2, 3, &Game);

	expectedBuys = 1;
	currentBuys = Game.numBuys;

#if (NOISY_TEST==1)
	if (expectedBuys == currentBuys)
	{
		printf("\t Current buys = %d, Expected buys = %d\n", currentBuys, expectedBuys);
		printf("Test #7 passed.  Player did not have additional buys.\n");
	}
	else
	{
		printf("\t Current buys = %d, Expected buys = %d\n", currentBuys, expectedBuys);
		printf("Test #7 FAILED! Player had additional buys. \n");
	}

#endif

	return 0;

}
