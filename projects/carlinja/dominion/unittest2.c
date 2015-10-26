/* -----------------------------------------------------------------------
 * James Carlin
 * 10/20/2015
 *
 * CardTest2
 *  Tests the isGameOver() card
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"



void testGameOver()
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
//will test various amounts of supply
//to make sure test fails/passes


//first with province at 0

G.supplyCount[province] = 0;

if(isGameOver(&G))
    printf("Passed with pile empty. Game ENDS\n");
else
    printf("Failed when pile is empty. Game DOES NOT end\n");

//add one to supplycount
//I use !isGameOver because it should return 1,

G.supplyCount[province]++;
if(isGameOver(&G))
    printf("Failed with one province. Game ENDS\n");
else
    printf("Passed with one province. Game DOES NOT end\n");
//add another
//I use !isGameOver because it should return 1,

G.supplyCount[province]++;
if(!isGameOver(&G))
    printf("Passed with two province. Game DOES NOT end\n");
else
    printf("Failed with two province. Game ENDS\n");

//add another
//I use !isGameOver because it should return 1,
G.supplyCount[province]++;
if(!isGameOver(&G))
    printf("Passed with three province. Game DOES NOT end\n");
else
    printf("Failed with three province. Game ENDS\n");




}

int main() {
//runs the test update coins function
	testGameOver();


    return 0;
}
