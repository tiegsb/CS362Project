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
#include <time.h>

void testShuffle() {
  struct gameState gs;
  int deckCopy[5];
  int otherDeckCopy[5];
  int player=0;
  int numPlayers=2;
  int handCount=5;
  int randomSeed = rand() % 100 + 1;
  int shuffleVal;
  int count = 0;
  gs.numPlayers= 2;
  int test1[5];
  int test2[5];
  int kingdom[10]= { adventurer, baron, embargo, feast, gardens,
 great_hall, mine, remodel, smithy, tribute };
  int i, r;
  int num1, num2;
  
  //Test shuffle function 5 times
  // Player 0's deck should be shuffled, Player 1's deck should not
  for(r=0; r<5; r++){
    srand(time(NULL));
    for(i=0; i<5; i++){
      num1 = rand() % 27 + 1;
      num2 = rand() % 27 + 1;
      test1[i] = num1;
      test2[i] = num2;
    }


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
  
    shuffleVal = shuffle(player, &gs);
 
    if(shuffleVal == 0)
      printf("Shuffle function ran.\n");
    else
      printf("Shuffle function did not run.\n");
    //assert(shuffleVal == 0);
    int j=0, otherPlayersDeck=0;
    for(i=0; i<handCount; i++){
      //compare player 0's hand before and after shuffle
      if(gs.deck[0][i] == deckCopy[i]){
        j++;
      }
      //compare player 1's hand before and after shuffle
      if(gs.deck[1][i] != otherDeckCopy[i])
        otherPlayersDeck++; 
    }

    printf("Only Player 0's deck should be shuffled.\n");

    if(j<=4){
      printf("Pass: Player 0's deck has been shuffled.\n");
    }else{
      printf("Fail: Player 0's deck has not been shuffled.\n");
      count++;
    }
    //assert(j<=4);
    if(otherPlayersDeck == 0){
      printf("Pass: Player 1's deck has not been shuffled.\n");
    }else{
      printf("Fail: Player 1's deck has been shuffled.\n");
      count++;
    }
  }



    //assert(otherPlayersDeck == 0);
    if(count == 0)
      printf("All Shuffle tests passed!\n");
    else
      printf("%d tests failed\n", count);

}

int main(){
  testShuffle();
  return 0;
}

