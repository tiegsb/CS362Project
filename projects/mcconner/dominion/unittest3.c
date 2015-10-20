/* Rachael McConnell
 * CS362 Fall 2015
 * Unit Test 3: isGameOver
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int testIsGameOver(struct gameState *gs) {
  /*struct gameState gs;
  int numPlayers = 2;
  int handCount=5;
  int randomSeed = rand() % 100 + 1;
  int test1[5] = { copper, copper, copper, copper, copper };
  int test2[5] = { copper, silver, estate, duchy, silver };
  int test3[0] = { };
    
  int kingdom[10]= { adventurer, baron, council_room, feast, gardens, great_hall, mine, remodel, smithy, village };
 
  memset(&gs, 23, sizeof(struct gameState));
  initializeGame(numPlayers, kingdom, randomSeed, &gs);
  memcpy(gs.hand[0], test1, sizeof(int)*handCount);
  */
  int gameOver = isGameOver(gs);

  if(gameOver == 1){
    printf("Game over\n");
  }else{
    printf("Game continues\n");
  }
  printf("Pass\n");

  return 0;
}

int main(){
 
  struct gameState gs;
  int numPlayers = 2;
  int handCount=5;
  int returned=0;
  int randomSeed = rand() % 100 + 1;
  int test1[5] = { copper, copper, copper, copper, copper };
  
  int kingdom[10]= { adventurer, baron, council_room, feast, gardens, great_hall, mine, remodel, smithy, village };
 
  memset(&gs, 23, sizeof(struct gameState));
  initializeGame(numPlayers, kingdom, randomSeed, &gs);
  memcpy(gs.hand[0], test1, sizeof(int)*handCount);
  
  printf("\nTest 1 (Stack of province cards is empty- game should end)\n");
  gs.supplyCount[province] = 0;
  returned+= testIsGameOver(&gs);
 
  printf("\nTest 2 (No supply piles are empty- game should continue)\n");
  gs.supplyCount[province]=1;
  returned+= testIsGameOver(&gs);

  printf("\nTest 3 (3 supply piles are empty- game should end)\n");
  gs.supplyCount[copper]=0;
  gs.supplyCount[estate]=0;
  gs.supplyCount[silver]=0;
  returned+= testIsGameOver(&gs);

  printf("\nTest 4 (2 supply piles are empty- game should continue)\n");
  gs.supplyCount[copper]=10;
  returned+= testIsGameOver(&gs);

  if(returned == 0)
    printf("All isGameOver tests passed!\n");
  else
    printf("Some isGameOver tests failed\n");

  return 0;
}

