#include "dominion.h"
#include <string.h>
#include <stdio.h>
#include "unittestHelper.h"
#include <stdlib.h>
#include <limits.h>


int main()
{
	int i;

	int TEST_TIMES= 50;
	struct gameState testerState;
	srand(time(0));

	printf("*****************************************************\n");
	printf("*UNITTEST1 Suite \n");
	printf("  (tests endTurn() with 50 semi-random state)\n");
	printf("*****************************************************\n");
	for(i=0; i<TEST_TIMES; i++)
	{
		createRandState(&testerState);
		unittest1(&testerState);
	}
	
	return 0;
}
//Test function endTurn()
unittest1(struct gameState *state)
{
	int i, b, length, test[E_playedCardCount+1]= {0};

	int hand[2], //arrays that show how many players may have differences in those attributes after call
		handCount[2],
		deck[1],
		deckCount[1],
		discard[2],
		discardCount[2];

	int hLen,
		hcLen,
		deLen,
		decLen,
		diLen,
		dicLen;

	struct gameState copyState, afterCopy;		
	
	//snapshot of state BEFORE
	copyState= *state;
	//makeCopyState(state, &copyState);

	endTurn(state);

	//snapshot of state AFTER
	afterCopy= *state;
	
	//---------------------------------------
	// Checks all post conditions
	//---------------------------------------

	//playedCard count should be reset to 0
	if(afterCopy.playedCardCount == 0);
		//{printf("Test playedCardCount: PASSED\n");}
	else
	{	
		printf("Test playedCardCount: FAILED\n");
		printf("playedCardCount Before: %d\n", copyState.playedCardCount);
		printf("playedCardCount After: %d\n\n", afterCopy.playedCardCount);
	}	

	//numBuys should be reset to 1
	if(afterCopy.numBuys == 1);
		//{printf("Test numBuys: PASSED\n");}
	else
	{	
		printf("Test numBuys: FAILED\n");
		printf("numBuys Before: %d\n", copyState.numBuys);
		printf("numBuys After: %d\n\n", afterCopy.numBuys);
	}

	//numActions should be reset to 1
	if(afterCopy.numActions == 1);
		//{printf("Test numActions: PASSED\n");}
	else
	{	
		printf("Test numActions: FAILED\n");
		printf("numActions Before: %d\n", copyState.numActions);
		printf("numActions After: %d\n\n", afterCopy.numActions);
	}

	//phase should be reset to 0
	if(afterCopy.phase == 0);
		//{printf("Test phase: PASSED\n");}
	else
	{	
		printf("Test phase: FAILED\n");
		printf("phase Before: %d\n", copyState.phase);
		printf("phase After: %d\n\n", afterCopy.phase);
	}

	//whoseTurn should be previous whoseTurn +1, or 0 if previous whoseTurn was max index
	if(copyState.whoseTurn >= (copyState.numPlayers-1))
	{
		if(afterCopy.whoseTurn != 0)
		{
			printf("Test whoseTurn: Failed\n");
			printf("whoseTurn Before: %d\n", copyState.whoseTurn);
			printf("whoseTurn After: %d\n", afterCopy.whoseTurn);
			printf("numplayers:%d\n\n", copyState.numPlayers);
		}
	}
	else if(afterCopy.whoseTurn != (copyState.whoseTurn + 1))
	{
		printf("Test whoseTurn: Failed\n");
		printf("whoseTurn Before: %d\n", copyState.whoseTurn);
		printf("whoseTurn After: %d\n", afterCopy.whoseTurn);
		printf("numplayers:%d\n\n", copyState.numPlayers);
	}

	//outpostPlayed should be reset to 0
	if(afterCopy.outpostPlayed == 0);
		//{printf("Test outpostPlayed: PASSED\n");}
	else
	{	
		printf("Test outpostPlayed: FAILED\n");
		printf("outpostPlayed Before: %d\n", copyState.outpostPlayed);
		printf("outpostPlayed After: %d\n\n", afterCopy.outpostPlayed);
	}

	//discard count of previous whoseTurn should be increased by previous whoseTurn hand count 
	if(afterCopy.discardCount[copyState.whoseTurn] == copyState.discardCount[copyState.whoseTurn] + copyState.handCount[copyState.whoseTurn]);
	//{printf("Test discardCount: PASSED\n");}	
	else
	{
		printf("Test discardCount: FAILED\n");
		printf("discardCount Before: %d\n");
		printf("discardCount After: %d\n\n");
	}

	//discard pile of the previous whoseTurn should include the cards from previous whoseTurn hand, in order
	b=0;
	for(i=0; i<copyState.handCount[copyState.whoseTurn]; i++)
	{
		if(afterCopy.discard[copyState.whoseTurn][copyState.discardCount[copyState.whoseTurn]+i] != copyState.hand[copyState.whoseTurn][i])
		{
			printf("Test discard: FAILED\n");
			printf("Error: last user's hand was not properly put into the discard pile.\n");
			printf("Card#%d expected in player#%d's discard pile position#%d\n\n", copyState.hand[copyState.whoseTurn][i], copyState.whoseTurn, copyState.discardCount+i);
			b= 1;
		}
	}
	//if(!b){printf("Test discard: PASSED\n");}
	
	//current whoseTurn handCount should be 5
	if(afterCopy.handCount[afterCopy.whoseTurn] != 5)
	{
		printf("Test handCount: FAILED\n");
		printf("Error: current player should have a handCount of 5.\n");
		printf("Actual handCount: %d\n", afterCopy.handCount[afterCopy.whoseTurn]);
		printf("stateBefore:%d, stateAfter:%d\n\n",state->handCount[copyState.whoseTurn],
												 state->handCount[state->whoseTurn]);
	}

	//previous whoseTurn handCount should be 0
	if(afterCopy.handCount[copyState.whoseTurn] != 0)
	{
		printf("Test handCount: FAILED\n");
		printf("previous player should now have a handCount of 0.\n");
		printf("Actual handCount: %d\n\n", afterCopy.handCount[copyState.whoseTurn]);
	}


	//These are state attributes that are expected to change
	//This array will let the change spotter know to ignore changes to these
	//attributes
	test[E_playedCardCount]= 1;
	test[E_playedCards]= 1;	
	test[E_numBuys]= 1;
	test[E_numActions]= 1;
	test[E_phase]= 1;
	test[E_whoseTurn]= 1;
	test[E_outpostPlayed]= 1;
	test[E_coins]= 1;

	//the hand of the former player is expected change
	hand[0]= copyState.whoseTurn;	
	//the hand of the new player is expected to change
	hand[1]= afterCopy.whoseTurn;
	hLen= 2;
				
	handCount[0]= copyState.whoseTurn;	
	handCount[1]= afterCopy.whoseTurn;	
	hcLen= 2;

	discard[0]= copyState.whoseTurn;	
	discard[1]= afterCopy.whoseTurn;
	diLen= 2;

	discardCount[0]= copyState.whoseTurn;	
	discardCount[1]= afterCopy.whoseTurn;
	dicLen= 2;

	deck[0]= afterCopy.whoseTurn;
	deLen= 1;
	
	deckCount[0]= afterCopy.whoseTurn;
	decLen= 1;

	//Find all changes to gamestate and print errors if changes were not expected
	printBadDiffs(&copyState, &afterCopy, test, hand, hLen, handCount, hcLen, discard, diLen, discardCount, dicLen, deck, deLen, deckCount, decLen);	
		
	return 0;
}


	