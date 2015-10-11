Adventurer
The adventurer card function first with a while loop that runs until the player has drawn two treasure cards.
Inside this loop we first check if the deck is empty and if so reshuffle discard and create new deck.
We then Draw a card if the card is treasure we then increase the number of trasure cards drawn. If not
we draw a new card. Once this while loop finishes we then discard all cards that have been drawn


Smithy
The smitthy is a simpler card in that it has a for loop that runs 3 times and each time through a new card is drawn then discards card from hand.

Discardcard
The function first checks if the card is trashed. If it is not it is added the players played card list and the number of cards played is incrimented.
The function then sets the desired card to location of -1. There is then a triple an if else if else tree that is used if it is the last card in hand was played,
or if the there is only one card in hand or else. In all three events the number of cards in the players hand is replaced. In the else statement the discarded
card from your hand is replaced by the last card in your hand.

update coins
This function works by first setting the players number of coins to 0.
Then a for loop cycles through the players hand. For each copper encountered 1 is added, 2 for each silver and 3 for each gold.
At the end any bonus coins are added.
