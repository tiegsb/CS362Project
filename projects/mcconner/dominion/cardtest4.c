/* Rachael McConnell
 * CS362 Fall 2015
 * Card Test 4: villageCard()
 * 
 * Player should receive 2 actions and gain 1 card
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

void countCards(struct gameState *state, int player, int HandOrDeck) {

  int i=0;
  int villageCards =0;
  int copperCards = 0;
  int estateCards = 0;
  int duchyCards = 0;
  int silverCards = 0;
  if(HandOrDeck == 0){
    for(i=0;i<state->handCount[player];i++){
      if(state->hand[player][i] == village)
        villageCards++;
      if(state->hand[player][i] == copper)
        copperCards++;
      if(state->hand[player][i] == estate)
        estateCards++;
      if(state->hand[player][i] == duchy)
        duchyCards++;
      if(state->hand[player][i] == silver)
        silverCards++;
    }
  }else{

    for(i=0;i<state->deckCount[player];i++){
      if(state->deck[player][i] == village)
        villageCards++;
      if(state->deck[player][i] == copper)
        copperCards++;
      if(state->deck[player][i] == estate)
        estateCards++;
      if(state->deck[player][i] == duchy)
        duchyCards++;
      if(state->deck[player][i] == silver)
        silverCards++;
    }
  }
  printf("%d Copper Cards ", copperCards);
  printf("%d Duchy Cards ", duchyCards);
  printf("%d Estate Cards ", estateCards);
  printf("%d Silver Cards ", silverCards);
  printf("%d Village Cards ", villageCards);
  printf("\n");
}


void testVillageCard() {
  struct gameState gs;
  int errors = 0;
  int player;
  int numPlayers = 2;
  int handCount=5;
  int deckCount = 10;
  int randomSeed = rand() % 100 + 1;
  int test1[5];
  int test0[5];
  int seeds[4] = { copper, silver, duchy, estate };
  int test0Deck[10] = { silver, duchy, copper, estate, estate, silver, copper, silver, duchy, estate };
  int test1Deck[10] = { silver, copper, copper, silver, silver, silver, silver, silver, silver, silver };
  int numCopper, numSilver, numGold, numEstate, numDuchy, numProvince, numCurse;
  int kingdom[10]= { adventurer, council_room, feast, gardens, mine,
remodel, smithy, village, baron, great_hall };
  int i, j, num0, num1;




//Run village test 5 times
for(i=0;i<5;i++){

  printf("\nTEST #%d\n", i+1);

  for(j=0;j<5;j++){
    num0 = rand() % 3;
    num1 = rand() % 3;
    if(j==0)
      test0[j] = village;
    else
      test0[j] = seeds[num0];
    test1[j] = seeds[num1];
  }
 
  //set the game
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

  //Test for player 0 before the card is played
  player = 0;
  printf("BEFORE village card is played\n");
  printf("Player %d\n", player); 
  printf("In hand...");
  countCards(&gs, player, 0);
 
  printf("In Deck...");
  countCards(&gs, player, 1);
  printf("\n");  

//Test for player 1 before the card is played
  player = 1;
  printf("Player %d\n", player);
  printf("In Hand...");
  countCards(&gs, player, 0);

  printf("In Deck...");
  countCards(&gs, player, 1);
  printf("\n");
  int actionsStart = gs.numActions;
  printf("Number of Actions: %d\n", gs.numActions);

  //check the supply count
  numCopper = gs.supplyCount[copper];
  numGold = gs.supplyCount[gold];
  numSilver = gs.supplyCount[silver];
  numEstate = gs.supplyCount[estate];
  numDuchy = gs.supplyCount[duchy];
  numProvince = gs.supplyCount[province];
  numCurse =gs.supplyCount[curse];  
  

  //player 0 plays the village card
  cardEffect(village, 0, 0, 0, &gs, 0, 0);

  //check player 0 after card is played
  player = 0;
  printf("AFTER village card is played\n");
  printf("Player %d\n", player);
  printf("In Hand...");
  countCards(&gs, player, 0);

  printf("In Deck...");
  countCards(&gs, player, 1);
  if(gs.deckCount[player] != 9){
    printf("Fail: ");
    errors++;
  }else{
    printf("Pass: ");
  }
  printf("Deck count actual: %d, expected: 9\n", gs.deckCount[player]);

  if(gs.handCount[player] != handCount){
    printf("Fail: ");
    errors++;
  }else{
    printf("Pass: ");
  }
  printf("Hand count actual: %d, expected: 5\n", gs.handCount[player]);

  //check player 1 after the card is played 
  player = 1;
  printf("Player %d\n", player);
  printf("In Hand...");
  countCards(&gs, player, 0);

  printf("In Deck...");
  countCards(&gs, player, 1);

  printf("Number of Actions: %d\n", gs.numActions);

  //check that actions are 1 greater
  //this would mean that the player received 2 actions
  if(gs.numActions != actionsStart+1){
    printf("Fail: ");
    errors++;
  }else{
    printf("Pass: ");
  }
  printf("Actions actual: %d, expected %d\n", gs.numActions, actionsStart+1);

  if(gs.handCount[player] != handCount){
    printf("Fail: ");
    errors++;
  }else{
    printf("Pass: ");
  }
  printf("Hand count actual: %d, expected: 5\n", gs.handCount[player]);
  
  if(gs.deckCount[player] != 10){
    printf("Fail: ");
    errors++;
  }else{
    printf("Pass: ");
  }
  printf("Deck count actual: %d, expected: 10\n", gs.deckCount[player]);

 
  if(numCopper == gs.supplyCount[copper] && numGold == gs.supplyCount[gold] && numSilver == gs.supplyCount[silver] && numEstate == gs.supplyCount[estate] && numDuchy == gs.supplyCount[duchy] && numProvince == gs.supplyCount[province] && numCurse == gs.supplyCount[curse]){
    printf("Pass: Supply count is unchanged.\n");
  }else{
    printf("Fail: Supply count was changed.\n");
  }   


}



  if(errors == 0){
    printf("All villageCard tests passed\n");
  }else{
    printf("%d villageCard tests failed\n", errors);
  } 
}

int main(){
  srand(time(NULL));
  testVillageCard();
  return 0;
}

