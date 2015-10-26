/* Rachael McConnell
 * CS362 Fall 2015
 * Card Test 2: adventurerCard()
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

void testAdventurerCard() {
  struct gameState gs;
  int player;
  int treasureCards = 0;
  int adventurerCards = 0;
  int estateCards = 0;
  int duchyCards = 0;
  int copperCards = 0;
  int numPlayers = 2;
  int handCount=5;
  int randomSeed = rand() % 100 + 1;
  int test1[5];
  int test2[5];
  int seeds[4] = { copper, silver, estate, duchy };    
  int kingdom[10]= { adventurer, council_room, feast, gardens, mine,
remodel, smithy, village, baron, great_hall };
  int j, num0, num1;
  int errors = 0;

int a;
for(a=0;a<5;a++){

  printf("\nTEST #%d\n", a+1);
  for(j=0;j<5;j++){
    num0 = rand() % 3;
    num1 = rand() % 3;
    if(j==0)
      test2[j] = adventurer;
    else
      test2[j] = seeds[num0];
    test1[j] = seeds[num1];
  }

 
  memset(&gs, 23, sizeof(struct gameState));
  initializeGame(numPlayers, kingdom, randomSeed, &gs);
  memcpy(gs.hand[0], test2, sizeof(int)*handCount);
  memcpy(gs.hand[1], test1, sizeof(int)*handCount);
  gs.handCount[0]=5;
  gs.handCount[1]=5;


  //Test for player 0
  player = 0;
  printf("BEFORE Adventurer Card played\n"); 
  printf("Player 0\n");
  printf(" handCount: %d\n", gs.handCount[player]);
  int handCountBefore = gs.handCount[player];
  int i=0;
  int treasureCardsBefore = 0;
  for(i=0;i<gs.handCount[player];i++){

    if(gs.hand[player][i] == copper || gs.hand[player][i] == silver || gs.hand[player][i] == gold){
      treasureCards++;
    }
    if(gs.hand[player][i] == adventurer)
      adventurerCards++;
    if(gs.hand[player][i] == copper)
      copperCards++;
    if(gs.hand[player][i] == estate)
      estateCards++;
    if(gs.hand[player][i] == duchy)
      duchyCards++;
  }
  treasureCardsBefore = treasureCards;
  printf(" %d Adventurer Cards\n", adventurerCards);
  printf(" %d Treasure Cards\n", treasureCards);
  

  //Test for player 1
  player = 1;

  printf("Player %d\n", player);
  printf(" handCount: %d\n", gs.handCount[player]);
  treasureCards=0, adventurerCards = 0, duchyCards=0, copperCards=0, estateCards=0;
  for(i=0;i<gs.handCount[player];i++){
    if(gs.hand[player][i] == adventurer)
      adventurerCards++;
    if(gs.hand[player][i] == copper)
      copperCards++;
    if(gs.hand[player][i] == estate)
      estateCards++;
    if(gs.hand[player][i] == duchy)
      duchyCards++;
  }
  printf("\n");


  adventurerCard(0, 0, &gs, 0, 0, 0);



  printf("AFTER Adventurer Card Played\n");
  printf("Player 0\n");
  player = 0;
  printf(" handCount: %d\n", gs.handCount[player]);
  treasureCards=0, adventurerCards=0, duchyCards=0, copperCards=0, estateCards=0;
  for(i=0;i<gs.handCount[player];i++){
    if(gs.hand[player][i] == copper || gs.hand[player][i] == silver || gs.hand[player][i] == gold){
      treasureCards++;
    }
    if(gs.hand[player][i] == adventurer)
      adventurerCards++;
    if(gs.hand[player][i] == copper)
      copperCards++;
    if(gs.hand[player][i] == estate)
      estateCards++;
    if(gs.hand[player][i] == duchy)
      duchyCards++;
  }
  printf(" %d Adventurer Cards\n", adventurerCards);
  
  
  if(treasureCards == treasureCardsBefore+2){
    printf(" Pass: Treasure Cards incremented by 2\n");
  }else{
    printf(" Fail: ");
    errors++;
  }
  printf(" Treasure Cards: %d, expected: %d\n", treasureCards, treasureCardsBefore+2);
  if(handCountBefore+2 == gs.handCount[player]){
    printf(" Pass: Hand count incremented by 2\n");
  }else{
    printf(" Fail: ");
    errors++;
  }
  printf(" Hand count: %d, expected: %d\n", handCountBefore+2, gs.handCount[player]);
  int cardInHand=0;
  for(i=0;i<gs.handCount[player];i++){
    if(gs.hand[player][i] == adventurer)
      cardInHand = 1;
  }
  if(cardInHand == 1){
    printf(" Fail: Adventurer card was not discarded.\n");
    errors++;
  }else{
    printf(" Pass: Adventurer card was discarded.\n");
  }
   


  printf("Player 1 \n");
  player = 1;

  if(gs.handCount[player] == 5){
    printf(" Pass: Hand count remains the same\n");
  }else{
    printf(" Fail: ");
    errors++;
  }
  printf(" handCount: %d, expected: 5\n", gs.handCount[player]);

  treasureCards=0, adventurerCards = 0, duchyCards=0, copperCards=0, estateCards=0;
  for(i=0;i<gs.handCount[player];i++){

    if(gs.hand[player][i] == adventurer)
      adventurerCards++;
    if(gs.hand[player][i] == copper)
      copperCards++;
    if(gs.hand[player][i] == estate)
      estateCards++;
    if(gs.hand[player][i] == duchy)
      duchyCards++;
  }

}
printf("\n");  

  if(errors == 0){
    printf("All adventurerCard tests passed!\n");
  }else{
    printf("%d bugs found in adventurerCard tests\n", errors);
  }
}

int main(){
  testAdventurerCard();
  return 0;
}

