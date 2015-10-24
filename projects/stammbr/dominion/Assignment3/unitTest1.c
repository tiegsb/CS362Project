/*****************
 * Author:  Brian Stamm
 * Title:  unitTest1.c
 * Assignment:  3
 * Date:  10.25.15
 * Notes:  Create unit test for shuffle().
 * ****************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>


void test(){
  struct gameState g;
  struct gameState *game = &g;
  srand(time(NULL));
  int player = 0;
  int card, position, same, index, i, r, failNum;
  int testDeck[500];

  //Initial check, first if
  game->deckCount[player] = 0;
  if(shuffle(player, game) == -1){
    printf("shuffle() test 1:  PASSED - first if\n");
  }
  else{
    printf("shuffle() test 1:  FAILED - first if\n");
  }

  //Random testing, increasing card count along the way to 500.
  position = 0;
  same = 0;
  index = 1;
  failNum = 0;
  printf("Testing started - increasing card count from 0 to 500\n");
  while(game->deckCount[player] <= 500){
    
    for(i = 0; i <= position; i++){    
      r = rand();
      card = r % treasure_map;
      game->deck[player][i] = card;
      testDeck[i] = game->deck[player][i];
    }

    shuffle(player, game);

    for(i = 0; i <= position; i++){
      if(testDeck[i] == game->deck[player][i]){
        same++;
      }
    }
    if((float)same/index > 0.75){
      printf("shuffle() increase random test:  FAIL\n");
      printf("Amount of Cards:  %d\tPercent same:  %.1f\n\n", index, (float)same/index*100);
      failNum++;
    }
    same = 0;
    game->deckCount[player] += 1;
    position++;
    index++;
  }

  if(failNum == 0){
    printf("shuffle() increasing deck - PASSED.\n\n");
  }
  else{
    printf("shuffle() increasing deck - FAILED  - %d times\n\n", failNum);
  }

  //Random testing, 500 cards, 500 times
  game->deckCount[player] = 500;
  position = 0;
  same = 0;
  index = 0;
  failNum = 0;
  printf("Testing 500 cards, random\n");
  while(index < 500){
    for(i = 0; i < 500; i++){
      r = rand();
      card = r % treasure_map;
      game->deck[player][i] = card;
      testDeck[i] = card;
    } 

    shuffle(player, game);

    for(i = 0; i < 500; i++){
      if(testDeck[i] == game->deck[player][i]){
        same++;
      }
    }
    if(((float)same/500) > 0.75){
      printf("shuffle() 500 random test:  FAIL\n");
      printf("%d:  Percent same:  %.1f\n\n", index+1, (float)same/index*100);
      failNum++;
    }
    same = 0;
    index++;
  }
  if(failNum == 0){
    printf("shuffle() random deck - PASSED.\n\n");
  }
  else{
    printf("shuffle() random deck - FAILED  - %d times\n\n", failNum);
  }
}

int main(int argc, char **argv){

	test();

	return 0;
}


/*
int shuffle(int player, struct gameState *state) {
 

  int newDeck[MAX_DECK];
  int newDeckPos = 0;
  int card;
  int i;

  if (state->deckCount[player] < 1)
    return -1;
  qsort ((void*)(state->deck[player]), state->deckCount[player], sizeof(int), compare); 
  //SORT CARDS IN DECK TO ENSURE DETERMINISM!

  while (state->deckCount[player] > 0) {
    card = floor(Random() * state->deckCount[player]);
    newDeck[newDeckPos] = state->deck[player][card];
    newDeckPos++;
    for (i = card; i < state->deckCount[player]-1; i++) {
      state->deck[player][i] = state->deck[player][i+1];
    }
    state->deckCount[player]--;
  }
  for (i = 0; i < newDeckPos; i++) {
    state->deck[player][i] = newDeck[i];
    state->deckCount[player]++;
  }

  return 0;
}
*/
