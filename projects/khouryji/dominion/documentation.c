Jibrahn Khoury
CS 362
Assignment 2

Documented understanding of smithy, adventurer, discardCard() and updateCoins().

discardCard() is used to remove a card from a player's hand. If the trash flag is set to 1, it is simply
removed (by taking the game state's 2d array which alots space for each player to have the maximum number
of cards.) When a card is removed from the hand, the value at the index of that card is set to -1).
If the trash flag is set to 0, then the card is considered to have been played. The game state keeps a log
of each card played. Again the 2d array which tracks the hands of all players is consulted on which card
was played, and it is added to the array which holds the log of played cards and the size of that log is
incremented by 1. The count of the current player's hand is also reduced by 1.

updateCoins() tallies the current player's number of coins. It starts at zero and adds 1 coin for every
copper, 2 coins for every silver, and 3 coins for every gold. It also includes any bonus, specified by 
the argument passed to this function. It stores this total in the game state's coins variable.

The Smithy card simply calls drawCard() three times, adding 3 cards to the current player's hand.

The Adventurer card draws cards until two treasure cards have been revealed, keeps the treasure cards 
but discards the other drawn cards. It does this by calling drawcard(). If the card drawn is not a treasure
card the game state reduces the player's number of cards by 1, thus ignoring the card. Those
cards that were ignored are added to the game state's discard array at the end of the function. 