/******************************************************************************
bug1.c
Sharon Kuo (kuos@oregonstate.edu)
CS362-400: Assignment 3
Description: Notes on bugs found in unit tests for functions and cards,
  implemented in unittest1.c, unittest2.c, unittest3.c, unittest4.c,
  cardtest1.c, cardtest2.c, cardtest3.c, and cardtest4.c.

----------
unittest4.c
----------
The garden cards are not counted correctly in the scoreFor() function. It
appears in the code that they only count curse cards in the full deck for the
player, and divides the count of the curse cards by 10 to get the score added
for each garden card.

----------
cardtest1.c
----------
The smithy card appears to draw more cards than expected. Additionally, a card
is not discarded correctly. The deck count is lower than expected (because more
cards are drawn than expected).

----------
cardtest2.c
----------
The adventurer card draws more than is necessary, and a card is not discarded
properly. Additionally, the deck count differs from expected because of the
extra cards drawn. A card may not have been discarded or it went to the trash.

----------
cardtest3.c
----------
A card is not discarded correctly, so the discard pile is 1 less than expected.
The card may not have been discarded or went to trash.

----------
cardtest4.c
----------
A card is not discarded correctly, so the discard pile is 1 less than expected.
The card may not have been discarded or went to trash.


******************************************************************************/