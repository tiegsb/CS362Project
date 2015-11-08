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


void testShuffle()
{


    int seed = 1000;
    int numPlayer = 2;

    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
	int testPlayer=1;
	int handCount=5;
//initialize gamestate
    struct gameState G;



//test 1 with empty deck

G.deckCount[testPlayer] = 0;
if(shuffle(testPlayer,&G))
    printf("Passed: shuffle did not run with empty deck\n");
else
    printf("Failed: shuffle passed with empty deck\n");
//test 2 with 1 in deck
G.deckCount[testPlayer]++;
if(!shuffle(testPlayer,&G))
    printf("Failed: shuffle did not run with 1 in the deck\n");
else
    printf("Passed: shuffle passed with 1 in the deck\n");
//test 3 with 2 in deck
G.deckCount[testPlayer]++;
if(!shuffle(testPlayer,&G))
    printf("Failed: shuffle did not run with 2 in the deck\n");
else
    printf("Passed: shuffle passed with 2 in the deck\n");
//test 4 with 3 in deck
G.deckCount[testPlayer]++;
if(!shuffle(testPlayer,&G))
    printf("Failed: shuffle did not run with 3 in the deck\n");
else
    printf("Passed: shuffle passed with 3 in the deck\n");







}
int main()
{
    testShuffle();



    return 0;
}
