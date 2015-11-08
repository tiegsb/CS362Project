/*----------------------------------------------------------------------
* Name: Susan Lee
* Class: CS 362_400_F2015
* Homework 4
* Random tester for council card
* -----------------------------------------------------------------------
*/
#include "dominion.h"
#include "dominion_helpers.h"
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <time.h>
#include "rngs.h"

struct failures {
  int handFail;
  int deckFail;
  int discFail;
  int buyFail;
  int handOtherFail;
  int deckOtherFail;
  int coinsFail;
  int councilFail;
  int totalHand;
  int totalDeck;
  int totalDisc;
  int totalBuys;
  int totalHandOther;
  int totalDeckOther;
  int totalCoins;
  int totalCouncil;
};

int initFailures(struct failures *fail);
void setDeck(struct gameState *G, int numPlayers);
void setHand(struct gameState *G, int numPlayers);
int checkCouncil(int p, struct gameState post, int handPos, struct failures *failure, int currentPlayer);

int main(){
  int seed = 1000;
  //int putseed = 1;
  //int stream = 1;
  int n, i,r;
  int result;
  //bool pass = true;
  int p = 0;
  int handPos;

  int k[10] = { adventurer, council_room, feast, gardens, mine
    , remodel, smithy, village, baron, great_hall };
  struct gameState G;
  struct failures fail;

  initFailures(&fail);
  
  SelectStream(2);
  PutSeed(3);
  srand(time(NULL));

  //The following random loop was inspired by Lecture 11 CS 362
  for (n = 0; n < 50; n++){
    //initialize random gamesate
    for (i = 0; i < sizeof(struct gameState); i++){
      ((char*)&G)[i] = floor(Random() * 256);
    }
    //reset some gamestate members to reasonable input
    p = floor(Random() * MAX_PLAYERS);
    //if random input is 0, change to 1 player so tests can be run.
    if (p == 0){
      p = 1;
    }
    seed = floor(Random() * 5000);
     printf("\np before init is: %d\n", p);
    r = initializeGame(p, k, seed, &G); //initialize game
    for (i = 0; i < p; i++){
      G.deckCount[i] = floor(Random() * MAX_DECK);
      printf("deckCount %d\n", G.deckCount[i]);
      G.discardCount[i] = floor(Random() * MAX_DECK);
      printf("dicardCount %d\n", G.discardCount[i]);
      G.handCount[i] = floor(Random() * MAX_HAND);
      printf("handCount %d\n", G.handCount[i]);
    }
    //set handcount to 0
    //G.handCount[0] = 0;
    //set cards, set top card in hand to be council card
    setDeck(&G, p);
    setHand(&G, p);

    //run check on gamestate for council card
    for (i = 0; i < p; i++){
      handPos = floor(Random() * G.handCount[i]);
      G.playedCardCount = floor(Random() *MAX_DECK);
      G.numBuys = floor(Random() *50);
      G.coins = floor(Random() *50);
      result = checkCouncil(p, G, handPos, &fail, i);
    }
    //clear game state
    memset(&G, 23, sizeof(struct gameState));

  }

  //print out summary results
  printf("\nCOUNCIL ROOM FAILURE SUMMARY: \n");
  printf("********************************\n");
  printf("Hand count failures: %d/%d\n", fail.handFail, fail.totalHand);
  printf("Deck count failures: %d/%d\n", fail.deckFail, fail.totalDeck);
  printf("Discard count failures: %d/%d\n", fail.discFail, fail.totalDisc);
  printf("Buy count failures: %d/%d\n", fail.buyFail, fail.totalBuys);
  printf("Other Players' hand count failures: %d/%d\n", fail.handOtherFail, fail.totalHandOther);
  printf("Other Players' deck count failures: %d/%d\n", fail.deckOtherFail, fail.totalDeckOther);
  printf("Coin count failures: %d/%d\n", fail.coinsFail, fail.totalCoins);
  printf("Council count failures: %d/%d\n\n", fail.councilFail, fail.totalCouncil);
  return 0;
}

int initFailures(struct failures *fail){
  fail->handFail=0;
  fail->deckFail=0;
  fail->discFail=0;
  fail->buyFail=0;
  fail->handOtherFail=0;
  fail->deckOtherFail=0;
  fail->coinsFail=0;
  fail->councilFail=0;
  fail->totalHand=0;
  fail->totalDeck=0;
  fail->totalDisc=0;
  fail->totalBuys=0;
  fail->totalHandOther=0;
  fail->totalDeckOther=0;
  fail->totalCoins=0;
  fail->totalCouncil=0;
  return 0;
}

void setDeck(struct gameState *G, int numPlayers){
  int j, p;

  for (p = 0; p < numPlayers; p++){
    for (j = 0; j < G->deckCount[p]; j++){
      G->deck[p][j] = floor(Random() * 26);
    }
  }
}

void setHand(struct gameState *G, int numPlayers){
  int j, p;

  for (p = 0; p < numPlayers; p++){
    for (j = 0; j < G->handCount[p] - 1; j++){
      G->hand[p][j] = floor(Random() * 26);
    }
    G->hand[p][G->handCount[p] - 1] = council_room;
  }

}

