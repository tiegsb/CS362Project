Adventurer Card:
If the deck is empty at the start, we shuffle the discard pile into the deck.
You get to reveal cards from your deck and place them into your hand until
you have 2 treasures in your hand. Discard all newly drawn cards except the 2 treasures.
The adventurer card is then discarded.

Smithy Card:
Draw three cards and put them into your hand. Discard the Smithy card.

discardCard():
If card is not being trashed (completely removed from game), put in Played pile.
Set the played flag on the card to -1.
If last card in hand, reduce number of cards in hand and place the card in the discard pile.
If there is only one card in hand, reduce the number of cards in and hand place the card in the discard pile.
If there are other cards in the hand, replace discarded card with the next card in the hand.
Set last card to -1. And reduce number of cards in hand.

Remove the card from the players hand.
Reduce number of cards in players hand. Replace discarded card with the next card
in your hand.

updateCoins():
Resets the coin count to 0. Adds coins to the count for each treasure in the players hand.
Add any bonus (coin gains from actions) to the coin count.
