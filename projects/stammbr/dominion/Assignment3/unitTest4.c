/*****************
 * Author:  Brian Stamm
 * Title:  unitTest4.c
 * Assignment:  3
 * Date:  10.25.15
 * Notes:  Unit test for isGameOver().
 * ****************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void test(){
  struct gameState g;
  struct gameState *game = &g;
  srand(time(NULL));
  int r = rand();
  int j, i, k, c, truth;
  
  //Initial check, first no province cards
  game->supplyCount[province] = 0;
  if(isGameOver(game) == 1){
    printf("isGameOver() test:  PASSED 1 - province cards 0\n");
  }
  else{
    printf("isGameOver() test:  FAILED 1 - province cards 0\n");
  }
	
  //Check no supply cards are zero
  int total = treasure_map;
  for (i = 0; i <= total; i++){
    game->supplyCount[i] = 5;
  }

  if(isGameOver(game) == 0){
    printf("isGameOver() test:  PASSED 2 - Game not over\n");
  }
  else{
    printf("isGameOver() test:  FAILED 2 - Game not over\n");
  }

  //Check one supply card zero
  j = r % total;
  game->supplyCount[j] = 0;
  if(isGameOver(game) == 0){
    printf("isGameOver() test:  PASSED 3 - Game not over\n");
  }
  else{
    printf("isGameOver() test:  FAILED 3 - Game not over\n");
  }

  //Check two supply card zero
  k = j;
  while(k == j){
    r = rand();
    k = r % total;
  }
  game->supplyCount[k] = 0;
  if(isGameOver(game) == 0){
    printf("isGameOver() test:  PASSED 4 - Game not over\n");
  }
  else{
    printf("isGameOver() test:  FAILED 4 - Game not over\n");
  }

  //Check 3 supply cards are zero
  c = k;
  while(c == k){
    r = rand();
    c = r % total;
    if(c == j){
      c = k;
    }
  }
  game->supplyCount[c] = 0;
  if(isGameOver(game) == 1){
    printf("isGameOver() test:  PASSED 5 - Game over\n");
  }
  else{
    printf("isGameOver() test:  FAILED 5 - Game over\n");
  }

  //Random testing - 500x, random number of cards 0, loop.
  for (i = 0; i <= total; i++){
    game->supplyCount[i] = 5;
  }
  c = 0;
  truth = 0;
  while(c != 500){
    r = rand();
    j = r % total;
    for(i = 0; i < j; i++){
      r = rand();
      k = r % total;
      while(game->supplyCount[k] == 0){
        k++;
        if(k == total){
          k = 0;
        }
      }
      game->supplyCount[k] = 0;
    }
    if(j>= 3){
      if(isGameOver(game) != 1){
        printf("isGameOver() test:  FAILED 6a - Game over\n");
        printf("Game should be over.\tNumber of cards:  %d\n", j);
        truth++;
      }
    }
    else{
        if(isGameOver(game) != 0){
        printf("isGameOver() test:  FAILED 6b - Game over\n");
        printf("\tNumber of cards:  %d\n", j);
        printf("\tProvince supplyCount:  %d\n", game->supplyCount[province]);
        truth++;
      }
    }
    c++;
    for (i = 0; i <= total; i++){
      game->supplyCount[i] = 5;
    }
  }
  if(truth == 0){
    printf("isGameOver() test:  PASSED 6 - random number test\n");
  }
  else{
    printf("isGameOver() test failed random %d times.\n", truth);
  }



}

int main(int argc, char **argv){

	printf("This is the tests for the isGameOver() function.\n");
	
	test();

	return 0;
}


/*
int isGameOver(struct gameState *state) {
  int i;
  int j;
  
  //if stack of Province cards is empty, the game ends
  if (state->supplyCount[province] == 0)
    {
      return 1;
    }

  //if three supply pile are at 0, the game ends
  j = 0;
  for (i = 0; i < 25; i++){
    if (state->supplyCount[i] == 0){
      j++;
    }
  }
  
  if ( j >= 3){
    return 1;
  }

  return 0;
}
*/
