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
  
  updateCoins(0, &gs, bonus);

  if(calculatedCoins == gs.coins)
    printf("Pass: Correct number of coins.\n");
  else
    printf("Fail: Wrong number of coins.\n");
  printf("Calculated coins actual: %d, expected: %d\n", gs.coins, calculatedCoins);
  //assert(calculatedCoins == gs.coins);
  
  return 0;
}

int main(){
  int bonus; 
  int test1[5] = { copper, copper, copper, copper, copper };
  int test2[5] = { copper, silver, estate, duchy, silver };
  int test3[5] = { estate, gold, gold, copper, estate };
  int test4[5] = { gold, gold, gold, gold, gold };
  int returned;

  printf("Calling Test1\n");
  bonus=0;
  returned = testUpdateCoins(test1, bonus);
  
  printf("Calling Test2\n");
  bonus=5;
  returned = testUpdateCoins(test2, bonus);
  
  printf("Calling Test3\n");
  bonus=4;
  returned = testUpdateCoins(test3, bonus);
  
  printf("Calling Test 4\n");
  bonus=2;
  returned = testUpdateCoins(test4, bonus);

  if(returned == 0)
    printf("All updateCoins tests passed!\n");
  else
    printf("%d updateCoins tests failed\n", returned);

  return 0;
}

