Author: Allan Chan
ONID: chanal
Class: CS362
Filename: refactor.c
Description: Documents changes in the dominion.c file. Implements
subtle bugs that are hard to catch. Includes adventurer, council room,
smithy, salvager and great hall for refactored codes. Included 
function declarations for refactored code in dominion.h file.
The function definitions are at the end of the file on dominion.c. 
--------------------------------------------------------------------

adventurer card effect refactored
----------------------------------
Moved card effect code for adventurer to 
void adventurerCard (int drawntreasure, struct gameState* state, int currentPlayer, int cardDrawn, int temphand[], int z)

The bugs introduced is in the while(drawntreasure<2) is changed to while(drawntreasure<=2) which
would cause a 3rd treasure card to be drawn.

cardtest2.c test file for adventurerCard


council room card effect refactored
------------------------------------
Moved card effect code for council room to 
void councilRoomCard (int currentPlayer, struct gameState* state, int handPos)

The bugs introduced is in the for(i = 0; i < 4; i++) where i < 4 is changed to i <= 4. This
would cause 5 calls to drawCard. Another bug introduced is where state->numBuys++ is changed 
to state->numActions++ where this would increment numActions instead of numBuys which is 
the council room's card effect.

cardtest3.c test file for councilRoomCard


smithy card effect refactored
------------------------------
Moved card effect code for smithy to 
void smithyCard(int currentPlayer, struct gameState* state, int handPos)

The bug introduced is in for(i = 0; i < 3; i++) is changed to for(i = 0; i <= 3; i++)
which would call drawCard() 4 times instead of 3 which is the card's effect.

cardtest1.c test file for smithyCard


salvager card effect refactored
-------------------------------
Moved card effect code for salvager to
void salvagerCard(struct gameState* state, int choice1, int currentPlayer, int handPos)

The bug introduced is state->numBuys++ is changed to state->numActions++ which increments
the numActions instead of the card's original effect. 

cardtest4.c test file for salvagerCard


great hall card effect refactored
----------------------------------
Moved card effect code for great hall to
void greatHallCard(int currentPlayer, struct gameState* state, int handPos)

No bugs were introduced in the code. 