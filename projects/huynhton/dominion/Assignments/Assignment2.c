CS 362	Assignment 2
Tony Huynh	
----------
EXPLAINING CARDS/FUNCTIONS
----------


This assignment will simply talk about my understand of a few things for the 
	Dominion card game.  
-This file is in .c to prevent Github from thinking we are using it for just file storage.
-The C comments will not be used because it is hard to see the words on PuTTY

-----

Smithy: This card lets you draw three additional cards.  If there are no other cards 
	in your draw deck during any of the draw phase, you will take your played pile
	and reshuffle them into your draw deck.

Adventurer: This card will require the user to continue revealing the card on top of their deck
	until they have revealed two Treasure cards.  All the non-Treasure cards that have
	been revealed will be sent to the played pile, and the two Treasure cards revealed will 
	be added to the user's hand.

discardCard(): This function will discard a player's card into the discard pile.  It checks to see
	if the card was "trashed" in the first place before sending it to the played pile.  
	It then decrements the count of cards in the user's hand.

updateCoins(): This function simply adds up all the coin values in a player's hand.  After 
	iterating through the player's hand, it will account for any bonuses the player may have.