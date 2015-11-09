/*----------------------------------------------------------------------
* Name: Susan Lee
* Class: CS 362_400_F2015
* Homework 4
* Random tester for adventurer card
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
  int treasureFail;
  int handOtherFail;
  int coinsFail;
  int adventurerFail;
  int totalHand;
  int totalDeck;
  int totalDisc;
  int totalTreasure;
  int totalHandOther;
  int totalCoins;
  int totalAdventurer;
};

int initFailures(struct failures *fail);
void setDeck(struct gameState *G, int numPlayers);
void setHand(struct gameState *G, int numPlayers);
int checkAdventurer(int p, struct gameState post, struct failures *failure, int currentPlayer);

int main(){

  int seed = 1000;
  int n, i, r;
  //int result = 0;
  //bool pass = true;
  int p = 0;

  int k[10] = { adventurer, council_room, feast, gardens, mine
    , remodel, smithy, village, baron, great_hall };
  struct gameState G;
  struct failures fail;

  initFailures(&fail);

  SelectStream(2);
  PutSeed(3);
  srand(time(NULL));

  //The following random loop was inspired by Lecture 11 CS 362
  for (n = 0; n < 3000; n++){
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
     //printf("\np before init is: %d\n", p);
     seed = floor(Random() * 5000);
     r = initializeGame(p, k, seed, &G); //initialize game
     //printf("p after init is: %d\n", p);
     for (i = 0; i < p; i++){
       G.deckCount[i] = floor(Random() * MAX_DECK);
       //printf("deckCount %d\n", G.deckCount[i]);
       G.discardCount[i] = floor(Random() * MAX_DECK);
       //printf("dicardCount %d\n", G.discardCount[i]);
       G.handCount[i] = floor(Random() * MAX_HAND);
       //printf("handCount %d\n", G.handCount[i]);
     }
     //set cards, set top card in hand to be adventurer card
     setDeck(&G, p);
     setHand(&G, p);

     //run check on gamestate for adventurer card
     for (i = 0; i < p; i++){
       G.coins = floor(Random() * 50);
       checkAdventurer(p, G, &fail, i);
     }
     //clear game state
     memset(&G, 23, sizeof(struct gameState));

  }

  //print out summary results
  printf("\nADVENTURER FAILURE SUMMARY: \n");
  printf("********************************\n");
  printf("Hand count failures: %d/%d\n", fail.handFail, fail.totalHand);
  printf("Deck count failures: %d/%d\n", fail.deckFail, fail.totalDeck);
  printf("Discard count failures: %d/%d\n", fail.discFail, fail.totalDisc);
  printf("Treasure card failures: %d/%d\n", fail.treasureFail, fail.totalTreasure);
  printf("Other Players' hand count failures: %d/%d\n", fail.handOtherFail, fail.totalHandOther);
  printf("Coin count failures: %d/%d\n", fail.coinsFail, fail.totalCoins);
  printf("Adventurer count failures: %d/%d\n\n", fail.adventurerFail, fail.totalAdventurer);
  return 0;
}

int initFailures(struct failures *fail){
   fail->handFail=0;
   fail->deckFail=0;
   fail->discFail=0;
   fail->treasureFail = 0;
   fail->handOtherFail = 0;
   fail->coinsFail = 0;
   fail->adventurerFail = 0;
   fail->totalHand = 0;
   fail->totalDeck = 0;
   fail->totalDisc = 0;
   fail->totalTreasure = 0;
   fail->totalHandOther = 0;
   fail->totalCoins = 0;
   fail->totalAdventurer = 0;
   return 0;
}

void setDeck(struct gameState *G, int numPlayers){
  int j, p;

  for (p = 0; p < numPlayers; p++){
    for (j = 0; j < G->deckCount[p]; j++){
      G->deck[p][j] = floor(Random() * 26);
    }
  }
  //test for no trasure cards
  for (j = 0; j < G->deckCount[p]; j++){
    G->deck[0][j] = baron;
  }
  
  
}

void setHand(struct gameState *G, int numPlayers){
  int j, p;

  for (p = 0; p < numPlayers; p++){
    for (j = 0; j < G->handCount[p]-1; j++){
      G->hand[p][j] = floor(Random() * 26);
    }
    G->hand[p][G->handCount[p] - 1] = adventurer;
  }
  
}

int checkAdventurer(int p, struct gameState post, struct failures *failure, int currentPlayer) {

  struct gameState pre;
  int i;
  //int currentPlayer = 0;
  int temphand[MAX_HAND];
  int result; //to store the number of cards cycled through
  int preAdventurer, postAdventurer;
  int treasureCount = 0;
  bool fail = false;
  int expDeckCount = 0;
  int expHandCount = 0;
  int expDiscCount = 0;

  //copy the game state to compare pre and post values
  memcpy(&pre, &post, sizeof(struct gameState));

  result = adventurerAction(currentPlayer, &post, temphand);
  printf("Result is %d\n", result);
  printf("discardCard is %d\n", post.discardCount[currentPlayer]);
  
  //how many treasurer cards in deck?
  for (i = 0; i < pre.deckCount[currentPlayer]; i++){
    if ((pre.deck[currentPlayer][i] == gold) || (pre.deck[currentPlayer][i] == silver) || (pre.deck[currentPlayer][i] == copper)){
      treasureCount++;
    }
  }
  //check how many treasurer cards in discard pile
  for (i = 0; i < pre.discardCount[currentPlayer]; i++){
    if ((pre.discard[currentPlayer][i] == gold) || (pre.discard[currentPlayer][i] == silver) || (pre.discard[currentPlayer][i] == copper)){
      treasureCount++;
    }
  }
  printf("TreasureCount %d\n", treasureCount);
  if (p != 0){
    //check hand count
    //if only 1 treasure card in player's hand/discard pile
    if (treasureCount == 0){
      expHandCount = pre.handCount[currentPlayer] - 1;
    } else if (treasureCount == 1){
      expHandCount = pre.handCount[currentPlayer];
    } else{
      expHandCount = pre.handCount[currentPlayer] + 2 - 1;
    }
    printf("Hand Count\t Expected:%d\t Result:%d\n", expHandCount, post.handCount[currentPlayer]);

    //check deck count
    //if shuffle deck was called, indicating the deck count ran out, and the discard pile was shuffled back into the deck
    if (pre.deckCount[currentPlayer] - result < 0){
      expDeckCount = pre.deckCount[currentPlayer] - result + pre.discardCount[currentPlayer];
      expDiscCount = result + 1;
    }else{
      expDeckCount = pre.deckCount[currentPlayer] - result;
      expDiscCount = pre.discardCount[currentPlayer] + result + 1;
    }
    printf("Deck Count\t Expected:%d\t Result:%d\n", expDeckCount, post.deckCount[currentPlayer]);

    //check discard pile
    //should be + the cards cycled through and the discarded adventurer card
    printf("Discard Count\t Expected:%d\t Result:%d\n", expDiscCount, post.discardCount[currentPlayer]);

    //check card count for all other players
    //currentPlayer = p;
    for (i = 0; i< p; i++){
      if (i != currentPlayer)
        printf("HandCount for player %d\t Expected: %d\t Result:%d\n", i + 1, pre.handCount[i], post.handCount[i]);
    }

    //check count of coins has not changed
    printf("Coins\t Expected: %d\t Result:%d\n", pre.coins, post.coins);

    //check Adventurer Card has been discarded
    preAdventurer = 0;
    postAdventurer = 0;
    for (i = 0; i< pre.handCount[currentPlayer]; i++){
      //  printf("prehand[%d][%d]: %d\n", p, i, pre.hand[p][i]);
      if (pre.hand[currentPlayer][i] == adventurer){
        preAdventurer++;
      }
    }
    //iterate through post hand 
    for (i = 0; i< post.handCount[currentPlayer]; i++){
      //   printf("posthand[%d][%d]: %d\n", p, i, post.hand[p][i]);
      if (post.hand[currentPlayer][i] == adventurer){
        postAdventurer++;
      }
    }
    printf("Adventurer count\t Expected: %d\t Result:%d\n", preAdventurer - 1, postAdventurer);


    /***CHECK RESULTS***/
    failure->totalHand++;
    if (expHandCount != post.handCount[currentPlayer]){
      printf("Unexpected handcount\n");
      fail = true;
      failure->handFail++;
    }

    failure->totalDeck++;
    if (expDeckCount != post.deckCount[currentPlayer]){
      printf("Unexpected deckCount\n");
      fail = true;
      failure->deckFail++;
    }

    failure->totalDisc++;
    if (expDiscCount != post.discardCount[currentPlayer]){
      printf("Unexcpected discardCount\n");
      fail = true;
      failure->discFail++;
    }

    //since no handpos is passed in to function, and no discarding
    //is called in code, can safely assume that the last two cards
    //post hand will be the found treasure cards
    if (treasureCount > 1){
      failure->totalTreasure++;
      if ((post.hand[currentPlayer][post.handCount[currentPlayer] - 1] != gold)
        && (post.hand[currentPlayer][post.handCount[currentPlayer] - 1] != silver)
        && (post.hand[currentPlayer][post.handCount[currentPlayer] - 1] != copper)){
        printf("Treasurer card not added to hand\n");
        fail = true;
        failure->treasureFail++;

      }
      failure->totalTreasure++;
      if ((post.hand[currentPlayer][post.handCount[currentPlayer] - 2] != gold)
        && (post.hand[currentPlayer][post.handCount[currentPlayer] - 2] != silver)
        && (post.hand[currentPlayer][post.handCount[currentPlayer] - 2] != copper)){
        printf("Treasurer card not added to hand\n");
        fail = true;
        failure->treasureFail++;
      }
    } else{
      failure->totalTreasure++;
      if ((post.hand[currentPlayer][post.handCount[currentPlayer] - 1] != gold)
        && (post.hand[currentPlayer][post.handCount[currentPlayer] - 1] != silver)
        && (post.hand[currentPlayer][post.handCount[currentPlayer] - 1] != copper)){
        printf("Treasurer card not added to hand\n");
        fail = true;
        failure->treasureFail++;
      }
   }

    //check card count for other players
    for (i = 0; i< p; i++){
      if (i != currentPlayer){
        failure->totalHandOther++;
        if (pre.handCount[i] != post.handCount[i]){
          printf("Unexpected handcount change in other player\n");
          fail = true;
          failure->handOtherFail++;
          break;
        }
      }
    }
    //check coin count has not changed
    failure->totalCoins++;
    if (pre.coins != post.coins){
      printf("Unexpected change in coin count\n");
      return -1;
      fail = true;
      failure->coinsFail++;
    }
    //check adventurer count
    failure->totalAdventurer++;
    if (preAdventurer - 1 != postAdventurer){
      printf("Adventurer card not discarded\n");
      fail= true;
      failure->adventurerFail++;
    }
    //for 0 deck
  }else{
    //check hand count
    //should be +2 treasure cards -1 discarded adventurer card
    printf("Hand Count\t Expected:%d\t Result:%d\n", pre.handCount[currentPlayer], post.handCount[currentPlayer]);

    //check deck count
    printf("Deck Count\t Expected:%d\t Result:%d\n", pre.deckCount[currentPlayer] - result, post.deckCount[currentPlayer]);

    //check discard pile
    //should be + the cards cycled through and the discarded adventurer card
    printf("Discard Count\t Expected:%d\t Result:%d\n", pre.discardCount[currentPlayer], post.discardCount[currentPlayer]);

    //check results
    failure->totalHand++;
    if (pre.handCount[currentPlayer] != post.handCount[currentPlayer]){
      printf("Unexpected handcount\n");
      fail = true;
      failure->handFail++;
    }

    failure->totalDeck++;
    if (pre.deckCount[currentPlayer] != post.deckCount[currentPlayer]){
      printf("Unexcpected deckCount\n");
      fail = true;
      failure->deckFail++;
    }

    failure->totalDisc++;
    if (pre.discardCount[currentPlayer] != post.discardCount[currentPlayer]){
      printf("Unexcpected discardCount\n");
      fail = true;
      failure->discFail++;
    }
  }

  if (fail == true){
    return -1;
  }

  return 0;
}

