#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

//========================
//TEST SHUFFLE() FUNCTION
//========================

int main (int argc, char** argv) {
	
	
	int oldDeck[MAX_PLAYERS][4];
	struct gameState s;
	int i, j;
	unsigned long same;
	float shuffled;

	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};

	printf ("\nshuffle() FUNCTION TEST\n\n");
  
	int r = initializeGame(MAX_PLAYERS, k, 21, &s);

	assert (r == 0);
  
	for(i=0; i<MAX_PLAYERS; i++)
	{
		for(j=0; j<5; j++)
		{
		oldDeck[i][j] = s.deck[i][j];
		}
	}
	
	for(i=0; i<MAX_PLAYERS; i++)
	{
		shuffle(i, &s);
	}
	
	for(i=0; i<MAX_PLAYERS; i++)
	{
		for(j=0; j<5; j++)
		{
			if(oldDeck[i][j] == s.deck[i][j])
			{
				same++;
			}
		}
	}
	
	shuffled = (100-((float)same/(5*(float)MAX_PLAYERS)*100));
	
	printf ("%f%% shuffled.\n", shuffled);

	printf ("\nFUNCTION TEST RESULT... PASSED\n\n");
	
  return 0;
}