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

    int k[10] = {adventurer, council_room, feast, gardens, mine,
                 remodel, smithy, village, baron, great_hall};

    struct gameState G , g;

    printf ("RANDOM TESTS.\n");

    SelectStream(2);
    PutSeed(3);


    printf("Begining Hand Card Fuction Test\n");

    for (n = 0; n < 2000; n++) { // Testing Loop
      for (i = 0; i < sizeof(struct gameState); i++) { // Generate GameState
        ((char*)&G)[i] = floor(Random() * 256);
      }
      p = floor(Random() * 3);
      G.whoseTurn = p;                  // Limits for the game to function
      G.handCount[p] = (int)(floor(Random() * MAX_HAND)) % MAX_HAND;


      memcpy (&g, &G, sizeof(struct gameState));       // Copy the generated gamestate
      currentPlayer = whoseTurn(&G);

      for (r = 0; r < G.handCount[currentPlayer]; r++)  {              // Check entire hand
          card = handCard(r,&g);
          if(card == G.hand[currentPlayer][r])  {
              testPass++;
          } else {
              testFail++;
          }

      }


    }
    printf("Tests Passed:%d Tests Failed %d\n",testPass,testFail);
    printf("Testing End\n");


  return 0;
}
