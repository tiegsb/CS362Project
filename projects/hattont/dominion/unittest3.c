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


int checkShuffle(int player, struct gameState *post){
  struct gameState pre;
  memcpy (&pre, post, sizeof(struct gameState));

  int r;

  r = shuffle(player, post);

  assert(post->deckCount[player]==pre.deckCount[player]);
  return 0;
}

int main () {

  int i, n, p;

  struct gameState G;

  printf ("Testing Shuffle.\n");

  SelectStream(2);
  PutSeed(3);

  for (n = 0; n < 2000; n++) {
    for (i = 0; i < sizeof(struct gameState); i++) {
      ((char*)&G)[i] = floor(Random() * 256);
    }
    G.numPlayers = floor(Random() * 5);
    p = floor(Random() * G.numPlayers);
    G.playedCards[p] = floor(Random() * MAX_HAND);
    G.playedCardCount = floor(Random() * MAX_DECK);
    G.deckCount[p] = floor(Random() * MAX_DECK);
    G.discardCount[p] = floor(Random() * MAX_DECK);
    G.handCount[p] = floor(Random() * MAX_HAND);
    checkShuffle(p, &G);
  }

  printf ("ALL TESTS OK\n");

  return 0;
}
