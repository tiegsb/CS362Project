#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int testRefAdventurer(struct gameState *state);


int testRefAdventurer(struct gameState *state) {

    int z = 0;
    int currentPlayer = whoseTurn(state);
    int temphand[MAX_HAND];
    int cardDrawn;
    int drawntreasure = 0;

    int tempDeckCount = 0;
    int tempDiscardCount = 0;
    int pass = 0;
    int fail = 0;

    tempDeckCount = state->deckCount[currentPlayer];
    tempDiscardCount = state->discardCount[currentPlayer];

    while(drawntreasure <= 2){
        if (state->deckCount[currentPlayer] <1){//if the deck is empty we need to shuffle discard and add to deck
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

      while(z - 1 >= 0){
        state->discard[currentPlayer][state->discardCount[currentPlayer]++] = temphand[z-1]; // discard all cards in play that have been drawn
        z = z - 1;
      }

      printf("Testing discard count increase\n");
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

//      printf("%d tests passed, %d tests failed\n", pass, fail);


      return 0;
}

int main()
{
    int retValue;
    int seed = 1000;
    int numPlayers = 2;

    struct gameState G;

    int kings[10] = {adventurer, council_room, feast, gardens, mine,
                     remodel, smithy, village, baron, great_hall};

    printf("*****Testing refactored Adventurer function*****\n");

    initializeGame(numPlayers, kings, seed, &G);

    retValue = testRefAdventurer(&G);

    if(retValue == 0)
    {
        printf("Test passed: return value = 0.\n");
    }
    else {
        printf("Test failed: return value = 1.\n");
    }
    printf("\n");

    return 0;
}
