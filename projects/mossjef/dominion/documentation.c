Name: 	Jeff Moss
Date:	09/29/15
Title: 	Documentation of smithy, adventurer, discardCard() and updateCoins() 
	in the dominion game.
File:	documentation.c
Class:	CS362 Fall 2015

smithy card
In the dominion.c implementation file, within the switch statement within the cardeffect method, there is a case called smithy which is the use of the smithy card. From the code, it appears that the smithy card first allows the player to choose an additional three cards from the draw pile. Then, the smithy card is discarded from the pile.

adventurer card
In the dominion.c implementation file, within the switch statement within the cardeffect method, there is a case called adventurer which is the use of the adventurer card. From the code, it appears that the adventurer card allows the player to continue to draw cards until two treasure cards are drawn. If the card is a treasure card, the card is kept in the hand and the drawntreasure integer is incremented. If the card is not a treasurecard, it added into the temphand while the current handcount is reduced by one and the temphand count is incremented. Finally, after two treasure cards are drawn, or if the whole deck is shown, then all cards that are treasure cards are discarded into the player's discard pile.


discardCard() method
The discardCard() method puts played cards in the players played card pile unless it is flagged to be trashed. If the trashflag is not set, the card is added to the players played pile. All played cards get set to -1 and are removed from the players hand. There are a few conditions to remove a card from a players hand. One is if the last card in the hand array is played. In this case the handcount is reduced. Another option is if there is one card left in the hand. In this case the handcount is also reduced. The last scenario is replacing a discarded card with the last card in hand, and then reducing the number of cards.


updateCoins() method
The update coins method takes into account the number of treasure cards that are in a particular player's hand. In this case, the coin count is reset to zero, and coins are added for particular treasure cards in a player's hand. If the treasure card is copper, coins are incremented by one. If the treasure card is silver, coins are incremented by two. If the treasure card is gold, the coins are incremented by three. Further, if there is a bonus, the coins are incremented by the bonus amount. 
