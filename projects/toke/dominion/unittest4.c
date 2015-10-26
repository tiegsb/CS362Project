//#############################################
// Filename: unittest4.c
// Unit Test Objective: Tests the getCost method
//                      in dominion.c
//#############################################

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>

#define DEBUG 0
#define NOISY_TEST 1

void checkGetCost(int expectedCost, int cardNumber) {
  int actualCost;

  actualCost = getCost (cardNumber);

  if (expectedCost != actualCost)
  {
    printf("Test Failed: Expected cost was %d. Actual cost was %d for card %d\n", expectedCost, actualCost, cardNumber);
  }
  else
  {
    printf("Test Passed: Expected cost was %d. Actual cost was %d for card %d\n", expectedCost, actualCost, cardNumber);
  }
}

int main () {

  printf ("Unit Testing: getCost().\n");

  // Check the cost of a negative number
  printf("Testing...Getting cost of a non-existant negative number card\n");
  checkGetCost(-1, -1);

  // Check the cost of a big number
  printf("Testing...Getting cost of a card that does not exist and has a positive card number\n");
  checkGetCost(-1, 100);

  // Check the cost of all the cards
  printf("Testing...The cost of all the available cards\n");
  checkGetCost(0, curse);
  checkGetCost(2, estate);
  checkGetCost(5, duchy);
  checkGetCost(8, province);
  checkGetCost(0, copper);
  checkGetCost(3, silver);
  checkGetCost(6, gold);
  checkGetCost(6, adventurer);
  checkGetCost(5, council_room);
  checkGetCost(4, feast);
  checkGetCost(4, gardens);
  checkGetCost(5, mine);
  checkGetCost(4, remodel);
  checkGetCost(4, smithy);
  checkGetCost(3, village);
  checkGetCost(4, baron);
  checkGetCost(3, great_hall);
  checkGetCost(5, minion);
  checkGetCost(3, steward);
  checkGetCost(5, tribute);
  checkGetCost(3, ambassador);
  checkGetCost(4, cutpurse);
  checkGetCost(2, embargo);
  checkGetCost(5, outpost);
  checkGetCost(4, salvager);
  checkGetCost(4, sea_hag);
  checkGetCost(4, treasure_map);
  
  return 0;
}
