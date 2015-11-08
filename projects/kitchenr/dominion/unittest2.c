#include "dominion.h"


/* 
 * 
 * Unit test 2
 * 
 * Tests buyCard
 * 
 * Expected results:
 * 
 * should check if player is eligible to buy
 * should check if coins is enough to pay for card
 * remove 1 from supply if availiable, if not return error
 * add card to current player's discard pile only
 * if card is the last one of the deck, should check for end game conditions
 * should reduce number of buys by 1
 */


int main(){
  struct gameState *state=newGame();
  int *kc = kingdomCards(adventurer,council_room,feast,gardens,mine,remodel,smithy,village,baron,great_hall);
  initializeGame(2,kc,1,state);
  
  if(state->numBuys!=1) printf("Error: starting number of buys invalid\n");
  state->coins = 3;
  
  printf("Coins set to 3\n");
  
  
  printf("Buying adventurer (cost 6), should FAIL: %s\n",(buyCard(adventurer,state))?"FAILED":"PASSED");
  printf("Coins set to 6\n");
  state->coins=6;
  printf("Buying adventurer, should SUCCEED: %s\n", (buyCard(adventurer,state))?"FAILED":"PASSED");
  
  printf("Player 0's discard pile should have increased by one:%s\n",(state->discardCount[0] == 1)?"YES":"NO");
  printf("Player 1's discard pile should still be empty:%s\n",(state->discardCount[1] == 0)?"YES":"NO");
  printf("Player 0's discard pile should have adventurer on top:%s\n",(state->discard[0][0]==adventurer)?"YES":"NO");
  printf("Player 1's discard pile should not have adventurer on top:%s\n",(state->discard[1][0]==adventurer)?"YES":"NO");
  printf("Supply count for adventurer should be reduced by 1:%s\n",(state->supplyCount[adventurer]==9)?"YES":"NO");
  printf("Buys should be reduced by 1:%s\n",(state->numBuys==0)?"YES":"NO");
  printf("Coins should be reduced by 6:%s\n",(state->coins==4)?"YES":"NO");
  
  printf("Testing for multiple users:\n");
  initializeGame(4,kc,1,state);
  for(int i=0;i<4;i++){
    state->whoseTurn=i;
    state->coins=6;
    state->numBuys=1;
    printf("Works for player %d: %s\n",i,(!buyCard(adventurer,state))?"YES":"NO");
  }
  
  
  
  initializeGame(2,kc,1,state);
  state->supplyCount[adventurer]=0;
  state->coins=10;
  printf("Game reset\n");
  printf("Adventurer supply set to 0\n");
  printf("Coins set to 10\n");
  
  printf("Should fail: %s\n",(buyCard(adventurer,state))?"YES":"NO");
  printf("Supply should still be 0:%s\n",(state->supplyCount[adventurer]==0)?"YES":"NO");
  printf("Buys should still be 1:%s\n",(state->numBuys==1)?"YES":"NO");
  
  
  initializeGame(2,kc,1,state);
  state->coins=10;
  state->numBuys=0;
  printf("Game reset, number of buys set to 0.\n");
  printf("Should fail:%s\n",(buyCard(adventurer,state))?"YES":"NO");
  
  return 0;
}
  