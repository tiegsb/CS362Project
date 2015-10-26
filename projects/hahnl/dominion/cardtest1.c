/*****************************************
Author: Larissa Hahn
cardtest1.c - smithyCard()
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
  printf("\n\ncardtest1.c - Test for smithyCard() function:\n\n");
  precard = g.handCount[0];
  cardEffect(smithy, 1, 2, 3, &g, handPos, &bonus);
  postcard = g.handCount[0];
  assert(postcard == precard+3);
  assert(g.playedCardCount == 1);
  printf("All tests passed.");

  return 0;
}
