This document describes the refactoring of five cards in the cardEffect function.  The code
for the adventurer, council room, remodel, smithy and village cards has been moved out of
the switch statements into their own separate functions.  The function names, parameters and
return types are described below:

int playAdventurer(struct gameState *state, int currentPlayer);

int playCouncilRoom(struct gameState *state, int currentPlayer, int handPos);

int playRemodel(struct gameState *state, int currentPlayer, int handPos, int choice1, int choice2);
		
int playSmithy(struct gameState *state, int currentPlayer, int handPos);
      
int playVillage(struct gameState *state, int currentPlayer, int handPos);


A bug has been introduced into each of the following four cards.  A description of the 
bug is included.

playAdventurer:  One comparator "||" for cardDrawn has been switched to "&&"

playCouncilRoom:  The if statement checking if i equals the current player has been removed.
                  All players will draw an extra card including the current player.

playRemodel:  gainCard function parameter 1 changed from choice2 to choice1

playSmithy:  The comparator "<" in the for statement has been switched to ">"