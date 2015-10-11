I refactored:
	Adventurer
	Smithy
	Village
	Great Hall
	Outpost

To refactor these I sent in (struct gameState *state, int currentPlayer, int handPos) the rest of the variables were redefined inside the new function. 
My functions were added to the bottom of dominion.c

Bugs:

1) In Adventurer: changed drawntreasure to be 3 instead of 2
2) In Smithy: commented out discardCard
3) In Village: changed number of actions to be 4 instead of 2
4) In Great Hall: changed number of actions from ++ to --


