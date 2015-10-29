#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"


int main ()  {

    int i, n, r, p, deckCount, discardCount, handCount;

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


    printf("Begining gain Card Fuction Test\n");

    for (n = 0; n < 2000; n++) { // Testing Loop
      for (i = 0; i < sizeof(struct gameState); i++) { // Generate GameState
	((char*)&G)[i] = floor(Random() * 256);
      }
      p = floor(Random() * 3);
      G.whoseTurn = p;                  // Limits for the game to function
      G.deckCount[p] = floor(Random() * MAX_DECK);
      G.discardCount[p] = floor(Random() * MAX_DECK);
      G.handCount[p] = floor(Random() * MAX_HAND);


      memcpy (&g, &G, sizeof(struct gameState));       // Copy the generated gamestate
      currentPlayer = whoseTurn(&G);
      result = gainCard(n%(treasure_map+1),&g,n%3,currentPlayer); // The first value sends in a vaild kingdom card, The randomized game state, a vaild toFlag and the current player

      if(result == -1)  {
	  if(g.supplyCount[n%27] == G.supplyCount[n%27]) {
	      testPass++;
	  } else  {
	      testFail++;
	      printf("f0");
	  }
      } else if(result == 0)  {
	  if (n%3 == 1)
	    {
	      if (((g.deck[ currentPlayer ][ g.deckCount[currentPlayer]-1 ]) == (n%27)) && (g.deckCount[currentPlayer] == (G.deckCount[currentPlayer]+1)))
		  testPass++;
	      else {
		  testFail++;
		  printf("f1");
	      }

	    }
	  else if (n%3 == 2)
	    {
	      if ((g.hand[currentPlayer ][ g.handCount[currentPlayer]-1 ] == (n%27)) && (g.handCount[currentPlayer] == (G.handCount[currentPlayer]+1)))
		  testPass++;
	      else {
		  testFail++;
		  printf("f2");
	      }
	    }
	  else if (n%3 == 0)
	    {
	      if ((g.discard[ currentPlayer ][ g.discardCount[currentPlayer]-1 ] == (n%27)) && (g.discardCount[currentPlayer] == (G.discardCount[currentPlayer]+1)))
		  testPass++;
	      else {
		  testFail++;
		  printf("f3");
	      }
	    }
      } else {
		       testFail++;
		       printf("f4");
      }


    }
    printf("Tests Passed:%d Tests Failed %d\n",testPass,testFail);
    printf("Testing End\n");


  return 0;
}
