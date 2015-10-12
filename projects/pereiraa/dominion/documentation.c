Smithy
-Draws 3 cards, then discards the smithy card

Adventurer
-Reveal cards from your deck until you reveal 2 treasure cards. Pull those treasure cards into you hand and discard the other
revealed cards. The code says while you haven't found 2 treasure cards:
    1st check to see if the player's deck is empty. If so call the shuffle function. Then draw a card from the deck. If it's
    silver, copper, or gold, increment the treasure counter. If it isn't one of these cards remove the card and start again.
    Once 2 tresures have been found discard the cards that weren't treasures.

discardCard()
-First it checks to see if the card is being discarded because it should be trashed. If no, the card is added to the played pile.
The player's hand is then adjusted so that the "played card" is removed (changed to -1 to denote it's not in the game). 
If the card to be discarded is the last card in your hand or if you only have one card in your hand simply 
reduce the number of cards in your hand. If not the card removed should be replaced by the last card in the hand.
 

updateCoins()
-First the coin count is reinitialized to 0. Then the card is searched for treasure coines (copper, silver and gold). For each
type of treasure found, the coint count is incremented (1 for copper, 2 for silver, 3 for gold). If the player had a coin bonus 
that is added to coin count and the final number is placed in the structs coin "bucket". 
