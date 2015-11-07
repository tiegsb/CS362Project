#include "dominion.h"
#include <string.h>
#include <stdio.h>
#include "unittestHelper.h"
#include <stdlib.h>
#include <limits.h>

int main()
{
	int i;
	int TEST_TIMES= 100;
	struct gameState testerState;
	srand(time(0));

	printf("*****************************************************\n");
	printf("*UNITTEST2 Suite \n");
	printf("  (tests drawCard() with 100 semi-random state)\n");
	printf("*****************************************************\n");
	for(i=0; i<TEST_TIMES; i++)
	{
		createRandState(&testerState);
		unittest2(&testerState);
	}
	
	return 0;
}
  
//Tests drawCard()
unittest2(struct gameState *state)
{
	int i, b, test[E_playedCardCount+1]= {0};
	
	int hand[1], //arrays that show how many players may have differences in those attributes after call
		handCount[1],
		deck[1],
		deckCount[1],
		discard[1],
		discardCount[1];

	int hLen,
		hcLen,
		deLen,
		decLen,
		diLen,
		dicLen;

	struct gameState copyState, afterCopy;
	
	
	//snapshot of state BEFORE
	copyState= *state;

	drawCard(copyState.whoseTurn, state);

	//snapshot of state AFTER
	afterCopy= *state;

	
	//check if deck was empty before, if it was, the new deckCount should be same 
	//as the old discardCount-1
	if(copyState.deckCount[copyState.whoseTurn]== 0)
	{
		if(afterCopy.deckCount[afterCopy.whoseTurn]!= copyState.discardCount[copyState.whoseTurn]- 1)
		{	
			printf("Test deckCount when empty before: FAILED\n");
			printf("deckCount Before: %d\n", copyState.deckCount[copyState.whoseTurn]);
			printf("deckCount After: %d\n", afterCopy.deckCount[copyState.whoseTurn]);
			printf("discardCount Before: %d\n\n", copyState.discardCount[copyState.whoseTurn]);
		}
	}

	//if deck was not empty, then deckCount should decrease by 1
	if(copyState.deckCount[copyState.whoseTurn]!= 0)
	{
		if(afterCopy.deckCount[afterCopy.whoseTurn]!= copyState.deckCount[copyState.whoseTurn]- 1)
		{	
			printf("Test deckCount when not empty before: FAILED\n");
			printf("deckCount Before: %d\n", copyState.deckCount[copyState.whoseTurn]);
			printf("deckCount After: %d\n\n", afterCopy.deckCount[copyState.whoseTurn]);
		}
	}

	//check if deck was empty before, if it was, the new discardCount should be 0.
	if(copyState.deckCount[copyState.whoseTurn]== 0)
	{
		if(afterCopy.discardCount[copyState.whoseTurn]!= 0)
		{	
			printf("Test discardCount when deck was empty before: FAILED\n");
			printf("deckCount Before: %d\n", copyState.deckCount[copyState.whoseTurn]);
			printf("deckCount After: %d\n", afterCopy.deckCount[copyState.whoseTurn]);
			printf("discardCount Before: %d\n", copyState.discardCount[copyState.whoseTurn]);
			printf("discardCount After: %d\n\n", afterCopy.discardCount[copyState.whoseTurn]);
		}
	}

	//handCount should increase by 1
	if(afterCopy.handCount[afterCopy.whoseTurn]!= copyState.handCount[copyState.whoseTurn]+ 1)
	{	
		printf("Test handCount: FAILED\n");
		printf("handCount Before: %d\n", copyState.handCount[copyState.whoseTurn]);
		printf("handCount After: %d\n\n", afterCopy.handCount[afterCopy.whoseTurn]);		
	}

	//if deck was not empty
	//new hands last card should be the one drawn from the old decks last position
	if(copyState.deckCount[copyState.whoseTurn]!= 0)
	{
		if((copyState.whoseTurn < MAX_PLAYERS)
		&&(copyState.deckCount[copyState.whoseTurn] < MAX_DECK)
		&&(copyState.handCount[copyState.whoseTurn] < MAX_HAND))		
		{
			if(afterCopy.hand[copyState.whoseTurn][copyState.handCount[copyState.whoseTurn]] 
				!= copyState.deck[copyState.whoseTurn][copyState.deckCount[copyState.whoseTurn]-1])
			{	
				printf("Test handCount: FAILED\n");
				printf("handCount Before: %d\n", copyState.handCount[copyState.whoseTurn]);
				printf("handCount After: %d\n\n", afterCopy.handCount[copyState.whoseTurn]);		
			}
		}
	}
	
	//players who are expected to possibly change in the following attributes
	hand[0]= copyState.whoseTurn;		
	hLen= 1;
				
	handCount[0]= copyState.whoseTurn;	
	hcLen= 1;

	discard[0]= copyState.whoseTurn;	
	diLen= 1;

	discardCount[0]= copyState.whoseTurn;	
	dicLen= 1;

	deck[0]= copyState.whoseTurn;
	deLen= 1;
	
	deckCount[0]= copyState.whoseTurn;
	decLen= 1;

	//Find all changes to gamestate and print errors if changes were not expected
	printBadDiffs(&copyState, &afterCopy, test, hand, hLen, handCount, hcLen, discard, diLen, discardCount, dicLen, deck, deLen, deckCount, decLen);	

	return 0;
}

