#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int testRefCouncil_Room(struct gameState *state, int handPos);

int testRefCouncil_Room(struct gameState *state, int handPos) {

    int i;
    int currentPlayer = whoseTurn(state);

    int tempDeckCount = 0;
    int tempDiscardCount = 0;
    int tempHandCount = 0;
    int pass = 0;
    int fail = 0;

    tempDeckCount = state->deckCount[currentPlayer];
    tempDiscardCount = state->discardCount[currentPlayer];
    tempHandCount = state->handCount[currentPlayer];

    //+4 Cards
    for (i = 0; i < 4; i++)
	{
	  drawCard(currentPlayer, state);
	}

    printf("Testing hand count increase\n");
    if(state->handCount[currentPlayer] != (tempHandCount + 4))
    {
        printf("Test failed\n");
        fail++;
    }
    else
    {
        printf("Test passed\n");
        pass++;
    }

    printf("Testing deck count decrease\n");
    if(state->deckCount[currentPlayer] != (tempDeckCount - 4))
    {
        printf("Test failed\n");
        fail++;
    }
    else
    {
        printf("Test passed\n");
        pass++;
    }

     //+1 Buy
    state->numBuys++;

     //Each other player draws a card
    for (i = 0; i < state->numPlayers; i++)
	{
	  if (i != currentPlayer)
      {
	      drawCard(i, state);
      }
	}

//tempDeckCount = state->deckCount[currentPlayer];


      //put played card in played card pile
      discardCard(handPos, currentPlayer, state, 0);

      printf("Testing discard count increase\n");
      if(state->discardCount[currentPlayer] >= (tempDiscardCount + 9)) //Normal discard of 5 plus extra 4
      {
          printf("Test failed\n");
          fail++;
      }
      else
      {
          printf("Test passed\n");
          pass++;
      }

      return 0;
}

int main()
{
    int retValue;
    int seed = 1000;
    int numPlayers = 2;
    int handPos = 1;

    struct gameState G;

    int kings[10] = {adventurer, council_room, feast, gardens, mine,
                     remodel, smithy, village, baron, great_hall};

    printf("*****Testing refactored Council Room function*****\n");

    initializeGame(numPlayers, kings, seed, &G);

    retValue = testRefCouncil_Room(&G, handPos);

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
