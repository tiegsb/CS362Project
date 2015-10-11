//Documentation of code changes
//Keenan Bishop
//
//
//dominion.c
/*
1. Gave smithy its own function: smithyCard()
	prototyped in dominion_helpers.c
	accepts handpos, current player, and state
	it passes these to drawcard (3 times) and calls discard
	BUG = 2 cards instead of 3!

2. Gave Adventurer its own function: adventurerCard():
	prototyped in dominion_helpers.c
	accepts currentplayer and state
	BUG = drawn silver card doesn't update drawntreasures, card can give more than 2 treasures!

3. Gave Village its own function: villageCard();
	
	BUG = +3 actions instead of 2

4. Gave great_hall its own function great_hallCard()
	
	BUG = doesn't discard card!


5. Gave outpost its own function: outpostCard();

	no bugs in this one













*/
