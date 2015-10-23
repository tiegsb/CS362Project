Smithy
The smithy card calls drawCard() three times in a for loop, allowing the current
player to have 3 more cards added to their hand that turn.  After the cards are
drawn, the discardCard() function is called causing the player to discard the 
smithy card after 3 cards have been drawn.

Adventurer
The adventurer code calls drawCard() until the player has drawn 2 treasure cards.
Before cards are drawn, the number of cards in the deck are checked and the
discard deck is shuffeled into the deck if there aren't enough cards.  As the
cards are drawn, they are removed from the top of the player's draw deck.

discardCard()
The discardCard() function first checks for a trash flag which can be set by
passing it a 1.  If this is set, the card is not returned to the played pile,
otherwise, it's added to the played pile.  Next, it removes the last card from
the player's hand if it was played, discarded, or still in the player's hand.

updateCoins()
The updateCoins() function scans through the player's hand and counts the value
of each treasure card and stores them in state->conins variable. A bonus value
is also passed to the function with can be used when certain cards give the 
player more coins for that turn.