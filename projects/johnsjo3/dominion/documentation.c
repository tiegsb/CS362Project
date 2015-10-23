Documentation  Josh Johnson 10/11/2015

Documentation on smithy
Smithy is a card that when played has the player draw 3 cards into their hand.  The smithycard is then discarded.

Documentation on Adventurer Card
The Adventurer card draws cards until two treasure cards are drawn.  The two
treasure cards stay in the player's hand. The other cards are discarded along
with the Adventurer card

discardCard()
discardCard function has several properties, namely, as the funtion is so aptly named, to discard a card.  Normally this would be to the player's discard pile (or 'played pile' as the comments state).  However, discardCard() will 'trash' a card when the trashFlag is set.

To discard the card, the card is first copied to the top of the discard pile (assuming it's not trashed).  It is then removed from the hand, either by subtracting the hand count by one if it's at the end, or by doing a swap with the last card in the hand and then subtracting from the hand (since the hand is an array)

updateCoins()
For the player's turn, counts the number of coins in the player's hand.

To accomplish this, it resents the coin count to 0, then iteratively looks at each card in the player's hand for copper, silver, and gold.  When it comes across these cards, the appropriate value is added to the player's coin count.  Then any extra bonus amounts (from an action card for example) which was passed in to the function is added in to the total.
