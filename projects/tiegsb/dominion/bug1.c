/*
Brian Tiegs
CS 362 - Assignment 3

Documentation of bugs found
unittest1: scoreFor() function
Bug 1 - Scores calculated incorrectly when discardCount and deckCount values are different.
Bug 2 - Gardens card is not being calculated correctly by scoreFor(), always returns a score of 0.

unittest2: isGameOver() function
Bug 3 - Does not end game if 1 of the 3 empty card piles are either Sea Hag or Treasure Map.

unittest3: getWinners() function
No bugs found.

unittest4: gainCard() function
No bugs found.

cardtest1: Adventurer Card
Bug 4 - Hand not gaining 2 treasure cards. handCount calculation error. Bug introduced for assignment 2.
Bug 5 - If no treasure cards are in the deck or discard pile, a segmentation fault occurs. Code commented out in order to run remaining tests.

cardtest2: Smithy Card
Bug 6 - No cards are added to hand and no cards are taken from deck. Loop error for drawCard call. Bug introduced for assignment 2.

cardtest3: Council Room Card
Bug 7 - Current player draws too many cards, other players do not draw any cards. drawCard call error for other players. Calls current player instead of other player. Bug introduced for assignment 2.

cardtest4: Treasure Map Card
Bug 8 - If 2 treasure cards are in hand, they are not always trashed from the player's hand.

*/
