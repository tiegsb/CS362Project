#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"


int main ()  {
    int i, j,p;

    int card;
    int testPass = 0;
    int testFail = 0;
    int currentPlayer;
    int result;

    int k[10] = {adventurer, council_room, feast, gardens, mine,
		 remodel, smithy, village, baron, great_hall};

    struct gameState G , g;

    printf ("RANDOM TESTS.\n");

    SelectStream(2);
    PutSeed(3);


    printf("Begining isGameOver Fuction Test\n");
      for (i = 0; i < sizeof(struct gameState); i++) { // Generate GameState
	((char*)&G)[i] = floor(Random() * 256);
      }
      p = floor(Random() * 3);
      G.whoseTurn = p;                  // Limits for the game to function
      G.deckCount[p] = floor(Random() * MAX_DECK);
      G.discardCount[p] = floor(Random() * MAX_DECK);
      G.handCount[p] = floor(Random() * MAX_HAND);



      memcpy (&g, &G, sizeof(struct gameState));       // Copy the generated gamestate
      G.supplyCount[province] = 0;
      g.supplyCount[1] = 0;
      g.supplyCount[11] = 0;
      g.supplyCount[5] = 0;

      result = isGameOver(&G);
      if(result == 1 && G.supplyCount[province] == 0)
	      testPass++;



      result = isGameOver(&g);
      j = 0;
      for (i = 0; i < 25; i++)
	{
	  if (g.supplyCount[i] == 0)
	    {
	      j++;
	    }
	}
      if(result == 1 &&  j >= 3)
	  testPass++;

      printf("Tests Passed:%d Tests Failed %d\n",testPass,testFail);
      printf("Testing End\n");












    return 0;
}
