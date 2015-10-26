/* isGameOver test */
#include <stdio.h>
#include "dominion.h"
#include "cards.h"

static void doTest(char *testName, int condition) {
  printf("TEST %s:  ", testName);

  if (condition) {
    printf("PASS\n");
  } else {
    printf("FAIL\n");
  }
}

int main(int argc, char **argv) {
  int i;
  struct gameState G;

  // test empty Province stack
  G.supplyCount[province] = 0;
  doTest("empty province stack", isGameOver(&G) == 1);

  // test non-empty Province stack
  for (i = 0; i < treasure_map + 1; i++)
    G.supplyCount[i] = 1;
  doTest("no empty piles", isGameOver(&G) == 0);

  // test three empty supply pile
  for (i = 0; i < 3; i++)
    G.supplyCount[i] = 0;
  doTest("three empty piles", isGameOver(&G) == 1);

  return 0;
}