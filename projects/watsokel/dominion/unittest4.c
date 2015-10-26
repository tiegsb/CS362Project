/* -----------------------------------------------------------------------
* Programmed by: Kelvin Watson
* Filename: unittest4.c
* Created: 10 Oct 2015
* Last modified: 21 Oct 2015
* Description: Unit tests for dominion.c 's gainCard() function
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
  return errFlag;
}


int main() {
  int p,r;
  int seed = 1000;
  int numPlayers = 2;
  int k[10] = {adventurer, council_room, feast, gardens, mine
    , remodel, smithy, outpost, salvager, sea_hag};
  struct gameState G;
  int errFlag=0;
  int supplyPos, toFlag, gain;
  
  printf ("TESTING gainCard():\n");
	
	for (p = 0; p < numPlayers; p++){
		for(supplyPos = curse; supplyPos <= treasure_map; supplyPos++){
      for(toFlag = 0; toFlag <= 2; toFlag++){
        printf("Testing player %d, supply card %d with gain card flag of %d:\n", p, supplyPos, toFlag);
        memset(&G, 23, sizeof(struct gameState));   // clear game state
        r=initializeGame(numPlayers, k, seed, &G);  // initialize new game
        gain = gainCard(supplyPos,&G,toFlag,p);
        if(supplyPos != curse && supplyPos != estate && supplyPos != duchy &&  supplyPos != province 
          && supplyPos != copper && supplyPos !=silver && supplyPos != gold && supplyPos != adventurer 
          && supplyPos != council_room && supplyPos != feast && supplyPos != gardens && supplyPos != mine 
          && supplyPos != remodel && supplyPos != smithy && supplyPos != outpost && supplyPos != salvager
          && supplyPos != sea_hag){
          //if card is not in the game, then player should not be able to gain that card
            printf("  Attempt to gain a card that is not in the game\n");
			if(gain != -1){
              printf("    FAIL, gain=%d, expected=%d\n", gain, -1);
              errFlag++;
            }else{
              printf("    PASS, gain=%d, expected=%d\n", gain, -1);
            }
        //if card is in the game, then player should be able to gain that card
        } else{
          if(gain != 0){
            printf("    FAIL, gain=%d, expected=%d\n", gain, 0);
            errFlag++;
          }else{
            printf("    PASS, gain=%d, expected=%d\n", gain, 0);
          }
        }
      }
    }
  }
  
  if(errFlag != 0){
    printf("Some tests failed. See bug1.c for details.\n");
  } else {
    printf("All tests passed!\n");
  }

  return 0;
}