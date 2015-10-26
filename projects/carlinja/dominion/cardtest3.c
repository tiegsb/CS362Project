/* -----------------------------------------------------------------------
 * James Carlin
 * 10/20/2015
 *
 * CardTest2
 *  Tests the greatHallCard
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"



void testGreatHall()
{



    int seed = 1000;
    int numPlayer = 2;

    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
	int testPlayer=1;
	int handCount=5;
//initialize gamestate
    struct gameState G;


//loading hand with 5 cards first, hardcoded in

int firstHand[5];

//place specific cards in each possible spot

firstHand[0] = feast;
firstHand[1] = feast;
firstHand[2] = estate;
firstHand[3] = smithy;
firstHand[4] = great_hall;


initializeGame(numPlayer, k, seed, &G);

//set specifics for new game state

G.handCount[testPlayer]= handCount;

//place cards in test player's hand

memcpy(G.hand[testPlayer], firstHand, sizeof(int) * handCount);

//The adventure card has two basic functions
//draws cards until two treasures are drawn
//discards all other cards

//now to test actual function

greatHallCard(&G, testPlayer, 4);

//now going to test state after passing correct values
//since it adds two treasures, handCount should be at 7

if(G.numActions == 2)
{
    printf ("Passed, game action =3, expected %d\n", G.numActions);
}
else if(G.numActions == 3)
{
    printf("Failed, game action = %d cards, expected 2\n", G.numActions);
    printf("This occurs because of a bug I introduced, else would be 2");
}
else
    {
    printf ("Failed, game action = %d cards, expected 3\n", G.numActions);

    }

}

int main() {

	testGreatHall();


    return 0;
}
