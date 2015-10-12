#refactor.c
#Woo Choi
#SE II CS362F15

/*
5 cards:
Adventurer
Smithy
great_hall
village
council_room

These five kingdom cards' implementations have been removed from switch and got their own functions.
The functions are called in switch statements


*/

/*
Bugs:
1. Adventurer:
	drawntreasure's initial value changed from 0 to 10.
	the first while loop will not run
	
2. Smithy:
	in for loop, initial i's value is now 1 instead of 0
	player will only get +2 cards
	
3. great_hall:
	instead of state->numActions++, it became state->numAction = 2;
	so action number will be 2 after using this card no matter what
	
4. village:
	instead of +2 actions, # of actions just becomes 2
	    from
			state->numActions = state->numActions = 2;
		to
			state->numActions = 2;
5. council_room:

	
	under the last forloop, instead of i != currentPlayer,
	it became i == currentPlayer
	so the currentplayer draws 1 more card.
    for (i = 0; i < state->numPlayers; i++)
	{
	  if ( i == currentPlayer )
	    {
	      drawCard(i, state);
	    }
	}
*/