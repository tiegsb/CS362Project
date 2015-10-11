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
	The gardensEffect is now called when the gardensEffect card is played. It
	is called by the switch statement in the cardEffect function. It 
	incorrectly returns sucessfully if the gardenNum is negative one, and it 
	returns zero otherwize.
	
