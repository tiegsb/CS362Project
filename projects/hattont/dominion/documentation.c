Ty Hatton 
CS362 F15

smithy card-
The smithy card has the current player draw 3 cards. This is completed within a for loop which draws the 3 cards. Discard function is called to discard a card from the players hand.

adventurer card-
This card has the player show cards out of their hand until 2 treasure cards are revealed. The treasure cards are added to the hand and the other revealed cards are removed. The task is performed in while loops to look for 2 treaasure cards. Checked for empty deck and then shuffled, otherwise checks to see if card is a treasure card (copper, silver, or gold). All non-treasure cards are removed in final action.

discardCard()-
This function removes a card from a players hand. If the trashLFag is set, if it is the card is trashed from the players hand, otherwise it is added to the players card pile. Then handCount is decremented by 1.

updateCoins()-
first resets coin count to 0.  With a for loop, sums the value of coins in the players hand (1 for copper, 2 for silver and 3 for gold)  If there is a bonus passed to the function it is added to the coin value at the end of the function.
