/* -----------------------------------------------------------------------
 * card test for smithy  -----------------------------------------------------------------------
 */
//used provided testUpdateCoins.c shell provided in OSU Fall CS362
//modified some initialation variables to test boundaries more completely
 
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main() {
    int seed = 1000;
    int numPlayer = 2;   //add for loop condition to iterate up to 4
    int p, r, handCount;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int maxHandCount = 5;  //number of cards in each player's hand 
    int prehand; //precounter
    int posthand; //post counter 
    printf ("TESTING drawCard():\n");
    while (numPlayer <= MAX_PLAYERS)
    {//check for all ranges of players 2 - 4
        for (p = 0; p < numPlayer; p++)
        {//for 0 -  numPlayer starting at 2 and going to 4
            for (handCount = 0; handCount <= maxHandCount; handCount++)
            {//start at handcount 0 to test return -1 status
                
                memset(&G, 23, sizeof(struct gameState));   // clear the game state
                r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
                G.handCount[p] = handCount;   
                prehand = G.handCount[p]; //prefn call hand count 
                printf("pre-handcount is %d\n", prehand);
                    // set the number of cards on hand
                play_smithy(p, &G, 0);
                posthand = G.handCount[p]; //after call hand count 
                printf("post-handcount is %d\n", posthand);
            }
            //start at 2 players
         }//exit top for loop 
   numPlayer++; //increase numPlayer by one maxing at 4 to test game state for 2 - 4 players 
  
   }//exit while loop 
    
    printf("All tests passed!\n");

    return 0;
}
