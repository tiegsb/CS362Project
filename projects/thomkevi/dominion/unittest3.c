/* -----------------------------------------------------------------------
 * Unit test for dominion-base getCost function
 * Include the following lines in your makefile:
 *
 * unittest3: unittest3.c dominion.c rngs.c
 *      gcc -o unittest3 unittest3.c dominion.c rngs.c $(CFLAGS)
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>

int main() {

  int r;
  printf ("TESTING getCost():\n");
  
  r = getCost(curse);
  printf("cost curse = %d, expected = %d\n", r, 0);
  assert(r == 0);
  r = getCost(estate);
  printf("cost estate = %d, expected = %d\n", r, 2);
  assert(r == 2);
  r = getCost(duchy);
  printf("cost duchy = %d, expected = %d\n", r, 5);
  assert(r == 5);
  r = getCost(province);
  printf("cost province = %d, expected = %d\n", r, 8);
  assert(r == 8);
  r = getCost(copper);
  printf("cost copper = %d, expected = %d\n", r, 0);
  assert(r == 0);
  r = getCost(silver);
  printf("cost silver = %d, expected = %d\n", r, 3);
  assert(r == 3);
  r = getCost(gold);
  printf("cost gold = %d, expected = %d\n", r, 6);
  assert(r == 6);
  r = getCost(adventurer);
  printf("cost adventurer = %d, expected = %d\n", r, 6);
  assert(r == 6);
  r = getCost(council_room);
  printf("cost council_room = %d, expected = %d\n", r, 5);
  assert(r == 5);
  r = getCost(feast);
  printf("cost feast = %d, expected = %d\n", r, 4);
  assert(r == 4);
  r = getCost(gardens);
  printf("cost gardens = %d, expected = %d\n", r, 4);
  assert(r == 4);
  r = getCost(mine);
  printf("cost mine = %d, expected = %d\n", r, 5);
  assert(r == 5);
  r = getCost(remodel);
  printf("cost remodel = %d, expected = %d\n", r, 4);
  assert(r == 4);
  r = getCost(smithy);
  printf("cost smithy = %d, expected = %d\n", r, 4);
  assert(r == 4);
  r = getCost(village);
  printf("cost village = %d, expected = %d\n", r, 3);
  assert(r == 3);
  r = getCost(baron);
  printf("cost baron = %d, expected = %d\n", r, 4);
  assert(r == 4);
  r = getCost(great_hall);
  printf("cost great_hall = %d, expected = %d\n", r, 3);
  assert(r == 3);
  r = getCost(minion);
  printf("cost minion = %d, expected = %d\n", r, 5);
  assert(r == 5);
  r = getCost(steward);
  printf("cost steward = %d, expected = %d\n", r, 3);
  assert(r == 3);
  r = getCost(tribute);
  printf("cost tribute = %d, expected = %d\n", r, 5);
  assert(r == 5);
  r = getCost(ambassador);
  printf("cost ambassador = %d, expected = %d\n", r, 3);
  assert(r == 3);
  r = getCost(cutpurse);
  printf("cost cutpurse = %d, expected = %d\n", r, 4);
  assert(r == 4);
  r = getCost(embargo );
  printf("cost embargo  = %d, expected = %d\n", r, 2);
  assert(r == 2);
  r = getCost(outpost);
  printf("cost outpost = %d, expected = %d\n", r, 5);
  assert(r == 5);
  r = getCost(salvager);
  printf("cost salvager = %d, expected = %d\n", r, 4);
  assert(r == 4);
  r = getCost(sea_hag);
  printf("cost sea_hag = %d, expected = %d\n", r, 4);
  assert(r == 4);
  r = getCost(treasure_map);
  printf("cost treasure_map = %d, expected = %d\n", r, 4);
  assert(r == 4);

  printf("All tests passed!\n");

  return 0;

}