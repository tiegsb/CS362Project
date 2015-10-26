//tests the whoseTurn function



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dominion.h"
#include "assert.h"
#include "unittest2.h"

//Tests whose turn by comparing the return value from whoseTurn to the state->whoseTurn. Takes in the game state and the error code message from unitTest2()
int testWhoseTurn(int turn, const char* message)
{
	struct gameState state;
	memset(&state, 0, sizeof(struct gameState));
	state.whoseTurn = turn;

	//will return 0 if passes 1 if fails.
	
	return assert(whoseTurn(&state) == state.whoseTurn, "whoseTurn()", message);
	
}


int unitTest2()
{
	int failcount = 0;

	failcount += testWhoseTurn(0, "should return 0 if state->whoseTurn is 0");
	failcount += testWhoseTurn(1, "should return 1 if state->whoseTurn is 1");
	failcount += testWhoseTurn(-1, "should return -1 if state->whoseTurn is -1");
	
	return failcount;
}

