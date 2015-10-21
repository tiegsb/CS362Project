/* Rachael McConnell
 * CS362 Fall 2015
 * Unit Test 2: updateCoins
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int testUpdateCoins(int test[], int bonus) {
  struct gameState gs;
  int numPlayers = 2;
  int calculatedCoins=0;
  int handCount=5;
  int randomSeed = rand() % 100 + 1;
      
  int kingdom[10]= { adventurer, council_room, feast, gardens, mine,
remodel, smithy, village, baron, great_hall };
 
  memset(&gs, 23, sizeof(struct gameState));
  initializeGame(numPlayers, kingdom, randomSeed, &gs);
  memcpy(gs.hand[0], test, sizeof(int)*handCount);
  gs.handCount[0]=8;

  int i=0;
  for(i=0; i<handCount; i++){
    if(test[i] == copper){
      calculatedCoins++;
    }
    if(test[i] == silver){
      calculatedCoins+=2;
    }
    if(test[i] == gold){
      calculatedCoins+=3;
    }
    printf("Coins= %d\n", calculatedCoins);
   
  }
  calculatedCoins+=bonus;
  printf("Calculated coins w/ bonus: %d\n", calculatedCoins);
  updateCoins(0, &gs, bonus);
  printf("gs.coins: %d\n", gs.coins);
  assert(calculatedCoins == gs.coins);
  printf("Pass\n");
  return 0;
}

int main(){
  int bonus; 
  int test1[5] = { copper, copper, copper, copper, copper };
  int test2[5] = { copper, silver, estate, duchy, silver };
  int test3[5] = { estate, gold, gold, copper, estate };
  int returned;
  printf("Calling Test1: All Coppers\n");
  bonus=0;
  returned = testUpdateCoins(test1, bonus);
  printf("Calling Test2\n");
  bonus=5;
  returned = testUpdateCoins(test2, bonus);
  printf("Calling Test3\n");
  bonus=4;
  returned = testUpdateCoins(test3, bonus);
  
  if(returned == 0)
    printf("All updateCoins tests passed!\n");
  else
    printf("Some updateCoins tests failed\n");

  return 0;
}

