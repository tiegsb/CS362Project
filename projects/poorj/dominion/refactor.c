Jesse Poor
CS 362

New Function: smithyEffect
	The smithyEffect function is called by cardEffect. Code that was previously
	executed in cardEffect's switch statement has been moved to smithyEffect.
	The error in the new code is that when smithyEffect calls the discardCard
	function, the trashFlag is set, which removes the card from the game.
	
New Function: adventurerEffect
	The adventurerEffect function plays the adventurer card. It is called by 
	the switch statement in the cardEffect function. The error introduced is 
	that drawntreasure is no longer incremented when copper is drawn (This 
	card is OP). 
	
New Function: gardensEffect
	The gardensEffect is now called when the gardens card is played. It
	is called by the switch statement in the cardEffect function. It 
	incorrectly returns sucessfully if the gardenNum is negative one, and it 
	returns zero otherwize.
	
New Function: villageEffect
	The villageEffect function draws a card and puts it into the player's hand,
	then gives the player two additional actions. It is called by the switch 
	statement in the cardEffect function. The error is that the number of 
	turns it gives plus equals itself plus two, giving the incorrect number of 
	additional turns.
	
New Function: remodelEffect
	The remodelEffect function is called by the cardEffect function when the 
	remodel card is played. It gets the player's choice of trashed card and 
	compares it to the player's card pickup. If the difference is greater than 
	two the  function returns false, otherwise the card is picked up. Then the 
	trashed card is returned and the card is removed from the deck.