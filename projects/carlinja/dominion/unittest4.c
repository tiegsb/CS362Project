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


void testWhoseTurn()
{

    int testNum;
    int seed = 1000;
    int numPlayer = 2;

    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
	int testPlayer=1;
	int handCount=5;
//initialize gamestate
    struct gameState G;



G.whoseTurn = 0;

testNum = whoseTurn(&G);

if(testNum = G.whoseTurn){
    printf("Passed. Expected 0, got %d\n", testNum);
}
else
    printf("Passed. Expected 0, got %d\n", testNum);

G.whoseTurn = 1;

testNum = whoseTurn(&G);

if(testNum = G.whoseTurn){
    printf("Passed. Expected 1, got %d\n", testNum);
}
else
    printf("Passed. Expected 1, got %d\n", testNum);

G.whoseTurn = 2;

testNum = whoseTurn(&G);

if(testNum = G.whoseTurn){
    printf("Passed. Expected 2, got %d\n", testNum);
}
else
    printf("Passed. Expected 2, got %d\n", testNum);

















}

int main(){


testWhoseTurn();




return 0;
}
