The smithy card draws three cards from the player's deck and puts them in their hand. If at any point the deck is empty, the discard pile will be shuffled into the deck.

The adventurer card draws cards from the deck until two treasure cards are found. These cards are NOT discarded until AFTER the treasures are found, so the only situation where the discard will be shuffled is if the deck already has less than 2 cards left in it.

The discardCard function removes the card from the player's hand. If it is set to be trashed, the card is trashed, otherwise the card is removed, then replaced with the last card in the player's hand array. The player's hand size is then reduced. This avoids having to shift the whole array over.

The updateCoins function sets the number of coins the player has at the beginning of their buy phase. The bonus is any coins that are given from other card effects.
