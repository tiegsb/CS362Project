#include "dominion.h"



/*
 * 
 * Unit test 4
 * 
 * tests endTurn
 * 
 * End of turn, should do the following:
 * Put played cards in player's discard pile
 * Put player's hand in discard pile
 * Draw a new hand for player
 * Check for winning conditions
 * If game is not over, advance player
 * 
 * 
 */



int main(){
  
  
  
  struct gameState *state=newGame();
  int *kc = kingdomCards(adventurer,council_room,feast,gardens,mine,remodel,smithy,village,baron,great_hall);
  initializeGame(2,kc,1,state);
  
  /*
   * 
   * Test simple, no cards played, situation
   */
  
  int hand[2][5];
  for(int i=0;i<5;i++){
    hand[0][i]=state->hand[0][i];
    hand[1][i]=state->hand[1][i];
  }
  
  printf("Turn is %d\n",state->whoseTurn);
  printf("Player 0 has hand? %s\n",(state->handCount[0]==5)?"YES":"NO");
  printf("Player 1 has hand? %s\n",(state->handCount[1]==5)?"YES":"NO");
  printf("Ending turn\n");
  
  endTurn(state);
  printf("Turn is now 1? %s\n",(state->whoseTurn==1)?"YES":"NO");
  int same=0;
  for(int i=0;i<5;i++){
    if(hand[0][i]==state->hand[0][i]) same++;
    hand[0][i]=state->hand[0][i];
  }
  printf("Player 0 has hand? %s\n",(state->handCount[0]==5)?"YES":"NO");
  printf("Player 0's hand changed? %s\n",(same!=5)?"YES":"NO");
  same=0;
  for(int i=0;i<5;i++){
    if(hand[1][i]==state->hand[1][i]) same++;
    hand[1][i]=state->hand[1][i];
  }
  printf("Player 1 has hand? %s\n",(state->handCount[1]==5)?"YES":"NO");
  printf("Player 1's hand changed? %s\n",(same!=5)?"YES":"NO");
  printf("Ending turn\n");
  endTurn(state);
  printf("Turn is now 0? %s\n",(state->whoseTurn==0)?"YES":"NO");
  for(int i=0;i<5;i++){
    if(hand[0][i]==state->hand[0][i]) same++;
    hand[0][i]=state->hand[0][i];
  }
  printf("Player 0 has hand? %s\n",(state->handCount[0]==5)?"YES":"NO");
  printf("Player 0's hand changed? %s\n",(same!=5)?"YES":"NO");
  same=0;
  for(int i=0;i<5;i++){
    if(hand[1][i]==state->hand[1][i]) same++;
    hand[1][i]=state->hand[1][i];
  }
  printf("Player 1 has hand? %s\n",(state->handCount[1]==5)?"YES":"NO");
  printf("Player 1's hand changed? %s\n",(same!=5)?"YES":"NO");
  
  
  /*
   * Test with cards played
   * 
   */
  
  printf("Played card \"adventurer\"\n");
  
  state->playedCards[0]=adventurer;
  state->playedCardCount=1;
  printf("Ending turn\n");
  endTurn(state);
  printf("Turn is 1? %s\n",(state->whoseTurn==1)?"YES":"NO");
  printf("playedCards reset? %s\n",(state->playedCardCount==0)?"YES":"NO");
  printf("adventurer in player 0's deck,hand,or discard pile? %s\n",(fullDeckCount(0,adventurer,state)==1)?"YES":"NO");
  
  
  
  /*
   * 
   * Test for end of game behavior
   * 
   */
  
  state->supplyCount[province]=0;
  printf("Provinces set to 0\n");
  printf("Ending turn..\n");
  endTurn(state);
  printf("Turn is still 1? %s\n",(state->whoseTurn==1)?"YES":"NO");
  
  
  
  
  return 0;
}