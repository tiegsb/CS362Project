/* compare() test */
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include "dominion_helpers.h"
#include "rngs.h"

static void doTest(char *testName, int condition) {
  printf("TEST %s: ", testName);

  if (condition) {
    printf("PASS\n");
  } else {
    printf("FAIL\n");
  }
}

int main(int argc, char **argv) {
  int a, b;

  /* initialize RNG */
  SelectStream(9);
  PutSeed(37); /* 37 is the most random number */

  a = b = floor(Random() * INT_MAX);
  doTest("equal", a == b);

  a -= floor(Random() * INT_MAX);
  doTest("not equal", a != b);

  return 0;
}