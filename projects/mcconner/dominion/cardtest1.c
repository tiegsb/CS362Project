/* Rachael McConnell
 * CS362 Fall 2015
 * Card Test 1: smithyCard()
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
  int smithyCards =0;
  int copperCards = 0;
  int estateCards = 0;
  int duchyCards = 0;
  int silverCards = 0;
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
    }
  }
  printf("%d Smithy Cards ", smithyCards);
  printf("%d Copper Cards ", copperCards);
  printf("%d Duchy Cards ", duchyCards);
  printf("%d Estate Cards ", estateCards);
  printf("%d Silver Cards ", silverCards);
  printf("\n");
}


int testSmithyCard(struct gameState *gs, int handPos) {
  int player;
  int deckCount;
  int handCount = 5;
  int errors = 0;

  printf("BEFORE Smithy Card Played\n");
  //Test for player 0
  player = 0;
  printf("Player 0\n");
  deckCount = 8;

  printf("In hand...");

  countCards(gs, player, 0); 
  printf("In Deck...");
  countCards(gs, player, 1); 
  //Test for player 1
  player = 1;
  printf("Player 1\n");
  deckCount = 10;

  printf("In Hand...");

  countCards(gs, player, 0);
  printf("In Deck...");
  countCards(gs, player, 1);
  printf("\n");


  int numCopper = gs->supplyCount[copper];
  int numGold = gs->supplyCount[gold];
  int numSilver = gs->supplyCount[silver];
  int numEstate = gs->supplyCount[estate];
  int numDuchy = gs->supplyCount[duchy];
  int numProvince = gs->supplyCount[province];
  int numCurse = gs->supplyCount[curse];  
 

  smithyCard(0, gs, handPos);

  //Test player 0
  printf("AFTER Smithy Card played\n");
  printf("Player 0\n");
  player = 0;
  printf("In Hand...");
    
  countCards(gs, player, 0);
  printf("In Deck...");
  countCards(gs, player, 1);
  if(gs->deckCount[player] != 8){
    printf("Fail: ");
    errors++;
  }else{
    printf("Pass: ");
  }
  printf("Deck count actual: %d, expected: 8\n", gs->deckCount[player]);

  if(gs->handCount[player] != handCount+1){
    printf("Fail: ");
    errors++;
  }else{
    printf("Pass: ");
  }
  printf("Hand count actual: %d, expected: 6\n", gs->handCount[player]);
  
  
  player = 1;
  printf("Player 1\n");
  
  printf("In Hand...");
  countCards(gs, player, 0);
  printf("In Deck...");
  countCards(gs, player, 1);
  if(gs->handCount[player] != handCount){
    printf("Fail: ");
    errors++;
  }else{
    printf("Pass: ");
  }
  printf("Hand count actual: %d, expected: 5\n", gs->handCount[player]);

  if(gs->deckCount[player] != 10){
    printf("Fail: ");
    errors++;
  }else{
    printf("Pass: ");
  }
  printf("Deck count actual: %d, expected: 10\n", gs->deckCount[player]);

  if(numCopper == gs->supplyCount[copper] && numGold == gs->supplyCount[gold] && numSilver == gs->supplyCount[silver] && numEstate == gs->supplyCount[estate] && numDuchy == gs->supplyCount[duchy] && numProvince == gs->supplyCount[province] && numCurse == gs->supplyCount[curse]){
    printf("Pass: Supply count unchanged.\n");
  }else{
    printf("Fail: Supply count changed.\n");
  } 

  if(errors == 0)
    return 0;
  else
    return 1;
 
}

int main(){


  struct gameState gs;
  int handPos = 0;
  int numPlayers = 2;
  int handCount=5;
  int deckCount = 10;
  int randomSeed = rand() % 100 + 1;
  int returned = 0;
  int test1[5];
  int test0[5];
  int seeds[4] = { copper, silver, duchy, estate }; 
  int test0Deck[10] = { silver, duchy, copper, estate, estate, silver, copper, silver, duchy, estate };
  int test1Deck[10] = { silver, copper, copper, silver, silver, silver, silver, silver, silver, silver };

  int kingdom[10]= { adventurer, council_room, feast, gardens, mine,
remodel, smithy, village, baron, great_hall };

  int i, j, num0, num1;
  srand(time(NULL));

  for(i=0;i<5;i++){

    for(j=0; j<5; j++){
      num0 = rand() % 3;
      num1 = rand() % 3;
      test1[j] = seeds[num1];
      if(j==0)
        test0[j] = smithy;
      else
        test0[j] = seeds[num0];
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

    printf("\nTEST #%d\n\n", i+1);
   returned += testSmithyCard(&gs, handPos);

  }

  if(returned == 0)
    printf("All smithyCard tests passed!\n");
  else
    printf("%d smithyCard tests failed.\n", returned);

  return 0;
}

