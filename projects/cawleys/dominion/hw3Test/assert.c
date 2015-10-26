#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "assert.h"


// Doesn't test anything, just records the fact that the test passed or failed.
//Retunrs 0 if the pass value is true, 1 if it is false. Also prints out the pass or fail message to standard out
int assert(bool pass, const char* what, const char* message) {
	if (pass) {
		printf("PASS: %s %s\n", what, message);
		return 0;
	} else {
		printf("FAIL: %s %s\n", what, message);
		return 1;
	}
}


//Creates a game predefined game state for me to test against.
void initState(struct gameState* state) 
{
	int i = 0;
	int j = 0;

	int kingdomCards[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
           sea_hag, tribute, smithy};
	memset(state, 0, sizeof(struct gameState));
	

	state->numPlayers = 2;
    state->supplyCount[curse] = 10;  //this is the amount of a specific type of card given a specific number.
    state->supplyCount[estate] = 8;
    state->supplyCount[duchy] = 8;
    state->supplyCount[province] = 8;
    state->supplyCount[copper] = 60 - (7 * state->numPlayers);
  	state->supplyCount[silver] = 40;
  	state->supplyCount[gold] = 30;


	//set number of Kingdom cards
	  for (i = adventurer; i <= treasure_map; i++)               //loop all cards
	    {
	      for (j = 0; j < 10; j++)                           //loop chosen cards
	        {
	          if (kingdomCards[j] == i)
	            {
	              //check if card is a 'Victory' Kingdom card
	              if (kingdomCards[j] == great_hall || kingdomCards[j] == gardens)
	                {
	                    state->supplyCount[i] = 8;
	                }
	              else
	                {
	                  state->supplyCount[i] = 10;
	                }
	              break;
	            }
	          else    //card is not in the set choosen for the game
	            {
	              state->supplyCount[i] = -1;
	            }
	        }

	    }

  state->outpostPlayed = 0;
  state->phase = 0;
  state->numActions = 1;
  state->numBuys = 1;
  state->playedCardCount = 0;
  state->whoseTurn = 0;
  state->handCount[state->whoseTurn] = 0;
  state->outpostTurn = 0;
 

  
	//the set hand that player 0 is starting with for testing reasons	
	state->deckCount[0] = 5;
	state->handCount[0] = 6;
	state->discardCount[0] = 5;


	state->hand[0][0] = estate;
	state->hand[0][1] = copper;
	state->hand[0][2] =	feast;
	state->hand[0][3] =	baron;
	state->hand[0][4] = estate;
	state->hand[0][5] = smithy;

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



	//set hand for player 1 (same as player 0, except no smithy in hand)
	state->handCount[1] = 6;
	state->deckCount[1] = 5;
	state->discardCount[1] = 5;


	state->hand[1][0] = estate;
	state->hand[1][1] = copper;
	state->hand[1][2] =	feast;
	state->hand[1][3] =	baron;
	state->hand[1][4] = estate;
	state->hand[1][5] = estate;

	state->discard[1][0] = feast;
	state->discard[1][1] = silver;
	state->discard[1][2] = copper;
	state->discard[1][3] = copper;
	state->discard[1][4] = silver;

	state->deck[1][0] = estate;
	state->deck[1][1] = estate;
	state->deck[1][2] = gold;
	state->deck[1][3] = copper;
	state->deck[1][4] = steward;

}