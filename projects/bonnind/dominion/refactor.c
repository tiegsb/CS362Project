Daniel Bonnin
CS362 Fall 2015
bonnind@oregonstate.edu
refactor.c

This file contains documentation for 5 dominion card functions which are
the result of refactoring the switch statement in cardEffect(). These functions
have been appended to the end of the file dominion.c and are declared in the 
file dominion.h.

A bug has been introduced in each card function. Each function and 
associated bug is documented in this file. 


***smithyCard():***

This function simulates the drawing of 3 cards and discarding this card. 

The function enters a for loop which is initialized for 3 iterations. In each
iteration, drawCard() is called, which adds the next card in the deck to the 
hand of the current player. 

The bug I introduced initializes the variable i in the for loop to 1 instead of
0. This will cause the loop to execute only twice. 

The original code:
for (i = 0; i < 3; i++)
  {
    drawCard(currentPlayer, state);
  } 

The buggy code:
for (i = 1; i < 3; i++)
  {
    drawCard(currentPlayer, state);
  }


***adventurerCard():***

This function simulates the drawing of cards into a temporary hand until 2 
Treasure cards are revealed. The Treasure cards are added to the current 
player's hand while the other revealed cards are discarded back into the 
current player's discard pile. 

The function loops until 2 treasure cards are revealed. In the loop: 
re-shuffle (if necessary), call drawCard(), if Treasure, increment counter, 
if not Treasure, remove card from hand and add to temp hand. 

Finally, the tempHand array is discarded in a loop. 

The bug I introduced replaces an equality comparison operator with an 
assignment operator. 

The original code:
    if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
      drawntreasure++;

The buggy code: 
    if (cardDrawn = copper || cardDrawn == silver || cardDrawn == gold)
      drawntreasure++;


***villageCard():***

This function simulates the drawing of a card and the addition of 2
actions before discarding this card. 

The function calls drawCard(), then increments the 
game state's numActions variable by 2 before discarding this card with
the discardCard() function. 

The bug I introduced increments numActions by too much. 

The original code:
    state->numActions = state->numActions + 2;

The buggy code: 
     state->numActions += state->numActions + 2;

***greatHallCard():***

This function simulates the drawing of a card and the addition of 1 actions
before discarding this card. 

The function calls drawCard(), then increments the game state's numActions
variable by 1 before calling discardCard();

The bug I introduced uses the wrong index for the current player unless 
the current player is 0 (this makes the bug more subtle by causing it to
be intermittent). 

The original code: 
  drawCard(currentPlayer, state);

The buggy code:
  drawCard(((currentPlayer) ? (currentPlayer - 1) : currentPlayer), state);


***cutpurseCard():***

This function simulates the removal of 1 copper card from all opponents' hands,
if a copper card is present, before discarding this card. If no copper card
present in the current opponent's hand, then all cards in current opponent's 
hand are revealed.  

The function loops through all players, and, in a nested loop, loops through
each player's hand, checking for copper card. If a copper is found, it is 
discarded, and the inner loop (current player's hand) terminates. If the loop
iterates past the end of the current opponent's hand array without revealing
a copper card, all the cards in the hand are printed via a for loop. Finally,
discardCard() is called. 

The bug I introduced does not allow the nested loop to iterate past the end 
of the opponent's hand array, so it will never print a no-copper hand. 

The original code:
  for (j = 0; j <= state->handCount[i]; j++) 

The buggy code:
  for (j = 0; j < state->handCount[i]; j++)
