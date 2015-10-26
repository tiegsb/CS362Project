//tests fullDeckCount

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dominion.h"
#include "assert.h"
#include "unittest4.h"


//testDeckCount takes in the state of the game, the type of card (copper, silver etc) the total number of cards and the message
//to be read to the screen. It compares the function from the game to the total number that I have prepopulated to see if 
//the amounts are the same
int testDeckCount(struct gameState* state, int card, int total, const char* message)
{

	return assert(fullDeckCount( 0, card, state) == total, "fullDeckCount()", message);

}


//initialize the hand that I am checking against
void initState2(struct gameState* state) 
{

	memset(state, 0, sizeof(struct gameState));
	state->deckCount[0] = 5;
	state->handCount[0] = 5;
	state->discardCount[0] = 5;


	state->hand[0][0] = estate;
	state->hand[0][1] = copper;
	state->hand[0][2] =	feast;
	state->hand[0][3] =	baron;
	state->hand[0][4] = estate;

	state->discard[0][0] = feast;
	state->discard[0][1] = silver;
	state->discard[0][2] = copper;
	state->discard[0][3] = copper;
	state->discard[0][4] = silver;

	state->deck[0][0] = estate;
	state->deck[0][1] = estate;
	state->deck[0][2] = gold;
	state->deck[0][3] = copper;
	state->deck[0][4] = steward;
}


//calls cases of testDeckCount, each with its own test to test if the function is working properly. Returns the number of
//fails from the cards
int unitTest4()
{

	struct gameState state;
	initState2(&state);

	int failcount = 0;

	failcount += testDeckCount( &state, copper, 4, "should return 4 coppers");
	failcount += testDeckCount( &state, estate, 4, "should return  3 estates ");
	failcount += testDeckCount( &state, feast, 2, "should return 2 feasts");
	failcount += testDeckCount( &state, baron, 1, "should return 1 baron");
	failcount += testDeckCount( &state, silver, 2, "should return 2 silver");
	failcount += testDeckCount( &state, gold, 1, "should return 1 gold");
	failcount += testDeckCount( &state, steward, 1, "should return 1 steward");
	
	return failcount;
}


