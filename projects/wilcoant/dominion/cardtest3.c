/* -----------------------------------------------------------------------
 * card test for council_room -----------------------------------------------------------------------
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
    int test;
    int counc; //return value from council_room
    int prebuy; //precounter
    int posthand, postbuy; //post counter 
    int seed = 1000;
    int numPlayer = 2;   //add for loop condition to iterate up to 4
    int p, r, handCount;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int maxHandCount = 5;  //number of cards in each player's hand 
    printf ("TESTING drawCard():\n");
    while (numPlayer <= MAX_PLAYERS)
    {//check for all ranges of players 2 - 4
        for (p = 0; p < numPlayer; p++)
        {//for 0 -  numPlayer starting at 2 and going to 4
            for (handCount = 0; handCount < maxHandCount; handCount++)
            {//start at handcount 0 to test return -1 status
                
                memset(&G, 23, sizeof(struct gameState));   // clear the game state
                r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
                prebuy = G.numBuys;
                counc = play_council(&G, p, handCount);
                /*posthand should yield the total number of 
                cards drawn per card play, each non player
                gets one and the player themself gets 4*
                proper fn then return value will e same as 
                 post hand*/
                posthand = (numPlayer - 1) + 4; 
                postbuy = G.numBuys;
                printf("Counc = %d, posthand = %d\nprebuy= %d, postbuy = %d\n", counc, posthand, prebuy, postbuy );
                prebuy = 0;
                counc = 0;
                postbuy = 0;
                posthand = 0;
            }
            //start at 2 players
         }//exit top for loop 
   numPlayer++; //increase numPlayer by one maxing at 4 to test game state for 2 - 4 players 
  
   }//exit while loop 
    
    printf("Test Failure if all counc values != posthand\nand postbuy != prebuy + 1.");

    return 0;
}
