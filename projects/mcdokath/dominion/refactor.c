Author: Kathryn McDonald
ONID: mcdokath
Class: CS 362
Filename: refactor.c
Description: Documentation of changes to the dominion.c file.  Includes bugs that are difficult to catch.  Cards included are the Adventurer Card, Smithy Card, 
******************************************************************************************

****************************
Refactor: Adventurer Card Effect
****************************
Created adventurerEffect() function above cardEffect().  Takes arguments struct gameState *state, int currentPlayer, and int handPos and returns 0.  Added break statement in switch(card) as a failsafe.

Bug: Changed the initialization of drawntreasure to 1 instead of 0, so that it will only allow the player to draw 1 Treasure Card rather than 2.

****************************
Refactor: Smithy Card Effect
****************************
Created smithyEffect() function above cardEffect().  Takes arguments struct gameState *state, int currentPlayer, and int handPos and returns 0.  Added break statement in switch(card) as a failsafe.

Bug: Changed for loop condition to i <= 3 instead of i < 3.  This will cause the player to draw 4 cards instead of 3.

****************************
Refactor: Village Card Effect
****************************
Created villageEffect() function above cardEffect().  Takes arguments struct gameState *state, int currentPlayer, and int handPos and returns 0.  Added break statement in switch(card) as a failsafe.

****************************
Refactor: Great Hall Card Effect
****************************
Created greathallEffect() function above cardEffect().  Takes arguments struct gameState *state, int currentPlayer, and int handPos and returns 0.  Added break statement in switch(card) as a failsafe.

Bug: Deleted the +1 action

****************************
Refactor: Embargo Card Effect
****************************
Created embargoEffect() function above cardEffect().  Takes arguments struct gameState *state, int currentPlayer, int handPos, and int choice1 and returns 0.  Added break statement in switch(card) as a failsafe.

Bug: Changed discardCard to 0 instead of 1, meaning it is discarded rather than 