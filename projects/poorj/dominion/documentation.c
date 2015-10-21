Jesse Poor
Assignment 2 Documentation

smithy: 
	Smithy allows the player to draw three additional cards by using a for loop
	to call drawCard three times. This gives the player the potential to get
	more gold to buy more expensive items during their turn. However, it does 
	not give additional actions or buys. Consequently, Smithy scales well with 
	treasures, and poorly with actions (as well as victory cards, but that
	probably goes without saying). Once cards are drawn the discardCard 
	function is used to put smithy into the discard pile, and the cardEffect
	function returns 0.
	
adventurer:
	Adventurer allows the player to draw from their deck until they have two
	additional treasure cards in their hand. While there have been less than 
	two treasures drawn, the function checks to make sure that the deck is 
	not empty. If it is, the deck is reshuffled so that there are cards to be 
	drawn. It then draws a card increasing drawntreasure if it is a treasure
	card and adding it to the temphand array if it is not. Then, another while
	loop is used to discard everything in temphand. After temphand is empty the
	cardEffect funtion returns 0.

discardCard():
	First the discardCard function checks its trashFlag parameter. If trashFlag
	is not set the card is added to the played card pile and the size of the 
	played card pile is increased by one. Then the current player's hand 
	position is set to -1. The players handcount is then reduced by one, and 
	the discardCard function returns 0.

updateCoins():
	The updateCoins funtion starts by setting coins to 0. Then a for loop 
	iterates over each card in the current players hand adding the appropriate
	number of coins for each treasure card. The game then adds any additional 
	coins based on its bonus parameter, before returning 0.