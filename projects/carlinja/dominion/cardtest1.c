/* -----------------------------------------------------------------------
 * James Carlin
 * 10/20/2015
 *
 * CardTest1
 *  Tests the SMITHY card
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"



void testSmithy()
{


    int i;
    int seed = 1000;
    int numPlayer = 2;
    int maxBonus = 10;
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
firstHand[1] = silver;
firstHand[2] = gold;
firstHand[3] = smithy;
firstHand[4] = adventurer;


initializeGame(numPlayer, k, seed, &G);

//set specifics for new game state

G.handCount[testPlayer]= handCount;

//place cards in test player's hand

memcpy(G.hand[testPlayer], firstHand, sizeof(int) * handCount);

//the smithy card has two basic functions
//first it draws 3 cards
//then discards the smithy

//now to test actual function

smithyCard(&G, testPlayer, 3);
//Tests to see if 3 cards were drawn
//this portion does not test the discard function yet
//just the drawing function
if(G.handCount[testPlayer] == 8 || G.handCount[testPlayer] == 7)
	{
	printf ("Passed, player %d drew correct amount of cards\n", testPlayer);
	if(G.handCount[testPlayer] == 8)
	{
		printf ("Failed, player %d did not discard the smithy card\n", testPlayer);
	}

	else if(G.handCount[testPlayer] == 7)
		{
			printf ("Passed, player %d discarded the smithy card\n", testPlayer);
		}

	else
		{
			printf ("Failed, player %d did not discard the smithy card\n", testPlayer);
		}

}

else
{
	printf ("Failed, player %d drew incorrect amount of cards\n", testPlayer);
}

}

int main() {

	testSmithy();


    return 0;
}
