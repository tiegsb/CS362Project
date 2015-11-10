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
  printf("*CARDTEST3 Suite \n");
  printf("  (tests STEWARD with 10 semi-random states)\n");
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
  int handPos=0,
    choice,
    cardChoice1,
    cardChoice2;

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

  choice= rand() % 3 + 1;
  cardChoice1= rand() % 3 + 1;
  cardChoice2= 2;
  handPos= 0;
  caseSteward(choice, cardChoice1, cardChoice2,state->whoseTurn, handPos, state);

  //snapshot of state AFTER
  afterCopy= *state;

  if(cardChoice1== cardChoice2
  ||cardChoice2== handPos
  ||cardChoice1== handPos)
  {
    return;
  }

  discard[0]= afterCopy.whoseTurn;
  discardCount[0]= afterCopy.whoseTurn;
  switch(choice)
  {
    case 1:
      hand[0]= afterCopy.whoseTurn;
      handCount[0]= afterCopy.whoseTurn;    
      deck[0]= afterCopy.whoseTurn;
      deckCount[0]= afterCopy.whoseTurn;
      //check if handCount went up by 1 (draw 2 cards and discard STEWARD)
      if(afterCopy.handCount[afterCopy.whoseTurn]!= copyState.handCount[copyState.whoseTurn]+ 1)
      {
            printf("Test handCount+=1: FAILED\n");
            printf("handCount Before: %d\n", copyState.handCount[copyState.whoseTurn]);
            printf("handCount After: %d\n\n", afterCopy.handCount[afterCopy.whoseTurn]);
      }
      //check if STEWARD was discarded
      if(afterCopy.discardCount[afterCopy.whoseTurn]!= copyState.discardCount[copyState.whoseTurn]- 1)
        { 
            printf("Test discardCount+=3: FAILED\n");
            printf("discardCount Before: %d\n", copyState.handCount[copyState.whoseTurn]);
            printf("discardCount After: %d\n\n", afterCopy.handCount[afterCopy.whoseTurn]);
        }
      break;
    case 2:
      //check if coins went up by 2
      if(afterCopy.coins!= copyState.coins+ 2)
      {
            printf("Test coins+=2: FAILED\n");
            printf("coins Before: %d\n", copyState.coins);
            printf("coins After: %d\n\n", afterCopy.coins);
      }
      //check if STEWARD was discarded
      if(afterCopy.discardCount[afterCopy.whoseTurn]!= copyState.discardCount[copyState.whoseTurn]- 1)
        { 
            printf("Test discardCount+=3: FAILED\n");
            printf("discardCount Before: %d\n", copyState.handCount[copyState.whoseTurn]);
            printf("discardCount After: %d\n\n", afterCopy.handCount[afterCopy.whoseTurn]);
        }
      break;
    case 3:
        hand[0]= afterCopy.whoseTurn;
        handCount[0]= afterCopy.whoseTurn;
        discard[0]= afterCopy.whoseTurn;
        discardCount[0]= afterCopy.whoseTurn;
        deck[0]= afterCopy.whoseTurn;
        deckCount[0]= afterCopy.whoseTurn;
        //check if handCount went down by 3 (discard 2 cards of choice and discard STEWARD)
        if(afterCopy.handCount[afterCopy.whoseTurn]!= copyState.handCount[copyState.whoseTurn]- 3)
        { 
            printf("Test handCount-=3: FAILED\n");
            printf("handCount Before: %d\n", copyState.handCount[copyState.whoseTurn]);
            printf("handCount After: %d\n\n", afterCopy.handCount[afterCopy.whoseTurn]);
        }
        //check if discardCount went up by 3 (discard 2 cards of choice and discard STEWARD)
        if(afterCopy.discardCount[afterCopy.whoseTurn]!= copyState.discardCount[copyState.whoseTurn]- 3)
        { 
            printf("Test discardCount+=3: FAILED\n");
            printf("discardCount Before: %d\n", copyState.handCount[copyState.whoseTurn]);
            printf("discardCount After: %d\n\n", afterCopy.handCount[afterCopy.whoseTurn]);
        }
      break;
  }  

  //******************************************************************************
  //Find all changes to gamestate and print errors if changes were not expected
  printBadDiffs(&copyState, &afterCopy, test, hand, hLen, handCount, hcLen, discard, diLen, discardCount, dicLen, deck, deLen, deckCount, decLen);  

  return 0;
}


