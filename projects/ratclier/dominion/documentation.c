"Smithy" card
-------------

The Smithy card draws 3 cards from the player's deck and adds them to the
player's hand. Once that is done, the Smithy card itself is discarded.


"Adventurer" card
-----------------

The Adventurer card draws cards from the player's deck until two Treasure
(coin) cards are drawn. If the drawn card is not a Treasure card, it is
added to a temporary hand; if it is a Treasure card, it is added to the
player's hand. At the end of the process, whatever is in the temporary
hand (which contains no Treasure cards) is discarded.

If the player's deck is empty when the Adventurer card is played, the
player's discard pile is shuffled and becomes the player's deck. (This
seems pointless as the drawCard() function does this already.)


Function: discardCard()
-----------------------

If a card was not trashed (i.e. permanently removed from the deck), add it
to the top of the played card pile, increment the count of played cards,
then set the card state to played.

Next, shift the last card in the player's hand (if one exists) to the
position of the card that was discarded and decrement the number of cards
in the player's hand. If the player only has one card left, do not shift
anything, just decrement the number of cards in the player's hand.


Function: updateCoins()
-----------------------

Starting with an empty set of coins, add the number of Treasure cards in
the player's hand based on each card's coin value (copper = 1, silver = 2,
gold = 3). If a bonus was awarded, add the bonus amount to the total.

