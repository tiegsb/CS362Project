/* 
Anthony Wilcox
CS362 
Fall 2015
-----------------------------------------------------------------------
 * card test for village  -----------------------------------------------------------------------
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
    int test1, test2; //for hand val of each player to compare to counter
    int vil; //return value from council_room
    int preact; //precounter
    int postact; //post counter 
    int seed = 1000;
    int numPlayer = 2;   //add for loop condition to iterate up to 4
    int p, r, handCount;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int maxHandCount = 5;  //number of cards in each player's hand 
    printf ("TESTING village():\n");
    while (numPlayer <= MAX_PLAYERS)
    {//check for all ranges of players 2 - 4
        for (p = 0; p < numPlayer; p++)
        {//for 0 -  numPlayer starting at 2 and going to 4
            for (handCount = 0; handCount < maxHandCount; handCount++)
            {//start at handcount 0 to test return -1 status
                
                memset(&G, 23, sizeof(struct gameState));   // clear the game state
                r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
                preact = G.numActions;
                test1 = G.handCount[p];
                vil = play_village(p, handCount, &G);
                /*actions shoudl increase by two
                player hand count should go up by one 
                vil should equal test2 if drawCard is working*/
                postact = G.numActions;
                test2 = G.handCount[p];
                printf("test1 is: %d, test2 is: %d\npreact is: %d, postact is: %d\n", test1, test2, preact, postact);
            }
            //start at 2 players
         }//exit top for loop 
   numPlayer++; //increase numPlayer by one maxing at 4 to test game state for 2 - 4 players 
  
   }//exit while loop 
    
    printf("Test Failure if test1 != test2\nTest Faulure if postact != preact + 2.\n");

    return 0;
}
