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


    SelectStream(2);
    PutSeed(3);


    printf("Begining Smithy Card Fuction Test\n");

    initializeGame(2,k,3,&G);

    memcpy (&g, &G, sizeof(struct gameState));       // Copy the generated gamestate
    currentPlayer = whoseTurn(&G);

    result = smithyCardPlayed(&g,0);

    if(g.handCount[currentPlayer] == (G.handCount[currentPlayer]+2) && g.deckCount[currentPlayer] == (G.deckCount[currentPlayer]-3))
	testPass++;
    else
	testFail++;
   printf("HandCountAfter:%d HandCountbefore:%d\n",g.handCount[currentPlayer], G.handCount[currentPlayer]);
   printf("discardCountAfter:%d discardCountbefore:%d\n",g.discardCount[currentPlayer], G.discardCount[currentPlayer]);
   printf("deckCountAfter:%d deckCountbefore:%d\n",g.deckCount[currentPlayer], G.deckCount[currentPlayer]);


    printf("Tests Passed:%d Tests Failed %d\n",testPass,testFail);
    printf("Testing End\n");


  return 0;
}
