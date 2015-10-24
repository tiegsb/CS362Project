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

int testIsGameOver(struct gameState *gs, int expected) {
  
  int gameOver = isGameOver(gs);
  
  if(gameOver == 1){
    printf("Game over- ");
  }else{
    printf("Game continues- ");
  }

  if(gameOver == expected){
    printf("Pass.\n");
    return 0;
  }else{
    printf("Fail.\n ");
    return 1;
  }
}

int main(){
 
  struct gameState gs;
  int numPlayers = 2;
  int handCount=5;
  int randomSeed = rand() % 100 + 1;
  int test1[5] = { province, copper, copper, copper, copper };
  int expected; 
  int kingdom[10]= { adventurer, baron, council_room, feast, gardens, great_hall, mine, remodel, smithy, village };
  int j;
  int num1;
  int num2;
  int failCount=0; 
  printf("Random seed: %d\n", randomSeed);
  memset(&gs, 23, sizeof(struct gameState));
  initializeGame(numPlayers, kingdom, randomSeed, &gs);
  memcpy(gs.hand[0], test1, sizeof(int)*handCount);


  //Test each of the 27 supply positions 
  //Each card is tested with the ones next to it
  // ie. 1,2,3 or 2,3,4 or 25,26,27
  // All tests should end the game because 3 supply's are at 0
  printf("Testing setting 3 supply piles to 0: Game should end.\n");
  for(j=1; j<28; j++){
    //expect game to end
    expected=1;
    //reset game state
    memset(&gs, 23, sizeof(struct gameState));
    //set supply count to 0 for 3 cards
    if(j>25){
      gs.supplyCount[j] = 0;
      gs.supplyCount[1] = 0;
      gs.supplyCount[2] = 0;
      printf("Testing %d, 1, 2\n", j);
    }else{
      gs.supplyCount[j] = 0;
      gs.supplyCount[j+1] = 0;
      gs.supplyCount[j+2] = 0;
      printf("Testing %d, %d, %d\n", j, j+1, j+2);
    }
    failCount += testIsGameOver(&gs, expected);
  }

  
  //Test province card
  printf("Testing setting the province supply pile to 0: Game should end.\n");
  //expect game to end
  expected=1;
  //reset game state
  memset(&gs, 23, sizeof(struct gameState));
  //set supply count to 0 for province card
  gs.supplyCount[province] = 0;
  failCount += testIsGameOver(&gs, expected);

  //Testing only setting two supply's to 0  
  printf("Testing only setting two supply piles to 0: Game should continue\n");
  for(j=0; j<10; j++){
    expected = 0;
    num1=0;
    num2=0;
    //reset game state
    memset(&gs, 23, sizeof(struct gameState));
    num1 = rand() % 27 + 1;
    num2 = rand() % 27 + 1;
    //province card is 3- change this because it will end the game
    if(num1 == 3)
      num1++;
    if(num2 == 3)
      num2++;
    //set 2 supply piles to 0
    gs.supplyCount[num1] = 0;
    gs.supplyCount[num2] = 0;
    failCount += testIsGameOver(&gs, expected);
  }
  printf("Total tests run: 38\n");

  if(failCount == 0)
    printf("All isGameOver tests passed!\n");

  printf("Tests passed: %d\n", 38-failCount);
  printf("Tests failed: %d\n", failCount);

  return 0;
}

