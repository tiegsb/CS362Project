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
  printf("*UNITTEST4 Suite \n");
  printf("  (tests gainCard() with 100 semi-random state)\n");
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
  int supplyPos=0;
  int toFlag=0;

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

  supplyPos= rand() % treasure_map+1;
  toFlag= rand() % 3;
  r= gainCard(supplyPos, state, toFlag, copyState.whoseTurn);

  //snapshot of state AFTER
  afterCopy= *state;



//check if supply pile is empty (0) or card is not used in game (-1) and 
  //check taht supply count is not changed from 0
  if(copyState.supplyCount[supplyPos] < 1)
  {
    if(r!= -1)
    {
      printf("Test empty supply: FAILED\n");
      printf("expected return value: -1\n\n");
    }
    if(afterCopy.supplyCount[supplyPos] != copyState.supplyCount[supplyPos])
    {
      printf("Test supplyCount on empty supply: FAILED\n");
      printf("supplyCount Before: %d\n", copyState.supplyCount[supplyPos]);
      printf("supplyCount After: %d\n\n", afterCopy.supplyCount[supplyPos]);
    }

  }
  else
  {
    test[E_supplyCount]= 1;
    if(afterCopy.supplyCount[supplyPos] != copyState.supplyCount[supplyPos]- 1)
    {
      printf("Test supplyCount decrement: FAILED\n");
      printf("supplyCount Before: %d\n", copyState.supplyCount[supplyPos]);
      printf("supplyCount After: %d\n\n", afterCopy.supplyCount[supplyPos]);
    }

    // check
    //added card for [whoseTurn] current player:
    // toFlag = 0 : add to discard
    // toFlag = 1 : add to deck
    // toFlag = 2 : add to hand
    switch(toFlag)
    {
      case 0: 
        test[E_discard]= 1;
        test[E_discardCount]= 1;
        if(afterCopy.discardCount[afterCopy.whoseTurn] != copyState.discardCount[copyState.whoseTurn]+ 1)
        {
          printf("Test discardCount increment: FAILED\n");
          printf("discardCount Before: %d\n", copyState.discardCount[copyState.whoseTurn]);
          printf("discardCount After: %d\n\n", afterCopy.discardCount[afterCopy.whoseTurn]);

          //tell difference finder at end of function to allow these changes          
        }
        if(afterCopy.discard[afterCopy.whoseTurn][afterCopy.discardCount[afterCopy.whoseTurn]-1] != supplyPos)
        {
          printf("Test discard pile gained the right card: FAILED\n");
          printf("card selected for gain: %d\n", supplyPos);
          printf("discard pile last card Before: %d\n", copyState.discard[copyState.whoseTurn][copyState.discardCount[afterCopy.whoseTurn]-1]);
          printf("discard pile last card After: %d\n\n", afterCopy.discard[afterCopy.whoseTurn][afterCopy.discardCount[afterCopy.whoseTurn]-1]);
        }      
        break;

      case 1:
        //tell difference finder at end of function to allow these changes
        test[E_deck]= 1;
        test[E_deckCount]= 1;
        if(afterCopy.deckCount[afterCopy.whoseTurn] != copyState.deckCount[copyState.whoseTurn]+ 1)
        {
          printf("Test deckCount increment: FAILED\n");
          printf("deckCount Before: %d\n", copyState.deckCount[copyState.whoseTurn]);
          printf("deckCount After: %d\n\n", afterCopy.deckCount[afterCopy.whoseTurn]);          
          
        } 
        if(afterCopy.deck[afterCopy.whoseTurn][afterCopy.deckCount[afterCopy.whoseTurn]-1] != supplyPos)
        {
          printf("Test deck gained the right card: FAILED\n");
          printf("card selected for gain: %d\n", supplyPos);
          printf("deck pile last card Before: %d\n", copyState.deck[copyState.whoseTurn][copyState.deckCount[afterCopy.whoseTurn]-1]);
          printf("deck pile last card After: %d\n\n", afterCopy.deck[afterCopy.whoseTurn][afterCopy.deckCount[afterCopy.whoseTurn]-1]);
        }
        break;

      case 2: 
        //tell difference finder at end of function to allow these changes
        test[E_hand]= 1;
        test[E_handCount]= 1;
        if(afterCopy.handCount[afterCopy.whoseTurn] != copyState.handCount[copyState.whoseTurn]+ 1)
        {
          printf("Test handCount increment: FAILED\n");
          printf("handCount Before: %d\n", copyState.handCount[copyState.whoseTurn]);
          printf("handCount After: %d\n\n", afterCopy.handCount[afterCopy.whoseTurn]);
                    
        } 
        if(afterCopy.hand[afterCopy.whoseTurn][afterCopy.handCount[afterCopy.whoseTurn]-1] != supplyPos)
        {
          printf("Test hand gained the right card: FAILED\n");
          printf("card selected for gain: %d\n", supplyPos);
          printf("hand pile last card Before: %d\n", copyState.hand[copyState.whoseTurn][copyState.handCount[afterCopy.whoseTurn]-1]);
          printf("hand pile last card After: %d\n\n", afterCopy.hand[afterCopy.whoseTurn][afterCopy.handCount[afterCopy.whoseTurn]-1]);
        }
        break;

    }
  }
 

  //Find all changes to gamestate and print errors if changes were not expected
  printBadDiffs(&copyState, &afterCopy, test, hand, hLen, handCount, hcLen, discard, diLen, discardCount, dicLen, deck, deLen, deckCount, decLen);  

  return 0;
}
