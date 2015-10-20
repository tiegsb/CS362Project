/* Rachael McConnell
 * CS362 Fall 2015
 * Unit Test 1: Shuffle
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

void testShuffle() {
  struct gameState gs;
  int deckCopy[5];
  int otherDeckCopy[5];
  int player=0;
  int numPlayers=2;
  int handCount=5;
  int randomSeed = rand() % 100 + 1;
  int shuffleVal;
  gs.numPlayers= 2;
  int test1[5] = { smithy, adventurer, estate, silver, copper };
  int test2[5] = { copper, gold, gold, duchy, copper };
  int kingdom[10]= { adventurer, baron, embargo, feast, gardens,
 great_hall, mine, remodel, smithy, tribute };
 
  memset(&gs, 23, sizeof(struct gameState));
  initializeGame(numPlayers, kingdom, randomSeed, &gs);
  memcpy(gs.deck[0], test1, sizeof(int)*handCount);
  memcpy(gs.deck[1], test2, sizeof(int)*handCount);
  gs.handCount[0]=5;
  gs.handCount[1]=5;  

  /*assign copies*/
  deckCopy[0] = gs.deck[0][0];
  deckCopy[1] = gs.deck[0][1];
  deckCopy[2] = gs.deck[0][2];
  deckCopy[3] = gs.deck[0][3];
  deckCopy[4] = gs.deck[0][4];

  otherDeckCopy[0] = gs.deck[1][0];
  otherDeckCopy[1] = gs.deck[1][1];
  otherDeckCopy[2] = gs.deck[1][2];
  otherDeckCopy[3] = gs.deck[1][3];
  otherDeckCopy[4] = gs.deck[1][4];
  
  printf("Player 0 before shuffle: %d, %d, %d, %d, %d\n", gs.deck[0][0], gs.deck[0][1], gs.deck[0][2], gs.deck[0][3], gs.deck[0][4]);
  printf("Player 1 before shuffle: %d, %d, %d, %d, %d\n", gs.deck[1][0], gs.deck[1][1], gs.deck[1][2], gs.deck[1][3], gs.deck[1][4]);

  shuffleVal = shuffle(player, &gs);
 
  printf("Player 0 after shuffle: %d, %d, %d, %d, %d\n", gs.deck[0][0], gs.deck[0][1], gs.deck[0][2], gs.deck[0][3], gs.deck[0][4]);
  printf("Player 1 after shuffle: %d, %d, %d, %d, %d\n", gs.deck[1][0], gs.deck[1][1], gs.deck[1][2], gs.deck[1][3], gs.deck[1][4]);
  //assert that the shuffle function ran through and returned
  assert(shuffleVal == 0);
  int j=0, i=0, otherPlayersDeck=0;
  for(i=0; i<handCount; i++){
    if(gs.deck[0][i] == deckCopy[i]){
      j++;
    }
    if(gs.deck[1][i] != otherDeckCopy[i])
      otherPlayersDeck++;
   
  }
  assert(j<=4);
  assert(otherPlayersDeck == 0);
  printf("All Shuffle tests passed!\n");
}

int main(){
  testShuffle();
  return 0;
}

