/*****************************************
Author: Larissa Hahn
cardtest3.c - villageCard()
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
  int handPos = 0;
  int bonus = 0;
  int precard, postcard, predisc, postdisc;

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
  printf("\n\ncardtest3.c - Test for villageCard() function:\n\n");
  precard = g.handCount[0];
  predisc = g.discardCount[0];
  cardEffect(village, 1, 2, 3, &g, handPos, &bonus);
  postcard = g.handCount[0];
  postdisc = g.discardCount[0];
  //assert(postcard == precard+1);
  //assert(postdisc == predisc+1);
  //printf("All tests passed.\n");

  return 0;
}
