During refactor, code was copy/pasted into functions and variable references/values were added to function definition

Smithy:
Function starts on line 1329
playSmithy(int i, int handPos, int currentPlayer, struct gameState *state)
{
    for (i = 0; i < 3; i++) //changed to <=
	{
	  drawCard(currentPlayer, state);
	}

    discardCard(handPos, currentPlayer, state, 0);
    return 0;
}

adventurer:
Function starts on line 1306
playAdventurer(int drawntreasure, struct gameState *state, int currentPlayer, int cardDrawn, int *temphand, int z)
//changed z++ to z--
    while(z-1>=0){
        state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; // changed z-1 to z+1
        z=z-1;
    }


council_room:
Function starts on line 1325
playCouncil_Room(int i, int handPos, int currentPlayer, struct gameState *state) //rotated int handPos with int currentPlayer in func definition
{
    for (i = 0; i < 4; i++)
	{
	  drawCard(currentPlayer, state);
	}

    state->numBuys++;

    for (i = 0; i < state->numPlayers; i++)
	{
	  if ( i != currentPlayer )
	    {
	      drawCard(i, state);currentPlayer
	    }
	}

    discardCard(handPos, currentPlayer, state, 0);

    return 0;
}


Embargo:
Function starts on line 1340
playEmbargo(int handPos, int choice1, int currentPlayer, struct gameState *state)
{
    state->coins = state->coins + 2;

    if ( state->supplyCount[choice1] == -1 ) //changed choice1 to choice1 +1
	{
	  return -1;
	}

    state->embargoTokens[choice1]++; //changed choice1 to choice1 +1

    discardCard(handPos, currentPlayer, state, 1);
    return 0;
}

Steward:
Function starts on line 1360
//no  changes/errors added to orignal functions
playSteward(int choice1, int choice2, int choice3, int handPos, int currentPlayer, struct gameState *state)
{
    if (choice1 == 1)
	{
	  drawCard(currentPlayer, state);
	  drawCard(currentPlayer, state);
	}
      else if (choice1 == 2)
	{
	  state->coins = state->coins + 2;
	}
      else
	{
	  discardCard(choice2, currentPlayer, state, 1);
	  discardCard(choice3, currentPlayer, state, 1);
	}
    discardCard(handPos, currentPlayer, state, 0);
    return 0;
}

//end of dominion.c
