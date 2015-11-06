#include "dominion.h"
#include <string.h>
#include <stdio.h>
#include "unittestHelper.h"
#include <stdlib.h>
#include <limits.h>


int main()
{
  int i;
  int TEST_TIMES= 10;
  struct gameState testerState;
  srand(time(0));

  printf("*****************************************************\n");
  printf("*CARDTEST1 Suite \n");
  printf("  (tests SMITHY with 10 semi-random states)\n");
  printf("*****************************************************\n");
  for(i=0; i<TEST_TIMES; i++)
  {    
    createRandState(&testerState);
    testerState.handCount[testerState.whoseTurn]= rand() % 13 +1;
    unittest2(&testerState);
  }
  
  return 0;
}
  
//Tests drawCard()
unittest2(struct gameState *state)
{
  int i, b, r, test[E_playedCardCount+1]= {0};
  int handPos=0;

  int hand[1]={-1}, //arrays that show how many players may have differences in those attributes after call
    handCount[1]={-1},
    deck[1]={-1},
    deckCount[1]={-1},
    discard[1]={-1},
    discardCount[1]={-1};


  int hLen=1,
    hcLen=1,
    deLen=1,
    decLen=1,
    diLen=1,
    dicLen=1;

  struct gameState copyState, afterCopy;
  
  
  //snapshot of state BEFORE
  copyState= *state;

	if(copyState.handCount[copyState.whoseTurn]== 0)
	{
		printf("Skipping this random state: Random handCount assigned 0.\n\n");
		return 0;
	}
	else
	{
		handPos= rand() % copyState.handCount[copyState.whoseTurn];
	}
	caseSmithy(copyState.whoseTurn, handPos, state);

  //snapshot of state AFTER
  afterCopy= *state;

  	//*********************************************************************
  	//These assignments affect the difference finder function at the end
  	//
  	//hand for this playere is expected to changed
  	hand[0]= copyState.whoseTurn;
  	handCount[0]= copyState.whoseTurn;
  	//playedCards should be changed by smithy
  	test[E_playedCards]= 1;
  	test[E_playedCardCount]= 1;
  	//deck and discard piles for this player should change if the deck 
  	//becomes empty while drawing
  	deck[0]= copyState.whoseTurn;
  	deckCount[0]= copyState.whoseTurn;
  	discard[0]= copyState.whoseTurn;
  	discardCount[0]= copyState.whoseTurn;
  	//*********************************************************************

  	//check if handCount when up by 2 (draw 3 and discard smithy)
 	if(afterCopy.handCount[afterCopy.whoseTurn]!= copyState.handCount[copyState.whoseTurn]+ 2)
	{
		printf("Test handCount+=2: FAILED\n");
      	printf("handCount Before: %d\n", copyState.handCount[copyState.whoseTurn]);
      	printf("handCount After: %d\n\n", afterCopy.handCount[afterCopy.whoseTurn]);
	}

 
  //******************************************************************************
  //Find all changes to gamestate and print errors if changes were not expected
  printBadDiffs(&copyState, &afterCopy, test, hand, hLen, handCount, hcLen, discard, diLen, discardCount, dicLen, deck, deLen, deckCount, decLen);  

  return 0;
}


