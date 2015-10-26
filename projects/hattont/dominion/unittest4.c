#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

#define DEBUG 0
#define NOISY_TEST 1

int checkUpdateCoins(int player, struct gameState *post, int bonus) {
        struct gameState pre;
        memcpy (&pre, post, sizeof(struct gameState));

        int r, i;

        r = updateCoins(player, post, bonus);

        pre.coins = 0;

        for (i = 0; i < pre.handCount[player]; i++)
  {
                if (pre.hand[player][i] == copper) pre.coins += 1;
    else if (pre.hand[player][i] == silver) pre.coins += 2;
    else if (pre.hand[player][i] == gold) pre.coins += 3;
  }
  pre.coins += bonus;

  assert (r == 0);
  assert(memcmp(&pre, post, sizeof(struct gameState)) == 0);

  return 0;
}

int main () {

  int i, n, j, p;

  struct gameState G;

  printf ("Testing updateCoins\n");

  SelectStream(2);
  PutSeed(3);

  for (n = 0; n < 2000; n++) {
    for (i = 0; i < sizeof(struct gameState); i++) {
      ((char*)&G)[i] = floor(Random() * 256);
    }
    G.numPlayers = floor(Random() * 5);
    p = floor(Random() * G.numPlayers);
    G.deckCount[p] = floor(Random() * MAX_DECK);
    G.discardCount[p] = floor(Random() * MAX_DECK);
    G.handCount[p] = floor(Random() * MAX_HAND);
    for(j=0;j<G.handCount[p];j++){
        G.hand[p][j] = floor(Random() * 26);
    }
    checkUpdateCoins(p, &G, 0);
  }

  printf ("ALL TESTS OK\n");

  return 0;
}
