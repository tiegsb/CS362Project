/*
*	CS362 - Assignment 3 - cardtest4.c
*	Card Test #4: This program runs the following 7 tests
*		to ensure the Great Hall card implementation is correct:
*		1. Player gets 1 card
*		2. card is discarded & replaced by correct card
*		3. Card drawn belong to player's deck
*		4. GreatHall doesn't affect other player's deck
*		5. Great Hall doesn't affects other's player's hand
*		6. Player receives 1 additional action
*		7. Player does not receive additional buy
*
*
*
*	Author: Carol D. Toro
*	Date: 10/21/2015
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
	const char* cardNames[] = { "curse", "estate", "duchy", "province", "copper", "silver", "gold", "adventurer", "council_room", "feast", "gardens", "mine", "remodel", "Adventurer", "village", "baron", "great_hall", "minion", "steward", "tribute", "ambassador", "cutpurse", "embargo", "outpost", "salvager", "sea_hag", "treasure_map" };

	/*Keep track of P0s deck & hand before & after*/
	int p_0_deckBeforeGreatHall[MAX_DECK];
	//int p_0_deckAfterGreatHall[MAX_DECK];
	//int p_0_handBeforeGreatHall[MAX_HAND];
	int p_0_handAfterGreatHall[MAX_HAND];

	/*Keep track of P1s deck before & after*/
	int p_1_deckBeforeGreatHall[MAX_DECK];
	int p_1_deckAfterGreatHall[MAX_DECK];
	int p_1_handBeforeGreatHall[MAX_HAND];
	int p_1_handAfterGreatHall[MAX_HAND];

	/*initialize array of silver filled hands, starting with CouncilRoom*/
	int silverHand[MAX_HAND];
	for (i = 0; i < MAX_HAND; i++)
	{
		if (i == 0)
			silverHand[i] = great_hall;
		else
			silverHand[i] = gold;
	}

	/*initialize array of copper filled hands*/
	int copperHand[MAX_HAND];
	for (i = 0; i < MAX_HAND; i++)
	{
		if (i == 0)
			copperHand[i] = great_hall;
		else
			copperHand[i] = copper;
	}




	/*Starting Test #1*/
#if (NOISY_TEST==1)
	printf("Starting cardtest3.c which checks GreatHallCard() \n");
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
		printf(" Test #1 passed. Player received 1 card. \n");
	}
	else
	{
		printf("\t \nGame state = %d, Expected state = %d\n", numCardsAfter, 5);
		printf(" Test #1 FAILED! Player did not receive 1 card. \n");
	}
#endif


	/*Starting Test #2*/
#if (NOISY_TEST==1)
	printf("\n Starting Test #2 - Great Hall is card is discarded & replaced by correct card \n");
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

	/*Save player 0's deck*/
	for (i = 0; i < 10; i++)
	{
		p_0_deckBeforeGreatHall[i] = Game.deck[0][i];
	}

	/*save player 1's deck*/
	for (i = 0; i < 10; i++)
	{
		p_1_deckBeforeGreatHall[i] = Game.deck[1][i];
	}

	/*play the smithy card*/
	result = playCard(0, 1, 2, 3, &Game);

	numCardsAfter = (numHandCards(&Game));

	/*Copy the hand after the Smithy was played*/
	for (i = 0; i < numCardsAfter; i++)
	{
		p_0_handAfterGreatHall[i] = Game.hand[0][i];
	}

	if (p_0_deckBeforeGreatHall[4] == p_0_handAfterGreatHall[0])
	{
		printf("\t Received card: %s, Expected card: %s \n", cardNames[p_0_handAfterGreatHall[0]], cardNames[p_0_deckBeforeGreatHall[4]]);
		printf(" Test #2 passed. Great Hall was replaced by correct card! \n");
	}
	else
	{
		printf("\t Received card: %s, Expected card: %s \n", cardNames[p_0_handAfterGreatHall[0]], cardNames[p_0_deckBeforeGreatHall[4]]);
		printf(" Test #2 FAILED! Great Hall was not replaced by correct card! \n");
	}


	/*Starting Test #3*/
