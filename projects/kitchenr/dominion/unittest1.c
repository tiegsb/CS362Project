#include "dominion.h"

/*
 * 
 * 
 * Unit testing for initializeGame
 * 
 * Black box test, tests if initializeGame works correctly with valid inputs, and if it detects invalid ones
 * 
*/




int testInitialDeck(struct gameState *state, int player){
  int copcards=0,estatecards=0,other=0;
  for(int i=0;i<state->handCount[player];i++){
    int curcard=state->hand[player][i];
    if(curcard==copper) copcards++;
    else if(curcard==estate) estatecards++;
    else other++;
  }
  for(int i=0;i<state->deckCount[player];i++){
    int curcard=state->deck[player][i];
    if(curcard==copper) copcards++;
    else if(curcard==estate) estatecards++;
    else other++;
  }
  if(other) return 1;
  if(copcards!=7) return 2;
  if(estatecards!=3) return 3;
  return 0;
}
    
int testSupply(struct gameState *state, int kc[10]){
  for(int i=0;i<10;i++){
    if(state->supplyCount[kc[i]]!=10){
      if(kc[i]==gardens || kc[i]==great_hall) printf("Kingdom card %s is also a victory card, %d copies instead of 10\n",(kc[i]==gardens)?"gardens":"great_hall",state->supplyCount[kc[i]]);
      else return 1;
    }
  }
  for(int i=adventurer;i<treasure_map+1;i++){
    if(state->supplyCount[i]!=-1){
      int selected=0;
      for(int j=0;j<10;j++) if(i==kc[j]) selected++;
      if(!selected) return 2;
    }
  }
  return 0;
}
    

int main(){
  /* test 1
   * players = 2
   * kingdom cards = adventurer - great_hall (all valid)
   * seed = 1
   * 
   * 
   * output expected:
   * gamestate - players set to 2
   * handCount of each player should be 5
   * deckCount of each player should be 5
   * number of each victory card should be 8;
   * supply count for each kingdom card chosen should be 10, others should be -1
  */
  
  struct gameState *state=newGame();
  int *kc = kingdomCards(adventurer,council_room,feast,gardens,mine,remodel,smithy,village,baron,great_hall);
  int results = initializeGame(2, kc,1,state);
  
  printf("Test 1: 2 players, first 10 kingdom cards, seed = 1.\n");
  printf("state->numPlayers = 2? %c\n",(state->numPlayers==2)?'y':'n');
  printf("Hand counts of players 1 and 2 are 5? %d,%d,%c\n",state->handCount[0],state->handCount[1],(state->handCount[0]==5 && state->handCount[1]==5)?'y':'n');
  printf("Deck counts of players 1 and 2 are 5? %d,%d,%c\n",state->deckCount[0],state->deckCount[1],(state->deckCount[0]==5 && state->deckCount[1]==5)?'y':'n');
  int id1 = testInitialDeck(state,0);
  int id2 = testInitialDeck(state,1);
  printf("Initial deck/hands contain 7 copper and 3 estates? %c %c\n",(!id1)?'y':'n',(!id2)?'y':'n');
  if(id1 || id2){
    printf("FAILED:\n");
    if(id1 == 1 || id2 == 1) printf("Other cards found in hand or deck!\n");
    if(id1 == 2 || id2 == 2) printf("Wrong amount of copper cards!\n");
    if(id1 == 3 || id2 == 3) printf("Wrong amount of estate cards!\n");
  }
  printf("Victory card supply counts should be 8: %d,%d,%d\n", state->supplyCount[estate], state->supplyCount[duchy],state->supplyCount[province]);
  printf("Selected kingdom supply counts should be 10, others -1: %c\n",(!testSupply(state,kc))?'y':'n');

  
  /* test 2
   * players = 1
   * kingdom cards = same as 1st
   * seed = 0
   * 
   * should return error
   */
  
  printf("Test 2: 1 player, first 10 kingdom cards, seed = 1.\n");
  printf("Should return nonzero indicating error: %d\n",initializeGame(1,kc,1,state));
  
  
  printf("Test 3: 2 players, all kingdom cards adventurer, seed = 0.\n");
  int *badkc = kingdomCards(adventurer,adventurer,adventurer,adventurer,adventurer,adventurer,adventurer,adventurer,adventurer,adventurer);
  printf("Should return nonzero indicating error: %d\n",initializeGame(2,badkc,1,state));
  
  
  printf("Test 4: 2 players, kingdom cards include copper and first 9, seed = 0.\n");
  int *copperkc = kingdomCards(copper,adventurer,council_room,feast,gardens,mine,remodel,smithy,village,baron);
  printf("Should return nonzero indicating error: %d\n",initializeGame(2,copperkc,1,state));
  
  printf("Testing initialization for multiple players:\n");
  printf("3 players works? %s\n",(!initializeGame(3,kc,1,state))?"YES":"NO");;
  printf("4 players works? %s\n",(!initializeGame(4,kc,2,state))?"YES":"NO");
  
  
  
  return 0;
}