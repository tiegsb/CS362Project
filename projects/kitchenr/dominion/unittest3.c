#include "dominion.h"

/*
 * 
 * Unit test 3
 * 
 * Tests fullDeckCount
 * 
 * Should return the total number of a certain card a player has
 * 
 * 
 */


int main(){
  struct gameState *state=newGame();
  int *kc = kingdomCards(adventurer,council_room,feast,gardens,mine,remodel,smithy,village,baron,great_hall);
  initializeGame(2,kc,1,state);
  
  
  state->deck[0][0] = duchy;
  state->deck[0][1] = province;
  state->deck[0][2] = copper;
  state->deck[0][3] = duchy;
  state->deck[0][4] = province;
  state->deck[0][5] = copper;
  state->deck[0][6] = duchy;
  state->deck[0][7] = province;
  state->deck[0][8] = adventurer;
  state->deck[0][9] = copper;  /// this isn't real, just garbage data in the array
  state->deckCount[0]=9;
  
  
  state->hand[0][0] = copper;
  state->hand[0][1] = copper;
  state->hand[0][2] = copper;
  state->hand[0][3] = silver;
  state->hand[0][4] = smithy;
  state->hand[0][5] = smithy; //fake
  state->handCount[0]=5;
  
  state->discard[0][0] = curse;
  state->discard[0][1] = curse;
  state->discard[0][2] = silver;
  state->discard[0][3] = copper;
  state->discard[0][4] = province; //fake
  state->discardCount[0]=4;
  
  state->playedCards[0]=duchy;
  state->playedCardCount=1;
  
  state->whoseTurn=0;
  
    /* total copper = 6
   * total duchy = 4
   * total province = 3
   * total silver = 2
   * total smithy = 1
   */
  
  state->deck[1][0] = duchy;
  state->deck[1][1] = province;
  state->deck[1][2] = copper;
  state->deck[1][3] = duchy;
  state->deck[1][4] = province;
  state->deck[1][5] = copper;
  state->deck[1][6] = duchy;
  state->deck[1][7] = province;
  state->deck[1][8] = copper;
  state->deckCount[1]=0;
  
  
  state->hand[1][0] = copper;
  state->hand[1][1] = copper;
  state->hand[1][2] = copper;
  state->hand[1][3] = silver;
  state->hand[1][4] = smithy;
  state->handCount[1]=0;
  
  state->discardCount[1]=0;
  
  
    /* total copper = 0
   * total duchy = 0
   * total province = 0
   * total silver = 0
   * total smithy = 0
   */
  

  
  printf("Testing fullDeckCount:\n");
  printf("Player 0:\n");
  printf("Copper = 6: %s\n",(fullDeckCount(0,copper,state)==6)?"YES":"NO");
  printf("Duchy = 4: %s\n",(fullDeckCount(0,duchy,state)==4)?"YES":"NO");
  printf("Province = 3: %s\n",(fullDeckCount(0,province,state)==3)?"YES":"NO");
  printf("Silver = 2: %s\n",(fullDeckCount(0,silver,state)==2)?"YES":"NO");
  printf("smithy = 1: %s\n",(fullDeckCount(0,smithy,state)==1)?"YES":"NO");
  printf("Adventurer = 1: %s\n",(fullDeckCount(0,adventurer,state)==1)?"YES":"NO");
  printf("\n");
  printf("Player 1:\n");
  printf("Copper = 0: %s\n",(fullDeckCount(1,copper,state)==0)?"YES":"NO");
  printf("Duchy = 0: %s\n",(fullDeckCount(1,duchy,state)==0)?"YES":"NO");
  printf("Province = 0: %s\n",(fullDeckCount(1,province,state)==0)?"YES":"NO");
  printf("Silver = 0: %s\n",(fullDeckCount(1,silver,state)==0)?"YES":"NO");
  printf("smithy = 0: %s\n",(fullDeckCount(1,smithy,state)==0)?"YES":"NO");
  printf("Adventurer = 0: %s\n",(fullDeckCount(1,adventurer,state)==0)?"YES":"NO");
  printf("\n");
  
  
  return 0;
}
