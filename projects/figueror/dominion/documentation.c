Rebecca Figueroa
CS 362 Software Engineering
Assignment 2 
October 10, 2015

smithy
When the smithy card is played, the user draws three cards. 
The cards are drawn by a function which loops three times. 
Then the player discards their smithy card.

adventurer
If the deck is empty then the discard pile is shuffled into the deck.
The user gets to draw cards until they receive 2 treasure cards in your hand.
The treasure cards are copper, silver, and gold. 
All other cards are discarded. Then the adventurer card is discarded.

discardCard()
If the card being played is not a trash card, then add to the Played pile.
The played card is then set to -1.
If the user plays their last card, the card is discarded and then the number of cards in hand are reduced.
If the user only has one card in their hand, then the number of cards in their hand is reduced.
Else replace the discarded card with the last card in hand, then set last card to -1, and
reduce the number of cards in their hand.

updateCoins()
Set coins to zero.
For every treasure card in hand, add a certain amount of coins to the player.
For a cooper treasure, add one coin.
For a gold treasure, add three coins.
For a silver treasure, add two coins.
Add any bonus coins to the player's collection.