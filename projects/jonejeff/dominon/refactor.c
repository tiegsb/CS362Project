
The Refactoring of adventurer, smithy, remodel, minion, and great_hall card are done. The function declarations are in dominion_helpers.h in the format "card"CardPlayed();
The diffinitions are at the button of dominion.c. For the minion card I swaped which check gets each choice. So choice one now get choice two and vice versa. For the
remodel card I set the trash flag to one so the card chosen does not get trashed. The smithy card I have it discard the second card and draw a forth. while oddvious if look at in the source code
should be hard to spot with just playing the game. For the adventurer card I have check the second card from the top so -2 instead of -1 at line 1249. This introduces a infinite loop so I have them draw two cards every time in addition
to make the game play with out the infinite loop.
