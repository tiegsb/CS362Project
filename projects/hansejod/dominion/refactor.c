Smithy:
Function prototype is - int callSmithy(int currentPlayer_, int handPos_, struct gameState *state);
Starts on line 1222.
Refactor description - created a prototype in dominion.h with arguments that were variables in the cardEffect function, including currentPlayer, handPos, and the game structure. I had to create a local variable i to use in the for loop.
Bug: The variable i is converted from postfix to prefix, i++ -> ++i (L225). Loop will executed one less time than it should.


Adventurer:
Function prototype is - int callAdventurer(int currentPlayer_, int cardDrawn_, int *temphand, struct gameState *state);
Starts on line 1236.
Refactor description - created a prototype in dominion.h with arguments that were variables in the cardEffect function, including currentPlayer, cardDrawn, a pointer to the array temphand, and the game structure. I had to create local variables z and drawntreasure to use in the while loops, one as a counter and the other as an increasing index reference.
Bug: While loop conditional was change from drawntreasure<2 to drawntreasure<=2 (L1241). State no longer references the correct variable in the strucutre in state->handCount[currentPlayer_] to state->deckCount[currentPlayer_] (L1251).


CouncilRoom:
Function prototype is - int callCouncilRoom(int currentPlayer_, int handPos_, struct gameState *state);
Starts on line 1262.
Refactor description - created a prototype in dominion.h with arguments that were variables in the cardEffect function, including currentPlayer, handPos, and the game structure. I had to create a local variable i to use in the for loop.
Bug: The number of buys is not increased for the card, state->numBuys++; -> state->numBuys; (L1273).


Ambassador:
Function prototype is - int callAmbassador(int currentPlayer_, int handPos_, int choice1_, int choice2_, int choice3_, struct gameState *state);
Starts on line 1291.
Refactor description - created a prototype in dominion.h with arguments that were variables in the cardEffect function, including currentPlayer, handPos, the game structure, and all the choices. I had to create local variables i and j to use in the for loops.
Bug: One of the return statements returns 0 instead of 1, return -1 -> return 0 (L1315). The break statement was removed in what should be at line L1344.


SeaHag:
Function prototype is - int callSeaHag(int currentPlayer_, struct gameState *state);
Starts on line 1351.
Refactor description - created a prototype in dominion.h with arguments that were variables in the cardEffect function, including currentPlayer and the game structure. I had to create a local variable i to use in the for loop.


All functions:
Bug: All functions have the bug in that all variables are passed by value when some should be passed by reference such as currentPlayer_.