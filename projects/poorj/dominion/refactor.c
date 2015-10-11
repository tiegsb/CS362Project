Jesse Poor
CS 362

New Function: smithyEffect
	The smithyEffect function is called by cardEffect. Code that was previously
	executed in cardEffect's switch statement has been moved to smithyEffect.
	The error in the new code is that when smithyEffect calls the discardCard
	function, the trashFlag is set, which removes the card from the game.
	
