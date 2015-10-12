Smithy
The code for this card involves a simple for loop which is executed three times. Each time the loop is executed, 
the drawCard() function is called. After the loop completes the discardCard() function is called.

Adventurer
A while loop ceases after two treasure cards are drawn. A check to see if the deck is empty occurs; if true, then the discard is 
shuffled and added to the deck. The drawCard() fucnction is called and checks are made to see if it is either a copper,
silver, or gold card. If true, increment the drawtreasure variable, else add the card to a temporary hand which will 
later be removed since the card has been revealed.

discardCard()
The following actions occur in this function:
1. A check is made to see if the discarded card was not designated for trash. If not, then it is added to the played pile.
2. The player's state struct played card flag is set to -1, indicating a card was played.
3. The count indicating the number of cards in the player's hand is decremented and the card is removed from their hand.

updateCoins()
The following actions occur in this function:
1. The coin count is reset to 0.
2. Each card in the player's hand is checked for a tresure card. If true, the proper value is assigned to the state->coins
member.
3. The bonus argument is added to get the final coin count.
