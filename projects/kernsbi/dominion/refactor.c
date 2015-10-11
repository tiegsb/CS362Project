Added five new functions in the cardEffect function:

int adventureCard(int drawntreasure, struct gameState *state, int currentPlayer, int temphand[], int z, int cardDrawn)
which replaces the code for the adventurer card
	Bug introduced:
		changed while(z-1>=0) to while (z-1>0)

int smithyCard(int currentPlayer, struct gameState *state, int handPos)
which replaces the code for the smithy card
	Bug introduced:
		changed discardCard(handPos, currentPlayer, state, 0) to discardCard(handPos, currentPlayer, state, 1)

int councilRoomCard(int currentPlayer, struct gameState *state, int handPos)
which replaces the code for the council room card
	Bug introduced:
		changed state->numBuys++ to state->numBuys--

int greatHallCard(int currentPlayer, struct gameState *state, int handPos)
which replaces the code for the great hall card

int minionCard(struct gameState *state, int handPos, int currentPlayer, int choice1, int choice2)
which replaces the code for the minion card
	Bugs introduced:
		changed  for (j = 0; j < 4; j++) to  for (j = 0; j < 5; j++)
		changed if (choice1) to if (!choice1)
