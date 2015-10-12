Ben Henning
CS 362
Description of Refactored Code

Changes to cardEffect():
Adventurer case now calls adventurerCardEffect() function.
Moved original code from adventurer case to adventurerCardEffect() function.

Smithy case now calls smithyCardEffect() function.
Moved original code from smithy case to smithyCardEffect() function.

Steward case now calls stewardCardEffect() function.
Moved original code from steward case to stewardCardEffect() function.

Village case now calls villageCardEffect() function.
Moved original code from vilalge case to villageCardEffect() function.

Sea_hag case now calls seaHagCardEffect() function.
Moved original code from sea_hag case to seaHagCardEffect() function.

Deleted local variables int i, int z, int drawntreasure, and int cardDrawn
(now declared as local variables in their appropriate functions).



New Functions:


void adventurerCardEffect(int currentPlayer, struct gamestate *state):
Cut and pasted code originally in cardEffect() switch statement for adventurer case.
Added local variables int z, int cardDrawn, int drawntreasure, and int temphand[MAX_HAND].
CurrentPlayer and state are passed as arguments by cardEffect().
BUG: In the else block dealing with non-treasure cards, player's handCount is incremented instead of
decremented.

void smithyCardEffect(int handPos, int currentPlayer, struct gameState *state):
Cut and pasted code originally in cardEffect() switch statement for smithy case.
Added local variable int i.
HandPos, currentPlayer, and state are passed as arguments by cardEffect().
BUG: Changed the terminating condition of the loop from i<3 to i<=3.

void stewardCardEffect(int handPos, int currentPlayer, struct gameState *state,
int choice1, int choice2, int choice3):
Cut and pasted code originally in cardEffect() switch statement for steward case.
HandPos, currentPlayer, state, choice1, choice2, and choice3 are passed as arguments by cardEffect().
BUG: In the else statement where two cards are supposed to be trashed, the last arguments to the two
discardCard() function calls have been changed to 0s instead of 1s.

void villageCardEffect(int handPos, int currentPlayer, struct gameState *state):
Cut and pasted code originally in cardEffect() switch statement for village case.
HandPos, currentPlayer, and state are passed as arguments by cardEffect();


void seaHagCardEffect(int currentPlayer, struct gameState *state):
Cut and pasted code originally in cardEffect() switch statement for sea_hag case.
Added local variable int i.
CurrentPlayer and state are passed as arguments by cardEffect()
BUG: If statement condition has been changed from i!=currentPlayer to i==currentPlayer

