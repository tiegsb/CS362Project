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



void testUpdateCoins()
{


int i;
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

firstHand[0] = copper;
firstHand[1] = copper;
firstHand[2] = estate;
firstHand[3] = smithy;
firstHand[4] = great_hall;

//init game state
initializeGame(numPlayer, k, seed, &G);


//place cards in test player's hand
G.handCount[testPlayer]= handCount;

//place cards in test player's hand
//new state
memcpy(G.hand[testPlayer], firstHand, sizeof(int) * handCount);
//the for loop iterates through the function
//it checks the number of coins per iteration, with an added "bonus" roll
//outputs pass/fail based on value of coins on state

for(i=0; i < 100; i++)
{
    int testIterator = 2; //this is because that would be the the value of coins without bonus
    updateCoins(testPlayer, &G, i);
    if(G.coins == testIterator+i)
    {
        printf ("Passed, results : %d\n", G.coins);
    }
    else
        {
            printf ("Failed, expected : %d\n", testIterator+i);
        }

}

}

int main() {
//runs the test update coins function
	testUpdateCoins();


    return 0;
}
