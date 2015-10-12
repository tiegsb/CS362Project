/******************\
| Allyce McWhorter |
| CS 362           |
| 12-Oct-2015      |
| Assignment #2    |
| documentation.c  |
\******************/

Smithy Cards
----------------
Draws three additional cards and adds them to the current 
player's hand. Once the cards are drawn via drawCard(), 
discardCard() is called and all the player's cards are discarded. 

Adventurer Cards
----------------
Draws cards until two treasure cards are drawn. It also tracks 
whether the drawn card is copper, silver or gold and increments 
drawntreasure() when the drawn card is one of the three. If the 
card is not a treasure card then it decrements the overall handcount 
for the player and increases the count of cards that have been drawn.
Nothing is actually done with the temporary hand once two treasures 
are drawn so the cards are placed back into the player's discard pile 
via state->discard.

discardCard()
----------------
This function discards card from player's hand. It is first determined 
if the card is trashed. If it is not, that card is added to the player's 
played pile. The played card is then set to -1. The card is then removed 
from the player's hand. If it the last card in the hand or if it is the 
only card in the hand, the number of cards is reduced by 1. If it is 
neither the last card in the hand played nor the only card remaining, the
discarded card is replaced with the last card in the hand, which is set 
to -1. The number of cards in the hand is then reduced by 1.

updateCoins()
----------------
This function updates the coin count for the player. The coin count is
first reset. The function then counts each treasure card in the player's 
hand by determining which treasure the card is (copper, silver, or gold) 
and then adding the appropriate value (state->coins). Additionally, 
bonuses are also added to state->coins.