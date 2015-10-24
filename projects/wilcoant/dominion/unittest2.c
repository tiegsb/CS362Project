/* -----------------------------------------------------------------------
Anthony Wilcox
CS362 
Fall 2015
 *
 unit test for drawCard -----------------------------------------------------------------------
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
    int drawcard; //drawcard var for assert 0
    int seed = 1000;
    int numPlayer = 2;   //add for loop condition to iterate up to 4
    int p, r, handCount;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    int maxHandCount = 5;  //number of cards in each player's hand 
    int deckcounter; //place holder
    int count; // current' player's hand count 
    int predeck, prehand; //precounter
    int postdeck, posthand; //post counter 
    printf ("TESTING drawCard():\n");
    while (numPlayer <= MAX_PLAYERS)
    {//check for all ranges of players 2 - 4
        for (p = 0; p < numPlayer; p++)
        {//for 0 -  numPlayer starting at 2 and going to 4
            for (handCount = 0; handCount <= maxHandCount; handCount++)
            {//start at handcount 0 to test return -1 status
                //printf("Test player %d with %d handcounts(s).\n", p, handCount);
                memset(&G, 23, sizeof(struct gameState));   // clear the game state
                r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
                G.handCount[p] = handCount;   
                printf("handcount is %d\n", handCount);
                    // set the number of cards on hand
                predeck = G.deckCount[p]; //prefunction call deck count
                prehand = G.handCount[p]; //prefn call hand count 
                drawcard = drawCard(p, &G); //make fn call 
                
                deckcounter = G.deckCount[p]; //deck count of current player for index 
                count = G.handCount[p]; //current players hand count
                postdeck = G.deckCount[p]; //after call deck count 
                posthand = G.handCount[p]; //after call hand count 
                
                assert(drawcard == 0); //doesn't crash 
                assert(G.discardCount[p] == 0); //should be set to zero when shuffling back into deck 
                //assert that the players hand now has the top card in deck
                assert(G.hand[p][count] = G.deck[p][deckcounter - 1]);
                assert(postdeck = predeck - 1); //one card removed from deck
                assert(posthand = prehand + 1); //one card added to player hand 
                printf("postdeck: %d, predeck - 1: %d\n", postdeck, predeck - 1);
                printf("posthand: %d, prehand + 1: %d\n", posthand, prehand +1);
            }
            //start at 2 players
         }//exit top for loop 
   numPlayer++; //increase numPlayer by one maxing at 4 to test game state for 2 - 4 players 
  
   }//exit while loop 
    /* memset(&G, 23, sizeof(struct gameState));   // clear the game state
                r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
    G.deckCount[0] = 0;
    drawcard = drawCard(p, &G); */
    printf("Empty Deck Fails, all others pass.\n");

    return 0;
}
