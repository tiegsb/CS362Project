/*
Filename: documentation.c
Author: Sharon Kuo (kuos@oregonstate.edu)
Last modified: 2015-10-11
Description: Documentation for the Dominion game

*******************************************************************************
Cards
*******************************************************************************
----------------------------------------
Smithy
----------------------------------------
Type: Action
Cost: 4 (defined in getCost())
Effect: +3 cards
Enum value: 13 (defined in dominion.h)
--------------------
The Smithy card is an action card that costs 4 coins to buy. When the player
plays the Smithy card, the branch case for smithy in cardEffect() executes a
for loop that loops 3 times and draws a card for the current player by calling
the drawCard() function. After the cards are drawn, the Smithy card is
discarded from the player's hand by the discardCard() function.

----------------------------------------
Adventurer
----------------------------------------
Type: Action
Cost: 6 (defined in getCost())
Effect: Reveal cards from your deck until you reveal 2 Treasure cards. Put
those Treasure cards in your hand and discard the other revealed cards.
Enum value: 7 (defined in dominion.h)
--------------------
The Adventurer card is an action card that costs 6 coins to buy. When the
Adventurer card is played, the branch case for adventurer in the cardEffect()
function executes a while loop. This while loop executes while the number of
drawn Treasure cards (drawntreasure) is less than 2. It first checks if the
deck is empty; if so, then the played/discard pile is shuffled and added to the
deck by calling the shuffle() function. The while loop draws a card from the
deck. The card that is drawn is placed at the top card of the player's hand. If
the drawn card is either a copper, silver, or gold card, then drawntreasure is
incremented by one. If the drawn card is none of the three treasure cards, then
it goes into a temporary hand (temphand; the revealed cards), and is removed
from the player's hand (the most recently drawn one, the top of the hand). The
count for the temporary hand is increased. After two treasure cards are
revealed, the while loop concludes, and then the cards in the temporary hand
are discarded into the played/discard pile by the use of a second while loop
that executes while the count of cards in temphand minus 1 is greater than or
equal to 0.

*******************************************************************************
Functions
*******************************************************************************
----------------------------------------
discardCard()
----------------------------------------
int discardCard(int handPos, int currentPlayer, struct gameState *state, 
	int trashFlag)
int handPos: card's position in the hand
int currentPlayer: current player number
gameState state: struct storing the game state
int trashFlag: determines if the card is to be trashed
Function: Determines if a card goes to the played or trash pile and adjusts the
player's hand.
--------------------
The discardCard() function first checks if the card is to be trashed; if the
trashFlag is not set (trashFlag = 0), then the card is added to the pile of
played cards, and the number of played cards is incremented by one. Next, the
function sets the played card in the player's hand to -1. If the card was the
last card in the hand array or the only card in the hand, then the number of
cards in the hand is decremented by 1. Otherwise, the discarded card is
replaced by the last card in the hand, and the count of cards in the hand is
decremented by 1.

----------------------------------------
updateCoins()
----------------------------------------
int updateCoins(int player, struct gameState *state, int bonus)
int player: player number
gameState state: struct storing the game state
int bonus: bonus coins to add
Function: Counts the total value given by Treasure cards in a player's hand and
adds any bonus coins.
--------------------
The updateCoins() function first resets the number of coins to 0. It then
loops through the cards in the player's hand checking for Treasure cards. If
a card is a copper card, then 1 coin is added to the game state. If the card is
a silver card, 2 coins are added to the game state. If the card is a gold card,
then 3 coins are added to the game state. The for loop goes through each card
in the player's hand. When it is finished, it then adds any bonus coins to the
game state.

*/
