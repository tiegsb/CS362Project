//this tests updateCoins

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dominion.h"
#include "assert.h"
#include "unittest3.h"


//prototype for updateCoins from dominion.c, as it was not declared in dominion.h
int updateCoins(int player, struct gameState *state, int bonus);


//tests to see if the updateCoins function is working. sends in predfined numbers of each type of card (defined in the tests below)
//and the message about the test
int testUpdateCoins( int numGold, int numSilver, int numCopper, int numOther, int numBonus, const char* message)
{
  int thiscount = (3*numGold) + (2*numSilver) + (numCopper) + numBonus;

  int slot = 0;
  int i = 0;
  struct gameState state;
  memset(&state, 0, sizeof(struct gameState));


  //propogate hand with correct number of each card
  for (i = 0 ; i<numGold; ++i)
  {
    state.hand[0][slot++] = gold;
  }
  for (i = 0 ; i<numSilver; ++i)
  {
    state.hand[0][slot++] = silver;
  }
  for (i = 0 ; i<numCopper; ++i)
  {
    state.hand[0][slot++] = copper;
  }
  for (i = 0 ; i<numOther; ++i)
  {
    state.hand[0][slot++] = estate;
  }

  //propogate numcards
  state.handCount[0] = slot;

  updateCoins( 0, &state, numBonus);



  //test to make sure the coins are the same
  return assert(thiscount == state.coins, "updateCoins()", message);

}


//call tests of testUpdateCoins, the order of coins is: gold, silver,copper, other (no coin value) and bonus
int unitTest3()
{
  int failcount = 0 ;

  failcount += testUpdateCoins(0,0,0,0,0, "should return 0 if the player's hand has no coins and no bonus");
  failcount += testUpdateCoins(0,0,0,3,0, "should return 0 if the player's hand has no coins and 3 other cards");
  failcount += testUpdateCoins(3,0,0,0,0, "should return 9 if the player's had has 3 gold");
  failcount += testUpdateCoins(3,0,0,0,0, "should return 9 if the player's had has 3 gold");
  failcount += testUpdateCoins(0,3,0,0,0, "should return 6 if the player's had has 3 silver");
  failcount += testUpdateCoins(0,0,3,0,0, "should return 3 if the player's had has 3 copper");
  failcount += testUpdateCoins(0,0,0,0,3, "should return 9 if the player's had has 3 bonus");
  
  return failcount;
}



