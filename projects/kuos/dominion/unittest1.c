/******************************************************************************
unittest1.c
Sharon Kuo (kuos@oregonstate.edu)
CS362-400: Assignment 3
Description: Unit testing for the getCost() function in dominion.c.
  Testing each possibility in the switch case in getCost(), as well as
  out-of-bounds values, negative values, and large numbers.
******************************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>

void test_getCost() {
  int passing = 1;

  printf("************\nTESTING getCost():\n************\n");
  // getCost() is just switch statements, so test all cases

  if (getCost(curse) != 0) {
    printf("FAIL: getCost(curse) expected is 0; actual value is %d\n",
      getCost(curse));
    passing = 0;
  }
  else
    printf("PASS: getCost(curse) expected is 0; actual value is %d\n",
      getCost(curse));

  if (getCost(estate) != 2) {
    printf("FAIL: getCost(estate) expected is 2; actual value is %d\n",
      getCost(estate));
    passing = 0;
  }
  else
    printf("PASS: getCost(estate) expected is 2; actual value is %d\n",
      getCost(estate));

  if (getCost(duchy) != 5) {
    printf("FAIL: getCost(duchy) expected is 5; actual value is %d\n",
      getCost(duchy));
    passing = 0;
  }
  else
    printf("PASS: getCost(duchy) expected is 5; actual value is %d\n",
      getCost(duchy));

  if (getCost(province) != 8) {
    printf("FAIL: getCost(province) expected is 8; actual value is %d\n",
      getCost(province));
    passing = 0;
  }
  else
    printf("PASS: getCost(province) expected is 8; actual value is %d\n",
      getCost(province));

  if (getCost(copper) != 0) {
    printf("FAIL: getCost(copper) expected is 0; actual value is %d\n",
      getCost(copper));
    passing = 0;
  }
  else
    printf("PASS: getCost(copper) expected is 0; actual value is %d\n",
      getCost(copper));

  if (getCost(silver) != 3) {
    printf("FAIL: getCost(silver) expected is 3; actual value is %d\n",
      getCost(silver));
    passing = 0;
  }
  else
    printf("PASS: getCost(silver) expected is 3; actual value is %d\n",
      getCost(silver));

  if (getCost(gold) != 6) {
    printf("FAIL: getCost(gold) expected is 6; actual value is %d\n",
      getCost(gold));
    passing = 0;
  }
  else
    printf("PASS: getCost(gold) expected is 6; actual value is %d\n",
      getCost(gold));

  if (getCost(adventurer) != 6) {
    printf("FAIL: getCost(adventurer) expected is 6; actual value is %d\n",
      getCost(adventurer));
    passing = 0;
  }
  else
    printf("PASS: getCost(adventurer) expected is 6; actual value is %d\n",
      getCost(adventurer));

  if (getCost(council_room) != 5) {
    printf("FAIL: getCost(council_room) expected is 5; actual value is %d\n",
      getCost(council_room));
    passing = 0;
  }
  else
    printf("PASS: getCost(council_room) expected is 5; actual value is %d\n",
      getCost(council_room));

  if (getCost(feast) != 4) {
    printf("FAIL: getCost(feast) expected is 4; actual value is %d\n",
      getCost(feast));
    passing = 0;
  }
  else
    printf("PASS: getCost(feast) expected is 4; actual value is %d\n",
      getCost(feast));

  if (getCost(gardens) != 4) {
    printf("FAIL: getCost(gardens) expected is 4; actual value is %d\n",
      getCost(gardens));
    passing = 0;
  }
  else
    printf("PASS: getCost(gardens) expected is 4; actual value is %d\n",
      getCost(gardens));

  if (getCost(mine) != 5) {
    printf("FAIL: getCost(mine) expected is 5; actual value is %d\n",
      getCost(mine));
    passing = 0;
  }
  else
    printf("PASS: getCost(mine) expected is 5; actual value is %d\n",
      getCost(mine));

  if (getCost(remodel) != 4) {
    printf("FAIL: getCost(remodel) expected is 4; actual value is %d\n",
      getCost(remodel));
    passing = 0;
  }
  else
    printf("PASS: getCost(remodel) expected is 4; actual value is %d\n",
      getCost(remodel));

  if (getCost(smithy) != 4) {
    printf("FAIL: getCost(smithy) expected is 4; actual value is %d\n",
      getCost(smithy));
    passing = 0;
  }
  else
    printf("PASS: getCost(smithy) expected is 4; actual value is %d\n",
      getCost(smithy));

  if (getCost(village) != 3) {
    printf("FAIL: getCost(village) expected is 3; actual value is %d\n",
      getCost(village));
    passing = 0;
  }
  else
    printf("PASS: getCost(village) expected is 3; actual value is %d\n",
      getCost(village));

  if (getCost(baron) != 4) {
    printf("FAIL: getCost(baron) expected is 4; actual value is %d\n",
      getCost(baron));
    passing = 0;
  }
  else
    printf("PASS: getCost(baron) expected is 4; actual value is %d\n",
      getCost(baron));

  if (getCost(great_hall) != 3) {
    printf("FAIL: getCost(great_hall) expected is 3; actual value is %d\n",
      getCost(great_hall));
    passing = 0;
  }
  else
    printf("PASS: getCost(great_hall) expected is 3; actual value is %d\n",
      getCost(great_hall));

  if (getCost(minion) != 5) {
    printf("FAIL: getCost(minion) expected is 5; actual value is %d\n",
      getCost(minion));
    passing = 0;
  }
  else
    printf("PASS: getCost(minion) expected is 5; actual value is %d\n",
      getCost(minion));

  if (getCost(steward) != 3) {
    printf("FAIL: getCost(steward) expected is 3; actual value is %d\n",
      getCost(steward));
    passing = 0;
  }
  else
    printf("PASS: getCost(steward) expected is 3; actual value is %d\n",
      getCost(steward));

  if (getCost(tribute) != 5) {
    printf("FAIL: getCost(tribute) expected is 5; actual value is %d\n",
      getCost(tribute));
    passing = 0;
  }
  else
    printf("PASS: getCost(tribute) expected is 5; actual value is %d\n",
      getCost(tribute));

  if (getCost(ambassador) != 3) {
    printf("FAIL: getCost(ambassador) expected is 3; actual value is %d\n",
      getCost(ambassador));
    passing = 0;
  }
  else
    printf("PASS: getCost(ambassador) expected is 3; actual value is %d\n",
      getCost(ambassador));

  if (getCost(cutpurse) != 4) {
    printf("FAIL: getCost(cutpurse) expected is 4; actual value is %d\n",
      getCost(cutpurse));
    passing = 0;
  }
  else
    printf("PASS: getCost(cutpurse) expected is 4; actual value is %d\n",
      getCost(cutpurse));

  if (getCost(embargo) != 2) {
    printf("FAIL: getCost(embargo) expected is 2; actual value is %d\n",
      getCost(embargo));
    passing = 0;
  }
  else
    printf("PASS: getCost(embargo) expected is 2; actual value is %d\n",
      getCost(embargo));

  if (getCost(outpost) != 5) {
    printf("FAIL: getCost(outpost) expected is 5; actual value is %d\n",
      getCost(outpost));
    passing = 0;
  }
  else
    printf("PASS: getCost(outpost) expected is 5; actual value is %d\n",
      getCost(outpost));

  if (getCost(salvager) != 4) {
    printf("FAIL: getCost(salvager) expected is 4; actual value is %d\n",
      getCost(salvager));
    passing = 0;
  }
  else
    printf("PASS: getCost(salvager) expected is 4; actual value is %d\n",
      getCost(salvager));

  if (getCost(sea_hag) != 4) {
    printf("FAIL: getCost(sea_hag) expected is 4; actual value is %d\n",
      getCost(sea_hag));
    passing = 0;
  }
  else
    printf("PASS: getCost(sea_hag) expected is 4; actual value is %d\n",
      getCost(sea_hag));

  if (getCost(treasure_map) != 4) {
    printf("FAIL: getCost(treasure_map) expected is 4; actual value is %d\n",
      getCost(treasure_map));
    passing = 0;
  }
  else
    printf("PASS: getCost(treasure_map) expected is 4; actual value is %d\n",
      getCost(treasure_map));

  if (getCost(-1) != -1) {
    printf("FAIL: getCost(-1) expected is -1: actual value is %d\n",
      getCost(-1));
    passing = 0;
  }
  else
    printf("PASS: getCost(-1) expected is -1; actual value is %d\n",
      getCost(-1));

  if (getCost(27) != -1) {
    printf("FAIL: getCost(27) expected is -1: actual value is %d\n",
      getCost(27));
    passing = 0;
  }
  else
    printf("PASS: getCost(27) expected is -1; actual value is %d\n",
      getCost(27));

  if (getCost(10000) != -1) {
    printf("FAIL: getCost(10000) expected is -1: actual value is %d\n",
      getCost(10000));
    passing = 0;
  }
  else
    printf("PASS: getCost(10000) expected is -1; actual value is %d\n",
      getCost(10000));

  // if all tests passed
  printf("\n");
  if (passing)
    printf("PASS: all values for getCost() passed\n");
  else
    printf("FAIL: one or more values for getCost() failed\n");
}

int main() {
  test_getCost();
  return 0;
}
