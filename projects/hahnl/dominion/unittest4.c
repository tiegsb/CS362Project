/*****************************************
Author: Larissa Hahn
unittest4.c - getCost()
*****************************************/
#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <string.h>
#include "rngs.h"
#include <assert.h>
#define NOISY_TEST 0

int main (int argc, char** argv) {
  //Initalize variable
  int cost;

  //Tests begin
  printf("\n\nunittest4.c - Test for getCost() function:\n\n");
  cost = getCost(curse);
  assert(cost == 0);
  cost = getCost(estate);
  assert(cost == 2);
  cost = getCost(duchy);
  assert(cost == 5);
  cost = getCost(province);
  assert(cost == 8);
  cost = getCost(copper);
  assert(cost == 0);
  cost = getCost(silver);
  assert(cost == 3);
  cost = getCost(gold);
  assert(cost == 6);
  cost = getCost(adventurer);
  assert(cost == 6);
  cost = getCost(council_room);
  assert(cost == 5);
  cost = getCost(feast);
  assert(cost == 4);
  cost = getCost(gardens);
  assert(cost == 4);
  cost = getCost(mine);
  assert(cost == 5);
  cost = getCost(remodel);
  assert(cost == 4);
  cost = getCost(smithy);
  assert(cost == 4);
  cost = getCost(village);
  assert(cost == 3);
  cost = getCost(baron);
  assert(cost == 4);
  cost = getCost(great_hall);
  assert(cost == 3);
  cost = getCost(minion);
  assert(cost == 5);
  cost = getCost(steward);
  assert(cost == 3);
  cost = getCost(tribute);
  assert(cost == 5);
  cost = getCost(ambassador);
  assert(cost == 3);
  cost = getCost(cutpurse);
  assert(cost == 4);
  cost = getCost(embargo);
  assert(cost == 2);
  cost = getCost(outpost);
  assert(cost == 5);
  cost = getCost(salvager);
  assert(cost == 4);
  cost = getCost(sea_hag);
  assert(cost == 4);
  cost = getCost(treasure_map);
  assert(cost == 4);
  printf("\nAll cards pass.\n");
  cost = getCost(28); // Not a card
  assert(cost == -1);
  cost = getCost(-40); // Not a card
  assert(cost == -1);
  printf("\nAll tests pass with expected results.\n");

  return 0;
}
