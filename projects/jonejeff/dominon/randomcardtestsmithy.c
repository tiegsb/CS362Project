#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"


int main ()  {

    int i, n, r, p, deckCount, discardCount, handCount;

    int test = 1;
    int result;

    int card;
    int testPass = 0;
    int testFail = 0;
    int currentPlayer;

    int k[10] = {adventurer, council_room, feast, gardens, mine,
		 remodel, smithy, village, baron, great_hall};

    struct gameState G , g;

    SelectStream(2);
    PutSeed(3);


    printf("Begining Smithy Card Fuction Test\n");


    for (n = 0; n < 2000; n++) { // Testing Loop
      for (i = 0; i < sizeof(struct gameState); i++) { // Generate GameState
	((char*)&G)[i] = floor(Random() * 256);
      }
      p = floor(Random() * 3);
      G.whoseTurn = p;                  // Limits for the game to function
      G.deckCount[p] = floor(Random() * (MAX_DECK));
      G.discardCount[p] = floor(Random() * (MAX_DECK));
      G.handCount[p] = floor(Random() * MAX_HAND);
      G.playedCardCount = floor(Random() * (MAX_DECK));

      printf("handCount:%d\n",G.handCount[p]);

      memcpy (&g, &G, sizeof(struct gameState));       // Copy the generated gamestate

      currentPlayer = whoseTurn(&G);
      if(whoseTurn(&G) != whoseTurn(&g))
	  printf("CurrentPlayer mismatch\n");

      result = smithyCardPlayed(&g,0);

      if(g.handCount[currentPlayer] == (G.handCount[currentPlayer]+2) && g.deckCount[currentPlayer] == (G.deckCount[currentPlayer]-3))
	  testPass++;
      else
	  testFail++;
     printf("HandCountAfter:%d HandCountbefore:%d\n",g.handCount[currentPlayer], G.handCount[currentPlayer]);
     printf("discardCountAfter:%d discardCountbefore:%d\n",g.discardCount[currentPlayer], G.discardCount[currentPlayer]);
     printf("deckCountAfter:%d deckCountbefore:%d\n",g.deckCount[currentPlayer], G.deckCount[currentPlayer]);
    }
    printf("Tests Passed:%d Tests Failed %d\n",testPass,testFail);
    printf("Testing End\n");


  return 0;
}
