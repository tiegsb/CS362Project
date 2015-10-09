Smithy: 	A for loop is called three times in which the function drawCard is called. The smithy is then discarded from the player’s hand using discardCard.

Adventurer:		 When the switch statement processes the adventurer card, it immediately jumps into a while loop whose condition is while the variable drawntreasure is less than two. Then if need be the deck is shuffled using the shuffle function.  Then a card is drawn and inspected. If the newly drawn card is a copper, silver, or gold drawntreasure is incremented. Otherwise the card is put into a temporary hand, to be discarded after the action of the adventurer is completed. After the initial while loop completes, another while loop occurs which discards the temporary hand. The adventurer card does not seem to get discarded.

discardedCard: 		DiscardCard takes a trash flag, where if not set, then the card is removed as played. Otherwise the card is set to a value of -1, rendering the card as discarded. The hand count is then reduced.

updateCoins: 		UpdateCoins keeps a running total of coins in the players hand by beginning at 0, and then for each card in the player hand, checking if each card is a treasure card. If it is, that specific amount is added to the coins. Bonus coins fed into the function are added at the end of the function.