#if (NOISY_TEST==1)
	printf("\n Starting Test #3 - player draws card from own deck \n");
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

	/*Save player 0's deck*/
	for (i = 0; i < 10; i++)
	{
		p_0_deckBeforeGreatHall[i] = Game.deck[0][i];
	}

	/*save player 1's deck*/
	for (i = 0; i < 10; i++)
	{
		p_1_deckBeforeGreatHall[i] = Game.deck[1][i];
	}

	/*play the smithy card*/
	result = playCard(0, 1, 2, 3, &Game);

	numCardsAfter = (numHandCards(&Game));

	/*Copy the hand after the Smithy was played*/
	for (i = 0; i < numCardsAfter; i++)
	{
		p_0_handAfterGreatHall[i] = Game.hand[0][i];
	}
#if (NOISY_TEST==1)
	if (p_0_deckBeforeGreatHall[4] == p_0_handAfterGreatHall[0])
	{
		printf("\t Received card: %s, Expected card: %s \n", cardNames[p_0_handAfterGreatHall[0]], cardNames[p_0_deckBeforeGreatHall[4]]);
		printf(" Test #3 passed and card was drawn from player's deck! \n");
	}
	else
	{
		printf("\t Received card: %s, Expected card: %s \n", cardNames[p_0_handAfterGreatHall[0]], cardNames[p_0_deckBeforeGreatHall[4]]);
		printf(" Test #3 FAILED! Card not drawn from player's deck! \n");
	}
#endif


	/*Starting Test #4*/
#if (NOISY_TEST==1)
	printf("\n Starting Test #4 - Great Hall doesn't affect other player \n");
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
		p_1_deckBeforeGreatHall[i] = Game.deck[1][i];
	}

	/* P0 plays the smithy card*/
	result = playCard(0, 1, 2, 3, &Game);

	numCardsAfter = (numHandCards(&Game));

	/*Copy p1's deck after the Smithy was played*/
	for (i = 0; i < 10; i++)
	{
		p_1_deckAfterGreatHall[i] = Game.deck[1][i];
	}

#if (NOISY_TEST==1)
	if (memcmp(p_1_deckBeforeGreatHall, p_1_deckAfterGreatHall, 10) == 0)
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
	printf("\n Starting Test #5 - Great Hall doesn't affect other player's hand \n");
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
		p_1_handBeforeGreatHall[i] = Game.hand[1][i];
	}

	/*P0 plays the greathall card*/
	result = playCard(0, 1, 2, 3, &Game);

	numCardsAfter = (numHandCards(&Game));

	/*Copy p1's hand after the greathall was played*/
	for (i = 0; i < 10; i++)
	{
		p_1_handAfterGreatHall[i] = Game.hand[1][i];
	}

#if (NOISY_TEST==1)
	if (memcmp(p_1_handBeforeGreatHall, p_1_handAfterGreatHall, 5) == 0)
	{
		printf("Test #5 passed. Other player hand was not affected. \n");
	}
	else
	{
		printf("Test #5 FAILED! Other player's hand was affected! \n"); 
	}
#endif


	/*Starting Test #6*/
#if (NOISY_TEST==1)
	printf("\n Starting Test #6 - ensure player receives 1 additional action \n");
#endif
	/*initialize gameSeed*/
	gameSeed = rand() % 1000 + 1;

	/*clear the game state*/
	memset(&Game, 23, sizeof(struct gameState));

	/*initialize game*/
	initializeGame(numPlayer, k, gameSeed, &Game);

	/*load player 0 hands with silverHand array & player 1 with copper*/
	memcpy(Game.hand[0], silverHand, sizeof(int) * MAX_HAND);
	memcpy(Game.deck[1], copperHand, sizeof(int) * MAX_HAND);

	/*load player's deck with gold*/
	memcpy(Game.deck[0], silverHand, sizeof(int) * MAX_DECK);

	updateCoins(0, &Game, 0);

	currentNumCards = (numHandCards(&Game));

	cardType = handCard(0, &Game);

	/*play the smithy card*/
	result = playCard(0, 1, 2, 3, &Game);

	expectedActions = 1;
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
	printf("\n Starting Test #7 - ensure player only receives 1 buy \n");
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

	/*play the smithy card*/
	result = playCard(0, 1, 2, 3, &Game);

	expectedBuys = 1;
	currentBuys = Game.numBuys;

#if (NOISY_TEST==1)
	if (expectedBuys == currentBuys)
	{
		printf("\t Current buys = %d, Expected buys = %d\n", currentBuys, expectedBuys);
		printf("Test #7 passed.  Player did not receive additional buy.\n");
	}
	else
	{
		printf("\t Current buys = %d, Expected buys = %d\n", currentBuys, expectedBuys);
		printf("Test #7 FAILED! Player received additional buy. \n");
	}

#endif



	return 0;

}
