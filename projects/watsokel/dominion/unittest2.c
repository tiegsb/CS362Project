/* -----------------------------------------------------------------------
* Programmed by: Kelvin Watson
* Filename: unittest2.c
* Created: 10 Oct 2015
* Last modified: 14 Oct 2015
* Description: Unit tests for dominion.c 's discardCard() function

* ***NOTE: Some of these unit tests fail. Professor Christi is aware of this.
* Please see Piazza post where I notify Professor Christi that I may have
* discovered a possible bug with this unit test:
* https://piazza.com/class/iespjuw0jz7jg?cid=47 ***
* -----------------------------------------------------------------------
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int checkDiscardCard(int handPos, int player, struct gameState* state,int handCount, int discardedCard){
  int errFlag=0; //used in place of assertion failure: test passed=0; assertion failure=1
  int r = discardCard(handPos,player,state,0);
  if(r != 0){
#if (NOISY_TEST==1)
    printf("  discardCard(): FAIL, return value=%d, expected=%d\n", r, 0);
#endif 
  } else{
#if (NOISY_TEST==1)
    printf("  discardCard(): PASS, return value=%d, expected=%d\n", r, 0);
#endif 
  }
  //assert(r==0);
  //check handCount
  if(state->handCount[player] != (handCount-1)){
#if (NOISY_TEST==1)
    printf("  discardCard(): FAIL, handCount=%d, expected=%d\n", state->handCount[player], (handCount-1));
#endif    
    errFlag=1; //set error flag
  } else {
#if (NOISY_TEST==1)
    printf("  discardCard(): PASS handCount=%d, expected=%d\n", state->handCount[player], (handCount-1));
#endif
  }
  //assert(state->handCount[player] == (handCount-1));
  //check discard pile for the card discarded
  if(state->discardCount[player] != 1){
#if (NOISY_TEST==1)
    printf("  discardCard(): FAIL, discardCount=%d, expected=%d\n", state->discardCount[player], 1);
#endif    
    errFlag=1; //set error flag
  } else {
#if (NOISY_TEST==1)
    printf("  discardCard(): PASS discardCount=%d, expected=%d\n", state->discardCount[player], 1);
#endif
  }

  if(state->discard[player][(state->discardCount[player])-1] != discardedCard){
#if (NOISY_TEST==1)
    printf("  discardCard(): FAIL, discardedCard=%d, expected=%d\n", state->discard[player][(state->discardCount[player])-1], discardedCard);
#endif    
    errFlag=1; //set error flag
  } else {
#if (NOISY_TEST==1)
    printf("  discardCard(): PASS, discardedCard=%d, expected=%d\n",state->discard[player][(state->discardCount[player])-1] , discardedCard);
#endif
  }
  //assert(state->discard[player][(state->discardCount[player])-1] == discardedCard);
  
  return errFlag;
}


int main() {
  int i,p,r;
  int seed = 1000;
  int numPlayers = 2;
  int k[10] = {adventurer, sea_hag, council_room, feast, gardens, mine
    , remodel, smithy, baron, salvager};
  struct gameState G;
  int handPos;
  int maxHandCount = 5;
  int estates[MAX_HAND];
  int golds[MAX_HAND];
  int err=0;
  
  for (i = 0; i < MAX_HAND; i++){
    estates[i] = estate;
  }
  
  for (i = 0; i < MAX_HAND; i++){
    golds[i] = gold;
  }
  
  printf ("TESTING discardCard():\n");
	
	for (p = 0; p < numPlayers; p++){
		for(handPos = 0; handPos < maxHandCount; handPos++){
      printf("Testing player %d and discard card position of %d:\n", p, handPos);
      memset(&G, 23, sizeof(struct gameState));   // clear game state
			r=initializeGame(numPlayers, k, seed, &G);  // initialize new game
      G.handCount[p] = maxHandCount;                 // set the number of cards on hand
			memcpy(G.hand[p], estates, sizeof(int) * maxHandCount); //set all cards in hand to estate
			//printf("setting handPos=%d to be gold\n",handPos);
      G.hand[p][handPos]=gold; //set one card to be gold
      //printf("G.hand[p][gold]=%d\n",G.hand[p][handPos]);
			if(checkDiscardCard(handPos,p,&G,maxHandCount,gold) == 1){ //attempt to remove the single gold card
        err++;
      }
		}
	}
  
  if(err != 0){
    printf("Some tests failed.\n");
  } else {
    printf("All tests passed!\n");
  }

  return 0;
}