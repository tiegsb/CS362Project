Smithy:
•	Smithy is of type enum.CARD.smithy
•	The cost of Smithy is defined in getCost() and is equal to 4.
•	Smithy will draw the player three cards (call/defined in drawCard() three times) according to cardEffect().
o	If the deck is empty the deck will be shuffled and the process will resume.
o	The card will be added to the played cards.

Adventurer:
•	The cost of Adventurer is defined in getCost() and is equal to 6.
•	Adventurer will draw the player two cards (call/defined in drawCard() from the top of the deck
o	If the deck is empty the deck will be shuffled and the process will resume.
o	The card will be added to the played cards.
o	Drawnreasure will be incremented if it’s value is equal to a copper, silver, or gold, otherwise the most recently drawn ard will be removed from the top of the deck
o	Then all cards will be discarded

discardCard():
•	Accepts four parameters, handpost, currentPlayer, state, and trashFlag
•	If a card is not trashed it is added to the played pile, trashFlag determines this action
•	If handpost is equal to the currentPlayer’s handCount then the last card in the array is played and the number of cards in the hand is decremented, else if there is only one card in handCount the reduce the number of cards in hand without playing the last card in the array, else replace the discarded card with the last card in handpost, set the last card to -1 (meaning it has been played) and decrement the number of cards in handCount

updateCoins():
•	Accepts three paramenters, player, state, and bonus
•	State.coins is set to 0 and then all the treasure cards in the players hand is recalculated.
•	Each card is evaluated in turn and if it is a copper then coins is incremented by one, if silver then by two, if gold, then by three.
•	If there is any bonus value greater than zero then this amount will be added to the value of coins as well.
