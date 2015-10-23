/* -----------------------------------------------------------------------
 * unit test for scoreFor  -----------------------------------------------------------------------
 */
//used provided testUpdateCoins.c shell provided in OSU Fall CS362
//modified some initialation variables to test boundaries more completely
 
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
int main() {
    int a, b, c, r; //integer vars for score comps and game init  
    int p, i;
    int seed = 1000;
    int numPlayer = 2; //initial number of players 
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
    
    while (numPlayer <= MAX_PLAYERS)
    {//check for all ranges of players 2 - 4
        for (p = 0; p < numPlayer; p++)
        {//for 0 -  numPlayer starting at 2 and going to 4
             /*set all counts equal to treasure map enum since that's
            how many cards you just put in*/
            G.handCount[p] = treasure_map;
            G.deckCount[p] = treasure_map;
            G.discardCount[p] = treasure_map;
            for (i = 0; i <= treasure_map; i++)
            {//populate hand, discardcount, deck with all enumerated cards
                G.hand[p][i] = i;
                G.discard[p][i] = 7; //adventurer, no value 
                G.deck[p][i] = 7;  //adventurer, no value in score fn 
            }
           /*now call scoreFor to see if the all three piles are properly totaled.  there is only one of each type of each scoring card in 
            each of the piles so they should all be equal to each other*/
            a = scoreFor(p, &G);
            for (i = 0; i <= treasure_map; i++)
            {//populate hand, discardcount, deck with all enumerated cards
                G.hand[p][i] = 7; //adventurer, no value 
                G.discard[p][i] = i; 
                G.deck[p][i] = 7;  //adventurer, no value in score fn 
            }
            b = scoreFor(p, &G);
            for (i = 0; i <= treasure_map; i++)
            {//populate hand, discardcount, deck with all enumerated cards
                G.hand[p][i] = 7; //adventurer, no value 
                G.discard[p][i] = 7; //adventurer, no value in score fn  
                G.deck[p][i] = i;  
            }
            /*all should be equal since all conditions were same when
            checking score of each pile of cards, the same cars were 
            in them*/
            c = scoreFor(p, &G);
            printf("hand is %d; discard is %d, deck is %d\n", a, b, c);
            assert((a == b));
            assert((b == c));
            //start at 2 players
         }//exit top for loop 
   numPlayer++; //increase numPlayer by one maxing at 4 to test game state for 2 - 4 players 
  
   }//exit while loop 
    
    printf("All tests passed!\n");

    return 0;
}
