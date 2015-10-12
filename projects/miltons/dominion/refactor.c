/*
Summary of changes made to dominion.c (and dominion.h)

1) Moved code for Adventurer card from switch statement in cardEffect() to
separate function named adventurerEffect(). Placed this function at the
bottom of the file so it is easy to locate. Added function call at appropriate
place in switch statement in cardEffect(). Added parameters to function
definition and arguments to function call as necessary. These are the
parameters added:

int currentPlayer, int drawntreasure, int temphand[MAX_HAND],
struct gameState *state, int cardDrawn, int z

Added matching function declaration to dominion.h.

----------

2) Moved code for Smithy card to separate function. Added function call in
cardEffect(). Added parameters to function definition and arguments to
function call. These are the parameters added:

int currentPlayer, struct gameState *state, int handPos

Added matching function declaration to dominion.h.

----------

3) Moved code for Council Room, Feast, and Mine cards to separate functions.
Added function calls at appropriate places in switch statement in cardEffect().
Added parameters to function definitions and arguments to function calls.
Added matching function declarations to dominion.h.



------------------------------------------------
Summary of bugs added to functions in dominion.c


*/