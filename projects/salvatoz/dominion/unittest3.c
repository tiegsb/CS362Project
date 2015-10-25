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
  doTest("equal", compare(&a, &b) == 0);

  a -= floor(Random() * INT_MAX);
  doTest("a less", compare(&a, &b) == -1);

  b = a - floor(Random() * INT_MAX / 2);
  doTest("b less", compare(&a, &b) == 1);

  return 0;
}