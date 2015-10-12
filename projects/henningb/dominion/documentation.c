Ben Henning
CS 362
Documentation


Smithy Card

The Smithy card uses a loop to call the drawCard() function 3 times in order to draw 3 card to
the player's deck. The discardCard() method is then called to discard the smithy card.


Adventurer Card

The Adventurer card draws cards from the player's deck until it has drawn two treasure cards, then
discards itself and all of the non-treasure cards it has drawn. A loop runs while drawntreasure
is less than 2. Each iteration, the player's deck size is checked. If the player's deck size
is less than 1, the player's discard pile is shuffled and added to the player's deck. The drawCard()
function is then called. If the newly drawn card is a treasure card, drawntreasure is incremented.
Otherwise, the new card is removed from the player's hand and placed in a temporary hand. After 2
treasure cards have been drawn, the Adventurer card and the temporary hand are discarded using
the discardCard() function.


int discardCard(int handPos, int currentPlayer, struct gameState *state, int trashFlag)

The discardCard() function first checks parameter trashFlag to see if the card is trashed. If it has
not been trashed, the card at handPos in the current player's hand is added to the played pile. The
card is then removed from the player's hand by being set to -1. If there is more than 1 card left
in the player's hand, the last card in the player's hand replaces the discarded one and the player's
hand count is decremented. If there are 0 or 1 cards left in the player's hand, the function just
decrements the player's hand count.


int updateCoins(int player, struct gameState *state, int bonus)

The updateCoins() method first resets the coin count in parameter state to 0. The function then
loops through each card in the player's hand. For each card, the count count is increased by 1
if the card is copper, 2 if the card is silver, and 3 if the card is gold. After the loop completes,
the function increases the coin count by the parameter bonus and returns 0.
