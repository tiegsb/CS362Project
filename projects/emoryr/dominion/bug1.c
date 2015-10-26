
/*
Bug2 gainCard():

There is no protection for unexpected toFlag numbers. The function treats any number other than
1 or 2 as a 0 and adds the card to discard.

This may be an acceptable bug. Low priority.
*/

/*
Bug2 getCost():
unittest4.c ln 47

This assertion currently passes because it was customized to the function's current behavior.
There is no protection for card values not in the current game but still in the overall deck.
You could return the cost of steward even if it is not in the game to another function with no warning.
*/

/*
Bug 3 smithy_play:
cardtest1.c ln 49

The assert statement fails on line 49.
This asserts that handCount for the current player was increased by 2 after smithy_play was called.
3 cards picked up - 1 discard = 2 more cards in hand after function executes.
*/


/*

Bug 5 adventurer_play:
cardtest2.c ln 58

Fails due to gold not being included in treasure conditional statement.
If the assert only looks for gold and silver in the discard, it passes.
This was expected as it was an added bug.
*/

/*
Bug 6 village_play:
cardtest4.c ln 57

Num actions is not actually incremented by function.
*/

/*
Bug 7 village_play
cardtest4.c ln 69

assert passes 7 times and then fails. seems to be failing due to drawCard function.
*/

/*
Bug 8 great_hall_play
cardtest3.c ln 72

assert passes 7 times then fails. function is supposed to draw a card and then discard great hall.
The drawCard function seems to be failing.

*/
