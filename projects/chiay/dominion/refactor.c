-----------------------
Refactor Documentation:
-----------------------

Switch statement refactored:
****************************

(i) Smithy
   Refactored to function "cardEffect_smithy" with no return value (void function)

(ii) Adventurer
   Refactored to function "cardEffect_adventurer" with no return value (void function)

(iii) Council Room
   Refactored to function "cardEffect_council_room" with no return value (void function)

(iv) Remodal
   Refactored to function "cardEffect_remodal", returning integer value of -1 or 0

(v) Salvager
   Refactored to function "cardEffect_salvager" with no return value (void function)

*Function will be called if satisfied the switch-case statement*
*Function declaration added to dominion_helpers.c*


Implementation with bug and fix:
********************************

Smithy:
Fix: discardCard(handPos, currentPlayer, state, 0);

Bug: discardCard(handPos, currentPlayer, state, 1);

Adventurer:
Fix: {Second While loop} state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1];

Bug: {Second While loop} state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z];

Council Room:
Fix: {Second for loop, if-else statement} clear else { return; }, suppose if-else statement ends after finish executing drawCard(i, state); line

Bug: {Second for loop, if-else statement} else { return; } added after if statement

Remodal:
Fix: initialization of j after declare j as integer, add this line "j = state->hand[currentPlayer][choice1];" after int j;

Bug: "j = state->hand{currentPlayer][choice1];" missing after declaration of j

Salvager:
Fix: {if statement} state->coins = state->coins + getCost( handCard(choice1, state) );

Bug: {if statement} state->coins = state->numBuys + getCost( handCard(choice1, state) );`
