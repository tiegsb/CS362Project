Dominion documentation
======================

Cards
=====

This is the documentation for the Smithy and Adventurer Cards. It fulfills part
2 of assignment 2

Smithy
------
Action card. When played during the Action phase of the game, the player draws
3 cards.
Cost: 4 coins.

Adventurer
----------
Action card. When played during the Action phase of the game, the player mills
cards until they draw two Treasure cards.
Cost: 6 coins.

Functions
=========

discardCard
-----------
Signature: 
int discardCard(int handPos, int currentPlayer, struct gameState *state, int trashFlag)

Return value:
Always 0.

The function takes 4 arguments. The first is the index of the card to be
discarded in the player's hand. The second is the index of the current player
in the array of players. The third is the state of the game including the array
of hands and players. The final argument is whether the card should be put in
the trash.

1. If the trashFlag is set the card is added to the trashed file.
2. The value of the card is always set to -1 to indicate that it has been
   discarded.
3. If the discarded card is the last card in the hand or there is only one card
   the hand's size is shrunk. Otherwise it is replaced by the last card in the
   hand and the hand's size is shrunk.


updateCoins
-----------

Signature:
int updateCoins(int player, struct gameState *state, int bonus)

Return value:
Always 0

The function takes three arguments. The first is the index of the current
player in the game. The second is the state of the game including the array of
players and hands. The last represents the number of bonus treasure points (for
instance, the Militia card gives two bonus points).

The function iterates through the hand, counts the number of coins available,
and then adds them to the number of coins available in the game state.
