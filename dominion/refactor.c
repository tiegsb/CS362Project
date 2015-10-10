Ben Henning
CS 362
Description of Refactored Code

cardEffect():
Adventurer case now calls adventurerCardEffect() function.
Deleted local variables int i, int z, int drawntreasure, and int cardDrawn (now declared in adventurerCardEffect()).
Moved original code from adventurer case to adventurerCardEffect() function.

Smithy case now calls smithyCardEffect() function.

adventurerCardEffect(int currentPlayer, struct gamestate *state):
Cut and paste code originally in cardEffect() switch statement for adventurer case.
Added local variables int z, int cardDrawn, and int temphand[MAX_HAND].
CurrentPlayer and state are passed as arguments by cardEffect().

void smithyCardEffect(int handPos, int currentPlayer, struct gameState *state):
Cut and paste code originally in cardEffect() switch statement for smithy case.
Added local variable int i.
HandPos, currentPlayer, and state are passed as arguments by cardEffect().


