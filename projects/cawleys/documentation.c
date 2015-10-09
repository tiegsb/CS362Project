Documentation for the Dominion card game

Adventurer
	The adventurer card reveals cards from your deck until you reveal 2 Treasure cards. You put those Treasure cards in your hand and discard the other revealed cards (Vicory points and Action cards). This card costs 6 coins

	Code interpretation:
	Most of the code for this function is in a while loop that is testing to see if you have drawn your 2 pieces of treasure yet. First thing it checks is if you still have cards in your deck, if not it will shuffle the cards and add them to the deck. If the card you draw is a treasure card it ups the count in drawntreasure which is keeping track of how much treasure you have drawn so far. If the card is not a treasure it goes into a temparary hand and then retuns to the while loop to draw another card. After you have your 2 treasure you are kicked out of the while loop and the exess cards are discarded.
	
	

Smithy
	Lets you draw 3 cards from your pile. This card costs 4 coins

	Code interpretation:
	This function is rather simple. In a for loop it draws 3 cards. After you have drawn the cards it calls discardCard to discard the card.

	


discardCard

	This is the function that deals with cards leaving your hand

	1) It checks to see if the card should be trashed or not, if the card should not be trashed it adds it to the played pile.
	2) Reduces the card count in your hand. It reconfigures your hand to remove the card (leaving blank space)
	3) Regconfigures hand taking out blank space, by moving last card in hand to the played card's space. Unless the card you played was the last one, in which it does not move any cards, just reduces the count in your hand.


updateCoins

	This recalculates the number of coins you have to play in a given turn. 
	1) First it resets the current players coins to play
	2) It goes throgh the array of cards in your hand and gives appropriate coin value for all treasure cards
	3) That total is then adjusted by the bonus (from action cards) this value has been sent into the function

