//testing smithy

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dominion.h"
#include "assert.h"
#include "cardtest1.h"


int testSmithy (struct gameState * state, int currentPlayer, int handPos, int numInHand, const char* message )
{
	int errors = 0;
	numInHand = 2 + numInHand;
	
	//test that 3 cards were received
	
	smithy_effect(state, currentPlayer, handPos);

	errors += assert( state->handCount[currentPlayer] == numInHand, "smithy_effect()", message);
	printf("       There are now %i cards in the hand\n", state->handCount[0]);

	//tests to see that smithy came from player 0's deck. Player 0 should now have 2 cards in their hand, and player 1 should have 5
	if ((state->deckCount[0] ==2) &&  (state->deckCount[1] ==5))
	{
		printf("PASS: The cards for Smithy were taken from the correct pile\n");
	}
	else
	{
		printf("FAIL: The cards for Smithy were NOT taken from the correct pile\n");
		errors ++;
	}

	//test that cards are in only players hand, player 2 should only have 6 cards in their hand
	if (state->handCount[1] == 6)
	{
		printf("PASS: Smithy did not add cards to the other players hand\n");
	}
	else
	{
		printf("FAIL: Smithy put cards into the other player's hand\n");
		errors ++;
	}
	
	//test to see that smithy discarded. Discard started at 5, so it should now be 6
	if (state->discardCount[0] == 6)
	{
		printf("PASS: Smithy was discarded\n");
	}
	else
	{
		printf("FAIL: Smithy was not discarded\n");
		errors ++;
	}

	return errors;
}



//tests to see if the cards were received. In the end there should be +2 cards in the hand, +3 new -1 smithy
int cardtest1_cardsReceived()
{
	struct gameState state;
	initState(&state);
	int handPos = 5;

	int failcount = 0;

	failcount += testSmithy( &state, 0, handPos, 6, "This hand started with 6, should now have 8");

	return failcount;
}

 

/*
int smithy_effect(struct gameState *state, int currentPlayer, int handPos)
{
  int i = 0;
  //+3 Cards
  for (i = 0; i < 3; i++)
    {
      drawCard(currentPlayer, state);
    }
                    
  //discard card from hand
  //discardCard(handPos, currentPlayer, state, 0);
  return 0;
}

*/

