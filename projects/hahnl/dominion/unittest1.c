/*****************************************
Author: Larissa Hahn
unittest1.c - updateCoins()
*****************************************/
#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <string.h>
#include "rngs.h"
#include <assert.h>
#include <time.h>
#define NOISY_TEST 0

int main (int argc, char** argv) {
  //Seed random
  srand(time(NULL));

  //Initalize variables
  struct gameState g;
  int newGame;
  int test, total, bonus, i, count;

  int k[10] = {
    smithy,
    adventurer,
    village,
    great_hall,
    council_room,
    gardens,
    feast,
    mine,
    embargo,
    tribute
  };

  //Initialize game
  memset(&g, 23, sizeof(struct gameState));
  newGame = initializeGame(2, k, 1000, &g);
  g.handCount[0] = 5;
  assert(newGame == 0);

  //Tests begin
  printf("\n\nunittest1.c - Test for updateCoins() function:\n\n");

  for(count=0;count<1000;count++){
    bonus = rand()%10;
    total = 0;
    total += bonus;

    for(i=0;i<8;i++){
      g.hand[0][i] = rand()%26+1;

      if (g.hand[0][i] == 4) {
        total+=1;
      }

      if(g.hand[0][i] == 5){
        total+=2;
      }

      if(g.hand[0][i] == 6){
        total+=3;
      }
    }
    test = updateCoins(0, &g, bonus);
    assert(test == 0);

  }
  printf("All tests passed.\n");

  return 0;
}
