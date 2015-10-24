/* Rachael McConnell
 * CS362 Fall 2015
 * Card Test 3: council_roomCard()
 *
 * Player should receive 4 cards and 1 buy
 * All other players should draw 1 card
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

void countCards(struct gameState *state, int player, int HandOrDeck) {

  int i=0;
  int smithyCards =0;
  int copperCards = 0;
  int estateCards = 0;
  int duchyCards = 0;
  int silverCards = 0;
  int council_roomCards = 0;
  if(HandOrDeck == 0){
    for(i=0;i<state->handCount[player];i++){
      if(state->hand[player][i] == smithy)
        smithyCards++;
      if(state->hand[player][i] == copper)
        copperCards++;
      if(state->hand[player][i] == estate)
        estateCards++;
      if(state->hand[player][i] == duchy)
        duchyCards++;
      if(state->hand[player][i] == silver)
        silverCards++;
      if(state->hand[player][i] == council_room)
	council_roomCards++;
    }
  }else{

    for(i=0;i<state->deckCount[player];i++){
      if(state->deck[player][i] == smithy)
        smithyCards++;
      if(state->deck[player][i] == copper)
        copperCards++;
      if(state->deck[player][i] == estate)
        estateCards++;
      if(state->deck[player][i] == duchy)
        duchyCards++;
      if(state->deck[player][i] == silver)
        silverCards++;
      if(state->deck[player][i] == council_room)
	council_roomCards++;
    }
  }
  printf("%d Smithy Cards. ", smithyCards);
  printf("%d Copper Cards. ", copperCards);
  printf("%d Duchy Cards. ", duchyCards);
  printf("%d Estate Cards. ", estateCards);
  printf("%d Silver Cards. ", silverCards);
  printf("%d Council Room Cards. ", council_roomCards);
  printf("\n");

}


void testcouncil_roomCard() {
  struct gameState gs;
  int handPos = 0;
  int errors = 0;
  int player;
  int numPlayers = 2;
  int i, j, num0, num1;
  int handCount=5;
  int deckCount = 10;
  int randomSeed = rand() % 100 + 1;
  int test1[5];
  int test0[5];
  int seeds[5];
  int test0Deck[10] = { silver, duchy, copper, estate, estate, silver, copper, silver, duchy, estate };
  int test1Deck[10] = { silver, copper, copper, silver, silver, silver, silver, silver, silver, silver };

  int kingdom[10]= { adventurer, council_room, feast, gardens, mine,
remodel, smithy, village, baron, great_hall };
 
for(i=0;i<5;i++){

  printf("\nTEST #%d\n", i+1);

  for(j=0;j<5;j++){
    num0 = rand() % 4;
    num1 = rand() % 4;
    if(j==0)
      test0[j] = council_room;
    else
      test0[j] = seeds[num0];
    test1[j] = seeds[num1];
  }

  memset(&gs, 23, sizeof(struct gameState));
  initializeGame(numPlayers, kingdom, randomSeed, &gs);
  memcpy(gs.hand[0], test0, sizeof(int)*handCount);
  memcpy(gs.hand[1], test1, sizeof(int)*handCount);
  memcpy(gs.deck[0], test0Deck, sizeof(int)*deckCount);
  memcpy(gs.deck[1], test1Deck, sizeof(int)*deckCount);
  gs.handCount[0]=5;
  gs.handCount[1]=5;
  gs.deckCount[0]=10;
  gs.deckCount[0]=10;
  int buysStart = gs.numBuys;
  int numCopper, numSilver, numGold, numEstate, numProvince, numDuchy, numCurse;
  //Before council room card is played
  player = 0;
  
  printf("BEFORE Council Room Card is played \n\n"); 
  printf("Player %d\n", player);
  printf("In hand...");

  countCards(&gs, player, 0); 
  printf("In Deck...");
  countCards(&gs, player, 1);
  printf("Number of buys: %d\n", gs.numBuys);
  player = 1;
  deckCount = 10;
  printf("Player %d\n", player);
  printf("In Hand...");

  countCards(&gs, player, 0);
  printf("In Deck...");
  countCards(&gs, player, 1);
 

  numCopper = gs.supplyCount[copper];
  numGold = gs.supplyCount[gold];
  numSilver = gs.supplyCount[silver];
  numEstate = gs.supplyCount[estate];
  numDuchy = gs.supplyCount[duchy];
  numProvince = gs.supplyCount[province];
  numCurse =gs.supplyCount[curse];  

 
  //Call council room card
  council_roomCard(0, &gs, handPos);
  printf("\nAFTER Council Room Card is played \n\n");
  player = 0;
  printf("Player %d\n", player);
  printf("In Hand...");
    
  countCards(&gs, player, 0);
  printf("In Deck...");
  countCards(&gs, player, 1);
  printf("Number of buys: %d\n", gs.numBuys);
  if(gs.deckCount[player] != 6){
    printf("Fail: ");
    errors++;  
  }else{
    printf("Pass: ");
  }
  printf("Deck count actual: %d, expected: 6\n", gs.deckCount[player]);

  if(gs.handCount[player] != handCount+3){
    printf("Fail: ");
    errors++;
  }else{
    printf("Pass: ");
  }
  printf("Hand count actual: %d, expected: 8\n", gs.handCount[player]);
  


  player = 1;
  printf("Player %d\n", player);
  printf("In Hand...");

  countCards(&gs, player, 0);
  printf("In Deck...");
  countCards(&gs, player, 1);
  if(gs.handCount[player] != handCount+1)
    errors++;  
  printf("Hand count actual: %d, expected: 6\n", gs.handCount[player]);
 
  if(gs.deckCount[player] != 9){
    printf("Fail: ");
    errors++;
  }else{
    printf("Pass: ");
  }
  printf("Deck count actual: %d, expected: 9\n", gs.deckCount[player]);

  if(gs.numBuys != buysStart+1){
    printf("Fail: ");
    errors++;
  }else{
    printf("Pass: ");
  }
  printf("Number of buys actual: %d, expected: 2\n", gs.numBuys); 


  if(numCopper == gs.supplyCount[copper] && numGold == gs.supplyCount[gold] && numSilver == gs.supplyCount[silver] && numEstate == gs.supplyCount[estate] && numDuchy == gs.supplyCount[duchy] && numProvince == gs.supplyCount[province] && numCurse == gs.supplyCount[curse]){
    printf("Pass: Supply count is unchanged.\n");
  }else{
    printf("Fail: Supply count was changed.\n");
  }   


}


  if(errors == 0){
    printf("\nAll council_roomCard tests passed\n");
  }else{
    printf("%d council_roomCard tests failed\n", errors);
  } 
}

int main(){
  
  testcouncil_roomCard();
  return 0;
}

