#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"


int main ()  {

    int i, n, r, p, deckCount, discardCount, handCount;

    int test = 1;

    int card;
    int testPass = 0;
    int testFail = 0;
    int currentPlayer;

    int k[10] = {adventurer, council_room, feast, gardens, mine,
                 remodel, smithy, village, baron, great_hall};

    struct gameState G , g;

    SelectStream(2);
    PutSeed(3);


    printf("Begining Adventurer Card Fuction Test\n");


      initializeGame(2,k,3,&G);

       memcpy (&g, &G, sizeof(struct gameState));       // Copy the generated gamestate

      adventurerCardPlayed(&g);
      currentPlayer = whoseTurn(&g);

      discardCount =g.discardCount[currentPlayer] - G.discardCount[currentPlayer]; // get diffece of discards
      printf("HandCountAfter:%d HandCountbefore:%d\n",g.handCount[currentPlayer], G.handCount[currentPlayer]);
      printf("deckCountAfter:%d deckCountbefore:%d\n",g.deckCount[currentPlayer], G.deckCount[currentPlayer]);
      printf("discardCountAfter:%d discardCountbefore:%d\n",g.discardCount[currentPlayer], G.discardCount[currentPlayer]);

      for(i = 0 ; i < discardCount;i ++)
      {
	  printf("discard:%d deck:%d\n",g.discard[currentPlayer][G.discardCount[currentPlayer]+i],G.deck[currentPlayer][G.deckCount[currentPlayer]-1-i]);
	  if(g.discard[currentPlayer][G.discardCount[currentPlayer]+i] != G.deck[currentPlayer][G.deckCount[currentPlayer]-1-i]) {
		test = 0;
	  }

      }

      if( (g.handCount == (G.handCount+2))&&  test == 1)
	  testPass++;
      else
	  testFail++;


    printf("Tests Passed:%d Tests Failed %d\n",testPass,testFail);
    printf("Testing End\n");


  return 0;
}
