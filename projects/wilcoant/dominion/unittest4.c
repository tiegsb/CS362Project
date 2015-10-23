//if supplycount i ! = 0 then set = 0 then call isgame over
/* -----------------------------------------------------------------------
 * unit test for isgameover  -----------------------------------------------------------------------
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
    int r; //integer vars for score comps and game init  
    int i; //loop counter 
    int seed = 1000;
    int numPlayer = 2; //initial number of players 
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
    for(i = 0; i <= treasure_map; i++)
    {
        if(G.supplyCount[i] != 0)
        {//if there is currently a supply, set to zero
            G.supplyCount[i] = 0; 
        }
    }
    r = isGameOver(&G);
    printf("r is: %d\n", r);
    assert(r = 1); //game has ended since all supply levels are 0 so definitely three piles are 0
    /*init new game, check province condition*/
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
    G.supplyCount[3] = 0; //Province cards are at 0, game ending condition 
    r = isGameOver(&G); //see if province ends game 
    printf("r is: %d\n", r);
    assert(r = 1); //if province is zero the game should properly end 
    
} //exit main 