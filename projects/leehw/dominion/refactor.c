/******************************
Susan Lee
CS 362_400_Fall15
Assignment2 – refactor.c
*******************************/

The actions of the following cards were taken out of the cardEffect() switch
statement and placed in its own separate function.Those functions were
declared in the dominion.h file, and defined at the bottom of the dominion.c
file.  Under each card is a description of any intentional bugs introduced.

Smithy: smithyAction(int player, struct gameState *state, int handPos)
Adventurer: adventurerAction(int player, struct gameState *state, int temphand[])
Council: councilAction(int player, struct gameState *state, int handPos)
Village: villageAction(int player, struct gameState *state, int handPos)
Baron: baronAction(int player, struct gameState *state, int choice1, int handPos)

/*******************************
smithyAction()
******************************/
- Added i<=3 in for loop.  This will allow the player to draw 4 cards instead of 3.
- Struct gameState state is passed by reference in drawCard() function.

  for(i = 0; i < 3; i++) TO for (i = 0; i <= 3; i++)
  drawCard(player, state) TO drawCard(player, &state)

/*******************************
adventurerAction()
******************************/
- Changed z increment to  z = z++.  This will cause z to never increment, thereby causing 
  the card at temphand[0] to be overwritten.  This means that not all the drawn cards will
  be placed inthe discard pile.
  
  z++ TO z = z++
  
/*******************************
councilAction()
******************************/
- Changed conditional statement to only allow the current player an extra draw, instead
  of all other players.
  
  if (i != player) TO if (i == player)

/*******************************
villageAction()
******************************/
- Changed the statement to add 2 more actions to the player's turn so that it is merely 
  setting it the number of actions to 2, instead of adding 2 more to the existing number.
  
  state->numActions = state->numActions + 2  TO state->numActions = 2