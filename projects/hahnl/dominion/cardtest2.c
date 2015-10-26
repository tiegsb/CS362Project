/*****************************************
Author: Larissa Hahn
cardtest2.c - adventurerCard()
*****************************************/
#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <string.h>
#include "rngs.h"
#include <assert.h>
#define NOISY_TEST 0

int main (int argc, char** argv) {
  //Initialize variables
  struct gameState g;
  int newGame;
  int precard, postcard;
  int handPos = 0;
  int bonus = 0;
  int i = 0;
  int pretotal = 0;
  int posttotal = 0;
  int predisc = 0;
  int postdisc = 0;

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

  //Initalize game
  memset(&g, 23, sizeof(struct gameState));
  newGame = initializeGame(2, k, 1000, &g);
  g.handCount[0] = 5;

  //Tests begin
  printf("\n\ncardtest2.c - Test for adventurerCard() function:\n\n");
  precard = g.handCount[0];
  predisc = g.discardCount[0];
  for (i=0; i<g.handCount[0];i++){
    if (g.handCount[0][i] == copper){
      pretotal += 1;
    }

    if (g.handCount[0][i] == silver){
      pretotal += 2;
    }

    if (g.handCount[0][i] == gold){
      pretotal += 3;
    }
  }

  cardEffect(&g, handPos, &bonus, adventurer, 1, 2, 3);

  postcard = g.handCount[0];
  postdisc = g.discardCount[0];
  for (i=0; i<g.handCount[0];i++){
    if (g.handCount[0][i] == copper){
      posttotal += 1;
    }

    if (g.handCount[0][i] == silver){
      posttotal += 2;
    }

    if (g.handCount[0][i] == gold){
      posttotal += 3;
    }
  }
  assert(postcard == precard+2);
  assert(postdisc == predisc+1);
  assert(posttotal > pretotal);
  printf("All tests passed.");

  return 0;
}