int checkCouncil(int p, struct gameState post, int handPos, struct failures *failure, int currentPlayer) {

  struct gameState pre;
  int i;
  bool fail = false;
  //int newCard1, newCard2, newCard3, newCard4;
  //int deckCard1, deckCard2, deckCard3, deckCard4;
  int preCouncil = 0;
  int councilCount = 0;

  //copy the game state to compare pre and post values
  memcpy(&pre, &post, sizeof(struct gameState));

  councilAction(currentPlayer, &post, handPos);

  //expected hand count
  printf("Hand Count\t Expected: %d\t Result:%d\n", pre.handCount[currentPlayer] + 3, post.handCount[currentPlayer]);
  //check deck count
  printf("Deck Count\t Expected: %d\t Result:%d\n", pre.deckCount[currentPlayer] - 4, post.deckCount[currentPlayer]);
  //gather count of council cards
  if (post.hand[currentPlayer][pre.handCount[currentPlayer]] == council_room){
    councilCount++;
  }
  if (post.hand[currentPlayer][pre.handCount[currentPlayer]] == council_room){
    councilCount++;
  }
  if (post.hand[currentPlayer][pre.handCount[currentPlayer] + 1] == council_room){
    councilCount++;
  }
  if (post.hand[currentPlayer][pre.handCount[currentPlayer] + 2] == council_room){
    councilCount++;
  }
  if (post.hand[currentPlayer][handPos] == council_room){
    councilCount++;
  }
 
  //check number of buys
  printf("Buys\t Expected: %d\t Result:%d\n", pre.numBuys + 1, post.numBuys);

  //check card count for all other players
  for (i = 0; i< p; i++){
    if (i != currentPlayer){
      printf("HandCount p%d\t Expected: %d\t Result:%d\n", i + 1, pre.handCount[i] + 1, post.handCount[i]);
      printf("DeckCount p%d\t Expected: %d\t Result:%d\n", i + 1, pre.deckCount[i] - 1, post.deckCount[i]);
    }
  }

  //check count of coins has not changed
  printf("Coins\t Expected: %d\t Result:%d\n", pre.coins, post.coins);

  //check Council Card has been discarded
  preCouncil = 0;
  for (i = 0; i< pre.handCount[currentPlayer]; i++){
    //  printf("prehand[%d][%d]: %d\n", p, i, pre.hand[p][i]);
    if (pre.hand[currentPlayer][i] == council_room){
      preCouncil++;
    }
  }
  printf("Council count\t Expected: %d\t Result:%d\n", preCouncil - 1, (preCouncil - 1 + councilCount));
  //check discard count incremenetd
  printf("Discard count \t Expected: %d\t Result:%d\n", pre.discardCount[currentPlayer] + 1, post.discardCount[currentPlayer]);


  /***CHECK RESULTS***/
  failure->totalHand++;
  if (pre.handCount[currentPlayer] + 2 != post.handCount[currentPlayer]){
    printf("Unexpected handcount\n");
    fail = true;
    failure->handFail++;
  }
  failure->totalDeck++;
  if (pre.deckCount[currentPlayer] - 3 != post.deckCount[currentPlayer]){
    printf("Unexpected deckCount\n");
    fail = true;
    failure->deckFail++;
  }
  /*if ((deckCard1 != newCard1) || (deckCard2 != newCard2) || (deckCard3 != newCard3) || (deckCard4 != newCard4)){
    printf("Unexpected card added to hand\n");
    fail = true;
  }*/

  failure->totalBuys++;
  if (pre.numBuys + 1 != post.numBuys){
    printf("Unexpected number of buys\n");
    fail = true;
    failure->buyFail++;
  };
  //check card count for other players
  for (i = 0; i< p; i++){
    if (i != currentPlayer){
      failure->totalHandOther++;
      if (pre.handCount[i] + 1 != post.handCount[i]){
        printf("Unexpected Handcount p%d\n", i + 1);
        fail = true;
        failure->handOtherFail++;
      };
      failure->totalDeckOther++;
      if (pre.deckCount[i] - 1 != post.deckCount[i]){
        printf("Unexpected Deckcount p%d\n", i + 1);
        fail = true;
        failure->deckOtherFail++;
      }
    }
  }
  //check coin count has not changed
  failure->totalCoins++;
  if (pre.coins != post.coins){
    printf("Unexpected change in coin count\n");
    fail = true;
    failure->coinsFail++;
  }
  //check council count
  failure->totalCouncil++;
  if (preCouncil - 1 != (preCouncil -1 + councilCount)){
    printf("Council card not discarded\n");
    fail = true;
    failure->councilFail++;
  }

  //check discard pile incremented
  failure->totalDisc++;
  if (pre.discardCount[currentPlayer] + 1 != post.discardCount[currentPlayer]){
    printf("Discard count not incremented\n");
    fail = true;
    failure->discFail++;
  }

  if (fail == true){
    return -1;
  }

  return 0;
}

