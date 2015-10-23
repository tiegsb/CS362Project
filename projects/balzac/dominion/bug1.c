/* 
Bugs found using test suite from assignment 3
Total bugs = 12
*/

/*from unittest1 discardCard()
Bug 1: When a card is discarded it is not added to the player's discard pile.
*/

/*from unittest2 drawCard()
Bug 2: When deck count is 0 and discard pile count is -1. Deck count is <= 0 after card is drawn. 
*/

/*from unittest3 isGameOver())
Bug 3: When 3 action card piles empty the game does not end. Specifically if Treasure Map card is one
		of the piles.
*/

/*from unittest4 scoreFor()
Bug 3: Score is not correctly calculated from the player's discard pile.
Bug 4: Score is not correctly calculated from the player's deck pile.
*/

/*from cardtest1 Smithy Card
Bug 5: Player does not receive the proper amount of cards.
*/

/*from cardtest2 Adventurer Card
Bug 6: Player's discard pile was not shuffled into player's deck.
Bug 7: Player does not receive the proper amount of cards.
Bug 8: Player does not receive two treasure cards.
*/

/*from cardtest3 Village Card
Bug 9: Player gains 2 actions but action count is not decreased from initial number of actions.
*/

/*from cardtest4 Steward Card
Bug 10: Using choice 1 player does not receive two cards.
Bug 11: Using choice 2 player does not receive two coins.
Bug 12: Using any choice other than 1 or 2 player does not discard two cards.
*/