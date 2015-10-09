/*
Brian Tiegs
CS 362 - Assignment 2

Revision Documentation

Updated dominion.c
Refactored code for cards: adventurer, smithy, council_room, feast and baron. For each card, the card's effect implementation was moved to its own function. The function is then called in the switch statement. Added functions:
  -adventurerEffect()
  -smithyEffect()
  -council_roomEffect()
  -feastEffect()
  -baronEffect()

Updated dominion.h
Added function refrences that were created in dominion.c.


Bugs introduced

1. Adveturer card
  Location:
    File: dominion.c
    Function: adventurerEffect()
    Line: 1204

  Bug:
    Before:
      cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];
    After:
      cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]--];
    Will decrease the handCount and remove a card from the players hand

2. Smithy card
  Location:
    File: dominion.c
    Function: smithyEffect()
    Line: 1226

  Bug:
    Before:
      for (i = 0; i < 3; i++)
    After:
      for (i = 0; i > 3; i++)
    Condition will always be false and loop will never run

3. Council room card
  Location:
    File: dominion.c
    Function: council_roomEffect()
    Line: 1254

  Bug:
    Before:
      drawCard(i, state);
    After:
      drawCard(currentPlayer, state);
    The current player will draw a card instead of the opponent

4. Baron card
  Location:
    File: dominion.c
    Function: baronEffect()
    Line: 1330

  Bug:
    Before:
      state->coins += 4;
    After:
      state->coins = 4;
    Statement will reset the number of coins to 4 instead of adding them
*/
