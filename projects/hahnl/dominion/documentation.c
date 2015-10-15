/* Author: Larissa Hahn
File name: documentation.c
Due date: 10-11-15
E-mail: hahnl@oregonstate.edu
*/

/*
//// Case Smithy (Smithy Card):
Player draws 3 cards. For each card drawn, a card is added
to the player's hand via the drawCard() function. This takes
one action but does not provide any further actions, so the
next stage of the turn commences after the Smithy card is
then discarded with the discardCard() function.

//// Case Adventurer (Adventurer Card):
The while loop executes until two treasure cards are in
the hand. First inside the loop it checks if the deck
is empty; if so, it calls the shuffle() function on the
discard pile and then adds those cards to the deck. Then it
continuously draws cards using the drawCard() function until
there are two treasure cards drawn. When the card is not
a treasure card, that card is removed and placed into a
temporary hand. Finally all the cards in play are discarded.

//// discardCard() function:
If the card in question is not trashed, it is added to the
played pile. Then the played card hand position is set to -1.
This function acts to remove the card from the player's hand.
To do so it next checks to see if the last card in the hand array
is played or if there is only one card left in the hand array.
If so, it decrements the hand card count by 1. Otherwise, it replaces
the discarded card with the last card in hand and sets the state
of the last card to -1, and then decrements the hand card count by 1.

//// updateCoins() function:
This function calculates the total number of coins the player has
currently. It does so by first resetting the coin count variable, then
looping through the cards in the player's hand and adding the
treasure cards in the player's hand up to give a current total. If the
card is a copper treasure card, 1 is added to the coin count. For silver,
2 is added to the coin count. For gold, 3 is added to the coin count.
Once the cards in the player's hands have been iterated over, the loop
finishes execution. Then any bonus coins are added (bonus is a parameter
to the updateCoins() function).
*/
