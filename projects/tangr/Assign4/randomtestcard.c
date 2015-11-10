/****************************************
* Name:		Robert Tang
* Class:	CS362, Fall 2015
* Filename:	randomtestcard.c
*
* Description:
* test if 'smithy' card works.
*	card count check
*
*	Still struggling with coding aspect
*	I think I have resolved my understanding with "played" and "discard"
*****************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "rngs.h"
#include <time.h>

#define NUM_CHECKS 1000												// macro in C?
#define MIN_PLAYERS 2												// use to determine players
#define MAX_PLAYERS 4
#define HANDSIZE 5													// maybe not necessary

void checkHand(int player, int currentSize, int expectedDifference, struct gameState *testGame)
{
	if (player != whoseTurn(testGame))
		printf("Error - player turn change \n");
	if (currentSize + expectedDifference != numHandCards(testGame))
		printf("Warning - possible error in hand size \n");
}

void checkDeck(int player, int currentDeckSize, int difference,  struct gameState *testGame)
{
	if (player != whoseTurn(testGame))
		printf("Error - player turn change \n");
	if (currentDeckSize + difference != numHandCards(testGame))
		printf("Warning - possible error in deck count \n");

}

void checkScore(int currentPlayer, int currentScore, struct gameState *testGame)
{
	if (currentPlayer != whoseTurn(testGame))
		printf("Error - player turn change \n");
	if (currentScore != scoreFor(currentPlayer, testGame))
		printf("Error - Score changed \n");
}

void checkCardPlayed(int currentPlayer, int position, int cardID, struct  gameState* testGame)
{
	if (currentPlayer != whoseTurn(testGame))
		printf("Error - player turn change \n");
    if(testGame->hand[currentPlayer][position] == cardID)
		printf("Warning - possible playing of card error \n");
}

void smithyTest(int numPlayers, int seed, struct gameState *testGame)
{
	srand(time(NULL));
//	int player = rand() % (MAX_PLAYERS - MIN_PLAYERS) + MIN_PLAYERS;
	int positionSmithy;
	int currentPlayer;
	int currentHandSize;
	int currentDeckTotal;
	int currentScore;
	
	currentPlayer = whoseTurn(testGame);
	currentHandSize = numHandCards(testGame);
	currentScore = scoreFor(currentPlayer, testGame);
	positionSmithy = rand() % currentHandSize;

// 	Play Card	
	playSmithy(testGame, positionSmithy);
//	Test Functions
	checkHand(currentPlayer, currentHandSize, 2, testGame);
//	checkCardPlayed(currentPlayer, positionSmithy, adventurer, testGame);		failed to understand in time for testing
	checkDeck(currentPlayer, currentDeckTotal, 0, testGame);
	checkScore(currentPlayer, currentScore, testGame);
	
	printf("End of Testing - Smithy\n");
}

int main()
{
    struct gameState testGame;										// initializer
	srand(time(NULL));
	int seed, numPlayers;									// randomizer
    int k[10] = {adventurer, gardens, embargo, village, minion, 
				mine, cutpurse, sea_hag, tribute, smithy};
	
	int i;
	
	for (i = 0; i < NUM_CHECKS; i++)
	{
		seed = (rand()%1000) + 1;									// randomize
		numPlayers = (random()% (MAX_PLAYERS - MIN_PLAYERS) + MIN_PLAYERS);
		initializeGame(numPlayers, k, seed, &testGame);
		smithyTest(numPlayers, seed, &testGame);
		
	}
	return 0;
}