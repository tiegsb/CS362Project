#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define NUMTESTS 10

int testAdventurer(struct gameState *state, int *pass, int *fail);


int main()
{
    int i;
    int retValue;
    int seed = rand();
    int numPlayers, p;
    struct gameState G;
    int pass = 0;
    int fail = 0;

    int kings[10] = {adventurer, council_room, feast, gardens, mine,
                     remodel, smithy, village, baron, great_hall};

    printf("*****Random Testing of Adventurer Card function*****\n");
    printf("The Adventurer Card has the player draw cards until 2 treasure cards are drawn\n");

    for(i = 0; i < NUMTESTS; i++) {
        numPlayers = 1 + (rand() % 4);
        initializeGame(numPlayers, kings, seed, &G);
        p = rand() % numPlayers;

        G.deckCount[p] = rand() % MAX_DECK;
        G.discardCount[p] = rand() % MAX_DECK;

        retValue = testAdventurer(&G, &pass, &fail);

    }
    printf("\n");
    //printf("%d tests passed, %d tests failed\n", pass, fail);

    return 0;
}
int testAdventurer(struct gameState *state, int *pass, int *fail) {

    int z = 0;
    int currentPlayer = whoseTurn(state);
    int temphand[MAX_HAND];
    int cardDrawn;
    int drawntreasure = 0;

    int tempDeckCount = 0;
    int tempDiscardCount = 0;
    int tempCoinCount = 0;

    tempDeckCount = state->deckCount[currentPlayer];
    tempDiscardCount = state->discardCount[currentPlayer];
    tempCoinCount = state->coins;

    while(drawntreasure <= 2){
        if (state->deckCount[currentPlayer] < 1){//if the deck is empty we need to shuffle discard and add to deck
          shuffle(currentPlayer, state);
        }
        drawCard(currentPlayer, state);
        cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];//top card of hand is most recently drawn card.
        if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
          drawntreasure++;
        else{
          temphand[z] = cardDrawn;
          state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
          z++;
        }
      }

      printf("Testing deck count decrease\n");
      printf("Pre-function count %d, post-function count %d\n", tempDeckCount, state->deckCount[currentPlayer]);
      if(state->deckCount[currentPlayer] >= (tempDeckCount - 2))
      {
          printf("Test failed\n");
          fail++;
      }
      else
      {
          printf("Test passed\n");
          pass++;
      }

      printf("\n");
      printf("Testing number of treasure drawn\n");
      printf("Expected: 2; actual: %d\n", drawntreasure);
      if(state->coins != 2) {
          printf("Test failed\n");
          fail++;
      }
      else
      {
          printf("Test passed\n");
          pass++;
        }

      while(z - 1 >= 0){
        state->discard[currentPlayer][state->discardCount[currentPlayer]++] = temphand[z-1]; // discard all cards in play that have been drawn
        z = z - 1;
      }

      printf("Testing discard count increase\n");
      printf("Pre-function count %d, post-function count %d\n", tempDeckCount, state->deckCount[currentPlayer]);

      if(state->discardCount[currentPlayer] >= (tempDiscardCount + 7))
      {
          printf("Test failed\n");
          fail++;
      }
      else
      {
          printf("Test passed\n");
          pass++;
      }

      //printf("%d tests passed, %d tests failed\n", pass, fail);


      return 0;
}
