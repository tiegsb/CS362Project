/* Documentation

Smithy Card - Player draws 3 cards and add them to their hand. Card has enumeration value of 7. Card cost 4 coins to buy.
cardEffect():
1. For loop invokes drawCard() 3 times.
2. The discardCard() function is called to discard 
getCost():
1. Return 4

Adventurer Card - Player reveals cards from hand until two treasure cards are revealed. The two treasure cards are added to the hand, the rest is discarded. Card has enumeration value of 13. Card cost 6 coins to buy.
cardEffect():
1. While loop repeats step 2 to 4, until treasure card counter is not less than 2.
2. If deck is empty, call shuffle() to add discard pile into deck.
3. Call drawCard()
4. If drawn card is a treasure card, increment counter by 1, otherwise add card to tempHand.
5. While loop discards all cards in tempHand.
getCost():
1. Return 6

discardCard() - Add card to played pile.
Parameters: int handPos, int currentPlayer, struct gameState *state, int trashFlag
1. If trashFlag is less than 1, add card to played pile and increase played pile by 1.
2. Set played card to -1.
3. If card is last card in hand or if there is only 1 card in hand, hand count of current player is reduced by 1. Otherwise, discarded card is replaced with last card in hand, last card is set to -1, and hand count of current player is reduced by 1.

updateCoins() - Update player's coin total.
Parameters: int player, struct gameState *state, int bonus
1. Coin count is set to 0.
2. Loop through players hand for treasure cards. Coin count is increased by 1 for each copper treasure card, 2 for each silver treasure card, and 3 for each gold treasure card in the player's hand.
3. Add bonus coins.

*/