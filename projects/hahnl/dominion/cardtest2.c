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
#include <stdlib.h>
#define NOISY_TEST 0

int main (int argc, char** argv) {
  //Initialize variables
  struct gameState g;
  int newGame;
  int precard, postcard;
  int drawntreasure = 0;
  int temphand[MAX_HAND];
  int z = 0;
  int cardDrawn = 0;
  int currentPlayer = 0;
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
  adventurerCard(drawntreasure, &g, currentPlayer, cardDrawn, temphand, z);
  postcard = g.handCount[0];
  postdisc = g.discardCount[0];
  //assert(postcard == precard+2);
  //assert(postdisc == predisc+1);
  //printf("All tests passed.");

  return 0;
}
