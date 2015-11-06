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
  printf("*UNITTEST3 Suite \n");
  printf("  (tests discardCard() with 100 semi-random state)\n");
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
  int i, b, test[E_playedCardCount+1]= {0};
  int handPos=0;
  int trashFlag=0;

  int hand[1], //arrays that show how many players may have differences in those attributes after call
    handCount[1],
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

  hand[0]= state->whoseTurn;
  handCount[0]= state->whoseTurn;

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
  trashFlag= rand() % 2;
  discardCard(handPos, copyState.whoseTurn, state, trashFlag);

  //snapshot of state AFTER
  afterCopy= *state;

  
  //If trash was not set, then playedCardCount should increase by 1 and the card at handPos
  //should now be in the playedCards set at the end.
  //else playedCardCount and playedCards should stay the same
  if(trashFlag==0)
  {
    if(afterCopy.playedCardCount!= copyState.playedCardCount+1)
    {
      printf("Test playedCardCount with no trash: FAILED\n");
      printf("playedCardCount Before: %d\n", copyState.playedCardCount);
      printf("playedCardCount After: %d\n\n", afterCopy.playedCardCount);    
    }
    if(afterCopy.playedCards[copyState.playedCardCount]!= copyState.hand[copyState.whoseTurn][handPos])
    {
      printf("Test playedCards with no trash: FAILED\n");
      printf("playedCards last card Before: %d\n", copyState.playedCards[copyState.playedCardCount]);
      printf("playedCards last card After: %d\n\n", afterCopy.playedCards[afterCopy.playedCardCount-1]);
    }

    //have difference finder at end of function allow changes to these attributes
    test[E_playedCardCount]= 1;
    test[E_playedCards]= 1;
  }
  else
  {

    if(afterCopy.playedCardCount!= copyState.playedCardCount)
    {
      printf("Test playedCardCount with trash set: FAILED\n");
      printf("playedCardCount Before: %d\n", copyState.playedCardCount);
      printf("playedCardCount After: %d\n\n", afterCopy.playedCardCount);    
    }
  }

  //Find all changes to gamestate and print errors if changes were not expected
  printBadDiffs(&copyState, &afterCopy, test, hand, hLen, handCount, hcLen, discard, diLen, discardCount, dicLen, deck, deLen, deckCount, decLen);  

  return 0;
}

