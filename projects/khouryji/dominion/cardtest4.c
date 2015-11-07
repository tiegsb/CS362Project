#include "dominion.h"
#include <string.h>
#include <stdio.h>
#include "unittestHelper.h"
#include <stdlib.h>
#include <limits.h>


int main()
{
  int i;
  int TEST_TIMES= 3;
  struct gameState testerState;
  srand(time(0));

  printf("*****************************************************\n");
  printf("*CARDTEST4 Suite \n");
  printf("  (tests VILLAGE with 3 semi-random states)\n");
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
  handPos= 0;
  caseVillage(state->whoseTurn, handPos, state);

  //snapshot of state AFTER
  afterCopy= *state;

    //*********************************************************************
    //These assignments affect the difference finder function at the end
    //
    //hand for this player is expected to be changed (increased in size by 2)
    hand[0]= copyState.whoseTurn;
    handCount[0]= copyState.whoseTurn;
    //deck for this player is expected to change as the player draws cards from the deck
    deck[0]= copyState.whoseTurn;
    deckCount[0]= copyState.whoseTurn;
    //the discard pile for this player should take all non treasure cards and should change if the 
    //deck runs empty
    test[E_discard]= 1;
    test[E_discardCount]= 1;
    test[E_numActions]= 1;
    //*********************************************************************
	
	//check if handCount stayed the same (draw 1 card discard village)
  if(afterCopy.handCount[afterCopy.whoseTurn]!= copyState.handCount[copyState.whoseTurn])
  {
        printf("Test handCount: FAILED\n");
        printf("handCount Before: %d\n", copyState.handCount[copyState.whoseTurn]);
        printf("handCount After: %d\n\n", afterCopy.handCount[afterCopy.whoseTurn]);
  }
  //check if numActions+=2
  if(afterCopy.numActions!= copyState.numActions+2)
  {
        printf("Test numActions+=2: FAILED\n");
        printf("numActions Before: %d\n", copyState.numActions);
        printf("numActions After: %d\n\n", afterCopy.numActions);
  }
  

  //******************************************************************************
  //Find all changes to gamestate and print errors if changes were not expected
  printBadDiffs(&copyState, &afterCopy, test, hand, hLen, handCount, hcLen, discard, diLen, discardCount, dicLen, deck, deLen, deckCount, decLen);  

  return 0;
}



